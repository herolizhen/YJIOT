#include "stm32f0xx_misc.h"
#include "stm32f0xx.h"
#include "stdio.h"
#include "usart2.h"

/// 配置USART接收中断
static void NVIC_Configuration(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;
    /* Configure the NVIC Preemption Priority Bits */
    //NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);

    /* Enable the USARTy Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn; 
    NVIC_InitStructure.NVIC_IRQChannelPriority =2;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}


void usart2_config(USART_TypeDef* USARTx, uint32_t BaudRate)
{
	USART_InitTypeDef	USART_InitStructure;
	GPIO_InitTypeDef	GPIO_InitStructure;
	
	//开启串口1和GPIOA的时钟
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	
	//PA2(TX),PA3(RX)引脚配置
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//打开引脚和串口1和连接
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_1);
	
	//清除串口配置
	USART_DeInit(USARTx);
	
	//配置串口
	USART_InitStructure.USART_BaudRate = BaudRate;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;		//8个数据位
	USART_InitStructure.USART_StopBits = USART_StopBits_1;			//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;				//无奇偶校验
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//开启接收和发送
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;	//无硬件流控制	
	USART_Init(USARTx, &USART_InitStructure);	//初始化串口
  
  //USART_ITConfig(USARTx, USART_IT_RXNE, ENABLE); 
	
	USART_Cmd(USARTx, ENABLE);	//启用串口
  
  NVIC_Configuration();
  
  USART_ITConfig(USARTx, USART_IT_RXNE, ENABLE); 
}



