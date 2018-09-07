
#include "stm32f0xx.h"
#include "stdio.h"

//串口配置函数，目前只适配串口1
void usart_config(USART_TypeDef* USARTx, uint32_t BaudRate)
{
	USART_InitTypeDef	USART_InitStructure;
	GPIO_InitTypeDef	GPIO_InitStructure;
	
	//开启串口1和GPIOA的时钟
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	
	//PA9(TX),PA10(RX)引脚配置
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//打开引脚和串口1和连接
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_1);
	
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
  
	
	USART_Cmd(USARTx, ENABLE);	//启用串口
}


//重定义fputc函数发送到串口1
int fputc(int ch, FILE *f)
{
	USART_SendData(USART1, (uint8_t) ch);

	/* 等待发送结束 */
	while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)
	{}

	return ch;
}


int fgetc(FILE *f)
{
	/* 等待串口1输入数据 */
	while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);

	return (int)USART_ReceiveData(USART1);
}

