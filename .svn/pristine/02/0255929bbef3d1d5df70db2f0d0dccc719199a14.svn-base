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

unsigned char which_key_blink = 0;
unsigned char which_key_blink_off = 0;
void TIMER0_ISR(void) interrupt TIMER0_VECTOR
{
    // To do something by using timer interrupt.
    static unsigned char idata times1ms = 1;
    static unsigned char idata times2ms = 2;
    static unsigned char idata times10ms = 10;
    static unsigned int idata times1000ms = 1000;
  
    static unsigned char idata led_control_times_1ms = 0;
    //static unsigned char idata which_key_blink_off = 0;
  
    //static unsigned long test = 0;
  
    if(--times1ms == 0)
    {
        g_1ms_flag = 1;
        times1ms = 1;
      
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
                which_key_blink_off = which_key_blink;
            }
            else if(led_blink_info.ledcount_1ms_times == LED_ON_TIMES)
            {
                led_blink_info.ledstate = LED_ON;
                led_blink_info.ledcount_1ms_times = 0;
                which_key_blink_off = KEY_NONE;
                led_blink_info.blinktimes++;
            }      
        }
        else
        {
            if(which_key_blink != KEY_NONE)
            {
                which_key_blink = KEY_NONE;
            }
        
            if(which_key_blink_off != KEY_NONE)
            {
                which_key_blink_off = KEY_NONE;
            }        
        } 
    
        if(led_control_times_1ms < 3)
        {
            led_control_times_1ms += 1;  
        }
        else 
        {
            led_control_times_1ms = 0;
        }
    
        if(led_control_times_1ms == 1)
        {
        
            LED_POWER_PIN = 0;
            LED_TIMER_PIN = 0;         
        }
        else 
        {       
            if(led_control_times_1ms == 2)
            {
                if(which_key_blink_off != KEY_POWER)
                {
                    LED_POWER_PIN = 1;
                }
            
                if(which_key_blink_off != KEY_TIMER)
                {
                    LED_TIMER_PIN = 1;
                }
           
                LED_SPEED_PIN = 0;
                LED_MODE_PIN = 0;
            }
            else if(led_control_times_1ms == 3)
            {
                if(which_key_blink_off != KEY_SPEED)
                {
                    LED_SPEED_PIN = 1;
                }
            
                if(which_key_blink_off != KEY_MODE)
                {
                    LED_MODE_PIN = 1;
                }
                led_control_times_1ms = 0;         
            }
        }          
      
    }

  
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

   

    TH0   = d_T0_TH0;  //MODE1 16bit
    TL0   = d_T0_TL0;
    TR0 = 1;
    
}