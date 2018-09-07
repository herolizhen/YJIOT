#ifndef __TOUCH_KEY_H__
#define __TOUCH_KEY_H__


//HK板子管脚定义
//#define KEY_IIC_SCL_PIN   P3_6
//#define KEY_IIC_SDA_PIN   P3_5

//#define KEY_IIC_SCL_PORTBIT    6
//#define KEY_IIC_SDA_PORTBIT    5


//#define KEY_IIC_PxM0      P3M0
//#define KEY_IIC_PxM1      P3M1

#define OB39A08T1_ADDRESS   0x30


#define KEY_IIC_SCL_PIN   P3_0
#define KEY_IIC_SDA_PIN   P3_1

#define KEY_IIC_SCL_PORTBIT    0
#define KEY_IIC_SDA_PORTBIT    1


#define KEY_IIC_PxM0      P3M0
#define KEY_IIC_PxM1      P3M1


#define KEY_POWER_VALUE     0x02
#define KEY_SPEED_VALUE     0x01
#define KEY_TIMER_VALUE     0x02
#define KEY_MODE_VALUE      0x04
#define KEY_WIFI_VALUE      0x06

#define KEY_TOUCH_MS_TIMES   50


enum TOUCH_KEY{
  
  KEY_NONE          = 0,
  KEY_MODE          = 1,
  KEY_TIMER         = 2,
  KEY_SPEED         = 3,
  KEY_POWER         = 4,
  KEY_WIFI          = 5,
  KEY_MAX_VALUE     = 6  
  
};


typedef struct{
  
  unsigned char IsCount;  //有按键被按下开始计数
  unsigned int  count_times;
  unsigned char lastkey;
  unsigned char IsTouchedKey;   //有按键按下并且保持按下500ms被置位
  unsigned char WhichKey;

}KEY_INFO_Typedef;

void Key_IIC_PinConifg(void);

void key_i2c_delay(void);
void Key_IIC_SDA_1(void);
void Key_IIC_SDA_0(void);
void Key_IIC_SCL_1(void);
void Key_IIC_SCL_0(void);
unsigned char Key_IIC_SDA_READ(void);

void Set_KEY_SDA_Pin_Mode(unsigned char mode);
void Set_KEY_SCL_Pin_Mode(unsigned char mode);

unsigned char Scan_TouchPad(void);
void Clear_Touch_Info(void);





#endif