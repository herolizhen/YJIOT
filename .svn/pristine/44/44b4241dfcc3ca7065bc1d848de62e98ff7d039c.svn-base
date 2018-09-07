#ifndef __USER_SIM7600_TASK_H__
#define __USER_SIM7600_TASK_H__


#include "stm32f10x.h"



#define UART_SIM7600_RX_BUFF_SIZE   512


uint8_t sim7600_usart_rb_initialize(void);
void sim7600_usart_begin(void);
uint8_t sim7600_usart_recv_available(void);
uint8_t sim7600_usart_read(void);


uint8_t sim7600_usart_sendbytes(uint8_t *buff,uint8_t length);

uint8_t sim7600_usart_recv_handler(void);

void sim7600_task(void *p_arg);


uint8_t uart_sim7600_sendbytes(const uint8_t *buff,uint16_t length);


#endif
