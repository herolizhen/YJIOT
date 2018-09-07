#include <stdio.h>
#include <string.h>
#include "IIC.h"
#include "TM1620.h"
#include "sensor.h"
#include "SOFT_IIC.h"
#include "PWM.h"
#include "dc_motor.h"
#include "timer.h"
#include "global.h"
#include "INT1.h"
#include "step_motor.h"
#include "sys_run.h"
#include "buzzer.h"
#include "wifi_uart.h"
#include "debug_uart.h"
#include "soft_uart.h"
#include "ADC.h"
#include "UV.h"
#include "ION.h"
#include "global.h"
#include "charge.h"
#include "UART0.h"


/*
sprintf需注意的地方：
1.格式化整数时，必须传参 unsigned int 格式
*/
/*
程序需注意问题：
1.在使用long类型和宏定义时容易出现问题，计算结果不对，如下示例
#define TEST_NUM   60000
unsigned long temp = 0;
temp = TEST_NUM + 10000;

计算结果本应该是70000 = 0x11170,但是实际运算出来的结果是0xffff1170。
宏定义的数值如果小于0xFFFF,用该宏定义的值和一个小于0xFFFF的数运算，如果结果超过0xFFFF，则出现错误结果。做乘法运算一样存在这样的问题
但是如果定义 
#define TEST_NUM   70000  
即宏定义的数值超过 0xFFFF，计算结果是正确的。

如果直接使用 temp = 60000 + 10000; 直接使用数字进行计算没有问题


解决办法：
temp = (TEST_NUM | 0x00) + 10000;  
这种运算结果正确


*/


void main(void)
{

  unsigned long times_1s = 0;

//  unsigned char test = 0;
//  unsigned char debug_buff[30] = {0};


  TM1620_Init();
  
  Key_IIC_PinConifg();
  Start_Timer1();
  Start_INT1();

  
  PWM_Init();
  PWM_Control(PWM7_NUM,PWM_ON);

  
  
  Step_Motor_Pin_Init();
  Buzzer_PinConfig();
  SENSOR_IIC_PinConifg();
  Soft_UART_Init();
#ifdef WIFI_SOFT_UART
  Wifi_Uart_Init();
#else
  init_UART0();
#endif 
  DEBUG_Uart_Init();
  UV_Pin_Init();
  ION_Pin_Init();

  
  Buzzer_Power_On();
  TM1620_DispalyData(SENSOR_PM25,0);
  TM1620_LED_Control(LED_ALL,LED_OFF);
  TM1620_LED_Control(LED_POWER,LED_ON);
  TM1620_LED_Control(LED_SLEEP_MODE,LED_ON);
  
  //为了保证安全启动必须进行仓门检测，仓门如果坏了则按键失效
  sys_init_check();
  
  charge_init();
  
  while(1)
  {
   
//      if(_test_timeflag(g_1min_flag))
//      { 
//          g_1min_flag = 0;
//              
//      }
      
      if(_test_timeflag(g_1s_flag))
      {
          g_1s_flag = 0;
          times_1s++;
        
          display_pm_data(); 
          
          //手机发送指令开仓门指令后，如果1分钟内不支付则关闭仓门
          Check_If_Close_Door();
          
          if(is_sys_auto_check == 1)
          {
              TM1620_DispalyData(2,sys_check_info.fan_check_fault_times);
              //TM1620_DispalyData(2,sys_check_info.fg_count);
            
          }
          
          //手动测试时，如果3分钟内不通过APP停止，则程序自动停止
          if(is_sys_manual_check == 1)
          {
              check_if_stop_manual_check();
          }
         
      }
  
      if(_test_timeflag(g_1ms_flag))
      {
          g_1ms_flag = 0;
          sys_run();
          DirectMotor();       
      }  

      if(_test_timeflag(g_2ms_flag))
      {
          g_2ms_flag = 0;
          TurnMotor();
      }        
      
      if(_test_timeflag(g_10ms_flag))
      {
          g_10ms_flag = 0;
          Scan_TouchPad();  
          Deal_Wifi_Uart_Data();         
      }   

      if(_test_timeflag(g_100ms_flag))
      {
          g_100ms_flag = 0;
        
            
          if(is_sys_auto_check == 1)
          {
              sys_dev_auto_check();
          }     

          Dcmoto_adj();   
          UV_Check();                
      }
      
      get_charge_info();
      
      if(cost_info.IsSelfChargeMode == 1)
      {  
          //当MCU和WIFI模块连续通讯错误达到一定次数后，可能是wifi模块无法正常工作了，此时MCU进入自计费模式，直到把费用时间用完
          mcu_self_charge();
      }
     
  }
}
