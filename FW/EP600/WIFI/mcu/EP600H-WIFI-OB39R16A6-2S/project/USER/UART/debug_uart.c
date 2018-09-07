#include "debug_uart.h"
#include "global.h"



void DEBUG_Uart_Init(void)
{

   DEBUG_UART_PxM0 &= ~(1 << DEBUG_UART_TXD_PORTBIT);
   DEBUG_UART_PxM1 &= ~(1 << DEBUG_UART_TXD_PORTBIT); 
  
   DEBUG_UART_PxM0 &= ~(1 << DEBUG_UART_RXD_PORTBIT);
   DEBUG_UART_PxM1 &= ~(1 << DEBUG_UART_RXD_PORTBIT); 
  
   DEBUG_UART_TXD_PIN = 1;
   DEBUG_UART_RXD_PIN = 1;

#ifdef DEBUG_UART_RX  
   mymemset(U3RxBuffer,0,U3RxBuff_MAXSIZE);
#endif   
}

void DEBUG_Uart_Sendbytes(unsigned char *sendbuff,unsigned char sendnum)
{
    unsigned char i = 0;
  
    if(sendnum + U3LdPtr > U3TxBuff_MAXSIZE)
    {
        return;
    }
    for(i = 0;i < sendnum;i++)
    {
        U3TxBuffer[i + U3LdPtr] = sendbuff[i];
    }
    U3LdPtr += sendnum;
    if(IsU3TxBusy == 0)
    {
        U3TxBitCount = 10;
        U3TxRate = 3;
    }

}



