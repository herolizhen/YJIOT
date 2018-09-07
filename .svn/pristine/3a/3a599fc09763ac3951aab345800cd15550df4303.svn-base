#include "stdio.h"
#include "string.h"
#include "user_usart.h"
#include "user_usart1.h"
#include "user_modbus.h"
#include "user_config.h"
#include "ucos_ii.h" 
#include "trans_recieve_buff_control.h"
#include "modbus_master.h"
#include "cJSON.h"
#include "user_usart_wifi.h"
#include "malloc.h"
#include "app_cfg.h"


#define SEND_BUFF_SIZE   150

OS_EVENT *modbus_mutex;

uint32_t next_readtimes[MAX_CONFIG_NUM] = {0};

extern user_configs_info_t user_configs_info;
extern uint16_t ku16MBResponseTimeout;
extern uint16_t _u16ResponseBuffer[ku8MaxBufferSize];    

extern uint8_t rx_index; 
extern uint8_t     m_Modbus_Master_RX_Buff[RX_Buff_SIZE];

extern OS_EVENT *wifi_usart_res_queue;

#define MAX_WAIT_WIFI_RESPONSE_TIME  2000
void moubus_loop(void)
{
    uint8_t i = 0;
    uint8_t slave_id = 0;
    uint16_t read_addr = 0;
    uint8_t read_quantity = 0;
    uint32_t nowtime = 0;
    uint8_t result = 0; 
    uint8_t *sendbuff = NULL;
    uint8_t frame_length = 0;
    INT8U err; 
    wifi_data_msg_t *res_msg = NULL;
    
    if(user_configs_info.config_num == 0)
    {
        return;
    }
    
    for(i = 0;i < user_configs_info.config_num;i++)
    {
        nowtime = OSTimeGet();
        //防止时间溢出后，无法进入Modbus数据采集
        if(nowtime < 0x10000000 && next_readtimes[i] > 0xF0000000)
        {
            next_readtimes[i] = nowtime;
        }
        
        if(nowtime >= next_readtimes[i])
        {
            OSMutexPend(modbus_mutex,0,&err);      
            slave_id = (uint8_t)(user_configs_info.user_configs[i]->slave_addr & 0xFF);
            read_addr = (uint16_t)(user_configs_info.user_configs[i]->start_addr & 0xFFFF);
            read_quantity = (uint8_t)(user_configs_info.user_configs[i]->length & 0xFF);
            if(user_configs_info.user_configs[i]->timeout <= 0)
            {
                ku16MBResponseTimeout = 2000;
            }
            else
            {
                ku16MBResponseTimeout = ((uint16_t)(user_configs_info.user_configs[i]->timeout & 0xFFFF)) * 1000;
            }
                
            WIFI_UART_LOG("slave_id=%d,read_addr=%d,quantity=%d",slave_id,read_addr,read_quantity);           
            //result = ModbusMaster_readHoldingRegisters(slave_id,read_addr,read_quantity);
            result = ModbusMaster_readInputRegisters(slave_id,read_addr,read_quantity);
            WIFI_UART_LOG("result=%d",result);
            if(result == 0x00)
            {
                //send data to wifi
                //memset(header,0,sizeof(header));
                //sprintf(header,"%s%s%d:",WIFI_UART_START,SLAVE,i);
                //wifi_usart_sendbytes((uint8_t *)header,strlen(header));
                //send_data_to_wifi(_u16ResponseBuffer,i);  
                //wifi_usart_sendbytes((uint8_t *)WIFI_UART_STOP,strlen(WIFI_UART_STOP));
              
                sendbuff = mymalloc(SEND_BUFF_SIZE);
                memset(sendbuff,0,SEND_BUFF_SIZE);
                result = send_data_to_buffer(sendbuff,_u16ResponseBuffer,i,&frame_length);
                if(result == 0)
                {
                    wifi_usart_sendbytes(sendbuff,frame_length);
                }
                myfree(sendbuff);
                
                //把wifi返回的小于0x10功能码的消息从队列取出来，不然队列会一直满，可以判断返回的消息是否跟发送的消息对应，此处没有判断
                res_msg = OSQPend(wifi_usart_res_queue,MAX_WAIT_WIFI_RESPONSE_TIME,&err);
                if(err == OS_ERR_NONE)
                {
                    if(res_msg->databuff != NULL)
                    {
                        myfree(res_msg->databuff);
                        res_msg->databuff = NULL;
                    }
            
                    if(res_msg != NULL)
                    {
                        myfree(res_msg);
                        res_msg = NULL;
                    }
                }                            
            }
            OSMutexPost(modbus_mutex);
                
            next_readtimes[i] = nowtime + user_configs_info.user_configs[i]->timeinterval * 1000;
                
            OSTimeDlyHMSM(0,0,1,0);    
        }
        OSTimeDlyHMSM(0,0,0,500);
    }   
}


uint8_t calculate_check_sum(uint8_t *data_buff,uint8_t length,uint16_t *checksum)
{
    uint8_t i = 0;
    uint16_t temp_checksum = 0;
  
    if(data_buff == NULL || length <= 0 || checksum == NULL)
    {
        return 1;
    }
    
    for(i = 0;i < length;i++)
    {
        temp_checksum += data_buff[i];
    }
    
    *checksum = temp_checksum;
    
    return 0;

}


uint8_t send_data_to_buffer(uint8_t *uart_buff,const uint16_t *data_buff,uint8_t which_config,uint8_t *frame_length)
{
    uint8_t ret = 0;
    uint8_t i = 0;
    uint8_t size = 0;
    cJSON *root = NULL;
    //char *s = NULL;  
    char *json_srting = NULL;
    float temp_data = 0;
    uint8_t string_length = 0;
    uint8_t index = 0;
    uint16_t check_sum = 0;
  
    //uint16_t temp_value = 0;
  
    if(uart_buff == NULL || data_buff == NULL || frame_length == NULL)
    {
        return 3;
    }
  
    if(user_configs_info.user_configs[which_config]->length >= user_configs_info.user_configs[which_config]->key_num)
    {
        size = (uint8_t)(user_configs_info.user_configs[which_config]->key_num & 0xFF);
    }
    else 
    {
        size = (uint8_t)(user_configs_info.user_configs[which_config]->length & 0xFF);
    }
    
    if(size > MAX_KEY_NUM)
    {
        size = MAX_KEY_NUM;
    }
    
    root = cJSON_CreateObject();
    if(root == NULL)
    {
        ret = 1;
        goto exit;
    }
    
//    s = user_configs_info.user_configs[which_config]->device_id;
//    
//    cJSON_AddItemToObject(root, "deviceid", cJSON_CreateString(s));
      
    for(i = 0;i < size;i++)
    {
        printf("data%d:%d ",i,data_buff[i]);
    }
    printf("\r\n");
    
    for(i = 0;i < size;i++)
    {
        temp_data = (float)data_buff[i] / user_configs_info.user_configs[which_config]->division[i];
        
        cJSON_AddItemToObject(root, user_configs_info.user_configs[which_config]->key.keys[i], cJSON_CreateNumber(temp_data));
    }
    
    json_srting = cJSON_PrintUnformatted(root);
    if(json_srting == NULL)
    {
        ret = 2;
        goto json_string_error;        
    }
    
    WIFI_UART_LOG("%s",json_srting);
    
    string_length = strlen(json_srting);
    
    uart_buff[0] = 0x2A;
    uart_buff[1] = string_length + 4;
    uart_buff[2] = 0x01;
    uart_buff[3] = which_config;
    sprintf((char *)(uart_buff + 4),"%s",json_srting);
    index = uart_buff[1];
    
    ret = calculate_check_sum(uart_buff + 1,uart_buff[1] - 1,&check_sum);
    if(ret != 0)
    {
        goto check_sum_error;
    }
    
    uart_buff[index++] = (uint8_t)(check_sum & 0xFF);
    uart_buff[index++] = (uint8_t)((check_sum >> 8) & 0xFF);
    uart_buff[index] = 0x23;
    
    *frame_length = index + 1;
    
    myfree(json_srting);
    
    cJSON_Delete(root);
    
    return 0;
    
check_sum_error:
    
    ret = 4;
json_string_error:    
    cJSON_Delete(root);
    
    
exit:
    if(json_srting != NULL)
    {
        myfree(json_srting);
    }
    
    return ret;  

}







void modbus_usart_handler(void)
{
    if(USART_GetITStatus(MODBUS_USART, USART_IT_RXNE) != RESET)
    {          
        //recv_data_num ++;
        Modbus_Master_Rece_Handler();
      
        USART_ClearITPendingBit(MODBUS_USART, USART_IT_RXNE);  
    }
    else if(USART_GetITStatus(MODBUS_USART, USART_IT_TXE) != RESET)
    {
        USART_ClearITPendingBit(MODBUS_USART, USART_IT_TXE);  
    }
}


void rs485_control_pin_config(void)
{

    GPIO_InitTypeDef GPIO_InitStruchture;
	
    RCC_APB2PeriphClockCmd(RS485_CONTROL_GPIO_CLK, ENABLE);
	
    GPIO_InitStruchture.GPIO_Pin = RS485_CONTROL_PIN;
    GPIO_InitStruchture.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruchture.GPIO_Speed = GPIO_Speed_50MHz;
	
    GPIO_Init(RS485_CONTROL_PORT, &GPIO_InitStruchture);
  
    RS485_CONTROL_PIN_LOW();

}

uint8_t MODBUS_RS485_SendBytes( USART_TypeDef * pUSARTx,const uint8_t *buff,uint8_t length) 
{
    if(buff == NULL || length <= 0)
    {
        return 1;
    }
    
    RS485_CONTROL_PIN_HIGH();
    OSTimeDlyHMSM(0,0,0,1);
    
    while(length--)
    {
        Usart_SendOneByte(pUSARTx,*buff++);
    }
    //延时2ms，否则485模块数据发送不完
    OSTimeDlyHMSM(0,0,0,2);
    
    RS485_CONTROL_PIN_LOW();
    
    return 0;
  
}




void Task_modbus(void *p_arg)
{
    uint8_t i = 0;
  
    INT8U err;

    (void)p_arg; 
    
    usart1_config(MODBUS_USART,9600);
    rs485_control_pin_config();
  
    OSTimeDlyHMSM(0,0,0,100);
  
    modbus_mutex = OSMutexCreate(MOUDBUS_MUTEX_PRIO,&err);
    
    ModbusMaster_begin();  
  
    if(user_configs_info.config_num == 0)
    {
        WIFI_UART_LOG("user_configs_info.config_num == 0");
        goto exit;
    }
    
    for(i = 0;i < user_configs_info.config_num;i++)
    {
        next_readtimes[i] = user_configs_info.user_configs[i]->timeinterval;
    }
	
    while (1)
    {
/*
        result = ModbusMaster_readInputRegisters(0x01,0x0,2);
        WIFI_UART_LOG("result:%d",result);
        if (result == 0x00)
        {
            temp = m_Modbus_Master_RX_Buff[2] + 5;
            printf("get data:");
            for(i = 0;i < temp;i++)
            {
                printf("%x ",m_Modbus_Master_RX_Buff[i]);
            }
            printf("\r\n");
            
        }
        OSTimeDlyHMSM(0, 0,5,0);
 */    
        moubus_loop();
        OSTimeDlyHMSM(0,0,0,100);
        
//        OSTimeDlyHMSM(0,0,1,0);
//        printf("Task_modbus\r\n");
        
    }
    
exit:
    OSTaskDel(TASK_MODBUS_PRIO);
}






