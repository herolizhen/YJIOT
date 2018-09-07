/*--------------------------------------------------------------------------
global.H

extern global resource for C51.
--------------------------------------------------------------------------*/
#ifndef		_GLOBAL_H
#define		_GLOBAL_H


/*------------------------------------------------------------------------------------------
;								datastruct.c
;-----------------------------------------------------------------------------------------*/

//----------------------------计沮挡篶--------------------------------------------------------
typedef	unsigned char	Byte;
typedef	unsigned int	Word;
typedef	unsigned long	Dword;
//////////////////////////////////////////////////////////
typedef unsigned char BYTE;
typedef unsigned int  WORD;
typedef unsigned long DWORD;

typedef unsigned char uchar;
typedef unsigned int  uint;
typedef unsigned long ulong;

typedef unsigned char u8;
typedef unsigned char U8;
typedef unsigned int u16;
typedef unsigned int  U16;

#define	uCHAR	unsigned char
#define	sCHAR	signed   char
#define	uINT	unsigned short
#define	sINT	signed   short
#define	uLONG	unsigned long
#define	sLONG	signed long
#define	npage	xdata
#define	zpage	data
////////////////////////////////////////////////////



#define ON        1
#define OFF       0
#define NULL      0
#define null      0

#define bit0      0
#define bit1      1
#define bit2      2
#define bit3      3
#define bit4      4
#define bit5      5
#define bit6      6
#define bit7      7

#define GPIO_OUTPUT_MODE      1
#define GPIO_INPUT_MODE       0
#define GPIO_PULL_LOW         1
#define GPIO_PULL_HIGH        0
/////////////////////////////////////////////
#define SetBit(var, bit_no)     {var |= (1 << bit_no);}
#define ClrBit(var, bit_no)     {var &= ~(1 << bit_no);}
#define GetBit(var, bit_def)    ((var&(1 << bit_def))?1:0)
#define DefineBit(var, bitno)   (((tpBIT *)&var)->bitno)


// 每分钟的转速 
//#define FAN_SPEED1	(480)
//#define FAN_SPEED2	(750)
//#define FAN_SPEED3	(1000)
//#define FAN_SPEED4	(1350)
//UV灯电流检测 
#define CURRENT_LOW_threshold	   2500  //2.5V为电流限值 
#define ERROR_NUMBER_FILT          50//1.5S保护动作 
#define ERROR_NUMBER_UP            50//1.5S保护动作 
//#define ERROR_NUMBER_UV        	   200 //6S保护动作 
#define ERROR_NUMBER_UV        	   250 //6S保护动作 2014年5月13下午改
#define ERROR_NUMBER_DOOR          200 //6S保护动作 

#define _test_timeflag(x)    ((x == 1)?1:0) 

extern bit g_1ms_flag;
extern bit g_2ms_flag;
extern bit g_10ms_flag;
extern bit g_100ms_flag;
//extern volatile unsigned char g_1000ms_flag;
extern bit g_1000ms_flag;


extern unsigned char which_key_blink;




#endif
