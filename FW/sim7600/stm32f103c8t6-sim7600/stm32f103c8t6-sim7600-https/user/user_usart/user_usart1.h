#ifndef __USER_USART1_H__
#define __USER_USART1_H__

#include "stdio.h"
#include "stm32f10x_usart.h"

void usart1_config(USART_TypeDef* USARTx, uint32_t BaudRate);

int fputc(int ch, FILE *f);
int fgetc(FILE *f);

#endif

