#include "stdio.h"
#include "string.h"
#include "user_usart2.h"
#include "user_modbus.h"
#include "user_config.h"
#include "ucos_ii.h" 
#include "trans_recieve_buff_control.h"
#include "modbus_master.h"
#include "cJSON.h"
#include "user_usart_wifi.h"
#include "malloc.h"
#include "app_cfg.h"


OS_EVENT *modbus_mutex;

uint32_t next_readtimes[MAX_CONFIG_NUM] = {0};

extern user_configs_info_t user_configs_info;
extern uint16_t ku16MBResponseTimeout;
extern uint16_t _u16ResponseBuffer[ku8MaxBufferSize];    

extern uint8_t rx_index; 
extern uint8_t     m_Modbus_Master_RX_Buff[RX_Buff_SIZE];

void moubus_loop(void)
{
    uint8_t i = 0;
    uint8_t slave_id = 0;
    uint16_t read_addr = 0;
    uint8_t read_quantity = 0;
    uint32_t nowtime = 0;
    uint8_t result = 0;
  
    INT8U err;
    
    if(user_configs_info.config_num == 0)
    {
        return;
    }
    
    for(i = 0;i < user_configs_info.config_num;i++)
    {
        nowtime = OSTimeGet();
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
                
                       
            result = ModbusMaster_readHoldingRegisters(slave_id,read_addr,read_quantity);
            printf("result=%d\r\n",result);
            if(result == 0x00)
            {
                //send data to wifi
                wifi_usart_sendbytes((uint8_t *)WIFI_UART_START,strlen(WIFI_UART_START));
                wifi_usart_sendbytes((uint8_t *)DATA_CMD,strlen(DATA_CMD));
                send_data_to_wifi(_u16ResponseBuffer,i);  
                wifi_usart_sendbytes((uint8_t *)WIFI_UART_STOP,strlen(WIFI_UART_STOP));
            }
            OSMutexPost(modbus_mutex);
                
            next_readtimes[i] = nowtime + user_configs_info.user_configs[i]->timeinterval * 1000;
                
                
        }
        OSTimeDlyHMSM(0,0,0,10);
    }   
}


uint8_t send_data_to_wifi(const uint16_t *data_buff,uint8_t which_config)
{
    uint8_t ret = 0;
    uint8_t i = 0;
    uint8_t size = 0;
    cJSON *root = NULL;
    //cJSON *item = NULL;
    char *s = NULL;
  
    char *json_srting = NULL;
  
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
    
    s = user_configs_info.user_configs[which_config]->device_id;
    
    cJSON_AddItemToObject(root, "deviceid", cJSON_CreateString(s));
    
    for(i = 0;i < size;i++)
    {
        cJSON_AddItemToObject(root, user_configs_info.user_configs[which_config]->key.keys[i], cJSON_CreateNumber(data_buff[i]));
    }
    
    json_srting = cJSON_PrintUnformatted(root);
    if(json_srting == NULL)
    {
        ret = 2;
        goto json_string_error;        
    }
    
    printf("%s\r\n",json_srting);
    
    wifi_usart_sendbytes((uint8_t *)json_srting,strlen(json_srting));
    
    myfree(json_srting);
    
    cJSON_Delete(root);
    
    return 0;
    
json_string_error:    
    cJSON_Delete(root);
    
    
exit:
    
    return ret;  

}







void Task_modbus(void *p_arg)
{
    uint8_t i = 0;
  
    INT8U err;

    (void)p_arg; 
    
    usart2_config(USART2,9600);
  
    modbus_mutex = OSMutexCreate(MOUDBUS_MUTEX_PRIO,&err);
    
    ModbusMaster_begin();  
  
    if(user_configs_info.config_num == 0)
    {
        printf("user_configs_info.config_num == 0\r\n");
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
        printf("result:%d\r\n",result);
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
        
    }
    
exit:
    OSTaskDel(TASK_MODBUS_PRIO);
}






