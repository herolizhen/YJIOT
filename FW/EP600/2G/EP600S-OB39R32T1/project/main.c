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
#include "INT.h"
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
#include "EEPROM.h"
#include "charge.h"
#include "UART0.h"
#include "common.h"
#include "M26.h"
#include "LVI_LVR.h"


/*
sprintf��ע��ĵط���
1.��ʽ������ʱ�����봫�� unsigned int ��ʽ
*/
/*
������ע�����⣺
1.��ʹ��long���ͺͺ궨��ʱ���׳������⣬���������ԣ�����ʾ��
#define TEST_NUM   60000
unsigned long temp = 0;
temp = TEST_NUM + 10000;

��������Ӧ����70000 = 0x11170,����ʵ����������Ľ����0xffff1170��
�궨�����ֵ���С��0xFFFF,�øú궨���ֵ��һ��С��0xFFFF�������㣬����������0xFFFF������ִ����������˷�����һ����������������
����������� 
#define TEST_NUM   70000  
���궨�����ֵ���� 0xFFFF������������ȷ�ġ�

���ֱ��ʹ�� temp = 60000 + 10000; ֱ��ʹ�����ֽ��м���û������


����취��
temp = (TEST_NUM | 0x00) + 10000;  
������������ȷ


*/

#define test_EEPROM_START_ADDR   0x3D00


extern M26_Cmd_Typedef m26_cmd_info;
extern M26_RESGISTER_Typedef M26_register_net;

extern unsigned char m26_action;



void main(void)
{

  unsigned long times_1s = 0;


  M26_Power_Pin_Init();
  M26_Power_On();
  M26_Wakeup_Pin_Init();
  
  TM1620_Init();
  
  Key_IIC_PinConifg();
  Start_Timer1();
  Start_INT3();

  
  PWM_Init();

  
  
  Step_Motor_Pin_Init();
  Buzzer_PinConfig();
  SENSOR_IIC_PinConifg();
  Soft_UART_Init();
#ifdef WIFI_SOFT_IIC
  Wifi_Uart_Init();
#else
  init_UART0();
#endif 
  DEBUG_Uart_Init();
  UV_Pin_Init();
  ION_Pin_Init();


  
  M26_register_net.Is_m26_registerd = 0;
  M26_register_net.step = 0;
    
  //EA = 1;                //Enable all inierrupt
  
  Buzzer_Power_On();
  TM1620_DispalyData(SENSOR_PM25,0);
  TM1620_LED_Control(LED_ALL,LED_OFF);
  TM1620_LED_Control(LED_POWER,LED_ON);
  TM1620_LED_Control(LED_SLEEP_MODE,LED_ON);
  
  
  LVI_EN();
  charge_init();


  
  //Ϊ�˱�֤��ȫ����������в��ż��
  sys_init_check();
  

  M26_Wakeup();

  
  //device_get_ccid();

  //m26_fog_service_init();
  
  //M26_Ota_Check();
  
  //next_sync_mstime = 0;
  
  m26_cmd_info.error_times = 0;
  m26_cmd_info.timeout_times = 0;


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
        
          
        
          charge_lefttime_count();         

        
//        mymemset(m26_cmd_info.sendtring,0,sizeof(m26_cmd_info.sendtring));
//        sprintf(m26_cmd_info.sendtring,"1s come\r\n");
//        DEBUG_Uart_Sendbytes(m26_cmd_info.sendtring,strlen(m26_cmd_info.sendtring));
        
          
          display_pm_data(); 
          
             

          Check_If_Close_Door(); 
  
          
          
          m26_signal_check();
          
          if(times_1s % 60 == 0)
          {
                         
          }
          if(times_1s % 5 == 1)
          {
              mymemset(m26_cmd_info.sendtring,0,sizeof(m26_cmd_info.sendtring));
              sprintf(m26_cmd_info.sendtring,"err times:%d,timeout times:%d\r\n",(unsigned int)m26_cmd_info.error_times,(unsigned int)m26_cmd_info.timeout_times);
              DEBUG_Uart_Sendbytes(m26_cmd_info.sendtring,strlen(m26_cmd_info.sendtring));           
          }
          
          if(is_sys_auto_check == 1)
          {
              //TM1620_DispalyData(SENSOR_PM25,sys_check_info.fg_count);
              TM1620_DispalyData(SENSOR_PM25,sys_check_info.fan_check_fault_times);
          }
          
          
          //TM1620_DispalyData(SENSOR_PM25,sys_check_info.fg_count);
          
          //�ֶ�����ʱ�����3�����ڲ�ͨ��APPֹͣ��������Զ�ֹͣ
          if(is_sys_manual_check == 1)
          {
              check_if_stop_manual_check();
          } 
          
          
          //���M26�Ƿ�������m26��������������ĳ�ʼ��
          m26_fogcloud_init_and_check();
          
          
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
         
          m26_http_loop();        
          M26_wait_response(); 
          check_m26_cmd_result();
        
          if(is_upload_auto_check_result == 1)
          {
              sys_check_auto_result_upload();
          }
          if(is_upload_manual_check_result == 1)
          {
              sys_check_manual_result_upload();
          }
        
          //�յ��������upload data,Ȼ������ִ�г���ȷ�ϣ����յ��������check_m26_cmd_result�����иı��� next_upload_data_time��ֵ���Ӷ�ʵ������upload data
          M26_Upload_Data();  
                 
        
          M26_Status_Sync(); 
          
      }   

      if(_test_timeflag(g_100ms_flag))
      {
          g_100ms_flag = 0;
        
          if(is_sys_auto_check == 1)
          {
              sys_dev_auto_check();
          } 
          
//          sys_check_info.fg_count = FGcount;
//          FGcount = 0;
        
          Dcmoto_adj();   
          UV_Check();                 
      }
      
     
  }
}