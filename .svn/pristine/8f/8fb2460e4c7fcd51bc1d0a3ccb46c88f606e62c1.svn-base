#include "OB39R32T1.h"
#include "dc_motor.h"
#include "global.h"
#include "PWM.h"
#include "TM1620.h"
#include "sensor.h"
#include "timer.h"

const unsigned int code PWM0DL_TAB[4] = {PWMDL_SPEED1,PWMDL_SPEED2,PWMDL_SPEED3,PWMDL_SPEED4};
const unsigned char code MotorFG_TAB[4]={SPEED_FG_COUNT1,SPEED_FG_COUNT2,SPEED_FG_COUNT3,SPEED_FG_COUNT4};



void Start_DC_Motor(void)
{
    speed_dang = LOW_SPEED;
    pwmDLbak = 0;
    PWM_Set_Duty(DC_MOTOR_PWM,pwmDLbak);
}


void Stop_DC_Motor(void)
{
   speed_dang = DC_MOTOR_SPEED0;
}


void Set_DC_Motor_Speed(unsigned char speed)
{
    if(speed > 4 || speed < 0)
    {
        return;
    }
    
    speed_dang = speed;
    IsSpeedChanged = 1;
    
    TM1620_LED_Control(speed_dang + 1,LED_ON);
}


//1ms执行1次
void DirectMotor(void)
{
	unsigned int temp = 0;
  
  nowtime_s = get_sys_stime();
  
  //开机后先开仓门，延时2秒再启动风机
  if(nowtime_s < (door_open_time + 2))
  {
      return;
  }
  
	if(speed_dang >= 1)
  {
      temp = PWM0DL_TAB[speed_dang-1]	;
  
  }
	
	if((sys_mode == RUNNING) && (IsSpeedChanged))// 转速发生改变, PWM 设定到目标值
	{

		if(speedBak != speed_dang)
		{

			gbMotorDelay = 1;
			speedBak = speed_dang;// 开始启动时, PWM 占空比设置的初始值
      gbMotorFGEn = 0;

		}
   			
		if(gbMotorDelay)	// 启动到PWM 设定目标值
		{	
     
			if(pwmDLbak < temp)
			{      
				pwmDLbak += 5;
			}
			else if(pwmDLbak > temp)
			{
				pwmDLbak -= 5;
			}
			else
			{         
				gbMotorDelay=0;
        IsSpeedChanged = 0;
			}
      PWM_Set_Duty(DC_MOTOR_PWM,pwmDLbak);
			
		}
		else  				// 通过反馈信号FG  控制转速 
		{	
			gBMotorFGSet = MotorFG_TAB[speed_dang-1];
			gbMotorFGEn = 1;
		}
	}
	else if((sys_mode == STANDBY) && (IsSpeedChanged))
	{
		gbMotorFGEn = 0;		  
		if(pwmDLbak >= 5)
		{
      if(IsFanRunning)
      {
          pwmDLbak -= 5;
          PWM_Set_Duty(DC_MOTOR_PWM,pwmDLbak);    
      }

		}
		else
		{ 
      if(IsFanRunning)
      {
          IsSpeedChanged = 0;
          pwmDLbak = 0;
          PWM_Set_Duty(DC_MOTOR_PWM,pwmDLbak);
          IsFanRunning = 0; 
          speedBak = speed_dang;        
      }

		} 
	} 

}

//100ms执行一次
void Dcmoto_adj(void)
{
	//unsigned int temp = 0;  
  
  //防止FG信号或者电机出现问题后，PWM的脉宽一直增加
  unsigned int pwm_compare = 0;
  
  if(is_sys_auto_check == 1)
  {
      return;
  }
  
  
  switch(speed_dang)
  {
    case QUIET_SPEED:
      pwm_compare = PWMDL_SPEED1 + 5;
      break;
    case LOW_SPEED:
      pwm_compare = PWMDL_SPEED2 + 5;
      break;    
    case MID_SPEED:
      pwm_compare = PWMDL_SPEED3 + 5;
      break;  
    case HIGH_SPEED:
      pwm_compare = PWMDL_SPEED4 + 5;
      break;   
    default:
      return;      
  }
  
  
	if(gbMotorFGEn)
	{
    // 通过反馈信号FG  控制转速
		if(FGcount > gBMotorFGSet)
		{								
			if(pwmDLbak > pwm_compare)
			{
				pwmDLbak -= 5;
			}
		}
		else if	(FGcount < gBMotorFGSet)
		{
			if(pwmDLbak < pwm_compare)
			{
				pwmDLbak += 5;
			}
		}
    PWM_Set_Duty(DC_MOTOR_PWM,pwmDLbak);
	}
  
  
	FGcount = 0;
}


