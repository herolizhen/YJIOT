#ifndef __USART_H__
#define __USART_H__

#include "stm32f0xx.h"

void Usart_SendOneByte( USART_TypeDef * pUSARTx, uint8_t ch);
uint8_t Usart_SendBytes(USART_TypeDef * pUSARTx, const uint8_t *buff, uint16_t length);




#endif
