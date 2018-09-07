#include "includes.h"
#include "user_debug.h"


#define APP_LOG(M,...)  custom_log("APP", M, ##__VA_ARGS__)


#define UPLOAD_DATA_MESSAGE_NUM  1
#define UPLOAD_RES_NUM           1
#define MQTT_CMD_MESSAGE_NUM    1
#define MQTT_ACTION_RES_MESSAGE_NUM    1
#define MQTT_DATA_MESSAGE_NUM    3

     

//OS_STK modbus_task_stk[TASK_MODBUS_STK_SIZE];		  //定义栈
OS_STK user_mqtt_task_stk[TASK_USER_MQTT_STK_SIZE];		  //定义栈
OS_STK user_l506_task_stk[TASK_L506_STK_SIZE];		  //定义栈
OS_STK user_upload_data_task_stk[TASK_UPLOAD_DATA_STK_SIZE];		  //定义栈
OS_STK fogcloud_init_and_monitor_task_stk[TASK_FOG_INIT_AND_MONITOR_STK_SIZE];		  //定义栈

//OS_EVENT *test_mutex;
//OS_EVENT *modbus_mutex;





OS_EVENT *upload_data_queue;
OS_EVENT *upload_res_queue;

OS_EVENT *mqtt_action_cmd_queue;
OS_EVENT *mqtt_action_res_queue;
OS_EVENT *mqtt_message_queue;

OS_EVENT *upload_data_mutex;
//OS_EVENT *mqtt_cmd_mutex;




void *upload_data_msg[UPLOAD_DATA_MESSAGE_NUM];
void *upload_res_msg[UPLOAD_RES_NUM];
void *mqtt_action_cmd_msg[MQTT_CMD_MESSAGE_NUM];
void *mqtt_action_res_msg[MQTT_ACTION_RES_MESSAGE_NUM];
void *mqtt_data_msg[MQTT_DATA_MESSAGE_NUM];

//extern void L506_task(void *p_arg);

extern volatile uint16_t uart_L506_rx_index;

void Task_Start(void *p_arg)
{
    INT8U err;
    //uint32_t temp = 0;
    (void)p_arg;                				// 'p_arg' 并没有用到，防止编译器提示警告
	  SysTick_init();
    cJSON_InitHooks(NULL);
  
    
    upload_data_queue = OSQCreate(&upload_res_msg[0],UPLOAD_DATA_MESSAGE_NUM);
    if(upload_data_queue == NULL)
    {
        APP_LOG("create upload_data_queue fail");
    }
    else
    {
        APP_LOG("create upload_data_queue success");
    }
    
    upload_res_queue = OSQCreate(&upload_data_msg[0],UPLOAD_RES_NUM);
    if(upload_res_queue == NULL)
    {
        APP_LOG("create upload_res_queue fail");
    }
    else
    {
        APP_LOG("create upload_res_queue success");
    }

    mqtt_action_cmd_queue = OSQCreate(&mqtt_action_cmd_msg[0],MQTT_CMD_MESSAGE_NUM);
    if(mqtt_action_cmd_queue == NULL)
    {
        APP_LOG("create mqtt_action_cmd_queue fail");
    }
    else
    {
        APP_LOG("create mqtt_action_cmd_queue success");
    }
    
    mqtt_action_res_queue = OSQCreate(&mqtt_action_res_msg[0],MQTT_ACTION_RES_MESSAGE_NUM);
    if(mqtt_action_res_queue == NULL)
    {
        APP_LOG("create mqtt_action_res_queue fail");
    }
    else
    {
        APP_LOG("create mqtt_action_res_queue success");
    }
    
    mqtt_message_queue = OSQCreate(&mqtt_data_msg[0],MQTT_DATA_MESSAGE_NUM);
    if(mqtt_message_queue == NULL)
    {
        APP_LOG("create mqtt_message_queue fail");
    }
    else
    {
        APP_LOG("create mqtt_message_queue success");
    }
      
    
    upload_data_mutex = OSMutexCreate(UPLOAD_MUTEX_PRIO,&err);
    if(err == OS_ERR_NONE)
    {
        printf("create upload_data_mutex success\r\n");
    }
    if(upload_data_mutex == NULL)
    {
    
    }
    
    //mqtt_cmd_mutex = OSMutexCreate(MQTT_CMD_MUTEX_PRIO,&err);
    
    
    stdio_tx_mutex = OSMutexCreate(STDIO_TX_MUTEX_PRIO,&err);
    if(err == OS_ERR_NONE)
    {
        printf("create stdio_tx_mutex success\r\n");
    }
    if(stdio_tx_mutex == NULL)
    {
    
    }
    


    
    OSTaskCreate(sim7600_task,(void *)0,
	     &user_l506_task_stk[TASK_L506_STK_SIZE-1], TASK_L506_PRIO);
    
    OSTaskCreate(user_mqtt_task,(void *)0,
	     &user_mqtt_task_stk[TASK_USER_MQTT_STK_SIZE-1], TASK_USER_MQTT_PRIO);	
    
    OSTaskCreate(user_upload_data_task,(void *)0,
	     &user_upload_data_task_stk[TASK_UPLOAD_DATA_STK_SIZE-1], TASK_UPLOAD_DATA_PRIO);
    
    OSTaskCreate(sim7600_fogcloud_init_and_monitor_task,(void *)0,
	     &fogcloud_init_and_monitor_task_stk[TASK_FOG_INIT_AND_MONITOR_STK_SIZE-1], TASK_FOG_INIT_AND_MONITOR_PRIO);
  
    printf("os start\r\n");  

    OSTimeDlyHMSM(0,0,1,0);     

    while (1)
    {
        LED1( ON );
        OSTimeDlyHMSM(0,0,1,0);
        //APP_LOG("FreeHeapSize:%d",mem_free_size()); 
        LED1( OFF);   
		    OSTimeDlyHMSM(0,0,1,0); 

//        temp += 1;
//        if(temp % 3 == 0)
//        {
//            printf("FreeHeapSize:%d\r\n",mem_free_size()); 
//        }
      //printf("FreeHeapSize:%d\r\n",mem_free_size()); 
        APP_LOG("FreeHeapSize:%d",mem_free_size());
        
    }
}



int is_queue_full(OS_EVENT *pevent)
{
    OS_Q_DATA p_q_data = {0};
    INT8U err = 0;
    int res = 0;
  
    err = OSQQuery(pevent,&p_q_data);
    if(err == OS_ERR_NONE)
    {
        if(p_q_data.OSNMsgs >= p_q_data.OSQSize)
        {
            res = 1;
        }
        else
        {
            res = 0;
        }
    }
    else
    {
        res = -1;
    }
    
    return res;
    
}

int is_queue_empty(OS_EVENT *pevent)
{
    OS_Q_DATA p_q_data = {0};
    INT8U err = 0;
    int res = 0;
  
    err = OSQQuery(pevent,&p_q_data);
    if(err == OS_ERR_NONE)
    {
        if(p_q_data.OSNMsgs == 0)
        {
            res = 1;
        }
        else
        {
            res = 0;
        }
    }
    else
    {
        res = -1;
    }
    
    return res;
}





