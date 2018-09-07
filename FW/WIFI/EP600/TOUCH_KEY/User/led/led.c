#include "led.h"
#include "touch.h"

extern KEY_INFO_Typedef key_info;

LED_BLINK_Typedef led_blink_info;


#define DELAY_NUM  100000
static void led_blink_delay(unsigned int num)
{
    unsigned int i = 0;
    for(i = 0;i < num;i++);
}

void Led_Pin_Config(void)
{
    LED_PIN_PxM0 &= ~((1 << LED_POWER_PORTBIT) | (1 << LED_SPEED_PORTBIT) | (1 << LED_TIMER_PORTBIT) | (1 << LED_MODE_PORTBIT));
    LED_PIN_PxM1 &= ~((1 << LED_POWER_PORTBIT) | (1 << LED_SPEED_PORTBIT) | (1 << LED_TIMER_PORTBIT) | (1 << LED_MODE_PORTBIT));
  
    LED_POWER_PIN = 1;
    LED_SPEED_PIN = 1;
    LED_TIMER_PIN = 1;
    LED_MODE_PIN = 1;


}

/*
void LedBlink(unsigned char pinnum)
{   
    if(pinnum > 3)
    {
        return;
    }
  
    switch(pinnum)
    {
      case LED_MODE_PORTBIT:
        LED_MODE_PIN = 1;
        break;
      case LED_TIMER_PORTBIT:
        LED_TIMER_PIN = 1;
        break;
      case LED_SPEED_PORTBIT:
        LED_SPEED_PIN = 1;
        break;
      case LED_POWER_PORTBIT:
        LED_POWER_PIN = 1;
        break;
      default:
        break;   
    }
    
    led_blink_delay(DELAY_NUM);
    
    switch(pinnum)
    {
      case LED_MODE_PORTBIT:
        LED_MODE_PIN = 0;
        break;
      case LED_TIMER_PORTBIT:
        LED_TIMER_PIN = 0;
        break;
      case LED_SPEED_PORTBIT:
        LED_SPEED_PIN = 0;
        break;
      case LED_POWER_PORTBIT:
        LED_POWER_PIN = 0;
        break;
      default:
        break;   
    }
    
    led_blink_delay(DELAY_NUM);
    
}
*/


void LedBlink(void)
{
    if(key_info.IsTouchedKey == 1)
    {
        if(key_info.WhichKey == KEY_MODE)
        {
            LED_MODE_PIN = 1;
//            LED_TIMER_PIN = 0;
//            LED_SPEED_PIN = 0;
//            LED_POWER_PIN = 0;
        }
        else if(key_info.WhichKey == KEY_TIMER)
        {
            LED_TIMER_PIN = 1;
//            LED_MODE_PIN = 0;
//            LED_SPEED_PIN = 0;
//            LED_POWER_PIN = 0;
        }
        else if(key_info.WhichKey == KEY_SPEED)
        {
            LED_SPEED_PIN = 1;
          
//            LED_MODE_PIN = 0;
//            LED_TIMER_PIN = 0;
//            LED_POWER_PIN = 0;
        }
        else if(key_info.WhichKey == KEY_POWER)
        {
//            LED_MODE_PIN = 0;
//            LED_TIMER_PIN = 0;
//            LED_SPEED_PIN = 0;
            LED_POWER_PIN = 1;
        }
        else
        {
            return;
        }
        
        led_blink_info.IsLedBlink = 1;
        led_blink_info.ledcount_1ms_times = 0;
        led_blink_info.blinktimes = 0;
        
        key_info.IsTouchedKey = 0;
        if( key_info.lastkey != key_info.WhichKey)
        {
            Led_Control(key_info.lastkey,LED_ON);
        }
        key_info.lastkey = key_info.WhichKey;
        
    }
    
    if(led_blink_info.IsLedBlink == 1)
    {
        if(led_blink_info.blinktimes < LED_BLINK_TIMES)
        {
            if(led_blink_info.ledstate == LED_OFF)
            {
                Led_Control(key_info.lastkey,LED_OFF);
                led_blink_info.blinktimes++;
            }
            if(led_blink_info.ledstate == LED_ON)
            {
                Led_Control(key_info.lastkey,LED_ON);
                led_blink_info.ledcount_1ms_times = 0;
            }               
        }
        else
        {
            led_blink_info.IsLedBlink = 0;
            led_blink_info.ledcount_1ms_times = 0;
            led_blink_info.blinktimes = 0;
            Led_Control(key_info.lastkey,LED_ON);
        }

    }



}

void Led_Control(unsigned char led,unsigned char on_off)
{
    if(led == KEY_NONE || led >= KEY_MAX_VALUE)
    {
        return;
    }
    if(on_off >= LED_NONE)
    {
        return;
    }
    switch(led)
    {
      case KEY_MODE:
        LED_MODE_PIN = on_off;
        break;
      case KEY_TIMER:
        LED_TIMER_PIN = on_off;
        break;
      case KEY_SPEED:
        LED_SPEED_PIN = on_off;
        break;
      case KEY_POWER:
        LED_POWER_PIN = on_off;
        break;
      default:
        break;        
    }
}




