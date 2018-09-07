#ifndef __TM1620_H__
#define __TM1620_H__

#include "OB39R32T1.h"
#include "sensor.h"

//wifi board
//#define TM1620_STB_PIN    P1_3
//#define TM1620_CLK_PIN    P1_4
//#define TM1620_DIO_PIN    P1_5

#define TM1620_STB_PIN    P0_1
#define TM1620_CLK_PIN    P2_4
#define TM1620_DIO_PIN    P0_2

//命令
#define TM1620_MODE_CMD        0x02
//使用地址自动增加模式
#define TM1620_DATA_CMD        0x40
#define TM1620_OFF             0x80
#define TM1620_ON              0x81
//TM1620手册上写的显示寄存器地址默认是0x00，但是用0x00地址会出错，用0xC0地址正常
//#define TM1620_SET_ADDR_CMD    0xC0
//#define TM1620_ADDR_CMD_BASE   0xC0
#define TM1620_ADDR_CMD_BASE   0xC0

//第一组LED使用的TM1620的 第5位
#define LED_GROUP1_GRID_NUM    5
#define LED_GROUP2_GRID_NUM    6


//显示脉冲宽度
#define TM1620_PULSE_WIDTH_1_16      0x88
#define TM1620_PULSE_WIDTH_2_16      0x89
#define TM1620_PULSE_WIDTH_4_16      0x8A
#define TM1620_PULSE_WIDTH_10_16     0x8B
#define TM1620_PULSE_WIDTH_11_16     0x8C
#define TM1620_PULSE_WIDTH_12_16     0x8D
#define TM1620_PULSE_WIDTH_13_16     0x8E
#define TM1620_PULSE_WIDTH_14_16     0x8F


#define TM1620_SLAVE_ADDR   0x30
#define TM1620_READ_REGIST  0x17


//LED灯
//丝印修改前的定义
/*
enum LED_NUM{

    LED_CHILD         = 0,
    LED_POWER         = 1,
    LED_QUIET         = 2,
    LED_SPEED_LOW     = 3,
    LED_SPEED_MID     = 4,
    LED_SPEED_HIGH    = 5,
    LED_TIMER_1H      = 6,
    LED_TIMER_2H      = 7,
    LED_TIMER_4H      = 8,
    LED_TIMER_8H      = 9,
    LED_AUTO_MODE     = 10,
    LED_SLEEP_MODE    = 11,
    LED_ALL           = 12,
    LED_MAX_NUM       = 13

};
*/
//丝印修改后的定义
enum LED_NUM{

    LED_CHILD         = 0,
    LED_POWER         = 1,
    LED_QUIET         = 2,
    LED_SPEED_LOW     = 3,
    LED_SPEED_MID     = 4,
    LED_SPEED_HIGH    = 5,
    LED_UV            = 6,
    LED_ION           = 7,
    LED_TIMER_1H      = 8,
    LED_TIMER_2H      = 9,
    LED_AUTO_MODE     = 10,
    LED_SLEEP_MODE    = 11,
    LED_WIFI          = 12,  
    LED_ALL           = 13,
    LED_MAX_NUM       = 14

};


enum LED_STATE{

    LED_OFF   = 0,
    LED_ON    = 1

};


enum GRID_NUM{
   
    GRID_NONE   = 0,
    GRID1       = 1,
    GRID2       = 2,
    GRID3       = 3,
    GRID4       = 4,
    GRID5       = 5, 
    GRID6       = 6,
    GRID_MAX    = 7

};



void TM1620_Pin_Config(void);
void TM1620_WriteOneByte(unsigned char senddata);
//void TM1620_WriteBytes(const unsigned char *senddata,unsigned char num);
void TM1620_SetMode(void);
void TM1620_SetDataMode(void);
void TM1620_WriteFrameRegister(unsigned char sensortype,unsigned char grid_num,unsigned char *displaybuff,unsigned char bufferlength);
void TM1620_Clear_Framebuff(void);
void TM1620_Display_On(void);
//void TM1620_Display_Off(void);
void TM1620_Init(void);
void TM1620_DispalyData(unsigned char sensor,unsigned int sensordata);

void TM1620_LED_Control(unsigned char led_num,unsigned char on_off);



#endif