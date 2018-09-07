#ifndef __USER_L506_TASK_H__
#define __USER_L506_TASK_H__


#include "stm32f10x.h"

#define UART_L506_RX_BUFF_SIZE   512


uint8_t L506_USART_RB_Initialize(void);
void L506_usart_begin(void);
uint8_t L506_usart_recv_available(void);
uint8_t L506_usart_read(void);


uint8_t L506_usart_sendbytes(uint8_t *buff,uint8_t length);

uint8_t L506_usart_recv_handler(void);

void L506_task(void *p_arg);


uint8_t uart_L506_sendbytes(const uint8_t *buff,uint16_t length);


#endif
