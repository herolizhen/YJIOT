#include "stdio.h"
#include "string.h"
#include "ucos_ii.h" 
#include "user_mqtt_task.h"
#include "sim7600.h"
#include "app.h"
#include "malloc.h"


extern OS_EVENT *mqtt_message_queue;

void user_mqtt_task(void *para)
{
    char *json_data = NULL;
    INT8U err = 0;
  
    while(1)
    {
        OSTimeDlyHMSM(0,0,0,2); 
      
        if(is_queue_empty(mqtt_message_queue) != QUEUE_EMPTY)
        {          
            json_data = OSQPend(mqtt_message_queue,10,&err);
            if(err == OS_ERR_NONE)
            {
                MQTT_LOG("json data:%s",json_data);
                myfree(json_data);
                json_data = NULL;
            }

        }
        
        if(json_data != NULL)
        {
            myfree(json_data);
            json_data = NULL;
        }
      
      
               
        
    }
}

