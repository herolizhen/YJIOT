#include "OB39R32T1.h"
#include <absacc.h>    /* Include Macro Definitions */
#include "EEPROM.h"

/*ISPFC.ISPF[2:0]*/
#define d_Command_Byte_Program  0
#define d_Command_Page_Erase    2
#define d_EEPROM_Start_Addr     0xF5

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
        Software_Reset();
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
    return CBYTE[Addr];    //The range of valid index values for this macro is 0-255
}

