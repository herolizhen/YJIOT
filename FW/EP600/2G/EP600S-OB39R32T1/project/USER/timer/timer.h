#ifndef __TIMER_H__
#define __TIMER_H__

#include "OB39R32T1.h"

/*
#define d_T0MOD 0x02    //mode2`  8bit

//timer0当定时器为1ms时 TIMER_BASE = 1，当定时器为0.5ms时 TIMER_BASE = 2，当定时器为0.25ms时， TIMER_BASE = 4，依次类推
#define TIMER_BASE  10
*/

/*1ms*/
//#define d_T0_TH0  0xF8
//#define d_T0_TL0  0xCD

/*0.25ms*/
//#define d_T0_TH0  0xFE
//#define d_T0_TL0  0x33


/*0.1ms*/
/*16bit模式*/
//#define d_T0_TH0  0xFF
//#define d_T0_TL0  0x48
/*8bit模式*/
//#define d_T0_TH0  0x48   //1min的误差在280ms左右
//#define d_T0_TH0  0x47   //比0x48精度更高一些  1min的误差在50ms左右

/*0.05ms*/
//#define d_T0_TH0  0xFF
//#define d_T0_TL0  0xA4





//#define ET2             0x00    //TIMER2 overflow Interrupt Enable (Default 0 Disable)
//#define ET1             0x00    //TIMER1 overflow Interrupt Enable (Default 0 Disable)
//#define ET0             0x01    //TIMER0 overflow Interrupt Enable (Default 0 Disable)


/*
#define TIMER0_VECTOR   1       //TIMER0 Interrupt Vevtor

void TIMER0_initialize(void);
void Start_Timer0(void);

unsigned long get_sys_mstime(void);
unsigned long get_sys_stime(void);
*/



#define d_T1MOD 0x02    //mode2`  8bit
#define d_T1_TH1  0x47   //比0x48精度更高一些  1min的误差在50ms左右

//timer0当定时器为1ms时 TIMER_BASE = 1，当定时器为0.5ms时 TIMER_BASE = 2，当定时器为0.25ms时， TIMER_BASE = 4，依次类推
#define TIMER_BASE  10


#define TIMER1_VECTOR   1       //TIMER0 Interrupt Vevtor

void TIMER1_initialize(void);
void Start_Timer1(void);

unsigned long get_sys_mstime(void);
unsigned long get_sys_stime(void);


#endif