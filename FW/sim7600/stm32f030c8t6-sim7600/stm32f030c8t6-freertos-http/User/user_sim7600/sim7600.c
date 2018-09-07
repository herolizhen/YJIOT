#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "stm32f0xx.h"
#include "FreeRTOS.h"
#include "task.h"
#include "sim7600.h"
#include "user_sim7600.h"
#include "charge.h"

extern Charge_Typedef charge_info;

extern uint16_t uart_sim7600_rx_index;
extern char uart_sim7600_rx_buff[UART_SIM7600_RX_BUFF_SIZE];

char order_num[41] = {0};
char ccid[40] = {0};
uint8_t Is_Get_CCID = 0;
char device_id[40] = {0};
//bit Is_Get_IMEI = 0;
uint8_t Is_device_activate = 0;
uint8_t Is_SIM7600_wakeup = 0;

uint8_t is_ota_check = 0;

uint8_t http_step = 0;

uint8_t SIM7600_action = 0;

uint8_t is_mqtt_init = 0;
uint8_t mqtt_connect_status = 0;
uint8_t mqtt_init_step = 0;
uint16_t mqtt_passowrd = 0;

//SIM7600启动后和服务器通讯的初始化工作是否结束
uint8_t is_SIM7600_fogcloud_init = 0;

//信号质量
uint32_t signal_quality = 0;
//读取信号质量时，检测误码率是否是0
uint8_t Is_signal_err_code_zero = 0;

//上传自动测试结果标志位
uint8_t is_upload_auto_check_result = 0;

//上传手动测试结果标志位
uint8_t is_upload_manual_check_result = 0;

//下次执行同步事件的时间
uint32_t next_sync_stime = 0;
//快速或者慢速同步状态标志位，当收到开仓门指令后同步时间间隔变为5秒，持续3分钟
uint8_t is_fast_sync = 0;
//快速同步的开始时间
uint32_t fast_sync_start_time = 0;

uint32_t next_upload_data_time;

uint8_t charge_confirm = 0;

uint8_t Is_signal_check;
uint8_t signal_check_err_times;

uint8_t sync_this_loop;

uint8_t resync;

uint8_t wifi_led_state;



//AT指令发送时间
SIM7600_Cmd_Typedef SIM7600_cmd_info;

SIM7600_RESGISTER_Typedef SIM7600_register_net;


//SIM7600与服务器http通讯第几步标识
static uint8_t Is_http = 0;


//电源芯片控制管脚低电平时，电源芯片工作
/*
void SIM7600_Reset_Pin_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruchture;
	
	RCC_AHBPeriphClockCmd(POWER_KEY_GPIO_CLK, ENABLE);
	
	GPIO_InitStruchture.GPIO_Pin = POWER_KEY_PIN;
	GPIO_InitStruchture.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruchture.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruchture.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruchture.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(POWER_KEY_PORT, &GPIO_InitStruchture);
	
	//GPIO_SetBits(GPIOC, GPIO_Pin_14);
  
  POWER_KEY_ON();
}

void SIM7600_Set(void)
{
    SIM7600_RESET_PIN = 0;   
}

void SIM7600_Reset(void)
{
    SIM7600_RESET_PIN = 1;
    //重启SIM7600的话断电保持一段时间，防止启动过快
    if(g_1s_flag == 1)
    {
        g_1s_flag = 0;
    } 
    while(g_1s_flag == 0) ;
    
}
*/

//开机：PWK管脚高电平脉冲，然后低电平保持500ms,然后再高电平开机
//关机：PWK管脚高电平脉冲，然后低电平保持3s,然后再高电平关机
void SIM7600_PowerKey_Pin_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruchture;
	
    RCC_AHBPeriphClockCmd(POWER_KEY_GPIO_CLK, ENABLE);
	
    GPIO_InitStruchture.GPIO_Pin = POWER_KEY_PIN;
    GPIO_InitStruchture.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStruchture.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruchture.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStruchture.GPIO_Speed = GPIO_Speed_50MHz;
	
    GPIO_Init(POWER_KEY_PORT, &GPIO_InitStruchture);
  
    POWER_KEY_HIGH();
}

//开机：PWK管脚高电平脉冲，然后低电平保持500ms,然后再高电平开机
void SIM7600_PowerKey_On(void)
{
    POWER_KEY_HIGH();
    vTaskDelay(500);
    POWER_KEY_LOW();
    vTaskDelay(500);
    POWER_KEY_HIGH();
    vTaskDelay(5000);
    POWER_KEY_LOW();
}

//关机：PWK管脚高电平脉冲，然后低电平保持3s,然后再高电平关机
void SIM7600_PowerKey_Off(void)
{
    POWER_KEY_HIGH();
    vTaskDelay(100);
    POWER_KEY_LOW();
    vTaskDelay(3000);
    POWER_KEY_HIGH();
    vTaskDelay(3000);
    POWER_KEY_LOW();
    vTaskDelay(30000);
}

void SIM7600_Restart(void)
{
    //重启SIM7600 
    SIM7600_PowerKey_Off();  
    SIM7600_PowerKey_On();
        
    //SIM7600_register_net.step = 0;
    http_step = 0;
    Is_http = 0;
    SIM7600_action = 0;
    
    signal_quality = 99;
    Is_Get_CCID = 0;
    Is_signal_err_code_zero = 0;
    Is_device_activate = 0;
    SIM7600_register_net.Is_SIM7600_registerd = 0;
        
    SIM7600_cmd_info.error_times = 0;
    SIM7600_cmd_info.timeout_times = 0;
    
    is_ota_check = 0;
    is_SIM7600_fogcloud_init = 0;
    is_mqtt_init = 0;
    mqtt_init_step = 0;
    
    is_upload_auto_check_result = 0;
    
//    memset(SIM7600_cmd_info.sendtring,0,sizeof(SIM7600_cmd_info.sendtring));
//    sprintf(SIM7600_cmd_info.sendtring,"SIM7600 restart\r\n");
//    DEBUG_Uart_Sendbytes(SIM7600_cmd_info.sendtring,strlen(SIM7600_cmd_info.sendtring));
    printf("SIM7600 restart\r\n");
    
}


int SIM7600_wait_response(void)
{
    int res = SIM7600_WAIT_RESPONSE;
    //unsigned char i,j = 0;
    //unsigned char num = 0;
    //char *cmd_position = NULL;
    //unsigned char debug_buff[180] = {0};
  
    uint32_t nowtime_ms = 0;
    
  
    if(SIM7600_register_net.Is_SIM7600_registerd == 0)
    {
        if(strstr(uart_sim7600_rx_buff,SIM7600_READY) != NULL)
        {
            SIM7600_register_net.Is_SIM7600_registerd = 1;
          
            printf("SIM7600 ready\r\n");
        }
        //是否加一些处理
    }
    
  
    //如果之前没有发送过数据或者命令，则直接返回
    if(SIM7600_cmd_info.cmd_result == CMD_SUCCESS)
    {
        //res = CMD_IDLE;
        //SIM7600_cmd_info.cmd_result = CMD_IDLE;
        goto exit;
    }
    
    nowtime_ms = xTaskGetTickCount();
    
    
    //防止时间溢出
    if(SIM7600_cmd_info.cmd_send_time > 0xF0000000 && nowtime_ms < 0xE0000000)
    {
        SIM7600_cmd_info.cmd_send_time = nowtime_ms;
    }

    
    //超时 没有返回数据
    if(nowtime_ms >= (SIM7600_cmd_info.cmd_send_time + (SIM7600_TIME_OUT | 0x00)))
    {
        SIM7600_cmd_info.cmd_result = CMD_TIMEOUT;
      
        printf("cmd:%s timeout\r\n",SIM7600_cmd_info.cmd);
              
        res = CMD_TIMEOUT;
        goto cmd_failed;
    }
    
    if(strstr(uart_sim7600_rx_buff,END_ERROR) != NULL)
    {
        SIM7600_cmd_info.cmd_result = CMD_ERROR;
      
        if(SIM7600_cmd_info.type == CMD_TYPE)
        {
            printf("cmd:%s error\r\n",SIM7600_cmd_info.cmd);         
        }
        else
        {
            printf("send string error\r\n");
        }

      
        res = CMD_ERROR;
        goto cmd_failed;
    }
    
    if(SIM7600_cmd_info.type == STRING_TYPE)
    {
        //发送字符串时返回OK或者ERROR
        if(strstr(uart_sim7600_rx_buff,SIM7600_cmd_info.end_flag) != NULL)
        {
            SIM7600_cmd_info.cmd_result = CMD_SUCCESS;   
            res = CMD_SUCCESS; 
            goto  cmd_success;       
        }
        
        if(Is_http == 1)
        {
            //http_step += 1;
            SIM7600_cmd_info.cmd_result = CMD_SUCCESS;   
            goto  cmd_success;       
        }
      
    }
    else if(SIM7600_cmd_info.type == CMD_TYPE)
    {
        
        //发送命令时会返回命令+OK或者命令+ERROR或者>>
        if(strstr(uart_sim7600_rx_buff,SIM7600_cmd_info.end_flag) != NULL)
        {            
            res = CMD_SUCCESS;
            SIM7600_cmd_info.cmd_result = CMD_SUCCESS;   

            printf("cmd:%s sucess\r\n",SIM7600_cmd_info.cmd);
        
            goto cmd_success;
        }

        
    }
    

exit:    
    return res;
    
cmd_success:
    //SIM7600_cmd_info.cmd_result = CMD_SUCCESS;
    return res;
    
    
cmd_failed:
    //SIM7600_cmd_info.cmd_result = res;
    return res;
    
}


void parse_SIM7600_cmd_result(void)
{    
    char *position = NULL;
    int value_int = -1;
    long value_long = -1;
    int status = -1;
    unsigned char ordnum_cmp_result = 0;
  
    int check_type = -1;
    int check_state = -1;
    
  
    unsigned char i = 0;
    
    //char debug_buff[40] = {0};
    
    if(SIM7600_cmd_info.Is_wait_data == 0)
    {
        return;
    }
    else if(SIM7600_cmd_info.Is_wait_data == 1)
    {
        if(SIM7600_cmd_info.cmd_result == CMD_WAIT)
        {
            return;
        }
        else if(SIM7600_cmd_info.cmd_result == CMD_SUCCESS)
        {
         
            
          
            //http发送url后再发送字符串并不返回命令，只返回OK
            if(Is_http == 1)
            {
                 if(strcmp(SIM7600_cmd_info.cmd,SIM7600_HTTP_END_CMD))
                 {
                     SIM7600_cmd_info.Is_wait_data = 0;
                 }
              
                if(SIM7600_cmd_info.type == STRING_TYPE)
                {
                    http_step += 1;
                    return;
                }
            }
            else
            {
                SIM7600_cmd_info.Is_wait_data = 0;
            }

          
            if(strcmp(SIM7600_cmd_info.cmd,SIM7600_ATI_CMD) == 0)
            {
            
            }
            else if(strcmp(SIM7600_cmd_info.cmd,SIM7600_CSQ_CMD) == 0)
            {
                //获取信号质量
                //debug
                //DEBUG_Uart_Sendbytes(uart_sim7600_rx_buff,strlen(uart_sim7600_rx_buff)); 
                printf("%s\r\n",uart_sim7600_rx_buff);
              
                position = strstr(uart_sim7600_rx_buff,":");
                if(position != NULL)
                {                   
                    if(*(position + 3) == ASCII_COMMA)
                    {
                        i = 1;
                    }
                    if(*(position + 4) == ASCII_COMMA)
                    {
                        i = 2;
                    }
                    
                    if(i == 0)
                    {
                        return;
                    }
                                        
                    memset(SIM7600_cmd_info.sendtring,0,strlen(SIM7600_cmd_info.sendtring));
                    strncpy(SIM7600_cmd_info.sendtring,(position + 2),i);
                    signal_quality = atoi(SIM7600_cmd_info.sendtring);
                    
//                    memset(SIM7600_cmd_info.sendtring,0,sizeof(SIM7600_cmd_info.sendtring));
//                    sprintf(SIM7600_cmd_info.sendtring,"signal_quality = %d\r\n",(unsigned int)signal_quality);
//                    DEBUG_Uart_Sendbytes(SIM7600_cmd_info.sendtring,strlen(SIM7600_cmd_info.sendtring));
                    printf("signal_quality = %d\r\n",signal_quality);
                }              
            }
            else if(strcmp(SIM7600_cmd_info.cmd,SIM7600_GSN_CMD) == 0)
            {
                //获取IMEI成功
//                memset(SIM7600_IMEI,0,sizeof(SIM7600_IMEI));
//                position = strstr(uart_sim7600_rx_buff,SIM7600_CMD_END_FLAG);
//                strncpy(SIM7600_IMEI,position + 2,SIM7600_IMEI_LEN);
              
//                memset(SIM7600_cmd_info.sendtring,0,sizeof(SIM7600_cmd_info.sendtring));
//                sprintf(SIM7600_cmd_info.sendtring,"IMEI:%s\n",SIM7600_IMEI);
//                DEBUG_Uart_Sendbytes(SIM7600_cmd_info.sendtring,strlen(SIM7600_cmd_info.sendtring));
              
                //Is_Get_IMEI = 1;
            }
            else if(strcmp(SIM7600_cmd_info.cmd,SIM7600_CICCID_CMD) == 0)
            {
                //获取CCID成功
                memset(ccid,0,sizeof(ccid));
                position = strstr(uart_sim7600_rx_buff,SIM7600_CICCID_RES);
                strncpy(ccid,position + strlen(SIM7600_CICCID_RES) + 1,SIM7600_CCID_LEN);
              
                printf("CCID:%s\n",ccid);
              
                Is_Get_CCID = 1;
            }            
            else if(strcmp(SIM7600_cmd_info.cmd,SIM7600_QSPN_CMD) == 0)
            {     
                //读取SIM 卡服务运营商名称             
//                memset(SIM7600_cmd_info.sendtring,0,sizeof(SIM7600_cmd_info.sendtring));
//                sprintf(SIM7600_cmd_info.sendtring,"SIM7600_QSPN_CMD OK\r\n");
//                DEBUG_Uart_Sendbytes(SIM7600_cmd_info.sendtring,strlen(SIM7600_cmd_info.sendtring));
                printf("SIM7600_QSPN_CMD OK\r\n");
            }
            else if(strcmp(SIM7600_cmd_info.cmd,SIM7600_HTTP_ACT_CMD) == 0)
            {   
                //set HTTP Server URL          
                http_step += 1;
            }
            else if(strcmp(SIM7600_cmd_info.cmd,SIM7600_HTTP_END_CMD) == 0)
            {   
                //set http send data length 
                if(http_step < HTTP_MAX_STEP)
                {
                    http_step += 1;
                }
                //else
                //{
                    SIM7600_cmd_info.error_times = 0;
                    SIM7600_cmd_info.timeout_times = 0;              
                    //http read                       
                    if(SIM7600_cmd_info.is_read_http_data == 0 && SIM7600_BIT_CHECK(SIM7600_action,HTTP_ACTIVATE))
                    {
                        //激活，获取到device_id
                        if((position = strstr(uart_sim7600_rx_buff,"deviceid")) != NULL)
                        {
                            memset(device_id,0,sizeof(device_id));
                            for(i = 0;i <= DEVICE_ID_LEN;i++)
                            {
                                //if(*(position + strlen("deviceid") + 3 + i) == '\"')
                                if(*(position + 11 + i) == '\"')
                                {
                                    break;
                                }
                            }
                            printf("position11 = %d,i = %d\r\n",*(position + 11),i);
                            
                            if(i > DEVICE_ID_LEN)
                            {
                                //处理错误
                            }
                            strncpy(device_id,position + strlen("deviceid") + 3,i);
                      
                            printf("id:%s\r\n",device_id);
                          
                            Is_device_activate = 1;
                            SIM7600_cmd_info.is_read_http_data = 1;
                        }
                        
                        
                    }
                    else if(SIM7600_cmd_info.is_read_http_data == 0 && SIM7600_BIT_CHECK(SIM7600_action,HTTP_OTA))
                    {
                        //ota check
                        is_ota_check = 1;
                        is_SIM7600_fogcloud_init = 1;

                        printf("%s\r\n",uart_sim7600_rx_buff);
                  
                        printf("ota check sucess\r\n");
                      
                        SIM7600_cmd_info.is_read_http_data = 1;
                    }
                    else if(SIM7600_cmd_info.is_read_http_data == 0 && SIM7600_BIT_CHECK(SIM7600_action,HTTP_UPLOAD_DATA))
                    {                       
                        printf("upload data sucess\r\n");
                      
                        SIM7600_cmd_info.is_read_http_data = 1;
                    }
                    else if(SIM7600_cmd_info.is_read_http_data == 0 && SIM7600_BIT_CHECK(SIM7600_action,HTTP_SYNC))
                    {            
                        //设备状态同步
                        //设备状态同步发送成功后，resync清零
                        //resync = 0;                   
                    
                        if((position = strstr(uart_sim7600_rx_buff,"SF")) == NULL)
                        {
//                            memset(SIM7600_cmd_info.sendtring,0,sizeof(SIM7600_cmd_info.sendtring));
//                            sprintf(SIM7600_cmd_info.sendtring,"not find SF\r\n");
//                            DEBUG_Uart_Sendbytes(SIM7600_cmd_info.sendtring,strlen(SIM7600_cmd_info.sendtring));   
                            printf("not find SF\r\n");
                        }
                        else
                        {
                            value_int = -1;
                            value_int = string_get_int(position);

                            if(value_int == 1)
                            {                         
                                //获取到的字符串中存在控制信息
                                position = strstr(uart_sim7600_rx_buff,"SM");
                                if(position != NULL)
                                {
                                    //手自动模式的改变
                                    value_int = -1;
                                    value_int = string_get_int(position);
                                 
                                    printf("SM:%d\r\n",value_int);
                              
//                                    if(value_int == 1 && run_mode == 0)
//                                    {
//                                        set_sys_to_smart_mode();
//                                    }  
//                                    else if(value_int == 0 && run_mode == 1)
//                                    {
//                                        stop_sys_smart_mode();
//                                    }                                 
                                } 
                                position = strstr(uart_sim7600_rx_buff,"FA");
                                if(position != NULL)
                                {
                                    //风机控制
                                    value_int = -1;
                                    value_int = string_get_int(position);
                              
                                    printf("FA:%d\r\n",value_int);
                                                         
                                }
                                position = strstr(uart_sim7600_rx_buff,"UV");
                                if(position != NULL)
                                {
                                    //UV灯控制
                                    value_int = -1;
                                    value_int = string_get_int(position);
                              
                                    printf("UV:%d\r\n",value_int);
                              
                              
                                }                                                        
                                position = strstr(uart_sim7600_rx_buff,"NI");
                                if(position != NULL)
                                {
                                    //ION控制
                                    value_int = -1;
                                    value_int = string_get_int(position);
                               
                                    printf("NI:%d\r\n",value_int);
                               
                              
                                }
                                position = strstr(uart_sim7600_rx_buff,"DR");
                                if(position != NULL)
                                {
                                    //开仓门
                                    value_int = -1;
                                    value_int = string_get_int(position);
                                                               
                                    printf("DR:%d\r\n",value_int);
                              
                                    //改变下一次同步的时间，立刻执行sync动作
                                    //next_sync_mstime = xTaskGetTickCount();
                                    //next_sync_stime = get_sys_stime();
                                    next_sync_stime = xTaskGetTickCount() / 1000;
                                    is_fast_sync = 1;
                                    //fast_sync_start_time = get_sys_stime();
                                    fast_sync_start_time = xTaskGetTickCount() / 1000;
                                
                                    //Door_Open();                                                        
                                }
                            
                                position = strstr(uart_sim7600_rx_buff,"EXAMID");
                                if(position != NULL)
                                {
                                    //因为ram空间有限，和CCID公用同一个数组
                                    memset(ccid,0,sizeof(ccid));
                                    strncpy(ccid,position + 9,CHECK_ID_LEN);

                                    printf("check_id:%s\r\n",ccid);
                                }
                    
                                if((position = strstr(uart_sim7600_rx_buff,"EXAMTYPE")) != NULL)
                                {
                                    check_type = string_get_int(position);

                                    printf("check_type:%d\r\n",check_type);
                                }
                    
                                if((position = strstr(uart_sim7600_rx_buff,"EXAMSTATE")) != NULL)
                                {
                                    check_state = string_get_int(position);
                      
//                                    memset(SIM7600_cmd_info.sendtring,0,sizeof(SIM7600_cmd_info.sendtring));
//                                    sprintf(SIM7600_cmd_info.sendtring,"check_state:%d\r\n",check_state);
//                                    DEBUG_Uart_Sendbytes(SIM7600_cmd_info.sendtring,strlen(SIM7600_cmd_info.sendtring));
                                    printf("check_state:%d\r\n",check_state);
                                }
                    
                                if(check_type == 1)
                                {
                                    //自动检测
//                                    sys_check_info.check_type = 1;
//                                    if(check_state == 0)
//                                    {
//                                        if(is_sys_auto_check == 1)
//                                        {
//                                            stop_sys_auto_check();
//                                        }
//                                    }
//                                    else if(check_state == 1)
//                                    {
//                                        if(is_sys_auto_check == 0 && is_sys_manual_check == 0)
//                                        {
//                                            start_sys_auto_check();
//                                        }                          
//                                    }
                                }
                                else if(check_type == 2)
                                {
                                    //手动检测
//                                    sys_check_info.check_type = 2;
//                                    if(check_state == 0)
//                                    {
//                                        if(is_sys_manual_check == 1)
//                                        {
//                                            stop_sys_manual_check();
//                                        }
//                                    }
//                                    else if(check_state == 1)
//                                    {
//                                        if(is_sys_manual_check == 0 && is_sys_auto_check == 0)
//                                        {
//                                            start_sys_manual_check();
//                                        }
//                                    }
                                }
                            
                            }
                        }
                    
                        if((position = strstr(uart_sim7600_rx_buff,"CF")) == NULL)
                        {
//                            memset(SIM7600_cmd_info.sendtring,0,sizeof(SIM7600_cmd_info.sendtring));
//                            sprintf(SIM7600_cmd_info.sendtring,"not find CF\r\n");
//                            DEBUG_Uart_Sendbytes(SIM7600_cmd_info.sendtring,strlen(SIM7600_cmd_info.sendtring));  
                            printf("not find CF\r\n");
                        }
                        else
                        {
                            value_int = -1;
                            value_int = string_get_int(position);
                      
//                        memset(SIM7600_cmd_info.sendtring,0,sizeof(SIM7600_cmd_info.sendtring));
//                        sprintf(SIM7600_cmd_info.sendtring,"CF val:%d\r\n",(unsigned int)value_int);
//                        DEBUG_Uart_Sendbytes(SIM7600_cmd_info.sendtring,strlen(SIM7600_cmd_info.sendtring)); 
                      
                            if(value_int == 1)
                            {
                                //debug
                                //DEBUG_Uart_Sendbytes(uart_sim7600_rx_buff,strlen(uart_sim7600_rx_buff)); 
                                //获取到的字符串中存在筹码信息 
                                position = strstr(uart_sim7600_rx_buff,"\"C\"");
                                if(position != NULL)
                                {
                                    value_long = -1;
                                    value_long = string_get_long(position);
                              
//                                    memset(SIM7600_cmd_info.sendtring,0,sizeof(SIM7600_cmd_info.sendtring));
//                                    sprintf(SIM7600_cmd_info.sendtring,"C:%d\r\n",(unsigned int)value_int);
//                                    DEBUG_Uart_Sendbytes(SIM7600_cmd_info.sendtring,strlen(SIM7600_cmd_info.sendtring)); 
                                    printf("C:%d\r\n",value_int);
                                }
                            
                                position = strstr(uart_sim7600_rx_buff,"\"T\"");
                                if(position != NULL)
                                {
                                    value_int = -1;
                                    value_int = string_get_int(position);
                              
//                                memset(SIM7600_cmd_info.sendtring,0,sizeof(SIM7600_cmd_info.sendtring));
//                                sprintf(SIM7600_cmd_info.sendtring,"T:%d\r\n",(unsigned int)value_int);
//                                DEBUG_Uart_Sendbytes(SIM7600_cmd_info.sendtring,strlen(SIM7600_cmd_info.sendtring)); 
                                    printf("T:%d\r\n",value_int);
                                }
                            
                                position = strstr(uart_sim7600_rx_buff,"\"S\"");
                                if(position != NULL)
                                {
                                    status = -1;
                                    status = string_get_int(position);
                              
//                                memset(SIM7600_cmd_info.sendtring,0,sizeof(SIM7600_cmd_info.sendtring));
//                                sprintf(SIM7600_cmd_info.sendtring,"S:%d\r\n",(unsigned int)status);
//                                DEBUG_Uart_Sendbytes(SIM7600_cmd_info.sendtring,strlen(SIM7600_cmd_info.sendtring)); 
                                }
                          
                                position = strstr(uart_sim7600_rx_buff,"\"O\"");
                                if(position != NULL)
                                {
//                                    memset(SIM7600_cmd_info.sendtring,0,strlen(SIM7600_cmd_info.sendtring));
//                                    sprintf(SIM7600_cmd_info.sendtring,"odernum:");
//                                    DEBUG_Uart_Sendbytes(SIM7600_cmd_info.sendtring,strlen(SIM7600_cmd_info.sendtring));
                                    printf("odernum:");
                              
                                    //ordernum复制到 SIM7600_cmd_info.sendtring 中
                                    memset(SIM7600_cmd_info.sendtring,0,sizeof(SIM7600_cmd_info.sendtring));
                                    string_get_string(position,SIM7600_cmd_info.sendtring);
                                    //debug
                                    //DEBUG_Uart_Sendbytes(SIM7600_cmd_info.sendtring,strlen(SIM7600_cmd_info.sendtring)); 
                                    printf("%s\r\n",SIM7600_cmd_info.sendtring);
                              
                                    //立刻对Order num进行比较，防止 SIM7600_cmd_info.sendtring 在后面被改变了
                                    //如果比较结果相等 ordnum_cmp_result == 0
                                    ordnum_cmp_result = strcmp(order_num,SIM7600_cmd_info.sendtring);
                                    if(strlen(SIM7600_cmd_info.sendtring) <= 40)
                                    {
                                        strcpy(order_num,SIM7600_cmd_info.sendtring);
                                    }
                                    else
                                    {
//                                        memset(SIM7600_cmd_info.sendtring,0,strlen(SIM7600_cmd_info.sendtring));
//                                        sprintf(SIM7600_cmd_info.sendtring,"odernum too long");
//                                        DEBUG_Uart_Sendbytes(SIM7600_cmd_info.sendtring,strlen(SIM7600_cmd_info.sendtring)); 
                                        printf("odernum too long\r\n");
                                    
                                        return;
                                    }
                                
                                  
                                
                                }
                            
                                if(status == 1)
                                {
                                    if(value_int >= 0 && value_long >= 0)
                                    {
                                        //筹码确认
                                        charge_confirm = 1;
                                        //立刻上传一次数据
                                        //next_upload_data_time = get_sys_stime() - 1; 
                                        next_upload_data_time = xTaskGetTickCount() / 1000;
                                    
                                    }
                                }
                            
                            }

                        }
                    
//                        if(Is_send_dr_confirm == 1)
//                        {
//                            dr_confirm = 0;
//                            Is_send_dr_confirm = 0;
//                        }
                        
                        SIM7600_cmd_info.is_read_http_data = 1;

                    }   
                    else if(SIM7600_cmd_info.is_read_http_data == 0 && SIM7600_BIT_CHECK(SIM7600_action,HTTP_C_CONFIRM))
                    {
                        //筹码确认
                        printf("confirm:%s\r\n",uart_sim7600_rx_buff);
                  
                        charge_confirm = 0;
                      
                        SIM7600_cmd_info.is_read_http_data = 1;
                    }
                    else if(SIM7600_cmd_info.is_read_http_data == 0 && SIM7600_BIT_CHECK(SIM7600_action,HTTP_FACTORY_CHECK))
                    {
                        if((position = strstr(uart_sim7600_rx_buff,"EXAMID")) != NULL)
                        {
                            //因为ram空间有限，和CCID公用同一个数组
                            memset(ccid,0,sizeof(ccid));
                            strncpy(ccid,position + 8,CHECK_ID_LEN);
                      
                            printf("check_id:%s\r\n",ccid);
                        }
                    
                        if((position = strstr(uart_sim7600_rx_buff,"EXAMTYPE")) != NULL)
                        {
                            check_type = string_get_int(position);
                      
                            printf("check_type:%d\r\n",check_type);
                        }
                    
                        if((position = strstr(uart_sim7600_rx_buff,"EXAMSTATE")) != NULL)
                        {
                            check_state = string_get_int(position);
                            printf("check_state:%d\r\n",check_state);
                        }
                    
                        if(check_type == 1)
                        {
                            //自动检测
//                            sys_check_info.check_type = 1;
//                            if(check_state == 0)
//                            {
//                                if(is_sys_auto_check == 1)
//                                {
//                                    stop_sys_auto_check();
//                                }
//                            }
//                            else if(check_state == 1)
//                            {
//                                if(is_sys_auto_check == 0 && is_sys_manual_check == 0)
//                                {
//                                    start_sys_auto_check();
//                                }                          
//                            }
                        }
                        else if(check_type == 2)
                        {
                            //手动检测
//                            sys_check_info.check_type = 2;
//                            if(check_state == 0)
//                            {
//                                if(is_sys_manual_check == 1)
//                                {
//                                    stop_sys_manual_check();
//                                }
//                            }
//                            else if(check_state == 1)
//                            {
//                                if(is_sys_manual_check == 0 && is_sys_auto_check == 0)
//                                {
//                                    start_sys_manual_check();
//                                }
//                            }
                        }
                    
                        SIM7600_cmd_info.is_read_http_data = 1;
                   
                    }
                    
                    if(strstr(uart_sim7600_rx_buff,SIM7600_HTTP_STOP_FLAG) != NULL)
                    {
                        SIM7600_cmd_info.Is_wait_data = 0;
                        SIM7600_cmd_info.is_read_http_data = 0;
                        http_step = 0;
                        Is_http = 0;
                        SIM7600_action = 0;
                    }
                    

                
                    //收到筹码后立刻执行筹码确认，防止连续收到
                    if(charge_confirm == 1)
                    {
                        SIM7600_Charge_Confirm();
                    }
                //}
                
            }
            else if(strcmp(SIM7600_cmd_info.cmd,SIM7600_MQTT_SSL_CMD) == 0)
            {
                mqtt_init_step += 1;
            }
            else if(strcmp(SIM7600_cmd_info.cmd,SIM7600_MQTT_CONFIG_CMD) == 0)
            {
                mqtt_init_step += 1;
            }
            else if(strcmp(SIM7600_cmd_info.cmd,SIM7600_MQTT_START_CMD) == 0)
            {
                mqtt_init_step += 1;
            }
            else if(strcmp(SIM7600_cmd_info.cmd,SIM7600_MQTT_CONNECT_CMD) == 0)
            {
                mqtt_init_step += 1;
            }
            else if(strcmp(SIM7600_cmd_info.cmd,SIM7600_MQTT_SUB_CMD) == 0)
            {
                //此处必须设置mqtt_init_step = MQTT_MAX_STEP，如果mqtt断开重新连接时，在连接过程中不能发送http指令，后面通过判断mqtt_init_step来判断是否正在重新连接mqtt
                mqtt_init_step = MQTT_MAX_STEP;
                mqtt_connect_status = 1;
                is_mqtt_init = 1;
                is_SIM7600_fogcloud_init = 1;
              
//                memset(SIM7600_cmd_info.sendtring,0,strlen(SIM7600_cmd_info.sendtring));
//                sprintf(SIM7600_cmd_info.sendtring,"mqtt init sucess\r\n");
//                DEBUG_Uart_Sendbytes(SIM7600_cmd_info.sendtring,strlen(SIM7600_cmd_info.sendtring));
                printf("mqtt init sucess\r\n");
            }
            else if(strcmp(SIM7600_cmd_info.cmd,SIM7600_MQTT_STATUS) == 0)
            {
                position = strstr(uart_sim7600_rx_buff,"+MQTTSTATU");
                if(position != NULL)
                {
                    status = string_get_int(position);
                  
//                    memset(SIM7600_cmd_info.sendtring,0,strlen(SIM7600_cmd_info.sendtring));
//                    sprintf(SIM7600_cmd_info.sendtring,"mqtt connect status:%d\r\n",status);
//                    DEBUG_Uart_Sendbytes(SIM7600_cmd_info.sendtring,strlen(SIM7600_cmd_info.sendtring));
                    printf("mqtt connect status:%d\r\n",status);
                  
                    if(status == 0)
                    {
                        mqtt_connect_status = 0;
                    }
                    else if(status == 1 || status == 2)
                    {
                        mqtt_connect_status = 1;
                    }
                    else
                    {
                        mqtt_connect_status = 0;
                    }
                }
                

               
                //SIM7600_mqtt_close();
                //is_mqtt_init = 0;
                //is_SIM7600_fogcloud_init = 0;
              
//                memset(SIM7600_cmd_info.sendtring,0,strlen(SIM7600_cmd_info.sendtring));
//                sprintf(SIM7600_cmd_info.sendtring,"mqtt error,disconnected\r\n");
//                DEBUG_Uart_Sendbytes(SIM7600_cmd_info.sendtring,strlen(SIM7600_cmd_info.sendtring));
            }

            
        }
        else if(SIM7600_cmd_info.cmd_result == CMD_ERROR)
        {
            SIM7600_cmd_info.error_times += 1;
            SIM7600_cmd_info.Is_wait_data = 0;
          
            //如果通讯失败了，本次通讯结束      
            SIM7600_http_close();
          
            //按下组合键了，正在检测信号
            if(Is_signal_check == 1)
            {
                signal_check_err_times += 1;
            }
          
            if(Is_http == 1 && http_step == 5)
            {
//                memset(SIM7600_cmd_info.sendtring,0,sizeof(SIM7600_cmd_info.sendtring));
//                sprintf(SIM7600_cmd_info.sendtring,"send string error,fail\r\n");
//                DEBUG_Uart_Sendbytes(SIM7600_cmd_info.sendtring,strlen(SIM7600_cmd_info.sendtring));
                printf("send string error,fail\r\n");
              
                http_step = 0;
                return;
            }
          
          
            if(strcmp(SIM7600_cmd_info.cmd,SIM7600_ATI_CMD) == 0)
            {
                
            }
            else if(strcmp(SIM7600_cmd_info.cmd,SIM7600_CSQ_CMD) == 0)
            {     
                //获取信号质量             
//                memset(SIM7600_cmd_info.sendtring,0,sizeof(SIM7600_cmd_info.sendtring));
//                sprintf(SIM7600_cmd_info.sendtring,"get signal quality error\n");
//                DEBUG_Uart_Sendbytes(SIM7600_cmd_info.sendtring,strlen(SIM7600_cmd_info.sendtring));
                printf("get signal quality error\r\n");
              
            }
            else if(strcmp(SIM7600_cmd_info.cmd,SIM7600_CICCID_CMD) == 0)
            {     
                //读取SIM 卡CCID          
//                memset(SIM7600_cmd_info.sendtring,0,sizeof(SIM7600_cmd_info.sendtring));
//                sprintf(SIM7600_cmd_info.sendtring,"SIM7600_QCCID_CMD error\n");
//                DEBUG_Uart_Sendbytes(SIM7600_cmd_info.sendtring,strlen(SIM7600_cmd_info.sendtring));
                printf("SIM7600_QCCID_CMD error\r\n");
              
            }
            else if(strcmp(SIM7600_cmd_info.cmd,SIM7600_GSN_CMD) == 0)
            {
                //获取IMEI失败              
                //Is_Get_IMEI = 0;
            }
            else if(strcmp(SIM7600_cmd_info.cmd,SIM7600_QSPN_CMD) == 0)
            {     
                //读取SIM 卡服务运营商名称             
//                memset(SIM7600_cmd_info.sendtring,0,sizeof(SIM7600_cmd_info.sendtring));
//                sprintf(SIM7600_cmd_info.sendtring,"SIM7600_QSPN_CMD error\n");
//                DEBUG_Uart_Sendbytes(SIM7600_cmd_info.sendtring,strlen(SIM7600_cmd_info.sendtring));  
                printf("SIM7600_QSPN_CMD error\r\n");
            }
            else if(strcmp(SIM7600_cmd_info.cmd,SIM7600_HTTP_ACT_CMD) == 0)
            {   
                //http open            
//                memset(SIM7600_cmd_info.sendtring,0,sizeof(SIM7600_cmd_info.sendtring));
//                sprintf(SIM7600_cmd_info.sendtring,"SIM7600_HTTP_OPEN_CMD error\n");
//                DEBUG_Uart_Sendbytes(SIM7600_cmd_info.sendtring,strlen(SIM7600_cmd_info.sendtring));
                printf("SIM7600_HTTP_ACT_CMD error\r\n");
              
                SIM7600_http_close();
            }
            else if(strcmp(SIM7600_cmd_info.cmd,SIM7600_HTTP_END_CMD) == 0)
            {   
                //set HTTP URL and port            
//                memset(SIM7600_cmd_info.sendtring,0,sizeof(SIM7600_cmd_info.sendtring));
//                sprintf(SIM7600_cmd_info.sendtring,"SIM7600_HTTPPARA_CMD error\n");
//                DEBUG_Uart_Sendbytes(SIM7600_cmd_info.sendtring,strlen(SIM7600_cmd_info.sendtring));
                printf("SIM7600_HTTP_END_CMD error\r\n");
              
                SIM7600_http_close();
            }

            
             //如果是状态更新，则重新把所有状态上传
            if(SIM7600_BIT_CHECK(SIM7600_action,HTTP_SYNC) )  
            {
                //如果本次是device sync，但是失败了，则下一次仍然上传设备状态
                if(sync_this_loop == 1)
                {
                    resync = 1;
                }
                
//                dr_confirm = 0;
//                Is_send_dr_confirm = 0;
            }
            
            if(Is_http == 1)
            {
                SIM7600_http_close();  
            }
            
            if(is_ota_check == 1 && is_SIM7600_fogcloud_init == 0)
            {
//                if(mqtt_init_step >= 0 && mqtt_init_step < MQTT_MAX_STEP)
//                {
//                    SIM7600_mqtt_close();
//                }
            
            }
            
          
        }
        else if(SIM7600_cmd_info.cmd_result == CMD_TIMEOUT)
        {
            SIM7600_cmd_info.timeout_times += 1;
            SIM7600_cmd_info.Is_wait_data = 0;
            //如果通讯失败了，本次通讯结束      
            SIM7600_action = 0;
          
            //按下组合键了，正在检测信号
            if(Is_signal_check == 1)
            {
                signal_check_err_times += 1;
            }
          
            if(Is_http == 1)
            {
                http_step = 0;
            }
            
            if(strcmp(SIM7600_cmd_info.cmd,SIM7600_CSQ_CMD) == 0)
            {     
                //获取信号质量            
//                memset(SIM7600_cmd_info.sendtring,0,sizeof(SIM7600_cmd_info.sendtring));
//                sprintf(SIM7600_cmd_info.sendtring,"get signal quality timeout\n");
//                DEBUG_Uart_Sendbytes(SIM7600_cmd_info.sendtring,strlen(SIM7600_cmd_info.sendtring));
                printf("get signal quality timeout\r\n");
            }
            else if(strcmp(SIM7600_cmd_info.cmd,SIM7600_CICCID_CMD) == 0)
            {     
                //读取SIM 卡CCID            
//                memset(SIM7600_cmd_info.sendtring,0,sizeof(SIM7600_cmd_info.sendtring));
//                sprintf(SIM7600_cmd_info.sendtring,"SIM7600_QCCID_CMD timeout\n");
//                DEBUG_Uart_Sendbytes(SIM7600_cmd_info.sendtring,strlen(SIM7600_cmd_info.sendtring));
                printf("SIM7600_QCCID_CMD timeout\r\n");
            }
       
            
            ////如果本次是device sync，但是失败了，则下一次仍然上传设备状态
            if(SIM7600_BIT_CHECK(SIM7600_action,HTTP_SYNC))  
            {
                if(sync_this_loop == 1)
                {
                     resync = 1;
                }
                
//                dr_confirm = 0;
//                Is_send_dr_confirm = 0;
            }
            
            if(Is_http == 1)
            {
                SIM7600_http_close();  
            }
            
            if(is_ota_check == 1 && is_SIM7600_fogcloud_init == 0)
            {
//                if(mqtt_init_step >= 0 && mqtt_init_step < MQTT_MAX_STEP)
//                {
//                    SIM7600_mqtt_close();
//                }
            
            }
            
        }
    
        clear_sim7600_uart_buff();
        
    }
    
    

}



//每次发送命令前先把UART0的缓存区清空
void clear_sim7600_uart_buff(void)
{
    memset(uart_sim7600_rx_buff,0,strlen(uart_sim7600_rx_buff));
    uart_sim7600_rx_index = 0;
}



int SIM7600_Send_data(unsigned char type,const char *cmd,const char *http_requeset)
{
    //unsigned char temp = 0;
    //unsigned char debug_buff[30] = {0};
    int res = 0;
    char *pbuff = NULL;
  
    if(SIM7600_cmd_info.Is_wait_data == 1)
    {
        res = SIM7600_BUSY;
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
    
    memset(SIM7600_cmd_info.end_flag,0,sizeof(SIM7600_cmd_info.end_flag));
  
    if(type == CMD_TYPE)
    { 
        pbuff = pvPortMalloc(150);
        memset(pbuff,0,150);
      
        if(strcmp(cmd,SIM7600_ATI_CMD) == 0)
        {
            strcpy(SIM7600_cmd_info.end_flag,END_OK);
        }
        if(strcmp(cmd,SIM7600_CSQ_CMD) == 0)
        {
            sprintf(pbuff,"%s%s",SIM7600_CSQ_CMD,SIM7600_CMD_END_FLAG);
            strcpy(SIM7600_cmd_info.end_flag,END_OK);
        }
        else if(strcmp(cmd,SIM7600_GSN_CMD) == 0)
        {
            strcpy(SIM7600_cmd_info.end_flag,END_OK);
        }
        else if(strcmp(cmd,SIM7600_CICCID_CMD) == 0)
        {
            sprintf(pbuff,"%s%s",SIM7600_CICCID_CMD,SIM7600_CMD_END_FLAG);
            strcpy(SIM7600_cmd_info.end_flag,END_OK);
        }
        else if(strcmp(cmd,SIM7600_QSPN_CMD) == 0)
        {
            strcpy(SIM7600_cmd_info.end_flag,END_OK);
        }
        else if(strcmp(cmd,SIM7600_HTTP_ACT_CMD) == 0)
        {
            sprintf(pbuff,"%s=%s,%d%s",SIM7600_HTTP_ACT_CMD,HTTP_SERVER_ADDR_1,HTTP_PORT,SIM7600_CMD_END_FLAG);
            strcpy(SIM7600_cmd_info.end_flag,SIM7600_HTTP_ACT_RES);
        }
        else if(strcmp(cmd,SIM7600_HTTP_END_CMD) == 0)
        {
            pbuff[0] = SIM7600_HTTP_END_FLAG;
            strcpy(SIM7600_cmd_info.end_flag,SIM7600_HTTP_END_RES);
        }
        else if(strcmp(cmd,SIM7600_MQTT_SSL_CMD) == 0)
        {
            sprintf(pbuff,"%s=0%s",SIM7600_MQTT_SSL_CMD,SIM7600_CMD_END_FLAG);
            strcpy(SIM7600_cmd_info.end_flag,END_OK);
        }
        else if(strcmp(cmd,SIM7600_MQTT_CONFIG_CMD) == 0)
        {
            sprintf(pbuff,"%s=%s,%s,%d%s",SIM7600_MQTT_CONFIG_CMD,device_id,device_id,mqtt_passowrd,SIM7600_CMD_END_FLAG);
            //strcpy(SIM7600_cmd_info.end_flag,END_OK);
            strcpy(SIM7600_cmd_info.end_flag,MQTT_CMD_SUCCESS);
        }
        else if(strcmp(cmd,SIM7600_MQTT_START_CMD) == 0)
        {
            sprintf(pbuff,"%s=%s,%s%s",SIM7600_MQTT_START_CMD,MQTT_SERVER_ADDR,MQTT_PORT,SIM7600_CMD_END_FLAG);
            //strcpy(SIM7600_cmd_info.end_flag,END_OK);
            strcpy(SIM7600_cmd_info.end_flag,MQTT_CMD_SUCCESS);
        }
        else if(strcmp(cmd,SIM7600_MQTT_CONNECT_CMD) == 0)
        {
            sprintf(pbuff,"%s=1,30%s",SIM7600_MQTT_CONNECT_CMD,SIM7600_CMD_END_FLAG);
            //strcpy(SIM7600_cmd_info.end_flag,END_OK);
            strcpy(SIM7600_cmd_info.end_flag,MQTT_CMD_SUCCESS);
        }
        else if(strcmp(cmd,SIM7600_MQTT_SUB_CMD) == 0)
        {
            sprintf(pbuff,"%s=c2d/%s/commands,0%s",SIM7600_MQTT_SUB_CMD,device_id,SIM7600_CMD_END_FLAG);
            //strcpy(SIM7600_cmd_info.end_flag,END_OK);
            strcpy(SIM7600_cmd_info.end_flag,MQTT_CMD_SUCCESS);
        }
        else if(strcmp(cmd,SIM7600_MQTT_STATUS) == 0)
        {
            sprintf(pbuff,"%s%s",SIM7600_MQTT_STATUS,SIM7600_CMD_END_FLAG);
            strcpy(SIM7600_cmd_info.end_flag,END_OK);
        }
        else if(strcmp(cmd,SIM7600_MQTT_CLOSE_CMD) == 0)
        {
            sprintf(pbuff,"%s%s",SIM7600_MQTT_CLOSE_CMD,SIM7600_CMD_END_FLAG);
            strcpy(SIM7600_cmd_info.end_flag,END_OK);
        }
    }
    else
    {
        strcpy(SIM7600_cmd_info.end_flag,END_OK);
    }
    
    clear_sim7600_uart_buff();
    
    
    
    SIM7600_cmd_info.cmd_result = CMD_WAIT;
    

    if(type == CMD_TYPE)
    {
       uart_sim7600_sendbytes((uint8_t *)pbuff,strlen(pbuff));
    }
    else 
    {
        uart_sim7600_sendbytes((uint8_t *)http_requeset,strlen(http_requeset));
    }
    
    
    SIM7600_cmd_info.cmd_send_time = xTaskGetTickCount();
    
    if(type == CMD_TYPE)
    {
        printf("%s\r\n",pbuff);
    }
    else 
    {
        printf("%s\r\n",http_requeset);
    }
    

    
  //此处需设置
    SIM7600_cmd_info.Is_wait_data = 1;
    
    if(pbuff != NULL)
    {
        vPortFree(pbuff);
    }
    
    return SIM7600_OK;
    
exit:
    
    if(pbuff != NULL)
    {
        vPortFree(pbuff);
    }    

    return res;


}



#define HTTP_REQUEST_LENGTH   700
#define HTTP_BODY_LENGTH      500

void SIM7600_http_loop(void)
{
    //unsigned char res = 0;
    //unsigned char string_length = 0;
    char *http_requeset = NULL;
    char *http_body = NULL;
    uint16_t http_body_length = 0;
  
    char *json_data = "\\\"KEY\\\":\\\"value\\\"";
  
    if(Is_http == 0)
    {
        return;
    }
    
    
    if(SIM7600_cmd_info.Is_wait_data == 1)
    {
        return;
    }
    
    memset(SIM7600_cmd_info.cmd,0,sizeof(SIM7600_cmd_info.cmd));
    
    if(http_step == 0)
    {
        //http open
        SIM7600_cmd_info.type = CMD_TYPE;       
        strcpy(SIM7600_cmd_info.cmd,SIM7600_HTTP_ACT_CMD);       
    }
    else if(http_step == 1)
    {
        SIM7600_cmd_info.type = STRING_TYPE;       

        http_requeset = pvPortMalloc(HTTP_REQUEST_LENGTH);
        if(http_requeset == NULL)
        {
            printf("http_request malloc fail\r\n");
            goto exit;
        }
        memset(http_requeset,0,HTTP_REQUEST_LENGTH);
      
        http_body = pvPortMalloc(HTTP_BODY_LENGTH);
        if(http_body == NULL)
        {
            printf("http_body malloc fail\r\n");
            goto exit;
        }
        memset(http_body,0,HTTP_BODY_LENGTH);
      
        if(SIM7600_BIT_CHECK(SIM7600_action,HTTP_ACTIVATE))
        {
            mqtt_passowrd = xTaskGetTickCount() % 10000;
            sprintf(http_requeset, "%s %s HTTP/1.1\r\n", HTTP_HEAD_METHOD_POST, FOG_V2_ACTIVATE_URI);
            sprintf(http_body,"{\"product_id\":\"%s\",\"mac\":\"%s\",\"devicepw\":\"%d\",\"mxchipsn\":\"%s\"}\r\n",PRODUCT_ID,ccid,mqtt_passowrd,MXCHIPSN);
        }
        else if(SIM7600_BIT_CHECK(SIM7600_action,HTTP_OTA))
        {
            sprintf(http_requeset, "%s %s HTTP/1.1\r\n", HTTP_HEAD_METHOD_POST, FOG_V2_OTA_UP_DATA_URI);
            sprintf(http_body,"{\"product_id\":\"%s\",\"firmware_type\":\"%s\",\"modulename\":\"%s\",\"firmware\":\"%s\"}\r\n",PRODUCT_ID,IOT_VERSION,MODULE_NAME,FIRMWARE_VERSION);
        }
        else if(SIM7600_BIT_CHECK(SIM7600_action,HTTP_UPLOAD_DATA))
        {
            sprintf(http_requeset, "%s %s HTTP/1.1\r\n", HTTP_HEAD_METHOD_POST, FOG_V2_SEND_EVENT_URI);
            sprintf(http_body,"{\"deviceid\":\"%s\",\"devicepw\":\"%d\",\"payload\":\"{%s}\",\"format\":\"json\",\"flag\":%d}\r\n",device_id,mqtt_passowrd,json_data,0);
            
        }
        else if(SIM7600_BIT_CHECK(SIM7600_action,HTTP_C_CONFIRM))
        {
            sprintf(http_requeset, "%s %s HTTP/1.1\r\n", HTTP_HEAD_METHOD_POST, FOG_V2_CHIPS_CONFIRM_URI);
            sprintf(http_body,"{\"orderNo\":\"%s\",\"type\":\"1\",\"status\":\"2\",\"chips\":%d}\r\n",order_num,100);
        }
        else if(SIM7600_BIT_CHECK(SIM7600_action,HTTP_FACTORY_CHECK))
        {
            sprintf(http_requeset, "%s %s HTTP/1.1\r\n", HTTP_HEAD_METHOD_POST, FOG_V2_EXAM_UPLOAD_URI);
        }
        
        sprintf(http_requeset + strlen(http_requeset), "Host: %s\r\n", HTTP_SERVER_ADDR);
        sprintf(http_requeset + strlen(http_requeset), "Content-Type: application/json;charset=utf-8\r\nConnection: Keepalive\r\n");
        http_body_length = strlen(http_body);
        
        sprintf(http_requeset + strlen(http_requeset), "Content-Length: %d\r\n\r\n", http_body_length);
        
        //*(http_requeset + strlen(http_requeset)) = SIM7600_HTTP_END_FLAG;
        
        if((http_body_length + strlen(http_requeset)) < HTTP_REQUEST_LENGTH)
        {
            sprintf(http_requeset + strlen(http_requeset), "%s", http_body);
        }
        else
        {
            printf("http requeset too long\r\n");
            goto exit;
        }
        
    }
    else if(http_step == 2)
    {
        SIM7600_cmd_info.type = CMD_TYPE;       
        strcpy(SIM7600_cmd_info.cmd,SIM7600_HTTP_END_CMD); 
        SIM7600_cmd_info.is_read_http_data = 0;
    }
    
    SIM7600_Send_data(SIM7600_cmd_info.type,SIM7600_cmd_info.cmd,http_requeset);
    
    
exit:

    if(http_body != NULL)
    {
        vPortFree(http_body);
    }
    
    if(http_requeset != NULL)
    {
        vPortFree(http_requeset);
    }


}


void SIM7600_Get_Signal_Quality(void)
{
    //unsigned char res = 0;
  
    if(SIM7600_cmd_info.Is_wait_data == 1 || Is_http == 1)
    {
        return;
    }
    
    memset(SIM7600_cmd_info.cmd,0,sizeof(SIM7600_cmd_info.cmd));
    //memset(SIM7600_cmd_info.sendtring,0,strlen(SIM7600_cmd_info.sendtring));
   
    SIM7600_cmd_info.type = CMD_TYPE;      
    strcpy(SIM7600_cmd_info.cmd,SIM7600_CSQ_CMD);   
             
    SIM7600_Send_data(SIM7600_cmd_info.type,SIM7600_cmd_info.cmd,NULL);

    //信号质量最大是99,如果数码管显示100则模块可能有问题
    signal_quality = 100;    
    
}

void SIM7600_Get_CCID(void)
{
    //unsigned char res = 0;
  
    if(SIM7600_cmd_info.Is_wait_data == 1 || Is_http == 1)
    {
        return;
    }
    
    memset(SIM7600_cmd_info.cmd,0,sizeof(SIM7600_cmd_info.cmd));
    //memset(SIM7600_cmd_info.sendtring,0,strlen(SIM7600_cmd_info.sendtring));
   
    SIM7600_cmd_info.type = CMD_TYPE;      
    strcpy(SIM7600_cmd_info.cmd,SIM7600_CICCID_CMD);   

    SIM7600_Send_data(SIM7600_cmd_info.type,SIM7600_cmd_info.cmd,NULL);    
    
}

void SIM7600_http_close(void)
{
    SIM7600_cmd_info.Is_wait_data = 0;
    Is_http = 0;
    http_step = 0;
    SIM7600_action = 0;
  
    memset(SIM7600_cmd_info.cmd,0,sizeof(SIM7600_cmd_info.cmd));
    //memset(SIM7600_cmd_info.sendtring,0,strlen(SIM7600_cmd_info.sendtring));
   
    SIM7600_cmd_info.type = CMD_TYPE;      
    strcpy(SIM7600_cmd_info.cmd,SIM7600_HTTP_END_CMD);   

    SIM7600_Send_data(SIM7600_cmd_info.type,SIM7600_cmd_info.cmd,NULL);    
}


void SIM7600_Device_Activate(void)
{   
    if(SIM7600_cmd_info.Is_wait_data == 1 || Is_http == 1)
    {
        return;
    }
    
    SIM7600_action = 0;
    SIM7600_action |= (1 << HTTP_ACTIVATE);
    
    Is_http = 1;
    http_step = 0;
}


void SIM7600_Ota_Check(void)
{
    if(Is_device_activate == 0)
    {
        return;
    } 
    
    if(SIM7600_cmd_info.Is_wait_data == 1 || Is_http == 1)
    {
        return;
    }
    
    SIM7600_action = 0;
    SIM7600_action |= (1 << HTTP_OTA);
    
    Is_http = 1;
    http_step = 0;
}


#define UPLOAD_DATA_TIME_INTERVAL   30
void SIM7600_Upload_Data(void)
{   
    unsigned long nowtime_s = 0;
  
    if(is_SIM7600_fogcloud_init == 0)
    {
        return;
    }      
    //如果 mqtt_init_step != MQTT_MAX_STEP，则正在进行MQTT初始化，此时不进行Http通讯
    if(SIM7600_cmd_info.Is_wait_data == 1 || Is_http == 1 || mqtt_init_step != MQTT_MAX_STEP)
    {
        return;
    }
    
    nowtime_s = xTaskGetTickCount();
    if(nowtime_s >= next_upload_data_time)
    {
        SIM7600_action = 0;
        SIM7600_action |= (1 << HTTP_UPLOAD_DATA);
    
        Is_http = 1; 
        http_step = 0;

        //next_upload_data_time = nowtime_s + (UPLOAD_DATA_TIME_INTERVAL | 0x00);      
        next_upload_data_time = nowtime_s + UPLOAD_DATA_TIME_INTERVAL;
    }    
}



void SIM7600_Status_Sync(void)
{
    //5秒的时间间隔
    //const unsigned long code sync_mstime_interval = 30000;
    //const unsigned long code sync_short_time_interval = 5;
    const unsigned long sync_long_time_interval = 30;
    //const unsigned long code fast_sync_continue_time = 180;
  
    unsigned long nowtime_s = 0;

  
    if(is_SIM7600_fogcloud_init == 0)
    {
        return;
    } 
    
    //如果 mqtt_init_step != MQTT_MAX_STEP，则正在进行MQTT初始化，此时不进行Http通讯
    if(SIM7600_cmd_info.Is_wait_data == 1 || Is_http == 1 || mqtt_init_step != MQTT_MAX_STEP )
    {
        return;
    }
    
    nowtime_s = xTaskGetTickCount();
    //防止时间溢出
    if(next_sync_stime > 0xF0000000 && nowtime_s < 0xE0000000)
    {
        next_sync_stime = nowtime_s;
    }
    
    
    if(nowtime_s < next_sync_stime)
    {
        return;
    }
    
    SIM7600_action = 0;
    SIM7600_action |= (1 << HTTP_SYNC);
    
    Is_http = 1;
    http_step = 0;
    
//    if(nowtime_s >= (fast_sync_start_time + fast_sync_continue_time) && charge_info.lefttime.l_time == 0)
//    {
//        if(is_fast_sync == 1)
//        {
//            is_fast_sync = 0;
//        }
//        
//    }
//    
//    if(charge_info.lefttime.l_time > 0)
//    {
//        if(is_fast_sync == 0)
//        {
//            is_fast_sync = 1;
//        }
//    }
//    
//    if(is_fast_sync == 1)
//    {
//        next_sync_stime = nowtime_s + sync_short_time_interval;
//    }
//    else 
//    {
//        next_sync_stime = nowtime_s + sync_long_time_interval;
//    }

      next_sync_stime = nowtime_s + sync_long_time_interval;
    
}



void SIM7600_Charge_Confirm(void)
{
    if(SIM7600_cmd_info.Is_wait_data == 1 || Is_http == 1)
    {
        return;
    }
    
    SIM7600_action = 0;
    SIM7600_action |= (1 << HTTP_C_CONFIRM);
    
    Is_http = 1;
    http_step = 0;
}

unsigned char SIM7600_Upload_Factory_Check_Result(void)
{
    if(SIM7600_cmd_info.Is_wait_data == 1 || Is_http == 1)
    {
        return SIM7600_BUSY;
    }
    
    SIM7600_action = 0;
    SIM7600_action |= (1 << HTTP_FACTORY_CHECK);
    
    Is_http = 1;
    http_step = 0;
    
    return SIM7600_OK;
}



int string_get_int(const char *string)
{
    unsigned char index_start = 0;
    unsigned char index_end = 0;
    unsigned char i = 0;
  
    //char buff[6] = {0};
  
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
    
    
    
    if(index_end <= index_start)
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
    
//    memset(SIM7600_cmd_info.cmd_para,0,sizeof(SIM7600_cmd_info.cmd_para));
//    strncpy(SIM7600_cmd_info.cmd_para,(string + index_start),(index_end - index_start + 1));
    
    memset(SIM7600_cmd_info.sendtring,0,strlen(SIM7600_cmd_info.sendtring));
    strncpy(SIM7600_cmd_info.sendtring,(string + index_start),(index_end - index_start + 1));
    
    
    return(atoi(SIM7600_cmd_info.sendtring));

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
    
//    memset(SIM7600_cmd_info.cmd_para,0,sizeof(SIM7600_cmd_info.cmd_para));
//    strncpy(SIM7600_cmd_info.cmd_para,(string + index_start),(index_end - index_start + 1));
    
    
    memset(SIM7600_cmd_info.sendtring,0,strlen(SIM7600_cmd_info.sendtring));
    strncpy(SIM7600_cmd_info.sendtring,(string + index_start),(index_end - index_start + 1));
    
    return(atol(SIM7600_cmd_info.sendtring));

}


void string_get_string(const char *string,char *dest)
{
    //该函数中不要使用SIM7600_cmd_info.string，ordernum复制到了该数组中
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
    
//    memset(SIM7600_cmd_info.cmd,0,sizeof(SIM7600_cmd_info.cmd));
//    sprintf(SIM7600_cmd_info.cmd,"s:%d,t:%d,l:%d\r\n",(unsigned int)index_start,(unsigned int)index_end,(unsigned int)(index_end - index_start + 1));
//    DEBUG_Uart_Sendbytes(SIM7600_cmd_info.cmd,strlen(SIM7600_cmd_info.cmd));  
    
    //DEBUG_Uart_Sendbytes((string + index_start),(index_end - index_start + 1));  

  
    
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

//检测SIM7600是否出现通讯错误，如果一直错误或者超时则重启SIM7600,SIM7600通讯指示灯控制
//此函数不需要太频繁的执行
void SIM7600_fogcloud_init_and_check(void)
{
    if((SIM7600_cmd_info.error_times >= 20 || SIM7600_cmd_info.timeout_times >= 3))
    {
        //重启SIM7600       
        SIM7600_Restart();
        
    }
  
    if(SIM7600_cmd_info.error_times != 0 || SIM7600_cmd_info.timeout_times != 0 || Is_device_activate == 0)
    {
        if(wifi_led_state == 1)
        {
            //关闭wifi led
            Wifi_Led_Off();
        }
    }
    else if(SIM7600_cmd_info.error_times == 0 && SIM7600_cmd_info.timeout_times == 0 && Is_device_activate == 1)
    {
        if(wifi_led_state == 0)
        {
            //打开wifi led
            Wifi_Led_On();
        }
    }
    
    
    if(SIM7600_register_net.Is_SIM7600_registerd == 1 && Is_Get_CCID == 0)
    {
        SIM7600_Get_CCID();
    }
    
    
    if(Is_Get_CCID == 1 && Is_device_activate == 0)
    {
        SIM7600_Device_Activate();
    }
    
    if(is_ota_check == 0 && Is_device_activate == 1)
    {
        SIM7600_Ota_Check();
    }
//    if(is_ota_check == 1 && is_mqtt_init == 0)
//    {
//        SIM7600_mqtt_init();
//    }
    
    
}



 
#define SIGNAL_CHECK_TIME_INTERVAL   61

void SIM7600_signal_check(void)
{
    static unsigned char signal_check_stimes = 0;
    //记录检测了多长时间，单位是秒，暂定检测1分钟。如果检测时间长的话需要修改变量类型
    if(Is_signal_check == 0)
    {
        if(signal_check_stimes != 0)
        {
            signal_check_stimes = 0;
        }
        return;
    }
    
    signal_check_stimes += 1;
    
    //TM1620_DispalyData(2,signal_quality);
    
    SIM7600_Get_Signal_Quality();
       
    if(signal_check_stimes >= SIGNAL_CHECK_TIME_INTERVAL)
    {
        Is_signal_check = 0;
        //Buzzer_Signal_Check();
    }   
}


/*
void SIM7600_mqtt_init(void)
{
    if(is_mqtt_init == 1 || is_ota_check == 0)
    {
        return;
    }
    
    
    if(mqtt_init_step == 0)
    {
        SIM7600_cmd_info.type = CMD_TYPE;       
        strcpy(SIM7600_cmd_info.cmd,SIM7600_MQTT_SSL_CMD);
    }
    else if(mqtt_init_step == 1)
    {
        SIM7600_cmd_info.type = CMD_TYPE;       
        strcpy(SIM7600_cmd_info.cmd,SIM7600_MQTT_CONFIG_CMD);
    }
    else if(mqtt_init_step == 2)
    {
        SIM7600_cmd_info.type = CMD_TYPE;       
        strcpy(SIM7600_cmd_info.cmd,SIM7600_MQTT_START_CMD);
    }
    else if(mqtt_init_step == 3)
    {
        SIM7600_cmd_info.type = CMD_TYPE;       
        strcpy(SIM7600_cmd_info.cmd,SIM7600_MQTT_CONNECT_CMD);
    }
    else if(mqtt_init_step == 4)
    {
        SIM7600_cmd_info.type = CMD_TYPE;       
        strcpy(SIM7600_cmd_info.cmd,SIM7600_MQTT_SUB_CMD);
    }
    
    SIM7600_Send_data(SIM7600_cmd_info.type,SIM7600_cmd_info.cmd,SIM7600_cmd_info.sendtring,0);    

}


void SIM7600_mqtt_message_check(void)
{
    char *position = NULL;
    char *mqtt_end_position = NULL;
    unsigned char i = 0;
  
    if(is_mqtt_init == 0)
    {
        return;
    }
  
    position = strstr(uart_sim7600_rx_buff,"+MSUB");
    if(position != NULL)
    {
      
//        memset(SIM7600_cmd_info.sendtring,0,strlen(SIM7600_cmd_info.sendtring));
//        sprintf(SIM7600_cmd_info.sendtring,"get +MSUB\r\n");
//        DEBUG_Uart_Sendbytes(SIM7600_cmd_info.sendtring,strlen(SIM7600_cmd_info.sendtring));
        
        mqtt_end_position = strstr(position,"\r\n");
        if(mqtt_end_position != NULL)
        {
            memset(SIM7600_cmd_info.sendtring,0,strlen(SIM7600_cmd_info.sendtring));
          
            position = strstr(uart_sim7600_rx_buff,"{");
            while(*(position + i) != '\r') 
            {
                SIM7600_cmd_info.sendtring[i] = *(position + i);
                i += 1;
            }
                   
            strcat(SIM7600_cmd_info.sendtring,"\r\n");
            
            if(*(mqtt_end_position + 2) == 0)
            {
                clear_wifi_uart_buff();
            }
            
            //DEBUG_Uart_Sendbytes(SIM7600_cmd_info.sendtring,strlen(SIM7600_cmd_info.sendtring));
            printf("%s\r\n",SIM7600_cmd_info.sendtring);
            

        }
    }
}


void SIM7600_mqtt_close(void)
{
    if(SIM7600_cmd_info.Is_wait_data == 1 || Is_http == 1)
    {
        return;
    }
  
  
    is_mqtt_init = 0;
    mqtt_init_step = 0;
  
    memset(SIM7600_cmd_info.cmd,0,sizeof(SIM7600_cmd_info.cmd));
    memset(SIM7600_cmd_info.sendtring,0,strlen(SIM7600_cmd_info.sendtring));
   
    SIM7600_cmd_info.type = CMD_TYPE;      
    strcpy(SIM7600_cmd_info.cmd,SIM7600_MQTT_CLOSE_CMD);   

    SIM7600_Send_data(SIM7600_cmd_info.type,SIM7600_cmd_info.cmd,SIM7600_cmd_info.sendtring,SIM7600_cmd_info.string_length);   
}


void SIM7600_get_mqtt_connect_status_cmd(void)
{
    if(is_mqtt_init == 0 || SIM7600_cmd_info.Is_wait_data == 1 || Is_http == 1)
    {
        return;
    }
    
    memset(SIM7600_cmd_info.cmd,0,sizeof(SIM7600_cmd_info.cmd));
    memset(SIM7600_cmd_info.sendtring,0,strlen(SIM7600_cmd_info.sendtring));
   
    SIM7600_cmd_info.type = CMD_TYPE;      
    strcpy(SIM7600_cmd_info.cmd,SIM7600_MQTT_STATUS);   

    SIM7600_Send_data(SIM7600_cmd_info.type,SIM7600_cmd_info.cmd,SIM7600_cmd_info.sendtring,SIM7600_cmd_info.string_length);     
}

void check_mqtt_status(void)
{
    if(mqtt_connect_status == 0 && is_mqtt_init == 1)
    {
        SIM7600_mqtt_close();
    }
}
*/




