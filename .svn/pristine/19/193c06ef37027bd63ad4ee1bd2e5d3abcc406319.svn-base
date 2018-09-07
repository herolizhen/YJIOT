#include "OB39R16A6.h"
#include <absacc.h>    /* Include Macro Definitions */
#include "EEPROM.h"

/*ISPFC.ISPF[2:0]*/
#define d_Command_Byte_Program  0
#define d_Command_Page_Erase    2
#define d_EEPROM_Start_Addr     0x3D

//====================================================================
#define d_DATALEN   64              // idata limit:1~128
unsigned char idata buf[d_DATALEN]; // idata limit:1~128

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
    if(ISPFAH<d_EEPROM_Start_Addr)
        Software_Reset();
}

void EEPROM_Enable(void)
{
    EA     = 0;
    TAKEY  = 0x55;
    TAKEY  = 0xAA;
    TAKEY  = 0x5A;
    IFCON |= 0x01;      // ISPE=1, Enable ISP function
    EA     = 1;
}

void EEPROM_Disable(void)
{
    EA     = 0;
    TAKEY  = 0x55;
    TAKEY  = 0xAA;
    TAKEY  = 0x5A;
    IFCON &= 0xFE;      // ISPE=0, Disable  ISP function
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
        Software_Reset();
    EEPROM_Disable();
}

void EEPROM_Page_Erase(unsigned int Addr)       // erase 128-Byte
{
    EEPROM_Enable();
    ISPFAH = (Addr/256);
    ISPFAL = (Addr%256);
    if (ISPFAH >= d_EEPROM_Start_Addr)
        ISPFC = d_Command_Page_Erase; 
    else
        Software_Reset();
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
//    unsigned char res = 0;
//    EEPROM_Enable();
//    res = CBYTE[Addr];
//    EEPROM_Disable();
//    return res;
  
    return CBYTE[Addr];         //The range of valid index values for this macro is 0-255
}

/*unsigned int EEPROM_Word_Read(unsigned int Addr)
{
    return CWORD[Addr];         //The range of valid index values for this macro is 0-65535
}*/

void EEPROM_Byte_Modify(unsigned int Addr, unsigned char Data)
    {
    unsigned char i;
    
    for (i = 0; i < d_DATALEN; i++)
        buf[i] = EEPROM_Byte_Read((Addr&0xFF00)+i);     // page read

    EEPROM_Page_Erase(Addr);                            // erase page 
    
    buf[(unsigned char)Addr] = Data;                    // byte modify

    for (i = 0; i < d_DATALEN; i++)
        EEPROM_Byte_Program((Addr&0xFF00)+i, buf[i]);   // page program
}
