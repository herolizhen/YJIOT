#include "fog_v2_include.h"
#include "mico.h"
#include "user_config.h"

#include "user_uart_data_process.h"

#define app_log(M, ...)                     custom_log("FOG_V2", M, ##__VA_ARGS__)

#ifndef FOG_V2_PRODUCT_ID
    #error "FOG_V2_PRODUCT_ID is not define"
#endif

#ifndef FOG_V2_REPORT_VER
    #error "FOG_V2_REPORT_VER is not define"
#endif

#ifndef FOG_V2_MODULE_TYPE
    #error "FOG_V2_MODULE_TYPE is not define"
#endif

#ifndef FOG_V2_DEVICE_SN
    #error "FOG_V2_DEVICE_SN is not define"
#endif

#ifndef FOG_V2_OTA_CHECK_ENABLE
    #error "FOG_V2_OTA_CHECK_ENABLE is not define"
#endif

#ifndef FOG_V2_USER_FLASH_PARAM
    #error "FOG_V2_USER_FLASH_PARAM is not define"
#endif

#ifndef ADAPT_MICO_SDK_VSERSION
    #error "ADAPT_MICO_SDK_VSERSION is not define"
#endif

static bool fog_v2_sdk_init_success = false;

FOG_DES_S *fog_des_g = NULL;
static bool is_https_connect = false;      //HTTPS �Ƿ�����
static bool is_mqtt_connect = false;       //MQTT�Ƿ�����

static mico_mutex_t http_send_setting_mutex = NULL;
static mico_semaphore_t fog_v2_init_complete_sem = NULL;

extern void wlan_get_mac_address (unsigned char *mac);

void user_free_json_obj(json_object **obj);
bool get_wifi_status(void);
FOG_DES_S *get_fog_des_g(void);
void fog_des_clean(void);
void fog_WifiStatusHandler(WiFiEvent status, void* const inContext);
FOG_DES_S *get_fog_des_g(void);
OSStatus fog_des_recovery(void);
OSStatus start_fog_v2_service(void);
bool fog_v2_is_have_superuser(void);
bool fog_v2_is_https_connect(void);
bool fog_v2_is_mqtt_connect(void);

OSStatus init_fog_v2_service(void);

static void fog_init(mico_thread_arg_t arg);
static OSStatus fog_des_init(void);

static uint32_t generate_http_session_id(void);
static OSStatus push_http_req_to_queue(FOG_HTTP_REQUEST_SETTING_S *http_req);
static OSStatus set_fog_v2_http_req(FOG_HTTP_REQUEST_SETTING_S *http_req, bool isuint32_jwt, FOG_HTTP_METHOD method, char *request_uri, char *host_name, char *http_body, uint32_t http_req_id);

OSStatus check_http_body_code(int32_t code);
OSStatus fog_v2_push_http_req_mutex(bool is_jwt, FOG_HTTP_METHOD method, char *request_uri, char *host_name, char *http_body, FOG_HTTP_RESPONSE_SETTING_S *user_http_resopnse);
OSStatus process_response_body(const char *http_body, int32_t *code);
OSStatus process_response_body_string(const char *http_body, int32_t *code, const char *user_key, char *value, uint32_t value_len);
OSStatus process_response_body_bool(const char *http_body, int32_t *code, const char *user_key, bool *user_key_data);

static OSStatus fog_v2_device_activate(void);           //����
static OSStatus fog_v2_device_get_token(void);          //��ȡtoken
static OSStatus fog_v2_device_check_superuser(void);    //��鳬���û�
static OSStatus fog_v2_device_recovery(void);           //�豸����
static OSStatus fog_v2_device_sync_status(void);        //ͬ��״̬
OSStatus fog_v2_device_get_server_time(char *server_time_p, uint32_t recv_len); //��ȡʱ��
OSStatus fog_v2_device_send_event(const char *payload, uint32_t flag); //��������
OSStatus fog_v2_device_generate_device_vercode(void);   //������֤��
OSStatus fog_v2_ota_check(char *resoponse_body, int32_t resoponse_body_len, bool *need_update);  //OTA���
OSStatus fog_v2_ota_upload_log(void);                   //�ϴ�OTA log

bool fog_v2_set_device_recovery_flag(void);
void set_https_connect_status(bool status);
bool get_https_connect_status(void);
void set_mqtt_connect_status(bool status);

void user_free_json_obj(json_object **obj)
{
    if(*obj != NULL)
    {
        json_object_put(*obj);
        *obj = NULL;
    }
}

//��ȡ��������״̬
bool get_wifi_status(void)
{
    LinkStatusTypeDef link_status;

    memset(&link_status, 0, sizeof(link_status));

    micoWlanGetLinkStatus(&link_status);

    return (bool)(link_status.is_connected);
}


//��ȡ�ṹ��ָ��ȫ�ֱ���
FOG_DES_S *get_fog_des_g(void)
{
    return fog_des_g;
}

//���ܣ���ѯ���豸�Ƿ��г����û�������)
//��������
//����ֵ��true - �г����û���flase - �޳����û�
bool fog_v2_is_have_superuser(void)
{
    if(fog_v2_sdk_init_success == false)
    {
        app_log("fog sdk is not init!");
        return false;
    }

    return fog_des_g->is_hava_superuser;
}

//�ж���https�Ƿ�����
bool fog_v2_is_https_connect(void)
{
    return is_https_connect;
}

//�ж���mqtt�Ƿ�����
bool fog_v2_is_mqtt_connect(void)
{
    return is_mqtt_connect;
}

//���ܣ��豸�����û��ձ�־λ �����øýӿڣ��豸�������������Զ����ƶ˷����豸��������
//��������
//����ֵ����
bool fog_v2_set_device_recovery_flag(void)
{
    if(get_fog_des_g() == NULL)
    {
        app_log("fog sdk is not init!");
        return false;
    }

    app_log("[NOTICE]device unbind!!");
    mico_rtos_thread_msleep(10);
    fog_des_g->is_recovery = true;
    mico_system_context_update(mico_system_context_get());

    return true;
}

#if (FOG_V2_USER_FLASH_PARAM == 1)
//���ܣ����û�����д�뵽�м����flash�û�������
//������user_data-�û�����ָ��, offset-ƫ����, user_data_len-�û����ݳ���
//����ֵ��kNoErr-�ɹ�,����-ʧ��
OSStatus fog_v2_write_user_param(const uint8_t *user_data, uint32_t user_data_len, uint32_t offset)
{
    OSStatus err = kGeneralErr;

    if(get_fog_des_g() == NULL)
    {
        app_log("fog sdk is not init!");
        return kGeneralErr;
    }

    require_action((user_data_len + offset) <= FOG_V2_USER_FLASH_PARAM_LEN, exit, err = kGeneralErr);

    memcpy(get_fog_des_g()->user_app_data + offset, user_data, user_data_len);

    err = mico_system_context_update(mico_system_context_get());
    require_noerr_string(err, exit, "update error!");

exit:
    return err;
}

//���ܣ����м�����û�flash����������
//������user_data-�û�����ָ��, offset-ƫ����, user_data_len-�û����ݳ���
//����ֵ��kNoErr-�ɹ�,����-ʧ��
OSStatus fog_v2_read_user_param(uint8_t *user_data, uint32_t user_data_len, uint32_t offset)
{
    OSStatus err = kGeneralErr;

    if(get_fog_des_g() == NULL)
    {
        app_log("fog sdk is not init!");
        return kGeneralErr;
    }

    require_action((user_data_len + offset) <= FOG_V2_USER_FLASH_PARAM_LEN, exit, err = kGeneralErr);

    memcpy(user_data, get_fog_des_g()->user_app_data + offset, user_data_len);

    err = kNoErr;

exit:
    return err;
}
#endif

//����mqtt����״̬
void set_mqtt_connect_status(bool status)
{
    is_mqtt_connect = status;
}

//����https����״̬
void set_https_connect_status(bool status)
{
    is_https_connect = status;
}

//��ȡhttps����״̬
bool get_https_connect_status(void)
{
    return is_https_connect;
}

//����һ��http�ػ�id
static uint32_t generate_http_session_id(void)
{
    static uint32_t id = 1;

    return id ++;
}

//���flash�е�����
void fog_des_clean(void)
{
    memset(fog_des_g, 0, sizeof(FOG_DES_S));
    mico_system_context_update(mico_system_context_get());
}

OSStatus fog_des_recovery(void)
{
    uint8_t major, minor, revision;
    unsigned char mac[10] = {0};

    memset(fog_des_g, 0, sizeof(FOG_DES_S));   //ȫ�ֱ������
    mico_system_context_update(mico_system_context_get());

    fog_des_g->is_activate = false;
    fog_des_g->is_hava_superuser = false;
    fog_des_g->is_recovery = false;


    sprintf(fog_des_g->fog_v2_lib_version, "fog%d.%d.%d", FOG_V2_LIB_VERSION_MAJOR, FOG_V2_LIB_VERSION_MINOR, FOG_V2_LIB_VERSION_REVISION);

    if(strlen(FOG_V2_PRODUCT_ID) >= sizeof(fog_des_g->product_id))
    {
        app_log("[ERROR]PRODUCT_ID is too long!");
        return kGeneralErr;
    }
    memcpy(fog_des_g->product_id, FOG_V2_PRODUCT_ID, strlen(FOG_V2_PRODUCT_ID));     //���ò�ƷID

    if((strlen(FOG_V2_REPORT_VER) + strlen(FOG_V2_REPORT_VER_NUM)) >= sizeof(fog_des_g->firmware))
    {
        app_log("[ERROR]FOG_V2_REPORT_VER + FOG_V2_REPORT_VER_NUM is too long!");
        return kGeneralErr;
    }
    memcpy(fog_des_g->firmware, FOG_V2_REPORT_VER, strlen(FOG_V2_REPORT_VER));
    memcpy(fog_des_g->firmware + strlen(fog_des_g->firmware), FOG_V2_REPORT_VER_NUM, strlen(FOG_V2_REPORT_VER_NUM));   //�����豸�����汾��

    if(strlen(FOG_V2_MODULE_TYPE) >= sizeof(fog_des_g->module_type))
    {
        app_log("[ERROR]FOG_V2_MODULE_TYPE is too long!");
        return kGeneralErr;
    }
    memcpy(fog_des_g->module_type, FOG_V2_MODULE_TYPE, strlen(FOG_V2_MODULE_TYPE));      //����ģ���ͺ�

    wlan_get_mac_address(mac);
    memset(fog_des_g->device_mac, 0, sizeof(fog_des_g->device_mac));
    sprintf(fog_des_g->device_mac, "%02X%02X%02X%02X%02X%02X", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    app_log("device_mac:%s", fog_des_g->device_mac);

#if (ADAPT_MICO_SDK_VSERSION == 1)
    mico_system_version( &major, &minor, &revision );
#elif (ADAPT_MICO_SDK_VSERSION == 2)
    mico_sdk_version( &major, &minor, &revision );
#else
    #error "ADAPT_MICO_SDK_VSERSION is not define!"
#endif
    sprintf(fog_des_g->mico_version, "%d.%d.%d", major, minor, revision);     //����MICO�汾��

    memset(fog_des_g->devicepw, 0, sizeof(fog_des_g->devicepw));              //�������

    memcpy(fog_des_g->mxchip_sn, FOG_V2_DEVICE_SN, strlen(FOG_V2_DEVICE_SN)); //����sn��Ϣ
    mico_system_context_update(mico_system_context_get());

    return kNoErr;
}

//����flash�����������Ƿ���ȷ������ȷ�ͻָ���������
bool check_fog_des_settings(void)
{
    char firmware[64] = {0};

    sprintf(firmware, "%s%s", FOG_V2_REPORT_VER, FOG_V2_REPORT_VER_NUM);

    if(0 != strcmp(fog_des_g->product_id, FOG_V2_PRODUCT_ID))
    {
        app_log("product_id change!");
        return false;
    }

    if(0 != strcmp(fog_des_g->firmware, firmware))
    {
        app_log("firmware change!");
        return false;
    }

    if(0 != strcmp(fog_des_g->mxchip_sn, FOG_V2_DEVICE_SN))
    {
        app_log("mxchip_sn change!");
        return false;
    }

    if(0 != strcmp(fog_des_g->module_type, FOG_V2_MODULE_TYPE))
    {
        app_log("module_type change!");
        return false;
    }

    if(fog_des_g->is_activate == true)
    {
        if(strlen(fog_des_g->device_id) < DEVICE_ID_MIN_LEN)
        {
            app_log("device_id is error!");
            return false;
        }

        if(strlen(fog_des_g->devicepw) == 0)
        {
            app_log("devicepw is null!");
            return false;
        }
    }

    if(strlen(fog_des_g->device_mac) != DEVICE_MAC_LEN)
    {
        app_log("device_mac is error!");
        return false;
    }

    return true;
}

//fog v2��ʼ�� ����micoϵͳΪ�û�ά����flash�������洢��
OSStatus init_fog_v2_service(void)
{
    OSStatus err = kGeneralErr;
    mico_Context_t* context = NULL;

    context = mico_system_context_get();
    require_action_string(context != NULL, exit, err = kGeneralErr,"[ERROR]context is NULL!!!");

#if (ADAPT_MICO_SDK_VSERSION == 1)
    fog_des_g = (FOG_DES_S *)(context->user_config_data);
    require_action_string(fog_des_g != NULL, exit, err = kGeneralErr,"[ERROR]fog_des_g is NULL!!!");

#elif (ADAPT_MICO_SDK_VSERSION == 2)
    fog_des_g = (FOG_DES_S *)mico_system_context_get_user_data(context);
    require_action_string(fog_des_g != NULL, exit, err = kGeneralErr,"[ERROR]fog_des_g is NULL!!!");
#else
    #error "ADAPT_MICO_SDK_VSERSION is not define!"
#endif

    err = kNoErr;
exit:
    return err;
}

//�ṹ���ʼ��
static OSStatus fog_des_init(void)
{
    OSStatus err = kGeneralErr;

    if(false == check_fog_des_settings())
    {
        app_log("[NOTICE]recovery settings!!!!!!!");
        err = fog_des_recovery();
        require_noerr( err, exit );
    }

    app_log("local firmware version:%s", fog_des_g->firmware);
    return kNoErr;

 exit:
    app_log("fog_des_init error");

    if(fog_des_g != NULL)
    {
        memset(fog_des_g, 0, sizeof(FOG_DES_S));   //ȫ�ֱ������
        mico_system_context_update(mico_system_context_get());
    }

    return kGeneralErr;
}


//�����������
OSStatus set_fog_v2_http_req(FOG_HTTP_REQUEST_SETTING_S *http_req, bool is_jwt, FOG_HTTP_METHOD method, char *request_uri, char *host_name, char *http_body, uint32_t http_req_id)
{
    memset(http_req, 0, sizeof(FOG_HTTP_REQUEST_SETTING_S));

    http_req->is_jwt = is_jwt;
    http_req->method = method;

    if(strlen(request_uri) > HTTP_REQUEST_REQ_URI_MAX_LEN)
    {
        app_log("request_uri is error!");
        memset(http_req, 0, sizeof(FOG_HTTP_REQUEST_SETTING_S));
        return kGeneralErr;
    }

    if(strlen(host_name) > HTTP_REQUEST_HOST_NAME_MAX_LEN)
    {
        app_log("host_name is error!");
        memset(http_req, 0, sizeof(FOG_HTTP_REQUEST_SETTING_S));
        return kGeneralErr;
    }

    if(http_body != NULL)
    {
        if(strlen(http_body) > HTTP_REQUEST_BODY_MAX_LEN)
        {
            app_log("http_body is too long!");
            memset(http_req, 0, sizeof(FOG_HTTP_REQUEST_SETTING_S));
            return kGeneralErr;
        }
    }

    if(strlen(fog_des_g->device_token) > HTTP_REQUEST_JWT_MAX_LEN)
    {
        app_log("device_token is too long!");
        memset(http_req, 0, sizeof(FOG_HTTP_REQUEST_SETTING_S));
        return kGeneralErr;
    }

    memcpy(http_req->request_uri, request_uri, strlen(request_uri));
    memcpy(http_req->host_name, host_name, strlen(host_name));

    if(http_body != NULL)
    {
        http_req->http_body = malloc(strlen(http_body) + 1);
        if(http_req->http_body == NULL)
        {
            app_log("http body malloc error");
            return kNoMemoryErr;
        }

        memset(http_req->http_body, 0, strlen(http_body) + 1);     //�������Ļ�����
        memcpy(http_req->http_body, http_body, strlen(http_body));
    }

    if(is_jwt == true)
    {
        if(fog_des_g->device_token != NULL)
        {
            memset(http_req->jwt, 0, sizeof(http_req->jwt));
            memcpy(http_req->jwt, fog_des_g->device_token, strlen(fog_des_g->device_token));
        }else
        {
            app_log("[ERROR]token is NULL");
        }

    }
    http_req->http_req_id = http_req_id;

    return kNoErr;
}


static OSStatus push_http_req_to_queue(FOG_HTTP_REQUEST_SETTING_S *http_req)
{
    OSStatus err = kGeneralErr;

    if(mico_rtos_is_queue_full(&fog_http_request_queue) == true)
    {
        app_log("fog_http_request_queue is full!");
        return kGeneralErr;
    }

    err = mico_rtos_push_to_queue(&fog_http_request_queue, &http_req, 10);
    if(err != kNoErr)
    {
        if(http_req->http_body != NULL)
        {
            free(http_req->http_body);
            http_req->http_body = NULL;
        }
        app_log("push req to fog_http_request_queue error");
    }

    return err;
}

//�Ӷ����л�ȡ����
OSStatus get_http_res_from_queue(FOG_HTTP_RESPONSE_SETTING_S *http_res, uint32_t id)
{
    OSStatus err = kGeneralErr;
    uint32_t res_body_len = 0;
    FOG_HTTP_RESPONSE_SETTING_S *fog_http_res_p = NULL;
    FOG_HTTP_REQUEST_SETTING_S *fog_http_req = NULL;

    memset(http_res, 0, sizeof(FOG_HTTP_RESPONSE_SETTING_S));

    err = mico_rtos_pop_from_queue( &fog_http_response_queue, &fog_http_res_p, WAIT_HTTP_RES_MAX_TIME);
    if(err != kNoErr)
    {
        http_res->send_status = HTTP_CONNECT_ERROR;
        http_res->status_code = -1;
        app_log("mico_rtos_pop_from_queue() timeout!!!");

        if(mico_rtos_is_queue_full(&fog_http_request_queue) == true)
        {
            err = mico_rtos_pop_from_queue(&fog_http_request_queue, &fog_http_req, 10);
            if(err == kNoErr)
            {
                if(fog_http_req->http_body != NULL)
                {
                    free(fog_http_req->http_body);
                    fog_http_req->http_body = NULL;
                }
                app_log("push one req from queue!");
            }
        }

        return kGeneralErr;
    }
    
    //lxc test
    //res_body_len = strlen(fog_http_res_p->fog_response_body);
    //app_log("response_length:%d",res_body_len);
    //app_log("response_body:%s",fog_http_res_p->fog_response_body);

    require_action_string((fog_http_res_p->http_res_id == id), exit, err = kIDErr, "response id is error");     //���ID

    require_action_string((fog_http_res_p->send_status == HTTP_RESPONSE_SUCCESS), exit, err = kStateErr, "send_state is not success");     //����Ƿ�ɹ�

    res_body_len = strlen(fog_http_res_p->fog_response_body);

    if(res_body_len == 0)
    {
        app_log("[error]get data is len is 0");
        err = kGeneralErr;
        goto exit;
    }

    if((fog_http_res_p->fog_response_body[0] != '{') || fog_http_res_p->fog_response_body[res_body_len - 1] != '}') //JSON��ʽ���
    {
        app_log("[error]get data is not JSON format!");
        err = kGeneralErr;
        goto exit;
    }
    

    memcpy(http_res, fog_http_res_p, sizeof(FOG_HTTP_RESPONSE_SETTING_S));

 exit:
     if(err != kNoErr)
     {   //copy send_status and status_code
         http_res->send_status = fog_http_res_p->send_status;
         http_res->status_code = fog_http_res_p->status_code;
     }

    if(err == kIDErr)
    {
        app_log("requese id:%ld, rseponse id:%ld", id, fog_http_res_p->http_res_id);
    }else if(err == kStateErr)
    {
        app_log("send_state:%d, state_code:%ld", fog_http_res_p->send_status, fog_http_res_p->status_code);
    }

    return err;
}

//����http����
OSStatus fog_v2_push_http_req_mutex(bool is_jwt, FOG_HTTP_METHOD method, char *request_uri, char *host_name, char *http_body, FOG_HTTP_RESPONSE_SETTING_S *user_http_resopnse)
{
    OSStatus err = kGeneralErr;
    int32_t id = 0;
    FOG_HTTP_REQUEST_SETTING_S user_http_req;
    FOG_HTTP_RESPONSE_SETTING_S *fog_http_response_temp_p = NULL;


    mico_rtos_lock_mutex(&http_send_setting_mutex);   //����� ��ס����Դ�Ƚ϶�

    if(false == mico_rtos_is_queue_empty(&fog_http_response_queue))  //queue����  �ڷ������������� ���ܵ���queue����������
    {
        app_log("[error]want send http request, but fog_http_response_queue is full");
        err = mico_rtos_pop_from_queue(&fog_http_response_queue, &fog_http_response_temp_p, 10); //��������
        require_noerr_string(err, exit, "mico_rtos_pop_from_queue() error");

        if(fog_http_response_temp_p->fog_response_body != NULL)
        {
            free(fog_http_response_temp_p->fog_response_body);
            fog_http_response_temp_p->fog_response_body = NULL;
        }

        fog_http_response_temp_p = NULL;
    }

    id = generate_http_session_id();

    memset(&user_http_req, 0, sizeof(user_http_req));
    err = set_fog_v2_http_req(&user_http_req, is_jwt, method, request_uri, host_name, http_body, id);
    require_noerr(err, exit);

    err = push_http_req_to_queue(&user_http_req);  //��������
    app_log("push_http_req_to_queue code:%d",err);
    require_noerr(err, exit);

    err = get_http_res_from_queue(user_http_resopnse, id); //�ȴ����ؽ��
    app_log("get_http_res_from_queue code:%d",err);
    require_noerr(err, exit);

 exit:
    mico_rtos_unlock_mutex(&http_send_setting_mutex);  //������Ҫ�ȵ�response���з���֮������ͷ�

    return err;
}


//�������ؽ�� ֻ����code
OSStatus process_response_body(const char *http_body, int32_t *code)
{
    OSStatus err = kGeneralErr;
    json_object *http_body_json_obj = NULL, *meta_json_obj = NULL, *code_json_obj = NULL;

    require_string(http_body != NULL, exit, "body is NULL ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");

    require_string(((*http_body == '{') && (*(http_body + strlen(http_body) - 1) == '}')), exit, "http body JSON format error");

    http_body_json_obj = json_tokener_parse(http_body);
    //    require_string(http_body_json_obj != NULL, exit, "json_tokener_parse error");
    if(http_body_json_obj == NULL)
    {
        app_log("num_of_chunks:%d, free:%d", MicoGetMemoryInfo()->num_of_chunks, MicoGetMemoryInfo()->free_memory);
        app_log("error body,%s", http_body);
        err = kGeneralErr;
        goto exit;
    }


    meta_json_obj = json_object_object_get(http_body_json_obj, "meta");
    require_string(meta_json_obj != NULL, exit, "get meta error!");

    code_json_obj = json_object_object_get(meta_json_obj, "code");
    require_string(code_json_obj != NULL, exit, "get code error!");

    *code = json_object_get_int(code_json_obj);

    err = kNoErr;

 exit:
    if(http_body_json_obj != NULL)
    {
        json_object_put(http_body_json_obj);
        http_body_json_obj = NULL;
    }

    return err;
}

//�������ؽ��  string����
OSStatus process_response_body_string(const char *http_body, int32_t *code, const char *user_key, char *value, uint32_t value_len)
{
    OSStatus err = kGeneralErr;
    json_object *http_body_json_obj = NULL, *meta_json_obj = NULL, *data_json_obj = NULL, *code_json_obj = NULL, *user_key_obj = NULL;
    const char *value_string = NULL;

    require_string(http_body != NULL, exit, "body is NULL ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");

    require_string(((*http_body == '{') && (*(http_body + strlen(http_body) - 1) == '}')), exit, "http body JSON format error");

    http_body_json_obj = json_tokener_parse(http_body);
    require_string(http_body_json_obj != NULL, exit, "json_tokener_parse error");

    meta_json_obj = json_object_object_get(http_body_json_obj, "meta");
    require_string(meta_json_obj != NULL, exit, "get meta error!");

    code_json_obj = json_object_object_get(meta_json_obj, "code");
    require_string(code_json_obj != NULL, exit, "get code error!");

    *code = json_object_get_int(code_json_obj);
    if(*code != FOG_HTTP_SUCCESS)
    {
        err = kNoErr;
        goto exit;
    }

    data_json_obj = json_object_object_get(http_body_json_obj, "data");
    require_string(data_json_obj != NULL, exit, "get data error!");

    if(user_key == NULL) //�ж��Ƿ���Ҫ����user_key
    {
        err = kNoErr;
        goto exit;
    }

    user_key_obj = json_object_object_get(data_json_obj, user_key);
    require_string(user_key_obj != NULL, exit, "get code error!");

    value_string = json_object_get_string(user_key_obj);
    require_string(value_string != NULL, exit, "get user_key_obj error!");

    require_string(strlen(value_string) < value_len, exit, "[ERROR]value len is short!!!");

    require_string(value != NULL, exit, "[ERROR]value is NULL");
    memset(value, 0, value_len);
    memcpy(value, value_string, strlen(value_string));

    err = kNoErr;

 exit:

    if(http_body_json_obj != NULL)
    {
        json_object_put(http_body_json_obj);
        http_body_json_obj = NULL;
    }

    return err;
}

//�������ؽ��,bool����
OSStatus process_response_body_bool(const char *http_body, int32_t *code, const char *user_key, bool *user_key_data)
{
    OSStatus err = kGeneralErr;
    json_object *http_body_json_obj = NULL, *meta_json_obj = NULL, *data_json_obj = NULL, *code_json_obj = NULL, *user_key_obj = NULL;

    require_string(http_body != NULL, exit, "body is NULL ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");

    require_string(((*http_body == '{') && (*(http_body + strlen(http_body) - 1) == '}')), exit, "http body JSON format error");

    http_body_json_obj = json_tokener_parse(http_body);
    require_string(http_body_json_obj != NULL, exit, "json_tokener_parse error");

    meta_json_obj = json_object_object_get(http_body_json_obj, "meta");
    require_string(meta_json_obj != NULL, exit, "get meta error!");

    code_json_obj = json_object_object_get(meta_json_obj, "code");
    require_string(code_json_obj != NULL, exit, "get code error!");

    *code = json_object_get_int(code_json_obj);
    if(*code != FOG_HTTP_SUCCESS)
    {
        err = kNoErr;
        goto exit;
    }

    data_json_obj = json_object_object_get(http_body_json_obj, "data");
    require_string(data_json_obj != NULL, exit, "get data error!");

    if(user_key == NULL) //�ж��Ƿ���Ҫ����user_key
    {
        err = kNoErr;
        goto exit;
    }

    user_key_obj = json_object_object_get(data_json_obj, user_key);
    require_string(user_key_obj != NULL, exit, "get code error!");

    *user_key_data = json_object_get_boolean(user_key_obj);

    err = kNoErr;

 exit:

    if(http_body_json_obj != NULL)
    {
        json_object_put(http_body_json_obj);
        http_body_json_obj = NULL;
    }

    return err;
}

//get json data
OSStatus process_response_body_get_data(const char *http_body, int32_t *code, char *data_p, uint32_t data_len)
{
    OSStatus err = kGeneralErr;
    json_object *http_body_json_obj = NULL, *meta_json_obj = NULL, *data_json_obj = NULL, *code_json_obj = NULL;
    const char *data_json_string = NULL;

    require_string(http_body != NULL, exit, "param error!");
    require_string(code != NULL, exit, "param error!");
    require_string(data_p != NULL, exit, "param error!");

    require_string(((*http_body == '{') && (*(http_body + strlen(http_body) - 1) == '}')), exit, "http body JSON format error");

    http_body_json_obj = json_tokener_parse(http_body);
    require_string(http_body_json_obj != NULL, exit, "json_tokener_parse error");

    meta_json_obj = json_object_object_get(http_body_json_obj, "meta");
    require_string(meta_json_obj != NULL, exit, "get meta error!");

    code_json_obj = json_object_object_get(meta_json_obj, "code");
    require_string(code_json_obj != NULL, exit, "get code error!");

    *code = json_object_get_int(code_json_obj);
    if(*code != FOG_HTTP_SUCCESS)
    {
        err = kNoErr;
        goto exit;
    }

    data_json_obj = json_object_object_get(http_body_json_obj, "data");
    require_string(data_json_obj != NULL, exit, "get data error!");

    data_json_string = json_object_to_json_string(data_json_obj);
    require_action_string(data_json_string != NULL, exit, err = kNoMemoryErr, "create data string error!");

    require_action_string(data_len > strlen(data_json_string), exit, err = kGeneralErr, "data len error!");

    memcpy(data_p, data_json_string, strlen(data_json_string));
    err = kNoErr;
 exit:
    if ( data_json_obj != NULL )
    {
        json_object_put( data_json_obj );
        data_json_obj = NULL;
    }

    if(http_body_json_obj != NULL)
    {
        json_object_put(http_body_json_obj);
        http_body_json_obj = NULL;
    }

    return err;
}


//���http����body�е�code, ����:kNoErr token����:kOptionErr ��������:kGeneralErr
OSStatus check_http_body_code(int32_t code)
{
    if(code == FOG_HTTP_SUCCESS)
    {
        return kNoErr;
    }
    else if((code == FOG_HTTP_TOKEN_EXPIRED) || (code == FOG_HTTP_TOKEN_ERROR) || (code == FOG_HTTP_TOKEN_INVAILD))
    {
        while(1)
        {
            app_log("[ERROR]code = %ld, refesh token!", code);

            if(fog_v2_device_get_token() == kNoErr)  //���»�ȡtoken �����õĻ��Ǿɵı�֤MQTT����������
            {
                break;
            }else
            {
                mico_thread_msleep(200);
            }
        }
        return kOptionErr;
    }else
    {
        return kGeneralErr;
    }

}


//�豸����
static OSStatus fog_v2_device_activate(void)
{
    OSStatus err = kGeneralErr;
    const char* device_activate_body = "{\"product_id\":\"%s\",\"mac\":\"%s\",\"devicepw\":\"%s\",\"mxchipsn\":\"%s\"}";
    char http_body[256] = {0};
    int32_t code = -1;
    FOG_HTTP_RESPONSE_SETTING_S user_http_res;
    uint8_t retry = 0;

    memset(&user_http_res, 0, sizeof(user_http_res));

    if((fog_des_g->is_activate == true))
    {
        return kNoErr;
    }

 start_actiavte:
    while(get_wifi_status() == false)
    {
        app_log("https disconnect, fog_v2_device_activate is waitting...");
        err = kGeneralErr;
        goto exit;
    }

    sprintf(fog_des_g->devicepw, "%04ld", (mico_rtos_get_time()) % 10000);

    sprintf(http_body, device_activate_body, fog_des_g->product_id, fog_des_g->device_mac, fog_des_g->devicepw, fog_des_g->mxchip_sn);

    app_log("=====> device_activate send ======>");

    err = fog_v2_push_http_req_mutex(false, FOG_V2_ACTIVATE_METHOD, FOG_V2_ACTIVATE_URI, FOG_V2_HTTP_DOMAIN_NAME, http_body, &user_http_res);
    require_noerr( err, exit );

    //�������ؽ��
    err = process_response_body_string(user_http_res.fog_response_body, &code, "deviceid", fog_des_g->device_id, sizeof(fog_des_g->device_id));
    require_noerr( err, exit );

    require_action(code == FOG_HTTP_SUCCESS, exit, err = kGeneralErr);

    fog_des_g->is_activate = true;
    err = mico_system_context_update(mico_system_context_get());
    require_noerr( err, exit );
    app_log("activate success, device_id: %s, pw:%s", fog_des_g->device_id, fog_des_g->devicepw);
    app_log("<===== device_activate success <======");

 exit:
     if(user_http_res.fog_response_body != NULL) //�ͷ���Դ
     {
         free(user_http_res.fog_response_body);
         user_http_res.fog_response_body = NULL;
     }

    if(err != kNoErr)
    {
        if ( (code == FOG_HTTP_PRODUCTI_ID_ERROR) || (code == FOG_HTTP_PRODUCTI_ID_NOT_SUB) || (code == FOG_HTTP_PRODUCTI_ID_NOT_GATEWAY))
        {
            app_log("product id is error! code = %ld", code);
            app_log("<===== device_activate error <======");
            return err;
        }

        fog_des_g->is_activate = false;
        memset(fog_des_g->devicepw, 0, sizeof(fog_des_g->devicepw));
        mico_system_context_update(mico_system_context_get());

        app_log("<===== device_activate error <======");

        mico_thread_msleep(200);

        retry ++;
        if(retry >= HTTP_MAX_RETRY_TIMES)
        {
            return kGeneralErr;
        }

        goto start_actiavte;
    }

    return err;
}

//�豸��ȡ��Ȩ
static OSStatus fog_v2_device_get_token( void )
{
    OSStatus err = kGeneralErr;
    const char* device_get_token_body = "{\"deviceid\":\"%s\",\"password\":\"%s\"}";
    char http_body[256] = { 0 };
    int32_t code = -1;
    FOG_HTTP_RESPONSE_SETTING_S user_http_res;
    uint8_t retry = 0;

    memset( &user_http_res, 0, sizeof(user_http_res) );

    start_get_token:
    while ( get_wifi_status() == false )
    {
        app_log("https disconnect, fog_v2_device_get_token is waitting...");
        err = kGeneralErr;
        goto exit;
    }

    sprintf( http_body, device_get_token_body, fog_des_g->device_id, fog_des_g->devicepw );

    app_log("=====> device_get_token send ======>");

    err = fog_v2_push_http_req_mutex( false, FOG_V2_GET_TOKEN_METHOD, FOG_V2_GET_TOKEN_URI, FOG_V2_HTTP_DOMAIN_NAME, http_body, &user_http_res );
    require_noerr( err, exit );
    
    //lxc test
    app_log("user_http_res.status_code = %d",user_http_res.status_code);
    app_log("user_http_res.fog_response_body:%s",user_http_res.fog_response_body);

    //�������ؽ��
    err = process_response_body_string( user_http_res.fog_response_body, &code, "token", fog_des_g->device_token, sizeof(fog_des_g->device_token) );
    require_noerr( err, exit );

    if ( code == FOG_HTTP_SUCCESS )
    {
        err = mico_system_context_update( mico_system_context_get( ) );
        require_noerr( err, exit );

        app_log("token:%s,device_id:%s,pw:%s", fog_des_g->device_token, fog_des_g->device_id, fog_des_g->devicepw);
        app_log("<===== device_get_token success <======");
    } else
    {
        fog_des_g->is_activate = false;
        err = kGeneralErr;
        goto exit;
    }

    exit:
    if ( user_http_res.fog_response_body != NULL ) //�ͷ���Դ
    {
        free( user_http_res.fog_response_body );
        user_http_res.fog_response_body = NULL;
    }

    if ( err != kNoErr )
    {
        memset( fog_des_g->device_token, 0, sizeof(fog_des_g->device_token) );
        mico_system_context_update( mico_system_context_get( ) );

        app_log("<===== device_get_token error <======");

        mico_thread_msleep( 200 );

        retry++;
        if ( retry >= HTTP_MAX_RETRY_TIMES )
        {
            return kGeneralErr;
        }

        goto start_get_token;
    }

    return err;
}

//��鳬���û�
static OSStatus fog_v2_device_check_superuser( void )
{
    OSStatus err = kGeneralErr;
    int32_t code = -1;
    FOG_HTTP_RESPONSE_SETTING_S user_http_res;
    uint8_t retry = 0;

    memset(&user_http_res, 0, sizeof(user_http_res));

    start_check_superuser:
    while ( get_wifi_status() == false )
    {
        app_log("https disconnect, fog_v2_device_check_superuser is waitting...");
        err = kGeneralErr;
        goto exit;
    }

    app_log("=====> device_check_superuser send ======>");

    err = fog_v2_push_http_req_mutex( true, FOG_V2_CHECK_SUPERUSER_METHOD, FOG_V2_CHECK_SUPERUSER_URI, FOG_V2_HTTP_DOMAIN_NAME, NULL, &user_http_res );
    require_noerr( err, exit );

    //�������ؽ��
    err = process_response_body_bool( user_http_res.fog_response_body, &code, "CheckDeviceSuperUser", &(fog_des_g->is_hava_superuser) );
    require_noerr( err, exit );

    err = check_http_body_code( code );   //�����token�����Ǵ������⣬�����ڲ��ᴦ�����֮���ٷ���
    require_noerr( err, exit );

    app_log("is_hava_superuser = %s", (fog_des_g->is_hava_superuser == true) ? "true" : "false");
    app_log("<===== device_check_superuser success <======");

    exit:
    if ( user_http_res.fog_response_body != NULL ) //��ײ��ͷ���Դ
    {
        free( user_http_res.fog_response_body );
        user_http_res.fog_response_body = NULL;
    }

    if ( err != kNoErr )
    {
        fog_des_g->is_hava_superuser = false;
        mico_system_context_update( mico_system_context_get( ) );

        app_log("<===== device_check_superuser error <======");

        mico_thread_msleep( 200 );

        retry++;
        if ( retry >= HTTP_MAX_RETRY_TIMES )
        {
            return kGeneralErr;
        }

        goto start_check_superuser;
    }

    return err;
}

//�����豸 http api
static OSStatus fog_v2_device_recovery(void)
{
    OSStatus err = kGeneralErr;
    int32_t code = -1;
    const char* device_recovery_body = "{\"deviceid\":\"%s\"}";
    char http_body[256] = {0};
    FOG_HTTP_RESPONSE_SETTING_S user_http_res;
    uint8_t retry = 0;

    memset(&user_http_res, 0, sizeof(user_http_res));

 start_recovery:
    while(get_wifi_status() == false)
    {
        app_log("https disconnect, fog_v2_device_recovery is waitting...");
        err = kGeneralErr;
        goto exit;
    }

    if(fog_des_g->is_activate == false)
    {
        err = kNoErr;
        app_log("[ERROR]device is not activate, can't revovery!!!");
        goto exit;
    }

    sprintf(http_body, device_recovery_body, fog_des_g->device_id);

    app_log("=====> device_recovery send ======>");

    err = fog_v2_push_http_req_mutex(true, FOG_V2_RECOVERY_METHOD, FOG_V2_RECOVERY_URI, FOG_V2_HTTP_DOMAIN_NAME, http_body, &user_http_res);
    require_noerr( err, exit );

    //�������ؽ��
    err = process_response_body(user_http_res.fog_response_body, &code);
    require_noerr( err, exit );

    err = check_http_body_code(code);   //�����token�����Ǵ������⣬�����ڲ��ᴦ�����֮���ٷ���
    require_noerr( err, exit );

    err = fog_des_recovery();
    require_noerr( err, exit );

    app_log("<===== device_recovery success <======");

 exit:
    if ( user_http_res.fog_response_body != NULL ) //�ͷ���Դ
    {
        free( user_http_res.fog_response_body );
        user_http_res.fog_response_body = NULL;
    }

    if(err != kNoErr)
    {
        app_log("<===== device_recovery error <======");

        mico_thread_msleep(200);

        retry++;
        if ( retry >= HTTP_MAX_RETRY_TIMES )
        {
            return kGeneralErr;
        }

        goto start_recovery;
    }

    return err;
}

//ͬ���豸�汾��Ӳ���ͺŵ��ƶ�
static OSStatus fog_v2_device_sync_status(void)
{
    OSStatus err = kGeneralErr;
    int32_t code = -1;
    const char* device_sync_status_body = "{\"product_id\":\"%s\",\"moduletype\":\"%s\",\"firmware\":\"%s\",\"mico\":\"%s\"}";
    char http_body[256] = {0};
    FOG_HTTP_RESPONSE_SETTING_S user_http_res;
    uint8_t retry = 0;

    memset(&user_http_res, 0, sizeof(user_http_res));

 start_sync_status:
    while(get_wifi_status() == false)
    {
        app_log("https disconnect, fog_v2_device_sync_status is waitting...");
        err = kGeneralErr;
        goto exit;
    }

    sprintf(http_body, device_sync_status_body, fog_des_g->product_id, fog_des_g->module_type, fog_des_g->firmware, fog_des_g->mico_version);

    app_log("=====> device_sync_status send ======>");

    err = fog_v2_push_http_req_mutex(true, FOG_V2_SYNC_STATUS_METHOD, FOG_V2_SYNC_STATUS_URI, FOG_V2_HTTP_DOMAIN_NAME, http_body, &user_http_res);
    require_noerr( err, exit );

    //�������ؽ��
    err = process_response_body(user_http_res.fog_response_body, &code);
    require_noerr( err, exit );

    err = check_http_body_code(code);   //�����token�����Ǵ������⣬�����ڲ��ᴦ�����֮���ٷ���
    require_noerr( err, exit );

    app_log("<===== device_sync_status success <======");

 exit:
    if ( user_http_res.fog_response_body != NULL ) //�ͷ���Դ
    {
        free( user_http_res.fog_response_body );
        user_http_res.fog_response_body = NULL;
    }

    if(err != kNoErr)
    {
        app_log("<===== device_sync_status error <======");

        mico_thread_msleep(200);

        retry ++;
        if(retry >= HTTP_MAX_RETRY_TIMES)
        {
            return kGeneralErr;
        }

        goto start_sync_status;
    }

    return err;
}


//OTA���
OSStatus fog_v2_ota_check(char *resoponse_body, int32_t resoponse_body_len, bool *need_update_p)
{
    OSStatus err = kGeneralErr;
    int32_t code = -1;
    const char *ota_ckeck_body = "{\"product_id\":\"%s\",\"firmware_type\":\"%s\",\"modulename\":\"%s\",\"firmware\":\"%s\"}";
    char http_body[512] = {0};
    FOG_HTTP_RESPONSE_SETTING_S user_http_res;
    uint8_t retry = 0;

    memset(&user_http_res, 0, sizeof(user_http_res));

 start_ota_check:
    while(get_wifi_status() == false)
    {
        app_log("https disconnect, fog_v2_ota_check is waitting...");
        err = kGeneralErr;
        goto exit;
    }

    sprintf(http_body, ota_ckeck_body, fog_des_g->product_id, fog_des_g->fog_v2_lib_version, fog_des_g->module_type, fog_des_g->firmware);

    app_log("=====> ota check send ======>");

    err = fog_v2_push_http_req_mutex(false, FOG_V2_OTA_UP_DATA_CHECK, FOG_V2_OTA_UP_DATA_URI, FOG_V2_HTTP_DOMAIN_NAME, http_body, &user_http_res);
    require_noerr( err, exit );

    //�������ؽ��
    err = process_response_body(user_http_res.fog_response_body, &code);
    require_noerr( err, exit );

    if(code == FOG_HTTP_OTA_NO_UPDATE)
    {
        err = kNoErr; //����Ҫ����
        *need_update_p = false;
        app_log("<===== ota check success <======");
        goto exit;
    }else
    {
        err = check_http_body_code(code);   //�����token�����Ǵ������⣬�����ڲ��ᴦ�����֮���ٷ���
        require_noerr( err, exit );

        //code == 0 ���µĹ̼�
        app_log("<===== ota check success <======");

        if(resoponse_body != NULL)
        {
            if(resoponse_body_len <= strlen(user_http_res.fog_response_body))
            {
                *need_update_p = false;
                app_log("[ERROR]resoponse_body_len is small!");
            }else
            {
                memcpy(resoponse_body, user_http_res.fog_response_body, strlen(user_http_res.fog_response_body));
                *need_update_p = true;
            }
        }else
        {
            app_log("[ERROR]resoponse_body is NULL");
        }
    }

 exit:
    if ( user_http_res.fog_response_body != NULL ) //�ͷ���Դ
    {
        free( user_http_res.fog_response_body );
        user_http_res.fog_response_body = NULL;
    }

    if(err != kNoErr)
    {
        *need_update_p = false;

        app_log("<===== ota check error <======");

        mico_thread_msleep(200);

        retry ++;
        if(retry >= HTTP_MAX_RETRY_TIMES)
        {
            return kGeneralErr;
        }

        goto start_ota_check;
    }

    return err;
}


//OTA�ɹ����ϴ���Ϣ
OSStatus fog_v2_ota_upload_log(void)
{
    OSStatus err = kGeneralErr;
    int32_t code = -1;
    const char *ota_upload_log_body = "{\"deviceid\":\"%s\",\"software\":\"%s\",\"modulename\":\"%s\"}";
    char http_body[512] = {0};
    FOG_HTTP_RESPONSE_SETTING_S user_http_res;
    uint8_t retry = 0;

    memset(&user_http_res, 0, sizeof(user_http_res));

 start_ota_upload_log:
    while(get_wifi_status() == false)
    {
        app_log("https disconnect, fog_v2_ota_upload_log is waitting...");
        err = kGeneralErr;
        goto exit;
    }

    sprintf(http_body, ota_upload_log_body, fog_des_g->device_id, fog_des_g->firmware, fog_des_g->module_type);

    app_log("=====> ota upload log send ======>");

    err = fog_v2_push_http_req_mutex(true, FOG_V2_OTA_UPLOAD_LOG, FOG_V2_OTA_UPLOAD_URI, FOG_V2_HTTP_DOMAIN_NAME, http_body, &user_http_res);
    require_noerr( err, exit );

    //�������ؽ��
    err = process_response_body(user_http_res.fog_response_body, &code);
    require_noerr( err, exit );

    err = check_http_body_code(code);   //�����token�����Ǵ������⣬�����ڲ��ᴦ�����֮���ٷ���
    require_noerr( err, exit );

    //code == 0 ���µĹ̼�
    app_log("<===== ota upload log success <======");

 exit:
     if(user_http_res.fog_response_body != NULL) //�ͷ���Դ
     {
         free(user_http_res.fog_response_body);
         user_http_res.fog_response_body = NULL;
     }

    if(err != kNoErr)
    {
        app_log("<===== ota upload log error <======");

        mico_thread_msleep(200);

        retry ++;
        if(retry >= HTTP_MAX_RETRY_TIMES)
        {
            return kGeneralErr;
        }

        goto start_ota_upload_log;
    }

    return err;
}


//�����豸��֤��
OSStatus fog_v2_device_generate_device_vercode(void)
{
    OSStatus err = kGeneralErr;
    int32_t code = -1;
    FOG_HTTP_RESPONSE_SETTING_S user_http_res;
    char http_body[64] = "{\"callback\":true}";
    uint8_t retry = 0;

    memset(&user_http_res, 0, sizeof(user_http_res));

 start_generate_device_vercode:
    while(get_wifi_status() == false)
    {
        app_log("https disconnect, fog_v2_device_generate_device_vercode is waitting...");
        err = kGeneralErr;
        goto exit;
    }

    app_log("=====> generate_device_vercode send ======>");

    err = fog_v2_push_http_req_mutex(true, FOG_V2_GENERATE_VERCODE_METHOD, FOG_V2_GENERATE_VERCODE_URI, FOG_V2_HTTP_DOMAIN_NAME, http_body, &user_http_res);
    require_noerr( err, exit );

    //�������ؽ��
    err = process_response_body_string(user_http_res.fog_response_body, &code, "vercode", fog_des_g->vercode, sizeof(fog_des_g->vercode));
    require_noerr( err, exit );

    if(code == FOG_HTTP_DEVICE_HAVE_SUPER_USER)  //���ܻᷢ���Ѿ��г����û�
    {
        app_log("device already have superuser! set Bonjour");
        app_log("<===== generate_device_vercode error <======");
        fog_v2_device_check_superuser();
        stop_fog_bonjour();
        start_fog_bonjour(false, fog_des_g);   //����bonjour

        err = kNoErr;
        goto exit;
    }

    err = check_http_body_code(code);   //�����token�����Ǵ������⣬�����ڲ��ᴦ�����֮���ٷ���
    require_noerr( err, exit );

    app_log("get device vercode success, vercode:%s", fog_des_g->vercode);
    app_log("<===== generate_device_vercode success <======");

 exit:
     if(user_http_res.fog_response_body != NULL) //�ͷ���Դ
     {
         free(user_http_res.fog_response_body);
         user_http_res.fog_response_body = NULL;
     }

    if ( err != kNoErr )
    {
        memset( fog_des_g->vercode, 0, sizeof(fog_des_g->vercode) );
        app_log("<===== generate_device_vercode error <======");

        retry ++;
        if(retry >= HTTP_MAX_RETRY_TIMES)
        {
            return kGeneralErr;
        }

        mico_thread_msleep(200);
        goto start_generate_device_vercode;
    }

    return err;
}

//���ܣ��豸�˴ӷ�������ȡʱ��
//������recv_p - ���ջ�������ַ
//������recv_len - ���ջ���������,������Ҫ����512 Byte
//����ֵ��kNoErrΪ�ɹ� ����Ϊʧ��
OSStatus fog_v2_device_get_server_time(char *server_time_p, uint32_t recv_len)
{
    OSStatus err = kGeneralErr;
    int32_t code = -1;
    FOG_HTTP_RESPONSE_SETTING_S user_http_res;
    uint8_t retry = 0;

    memset(&user_http_res, 0, sizeof(user_http_res));

 start_get_server_time:
    while(get_wifi_status() == false)
    {
        app_log("https disconnect, fog_v2_device_get_server_time is waitting...");
        err = kGeneralErr;
        goto exit;
    }

    app_log("=====> get_server_time send ======>");

    err = fog_v2_push_http_req_mutex(false, FOG_V2_GET_SERVER_TIME, FOG_V2_GET_SERVER_TIME_URI, FOG_V2_HTTP_DOMAIN_NAME, NULL, &user_http_res);
    require_noerr( err, exit );

    //�������ؽ��
    err = process_response_body_get_data(user_http_res.fog_response_body, &code, server_time_p, recv_len);
    require_noerr( err, exit );

    err = check_http_body_code(code);   //�����token�����Ǵ������⣬�����ڲ��ᴦ�����֮���ٷ���
    require_noerr( err, exit );

    app_log("<===== get_server_time success <======");

 exit:
     if(user_http_res.fog_response_body != NULL) //�ͷ���Դ
     {
         free(user_http_res.fog_response_body);
         user_http_res.fog_response_body = NULL;
     }

    if ( err != kNoErr )
    {
        app_log("<===== get_server_time error <======");

        retry ++;
        if(retry >= HTTP_MAX_RETRY_TIMES)
        {
            return kGeneralErr;
        }

        mico_thread_msleep(200);
        goto start_get_server_time;
    }

    return err;
}

//���ܣ����ƶ˷�������
//������ payload - Ҫ���ƶ˷��͵����ݣ���ָ��ָ�������ֻ��Ϊjson��ʽ
//������ flag - ���ͷ�ʽ
//���������궨�����,���������ϵķ�ʽ
//FOG_V2_SEND_EVENT_RULES_PUBLISH  ���豸��topicȥpublish����
//FOG_V2_SEND_EVENT_RULES_DATEBASE ���˴ε�payload���ݴ������ݿ�
//FOG_V2_SEND_EVENT_RULES_PRODUCT  ���豸��Ӧ��Ʒ��topicȥpublish����(�������͸�����)
//����ֵ��kNoErrΪ�ɹ� ����ֵΪʧ��
//extern OSStatus user_process_response_body(const char *http_body, int32_t *code);
/*
OSStatus fog_v2_device_send_event(const char *payload, uint32_t flag)
{
    OSStatus err = kGeneralErr;
    int32_t code = -1;
    json_object *send_json_object = NULL;
    char *http_body = NULL;
    FOG_HTTP_RESPONSE_SETTING_S user_http_res;
    uint8_t retry = 0;

    memset(&user_http_res, 0, sizeof(user_http_res));

    if(fog_v2_sdk_init_success == false)
    {
        app_log("fog sdk is not init!");
        return kGeneralErr;
    }

    if(strlen(payload) >= FOG_V2_PAYLOAD_LEN_MAX)
    {
        app_log("[ERROR]payload is too long!");
        return kGeneralErr;
    }

 start_send_event:
    while(get_wifi_status() == false)
    {
        app_log("https disconnect, fog_v2_device_send_event is waitting...");
        err = kGeneralErr;
        goto exit;
    }

    send_json_object = json_object_new_object();
    require_string(send_json_object != NULL, exit, "json_object_new_object() error");

    json_object_object_add(send_json_object, "payload", json_object_new_string(payload));
    json_object_object_add(send_json_object, "format", json_object_new_string("json"));
    json_object_object_add(send_json_object, "flag", json_object_new_int(flag));
    http_body = (char *)json_object_to_json_string(send_json_object);
    require_action_string(http_body != NULL, exit, err = kGeneralErr, "json_object_to_json_string() is error");

    app_log("=====> send_event send ======>");

    err = fog_v2_push_http_req_mutex(true, FOG_V2_SEND_EVENT_METHOD, FOG_V2_SEND_EVENT_URI, FOG_V2_HTTP_DOMAIN_NAME, http_body, &user_http_res);
    require_noerr( err, exit );

    //�������ؽ��
    err = process_response_body(user_http_res.fog_response_body, &code);
    require_noerr( err, exit );
    
    //lxc add
    //user_process_response_body(user_http_res.fog_response_body, &code);

    err = check_http_body_code(code);   //�����token�����Ǵ������⣬�����ڲ���ˢ����һ��token֮���ٷ���
    require_noerr_string(err, exit, "check_http_body_code() error");

    app_log("<===== send_event success <======");

 exit:
    user_free_json_obj(&send_json_object);

    if(user_http_res.fog_response_body != NULL) //�ͷ���Դ
    {
        free(user_http_res.fog_response_body);
        user_http_res.fog_response_body = NULL;
    }

    if(err != kNoErr)
    {
        app_log("deviceid:%s, pw:%s, token: %s",fog_des_g->device_id, fog_des_g->devicepw, fog_des_g->device_token);

        app_log("<===== send_event error <======");
        mico_thread_msleep(100);

        retry ++;
        if(retry >= HTTP_MAX_RETRY_TIMES)
        {
            return kGeneralErr;
        }

        goto start_send_event;
    }

    return err;
}
*/

OSStatus modbus_fog_v2_device_send_event(const char *device_id, const char *payload, uint32_t flag)
{
    OSStatus err = kGeneralErr;
    int32_t code = -1;
    json_object *send_json_object = NULL;
    char *http_body = NULL;
    FOG_HTTP_RESPONSE_SETTING_S user_http_res;
    uint8_t retry = 0; 
    
    if(device_id == NULL || payload == NULL)
    {
        return kGeneralErr;
    }

    memset(&user_http_res, 0, sizeof(user_http_res));

    if(fog_v2_sdk_init_success == false)
    {
        app_log("fog sdk is not init!");
        return kGeneralErr;
    }

    if(strlen(payload) >= FOG_V2_PAYLOAD_LEN_MAX)
    {
        app_log("[ERROR]payload is too long!");
        return kGeneralErr;
    }

 start_send_event:
    while(get_wifi_status() == false)
    {
        app_log("https disconnect, fog_v2_device_send_event is waitting...");
        err = kGeneralErr;
        goto exit;
    }

    send_json_object = json_object_new_object();
    require_string(send_json_object != NULL, exit, "json_object_new_object() error");

    json_object_object_add(send_json_object, "deviceid", json_object_new_string(device_id));
    json_object_object_add(send_json_object, "payload", json_object_new_string(payload));
    json_object_object_add(send_json_object, "format", json_object_new_string("json"));
    json_object_object_add(send_json_object, "flag", json_object_new_int(flag));
    http_body = (char *)json_object_to_json_string(send_json_object);
    require_action_string(http_body != NULL, exit, err = kGeneralErr, "json_object_to_json_string() is error");

    app_log("=====> send_event send ======>");

    err = fog_v2_push_http_req_mutex(true, FOG_V2_SEND_EVENT_METHOD, FOG_V2_SEND_EVENT_URI, FOG_V2_HTTP_DOMAIN_NAME, http_body, &user_http_res);
    require_noerr( err, exit );

    //�������ؽ��
    err = process_response_body(user_http_res.fog_response_body, &code);
    require_noerr( err, exit );
    
    //lxc add
    //user_process_response_body(user_http_res.fog_response_body, &code);

    err = check_http_body_code(code);   //�����token�����Ǵ������⣬�����ڲ���ˢ����һ��token֮���ٷ���
    require_noerr_string(err, exit, "check_http_body_code() error");

    app_log("<===== send_event success <======");

 exit:
    user_free_json_obj(&send_json_object);

    if(user_http_res.fog_response_body != NULL) //�ͷ���Դ
    {
        free(user_http_res.fog_response_body);
        user_http_res.fog_response_body = NULL;
    }

    if(err != kNoErr)
    {
        //app_log("deviceid:%s, pw:%s, token: %s",fog_des_g->device_id, fog_des_g->devicepw, fog_des_g->device_token);
        
        app_log("deviceid:%s,token: %s",device_id, fog_des_g->device_token);

        app_log("<===== send_event error <======");
        mico_thread_msleep(100);

        retry ++;
        if(retry >= HTTP_MAX_RETRY_TIMES)
        {
            return kGeneralErr;
        }

        goto start_send_event;
    }

    return err;
}

//lxc add
#ifdef USE_MODBOS_DEVICES
//extern modbus_devs_t modbus_devs;
#define DEVICE_RELATED    1480
OSStatus modbus_device_relation_event(device_t **devices, uint8_t count, int32_t *relation_code)
{
    OSStatus err = kGeneralErr;
    int32_t code = -1;
    json_object *send_json_object = NULL;
    char *http_body = NULL;
    FOG_HTTP_RESPONSE_SETTING_S user_http_res;
    uint8_t retry = 0; 
    //char *node = NULL;
    const char *node_type = "{\"deviceId\":\"%s\",\"deviceIdChild\":\"%s\",\"gate\":%d}";
    uint8_t i = 0;
    
    if(devices == NULL || count <= 0)
    {
        app_log("parameter error");
        return kGeneralErr;
    }

    memset(&user_http_res, 0, sizeof(user_http_res));

    if(fog_v2_sdk_init_success == false)
    {
        app_log("fog sdk is not init!");
        return kGeneralErr;
    }
    
    http_body = malloc(1024);
    if(http_body == NULL)
    {
        app_log("http_body malloc fail");
        return kGeneralErr;
    }
    
    memset(http_body,0,1024);
    
    for(i = 0;i < count;i++)
    {
        if(i == 0)
        {
            http_body[strlen(http_body)] = '[';
        }
        else
        {
            http_body[strlen(http_body)] = ',';
        }
        sprintf(http_body + strlen(http_body),node_type,fog_des_g->device_id,devices[i]->device_id,i + 1);
    }
    http_body[strlen(http_body)] = ']';
   

//    if(strlen(payload) >= FOG_V2_PAYLOAD_LEN_MAX)
//    {
//        app_log("[ERROR]payload is too long!");
//        if(http_body != NULL)
//       {
//           free(http_body);
//           http_body = NULL;
//        }
//        return kGeneralErr;
//    }

 start_send_event:
    while(get_wifi_status() == false)
    {
        app_log("https disconnect, fog_v2_device_send_event is waitting...");
        err = kGeneralErr;
        goto exit;
    }

    app_log("=====> device_relation_event send ======>");

    err = fog_v2_push_http_req_mutex(true, FOG_V2_DEVIE_RELATION_METHOD, FOG_V2_DEVIE_RELATION_URI, FOG_V2_HTTP_DOMAIN_NAME, http_body, &user_http_res);
    require_noerr( err, exit );

    //�������ؽ��
    err = process_response_body(user_http_res.fog_response_body, &code);
    *relation_code = code;
    require_noerr( err, exit );
    
    app_log("device_relation_event code:%d",code);
    
    if(code != kNoErr)
    {
        if((code == FOG_HTTP_TOKEN_EXPIRED) || (code == FOG_HTTP_TOKEN_ERROR) || (code == FOG_HTTP_TOKEN_INVAILD))
        {
            while(1)
            {
                app_log("[ERROR]code = %ld, refesh token!", code);

                if(fog_v2_device_get_token() == kNoErr)  //���»�ȡtoken �����õĻ��Ǿɵı�֤MQTT����������
                {
                    break;
                }else
                {
                    mico_thread_msleep(1000);
                }
            }
            goto exit;
        }
        else if(code == DEVICE_RELATED)
        {
            app_log("<===== device already related<======");
            err = kNoErr;
        }
        else
        {
            goto exit;
        }
    }

    app_log("<===== device_relation_event success <======");

 exit:
    user_free_json_obj(&send_json_object);

    if(user_http_res.fog_response_body != NULL) //�ͷ���Դ
    {
        free(user_http_res.fog_response_body);
        user_http_res.fog_response_body = NULL;
    }

    if(err != kNoErr)
    {
        //app_log("deviceid:%s, pw:%s, token: %s",fog_des_g->device_id, fog_des_g->devicepw, fog_des_g->device_token);

        app_log("<===== device_relation_event error <======");
        mico_thread_msleep(100);

        retry ++;
        if(retry >= HTTP_MAX_RETRY_TIMES)
        {
           if(http_body != NULL)
           {
               free(http_body);
               http_body = NULL;
            }
            return kGeneralErr;
        }

        goto start_send_event;
    }
    
    if(http_body != NULL)
    {
        free(http_body);
        http_body = NULL;
    }

    return err;
}
#endif

//�ȴ�mqtt����
bool fog_v2_wait_mqtt_connect(uint32_t timeout)
{
    uint32_t start_time = mico_rtos_get_time();
    uint32_t stop_time = 0;

    while(fog_v2_is_mqtt_connect() == false) //�ȴ�MQTT�������
    {
        stop_time = mico_rtos_get_time();

        if(stop_time - start_time > timeout)
        {
            return false;
        }
        mico_thread_msleep(50);
    }

    return true;
}

//FOG��ʼ��
static void fog_init(mico_thread_arg_t arg)
{
    UNUSED_PARAMETER( arg );
    OSStatus err = kGeneralErr;

    require_string(get_wifi_status() == true, exit, "wifi is not connect");

    err = mico_rtos_init_mutex(&http_send_setting_mutex);
    require_noerr(err, exit);

    //����http client ��̨�߳�
    err = start_fogcloud_http_client();  //�ڲ��ж��г�ʼ��,��Ҫ��ִ��
    require_noerr( err, exit );

 start_fog_init:
    err = fog_des_init();
    require_noerr( err, exit );

    stop_fog_bonjour();
    start_fog_bonjour(true, fog_des_g);

    //1.�豸����
    err = fog_v2_device_activate();
    require_noerr( err, exit );

    //2.��ȡ�豸��Ȩ
    err = fog_v2_device_get_token();
    require_noerr( err, exit );

    //3.����Ƿ���Ҫ �����豸��Ȩ
    if(fog_des_g->is_recovery == true)
    {
        err = fog_v2_device_recovery();
        require_noerr( err, exit );

        goto start_fog_init;
    }

#if (FOG_V2_OTA_CHECK_ENABLE == 1)
    //OTA���
    fog_v2_ota();
#endif

#if (FOG_V2_USE_SUB_DEVICE == 1)
    err = fog_v2_subdevice_des_init();
    require_noerr( err, exit );
#endif

    //4.����MQTT��̨����
    init_fog_mqtt_service();

    require_string(fog_v2_wait_mqtt_connect(5000) == true, exit, "mqtt connect error!"); //�ȴ�MQTT�������

    app_log("mqtt connect ok.....");

     //5.��鳬���û�
    err = fog_v2_device_check_superuser();  //��ˢ����token,token�����ܻ�ʧЧ
    require_noerr( err, exit );

    //6.��������tcp server
    if( fog_des_g->is_hava_superuser == false)
    {
        err = fog_tcp_server_start();
        require_noerr( err, exit );
    }else
    {
        app_log("device is already bind, don't start tcp server");
    }

    stop_fog_bonjour();
    start_fog_bonjour(false, fog_des_g);   //����bonjour

    //7.ͬ���豸�汾��Ӳ���ͺŵ��ƶ�
    err = fog_v2_device_sync_status();
    require_noerr( err, exit );

//    //8.�����豸����
//    err = fog_v2_device_generate_device_vercode( ); //������
//    require_noerr( err, exit );

    fog_v2_sdk_init_success = true;

 exit:
    mico_rtos_set_semaphore( &fog_v2_init_complete_sem ); //wait until get semaphore

    if(err != kNoErr)
    {
        stop_fog_bonjour();
    }

    mico_rtos_delete_thread( NULL );
    return;
}

//���ܣ�����fog�ķ���
//��������
//����ֵ��kNoErrΪ�ɹ�
OSStatus start_fog_v2_service(void)
{
    OSStatus err = kGeneralErr;

    fog_v2_sdk_init_success = false;

    err = mico_rtos_init_semaphore( &fog_v2_init_complete_sem, 1 ); //0/1 binary semaphore || 0/N semaphore
    require_noerr( err, exit );

    /* Create a new thread */
    err = mico_rtos_create_thread( NULL, MICO_APPLICATION_PRIORITY, "fog_init", fog_init, 0x1000, (uint32_t)NULL );
    require_noerr_string( err, exit, "ERROR: Unable to start the fog_init thread" );

    mico_rtos_get_semaphore( &fog_v2_init_complete_sem, MICO_WAIT_FOREVER ); //wait until get semaphore

 exit:
     if(fog_v2_sdk_init_success == true)
     {
         app_log("fog v2 sdk init success!");
         return kNoErr;
     }else
     {
         app_log("fog v2 sdk init failure!");
         return kGeneralErr;
     }
}



