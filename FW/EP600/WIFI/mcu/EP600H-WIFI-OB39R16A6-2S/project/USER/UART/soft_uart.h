#ifndef __SOFT_UART_H__
#define __SOFT_UART_H__

#include "OB39R32T1.h"
#include "wifi_uart.h"

/*
#define U2TxPin  WIFI_UART_TXD_PIN
#define U2RxPin  WIFI_UART_RXD_PIN

#define U3TxPin  DEBUG_UART_TXD_PIN
#define U3RxPin  DEBUG_UART_RXD_PIN

enum BAUDRATA_NUM{

  baudrate_9600      = 0,
  baudrate_19200     = 1,
};


void Timer1_Init(void);
void Soft_I2C_Init(void);
*/



#define U2TxPin  WIFI_UART_TXD_PIN
#define U2RxPin  WIFI_UART_RXD_PIN

#define U3TxPin  DEBUG_UART_TXD_PIN
#define U3RxPin  DEBUG_UART_RXD_PIN

enum BAUDRATA_NUM{

  baudrate_9600      = 0,
  baudrate_19200     = 1,
};


void Timer0_Init(void);
void Soft_UART_Init(void);




#endif