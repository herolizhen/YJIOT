#include "stdio.h"
#include "usart.h"


void Usart_SendOneByte( USART_TypeDef * pUSARTx, uint8_t ch) 
{
    USART_SendData(pUSARTx,ch); 
    while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET); 
}


uint8_t Usart_SendBytes(USART_TypeDef * pUSARTx, const uint8_t *buff, uint16_t length)
{
    if(pUSARTx == NULL || buff == NULL || length == 0)
    {
        return -1;
    }
    
    while(length--)
    {
        Usart_SendOneByte(pUSARTx,*buff++);
    }
    
    return 0;
}