#ifndef __TM1618_H__
#define __TM1618_H__

#include "OB39R16A6.h"

#define TM1618_STB_PIN    P1_3
#define TM1618_CLK_PIN    P1_4
#define TM1618_DIO_PIN    P1_5

//命令
#define TM1618_MODE_CMD        0x01
//使用地址自动增加模式
#define TM1618_DATA_CMD        0x40
#define TM1618_OFF             0x80
#define TM1618_ON              0x81
#define TM1618_SET_ADDR_CMD    0xC0


//最左边数码管DP的控制管脚
#define LED1_DP_PIN    P2_6

//显示脉冲宽度
//#define TM1618_PULSE_WIDTH_1_16      0x80
//#define TM1618_PULSE_WIDTH_2_16      0x81
//#define TM1618_PULSE_WIDTH_4_16      0x82
//#define TM1618_PULSE_WIDTH_10_16     0x83
//#define TM1618_PULSE_WIDTH_11_16     0x84
//#define TM1618_PULSE_WIDTH_12_16     0x85
//#define TM1618_PULSE_WIDTH_13_16     0x87

#define TM1618_PULSE_WIDTH_1_16      0x88
#define TM1618_PULSE_WIDTH_2_16      0x89
#define TM1618_PULSE_WIDTH_4_16      0x8A
#define TM1618_PULSE_WIDTH_10_16     0x8B
#define TM1618_PULSE_WIDTH_11_16     0x8C
#define TM1618_PULSE_WIDTH_12_16     0x8D
#define TM1618_PULSE_WIDTH_13_16     0x8E
#define TM1618_PULSE_WIDTH_14_16     0x8F


#define TM1618_SLAVE_ADDR   0x30
#define TM1618_READ_REGIST  0x17



void TM1618_Pin_Config(void);
void TM1618_WriteOneByte(unsigned char senddata);
//void TM1618_WriteBytes(const unsigned char *senddata,unsigned char num);
void TM1618_SetMode(void);
void TM1618_SetDataMode(void);
void TM1618_WriteFrameRegister(unsigned char *displaybuff,unsigned char lednum);
void TM1618_Clear_Framebuff(void);
void TM1618_Display_On(void);
//void TM1618_Display_Off(void);
void TM1618_Init(void);
void TM1618_DispalyData(unsigned char sensor,float sensordata);



#endif