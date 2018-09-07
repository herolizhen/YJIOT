#include "ION.h"
#include "global.h"
#include "TM1620.h"



void ION_Pin_Init(void)
{
    ION_PIN_PxM0 |= (1 << ION_PIN_PORTBIT);
    ION_PIN_PxM1 &= ~(1 << ION_PIN_PORTBIT);
  
    ION_CONTROL_PIN = 0;
}


void ION_On(void)
{
    ION_CONTROL_PIN = 1;
    Is_ION_On = 1;
    TM1620_LED_Control(LED_ION,LED_ON);
  
    dev_status = 1;
    
}

void ION_Off(void)
{
    ION_CONTROL_PIN = 0;
    Is_ION_On = 0;
    TM1620_LED_Control(LED_ION,LED_OFF);
  
    dev_status = 1;
}