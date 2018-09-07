#include "user_timer.h"
#include "user_modbus.h"
#include "fog_v2_include.h"
#include "mico.h"



user_set_timer_t user_set_timer;
user_upload_timer_t user_upload_timer;


/*
void set_timer_thread(mico_thread_arg_t arg)
{
  static const unsigned long wifi_check_time_interval = 2000;
  static unsigned long next_check_trigger = 0;
  
  unsigned long nowtime = 0;
  
  user_set_timer.type = -1;
  user_set_timer.set_time = -1;
  
  user_upload_timer.type = 0;
  user_upload_timer.set_time = 0;
  user_upload_timer.left_time = 0;
  
  next_check_trigger = mico_rtos_get_time() + wifi_check_time_interval;
  
  while(1) {

    if(user_set_timer.type == 0 || user_set_timer.type == 1)
    {
      if(user_set_timer.set_time >= 0)
      {
        user_set_timer_cmd(user_set_timer.type,user_set_timer.set_time);
        mico_thread_msleep(1500);
      }
    }
    
    nowtime = mico_rtos_get_time();
    if(next_check_trigger > 0xF0000000 && nowtime <= 0xF0000000 )
    {
      //time overflow
      next_check_trigger = nowtime;
    }
    
    if(nowtime >= next_check_trigger)
    {
      if(get_wifi_status() == true && fog_v2_is_mqtt_connect() == true)
      {      
        MicoGpioOutputLow((mico_gpio_t)MICO_SYS_LED);     
      }
      else 
      {
        MicoGpioOutputHigh((mico_gpio_t)MICO_SYS_LED);
      }  
      
      next_check_trigger = nowtime + wifi_check_time_interval;
    }

    
    mico_thread_msleep(100);
  }
}
*/

