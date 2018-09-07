#include "includes.h"

#define APP_LOG(M,...)  custom_log("APP", M, ##__VA_ARGS__)

__align(8) OS_STK wifi_request_stk[TASK_WIFI_REQUEST_STK_SIZE];		  //定义栈
__align(8) OS_STK modbus_task_stk[TASK_MODBUS_STK_SIZE];		  //定义栈
__align(8) OS_STK user_config_task_stk[TASK_USER_CONFIG_STK_SIZE];		  //定义栈
__align(8) OS_STK usart_wifi_task_stk[TASK_USART_WIFI_STK_SIZE];		  //定义栈

//OS_EVENT *test_mutex;
//OS_EVENT *modbus_mutex;

//extern OS_EVENT *modbus_mutex;

extern OS_EVENT *stdio_tx_mutex;

static void Task_user_config(void *p_arg);


void Task_Start(void *p_arg)
{
    INT8U err;
    uint32_t temp = 0;
  
    (void)p_arg;                				// 'p_arg' 并没有用到，防止编译器提示警告
	  SysTick_init();
    cJSON_InitHooks(NULL);
    read_user_configs();
  
    stdio_tx_mutex = OSMutexCreate(STDIO_TX_MUTEX_PRIO,&err);
    if(err == OS_ERR_NONE)
    {
        printf("create stdio_tx_mutex success\r\n");
    }
    
    //modbus_mutex = OSMutexCreate(MOUDBUS_MUTEX_PRIO,&err);
    OSTaskCreate(Task_wifi_request,(void *)0,
	     &wifi_request_stk[TASK_WIFI_REQUEST_STK_SIZE-1], TASK_WIFI_REQUEST_PRIO);

    OSTaskCreate(Task_modbus,(void *)0,
	     &modbus_task_stk[TASK_MODBUS_STK_SIZE-1], TASK_MODBUS_PRIO);	
    
    OSTaskCreate(Task_usart_wifi,(void *)0,
	     &usart_wifi_task_stk[TASK_USART_WIFI_STK_SIZE-1], TASK_USART_WIFI_PRIO);
    
    OSTaskCreate(Task_user_config,(void *)0,
	     &user_config_task_stk[TASK_USER_CONFIG_STK_SIZE-1], TASK_USER_CONFIG_PRIO);	
  
    printf("os start\r\n");  

    OSTimeDlyHMSM(0, 0,1,0);       

    while (1)
    {
        //LED1( ON );
        OSTimeDlyHMSM(0, 0,1,0);
        //LED1( OFF);   
		    OSTimeDlyHMSM(0, 0,1,0); 

        temp += 1;
        if(temp % 3 == 0)
        {
            APP_LOG("FreeHeapSize:%d",mem_free_size()); 
        }
        
    }
}




extern volatile uint8_t config_rx_index; 
static void Task_user_config(void *p_arg)
{
    (void)p_arg; 
    //uint8_t *p = NULL;
  
    
	
    while (1)
    {
        //printf("hello\r\n");
        deal_user_config_info();
     
        OSTimeDlyHMSM(0,0,1,0);   
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






