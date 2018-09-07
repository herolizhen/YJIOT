#include "string.h"
#include "stm32f0xx.h"
#include "stdio.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "user_sim7600.h"
#include "sim7600.h"
#include "user_updata_data.h"
#include "user_mqtt_task.h"


#define  UPLOAD_DATA_QUEUE_SIZE     1
#define  MQTT_MESSAGE_QUEUE_SIZE    2



extern void usart_config(USART_TypeDef* USARTx, uint32_t BaudRate);

void led_port_config(void);


void led_config(void);

void led_task(void *para);


void test_task(void *para);


xQueueHandle upload_data_queue;
xQueueHandle mqtt_message_queue;


int main(void)
{
	RCC_ClocksTypeDef RCC_Clocks;

	//获取系统时钟频率
	RCC_GetClocksFreq(&RCC_Clocks);
	//将SysTick定时器的中断频率设置1ms，即FreeRTOS的时间片为1ms
	SysTick_Config(RCC_Clocks.HCLK_Frequency / 1000);
  
  //cJSON_InitHooks(NULL);
  usart_config(USART1, 115200);
  
  led_port_config();
  
  upload_data_queue = xQueueCreate(UPLOAD_DATA_QUEUE_SIZE,HTTP_BODY_LENGTH);
  if(upload_data_queue == 0)
  {
  
  }
  
  mqtt_message_queue = xQueueCreate(MQTT_MESSAGE_QUEUE_SIZE,SIM7600_PAYLAOD_BUFF_SIZE);
  if(mqtt_message_queue == 0)
  {
  
  }

	//创建LED任务
	//xTaskCreate(led_task, ( signed char * )"led", 50, NULL, 2, NULL);
  xTaskCreate(uart_sim7600_task, ( signed char * )"uart_sim7600_task", 128, NULL, 1, NULL);
  xTaskCreate(user_upload_data_task, ( signed char * )"user_upload_data_task", 150, NULL, 3, NULL);
  xTaskCreate(user_mqtt_task, ( signed char * )"user_mqtt_task", 80, NULL, 4, NULL);
  
  
  printf("os start\r\n");
	
	vTaskStartScheduler();
	
	while (1)
	{
   
	}
}


void led_port_config(void)
{
	GPIO_InitTypeDef GPIO_InitStruchture;
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);
	
	GPIO_InitStruchture.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStruchture.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruchture.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruchture.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruchture.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOC, &GPIO_InitStruchture);
	
	GPIO_SetBits(GPIOC, GPIO_Pin_13);
}


/*
void led_task(void *para)
{
	const uint8_t *COMPILED_DATE=__DATE__;//获得编译日期
	const uint8_t *COMPILED_TIME=__TIME__;//获得编译时间

	
	//uint32_t runtime = 0;
	
	led_port_config();
		
	
	
	printf("FreeRTOS 7.6.0 for STM32F030\r\n");
	printf("Build date: ");
	printf((char *)COMPILED_DATE);
	printf(" ");
	printf((char *)COMPILED_TIME);
	printf("\r\n");
	
	while (1)
	{    
    GPIO_ResetBits(GPIOC, GPIO_Pin_13);
		
		vTaskDelay(500);
    
    GPIO_SetBits(GPIOC, GPIO_Pin_13);
		
		vTaskDelay(500);
		
		//printf("led_task has run %ds.\r\n",++runtime);
    
    printf("FreeHeapSize:%d\r\n",xPortGetFreeHeapSize());
	}
	
}

*/







//内存分配失败的钩子函数，configUSE_MALLOC_FAILED_HOOK定义为1时会调用
//void vApplicationMallocFailedHook( void )
//{
//	/* vApplicationMallocFailedHook() will only be called if
//	configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h.  It is a hook
//	function that will get called if a call to pvPortMalloc() fails.
//	pvPortMalloc() is called internally by the kernel whenever a task, queue,
//	timer or semaphore is created.  It is also called by various parts of the
//	demo application.  If heap_1.c or heap_2.c are used, then the size of the
//	heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE in
//	FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
//	to query the size of free heap space that remains (although it does not
//	provide information on how the remaining heap might be fragmented). */
//	taskDISABLE_INTERRUPTS();
//	for( ;; );
//}
///*-----------------------------------------------------------*/

//空闲任务钩子函数，configUSE_IDLE_HOOK定义为1时需要定义这个函数
//void vApplicationIdleHook( void )
//{
//	/* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
//	to 1 in FreeRTOSConfig.h.  It will be called on each iteration of the idle
//	task.  It is essential that code added to this hook function never attempts
//	to block in any way (for example, call xQueueReceive() with a block time
//	specified, or call vTaskDelay()).  If the application makes use of the
//	vTaskDelete() API function (as this demo application does) then it is also
//	important that vApplicationIdleHook() is permitted to return to its calling
//	function, because it is the responsibility of the idle task to clean up
//	memory allocated by the kernel to any task that has since been deleted. */
//}
///*-----------------------------------------------------------*/

//堆栈溢出钩子函数，configCHECK_FOR_STACK_OVERFLOW定义为1或2时会调用
//void vApplicationStackOverflowHook( xTaskHandle pxTask, signed char *pcTaskName )
//{
//	( void ) pcTaskName;
//	( void ) pxTask;

//	/* Run time stack overflow checking is performed if
//	configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
//	function is called if a stack overflow is detected. */
//	taskDISABLE_INTERRUPTS();
//	for( ;; );
//}
///*-----------------------------------------------------------*/

//时钟嘀嗒钩子函数，在SysTick定时器中断处理函数中会调用这个函数，所以此函数在调用FreeRTOS API时需要注意安全
//configUSE_TICK_HOOK被定义为1时会调用
//void vApplicationTickHook( void )
//{
//	/* This function will be called by each tick interrupt if
//	configUSE_TICK_HOOK is set to 1 in FreeRTOSConfig.h.  User code can be
//	added here, but the tick hook is called from an interrupt context, so
//	code must not attempt to block, and only the interrupt safe FreeRTOS API
//	functions can be used (those that end in FromISR()). */
//}
///*-----------------------------------------------------------*/

