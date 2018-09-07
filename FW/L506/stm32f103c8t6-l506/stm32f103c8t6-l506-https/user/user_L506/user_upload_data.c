#include "stdio.h"
#include "string.h"
#include "ucos_ii.h" 
#include "user_updata_data.h"
#include "L506.h"
#include "malloc.h"
#include "app.h"

extern uint16_t mqtt_passowrd;
extern char device_id[40];

extern uint8_t is_L506_fogcloud_init;

extern OS_EVENT *upload_data_queue;
extern OS_EVENT *upload_res_queue;

void user_upload_data_task(void *para)
{
    //INT8U err;
    //char *upload_data1 = "\\\"KEY\\\":\\\"value\\\"";
    char *upload_data2 = "\\\"key\\\":\\\"value\\\"";
  
    char *pbuff = NULL;
  
    uint8_t res = 0;
  
    OSTimeDlyHMSM(0,0,10,0);
  
device_activate:  
    res = device_activate_event();
    if(res != UPLOAD_SUCCESS)
    {
        goto device_activate;
    }
    
    OSTimeDlyHMSM(0,0,10,0);
    
get_token:
    res = device_get_token_event();
    if(res != UPLOAD_SUCCESS)
    {
        goto get_token;
    }

ota_check:    
    res = device_ota_check_event();
    if(res != UPLOAD_SUCCESS)
    {
        goto ota_check;
    } 
mqtt_init:
    res = mqtt_init_event();
    if(res != MQTT_ACTION_SUCCESS)
    {
        goto mqtt_init;
    } 
    
    
    while(1)
    {
//        if(is_L506_fogcloud_init == 0)
//        {
//            OSTimeDlyHMSM(0,0,3,0);
//            continue;
//        }
        OSTimeDlyHMSM(0,0,30,0);
        pbuff = mymalloc(HTTP_BODY_LENGTH);
        memset(pbuff,0,HTTP_BODY_LENGTH);
    
        sprintf(pbuff,"{%s}",upload_data2);
//        err = OSQPost(upload_data_queue,pbuff);
//        if(err != OS_ERR_NONE)
//        {
//            myfree(pbuff);
//            OSTimeDlyHMSM(0,0,3,0);
//            continue;
//        }

          
          //device_activate_event();
          res = upload_data_event(pbuff,0,NULL);
          UPLOAD_LOG("upload res = %d",res);
          myfree(pbuff);
    }
}














