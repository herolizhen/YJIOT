#include <stdio.h>
#include "common.h"
#include "wifi_uart.h"


//unsigned int mystrlen(unsigned char *buff)
//{
//    unsigned int length = 0;
//    while((*buff++) != '\0')
//    {
//        length++;
//        if(length > 0xFF)
//        {
//            return 0xFF;
//        }
//    }
//    
//    return length;

//}

unsigned char mymemset(unsigned char *buff,unsigned char fill_data,unsigned char length)
{
    unsigned int i = 0;
    if(length > 0xFF)
    {
        return 1;
    }
    
    for(i = 0;i < length;i++)
    {
        buff[i] = fill_data;
    }
    
    return 0;
}

