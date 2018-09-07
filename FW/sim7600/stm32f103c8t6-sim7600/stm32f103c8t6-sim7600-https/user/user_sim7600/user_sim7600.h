#ifndef __USER_L506_H__
#define __USER_L506_H__

#include "stdint.h"


#define UART_L506_RX_BUFF_SIZE   512




void uart_L506_task(void *para);

uint8_t uart_L506_sendbytes(const uint8_t *buff,uint16_t length);





#endif
