#ifndef __TIMER_H__
#define __TIMER_H__

#include "OB39A08T1.h"

#define d_T0MOD 0x01    //mode`  16bit
//#define d_T0_TH0  0xA9
//#define d_T0_TL0  0x9A

#define d_T0_TH0  0xF8
#define d_T0_TL0  0xCD

#define ET2             0x00    //TIMER2 overflow Interrupt Enable (Default 0 Disable)
#define ET1             0x00    //TIMER1 overflow Interrupt Enable (Default 0 Disable)
#define ET0             0x01    //TIMER0 overflow Interrupt Enable (Default 0 Disable)

#define TIMER0_VECTOR   1       //TIMER0 Interrupt Vevtor

void TIMER0_initialize(void);
void Start_Timer0(void);


#endif