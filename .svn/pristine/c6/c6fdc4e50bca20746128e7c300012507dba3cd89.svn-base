#include "misc.h"
#include "stm32f10x.h"
#include "stm32f10x_usart.h"
#include "stm32f10x_gpio.h"
#include "stdio.h"
#include "user_usart2.h"

/// 配置USART接收中断
static void NVIC_Configuration(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;
    /* Configure the NVIC Preemption Priority Bits */
    //NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);

    /* Enable the USARTy Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn; 
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

//串口配置函数，目前只适配串口1
void usart2_config(USART_TypeDef* USARTx, uint32_t BaudRate)
{
	USART_InitTypeDef	USART_InitStructure;
	GPIO_InitTypeDef	GPIO_InitStructure;
	
	//开启串口1和GPIOA的时钟  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE); 
	
	//PA2(TX),PA3(RX)引脚配置
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	
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



