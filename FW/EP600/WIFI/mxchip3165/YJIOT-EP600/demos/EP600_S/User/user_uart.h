/**
******************************************************************************
* @file    uart.h 
* @author  herolizhen
* @version V1.0.0
* @date    17-Mar-2016
* @brief   This header contains the uart interfaces for user. 
  operation
******************************************************************************
*/ 


#ifndef __USER_UART_H_
#define __USER_UART_H_

#include <stdio.h>
#include "mico.h"
#include "MICOAppDefine.h"
#include "user_modbus.h"

#define USER_UART_RECV_TIMEOUT              500
#define USER_UART_ONE_PACKAGE_LENGTH        256
#define USER_UART_BUFFER_LENGTH             256   
#define STACK_SIZE_USART_RECV_THREAD        0x500

#define user_uart_log(M, ...) custom_log("USER_UART", M, ##__VA_ARGS__)
#define user_uart_log_trace() custom_log_trace("USER_UART")

/*******************************************************************************
 * INTERFACES
 ******************************************************************************/

OSStatus user_uart_init(void);
OSStatus user_uart_send(unsigned char *inBuf, unsigned int inBufLen);
uint32_t user_uart_recv(unsigned char *outBuf, unsigned int getLen);
void    uart_recv_thread(mico_thread_arg_t arg);
#endif  // __USER_UART_H_
