/*
*按键说明：芯片中有3个寄存器 STATUS2 STATUS1 STATUS0
 每个STATUS寄存器对应8个按键，其中每一位对应一个按键
 STATUS0对应按键KEY1-KEY7 8个通道
 STATUS1对应按键KEY8-KEY15 共8个通道
 STATUS2对应按键KEY16-KEY24共8个通道
 
 POWER按键对应通道1，按下后STATUS0的bit1置1，即STATUS0 = 2
 SPEED按键对应的按键KEY8，第8通道，按下后 STATUS1 的bit0置位，即  STATUS1 = 1
 TIMER按键对应的按键KEY9，第9通道，按下后 STATUS1 的bit1置位，即  STATUS1 = 2
 MODE按键对应的按键KEY10，第10通道，按下后 STATUS1 的bit2置位，即 STATUS1 = 4
 因SPEED、TIMER和MODE按键都用STATUS1表示，所有当两个按键同时按下时对应的标志位都置1
 例如：TMIER和MODE同时按下时 STATUS1 = 2 + 4 = 6
*/


#include "OB39A08T1.h"
#include "touch.h"
#include "global.h"

//typedef struct{
//  
//  unsigned char IsCount;
//  unsigned char count_1ms_times;
//  unsigned char IsTouchedKey;
//  unsigned char WhichKey;

//}KEY_INFO_Typedef;


KEY_INFO_Typedef key_info;


unsigned char Scan_TouchPad(void)
{
    unsigned char whichkey = 0;
    unsigned char temp_status0,temp_status1 = 0;
    static unsigned char last_status0,last_status1 = 0;
  
    temp_status0 = STATUS0;
    temp_status1 = STATUS1;
  
    //POWER按键和其他按键不能同时按下
    if((temp_status0 == 0 && temp_status1 == 0) || (temp_status0 != 0 && temp_status1 != 0))
    {
        last_status0 = 0;
        last_status1 = 0;
        return 0;
    }
    
    if(temp_status0 != 0)
    {
        if(temp_status0 != last_status0)
        {
            key_info.IsCount = 1;
            key_info.count_1ms_times = 0;
            key_info.IsTouchedKey = 0;
            key_info.WhichKey = KEY_NONE;
        }
    }
    
    if(temp_status1 != 0)
    {
        if(temp_status1 != last_status1)
        {
            key_info.IsCount = 1;
            key_info.count_1ms_times = 0;
            key_info.IsTouchedKey = 0;
            key_info.WhichKey = KEY_NONE;
        }
    }
    
    if(key_info.count_1ms_times >= KEY_TOUCH_MS_TIMES)
    {
        //一个按键计数完毕后停止计数，防止一直按着一个按键不松开
        key_info.IsCount = 0;
        key_info.count_1ms_times = 0;
        
        if(temp_status0 != 0)
        {
            if(temp_status0 == KEY_POWER_VALUE)
            {
                key_info.IsTouchedKey = 1;
                key_info.WhichKey = KEY_POWER;
            }
            else
            {
                key_info.IsTouchedKey = 0;
                key_info.WhichKey = KEY_NONE;
            }
        }
        
        if(temp_status1 != 0)
        {
            if(temp_status1 == KEY_SPEED_VALUE)
            {
                key_info.IsTouchedKey = 1;
                key_info.WhichKey = KEY_SPEED;
            }
            else if(temp_status1 == KEY_TIMER_VALUE)
            {
                key_info.IsTouchedKey = 1;
                key_info.WhichKey = KEY_TIMER;
            }
            else if(temp_status1 == KEY_MODE_VALUE)
            {
                key_info.IsTouchedKey = 1;
                key_info.WhichKey = KEY_MODE;
            }    
            else if(temp_status1 == KEY_WIFI_VALUE)
            {
                key_info.IsTouchedKey = 1;
                key_info.WhichKey = KEY_WIFI;
            }              
            else
            {
                key_info.IsTouchedKey = 0;
                key_info.WhichKey = KEY_NONE;            
            }
        }
        

    
    }
    

   
    
    last_status0 = temp_status0;    
    last_status1 = temp_status1;
    
    return key_info.WhichKey;
}




