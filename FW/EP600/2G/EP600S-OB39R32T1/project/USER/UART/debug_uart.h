#ifndef __DEBUG_UART_H__
#define __DEBUG_UART_H__

#include "OB39R32T1.h"

//OB39R16A6
//#define DEBUG_UART_TXD_PIN  P1_6
//#define DEBUG_UART_RXD_PIN  P1_7

//#define DEBUG_UART_TXD_PORTBIT  6
//#define DEBUG_UART_RXD_PORTBIT  7

//#define DEBUG_UART_PxM0    P1M0
//#define DEBUG_UART_PxM1    P1M1


//OB39R32T1
#define DEBUG_UART_TXD_PIN  P0_4
#define DEBUG_UART_RXD_PIN  P0_3

#define DEBUG_UART_TXD_PORTBIT  4
#define DEBUG_UART_RXD_PORTBIT  3

#define DEBUG_UART_PxM0    P0M0
#define DEBUG_UART_PxM1    P0M1

void DEBUG_Uart_Init(void);
void DEBUG_Uart_Sendbytes(unsigned char *sendbuff,unsigned char sendnum);
//unsigned char DEBUG_Uart_ReceiveOnePackage(unsigned char *reveivebuff,unsigned char receive_num);





#endif