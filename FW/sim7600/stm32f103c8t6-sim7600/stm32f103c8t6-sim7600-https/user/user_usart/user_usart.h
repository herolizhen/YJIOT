#ifndef __USER_USART_H__
#define __USER_USART_H__

#include "stm32f10x_usart.h"

void Usart_SendOneByte( USART_TypeDef * pUSARTx, uint8_t ch) ;

uint8_t Usart_SendBytes( USART_TypeDef * pUSARTx,const uint8_t *buff,uint8_t length); 

#endif  
