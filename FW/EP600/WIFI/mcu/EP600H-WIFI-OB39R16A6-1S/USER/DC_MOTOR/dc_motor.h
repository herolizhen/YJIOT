#ifndef __DC_MOTOR_H__
#define __DC_MOTOR_H__

#include "PWM.h"

//定义的风机的转速单位是r/min
#define FAN_SPEED1       380    //睡眠档
#define FAN_SPEED2       620    //低档
#define FAN_SPEED3       760    //中档
//#define FAN_SPEED4       900    //高档
#define FAN_SPEED4       950    //高档

//风机每转一圈FG反馈12个脉冲
//风机的反馈信号FG每100ms是一个计数周期，下面定义的FG是100ms的计数
//风机转速和100ms FG的对应关系是 (FAN_SPEED/60)*12/10 = (FAN_SPEED*12)/(60*10) = (FAN_SPEED*2)/100 = FAN_SPEED/50
#define SPEED_FG_COUNT1		(8)//(FAN_SPEED1/50) 
#define SPEED_FG_COUNT2		(12)//(FAN_SPEED2/50) 
#define SPEED_FG_COUNT3		(15)//(FAN_SPEED3/50) 
//#define SPEED_FG_COUNT4		(18)//(FAN_SPEED4/50)
#define SPEED_FG_COUNT4		(19)//(FAN_SPEED4/50)

/*
净化器实测档位与模拟量的关系：
静音：  2.66V
低档：  3.35V
中档:   3.70V
高档：  4.36V


占空比对应的VSP的输出电压实际测试情况
8129      2.43V
9000      2.70V
9200      2.77V
9500      2.87V
10500     3.18V
11000     3.34V
11500     3.47V
11600     3.53V
12000     3.65V
12100     3.70V
12200     3.73
12500     3.81V
12600     3.86V
12800     3.9V
13500     4.14V
14000     4.20V
14000     4.3V
14200     4.36V
14500     4.45V
*/

//PWMDL_SPEED都定义为100的整数倍
//4.14V
//#define PWMDL_START			6000 
//#define PWMDL_SPEED1		9000  
//#define PWMDL_SPEED2		10500 
//#define PWMDL_SPEED3		11600 
//#define PWMDL_SPEED4		13500
//#define PWMDL_MAX		    14000

//4.36V
#define PWMDL_START			6000 
#define PWMDL_SPEED1		9000  
#define PWMDL_SPEED2		11000 
#define PWMDL_SPEED3		12100 
#define PWMDL_SPEED4		14200
#define PWMDL_MAX		    14500


#define DC_MOTOR_PWM  PWM7_NUM


enum DC_MOTOR_SPEED{
    
    DC_MOTOR_SPEED0   = 0,
    QUIET_SPEED       = 1,
    LOW_SPEED         = 2,
    MID_SPEED         = 3,
    HIGH_SPEED        = 4
    

};




void Start_DC_Motor(void);
void Stop_DC_Motor(void);

void Set_DC_Motor_Speed(unsigned char speed);

void DirectMotor(void);
void Dcmoto_adj(void);




#endif