#include "timer.h"
#include "global.h"
#include "led.h"
#include "touch.h"
/*
//时钟周期 22.1184MHz
1秒的机器周期为 22118400
1ms的需要的机器周期为 22118.4

22118.4/12 = 1843.2(0x0733)

65536 - 22118 = 43418（0xA99A）

65536 - 1843 = 43418（0xF8CD）



*/


extern KEY_INFO_Typedef key_info;

extern LED_BLINK_Typedef led_blink_info;



void TIMER0_initialize(void)  //Initialize TIMER0
{
    IEN0 |= (ET2<<5)|(ET1<<3)|(ET0<<1); //IE=IEN0
    TMOD  = d_T0MOD;
    TH0   = d_T0_TH0;  //MODE1 16bit
    TL0   = d_T0_TL0;
}


void Start_Timer0(void)
{
    TIMER0_initialize();
    
    EA   = 1;
    TR0  = 1;
}


void TIMER0_ISR(void) interrupt TIMER0_VECTOR
{
    // To do something by using timer interrupt.
    static unsigned char times2ms = 2;
    static unsigned char times10ms = 10;
    static unsigned int times1000ms = 1000;
  
    if(--times2ms == 0)
    {
        g_2ms_flag = 1;
        times2ms = 2;
    }
  
    if(--times10ms == 0)
    {
        g_10ms_flag = 1;
        times10ms = 10;
    }
    
    if(--times1000ms == 0)
    {
        g_1000ms_flag = 1;
        times1000ms = 1000;
    }  

    if(key_info.IsCount == 1)
    {
        key_info.count_1ms_times++;
    } 

    if(led_blink_info.IsLedBlink == 1)
    {
        led_blink_info.ledcount_1ms_times++;
        if(led_blink_info.ledcount_1ms_times == LED_OFF_TIMES)
        {
            led_blink_info.ledstate = LED_OFF;
        }
        else if(led_blink_info.ledcount_1ms_times == LED_ON_TIMES)
        {
            led_blink_info.ledstate = LED_ON;
        }
        else
        {
            led_blink_info.ledstate = LED_NONE;
        }
    }      

    TH0   = d_T0_TH0;  //MODE1 16bit
    TL0   = d_T0_TL0;
    TR0 = 1;
    
}