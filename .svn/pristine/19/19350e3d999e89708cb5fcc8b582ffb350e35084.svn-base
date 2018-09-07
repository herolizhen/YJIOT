#ifndef __BUZZER_H__
#define __BUZZER_H__

#include "OB39R32T1.h"

//wifi board
//#define BUZZER_P_PIN   P0_5
//#define BUZZER_N_PIN   P0_4

//m26 board
#define BUZZER_P_PIN   P1_6
#define BUZZER_N_PIN   P1_7

#define BUZZER_PWM_NUM   4

/*
0.1ms的定时器，对应的蜂鸣频率最高到 (1/(0.1*2))*1000 = 5000hz

0.05ms的定时器，对应的蜂鸣频率最高到 (1/(0.05*2))*1000 = 10000hz

*/
#define     tone_multi (2*2*2)
//#define     tone_multi (2*2)
//#define     tone_multi (2)
#define     tone_do (262 * tone_multi)
#define     tone_ri (294 * tone_multi)
#define     tone_mi (330 * tone_multi)
//#define     tone_fa (349 * tone_multi)
#define     tone_so (392 * tone_multi)


void Buzzer_PinConfig(void);
void BuzzerBeep(unsigned int timeMs,unsigned int frequency);
//void BuzzerOff(void);

void Buzzer_Power_On(void);
void Buzzer_Power_Off(void);
void Buzzer_Speed(void);
void Buzzer_Get_Charge(void);

void Buzzer_Signal_Check(void);



#endif