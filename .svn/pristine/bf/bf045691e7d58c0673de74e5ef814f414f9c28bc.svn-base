#ifndef __WIFI_UART_H__
#define __WIFI_UART_H__


#include "OB39R32T1.h"

//#define WIFI_UART_TXD_PIN  P3_0
//#define WIFI_UART_RXD_PIN  P3_1

//#define WIIF_UART_TXD_PORTBIT  0
//#define WIFI_UART_RXD_PORTBIT  1

#define WIFI_UART_TXD_PIN  P3_1
#define WIFI_UART_RXD_PIN  P3_0

#define WIIF_UART_TXD_PORTBIT  1
#define WIFI_UART_RXD_PORTBIT  0

#define WIFI_UART_PxM0    P3M0
#define WIFI_UART_PxM1    P3M1


#define WIFI_DATA_BUFF_SIZE  80

void Wifi_Uart_Init(void);
void Wifi_Uart_Sendbytes(unsigned char *sendbuff,unsigned char sendnum);
unsigned char Wifi_Uart_ReceiveOnePackage(unsigned char *receivebuff,unsigned char maxnum);

void deal_frame_data(unsigned char *framebuffer);
void Deal_Wifi_Uart_Data(void);

void f_0x41_data(void);
void f_0x44_data(void);
void f_0x45_data(unsigned char *framebuff);
void wifi_earse_easylink_cmd(void);
void f_0x49_data(unsigned char *framebuff);
void f_0x49_05_data(unsigned char *framebuff);

void user_timer_confirm(const unsigned char *framebuff);


void sys_check_auto_result_upload(void);
void sys_check_manual_result_upload(void);




#endif