#include "stdio.h"
#include "string.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "user_mqtt_task.h"
#include "sim7600.h"


extern xQueueHandle mqtt_message_queue;

void user_mqtt_task(void *para)
{
    char *json_data = NULL;
  
    while(1)
    {
        vTaskDelay(3);
      
        if(xQueueIsQueueEmptyFromISR(mqtt_message_queue) != pdTRUE)
        {
            json_data = pvPortMalloc(SIM7600_PAYLAOD_BUFF_SIZE);
            if(json_data == NULL)
            {
                printf("user_mqtt_task malloc fail\r\n");
                continue;
            }
            
            memset(json_data,0,SIM7600_PAYLAOD_BUFF_SIZE);
            if(xQueueReceive(mqtt_message_queue,json_data,0) != pdTRUE)
            {
                vPortFree(json_data);
                json_data = NULL;
                continue;
            }
            
            printf("json data:%s\r\n",json_data);
            
            vPortFree(json_data);
            json_data = NULL;
        }
        
        if(json_data != NULL)
        {
            vPortFree(json_data);
            json_data = NULL;
        }
        
        
    }
}