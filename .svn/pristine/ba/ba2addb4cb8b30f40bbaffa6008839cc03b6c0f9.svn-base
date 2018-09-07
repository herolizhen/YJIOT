#ifndef __TOUCH_H__
#define __TOUCH_H__


#define KEY_POWER_VALUE     0x02
#define KEY_SPEED_VALUE     0x01
#define KEY_TIMER_VALUE     0x02
#define KEY_MODE_VALUE      0x04
#define KEY_WIFI_VALUE      0x06

#define KEY_TOUCH_MS_TIMES   5


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
  unsigned int  count_1ms_times;
  unsigned char lastkey;
  unsigned char IsTouchedKey;   //有按键按下并且保持按下500ms被置位
  unsigned char WhichKey;

}KEY_INFO_Typedef;



unsigned char Scan_TouchPad(void);


#endif 