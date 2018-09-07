#include "OB39A08T1.h"
#include "led.h"
#include "global.h"
#include "INTRINS.H"
#include "timer.h"
#include "touch.h"



extern KEY_INFO_Typedef key_info;

extern LED_BLINK_Typedef led_blink_info;


//========================================================================================================
//  Command Read Format:
//  Start    -> Slave(W) -> Ack -> Command -> Ack ->
//  Re-Start -> Slave(R) -> Ack -> STATUS2 -> Ack -> STATUS1 -> Ack -> STATUS0 -> NAck -> Stop
//
//  Touch Slave(W) Address = 0x60
//  Touch Slave(R) Address = 0x61
//  Read Key Status Command Number = 0x17
//
//  [Master Example]  
//  Start    ->  0x60(W) -> Ack ->  0x17   -> Ack ->
//  Re-Start ->  0x61(R) -> Ack -> STATUS2 -> Ack -> STATUS1 -> Ack -> STATUS0 -> NAck -> Stop
//========================================================================================================

void IIC_ISR(void) interrupt 13 using 2
{
    ((void(code*)(void))0x2600)();      //IIC ISR Function
}

void WDT_ISR(void) interrupt 17 using 3
{
    ((void(code*)(void))0x2500)();      //WDT ISR Function
}

void TOUCH_ISR(void) interrupt 19 using 1
{
    ((void(code*)(void))0x3000)();      //Touch ISR Function
}

void INT0_ISR(void) interrupt 0
{
    ((void(code*)(void))0x2580)();      //INT0 ISR Function
}

void Global_Data_Init(void)
{
    led_blink_info.ledstate = LED_NONE;
}

void main(void)
{
    //unsigned char touch_status_0,touch_status_1,touch_status_2 = 0; 
    unsigned char pinstatus = 0;  
  
    ((void(code*)(unsigned char))0x24D0)(0x00);      //Select IIC interface for P3.2&P3.3
    ((void(code*)(void))0x2340)();                   //Touch initial
    LVC&=0x7C;
  
    Global_Data_Init();
   
    Led_Pin_Config();
    //Led_Control(LED_ALL,LED_ON);
    
    Start_Timer0();
    
    while(1)
    {
        ((void(code*)(void))0x21F0)();  //Touch Normal Run
        //LedBlink(LED_POWER_PORTBIT);
      
//        if(_test_timeflag(g_10ms_flag))	
//        {
//            
//            
//            g_10ms_flag = 0;
//        }
//      
//        if(_test_timeflag(g_1000ms_flag))	
//        {
//            pinstatus = !pinstatus;
//            LED_POWER_PIN = pinstatus;
//            g_1000ms_flag = 0;
//        }
          
      
//          if(_test_timeflag(g_10ms_flag))
//          {
//              g_10ms_flag = 0;
//              Scan_TouchPad();  
//              LedBlink();            
//          }
          
          if(_test_timeflag(g_2ms_flag))
          {
              g_2ms_flag = 0;
              Scan_TouchPad();  
              LedBlink();            
          }
         
        
    }
}
