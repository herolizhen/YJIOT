#include <stdio.h>
#include "touch_key.h"
#include "SOFT_IIC.h"
#include "timer.h"
#include "global.h"
#include "debug_uart.h"
//#include "common.h"


KEY_INFO_Typedef  key_info;


#define KEY_IIC_DELAY_COUNT  10

void key_i2c_delay(void)
{
	int i = 0;
	for(i = 0;i < KEY_IIC_DELAY_COUNT;i++);
}


void Key_IIC_PinConifg(void)
{
     
    KEY_IIC_PxM0 &= ~((1 << KEY_IIC_SDA_PORTBIT) | (1 << KEY_IIC_SCL_PORTBIT));
    KEY_IIC_PxM1 &= ~((1 << KEY_IIC_SDA_PORTBIT) | (1 << KEY_IIC_SCL_PORTBIT));
  
    KEY_IIC_SCL_PIN = 1;
    KEY_IIC_SDA_PIN = 1;
}



void Set_KEY_SDA_Pin_Mode(unsigned char mode)
{
    if(mode == PIN_INPUT)
    {
        //PIN设置为输入时，PxM0对应的位置0，PxM1对应的位置1
        KEY_IIC_PxM0 &= ~(1 << KEY_IIC_SDA_PORTBIT);
        KEY_IIC_PxM1 |= (1 << KEY_IIC_SDA_PORTBIT);
    }
    else if(mode == PIN_OUTPUT)
    {      
        KEY_IIC_PxM0 &= ~(1 << KEY_IIC_SDA_PORTBIT);
        KEY_IIC_PxM1 &= ~(1 << KEY_IIC_SDA_PORTBIT);
    }
}
  
void Set_KEY_SCL_Pin_Mode(unsigned char mode)
{
    if(mode == PIN_INPUT)
    {
        //PIN设置为输入时，PxM0对应的位置0，PxM1对应的位置1
        KEY_IIC_PxM0 &= ~(1 << KEY_IIC_SCL_PORTBIT);
        KEY_IIC_PxM1 |= ((1 << KEY_IIC_SCL_PORTBIT));
    }
    else if(mode == PIN_OUTPUT)
    {      
        KEY_IIC_PxM0 &= ~(1 << KEY_IIC_SCL_PORTBIT);
        KEY_IIC_PxM1 &= ~(1 << KEY_IIC_SCL_PORTBIT);     
    }

}


void Key_IIC_SDA_1(void)
{
    KEY_IIC_SDA_PIN = 1;
}

void Key_IIC_SDA_0(void)
{
    KEY_IIC_SDA_PIN = 0;
}

void Key_IIC_SCL_1(void)
{
    KEY_IIC_SCL_PIN = 1;
}
void Key_IIC_SCL_0(void)
{
    KEY_IIC_SCL_PIN = 0;
}


unsigned char Key_IIC_SDA_READ(void)
{
    return (KEY_IIC_SDA_PIN ? 1 : 0);
}



void Get_Key_Status(unsigned char *key_status)
{
    const unsigned char readaddr = 0x17;
    unsigned char res = 1;
  
    IIC_Operations.IIC_NUM = TOUCH_KEY_IIC;
    IIC_Operations.Set_SDA_Pin_Mode = Set_KEY_SDA_Pin_Mode;
    IIC_Operations.Set_SCL_Pin_Mode = Set_KEY_SCL_Pin_Mode;
    IIC_Operations.i2c_delay = key_i2c_delay;
    IIC_Operations.SDA_1 = Key_IIC_SDA_1;
    IIC_Operations.SDA_0 = Key_IIC_SDA_0;
    IIC_Operations.SCL_1 = Key_IIC_SCL_1;
    IIC_Operations.SCL_0 = Key_IIC_SCL_0;
    IIC_Operations.I2C_SDA_READ = Key_IIC_SDA_READ;
  
    
    res = I2C_WriteBytes(OB39A08T1_ADDRESS,&readaddr,1);
    if(res == 0)
    {
        I2C_ReadBytes(OB39A08T1_ADDRESS,key_status,3);
    }
    
}

unsigned char Scan_TouchPad(void)
{
    static unsigned char wifi_key_count_times = 0;
    static unsigned char timer_key_count_times = 0;
    static unsigned char mode_key_count_times = 0;
    unsigned char whichkey = 0;
    unsigned char temp_status0,temp_status1 = 0;
    static unsigned char last_status0,last_status1 = 0;
  
    //unsigned char debug_buff[20] = {0};
  
    unsigned char key_status[3] = {0};
    
    //如果上电后检测到仓门坏了，则按键不起作用
    //如果仓门正在工作则按键不起作用
    if(IsStepMotorBusy)
    {
        return 0xFF;
    }
    
    Get_Key_Status(key_status);
  
    temp_status0 = key_status[2];
    temp_status1 = key_status[1];
  
    //POWER按键和其他按键不能同时按下
    if((temp_status0 == 0 && temp_status1 == 0) || (temp_status0 != 0 && temp_status1 != 0))
    {
        last_status0 = 0;
        last_status1 = 0;
      
        wifi_key_count_times = 0;
        timer_key_count_times = 0;
        mode_key_count_times = 0;

        Clear_Touch_Info();
        return 0;
    }
    
    if(temp_status0 != 0)
    {
        if(temp_status0 != last_status0)
        {
            key_info.IsCount = 1;
            key_info.count_times = 0;
            key_info.IsTouchedKey = 0;
            key_info.WhichKey = KEY_NONE;
        }
    }
    
    if(temp_status1 != 0)
    {
        if(temp_status1 != last_status1)
        {
            key_info.IsCount = 1;
            key_info.count_times = 0;
            key_info.IsTouchedKey = 0;
            key_info.WhichKey = KEY_NONE;
        }
    }
    
    if(key_info.count_times >= (KEY_TOUCH_MS_TIMES * TIMER_BASE))
    {
        //一个按键计数完毕后停止计数，防止一直按着一个按键不松开
        if(temp_status1 != KEY_WIFI_VALUE && temp_status1 != KEY_TIMER_VALUE && temp_status1 != KEY_MODE_VALUE)
        {
            key_info.IsCount = 0;
            key_info.count_times = 0;
          
            //如果不是按下wifi组合键，先把wifi计数清零
            wifi_key_count_times = 0;
            //如果不是按下timer键，先把timer计数清零
            timer_key_count_times = 0;
            //如果不是按下mode键，先把mode计数清零
            mode_key_count_times = 0;
        }
        else
        {
            //如果按下的是WIFI按键，则从0重新开始计数，直到检测到按下2秒钟以后再停止
            key_info.count_times = 0;
        }

        
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
            
            wifi_key_count_times = 0;
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
                timer_key_count_times += 1;
                if(timer_key_count_times >= (1000 / KEY_TOUCH_MS_TIMES))
                {
                    key_info.IsTouchedKey = 1;
                    key_info.WhichKey = KEY_TIMER;
                  
                    //停止中断中的计数
                    key_info.IsCount = 0;
                    key_info.count_times = 0;
                    //此处timer_key_count_times不清零，防止一直按着组合键不松开，松开按键后再清零
                }
              
            }
            else if(temp_status1 == KEY_MODE_VALUE)
            {
                mode_key_count_times += 1;
                if(mode_key_count_times >= (1000 / KEY_TOUCH_MS_TIMES))
                {
                    key_info.IsTouchedKey = 1;
                    key_info.WhichKey = KEY_MODE;
                  
                    //停止中断中的计数
                    key_info.IsCount = 0;
                    key_info.count_times = 0;
                    //此处mode_key_count_times不清零，防止一直按着组合键不松开，松开按键后再清零
                }
            }    
            else if(temp_status1 == KEY_WIFI_VALUE)
            {
              
                wifi_key_count_times += 1;
//                mymemset(debug_buff,0,mystrlen(debug_buff));
//                sprintf(debug_buff,"wifi_times:%d\n",(unsigned int)wifi_key_count_times);  
//                DEBUG_Uart_Sendbytes(debug_buff,mystrlen(debug_buff));  
              
                if(wifi_key_count_times >= (2000 / KEY_TOUCH_MS_TIMES))
                {
                    key_info.IsTouchedKey = 1;
                    key_info.WhichKey = KEY_WIFI;
                  
                    //停止中断中的计数
                    key_info.IsCount = 0;
                    key_info.count_times = 0;
                    //此处wifi_key_count_times不清零，防止一直按着组合键不松开，松开按键后再清零
                }
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


void Clear_Touch_Info(void)
{
    key_info.IsCount = 0;
    key_info.count_times = 0;
    key_info.IsTouchedKey = 0;
    key_info.WhichKey = KEY_NONE;
}



