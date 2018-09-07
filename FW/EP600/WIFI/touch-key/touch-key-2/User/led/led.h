#ifndef __LED_H__
#define __LED_H__

#include "OB39A08T1.h"

#define LED_POWER_PIN  P2_3
#define LED_SPEED_PIN  P2_2
#define LED_TIMER_PIN  P2_1
#define LED_MODE_PIN   P2_0

#define LED_POWER_PORTBIT   3
#define LED_SPEED_PORTBIT   2
#define LED_TIMER_PORTBIT   1
#define LED_MODE_PORTBIT    0


#define LED_PIN_PxM0   P2M0
#define LED_PIN_PxM1   P2M1


#define LED_OFF_TIMES  300
#define LED_ON_TIMES   600
//#define LED_OFF_TIMES  500
//#define LED_ON_TIMES   1000
#define LED_BLINK_TIMES  3


typedef struct{

    volatile unsigned char IsLedBlink;
    volatile unsigned int  ledcount_1ms_times;
    volatile unsigned char blinktimes;
    volatile unsigned char ledstate;
  
}LED_BLINK_Typedef;


enum LED_STATUS{
    
    LED_OFF    = 0,
    LED_ON     = 1,
    LED_NONE   = 2,
    


};


void Led_Pin_Config(void);

void Led_Control(unsigned char led,unsigned char on_off);

//void LedBlink(unsigned char pinnum);

void LedBlink(void);




#endif