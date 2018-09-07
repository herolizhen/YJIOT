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
  
   mymemset(U3RxBuffer,0,U3RxBuff_MAXSIZE);
   
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


/*
unsigned char DEBUG_Uart_ReceiveOnePackage(unsigned char *reveivebuff,unsigned char receive_num)
{
    unsigned char i = 0;
    unsigned char max_receive_num = 0;
  
    if(IsU3RxBusy)
    {
        return 0;
    }
  
    if(receive_num > U3RxBuff_MAXSIZE)
    {
        max_receive_num = U3RxBuff_MAXSIZE;
    }
    else
    {
        max_receive_num = receive_num;
    }
    
    
    while(i < U3RxPtr)
    {
        reveivebuff[i] = U3RxBuffer[i];
        i += 1;
    }
    
    mymemset(U3RxBuffer,0,i);
    U3RxPtr = 0;
    
    
    
    return i;

}
*/

