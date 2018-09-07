#ifndef __STEP_MOTOR_H__
#define __STEP_MOTOR_H__

#include "OB39R16A6.h"

//邮寄的第一台样机ABCD定义
//#define STEP_MOTOR_A    P2_3
//#define STEP_MOTOR_B    P2_2
//#define STEP_MOTOR_C    P2_1
//#define STEP_MOTOR_D    P2_0

#define STEP_MOTOR_A    P2_0
#define STEP_MOTOR_B    P2_1
#define STEP_MOTOR_C    P2_2
#define STEP_MOTOR_D    P2_3


//仓门检测管脚定义
#define DOOR_CHECK_PIN       P1_1
#define DOOR_CHECK_PORTBIT   1
#define DOOR_CHECK_PxM0      P1M0
#define DOOR_CHECK_PxM1      P1M1



//void Step_Motor_run(void);

void Door_Pin_Init(void);

void Step_Motor_Pin_Init(void);

void StartMotor(signed long angle);
//void StopMotor(void);

//void Door_Check(void);
void Door_Open(void);
void Door_Close(void);

void Check_If_Close_Door(void);

void TurnMotor(void);

#endif