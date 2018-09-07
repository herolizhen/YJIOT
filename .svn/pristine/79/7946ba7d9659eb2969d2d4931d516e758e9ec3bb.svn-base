#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sensor_uart.h"


#include "OB39R32T1.h"
//#include "UART0.h"
#include "global.h"
#include "TM1620.h"
//#include "common.h"
#include "debug_uart.h"

//===============================================================
//DEFINITIONs
//===============================================================
#define d_S1RELH  0x03
#define d_S1RELL  0xB8

//===============================================================
//GLOBAL VARIABLE
//===============================================================
bit bU1TX = 0;


//=========================================================================
void init_UART1(void)
{
    S1RELH  = d_S1RELH;
    S1RELL  = d_S1RELL;
    IEN0   |= 0x80;        // EA =1
    IEN2   |= 0x01;        // ES1 =1, interrupt enable
    S1CON   = 0xB0;        // d_mode_B, S1M2 =1, REN1 =1
}


bit is_sensor_uart_get_data = 0;
void UART1_ISR(void) interrupt d_UART1_Vector
{
    //static unsigned char i = 0;
  
    //unsigned char debug_buff[40] = {0};
  
    static unsigned int frame_length = 0;

    if (S1CON & 0x01)                     // INT_RX
    {
        S1CON  &= 0xFE;                // RI clear
        if(U1RxPtr < SENSOR_MAX_BUFF_LENGTH)
        {
            U1RxBuffer[U1RxPtr] = S1BUF;         // Read BUF           
            U1RxPtr += 1;
                     
            if(U1RxPtr == 1)
            {
                frame_length = 0; 
                if(U1RxBuffer[0] != 0x42)
                {
//                    memset(debug_buff,0,sizeof(debug_buff));
//                    sprintf(debug_buff,"buff[0] = 0x%x\r\n",(unsigned int)U1RxBuffer[0]);
//                    DEBUG_Uart_Sendbytes(debug_buff,strlen(debug_buff)); 
                  
                    goto error_exit;
                }
            }
            else if(U1RxPtr == 2)
            {
                if(U1RxBuffer[1] != 0x4D)
                {
                    goto error_exit;
                }
            }
            else if(U1RxPtr >= 4)
            {
                if(U1RxPtr == 4)
                {
                    frame_length = (((unsigned int)U1RxBuffer[2] << 8) | U1RxBuffer[3]) + 4;  
                  
//                    mymemset(debug_buff,0,sizeof(debug_buff));
//                    //sprintf(debug_buff,"frame length:%d\r\n",(unsigned int)frame_length);
//                    sprintf(debug_buff,"frame length:\r\n");
//                    DEBUG_Uart_Sendbytes(debug_buff,mystrlen(debug_buff));                   
                }
                
                if(frame_length > SENSOR_DATA_MAX_LENGTH)
                {
                    goto error_exit;
                }
              
                if(U1RxPtr == frame_length)
                {                   
                    is_sensor_uart_get_data = 1;                 
                }
                
            }            
        }
        else
        {
            clear_sensor_uart_buff();
        }
        
    }
    else                        // INT_TX
    {
        bU1TX  = 0;
        S1CON &= 0xFD;     // TI clear
    }
    
    return;
    
    
error_exit:
    
    clear_sensor_uart_buff();
    
    
}

void UART1_TX(unsigned char n_temp1)
{
    bU1TX = 1;
    S1BUF = n_temp1;
    while(bU1TX)
    {
        ;
    }
}



void clear_sensor_uart_buff(void)
{
    //unsigned char i = 0;
    
    memset(U1RxBuffer,0,U1RxPtr);
  
    U1RxPtr = 0;
  
}



void Sensor_Uart_Sendbytes(const unsigned char *sendbuff,unsigned char sendnum)
{
    unsigned char i = 0;
    
    for(i = 0;i < sendnum;i++)
    {
        UART1_TX(sendbuff[i]);
    }
}



