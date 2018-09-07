#ifndef __STEP_MOTOR_H__
#define __STEP_MOTOR_H__

#include "OB39R32T1.h"

//邮寄的第一台样机ABCD定义
//#define STEP_MOTOR_A    P2_3
//#define STEP_MOTOR_B    P2_2
//#define STEP_MOTOR_C    P2_1
//#define STEP_MOTOR_D    P2_0

//wifi board
//#define STEP_MOTOR_A    P2_0
//#define STEP_MOTOR_B    P2_1
//#define STEP_MOTOR_C    P2_2
//#define STEP_MOTOR_D    P2_3

#define STEP_MOTOR_A    P1_3
#define STEP_MOTOR_B    P1_2
#define STEP_MOTOR_C    P2_0
#define STEP_MOTOR_D    P2_1


//仓门检测管脚定义
//wifi board
//#define DOOR_CHECK_PIN       P1_1
//#define DOOR_CHECK_PORTBIT   1
//#define DOOR_CHECK_PxM0      P1M0
//#define DOOR_CHECK_PxM1      P1M1

//m26 board
#define DOOR_CHECK_PIN       P0_0
#define DOOR_CHECK_PORTBIT   0
#define DOOR_CHECK_PxM0      P0M0
#define DOOR_CHECK_PxM1      P0M1



//void Step_Motor_run(void);

void Door_Pin_Init(void);

void Step_Motor_Pin_Init(void);

void StartMotor(signed long angle);
//void StopMotor(void);

//void Door_Check(void);
void Door_Open(void);
void Door_Close(void);

//void Check_If_Close_Door(void);

void TurnMotor(void);

#endif