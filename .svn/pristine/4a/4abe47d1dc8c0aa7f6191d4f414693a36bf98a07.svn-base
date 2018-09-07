#include "includes.h"

/*
 * 函数名：BSP_Init
 * 描述  ：时钟初始化、硬件初始化
 * 输入  ：无
 * 输出  ：无
 */
extern void usart1_config(USART_TypeDef* USARTx, uint32_t BaudRate);
void BSP_Init(void)
{
    SystemInit();		/* 配置系统时钟为72M */	
    LED_GPIO_Config();  /* LED 端口初始化 */
    //usart1_config(USART1,115200);
    usart3_config(USART3,115200);
    
}

/*
 * 函数名：SysTick_init
 * 描述  ：配置SysTick定时器
 * 输入  ：无
 * 输出  ：无
 */
void SysTick_init(void)
{
    SysTick_Config(SystemFrequency/OS_TICKS_PER_SEC);//初始化并使能SysTick定时器
}
