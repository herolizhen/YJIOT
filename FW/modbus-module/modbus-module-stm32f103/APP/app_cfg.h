#ifndef  __APP_CFG_H__
#define  __APP_CFG_H__


/*******************设置任务优先级*******************/
#define STARTUP_TASK_PRIO       4	   

#define	TASK_WIFI_REQUEST_PRIO			5 
#define	TASK_MODBUS_PRIO			6 
#define	TASK_USART_WIFI_PRIO			7
#define	TASK_USER_CONFIG_PRIO			8

#define MOUDBUS_MUTEX_PRIO      10
#define WIFI_USART_TX_MUTEX_PRIO      11
#define STDIO_TX_MUTEX_PRIO     12

/************设置栈大小（单位为 OS_STK ）************/
#define STARTUP_TASK_STK_SIZE   80 
#define	TASK_WIFI_REQUEST_STK_SIZE		150
#define	TASK_MODBUS_STK_SIZE		200
#define	TASK_USER_CONFIG_STK_SIZE		100
#define	TASK_USART_WIFI_STK_SIZE		(256*1)

#endif

