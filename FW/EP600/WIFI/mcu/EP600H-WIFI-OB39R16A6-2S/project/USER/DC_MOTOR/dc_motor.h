#ifndef __DC_MOTOR_H__
#define __DC_MOTOR_H__

#include "PWM.h"

//����ķ����ת�ٵ�λ��r/min
#define FAN_SPEED1       380    //˯�ߵ�
#define FAN_SPEED2       620    //�͵�
#define FAN_SPEED3       760    //�е�
//#define FAN_SPEED4       900    //�ߵ�
#define FAN_SPEED4       950    //�ߵ�

//���ÿתһȦFG����12������
//����ķ����ź�FGÿ100ms��һ���������ڣ����涨���FG��100ms�ļ���
//���ת�ٺ�100ms FG�Ķ�Ӧ��ϵ�� (FAN_SPEED/60)*12/10 = (FAN_SPEED*12)/(60*10) = (FAN_SPEED*2)/100 = FAN_SPEED/50
#define SPEED_FG_COUNT1		(8)//(FAN_SPEED1/50) 
#define SPEED_FG_COUNT2		(13)//(FAN_SPEED2/50) 
#define SPEED_FG_COUNT3		(16)//(FAN_SPEED3/50) 
//#define SPEED_FG_COUNT4		(18)//(FAN_SPEED4/50)
#define SPEED_FG_COUNT4		(19)//(FAN_SPEED4/50)
/*
������ʵ�⵵λ��ģ�����Ĺ�ϵ��
������  2.66V
�͵���  3.35V
�е�:   3.70V
�ߵ���  4.36V

ռ�ձȶ�Ӧ��VSP�������ѹʵ�ʲ������
560 2.75V
580 2.78V
650 3.21V
670 3.30V
675 3.34V
740 3.67V
745 3.69V
750 3.73V
870 4.33V
875 4.37V
890 4.43V
*/

//wifi board
//PWMDL_SPEED������Ϊ100��������
//#define PWMDL_START			6000 
//#define PWMDL_SPEED1		9000  
//#define PWMDL_SPEED2		10500 
//#define PWMDL_SPEED3		11600 
//#define PWMDL_SPEED4		12500
//#define PWMDL_MAX		    13500

//4.36V
//#define PWMDL_START			6000 
//#define PWMDL_SPEED1		9000  
//#define PWMDL_SPEED2		11000 
//#define PWMDL_SPEED3		12100 
//#define PWMDL_SPEED4		14200
//#define PWMDL_MAX		    14500

//m26 board
#define PWMDL_START			375 
#define PWMDL_SPEED1		580 
#define PWMDL_SPEED2		685 
#define PWMDL_SPEED3		745
#define PWMDL_SPEED4		875
#define PWMDL_MAX		    910


#define DC_MOTOR_PWM  PWM1_NUM


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