#include "stdio.h"
#include "string.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "user_updata_data.h"
#include "sim7600.h"

extern uint16_t mqtt_passowrd;
extern char device_id[40];

extern uint8_t is_SIM7600_fogcloud_init;

extern xQueueHandle upload_data_queue;

void user_upload_data_task(void *para)
{
    char *upload_data1 = "\\\"KEY\\\":\\\"value\\\"";
    char *upload_data2 = "\\\"key\\\":\\\"value\\\"";
  
    char *pbuff = NULL;
  
    signed res = 0;
    
    while(1)
    {
        

        if(is_SIM7600_fogcloud_init == 0)
        {
            vTaskDelay(5000);
            continue;
        }
      
        pbuff = pvPortMalloc(HTTP_BODY_LENGTH);
        memset(pbuff,0,HTTP_BODY_LENGTH);
            
//        xQueueOverwrite(upload_data_queue,upload_data1);      

//        memset(pbuff,0,HTTP_BODY_LENGTH);
//        res = xQueueReceive(upload_data_queue,pbuff,0);
//        if(res == pdTRUE)
//        {
//            printf("get data1:%s\r\n",pbuff);
//        }
//        else
//        {
//            printf("xQueueReceive fail 1\r\n");
//        }
      
        sprintf(pbuff,"{\"deviceid\":\"%s\",\"devicepw\":\"%d\",\"payload\":\"{%s}\",\"format\":\"json\",\"flag\":%d}\r\n",device_id,mqtt_passowrd,upload_data2,0);
        
        xQueueOverwrite(upload_data_queue,pbuff); 
      

//        memset(pbuff,0,HTTP_BODY_LENGTH);
//        res = xQueueReceive(upload_data_queue,pbuff,0);
//        if(res == pdTRUE)
//        {
//            printf("get data2:%s\r\n",pbuff);
//        }
//        else
//        {
//            printf("xQueueReceive fail 2\r\n");
//        }
//        
//        printf("3 queue is full:%d\r\n",(int)xQueueIsQueueFullFromISR(upload_data_queue));
        
        if(pbuff != NULL)
        {
            vPortFree(pbuff);
        }
        
        vTaskDelay(30000);
        
    }
}











