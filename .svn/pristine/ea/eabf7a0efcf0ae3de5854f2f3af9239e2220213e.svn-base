#include "OB39R16A6.h"
#include "PWM.h"
#include "intrins.h"




//=============================================================================================
//
//=============================================================================================
void PWM_Init(void)
{
    _push_(PAGESEL);
    PAGESEL     = PAGE_1;
    //PWMEN       = (PWM7 | PWM6 | PWM5 | PWM4 );
    PWMEN       &= ~(PWM7 | PWM6 | PWM5 | PWM4 );
    //PWMEN       = (PWM7);
    PWMTBC0     = (PWMTB_PRESCALE );
    PWMOPMOD    = (PWMOP3MOD | PWMOP2MOD);
    //PWMPOLARITY = (POLARITY7 | POLARITY6 | POLARITY5 | POLARITY4);
    PERIODH     = PWM_PERIOD / 256 ;
    PERIODL     = PWM_PERIOD % 256 ;
    PWMTBC1     = (0x90 | PWM_INTERRUPT);
    DUTY2L  = 0;
    DUTY2H  = 0;
    DUTY3L  = 0;
    DUTY3H  = 0;
    _pop_(PAGESEL);
}

void PWM_Control(unsigned char pwm_num,unsigned char on_off)
{
    _push_(PAGESEL);
    PAGESEL     = PAGE_1;
  
    if(on_off == PWM_OFF)
    {
        PWMEN &= ~(1 << pwm_num);
    }
    else if(on_off == PWM_ON)
    {
        PWMEN |= (1 << pwm_num);
    }
    
    _pop_(PAGESEL);

}

void PWM_Set_Duty(unsigned char pwm_num,unsigned int duty)
{
    if(duty > PWM_MAX_DUTY)
    {
        return;
    }
    _push_(PAGESEL);
    PAGESEL = PAGE_1;
    switch(pwm_num)
    {
      case PWM4_NUM:
      case PWM5_NUM:
          DUTY2L  = duty % 256;
          DUTY2H  = duty / 256;
          break;
      case PWM6_NUM:
      case PWM7_NUM:
          DUTY3L  = duty % 256;
          DUTY3H  = duty / 256;
          break;  
      default:
          break;        
    }
    _pop_(PAGESEL);
}



//=============================================================================================
//
//=============================================================================================
void PWM_ISR(void) interrupt d_PWM_Vector
{
    _push_(PAGESEL);
    PAGESEL  = PAGE_1;
    PWMINTF &= 0xFE;
    _pop_(PAGESEL);
}
