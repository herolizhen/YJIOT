#ifndef __PWM_H__
#define __PWM_H__

#define PAGE_0          0x01
#define PAGE_1          0x03

//===============================
//VARIABLES
//===============================
#define PWMTB_PRESCALE  0x00        //PWM Time base PreScale

#define PWM_INTERRUPT   0x01        //PWM Period Interrupt



#define PWM4            0x10        //PWM4 Output Enable
#define PWM5            0x20        //PWM5 Output Enable
#define PWM6            0x40        //PWM6 Output Enable
#define PWM7            0x80        //PWM7 Output Enable

#define POLARITY4       0x00        //PWM4 Polarity active
#define POLARITY5       0x00        //PWM5 Polarity active
#define POLARITY6       0x00        //PWM6 Polarity active
#define POLARITY7       0x00        //PWM7 Polarity active

#define PWMOP3MOD       0x80        //PWM6,PWM7 mode
#define PWMOP2MOD       0x40        //PWM4,PWM5 mode



#define PWM_PERIOD      16383      //PWM period
#define PWM_MAX_DUTY    16383    //1500kz,PWM_PERIOD = 16383模式下测试，占空比设置为16383后，FG电压为5V






enum PWM_NUM{ 

    PWM_NONE   = -1,
    PWM0_NUM   = 0,
    PWM1_NUM   = 1,
    PWM2_NUM   = 2,
    PWM3_NUM   = 3,
    PWM4_NUM   = 4,
    PWM5_NUM   = 5,
    PWM6_NUM   = 6,
    PWM7_NUM   = 7

};

enum PWM_STATE{

    PWM_OFF = 0,
    PWM_ON  = 1
};


enum PWM_FREQUENCE{

    PWM_1500HZ = 0,
    PWM_375HZ  = 1,
    PWM_94HZ   = 2,
    PWM_23HZ   = 3

};



//===============================
//PUBLIC SUBROUTINES
//===============================
void PWM_Init(void);
//void PWM_Control(PWM_NUM_Typedef pwm_num,PWM_STATE_Typedef on_off);
//void PWM_Set_Duty(PWM_NUM_Typedef pwm_num,unsigned int duty);

//void PWM_Control(unsigned char pwm_num,unsigned char on_off);
void PWM_Set_Duty(unsigned char pwm_num,unsigned int duty);



#endif
