#include <stdio.h>
#include "buzzer.h"
#include "PWM.h"
#include "timer.h"
#include "global.h"
//#include "common.h"
#include "debug_uart.h"

/*
0.1ms的定时器，对应的蜂鸣频率最高到 (1/(0.1*2))*1000 = 5000hz

0.05ms的定时器，对应的蜂鸣频率最高到 (1/(0.05*2))*1000 = 10000hz

*/


//unsigned char buzzer_buff[30] = {0};


void Buzzer_PinConfig(void)
{
//    P0M0 &= ~(1 << 5);
//    P0M1 &= ~(1 << 5);  
  
      P1M0 &= ~(1 << 6);
      P1M1 &= ~(1 << 6);  
    
    BUZZER_P_PIN = 0;

}

void BuzzerBeep(unsigned int timeMs,unsigned int frequency)
{  
    gBuzzerTimes_cnt = timeMs * TIMER_BASE;
    gBuzzerEdge_cnt = (TIMER_BASE * 1000 / 2)  / frequency;
    BUZZER_P_PIN = 1;


}

/*
void BuzzerOff(void)
{
    BUZZER_P_PIN = 0;
    gBuzzerTimes_cnt = 0;
    gBuzzerEdge_cnt = 0;
}
*/

void Buzzer_Power_On(void)
{
//    mymemset(buzzer_buff,0,mystrlen(buzzer_buff));
//    sprintf(buzzer_buff,"Buzzer_Power_On\n");
//    DEBUG_Uart_Sendbytes(buzzer_buff,mystrlen(buzzer_buff));
  
    BuzzerBeep(210,tone_mi);
    while(gBuzzerTimes_cnt) ;
    BuzzerBeep(210,tone_ri);
    while(gBuzzerTimes_cnt) ;
    BuzzerBeep(205,tone_do);
//    while(gBuzzerTimes_cnt) ;
//    BuzzerBeep(100,tone_so);
}


void Buzzer_Power_Off(void)
{
  
//    mymemset(buzzer_buff,0,mystrlen(buzzer_buff));
//    sprintf(buzzer_buff,"Buzzer_Power_Off\n");
//    DEBUG_Uart_Sendbytes(buzzer_buff,mystrlen(buzzer_buff));
  
    BuzzerBeep(210,tone_do);
    while(gBuzzerTimes_cnt) ;
    BuzzerBeep(210,tone_mi);
    while(gBuzzerTimes_cnt) ;
    BuzzerBeep(205,tone_so);
}

void Buzzer_Speed(void)
{
  
//    mymemset(buzzer_buff,0,mystrlen(buzzer_buff));
//    sprintf(buzzer_buff,"Buzzer_Speed\n");
//    DEBUG_Uart_Sendbytes(buzzer_buff,mystrlen(buzzer_buff));
  
    BuzzerBeep(205,tone_mi);
    while(gBuzzerTimes_cnt) ;
    BuzzerBeep(205,tone_do);
}

//WIFI获取到付费筹码后响一声
void Buzzer_Get_Charge(void)
{
    BuzzerBeep(210,tone_do);
    while(gBuzzerTimes_cnt) ;
    BuzzerBeep(210,tone_ri);
}

void Buzzer_Touch_Key(void)
{
    BuzzerBeep(210,tone_do);
    while(gBuzzerTimes_cnt) ;
    BuzzerBeep(210,tone_do);
}

