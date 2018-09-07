/*--------------------------------------------------------------------------
Header file for EEPROM.
Modify on 2015/10/26.
--------------------------------------------------------------------------*/

#ifndef __EEPROM_H__
#define __EEPROM_H__

#define EEPROM_START_ADDR 0x7C00
#define EEPROM_END_ADDR (0x7C7C)   //125bytes

//#define EEPROM_END_ADDR (0x7C7F)

void          EEPROM_Enable(void);
void          EEPROM_Disable(void);
void          EEPROM_Byte_Program(unsigned int Addr, unsigned char Data);
void          EEPROM_Page_Erase(unsigned int Addr);    //128-Byte
void          EEPROM_Sector_Program(unsigned int Addr_start, unsigned int Addr_end, unsigned char Data);
unsigned char EEPROM_Byte_Read(unsigned int Addr);
void          Check_ISPFAH(void);
void          EEPROM_Read_Bytes(unsigned char *buff,unsigned int Addr,unsigned char length);
void          EEPROM_Write_Bytes(unsigned char *buff,unsigned int Addr,unsigned char length);


void EEPROM_Init(void);
void EEPROM_Test(void);
#endif
