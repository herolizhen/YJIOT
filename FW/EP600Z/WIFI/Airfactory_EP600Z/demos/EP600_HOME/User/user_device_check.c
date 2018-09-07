#include "user_device_check.h"
#include "mico.h"
#include "fog_v2_include.h"

#define app_log(M, ...)                     custom_log("FOG_V2", M, ##__VA_ARGS__)

device_check_t device_check;

extern FOG_DES_S *fog_des_g;

//上传检测结果
OSStatus fog_v2_device_check_result_upload(unsigned char check_type)
{
    OSStatus err = kGeneralErr;
    int32_t code = -1;
    const char* device_auto_check_body = "{\"examId\":\"%s\",\"deviceId\":\"%s\",\"type\":\"1\",\"examItems\":[{\"examItem\":\"DOOR\",\"result\":%d},{\"examItem\":\"FAN\",\"result\":%d},{\"examItem\":\"UV\",\"result\":%d},{\"examItem\":\"PM25S\",\"result\":%d},{\"examItem\":\"PM25\",\"result\":%d}]}";
    const char* device_man_check_body = "{\"examId\":\"%s\",\"deviceId\":\"%s\",\"type\":\"1\",\"examItems\":[{\"examItem\":\"PWK\",\"result\":%d},{\"examItem\":\"QK\",\"result\":%d},{\"examItem\":\"LK\",\"result\":%d},{\"examItem\":\"MK\",\"result\":%d},{\"examItem\":\"HK\",\"result\":%d},{\"examItem\":\"TK\",\"result\":%d},{\"examItem\":\"MDK\",\"result\":%d}]}";
    char http_body[350] = {0};
    //char http_body[256] = {0};
    FOG_HTTP_RESPONSE_SETTING_S user_http_res;
    uint8_t retry = 0;
    unsigned char result = 0;
 
    memset(&user_http_res, 0, sizeof(user_http_res));
 
start_device_check_confirm:
    while(get_wifi_status() == false)
    {
        app_log("https disconnect, fog_v2_device_check_result_upload is waitting...");
        err = kGeneralErr;
        goto exit;
    }
 
    result = device_check.check_result;
    app_log("check result:%x",result);
    if(check_type == auto_check)
    {
        sprintf(http_body, device_auto_check_body, device_check.check_id, fog_des_g->device_id ,AUTO_CHECK_1(result,door_bit),
                AUTO_CHECK_1(result,fan_bit), AUTO_CHECK_1(result,uv_bit), AUTO_CHECK_1(result,pm25_bit), device_check.pm25_value);
    }
    else if(check_type == man_check)
    {
        sprintf(http_body, device_man_check_body, device_check.check_id, fog_des_g->device_id, MAN_CHECK_1(result,power_bit), MAN_CHECK_1(result,quiet_speed_bit),
                MAN_CHECK_1(result,low_speed_bit), MAN_CHECK_1(result,mid_speed_bit), MAN_CHECK_1(result,high_speed_bit), MAN_CHECK_1(result,timer_bit), MAN_CHECK_1(result,mode_bit));
        
        //sprintf(http_body, device_man_check_body, device_check.check_id, fog_des_g->device_id, 0, 0,
         //       0, 0, 0, 0, 0);
        
        app_log("sizeof http body:%d",strlen(http_body));
        
    }
    
 
    app_log("=====> fog_v2_device_check_result_confirm send ======>");
    app_log("upload:%s",http_body);
   
    err = fog_v2_push_http_req_mutex(true, FOG_V2_EXAM_UPLOAD_METHOD, FOG_V2_EXAM_UPLOAD_URI, FOG_V2_HTTP_DOMAIN_NAME, http_body, &user_http_res);
    require_noerr( err, exit );
 
    //处理返回结果
    err = process_response_body(user_http_res.fog_response_body, &code);
    require_noerr( err, exit );
 
    err = check_http_body_code(code);   //如果是token过期是错误问题，函数内部会处理完成之后再返回
    require_noerr( err, exit );
 
    app_log("<===== fog_v2_device_check_result_upload success <======");
 
exit:
    if ( user_http_res.fog_response_body != NULL ) //释放资源
    {
        free( user_http_res.fog_response_body );
        user_http_res.fog_response_body = NULL;
   }
 
    if(err != kNoErr)
    {
        app_log("<===== device_chips_confirm error <======");
 
        mico_thread_msleep(200);
 
        retry ++;
        if(retry >= HTTP_MAX_RETRY_TIMES)
        {
            return kGeneralErr;
        }
 
        goto start_device_check_confirm;
    }
 
    return err;
}