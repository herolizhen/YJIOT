#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ucos_ii.h" 
#include "stm32f10x.h"
#include "L506.h"
#include "user_L506_task.h"
#include "charge.h"
#include "malloc.h"
#include "app.h"
#include "cJSON.h"

//extern OS_EVENT *upload_data_queue;
extern OS_EVENT *mqtt_message_queue;

extern Charge_Typedef charge_info;

extern OS_EVENT *upload_data_queue;
extern OS_EVENT *upload_res_queue;

extern OS_EVENT *mqtt_action_cmd_queue;
extern OS_EVENT *mqtt_action_res_queue;

extern OS_EVENT *upload_data_mutex;
//extern OS_EVENT *mqtt_cmd_mutex;


char token_buff[TOKEN_BUFF_SIZE];
char order_num[41];
char ccid[40];
uint8_t is_disabled_cmd_echo = 0;
volatile uint8_t Is_Get_CCID = 0;
char device_id[40];
//bit Is_Get_IMEI = 0;
uint8_t Is_device_activate = 0;
uint8_t is_get_token = 0;
uint8_t is_need_updata_token = 0;
uint8_t Is_L506_wakeup = 0;

uint8_t is_ota_check = 0;

static uint8_t https_step = 0;

uint8_t L506_action = 0;

static uint8_t is_https_action = 0;

//如果mqtt_action = 0，则没有mqtt动作
static uint8_t mqtt_action = 0;
static uint8_t is_mqtt_inited = 0;
//static uint8_t mqtt_connect_status = 0;
static uint8_t mqtt_init_step = 0;
uint16_t mqtt_passowrd = 0;

//L506启动后和服务器通讯的初始化工作是否结束
uint8_t is_L506_fogcloud_init = 0;

//信号质量
uint32_t signal_quality = 0;
//读取信号质量时，检测误码率是否是0
uint8_t Is_signal_err_code_zero = 0;



uint8_t Is_signal_check;
uint8_t signal_check_err_times;



uint8_t wifi_led_state;



static https_requeset_res_t https_req_res;
static mqtt_action_res_t mqtt_action_res;
static uint8_t is_send_get_mqtt_status_cmd = 0;

static uint32_t http_session_id = 0;

uint8_t is_module_powered = 0;

static uint8_t is_module_restart = 0;



//AT指令发送时间
L506_Cmd_Typedef L506_cmd_info;

L506_RESGISTER_Typedef L506_register_net;


//L506与服务器http通讯第几步标识
static uint8_t Is_http = 0;

static uint32_t save_http_session_id(uint32_t id)
{
    http_session_id = id;

    return id;
}

static uint32_t get_http_session_id(void)
{
    return http_session_id;
}


//电源芯片控制管脚低电平时，电源芯片工作

/*
void L506_Reset_Pin_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruchture;
	
    RCC_APB2PeriphClockCmd(L506_RESET_GPIO_CLK, ENABLE);
	
    GPIO_InitStruchture.GPIO_Pin = L506_RESET_PIN;
    GPIO_InitStruchture.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruchture.GPIO_Speed = GPIO_Speed_50MHz;
	
    GPIO_Init(L506_RESET_PORT, &GPIO_InitStruchture);
  
    POWER_KEY_HIGH();
}

void L506_Reset_Pin_High(void)
{
    L506_RESET_HIGH();
}

void L506_Reset_Pin_Low(void)
{
    L506_RESET_LOW();    
}

void L506_Reset(void)
{
    L506_Reset_Pin_Low();
    OSTimeDlyHMSM(0,0,1,0); 
    L506_Reset_Pin_High();  

    is_disabled_cmd_echo = 0;
    https_step = 0;
    Is_http = 0;
    L506_action = 0;
    
    signal_quality = 99;
    Is_Get_CCID = 0;
    Is_signal_err_code_zero = 0;
    Is_device_activate = 0;
    is_get_token = 0;
    L506_register_net.Is_L506_registerd = 0;
        
    L506_cmd_info.error_times = 0;
    L506_cmd_info.timeout_times = 0;
    
    is_ota_check = 0;
    is_L506_fogcloud_init = 0;
    is_mqtt_inited = 0;
    mqtt_init_step = 0;
   
    L506_LOG("L506 reset");  
}
*/


//开机：PWK管脚高电平脉冲，然后低电平保持500ms,然后再高电平开机
//关机：PWK管脚高电平脉冲，然后低电平保持3s,然后再高电平关机
void L506_PowerKey_Pin_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruchture;
	
    RCC_APB2PeriphClockCmd(POWER_KEY_GPIO_CLK, ENABLE);
	
    GPIO_InitStruchture.GPIO_Pin = POWER_KEY_PIN;
    GPIO_InitStruchture.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruchture.GPIO_Speed = GPIO_Speed_50MHz;
	
    GPIO_Init(POWER_KEY_PORT, &GPIO_InitStruchture);
  
    POWER_KEY_HIGH();
}

//开机：PWK管脚高电平脉冲，然后低电平保持500ms,然后再高电平开机
void L506_PowerKey_On(void)
{  
    POWER_KEY_HIGH();
    OSTimeDlyHMSM(0,0,0,500);
    POWER_KEY_LOW();
    OSTimeDlyHMSM(0,0,0,500);
    POWER_KEY_HIGH();
    is_module_powered = 1;
    OSTimeDlyHMSM(0,0,20,0);
    L506_LOG("power on");  
    
}

//关机：PWK管脚高电平脉冲，然后低电平保持3s,然后再高电平关机
void L506_PowerKey_Off(void)
{
    POWER_KEY_HIGH();
    OSTimeDlyHMSM(0,0,0,500);
    POWER_KEY_LOW();
    OSTimeDlyHMSM(0,0,3,0);
    POWER_KEY_HIGH();
    OSTimeDlyHMSM(0,0,6,0);
    POWER_KEY_LOW();
    is_module_powered = 0;
    OSTimeDlyHMSM(0,0,38,0);
    L506_LOG("power off");  
}

void L506_Restart(void)
{  
    L506_LOG("L506 restart");
         
    is_disabled_cmd_echo = 0;
    https_step = 0;
    Is_http = 0;
    L506_action = 0;
    
    signal_quality = 99;
    Is_Get_CCID = 0;
    Is_signal_err_code_zero = 0;
    Is_device_activate = 0;
    is_get_token = 0;
    L506_register_net.Is_L506_registerd = 0;
        
    L506_cmd_info.error_times = 0;
    L506_cmd_info.timeout_times = 0;
       
    is_ota_check = 0;
    is_L506_fogcloud_init = 0;
    is_mqtt_inited = 0;
    mqtt_init_step = 0;   
       
    is_module_restart = 0;
    
    memset(L506_cmd_info.cmd,0,sizeof(L506_cmd_info.cmd));
    
    //释放内存，此处本来是在发送http stop命令时释放，但是重启的时候可能不会执行到http stop就重启了，会导致内存无法释放掉
    if(https_req_res.http_body != NULL)
    {
        myfree(https_req_res.http_body);
        https_req_res.http_body = NULL;
    }
            
    if(https_req_res.header != NULL)
    {
        myfree(https_req_res.header);
        https_req_res.header = NULL;
    }
            
    if(https_req_res.jwt != NULL)
    {
        myfree(https_req_res.jwt);
        https_req_res.jwt = NULL;
    }
    
    //重启L506 
    L506_PowerKey_Off();
    
    L506_PowerKey_On();
}


int L506_wait_response(char *rx_buff,uint16_t *index)
{
    int res = L506_WAIT_RESPONSE;
  
    uint32_t nowtime_ms = 0;
    
  
    if(L506_register_net.Is_L506_registerd == 0)
    {
        if(strstr(rx_buff,L506_READY) != NULL)
        {
            L506_register_net.Is_L506_registerd = 1;
            empty_rx_buff(rx_buff,index);
          
            L506_LOG("L506 ready");
            OSTimeDlyHMSM(0,0,5,0);
        }
        //是否加一些处理
    }
    
  
    //如果之前没有发送过数据或者命令，则直接返回
    if(L506_cmd_info.Is_wait_data == 0)
    {
        res = CMD_IDLE;
        L506_cmd_info.cmd_result = CMD_IDLE;
        goto exit;
    }
    
    nowtime_ms = OSTimeGet();
    
    
    //防止时间溢出
    if(L506_cmd_info.cmd_send_time > 0xF0000000 && nowtime_ms < 0xE0000000)
    {
        L506_cmd_info.cmd_send_time = nowtime_ms;
    }

    
    //超时 没有返回数据
    if(nowtime_ms >= (L506_cmd_info.cmd_send_time + L506_CMD_TIMEOUT_TIME))
    {
        L506_cmd_info.cmd_result = CMD_TIMEOUT;
      
        L506_LOG("cmd:%s timeout",L506_cmd_info.cmd);
              
        res = CMD_TIMEOUT;
        goto cmd_failed;
    }
    
    if(strstr(rx_buff,END_ERROR) != NULL)
    {
        L506_cmd_info.cmd_result = CMD_ERROR;
      
        if(L506_cmd_info.type == CMD_TYPE)
        {
            L506_LOG("cmd:%s error",L506_cmd_info.cmd);         
        }
        else
        {
            L506_LOG("send string error");
        }

      
        res = CMD_ERROR;
        goto cmd_failed;
    }
    
    if(L506_cmd_info.type == STRING_TYPE)
    {
        //发送字符串时返回OK或者ERROR
        if(strstr(rx_buff,L506_cmd_info.end_flag) != NULL)
        {
            L506_cmd_info.cmd_result = CMD_SUCCESS;   
            res = CMD_SUCCESS; 
            goto  cmd_success;       
        }
        
        if(Is_http == 1)
        {
            //https_step += 1;
            L506_cmd_info.cmd_result = CMD_SUCCESS;   
            goto  cmd_success;       
        }
      
    }
    else if(L506_cmd_info.type == CMD_TYPE)
    {
        
        //发送命令时会返回命令+OK或者命令+ERROR或者>>
        if(strstr(rx_buff,L506_cmd_info.end_flag) != NULL)
        {            
            res = CMD_SUCCESS;
            L506_cmd_info.cmd_result = CMD_SUCCESS;   

            L506_LOG("cmd:%s success",L506_cmd_info.cmd);
        
            goto cmd_success;
        }

        
    }
    

exit:    
    return res;
    
cmd_success:
    //L506_cmd_info.cmd_result = CMD_SUCCESS;
    return res;
    
    
cmd_failed:
    //L506_cmd_info.cmd_result = res;
    return res;
    
}


void parse_L506_cmd_result(char *rx_buff,uint16_t *index)
{  
    INT8U err;  
    char *pos,*pos_end = NULL;
    char *http_body_start_pos,*http_body_end_pos = NULL;
    uint16_t http_body_length = 0;
    unsigned char ordnum_cmp_result = 0;
    int res_code = -1;
    int http_code = 0;
    unsigned char i = 0;
    upload_res_t *temp_msg;
    char *buff = NULL;
    //uint8_t mqtt_conncet_status = 0;
    
    
    if(L506_cmd_info.Is_wait_data == 0)
    {
        return;
    }
    else if(L506_cmd_info.Is_wait_data == 1)
    {
        if(L506_cmd_info.cmd_result == CMD_WAIT)
        {
            return;
        }
        else if(L506_cmd_info.cmd_result == CMD_SUCCESS)
        {    
                   
            if(L506_cmd_info.type == STRING_TYPE)
            {
                https_step += 1;
                return;
            }
                        
          
            if(strcmp(L506_cmd_info.cmd,L506_ATI_CMD) == 0)
            {
            
            }
            else if(strcmp(L506_cmd_info.cmd,L506_DISABLE_CMD_ECHO_CMD) == 0)
            {
                is_disabled_cmd_echo = 1;
            }
            else if(strcmp(L506_cmd_info.cmd,L506_CSQ_CMD) == 0)
            {
                //获取信号质量
                //debug
                L506_LOG("%s",rx_buff);
              
                pos = strstr(rx_buff,":");
                if(pos != NULL)
                {                   
                    if(*(pos + 3) == ASCII_COMMA)
                    {
                        i = 1;
                    }
                    if(*(pos + 4) == ASCII_COMMA)
                    {
                        i = 2;
                    }
                    
                    if(i == 0)
                    {
                        return;
                    }
                                        
                    memset(L506_cmd_info.sendtring,0,strlen(L506_cmd_info.sendtring));
                    strncpy(L506_cmd_info.sendtring,(pos + 2),i);
                    signal_quality = atoi(L506_cmd_info.sendtring);
                    
                    L506_LOG("signal_quality = %d",signal_quality);
                }              
            }
            else if(strcmp(L506_cmd_info.cmd,L506_GSN_CMD) == 0)
            {
                //获取IMEI成功
              
                //Is_Get_IMEI = 1;
            }
            else if(strcmp(L506_cmd_info.cmd,L506_CICCID_CMD) == 0)
            {
                //获取CCID成功
                memset(ccid,0,sizeof(ccid));
                pos = strstr(rx_buff,L506_CICCID_RES);
                strncpy(ccid,pos + strlen(L506_CICCID_RES) + 1,L506_CCID_LEN);
              
                L506_LOG("CCID:%s",ccid);
              
                Is_Get_CCID = 1;
            }            
            else if(strcmp(L506_cmd_info.cmd,L506_QSPN_CMD) == 0)
            {     
                //读取SIM 卡服务运营商名称             
                //printf("L506_QSPN_CMD OK\r\n");
            }
            else if(strcmp(L506_cmd_info.cmd,L506_HTTPS_START_CMD) == 0)
            {                        
                //printf("L506_HTTPS_START_CMD OK\r\n");
              
                https_step += 1;
            }
            else if(strcmp(L506_cmd_info.cmd,L506_HTTPSPOSE_CMD) == 0)
            {                       
                //printf("L506_HTTPSPOSE_CMD OK\r\n");
              
                https_step += 1;
            }
            else if(strcmp(L506_cmd_info.cmd,L506_HTTPSSEND_NZ_CMD) == 0)
            {                       
                //printf("L506_HTTPSSEND_CMD OK\r\n");
              
                https_step += 1;
            }
            else if(strcmp(L506_cmd_info.cmd,L506_HTTPS_SEND_REQUEST_CMD) == 0)
            {                       
                //printf("send https request success\r\n");
              
                https_step += 1;
                //OSTimeDlyHMSM(0,0,0,10); 
            }
            else if(strcmp(L506_cmd_info.cmd,L506_HTTPSSEND_Z_CMD) == 0)
            {                       
                //printf("L506_HTTPSSEND_CMD OK\r\n");              
                https_step += 1;             
            }
            else if(strcmp(L506_cmd_info.cmd,L506_HTTPSRECV_CMD) == 0)
            { 
                L506_cmd_info.error_times = 0;
                L506_cmd_info.timeout_times = 0;   
              
                L506_LOG("%s",rx_buff);
                            
                //set http send data length 
                if(https_step < HTTPS_MAX_STEP)
                {
                    https_step += 1;
                }
                
                if(is_queue_full(upload_res_queue) == QUEUE_FULL)
                {
                    //消息队列满了，push一个出来
                    L506_LOG("upload data queue full,push one msg");
                    temp_msg = OSQPend(upload_res_queue,10,&err);
                    if(err != OS_ERR_NONE)
                    {
                        //res = UPLAOD_RES_QUEUE_ERR;
                        return;
                    }
        
                    //push出来的消息队列必须要释放掉内存空间
                    if(temp_msg->http_body != NULL)
                    {
                        myfree(temp_msg->http_body);
                        temp_msg->http_body = NULL;
                    }

                }
                
                if((pos = strstr(rx_buff,"code")) != NULL)
                {
                    res_code = string_get_int(pos);
                    https_req_res.upload_res.http_id = res_code;
                }
                else
                {
                    L506_LOG("not find code key");
                    //如果没有code，则服务器回复的数据有问题,立刻给 upload_res_queue 消息队列push一个错误的msg,让函数返回
                    https_req_res.upload_res.http_id = 0;
                    goto push_res_msg;
                    
                }
                
                //printf("return code:%d\r\n",res_code);
              
                if(res_code == TOKEN_WRONG_CODE)
                {
                    is_need_updata_token = 1;
                    L506_LOG("token expired");
                }
                
                pos = strstr(rx_buff,HTTPS_RES_START_FLAG);
                if(pos == NULL)
                {
                    https_req_res.upload_res.http_id = 0;
                    goto push_res_msg;
                }
                pos = pos + strlen(HTTPS_RES_START_FLAG);
                for(i = 0;i < 10;i++)
                {
                    if(*(pos + i) == '\r')
                    {
                        break;
                    }
                }
                    
                if(i == 10)
                {
                    https_req_res.upload_res.http_id = 0;
                    //服务器回复的数据有问题,立刻给 upload_res_queue 消息队列push一个错误的msg,让函数返回
                    goto push_res_msg;
                }
                    
                buff = mymalloc(10);
                if(buff == NULL)
                {
                    https_req_res.upload_res.http_id = 0;
                    //服务器回复的数据有问题,立刻给 upload_res_queue 消息队列push一个错误的msg,让函数返回
                    goto push_res_msg;
                }
                memset(buff,0,10);
                    
                strncpy(buff,pos,i);
                http_code = (uint8_t)atoi(buff);
                myfree(buff);
                buff = NULL;
                
                if(http_code != HTTPS_RES_OK)
                {
                    //如果返回的http头 code不等于200，则与服务器通讯错误
                    https_req_res.upload_res.http_id = 0;
                    goto push_res_msg;
                }
                
                
                //get http body
                pos = strstr(rx_buff,HTTPS_RES_BODY_START_FLAG);
                if(pos == NULL)
                {
                    https_req_res.upload_res.http_id = 0;
                    goto push_res_msg;
                }
                
                http_body_start_pos = pos + strlen(HTTPS_RES_BODY_START_FLAG) - 1;
                    
                http_body_end_pos = strstr(rx_buff,HTTPS_RES_BODY_STOP_FLAG);
                if(http_body_end_pos == NULL)
                {
                    https_req_res.upload_res.http_id = 0;
                    goto push_res_msg;
                }
                http_body_end_pos -= 3;
                
                if(*http_body_start_pos != '{' && *http_body_end_pos != '}')
                {
                    https_req_res.upload_res.http_id = 0;
                    goto push_res_msg;
                }
                //printf("malloc res http_body\r\n");
                https_req_res.upload_res.http_body = mymalloc(HTTP_RES_BODY_LENGTH);
                if(https_req_res.upload_res.http_body == NULL)
                {
                    https_req_res.upload_res.http_id = 0;
                    goto push_res_msg;
                }
                
                http_body_length = http_body_end_pos - http_body_start_pos + 1;
                if(http_body_length >= (HTTP_RES_BODY_LENGTH -1))
                {
                    https_req_res.upload_res.http_id = 0;
                    goto push_res_msg;
                }
                
                memset(https_req_res.upload_res.http_body,0,HTTP_RES_BODY_LENGTH);
                strncpy(https_req_res.upload_res.http_body,http_body_start_pos,http_body_length);
                
                
                
                push_res_msg:  
                  
                
                https_req_res.upload_res.code = http_code;
                https_req_res.upload_res.http_id = get_http_session_id();
                  
                err = OSQPost(upload_res_queue,&https_req_res.upload_res);
                if(err != OS_ERR_NONE)
                {
                    L506_LOG("push upload data msg error");
                    if(https_req_res.upload_res.http_body != NULL)
                    {
                        myfree(https_req_res.upload_res.http_body);
                        https_req_res.upload_res.http_body = NULL;
                    }
                    //res = UPLAOD_REQ_QUEUE_ERR;
                }
                
                
           
            
            }
            else if(strcmp(L506_cmd_info.cmd,L506_HTTPSCLOSE_CMD) == 0)
            {
                https_step += 1;
            }
            else if(strcmp(L506_cmd_info.cmd,L506_HTTPSSTOP_CMD) == 0)
            {
                L506_cmd_info.Is_wait_data = 0;
                https_step = HTTPS_MAX_STEP;
                Is_http = 0;
                L506_action = 0;
            }
            
            else if(strcmp(L506_cmd_info.cmd,L506_MQTT_SSL_CMD) == 0)
            {
                mqtt_init_step += 1;
            }
            else if(strcmp(L506_cmd_info.cmd,L506_MQTT_CONFIG_CMD) == 0)
            {
                mqtt_init_step += 1;
            }
            else if(strcmp(L506_cmd_info.cmd,L506_MQTT_START_CMD) == 0)
            {
                mqtt_init_step += 1;
            }
            else if(strcmp(L506_cmd_info.cmd,L506_MQTT_CONNECT_CMD) == 0)
            {
                mqtt_init_step += 1;
            }
            else if(strcmp(L506_cmd_info.cmd,L506_MQTT_SUB_CMD) == 0)
            {
                L506_cmd_info.error_times = 0;
                L506_cmd_info.timeout_times = 0;
                //此处必须设置mqtt_init_step = MQTT_MAX_STEP，如果mqtt断开重新连接时，在连接过程中不能发送http指令，后面通过判断mqtt_init_step来判断是否正在重新连接mqtt
                mqtt_init_step = MQTT_MAX_STEP;             
                //L506_LOG("mqtt init sucess");
                if(is_queue_full(mqtt_action_res_queue) == QUEUE_FULL)
                {
                    //如果mqtt_action_res_queue队列满，则push一个
                    L506_LOG("mqtt_action_res_queue full,push one");
                    pos_end = OSQPend(mqtt_action_res_queue,10,&err);
                }
                
                mqtt_action_res.cmd = MQTT_INIT_ACTION;
                mqtt_action_res.result = MQTT_ACTION_SUCCESS;
                err = OSQPost(mqtt_action_res_queue,&mqtt_action_res);
                if(err != OS_ERR_NONE)
                {
                    L506_LOG("push msg to mqtt_action_res_queue fail");
                }                         
                //mqtt_action = 0;                             
            }
            else if(strcmp(L506_cmd_info.cmd,L506_MQTT_GET_STATUS_CMD) == 0)
            {
                pos = strstr(rx_buff,L506_MQTT_STATUS_START_FLAG);
                if(pos != NULL)
                {
                    pos = pos + strlen(L506_MQTT_STATUS_START_FLAG);
                    if(*pos == ASCII_SPACE)
                    {
                        pos += 1;
                    }
                    
                    pos_end = strstr(pos,"\r\n");
                    if(pos_end != NULL)
                    {
                        pos_end -= 1;
                        if(pos_end == pos)
                        {
                            if(is_queue_full(mqtt_action_res_queue) == QUEUE_FULL)
                            {
                                //如果mqtt_action_res_queue队列满，则pull一个
                                L506_LOG("mqtt_action_res_queue full,pull one");
                                pos_end = OSQPend(mqtt_action_res_queue,10,&err);
                            }
                            memset(L506_cmd_info.sendtring,0,sizeof(L506_cmd_info.sendtring));
                            L506_cmd_info.sendtring[0] = *pos;
                            mqtt_action_res.status = (uint8_t)atoi(L506_cmd_info.sendtring);
                            //L506_LOG("mqtt status:%d",mqtt_action_res.status);
                            mqtt_action_res.cmd = MQTT_GET_CONNECT_STATUS_ACTION;
                            mqtt_action_res.result = MQTT_ACTION_SUCCESS;
                            err = OSQPost(mqtt_action_res_queue,&mqtt_action_res);
                            if(err != OS_ERR_NONE)
                            {
                                L506_LOG("push msg to mqtt_action_res_queue fail");
                            }                         
                            //mqtt_action = 0;
                            L506_cmd_info.Is_wait_data = 0;
                            memset(L506_cmd_info.cmd,0,sizeof(L506_cmd_info.cmd));
                            //L506_LOG("%s",rx_buff);
                        }
                    }
                }
            }
           
            
        }
        else if(L506_cmd_info.cmd_result == CMD_ERROR)
        {
            L506_cmd_info.error_times += 1;
            L506_cmd_info.Is_wait_data = 0;
            
            L506_LOG("%s",rx_buff);

          
            //按下组合键了，正在检测信号
//            if(Is_signal_check == 1)
//            {
//                signal_check_err_times += 1;
//            }
          
            if(Is_http == 1)
            {              
                L506_http_close();   
                goto exit;
            }
          
          
            if(strcmp(L506_cmd_info.cmd,L506_ATI_CMD) == 0)
            {
                
            }
            else if(strcmp(L506_cmd_info.cmd,L506_CSQ_CMD) == 0)
            {     
                //获取信号质量             
                //printf("get signal quality error\r\n");
              
            }
            else if(strcmp(L506_cmd_info.cmd,L506_CICCID_CMD) == 0)
            {     
                //读取SIM 卡CCID          
                //printf("L506_QCCID_CMD error\r\n");
              
            }
            else if(strcmp(L506_cmd_info.cmd,L506_GSN_CMD) == 0)
            {
                //获取IMEI失败              
                //Is_Get_IMEI = 0;
            }
            else if(strcmp(L506_cmd_info.cmd,L506_QSPN_CMD) == 0)
            {     
                //读取SIM 卡服务运营商名称              
                //printf("L506_QSPN_CMD error\r\n");
            }
            else if(strcmp(L506_cmd_info.cmd,L506_HTTPS_START_CMD) == 0)
            {   
                //printf("L506_HTTPS_START_CMD error\r\n");
              
            }
            else if(strcmp(L506_cmd_info.cmd,L506_HTTPSPOSE_RES) == 0)
            {   
                //printf("L506_HTTPSPOSE_RES error\r\n");              
            }
            else if(strcmp(L506_cmd_info.cmd,L506_HTTPSSEND_CMD) == 0)
            {   
                //printf("L506_HTTPSSEND_CMD error\r\n");
            }
            else if(strcmp(L506_cmd_info.cmd,L506_HTTPSRECV_CMD) == 0)
            {   
                //printf("L506_HTTPSRECV_CMD error\r\n");
            }
            else if(strcmp(L506_cmd_info.cmd,L506_HTTPSCLOSE_CMD) == 0)
            {   
                //printf("L506_HTTPSCLOSE_CMD error\r\n");
            }
            else if(strcmp(L506_cmd_info.cmd,L506_HTTPSSTOP_CMD) == 0)
            {   
                //printf("L506_HTTPSSTOP_CMD error\r\n");
                //如果发送http stop命令返回error，则可能模块内部出错，等待一段时间
               //OSTimeDlyHMSM(0,0,1,0);   
            }
            
            else if(strcmp(L506_cmd_info.cmd,L506_MQTT_SSL_CMD) == 0)
            {   

            }
            else if(strcmp(L506_cmd_info.cmd,L506_MQTT_CONFIG_CMD) == 0)
            {   

            }
            else if(strcmp(L506_cmd_info.cmd,L506_MQTT_START_CMD) == 0)
            {   
                //printf("L506_MQTT_START_CMD error\r\n");
            }
            else if(strcmp(L506_cmd_info.cmd,L506_MQTT_CONNECT_CMD) == 0)
            {   
                //printf("L506_MQTT_START_CMD error\r\n");
            }
            else if(strcmp(L506_cmd_info.cmd,L506_MQTT_SUB_CMD) == 0)
            {   
                //printf("L506_MQTT_START_CMD error\r\n");
            }
            else if(strcmp(L506_cmd_info.cmd,L506_MQTT_CLOSE_CMD) == 0)
            {   
                //printf("L506_MQTT_START_CMD error\r\n");
            }            
            
            if(is_ota_check == 1 && is_L506_fogcloud_init == 0)
            {
                if(mqtt_init_step < MQTT_MAX_STEP)
                {
                    L506_mqtt_close();
                    goto exit;
                }
            
            }
            
          
        }
        else if(L506_cmd_info.cmd_result == CMD_TIMEOUT)
        {
            L506_LOG("%s",rx_buff);
          
            L506_cmd_info.timeout_times += 1;
            L506_cmd_info.Is_wait_data = 0;
          
            //按下组合键了，正在检测信号
//            if(Is_signal_check == 1)
//            {
//                signal_check_err_times += 1;
//            }
          
            if(Is_http == 1)
            {              
                L506_http_close();
                goto exit;
            }
            
            if(strcmp(L506_cmd_info.cmd,L506_CSQ_CMD) == 0)
            {     
                //获取信号质量            
                //printf("get signal quality timeout\r\n");
            }
            else if(strcmp(L506_cmd_info.cmd,L506_CICCID_CMD) == 0)
            {     
                //读取SIM 卡CCID            
                //printf("L506_QCCID_CMD timeout\r\n");
            }
            else if(strcmp(L506_cmd_info.cmd,L506_HTTPS_START_CMD) == 0)
            {   
                //printf("L506_HTTPS_START_CMD error\r\n");
            }
            else if(strcmp(L506_cmd_info.cmd,L506_HTTPSPOSE_RES) == 0)
            {   
                //printf("L506_HTTPSPOSE_RES error\r\n");
            }
            else if(strcmp(L506_cmd_info.cmd,L506_HTTPSSEND_CMD) == 0)
            {   
                //printf("L506_HTTPSSEND_CMD error\r\n");
            }
            else if(strcmp(L506_cmd_info.cmd,L506_HTTPSRECV_CMD) == 0)
            {   
                //printf("L506_HTTPSRECV_CMD error\r\n");
            }
            else if(strcmp(L506_cmd_info.cmd,L506_HTTPSCLOSE_CMD) == 0)
            {   
                //printf("L506_HTTPSCLOSE_CMD error\r\n");
            }
                          
            
            if(is_ota_check == 1 && is_L506_fogcloud_init == 0)
            {
                if(mqtt_init_step < MQTT_MAX_STEP)
                {
                    L506_mqtt_close();
                    goto exit;
                }           
            }
            
        }
        
        //因为处理mqtt消息的函数在此函数的前面，所以有mqtt消息的话肯定已经处理了，把缓冲区清掉
        exit:
        empty_rx_buff(rx_buff,index);
        L506_cmd_info.Is_wait_data = 0;
    }

}




void empty_rx_buff(char *rx_buff,uint16_t *index)
{
    if(rx_buff == NULL)
    {
        return;
    }
    memset(rx_buff,0,*index);
    //printf("index:%d\r\n",*index);
    *index = 0;
    
}



int L506_Send_data(unsigned char type,const char *cmd,const char *http_requeset,uint16_t http_requeset_length)
{
    int res = 0;
    char *pbuff = NULL;
  
    if(L506_cmd_info.Is_wait_data == 1)
    {
        res = L506_BUSY;
        goto exit;
    }
    
    if(type != CMD_TYPE && type != STRING_TYPE)
    {
        res = PARAMETER_ERROR;
        goto exit;
    }
    
    if(type > CMD_TYPE)
    {
        res = PARAMETER_ERROR;
        goto exit;
    }
    
    memset(L506_cmd_info.end_flag,0,sizeof(L506_cmd_info.end_flag));
  
    if(type == CMD_TYPE)
    { 
        pbuff = mymalloc(150);
        memset(pbuff,0,150);
      
        if(strcmp(cmd,L506_ATI_CMD) == 0)
        {
            strcpy(L506_cmd_info.end_flag,END_OK);
        }
        else if(strcmp(cmd,L506_DISABLE_CMD_ECHO_CMD) == 0)
        {
            sprintf(pbuff,"%s%s",L506_DISABLE_CMD_ECHO_CMD,L506_CMD_END_FLAG);
            strcpy(L506_cmd_info.end_flag,END_OK);
        }
        else if(strcmp(cmd,L506_CSQ_CMD) == 0)
        {
            sprintf(pbuff,"%s%s",L506_CSQ_CMD,L506_CMD_END_FLAG);
            strcpy(L506_cmd_info.end_flag,END_OK);
        }
        else if(strcmp(cmd,L506_GSN_CMD) == 0)
        {
            strcpy(L506_cmd_info.end_flag,END_OK);
        }
        else if(strcmp(cmd,L506_CICCID_CMD) == 0)
        {
            sprintf(pbuff,"%s%s",L506_CICCID_CMD,L506_CMD_END_FLAG);
            strcpy(L506_cmd_info.end_flag,END_OK);
        }
        else if(strcmp(cmd,L506_QSPN_CMD) == 0)
        {
            strcpy(L506_cmd_info.end_flag,END_OK);
        }
        else if(strcmp(cmd,L506_HTTPS_START_CMD) == 0)     //https
        {
            sprintf(pbuff,"%s%s",L506_HTTPS_START_CMD,L506_CMD_END_FLAG);
            strcpy(L506_cmd_info.end_flag,L506_HTTPS_START_RES);
        }
        else if(strcmp(cmd,L506_HTTPSPOSE_CMD) == 0)    
        {
            sprintf(pbuff,"%s=%s,%d,2%s",L506_HTTPSPOSE_CMD,HTTPS_SERVER_ADDR,HTTPS_PORT,L506_CMD_END_FLAG);
            strcpy(L506_cmd_info.end_flag,L506_HTTPSPOSE_RES);
        }
        else if(strcmp(cmd,L506_HTTPSSEND_NZ_CMD) == 0)   
        {          
            sprintf(pbuff,"%s=%d%s",L506_HTTPSSEND_CMD,http_requeset_length,L506_CMD_END_FLAG);
            strcpy(L506_cmd_info.end_flag,L506_HTTPSSEND_NZ_RES);                
        }
        else if(strcmp(cmd,L506_HTTPS_SEND_REQUEST_CMD) == 0)   
        {
            //L506_HTTPS_SEND_REQUEST_CMD命令发送的是http请求的字符串，并不是真正的命令
            strcpy(L506_cmd_info.end_flag,L506_HTTPS_SEND_REQUEST_RES);                
        }
        else if(strcmp(cmd,L506_HTTPSSEND_Z_CMD) == 0)   
        {          
            sprintf(pbuff,"%s%s",L506_HTTPSSEND_CMD,L506_CMD_END_FLAG);
            strcpy(L506_cmd_info.end_flag,L506_HTTPSSEND_Z_RES);                
        }
        else if(strcmp(cmd,L506_HTTPSRECV_CMD) == 0)   
        {
            sprintf(pbuff,"%s=%d%s",L506_HTTPSRECV_CMD,UART_L506_RX_BUFF_SIZE,L506_CMD_END_FLAG);
            strcpy(L506_cmd_info.end_flag,L506_HTTPSRECV_RES);
        }
        else if(strcmp(cmd,L506_HTTPSCLOSE_CMD) == 0)   
        {
            sprintf(pbuff,"%s%s",L506_HTTPSCLOSE_CMD,L506_CMD_END_FLAG);
            strcpy(L506_cmd_info.end_flag,L506_HTTPSCLOSE_RES);
        }
        else if(strcmp(cmd,L506_HTTPSSTOP_CMD) == 0)   
        {
            sprintf(pbuff,"%s%s",L506_HTTPSSTOP_CMD,L506_CMD_END_FLAG);
            strcpy(L506_cmd_info.end_flag,L506_HTTPSSTOP_RES);
          
            if(https_req_res.http_body != NULL)
            {
                //printf("free send http_body\r\n");
                myfree(https_req_res.http_body);
                https_req_res.http_body = NULL;
            }
            
            if(https_req_res.header != NULL)
            {
                //printf("free http header\r\n");
                myfree(https_req_res.header);
                https_req_res.header = NULL;
            }
            
            if(https_req_res.jwt != NULL)
            {
                myfree(https_req_res.jwt);
                https_req_res.jwt = NULL;
            }
        }
        
        else if(strcmp(cmd,L506_MQTT_SSL_CMD) == 0)
        {
            sprintf(pbuff,"%s=0%s",L506_MQTT_SSL_CMD,L506_CMD_END_FLAG);
            strcpy(L506_cmd_info.end_flag,L506_MQTT_SSL_RES);
        }
        else if(strcmp(cmd,L506_MQTT_CONFIG_CMD) == 0)
        {
            sprintf(pbuff,"%s=%s,%s,%d%s",L506_MQTT_CONFIG_CMD,MQTT_CLIENT_ID,device_id,mqtt_passowrd,L506_CMD_END_FLAG);
            strcpy(L506_cmd_info.end_flag,L506_MQTT_CONFIG_RES);
        }
        else if(strcmp(cmd,L506_MQTT_START_CMD) == 0)
        {
            sprintf(pbuff,"%s=%s,%d%s",L506_MQTT_START_CMD,MQTT_SERVER_ADDR,MQTT_PORT,L506_CMD_END_FLAG);
            strcpy(L506_cmd_info.end_flag,L506_MQTT_START_RES);
        }
        else if(strcmp(cmd,L506_MQTT_CONNECT_CMD) == 0)
        {
            sprintf(pbuff,"%s=%d,%d%s",L506_MQTT_CONNECT_CMD,MQTT_CLEAN_SESSION,MQTT_KEEP_ALIVE_TIME,L506_CMD_END_FLAG);
            strcpy(L506_cmd_info.end_flag,L506_MQTT_CONNECT_RES);
        }
        else if(strcmp(cmd,L506_MQTT_SUB_CMD) == 0)
        {
            sprintf(pbuff,"%s=c2d/%s/commands,%d%s",L506_MQTT_SUB_CMD,device_id,MQTT_MESSAGE_QOS,L506_CMD_END_FLAG);
            strcpy(L506_cmd_info.end_flag,L506_MQTT_SUB_RES);
        }
        else if(strcmp(cmd,L506_MQTT_CLOSE_CMD) == 0)
        {
            sprintf(pbuff,"%s%s",L506_MQTT_CLOSE_CMD,L506_CMD_END_FLAG);
            strcpy(L506_cmd_info.end_flag,L506_MQTT_CLOSE_RES);
        }
        else if(strcmp(cmd,L506_MQTT_GET_STATUS_CMD) == 0)
        {
            sprintf(pbuff,"%s%s",L506_MQTT_GET_STATUS_CMD,L506_CMD_END_FLAG);
            strcpy(L506_cmd_info.end_flag,L506_MQTT_GET_STATUS_RES);
        }
    }
    else
    {
        strcpy(L506_cmd_info.end_flag,END_OK);
    }
     
    
    L506_cmd_info.cmd_result = CMD_WAIT;
    
    //L506_HTTSSTRING_CMD命令起始发送的是http请求的字符串，并不是真正的命令
    if(type == CMD_TYPE && strcmp(cmd,L506_HTTPS_SEND_REQUEST_CMD))
    {
       uart_L506_sendbytes((uint8_t *)pbuff,strlen(pbuff));
    }
    else 
    {
        uart_L506_sendbytes((uint8_t *)http_requeset,strlen(http_requeset));
    }
    
    
    L506_cmd_info.cmd_send_time = OSTimeGet();
    
    if(type == CMD_TYPE && strcmp(cmd,L506_HTTPS_SEND_REQUEST_CMD))
    {
        L506_LOG("%s",pbuff);
    }
    else 
    {
        L506_LOG("%s",http_requeset);
    }
    

    
  //此处需设置
    L506_cmd_info.Is_wait_data = 1;
    
    if(pbuff != NULL)
    {
        myfree(pbuff);
    }
    else
    {
        printf("pbuff == NULL\r\n");
    }
    
    //OSTimeDlyHMSM(0,0,0,300);   
    
    return L506_OK;
    
exit:
    
    if(pbuff != NULL)
    {
        myfree(pbuff);
    }    

    return res;


}




//不知道什么原因，给模块发送数据的时候数据包不能太大，太大会导致模块处理不了，所以数据量大的时候分几部分发，每发送一部分要延时一会
//数据上传时，分3部分发送，第一部分是header,第二部分jwt部分，第三部分http_body部分
void L506_http_loop(void)
{
    INT8U err;
  
    //char *http_requeset = NULL;
    static uint16_t http_body_length = 0;
    uint16_t http_request_length = 0;
  
  
    if(L506_cmd_info.Is_wait_data == 1 || mqtt_action != 0 || is_https_action == 0)
    {
        return;
    }
    
    if(Is_http == 0)
    {
        return;
    }
    
    
    memset(L506_cmd_info.cmd,0,sizeof(L506_cmd_info.cmd));
    
    if(https_step == 0)
    {
        //http open
        L506_cmd_info.type = CMD_TYPE;       
        strcpy(L506_cmd_info.cmd,L506_HTTPS_START_CMD);   

        https_req_res.upload_msg = OSQPend(upload_data_queue,10,&err);
        if(err != OS_ERR_NONE || https_req_res.upload_msg == NULL)
        {
            L506_LOG("http loop push msg fail");
            goto https_step0_error;
        }
        
        L506_action = https_req_res.upload_msg->action;
        save_http_session_id(https_req_res.upload_msg->http_id);
    }
    else if(https_step == 1)
    {
        L506_cmd_info.type = CMD_TYPE;       
        strcpy(L506_cmd_info.cmd,L506_HTTPSPOSE_CMD);    
    }
    else if(https_step == 2)
    {  
        //printf("malloc http header\r\n");
        https_req_res.header = mymalloc(HTTP_HEADER_LENGTH);
        if(https_req_res.header == NULL)
        {
            L506_LOG("http_request malloc fail");
            goto error;
        }
        memset(https_req_res.header,0,HTTP_HEADER_LENGTH);
        
        if(https_req_res.upload_msg->is_jwt == 1)
        {
            https_req_res.jwt = mymalloc(HTTP_JWT_LENGTH);
            if(https_req_res.jwt == NULL)
            {
                L506_LOG("jwt malloc fail");
                goto error;
            }
            memset(https_req_res.jwt,0,HTTP_JWT_LENGTH);
        }

        //printf("malloc send http_body\r\n");        
        https_req_res.http_body = mymalloc(HTTP_BODY_LENGTH);
        if(https_req_res.http_body == NULL)
        {
            L506_LOG("http_body malloc fail");
            goto error;
        }
        
        
        if(L506_BIT_CHECK(L506_action,HTTP_ACTIVATE))
        {
            mqtt_passowrd = OSTimeGet() % 10000;
            sprintf(https_req_res.header, "%s %s HTTP/1.1\r\n", HTTP_HEAD_METHOD_POST, FOG_V2_ACTIVATE_URI);
            sprintf(https_req_res.http_body,"{\"product_id\":\"%s\",\"mac\":\"%s\",\"devicepw\":\"%d\",\"mxchipsn\":\"%s\"}\r\n",PRODUCT_ID,ccid,mqtt_passowrd,MXCHIPSN);
        }
        if(L506_BIT_CHECK(L506_action,HTTP_TOKEN_AUTH))
        {
            sprintf(https_req_res.header, "%s %s HTTP/1.1\r\n", HTTP_HEAD_METHOD_POST, FOG_V2_GET_TOKEN_URI);
            sprintf(https_req_res.http_body,"{\"deviceid\":\"%s\",\"password\":\"%d\"}\r\n",device_id,mqtt_passowrd);
        }
        else if(L506_BIT_CHECK(L506_action,HTTP_OTA))
        {
            sprintf(https_req_res.header, "%s %s HTTP/1.1\r\n", HTTP_HEAD_METHOD_POST, FOG_V2_OTA_UP_DATA_URI);
            sprintf(https_req_res.http_body,"{\"product_id\":\"%s\",\"firmware_type\":\"%s\",\"modulename\":\"%s\",\"firmware\":\"%s\"}\r\n",PRODUCT_ID,IOT_VERSION,MODULE_NAME,FIRMWARE_VERSION);
        }
        else if(L506_BIT_CHECK(L506_action,HTTP_UPLOAD_DATA))
        {
            sprintf(https_req_res.header, "%s %s HTTP/1.1\r\n", HTTP_HEAD_METHOD_POST, FOG_V2_SEND_EVENT_URI);
            sprintf(https_req_res.http_body,"{\"deviceid\":\"%s\",\"devicepw\":\"%d\",\"payload\":\"{%s}\",\"format\":\"json\",\"flag\":%d}\r\n",device_id,mqtt_passowrd,https_req_res.upload_msg->payload,https_req_res.upload_msg->save_flag);
        
        }
        else if(L506_BIT_CHECK(L506_action,HTTP_C_CONFIRM))
        {
            sprintf(https_req_res.header, "%s %s HTTP/1.1\r\n", HTTP_HEAD_METHOD_POST, FOG_V2_CHIPS_CONFIRM_URI);
            sprintf(https_req_res.http_body,"{\"orderNo\":\"%s\",\"type\":\"1\",\"status\":\"2\",\"chips\":%d}\r\n",order_num,100);
        }
        else if(L506_BIT_CHECK(L506_action,HTTP_FACTORY_CHECK))
        {
            sprintf(https_req_res.header, "%s %s HTTP/1.1\r\n", HTTP_HEAD_METHOD_POST, FOG_V2_EXAM_UPLOAD_URI);
        }
        
        http_body_length = strlen(https_req_res.http_body);
        
        
        sprintf(https_req_res.header + strlen(https_req_res.header), "Host: %s\r\n", HTTPS_SERVER_ADDR);
        sprintf(https_req_res.header + strlen(https_req_res.header), "Content-Type: application/json;charset=UTF-8\r\n");
        sprintf(https_req_res.header + strlen(https_req_res.header), "Connection: Keepalive\r\n");
        
        if(https_req_res.upload_msg->is_jwt == 1)
        {
            sprintf(https_req_res.jwt, "Authorization: JWT %s\r\n\r\n", token_buff);
            http_request_length = strlen(https_req_res.header) + http_body_length + strlen(https_req_res.jwt);
        }
        else
        {
            strcat(https_req_res.header,L506_CMD_END_FLAG);
            http_request_length = strlen(https_req_res.header) + http_body_length;
        }
           
          
        L506_cmd_info.type = CMD_TYPE;       
        strcpy(L506_cmd_info.cmd,L506_HTTPSSEND_NZ_CMD); 
    }
    else if(https_step == 3)
    {
        //发送的http request数据量较大，必须分几次发送，否则模块会异常。先发送http header,然后发送jwt,最后发送http body,且中间要延时
        uart_L506_sendbytes((uint8_t *)https_req_res.header,strlen(https_req_res.header));
        OSTimeDlyHMSM(0,0,0,30); 
        L506_LOG("%s",https_req_res.header);
        if(https_req_res.upload_msg->is_jwt == 1)
        {
            uart_L506_sendbytes((uint8_t *)https_req_res.jwt,strlen(https_req_res.jwt));
            OSTimeDlyHMSM(0,0,0,30); 
            L506_LOG("%s",https_req_res.jwt);
        }
        
      
        L506_cmd_info.type = CMD_TYPE;       
        strcpy(L506_cmd_info.cmd,L506_HTTPS_SEND_REQUEST_CMD);
    }
    else if(https_step == 4)
    {
        L506_cmd_info.type = CMD_TYPE;       
        strcpy(L506_cmd_info.cmd,L506_HTTPSSEND_Z_CMD);
    }
    else if(https_step == 5)
    {
        L506_cmd_info.type = CMD_TYPE;       
        strcpy(L506_cmd_info.cmd,L506_HTTPSRECV_CMD);
    }
    else if(https_step == 6)
    {
        L506_cmd_info.type = CMD_TYPE;       
        strcpy(L506_cmd_info.cmd,L506_HTTPSCLOSE_CMD);
    }
    else if(https_step == 7)
    {
        L506_cmd_info.type = CMD_TYPE;       
        strcpy(L506_cmd_info.cmd,L506_HTTPSSTOP_CMD);
    }

    
    //L506_Send_data(L506_cmd_info.type,L506_cmd_info.cmd,g_http_requeset,http_request_length);
    L506_Send_data(L506_cmd_info.type,L506_cmd_info.cmd,https_req_res.http_body,http_request_length);
    
    
    return;
    
    
error:

    L506_LOG("http loop malloc fail");
    L506_http_close();
    return;
    
https_step0_error:
    
    Is_http = 0;
    

}


void L506_Get_Signal_Quality(void)
{
    //unsigned char res = 0;
  
    if(L506_cmd_info.Is_wait_data == 1 || Is_http == 1)
    {
        return;
    }
    
    memset(L506_cmd_info.cmd,0,sizeof(L506_cmd_info.cmd));
   
    L506_cmd_info.type = CMD_TYPE;      
    strcpy(L506_cmd_info.cmd,L506_CSQ_CMD);   
             
    L506_Send_data(L506_cmd_info.type,L506_cmd_info.cmd,NULL,0);

    //信号质量最大是99,如果数码管显示100则模块可能有问题
    signal_quality = 100;    
    
}

void L506_Disnable_Command_Echo(void)
{
    //unsigned char res = 0;
  
    if(L506_cmd_info.Is_wait_data == 1 || Is_http == 1)
    {
        return;
    }
    
    memset(L506_cmd_info.cmd,0,sizeof(L506_cmd_info.cmd));
   
    L506_cmd_info.type = CMD_TYPE;      
    strcpy(L506_cmd_info.cmd,L506_DISABLE_CMD_ECHO_CMD);   

    L506_Send_data(L506_cmd_info.type,L506_cmd_info.cmd,NULL,0);    
    
}

void L506_Get_CCID(void)
{
    //unsigned char res = 0;
  
    if(L506_cmd_info.Is_wait_data == 1 || Is_http == 1)
    {
        return;
    }
    
    memset(L506_cmd_info.cmd,0,sizeof(L506_cmd_info.cmd));
   
    L506_cmd_info.type = CMD_TYPE;      
    strcpy(L506_cmd_info.cmd,L506_CICCID_CMD);   

    L506_Send_data(L506_cmd_info.type,L506_cmd_info.cmd,NULL,0);    
    
}

void L506_http_close(void)
{   
    memset(L506_cmd_info.cmd,0,sizeof(L506_cmd_info.cmd));
   
    L506_cmd_info.type = CMD_TYPE;      
    strcpy(L506_cmd_info.cmd,L506_HTTPSSTOP_CMD);   

    L506_Send_data(L506_cmd_info.type,L506_cmd_info.cmd,NULL,0);  
   
    OSTimeDlyHMSM(0,0,5,0);

    Is_http = 0;
    https_step = 0;
    L506_action = 0;  
}


void L506_Event_Scan(void)
{  
    INT8U err = 0;
    mqtt_action_cmd_t *mqtt_action_cmd = NULL;
  
    if(L506_cmd_info.Is_wait_data == 1)
    {
        return;
    }
    else
    {
        if(is_https_action == 0 && mqtt_action == 0)
        {
            return;
        }
    }

    if(!is_queue_empty(mqtt_action_cmd_queue))
    {
        //L506_LOG("mqtt_action_cmd_queue not empty");
        mqtt_action_cmd = OSQPend(mqtt_action_cmd_queue,10,&err);
        if(err != OS_ERR_NONE || mqtt_action_cmd == NULL)
        {
            L506_LOG("get mqtt cmd fail");
            return;
        }
        //L506_LOG("mqtt_action_cmd:%p",mqtt_action_cmd);
        
        L506_LOG("mqtt cmd:%d",mqtt_action_cmd->cmd);
        if(mqtt_action_cmd->cmd == MQTT_INIT_ACTION)
        {
            L506_LOG("scan MQTT_INIT_ACTION");
            mqtt_action = MQTT_INIT_ACTION; 
            mqtt_init_step = 0;           
        }
        else if(mqtt_action_cmd->cmd == MQTT_GET_CONNECT_STATUS_ACTION)
        {
            L506_LOG("scan MQTT_GET_CONNECT_STATUS_ACTION");
            mqtt_action = MQTT_GET_CONNECT_STATUS_ACTION; 
            is_send_get_mqtt_status_cmd = 1;            
        }
        else
        {
            return;
        }

        
    }    
    //如果消息队列为空，则返回
    if(!is_queue_empty(upload_data_queue))
    {
        Is_http = 1; 
        https_step = 0;
        return;
    }    
   
}

int string_get_int(const char *string)
{
    unsigned char index_start = 0;
    unsigned char index_end = 0;
    unsigned char i = 0;

    //char buff[6] = {0};
  
    //查找字符串中的数字
    for(i = 0;i < 15;i ++)
    {
        if(*(string + i) == ASCII_COLONS)
        {
            if(*(string + i + 1) != ASCII_QUOTES)
            {
                index_start = i + 1;
            }
            else
            {
                index_start = i + 2;
            }
            
        }
        if(*(string + i) == ASCII_COMMA || *(string + i) == ASCII_BRANCE_CLOSE || *(string + i) == '\r')
        {
            if(*(string + i - 1) != ASCII_QUOTES)
            {
                index_end = i - 1;
            }
            else
            {
                index_end = i - 2;
            }
            
            break;
        }
    }
    
   
    if(index_end < index_start)
    {
       return -1; 
    }
    else
    {
        if(index_start == 0 || (index_end - index_start) > 5)
        {
            return -1;
        }
    }
     
    memset(L506_cmd_info.sendtring,0,strlen(L506_cmd_info.sendtring));
    strncpy(L506_cmd_info.sendtring,(string + index_start),(index_end - index_start + 1));
    
    
    return(atoi(L506_cmd_info.sendtring));

}

long string_get_long(const char *string)
{
    unsigned char index_start = 0;
    unsigned char index_end = 0;
    unsigned char i = 0;
  
    //char buff[6] = {0};
  
    for(i = 0;i < 15;i ++)
    {
        if(*(string + i) == ASCII_COLONS)
        {
            index_start = i + 1;
        }
        if(*(string + i) == ASCII_COMMA || *(string + i) == ASCII_BRANCE_CLOSE)
        {
            index_end = i - 1;
            break;
        }
    }
    
    if(index_end < index_start)
    {
       return -1; 
    }
    else
    {
        if((index_end - index_start) > 5)
        {
            return -1;
        }
    }
     
    memset(L506_cmd_info.sendtring,0,strlen(L506_cmd_info.sendtring));
    strncpy(L506_cmd_info.sendtring,(string + index_start),(index_end - index_start + 1));
    
    return(atol(L506_cmd_info.sendtring));

}


void string_get_string(const char *string,char *dest)
{
    //该函数中不要使用L506_cmd_info.string，ordernum复制到了该数组中
    unsigned char index_start = 0;
    unsigned char index_end = 0;
    unsigned char i = 0;

    for(i = 0;i < 50;i ++)
    {
        if(*(string + i) == ASCII_COLONS)
        {
            index_start = i + 2;
        }
        if(*(string + i) == ASCII_QUOTES && (*(string + i + 1) == ASCII_BRANCE_CLOSE || *(string + i + 1) == ASCII_COMMA))
        {
            index_end = i - 1;
            break;
        }
    }
    


    if(index_end < index_start || i == 50)
    {
        return;
    }
    else
    {
        if((index_end - index_start) > 40)
        {
            return;
        }
    }
    memset(dest,0,strlen(dest));
    strncpy(dest,(string + index_start),(index_end - index_start + 1));  

}


void Wifi_Led_On(void)
{
    if(wifi_led_state == 0)
    {
        //TM1620_LED_Control(LED_WIFI,LED_ON);
        wifi_led_state = 1;
    }
}

void Wifi_Led_Off(void)
{
    if(wifi_led_state == 1)
    {
        //TM1620_LED_Control(LED_WIFI,LED_OFF);
        wifi_led_state = 0;
    }
}

void L506_signal_check(void)
{
//    static unsigned char signal_check_stimes = 0;
//    //记录检测了多长时间，单位是秒，暂定检测1分钟。如果检测时间长的话需要修改变量类型
//    if(Is_signal_check == 0)
//    {
//        if(signal_check_stimes != 0)
//        {
//            signal_check_stimes = 0;
//        }
//        return;
//    }
//    
//    signal_check_stimes += 1;
//    
//    //TM1620_DispalyData(2,signal_quality);
//    
//    L506_Get_Signal_Quality();
//       
//    if(signal_check_stimes >= SIGNAL_CHECK_TIME_INTERVAL)
//    {
//        Is_signal_check = 0;
//    }   
}



void L506_mqtt_loop(void)
{
    //if(is_mqtt_init == 1 || is_ota_check == 0)
    if(L506_cmd_info.Is_wait_data == 1 || is_https_action == 1 || mqtt_action == 0)
    {
        return;
    }
  
    if(mqtt_action == MQTT_INIT_ACTION)
    {
        if(is_mqtt_inited == 1 || mqtt_init_step >= MQTT_MAX_STEP)
        {
            return;
        }
        
        if(mqtt_init_step == 0)
        {
            L506_cmd_info.type = CMD_TYPE;       
            strcpy(L506_cmd_info.cmd,L506_MQTT_SSL_CMD);
        }
        else if(mqtt_init_step == 1)
        {
            L506_cmd_info.type = CMD_TYPE;       
            strcpy(L506_cmd_info.cmd,L506_MQTT_CONFIG_CMD);
        }
        else if(mqtt_init_step == 2)
        {
            L506_cmd_info.type = CMD_TYPE;       
            strcpy(L506_cmd_info.cmd,L506_MQTT_START_CMD);
        }
        else if(mqtt_init_step == 3)
        {
            L506_cmd_info.type = CMD_TYPE;       
            strcpy(L506_cmd_info.cmd,L506_MQTT_CONNECT_CMD);
        }
        else if(mqtt_init_step == 4)
        {
            L506_cmd_info.type = CMD_TYPE;       
            strcpy(L506_cmd_info.cmd,L506_MQTT_SUB_CMD);
        }
        
        L506_Send_data(L506_cmd_info.type,L506_cmd_info.cmd,NULL,0);
        
    }
    else if(mqtt_action == MQTT_GET_CONNECT_STATUS_ACTION)
    {
        if(is_send_get_mqtt_status_cmd == 1)
        {
            L506_cmd_info.type = CMD_TYPE; 
            strcpy(L506_cmd_info.cmd,L506_MQTT_GET_STATUS_CMD);  
            L506_Send_data(L506_cmd_info.type,L506_cmd_info.cmd,NULL,0);  
          
            is_send_get_mqtt_status_cmd = 0;
        }
    
    }    

}


void L506_get_mqtt_message(char *rx_buff,uint16_t *index)
{
    INT8U err;
    char *mqtt_start_pos = NULL;
    char *mqtt_stop_pos = NULL;
    char *payload_start_pos = NULL;
    char *payload_end_pos = NULL;
    uint16_t payload_length = 0;
  
    char *payload = NULL;
  
    if(is_mqtt_inited == 0 || rx_buff == NULL || *index == 0)
    {
        return;
    }
    
    mqtt_start_pos = strstr(rx_buff,MQTT_MSG_START_FLAG);
    if(mqtt_start_pos != NULL)
    {

        
        mqtt_stop_pos = strstr(mqtt_start_pos,MQTT_MSG_STOP_FLAG);
        if(mqtt_stop_pos != NULL)
        {
            payload_start_pos = strstr(mqtt_start_pos,MQTT_PAYLOAD_START_FLAG);
            if(payload_start_pos != NULL)
            {
                if(payload_start_pos > mqtt_stop_pos)
                {
                    goto exit;
                }
                              
                payload_start_pos += strlen(MQTT_PAYLOAD_START_FLAG);
                payload_end_pos = mqtt_stop_pos - 1;
                
                if(*payload_start_pos != '{' || *payload_end_pos != '}')
                {
                    goto exit;
                }
                
                payload_length = payload_end_pos - payload_start_pos + 1;
                
                if(payload_length > L506_PAYLOAD_MAX_LENGTH)
                {
                    //此条mqtt消息太长，废弃掉
                    L506_LOG("mqtt pyaload too long");
                    if(mqtt_start_pos == rx_buff && (mqtt_stop_pos + 2) == (rx_buff + *index))
                    {
                        empty_rx_buff(rx_buff,index);
                    }
                    else
                    {
                        *mqtt_start_pos = 'A';
                    }
                    
                    goto exit;
                }
                
                //如果消息队列满，先Push一个消息，并且把内存释放掉
                if(is_queue_full(mqtt_message_queue) == QUEUE_FULL)
                {
                    L506_LOG("mqtt queue full,push one message");
                    payload = OSQPend(mqtt_message_queue,10,&err);
                    if(err != OS_ERR_NONE)
                    {
                        L506_LOG("mqtt queue full,push one message fail\r\n");
                        return;
                    }
                    
                    //此处是否需要把从消息队列中Push出来的消息进行处理？？？？？？？？？？？？？
                    
                    //此处一定要释放掉从消息队列中获取的数据，否则内存会泄漏
                    myfree(payload);
                    payload = NULL;
                }
               
                //printf("malloc payload\r\n");
                payload = mymalloc(L506_PAYLAOD_BUFF_SIZE);
                if(payload == NULL)
                {
                    goto exit;
                }
                memset(payload,0,L506_PAYLAOD_BUFF_SIZE);
                
                strncpy(payload,payload_start_pos,payload_length);
                
                //L506_LOG("payload_length=%d",payload_length);

                err = OSQPost(mqtt_message_queue,payload);
                if(err != OS_ERR_NONE)
                {
                    goto exit;
                }
                
                //printf("mqtt_start_pos:%p,rx_buff:%p\r\n",mqtt_start_pos,rx_buff);
                //printf("mqtt_stop_pos:%p,index:%p\r\n",mqtt_stop_pos + 2,rx_buff + *index);
                if((mqtt_stop_pos + 2) == (rx_buff + *index) && L506_cmd_info.Is_wait_data == 0)
                {
                    empty_rx_buff(rx_buff,index);
                    goto exit;
                }
                
                if(mqtt_start_pos == rx_buff && (mqtt_stop_pos + 2) == (rx_buff + *index))
                {
                    empty_rx_buff(rx_buff,index);
                    //printf("mqtt clean rx_buff\r\n");
                }
                else
                {
                    *mqtt_start_pos = 'A';
                    *mqtt_stop_pos = 'A';
                    *(payload_start_pos - strlen(MQTT_PAYLOAD_START_FLAG)) = 'A';
                }
                

            }

        }
    }
    
exit:
      if(payload != NULL)
      {
          myfree(payload);
          payload = NULL;
      } 

}


void L506_mqtt_close(void)
{
    if(Is_http == 1)
    {
        return;
    }

    mymemset(L506_cmd_info.cmd,0,sizeof(L506_cmd_info.cmd));
   
    L506_cmd_info.type = CMD_TYPE;      
    strcpy(L506_cmd_info.cmd,L506_MQTT_CLOSE_CMD);   

    L506_Send_data(L506_cmd_info.type,L506_cmd_info.cmd,NULL,0);   
    
    is_mqtt_inited = 0;
    mqtt_init_step = MQTT_MAX_STEP;
    
    OSTimeDlyHMSM(0,0,5,0);   
}

static uint32_t generate_http_session_id(void)
{
    static uint32_t id = 1;

    return id ++;
}




uint8_t upload_data_event(const char *upload_data,uint8_t save_flag,upload_res_t *res_msg)
{
    INT8U err;
    uint8_t res = UPLOAD_SUCCESS;
    upload_data_msg_t upload_data_msg;
    upload_res_t *upload_res_msg = NULL;
    upload_data_msg_t *temp_msg = NULL;
    uint8_t try_times = 0;
    uint8_t count = 0;
  
    if(is_L506_fogcloud_init == 0)
    {
        res = MODULE_NOT_UP;
        return res;
    }
    
    OSMutexPend(upload_data_mutex,0,&err);
    
    is_https_action = 1;
  
https_start:
  
    if(upload_data == NULL)
    {
        res = UPLOAD_PARA_ERR;
        try_times = HTTPS_MAX_TRY_TIMES;
        goto exit;
    }
    
//    if(mqtt_action != 0)
//    {
//        OSTimeDlyHMSM(0,0,0,500);
//        goto https_start;
//    }
       
    memset(&upload_data_msg,0,sizeof(upload_data_msg));
    //memset(&upload_res_msg,0,sizeof(upload_res_msg));
    
    if(is_queue_full(upload_data_queue) == QUEUE_FULL)
    {
        //消息队列满了，push一个出来
        L506_LOG("upload upload queue full,push one msg");
        temp_msg = OSQPend(upload_data_queue,10,&err);
        if(err != OS_ERR_NONE)
        {
            res = UPLAOD_REQ_QUEUE_ERR;
            goto exit;
        }
        
        //push出来的消息队列必须要释放掉内存空间
        
        myfree(temp_msg->payload);
        temp_msg->payload = NULL;
    }
    
    upload_data_msg.http_id = generate_http_session_id();
    upload_data_msg.action = 0;
    upload_data_msg.action |= (1 << HTTP_UPLOAD_DATA);
    upload_data_msg.save_flag = save_flag;
    upload_data_msg.is_jwt = 1;
    upload_data_msg.payload = (char *)upload_data;
    
    err = OSQPost(upload_data_queue,&upload_data_msg);
    if(err != OS_ERR_NONE)
    {
        L506_LOG("push upload data msg error");
        res = UPLAOD_REQ_QUEUE_ERR;
        goto exit;
    }
    
    upload_res_msg = OSQPend(upload_res_queue,WAIT_HTTP_RES_MAX_TIME,&err);
    if(err != OS_ERR_NONE)
    {
        if(err == OS_ERR_TIMEOUT)
        {
            L506_LOG("upload data timeout");
            res = UPLOAD_TIMEOUT;
        }
        else
        {
            L506_LOG("push from upload res queue err:%d",err);
            res = err;
        }

        goto exit;
    }
    
    if(upload_res_msg == NULL)
    {
        L506_LOG("upload_res_msg == NULL");
        res = UPLOAD_RES_NULL;
        goto exit;
    }
    
    if(upload_res_msg->http_id != upload_data_msg.http_id)
    {
        L506_LOG("http_id error");
        res = UPLOAD_RES_ID_ERR;
        goto exit;
    }
    
    if(res_msg != NULL)
    {
        memcpy(res_msg,upload_res_msg,sizeof(upload_res_t)); 
        strcpy(res_msg->http_body,upload_res_msg->http_body);
    }

    res = UPLOAD_SUCCESS;
       
exit:
    if(upload_res_msg != NULL && upload_res_msg->http_body != NULL)
    {
        //printf("free res http_body\r\n");
        myfree(upload_res_msg->http_body);
        upload_res_msg->http_body = NULL;
        upload_res_msg = NULL;
    }
    
    try_times += 1;
    
    if(res != UPLOAD_SUCCESS && try_times < HTTPS_MAX_TRY_TIMES)
    {
        OSTimeDlyHMSM(0,0,2,0);
        goto https_start;
    }
    
    //延时10ms等待发送完http close和stop命令，然后再释放锁
    while(Is_http && (count < 200))
    {
        OSTimeDlyHMSM(0,0,0,10);
        count += 1;
    }
    
    
    is_https_action = 0;
    
    OSMutexPost(upload_data_mutex);
    
    return res;

}




uint8_t device_activate_event(void)
{
    INT8U err;
    uint8_t res = UPLOAD_SUCCESS;
    upload_data_msg_t upload_data_msg;
    upload_res_t *upload_res_msg = NULL;
    upload_data_msg_t *temp_msg = NULL;
  
    cJSON *root = NULL;     
    cJSON *meta_item = NULL; 
    cJSON *code_item = NULL;  
    cJSON *data_item = NULL;  
    cJSON *deviceid_item = NULL; 
  
    int32_t code = 0;
    uint8_t try_times = 0;
  
    //这个锁锁住的资源比较多，时间可能会比较长
    OSMutexPend(upload_data_mutex,0,&err);
  
    is_https_action = 1;
    
https_start:
  
    if(L506_register_net.Is_L506_registerd == 0 || Is_Get_CCID == 0)
    {
        res = MODULE_NOT_UP;
        try_times = HTTPS_MAX_TRY_TIMES;
        goto exit;
    }
   
    memset(&upload_data_msg,0,sizeof(upload_data_msg));
    
    if(is_queue_full(upload_data_queue) == QUEUE_FULL)
    {
        //消息队列满了，push一个出来
        L506_LOG("activate upload queue full,push one");
        temp_msg = OSQPend(upload_data_queue,10,&err);
        if(err != OS_ERR_NONE)
        {
            res = UPLAOD_REQ_QUEUE_ERR;
            goto exit;
        }
        
        //push出来的消息队列必须要释放掉内存空间
        if(temp_msg->payload != NULL)
        {
            myfree(temp_msg->payload);
            temp_msg->payload = NULL;
        }
    }
    
    upload_data_msg.http_id = generate_http_session_id();
    upload_data_msg.action = 0;
    upload_data_msg.action |= (1 << HTTP_ACTIVATE);
    upload_data_msg.save_flag = 0;
    upload_data_msg.is_jwt = 0;
    upload_data_msg.payload = NULL;
    
    err = OSQPost(upload_data_queue,&upload_data_msg);
    if(err != OS_ERR_NONE)
    {
        L506_LOG("push upload data msg error");
        res = UPLAOD_REQ_QUEUE_ERR;
        goto exit;
    }
    
    L506_LOG("wait for activate");
    upload_res_msg = OSQPend(upload_res_queue,WAIT_HTTP_RES_MAX_TIME,&err);
    if(err != OS_ERR_NONE)
    {
        if(err == OS_ERR_TIMEOUT)
        {
            L506_LOG("device_activate timeout");
            res = UPLOAD_TIMEOUT;
        }
        else
        {
            L506_LOG("push from upload res queue err:%d",err);
            res = err;
        }

        goto exit;
    }
    
    if(upload_res_msg == NULL)
    {
        L506_LOG("upload_res_msg == NULL");
        res = UPLOAD_RES_NULL;
        goto exit;
    }
    
    if(upload_res_msg->http_id != upload_data_msg.http_id)
    {
        if(upload_res_msg->http_id == 0)
        {
          L506_LOG("res http id == 0");
        }
        else
        {
            L506_LOG("http_id error");
        }
        
        res = UPLOAD_RES_ID_ERR;
        goto exit;
    }
    
    
    //printf("%s\r\n",upload_res_msg->http_body);
    root = cJSON_Parse(upload_res_msg->http_body);
    if(root == NULL)
    {
        L506_LOG("json string formot error");
        res = JSON_ITEM_ERR;
        goto exit;
    }
    
    meta_item = cJSON_GetObjectItem(root,"meta");
    if(meta_item == NULL)
    {
        L506_LOG("not find meta_item");
        res = JSON_ITEM_ERR;
        goto exit;
    }
    
    code_item = cJSON_GetObjectItem(meta_item,"code");
    if(code_item == NULL)
    {
        L506_LOG("not find code item");
        res = JSON_ITEM_ERR;
        goto exit;
    }
    
    data_item = cJSON_GetObjectItem(root,"data");
    if(data_item == NULL)
    {
        L506_LOG("not find data_item");
        res = JSON_ITEM_ERR;
        goto exit;
    }
    
    deviceid_item = cJSON_GetObjectItem(data_item,"deviceid");
    if(deviceid_item == NULL)
    {
        L506_LOG("not find code item");
        res = JSON_ITEM_ERR;
        goto exit;
    }
       
    code = code_item->valueint;   
    if(code == 0)
    {
        Is_device_activate = 1;
        strcpy(device_id,deviceid_item->valuestring);
        L506_LOG("device_id:%s",device_id);
    }
    else
    {
        L506_LOG("code = %d",code);
    }
    
    res = UPLOAD_SUCCESS;
       
exit:
    
    if(deviceid_item != NULL)
    {
        cJSON_Delete(deviceid_item);
    }
    
    if(data_item != NULL)
    {
        cJSON_Delete(data_item);
    }
    
    if(code_item != NULL)
    {
        cJSON_Delete(code_item);
    }
    
    if(meta_item != NULL)
    {
        cJSON_Delete(meta_item);
    }
    
    if(root != NULL)
    {
        cJSON_Delete(root);
    }
    
      
    if(upload_res_msg != NULL && upload_res_msg->http_body != NULL)
    {
        //printf("free res http_body\r\n");
        myfree(upload_res_msg->http_body);       
        upload_res_msg->http_body = NULL;
        upload_res_msg = NULL;
    }
    
      
    try_times += 1;
    
    if(res != UPLOAD_SUCCESS && try_times < HTTPS_MAX_TRY_TIMES)
    {
        OSTimeDlyHMSM(0,0,5,0);
        goto https_start;
    }
    
    //延时10ms等待发送完http close和stop命令，然后再释放锁
    OSTimeDlyHMSM(0,0,0,10);
    
    is_https_action = 0;
    
    OSMutexPost(upload_data_mutex);
    
    return res;

}



uint8_t device_get_token_event(void)
{
    INT8U err;
    uint8_t res = UPLOAD_SUCCESS;
    upload_data_msg_t upload_data_msg;
    upload_res_t *upload_res_msg = NULL;
    upload_data_msg_t *temp_msg = NULL;
  
    cJSON *root = NULL;     
    cJSON *meta_item = NULL; 
    cJSON *code_item = NULL;  
    cJSON *data_item = NULL;  
    cJSON *token_item = NULL; 
  
    int32_t code = 0;
    uint8_t try_times = 0;

      //这个锁锁住的资源比较多，时间可能会比较长
    OSMutexPend(upload_data_mutex,0,&err);
  
    is_https_action = 1;
  
https_start:  
  
    if(L506_register_net.Is_L506_registerd == 0 || Is_Get_CCID == 0 || Is_device_activate == 0)
    {
        res = MODULE_NOT_UP;
        try_times = HTTPS_MAX_TRY_TIMES;
        goto exit;
    }
        
    memset(&upload_data_msg,0,sizeof(upload_data_msg));
    
    if(is_queue_full(upload_data_queue) == QUEUE_FULL)
    {
        //消息队列满了，push一个出来
        L506_LOG("token upload queue full,push one msg");
        temp_msg = OSQPend(upload_data_queue,10,&err);
        if(err != OS_ERR_NONE)
        {
            res = UPLAOD_REQ_QUEUE_ERR;
            goto exit;
        }
        
        //push出来的消息队列必须要释放掉内存空间
        if(temp_msg->payload != NULL)
        {
            myfree(temp_msg->payload);
            temp_msg->payload = NULL;
        }
    }
    
    upload_data_msg.http_id = generate_http_session_id();
    upload_data_msg.action = 0;
    upload_data_msg.action |= (1 << HTTP_TOKEN_AUTH);
    upload_data_msg.save_flag = 0;
    upload_data_msg.is_jwt = 0;
    upload_data_msg.payload = NULL;
    
    err = OSQPost(upload_data_queue,&upload_data_msg);
    if(err != OS_ERR_NONE)
    {
        L506_LOG("push upload data msg error");
        res = UPLAOD_REQ_QUEUE_ERR;
        goto exit;
    }
    
    L506_LOG("wait for get token");
    upload_res_msg = OSQPend(upload_res_queue,WAIT_HTTP_RES_MAX_TIME,&err);
    if(err != OS_ERR_NONE)
    {
        if(err == OS_ERR_TIMEOUT)
        {
            L506_LOG("device get token timeout");
            res = UPLOAD_TIMEOUT;
        }
        else
        {
            L506_LOG("push from upload res queue err:%d",err);
            res = err;
        }

        goto exit;
    }
    
    if(upload_res_msg == NULL)
    {
        L506_LOG("upload_res_msg == NULL");
        res = UPLOAD_RES_NULL;
        goto exit;
    }
    
    if(upload_res_msg->http_id != upload_data_msg.http_id)
    {
        if(upload_res_msg->http_id == 0)
        {
          L506_LOG("res http id == 0");
        }
        else
        {
            L506_LOG("http_id error");
        }
        res = UPLOAD_RES_ID_ERR;
        goto exit;
    }
    
    
    //printf("%s\r\n",upload_res_msg->http_body);
    root = cJSON_Parse(upload_res_msg->http_body);
    if(root == NULL)
    {
        L506_LOG("json string formot error");
        res = JSON_ITEM_ERR;
        goto exit;
    }
    
    meta_item = cJSON_GetObjectItem(root,"meta");
    if(meta_item == NULL)
    {
        L506_LOG("not find meta_item");
        res = JSON_ITEM_ERR;
        goto exit;
    }
    
    code_item = cJSON_GetObjectItem(meta_item,"code");
    if(code_item == NULL)
    {
        L506_LOG("not find code item");
        res = JSON_ITEM_ERR;
        goto exit;
    }
    
    data_item = cJSON_GetObjectItem(root,"data");
    if(data_item == NULL)
    {
        L506_LOG("not find data_item");
        res = JSON_ITEM_ERR;
        goto exit;
    }
    
    token_item = cJSON_GetObjectItem(data_item,"token");
    if(token_item == NULL)
    {
        L506_LOG("not find code item");
        res = JSON_ITEM_ERR;
        goto exit;
    }
       
    code = code_item->valueint;   
    if(code == 0)
    {
        is_get_token = 1;
        strcpy(token_buff,token_item->valuestring);
        //printf("token:%s\r\n",token_buff);
    }
    else
    {
        L506_LOG("token code = %d",code);
    }
    
    res = UPLOAD_SUCCESS;

    
       
exit:
    
    if(token_item != NULL)
    {
        cJSON_Delete(token_item);
    }
    
    if(data_item != NULL)
    {
        cJSON_Delete(data_item);
    }
    
    if(code_item != NULL)
    {
        cJSON_Delete(code_item);
    }
    
    if(meta_item != NULL)
    {
        cJSON_Delete(meta_item);
    }
    
    if(root != NULL)
    {
        cJSON_Delete(root);
    }
      
    if(upload_res_msg != NULL && upload_res_msg->http_body != NULL)
    {
        //printf("free res http_body\r\n");
        myfree(upload_res_msg->http_body);
        upload_res_msg->http_body = NULL;
        upload_res_msg = NULL;
    }
      
    try_times += 1;
    
    if(res != UPLOAD_SUCCESS && try_times < HTTPS_MAX_TRY_TIMES)
    {
        OSTimeDlyHMSM(0,0,5,0);
        goto https_start;
    }
    
    
    //延时10ms等待发送完http close和stop命令，然后再释放锁
    OSTimeDlyHMSM(0,0,0,10);
    
    is_https_action = 0;
    
    OSMutexPost(upload_data_mutex);
    
    return res;

}


uint8_t device_ota_check_event(void)
{
    INT8U err;
    uint8_t res = UPLOAD_SUCCESS;
    upload_data_msg_t upload_data_msg;
    upload_res_t *upload_res_msg = NULL;
    upload_data_msg_t *temp_msg = NULL;
  
    cJSON *root = NULL;     
    cJSON *meta_item = NULL; 
    cJSON *code_item = NULL;  
    cJSON *data_item = NULL;  
    cJSON *ota_status_item = NULL; 
    cJSON *ota_file_item = NULL; 
  
    int32_t code = 0;
    uint8_t try_times = 0;

      //这个锁锁住的资源比较多，时间可能会比较长
    OSMutexPend(upload_data_mutex,0,&err);
  
    is_https_action = 1;
  
https_start:  
  
    if(L506_register_net.Is_L506_registerd == 0 || Is_Get_CCID == 0 || Is_device_activate == 0)
    {
        res = MODULE_NOT_UP;
        try_times = HTTPS_MAX_TRY_TIMES;
        goto exit;
    }
        
    memset(&upload_data_msg,0,sizeof(upload_data_msg));
    
    if(is_queue_full(upload_data_queue) == QUEUE_FULL)
    {
        //消息队列满了，push一个出来
        L506_LOG("ota check upload queue full,push one msg");
        temp_msg = OSQPend(upload_data_queue,10,&err);
        if(err != OS_ERR_NONE)
        {
            res = UPLAOD_REQ_QUEUE_ERR;
            goto exit;
        }
        
        //push出来的消息队列必须要释放掉内存空间
        if(temp_msg->payload != NULL)
        {
            myfree(temp_msg->payload);
            temp_msg->payload = NULL;
        }
    }
    
    upload_data_msg.http_id = generate_http_session_id();
    upload_data_msg.action = 0;
    upload_data_msg.action |= (1 << HTTP_OTA);
    upload_data_msg.save_flag = 0;
    upload_data_msg.is_jwt = 0;
    upload_data_msg.payload = NULL;
    
    err = OSQPost(upload_data_queue,&upload_data_msg);
    if(err != OS_ERR_NONE)
    {
        L506_LOG("push upload data msg error");
        res = UPLAOD_REQ_QUEUE_ERR;
        goto exit;
    }
    
    L506_LOG("wait for ota check");
    upload_res_msg = OSQPend(upload_res_queue,WAIT_HTTP_RES_MAX_TIME,&err);
    if(err != OS_ERR_NONE)
    {
        if(err == OS_ERR_TIMEOUT)
        {
            L506_LOG("device ota check timeout");
            res = UPLOAD_TIMEOUT;
        }
        else
        {
            L506_LOG("push from upload res queue err:%d",err);
            res = err;
        }

        goto exit;
    }
    
    if(upload_res_msg == NULL)
    {
        L506_LOG("upload_res_msg == NULL");
        res = UPLOAD_RES_NULL;
        goto exit;
    }
    
    if(upload_res_msg->http_id != upload_data_msg.http_id)
    {
        if(upload_res_msg->http_id == 0)
        {
          L506_LOG("res http id == 0\r\n");
        }
        else
        {
            L506_LOG("http_id error");
        }
        res = UPLOAD_RES_ID_ERR;
        goto exit;
    }
    
    
    //printf("%s\r\n",upload_res_msg->http_body);
    root = cJSON_Parse(upload_res_msg->http_body);
    if(root == NULL)
    {
        L506_LOG("json string formot error");
        res = JSON_ITEM_ERR;
        goto exit;
    }
    
    meta_item = cJSON_GetObjectItem(root,"meta");
    if(meta_item == NULL)
    {
        L506_LOG("not find meta_item");
        res = JSON_ITEM_ERR;
        goto exit;
    }
    
    code_item = cJSON_GetObjectItem(meta_item,"code");
    if(code_item == NULL)
    {
        L506_LOG("not find code item");
        res = JSON_ITEM_ERR;
        goto exit;
    }
    
    data_item = cJSON_GetObjectItem(root,"data");
    if(data_item == NULL)
    {
        L506_LOG("not find data_item");
        res = JSON_ITEM_ERR;
        goto exit;
    }
    
    ota_status_item = cJSON_GetObjectItem(data_item,"OTAstatus");
    if(ota_status_item == NULL)
    {
        L506_LOG("not find ota_status_item");
        res = JSON_ITEM_ERR;
        goto exit;
    }
    
    ota_file_item = cJSON_GetObjectItem(data_item,"File");
    if(ota_file_item == NULL)
    {
        L506_LOG("not find ota_file_item");
        res = JSON_ITEM_ERR;
        goto exit;
    }
       
    code = code_item->valueint;   
    
    L506_LOG("code = %d",code);
    
    is_ota_check = 1; 
    
    res = UPLOAD_SUCCESS;

    
       
exit:
    
    if(ota_file_item != NULL)
    {
        cJSON_Delete(ota_file_item);
    }
    
    if(ota_status_item != NULL)
    {
        cJSON_Delete(ota_status_item);
    }
    
    if(data_item != NULL)
    {
        cJSON_Delete(data_item);
    }
    
    if(code_item != NULL)
    {
        cJSON_Delete(code_item);
    }
    
    if(meta_item != NULL)
    {
        cJSON_Delete(meta_item);
    }
    
    if(root != NULL)
    {
        cJSON_Delete(root);
    }
      
    if(upload_res_msg != NULL && upload_res_msg->http_body != NULL)
    {
        myfree(upload_res_msg->http_body);
        upload_res_msg->http_body = NULL;
        upload_res_msg = NULL;
    }
      
    try_times += 1;
    
    if(res != UPLOAD_SUCCESS && try_times < HTTPS_MAX_TRY_TIMES)
    {
        OSTimeDlyHMSM(0,0,5,0);
        goto https_start;
    }
    
    
    //延时10ms等待发送完http close和stop命令，然后再释放锁
    OSTimeDlyHMSM(0,0,0,10);
    
    is_https_action = 0;
    
    OSMutexPost(upload_data_mutex);
    
    return res;

}

uint8_t mqtt_init_event(void)
{
    INT8U err;
    uint8_t res = MQTT_ACTION_SUCCESS;
    mqtt_action_cmd_t mqtt_action_cmd_msg;
    mqtt_action_res_t *mqtt_action_res_msg = NULL;
    mqtt_action_cmd_t *temp_msg = NULL;
  
    uint8_t try_times = 0;

      //这个锁锁住的资源比较多，时间可能会比较长
    //OSMutexPend(mqtt_cmd_mutex,0,&err);
    OSMutexPend(upload_data_mutex,0,&err);
    mqtt_action = MQTT_INIT_ACTION;
  
mqtt_init_start:  
  
    if(L506_register_net.Is_L506_registerd == 0 || Is_Get_CCID == 0 || Is_device_activate == 0)
    {
        res = MODULE_NOT_UP;
        try_times = HTTPS_MAX_TRY_TIMES;
        goto exit;
    }
        
    memset(&mqtt_action_cmd_msg,0,sizeof(mqtt_action_cmd_msg));
    
    if(is_queue_full(mqtt_action_cmd_queue) == QUEUE_FULL)
    {
        //消息队列满了，pull一个出来
        L506_LOG("mqtt init queue full,pull one msg");
        temp_msg = OSQPend(mqtt_action_cmd_queue,10,&err);
        if(err != OS_ERR_NONE)
        {
            res = MQTT_CMD_QUEUE_ERR;
            if(temp_msg != NULL)
            {
                temp_msg = NULL;
            }
            goto exit;
        }
    }
    
    mqtt_action_cmd_msg.cmd = MQTT_INIT_ACTION;
    
    err = OSQPost(mqtt_action_cmd_queue,&mqtt_action_cmd_msg);
    if(err != OS_ERR_NONE)
    {
        L506_LOG("push mqtt init msg error");
        res = MQTT_CMD_QUEUE_ERR;
        goto exit;
    }
    
    L506_LOG("wait for mqtt init");
    mqtt_action_res_msg = OSQPend(mqtt_action_res_queue,WAIT_MQTT_INIT_RES_MAX_TIME,&err);
    if(err != OS_ERR_NONE)
    {
        if(err == OS_ERR_TIMEOUT)
        {
            L506_LOG("mqtt init timeout");
            res = MQTT_CMD_RES_TIMEOUT;
        }
        else
        {
            L506_LOG("push from mqtt cmd queue err:%d",err);
            res = err;
        }

        goto exit;
    }
    
    if(mqtt_action_res_msg == NULL)
    {
        L506_LOG("mqtt_action_res_msg == NULL");
        res = MQTT_CMD_RES_NULL;
        goto exit;
    }
    
    if(mqtt_action_res_msg->cmd != mqtt_action_cmd_msg.cmd)
    {
        L506_LOG("mqtt init res cmd err");
        goto exit;
    }
    
    if(mqtt_action_res_msg->result != MQTT_ACTION_SUCCESS)
    {
        L506_LOG("mqtt init cmd fail %d times",(try_times + 1));
        goto exit;
    }
        
    is_mqtt_inited = 1;
    is_L506_fogcloud_init = 1;
    
    L506_LOG("mqtt init success");
  
    res = MQTT_ACTION_SUCCESS;
      
exit:
            
    try_times += 1;
    
    if(res != MQTT_ACTION_SUCCESS && try_times < MQTT_INIT_TRY_MAX_TIME)
    {
        OSTimeDlyHMSM(0,0,5,0);
        goto mqtt_init_start;
    }
    
    mqtt_action = 0;
    
    //OSMutexPost(mqtt_cmd_mutex);
    OSMutexPost(upload_data_mutex);
    return res;

}


uint8_t get_mqtt_connect_status_event(uint8_t *mqtt_status)
{
    INT8U err;
    uint8_t res = MQTT_ACTION_SUCCESS;
    mqtt_action_cmd_t mqtt_action_cmd_msg;
    mqtt_action_res_t *mqtt_action_res_msg = NULL;
    mqtt_action_cmd_t *temp_msg = NULL;
  
    uint8_t try_times = 0;
  
    if(is_mqtt_inited == 0)
    {
        L506_LOG("mqtt not init,return");
        *mqtt_status = 0;
        res = MQTT_ACTION_SUCCESS;
        return res;
    }

      //这个锁锁住的资源比较多，时间可能会比较长
    //OSMutexPend(mqtt_cmd_mutex,0,&err);
    OSMutexPend(upload_data_mutex,0,&err);
    
    mqtt_action = MQTT_GET_CONNECT_STATUS_ACTION;
  
mqtt_action_start:  
    
//    if(is_https_action != 0)
//    {
//        OSTimeDlyHMSM(0,0,0,500);
//        goto mqtt_action_start;
//    }
        
    memset(&mqtt_action_cmd_msg,0,sizeof(mqtt_action_cmd_msg));
    
    if(is_queue_full(mqtt_action_cmd_queue) == QUEUE_FULL)
    {
        //消息队列满了，pull一个出来
        L506_LOG("mqtt queue full,pull one msg");
        temp_msg = OSQPend(mqtt_action_cmd_queue,10,&err);
        if(err != OS_ERR_NONE)
        {
            res = MQTT_CMD_QUEUE_ERR;
            if(temp_msg != NULL)
            {
                temp_msg = NULL;
            }
            goto exit;
        }
    }
    
    if(is_queue_full(mqtt_action_res_queue) == QUEUE_FULL)
    {
        //消息队列满了，pull一个出来
        L506_LOG("mqtt_action_res_queue full,pull one msg");
        mqtt_action_res_msg = OSQPend(mqtt_action_res_queue,10,&err);
        if(err != OS_ERR_NONE)
        {
            res = MQTT_CMD_QUEUE_ERR;
            goto exit;
        }
    }
    
    mqtt_action_cmd_msg.cmd = MQTT_GET_CONNECT_STATUS_ACTION;
    //L506_LOG("push mqtt cmd:%d",mqtt_action_cmd_msg.cmd);
    //L506_LOG("mqtt_action_cmd_msg:%p",&mqtt_action_cmd_msg);
    
    err = OSQPost(mqtt_action_cmd_queue,&mqtt_action_cmd_msg);
    if(err != OS_ERR_NONE)
    {
        L506_LOG("push get mqtt status msg error");
        res = MQTT_CMD_QUEUE_ERR;
        goto exit;
    }
    
    L506_LOG("wait for get mqtt status");
    mqtt_action_res_msg = OSQPend(mqtt_action_res_queue,WAIT_MQTT_INIT_RES_MAX_TIME,&err);
    if(err != OS_ERR_NONE)
    {
        if(err == OS_ERR_TIMEOUT)
        {
            L506_LOG("get mqtt status timeout");
            res = MQTT_CMD_RES_TIMEOUT;
        }
        else
        {
            L506_LOG("push from mqtt cmd queue err:%d",err);
            res = err;
        }

        goto exit;
    }
    
    if(mqtt_action_res_msg == NULL)
    {
        L506_LOG("mqtt_action_res_msg == NULL");
        res = MQTT_CMD_RES_NULL;
        goto exit;
    }
    
    if(mqtt_action_res_msg->cmd != mqtt_action_cmd_msg.cmd)
    {
        L506_LOG("get mqtt status res cmd err");
        goto exit;
    }
    
    if(mqtt_action_res_msg->result != MQTT_ACTION_SUCCESS)
    {
        L506_LOG("get mqtt status cmd fail %d times",(try_times + 1));
        goto exit;
    }
    
    
    L506_LOG("mqtt_action_res_msg->status:%d",mqtt_action_res_msg->status);
    *mqtt_status = mqtt_action_res_msg->status;
  
    res = MQTT_ACTION_SUCCESS;

    
       
exit:
      
      
    try_times += 1;
    
    if(res != MQTT_ACTION_SUCCESS && try_times < MQTT_INIT_TRY_MAX_TIME)
    {
        OSTimeDlyHMSM(0,0,1,0);
        goto mqtt_action_start;
    }
    
    mqtt_action = 0;
    
    //OSMutexPost(mqtt_cmd_mutex);
    OSMutexPost(upload_data_mutex);
    
    
    return res;

}



//检测L506是否出现通讯错误，如果一直错误或者超时则重启L506,L506通讯指示灯控制
//此函数不需要太频繁的执行
void L506_fogcloud_init_and_monitor_task(void *para)
{
    uint8_t res = 0;
    uint8_t mqtt_status = 0;
    uint8_t time_count = 0;
    uint8_t event_fail_times = 0;    
  
    OSTimeDlyHMSM(0,0,10,0);
    //刚上电启动的时候，不需要restart,直接跳到get ccid
    goto get_ccid_label;
  
restart:    
    L506_Restart(); 
    time_count = 0;
    event_fail_times = 0;
  
get_ccid_label:
    if(L506_register_net.Is_L506_registerd == 1)
    {
        if(Is_Get_CCID == 0)
        {
            L506_Get_CCID();
            OSTimeDlyHMSM(0,0,1,0); 
            if(Is_Get_CCID == 1)
            {
                event_fail_times = 0;
                goto device_activate;
            }
            else
            {
                L506_LOG("get ccid fail %d times",event_fail_times);
                event_fail_times += 1;
                if(event_fail_times >= 30)
                {
                    goto restart;
                }
                goto get_ccid_label;
            }
        }
    }
    else
    {
        OSTimeDlyHMSM(0,0,1,0); 
        time_count += 1;
        L506_LOG("time_count:%d",time_count);
        if(time_count >= 60)
        {
            //模块启动后，如果1分钟后还是没有收到Call Ready，则模块重启
            goto restart;
        }
        else
        {
            goto get_ccid_label;
        }
    }
 
device_activate:  
    res = device_activate_event();
    if(res != UPLOAD_SUCCESS)
    {
        event_fail_times += 1;
        if(event_fail_times >= 10)
        {
            goto restart;
        }
        goto device_activate;
    }
    else 
    {
        event_fail_times = 0;
    }
       
get_token:
    res = device_get_token_event();
    if(res != UPLOAD_SUCCESS)
    {
        event_fail_times += 1;
        if(event_fail_times >= 10)
        {
            goto restart;
        }
        goto get_token;
    }
    else 
    {
        event_fail_times = 0;
    }

ota_check:    
    res = device_ota_check_event();
    if(res != UPLOAD_SUCCESS)
    {
        event_fail_times += 1;
        if(event_fail_times >= 10)
        {
            goto restart;
        }
        goto ota_check;
    } 
    else 
    {
        event_fail_times = 0;
    }
    
mqtt_init:
    res = mqtt_init_event();
    if(res != MQTT_ACTION_SUCCESS)
    {
        event_fail_times += 1;
        if(event_fail_times >= 10)
        {
            goto restart;
        }
        goto mqtt_init;
    }
    
    time_count = 0;
    

    while(1)
    {
        OSTimeDlyHMSM(0,0,1,0);  
        time_count += 1;
      
        if((L506_cmd_info.error_times >= 20 || L506_cmd_info.timeout_times >= 3))
        {
            //重启L506       
            goto restart;        
        }
  
        if(L506_cmd_info.error_times != 0 || L506_cmd_info.timeout_times != 0 || Is_device_activate == 0)
        {
            if(wifi_led_state == 1)
            { 
                //关闭wifi led
                Wifi_Led_Off();
            }
        }
        else if(L506_cmd_info.error_times == 0 && L506_cmd_info.timeout_times == 0 && Is_device_activate == 1)
        {
            if(wifi_led_state == 0)
            {
                //打开wifi led
                Wifi_Led_On();
            }
        }
        
        if(time_count >= 60)
        {
            mqtt_status = 0;
            res = get_mqtt_connect_status_event(&mqtt_status); 
            if(res == MQTT_ACTION_SUCCESS)
            {
                L506_LOG("get mqtt status:%d",mqtt_status);
            }
            else
            {
                L506_LOG("get mqtt status fail");
            }
            
            time_count = 0;
        }

        if(is_module_restart == 1)
        {
            goto restart;
        }
    }    
}


void user_set_module_restart(void)
{
    is_module_restart = 1;
}




