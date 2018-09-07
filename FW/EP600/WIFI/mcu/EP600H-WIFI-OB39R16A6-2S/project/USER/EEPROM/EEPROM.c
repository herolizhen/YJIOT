#include <stdio.h>
#include <string.h>
#include "OB39R32T1.h"
#include <absacc.h>    /* Include Macro Definitions */
#include "EEPROM.h"
#include "global.h"
#include "common.h"
#include "debug_uart.h"



/*ISPFC.ISPF[2:0]*/
#define d_Command_Byte_Program  0
#define d_Command_Page_Erase    2
#define d_EEPROM_Start_Addr     0x7C

//====================================================================
//#define d_DATALEN   64              // idata limit:1~128
//unsigned char idata buf[d_DATALEN]; // idata limit:1~128

void Software_Reset(void)
{
    EA    = 0;
    TAKEY = 0x55;
    TAKEY = 0xAA;
    TAKEY = 0x5A;
    SWRES = 0xFF;
}

void Check_ISPFAH(void)
{
    if (ISPFAH < d_EEPROM_Start_Addr)
        Software_Reset();
}

void EEPROM_Enable(void)
{
    EA     = 0;
    TAKEY  = 0x55;
    TAKEY  = 0xAA;
    TAKEY  = 0x5A;
    IFCON |= 0x01;    // ISPE=1, Enable ISP function
    EA     = 1;
}

void EEPROM_Disable(void)
{
    EA     = 0;
    TAKEY  = 0x55;
    TAKEY  = 0xAA;
    TAKEY  = 0x5A;
    IFCON &= 0xFE;    // ISPE=0, Disable  ISP function
    EA     = 1;
}

void EEPROM_Byte_Program(unsigned int Addr, unsigned char Data)
{
    EEPROM_Enable();
    ISPFD  = Data;
    ISPFAH = (Addr/256);
    ISPFAL = (Addr%256);
    if (ISPFAH >= d_EEPROM_Start_Addr)
        ISPFC = d_Command_Byte_Program;
    else
        //Software_Reset();
        goto exit;
    
exit:
    EEPROM_Disable();
}

void EEPROM_Page_Erase(unsigned int Addr)    //erase 1K byte
{
    EEPROM_Enable();
    ISPFAH = (Addr/256);
    ISPFAL = (Addr%256);
    if (ISPFAH >= d_EEPROM_Start_Addr)
        ISPFC = d_Command_Page_Erase;
    else
        //Software_Reset();
        goto exit;
    
exit:
    EEPROM_Disable();
}

void EEPROM_Sector_Program(unsigned int Addr_start, unsigned int Addr_end, unsigned char Data)
{
    unsigned int i;
    for (i = Addr_start; i <= Addr_end; i++)
    {
        EEPROM_Byte_Program(i, Data);
    }
}

unsigned char EEPROM_Byte_Read(unsigned int Addr)
{
    return CBYTE[Addr];    //The range of valid index values for this macro is 0-255
}


void EEPROM_Read_Bytes(unsigned char *buff,unsigned int Addr,unsigned char length)
{
    unsigned char i = 0;
    if(buff == NULL)
    {
        return;
    }
    
    if(Addr < EEPROM_START_ADDR || Addr > EEPROM_END_ADDR)
    {
        return;
    }
    
//    mymemset(m26_cmd_info.sendtring,0,sizeof(m26_cmd_info.sendtring));
//    sprintf(m26_cmd_info.sendtring,"EEPROM_Read_Bytes step0\r\n");
//    DEBUG_Uart_Sendbytes(m26_cmd_info.sendtring,strlen(m26_cmd_info.sendtring));
    
    for(i = 0;i < length;i ++)
    {
        buff[i] = EEPROM_Byte_Read(Addr + i);
    }
}


void EEPROM_Write_Bytes(unsigned char *buff,unsigned int Addr,unsigned char length)
{
    unsigned char i = 0;
    unsigned int eeprom_addr = 0;
    if(buff == NULL)
    {
//        mymemset(m26_cmd_info.sendtring,0,sizeof(m26_cmd_info.sendtring));
//        sprintf(m26_cmd_info.sendtring,"EEPROM_Write_Bytes step0\r\n");
//        DEBUG_Uart_Sendbytes(m26_cmd_info.sendtring,strlen(m26_cmd_info.sendtring));
        return;
    }
    
    if(Addr < EEPROM_START_ADDR || Addr > EEPROM_END_ADDR)
    {
//        mymemset(m26_cmd_info.sendtring,0,sizeof(m26_cmd_info.sendtring));
//        sprintf(m26_cmd_info.sendtring,"EEPROM_Write_Bytes step2\r\n");
//        DEBUG_Uart_Sendbytes(m26_cmd_info.sendtring,strlen(m26_cmd_info.sendtring));
        return;
    }
    
//    mymemset(m26_cmd_info.sendtring,0,sizeof(m26_cmd_info.sendtring));
//    sprintf(m26_cmd_info.sendtring,"write addr:%x,length:%d\r\n",(unsigned int)Addr,(unsigned int)length);
//    DEBUG_Uart_Sendbytes(m26_cmd_info.sendtring,strlen(m26_cmd_info.sendtring));
    
    eeprom_addr = Addr;
    
    for(i = 0;i < length;i++)
    {
        EEPROM_Byte_Program((eeprom_addr + i),buff[i]);
    }
}



