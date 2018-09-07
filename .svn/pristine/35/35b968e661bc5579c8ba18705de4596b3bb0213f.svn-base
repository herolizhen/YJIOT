#include <stdio.h>
#include <string.h>
#include "OB39R32T1.h"
#include "LVI_LVR.h"
#include "debug_uart.h"
#include "EEPROM.h"
#include "M26.h"
#include "charge.h"

extern M26_Cmd_Typedef m26_cmd_info;

#define d_LVI_EN    0x01
#define d_LVR_EN    0x00

void LVI_EN(void)
{
    //LVC   |= 0x80;   //1.65V
    //LVC   |= 0x81;   //2.6V
    //LVC   |= 0x82;   //3.2V
    LVC   |= 0x83;   //4V
    IELVI  = 1;
    EA     = 1;
}

void LVR_Disable(void)
{
    LVC &= 0xDF;
}

void LVI(void) interrupt d_LVI_Vector
{ 
    //unsigned char readbuff[5] = 0;
    if(charge_info.IsChargeType == 0 || charge_info.lefttime.l_time == 0)
    {
        return;
    }
    else
    {
        //避免因电源有问题，频繁的操作flash
        if(g_1s_times > 60)
        {            
            charge_lefttime_flash_write();
          
            mymemset(m26_cmd_info.sendtring,0,sizeof(m26_cmd_info.sendtring));
            sprintf(m26_cmd_info.sendtring,"power off,flash save\r\n");
            DEBUG_Uart_Sendbytes(m26_cmd_info.sendtring,mystrlen(m26_cmd_info.sendtring));
        }
        
    }
    
//    mymemset(m26_cmd_info.sendtring,0,sizeof(m26_cmd_info.sendtring));
//    sprintf(m26_cmd_info.sendtring,"power off,flash save\r\n");
//    DEBUG_Uart_Sendbytes(m26_cmd_info.sendtring,mystrlen(m26_cmd_info.sendtring));
    
    
    

    
//    mymemset(readbuff,0,sizeof(readbuff));
//    EEPROM_Read_Bytes(readbuff,(unsigned int)(charge_info.eeprom_next_write_addr-5),5);
//    mymemset(m26_cmd_info.sendtring,0,sizeof(m26_cmd_info.sendtring));
//    sprintf(m26_cmd_info.sendtring,"read data:%x %x %x %x %x\r\n",(unsigned int)readbuff[0],(unsigned int)readbuff[1],
//             (unsigned int)readbuff[2],(unsigned int)readbuff[3],(unsigned int)readbuff[4]);
//    DEBUG_Uart_Sendbytes(m26_cmd_info.sendtring,strlen(m26_cmd_info.sendtring));
}
