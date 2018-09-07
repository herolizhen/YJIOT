#include <stdio.h>
#include <string.h>
#include "user_timer.h"
#include "global.h"
#include "timer.h"
#include "wifi_uart.h"
//#include "common.h"
#include "debug_uart.h"
#include "touch_key.h"
#include "sys_run.h"
#include "TM1620.h"

user_timer_t user_timer_info;

void user_timer_init(void)
{
    user_timer_info.user_timer_start = 0;
    user_timer_info.timer_state = 0;
    user_timer_info.set_time = 0;
    user_timer_info.left_time = 0;
}

void user_timer_count(void)
{
   const unsigned long min_to_ms = 60000;
   static unsigned long time_triger = 0;
   unsigned long nowtime = 0;
   unsigned char debug_buff[30] = {0};
  
   nowtime = get_sys_mstime();
   if(nowtime <= 0xF0000000 && time_triger > 0xF0000000 )
   {
       //·ÀÖ¹Ê±¼äÒç³ö
       time_triger = nowtime + min_to_ms;
   }
   
   if(user_timer_info.user_timer_start == 1)
   {
       //time_triger = nowtime + (MIN_TO_MS | 0x00);
       time_triger = nowtime + min_to_ms;
       user_timer_info.user_timer_start = 0;
   }
   
   if(nowtime >= time_triger)
   {
      if(user_timer_info.left_time > 0)
      {
          user_timer_info.left_time -= 1;
        
//          mymemset(debug_buff,0,sizeof(debug_buff));
//          sprintf(debug_buff,"lefttime:%d\r\n",(unsigned int)user_timer_info.left_time);
//          DEBUG_Uart_Sendbytes(debug_buff,strlen(debug_buff)); 
      }
      if(user_timer_info.left_time == 0)
      {
          if(sys_mode == RUNNING)
          {
              sys_stop(); 
          }
      }
      //time_triger = time_triger + (MIN_TO_MS | 0x00);
      time_triger = time_triger + min_to_ms;
   }
}


void stop_user_timer(void)
{
    user_timer_info.user_timer_start = 0;
    user_timer_info.timer_state = 0;
    user_timer_info.set_time = 0;
    user_timer_info.left_time = 0;
  
    if(user_timer_type == USER_TIMER_2H)
    {
        TM1620_LED_Control(LED_TIMER_2H,LED_OFF);
    }
    else if(user_timer_type == USER_TIMER_4H)
    {
        TM1620_LED_Control(LED_TIMER_4H,LED_OFF);
    }
  
    user_timer_type = USER_TIMER_NONE;
}

void set_user_timer(unsigned char timer_type)
{
    if(timer_type > USER_TIMER_4H || timer_type < 0)
    {
        return;
    }
    
    if(timer_type == USER_TIMER_NONE)
    {
        stop_user_timer();
    }
    else
    {
        user_timer_info.user_timer_start = 1;
        user_timer_info.timer_state = 1;
      
        if(timer_type == USER_TIMER_2H)
        {
            user_timer_info.set_time = 120;
            TM1620_LED_Control(LED_TIMER_2H,LED_ON);
        }
        else if(timer_type == USER_TIMER_4H)
        {
            user_timer_info.set_time = 240;
            TM1620_LED_Control(LED_TIMER_4H,LED_ON);
        }
        user_timer_info.left_time = user_timer_info.set_time;    
    }          
}


