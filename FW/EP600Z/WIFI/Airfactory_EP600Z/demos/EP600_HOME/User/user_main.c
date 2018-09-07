/**
******************************************************************************
* @file    user_main.c 
* @author  herolizhen
* @version V1.0.0
* @date    14-May-2016
* @brief   user main functons in user_main thread.
******************************************************************************
*/ 


#include "mico.h"
#include "json_c/json.h"
#include "user_uart.h"
#include "user_modbus.h"
#include "user_config.h"
#include "user_upstream.h"
#include "user_downstream.h"
#include "user_timer.h"
#include "fog_v2_include.h"

#define user_log(M, ...) custom_log("USER", M, ##__VA_ARGS__)
#define user_log_trace() custom_log_trace("USER")



/* user main function, called by AppFramework after system init done && wifi
 * station on in user_main thread.
 */

OSStatus user_main(mico_Context_t* inContext )
{
  user_log_trace();
  OSStatus err = kUnknownErr;
  //unsigned char mqtt_disconnect_times = 0;
  mico_thread_arg_t arg = (mico_thread_arg_t)inContext;
  //UART init
//  mico_thread_msleep(500);
//  err = user_uart_init();
//  require_noerr_action( err, exit, user_log("ERROR: user_uartInit err = %d.", err) );
//    
//  err = get_device_addr();
//  require_noerr_action( err, exit, user_log("ERROR: get_divice_addr err = %d.", err) );
  
  // Start the user_upstream_thread
  err = mico_rtos_create_thread(NULL, MICO_APPLICATION_PRIORITY, "user_upstream", 
                                  user_upstream_thread, STACK_SIZE_USER_UPSTREAM_THREAD, 
                                  arg );
  require_noerr_action( err, exit, user_log("ERROR: create user_uptream thread failed!") );
    // Start the user_downstream_thread
  err = mico_rtos_create_thread(NULL, MICO_APPLICATION_PRIORITY, "user_downstream_thread", 
                                user_downstream_thread, STACK_SIZE_USER_DOWNSTREAM_THREAD, 
                                arg );
  // Start the recv thread for user_uart to recv data from sensor 's  mcu
  
//  err = mico_rtos_create_thread(NULL, MICO_APPLICATION_PRIORITY, "uart_recv_thread", 
//                                uart_recv_thread, STACK_SIZE_UART_RECV_THREAD, 
//                                arg );
//  require_noerr_action( err, exit, user_log("ERROR: create user_uptream thread failed!") );
  
  
    // user timer thread,control wifi led
//  err = mico_rtos_create_thread(NULL, MICO_APPLICATION_PRIORITY, "user_timer", 
//                                set_timer_thread, STACK_SIZE_CHARGE_THREAD, 
//                                arg );
//  require_noerr_action( err, exit, user_log("ERROR: create set_timer_thread failed!") );
  

  // user_main loop, update oled display every 1s
  while(1){
     mico_thread_msleep(1000);

     //when wifi connect,but mqtt disconnet,reboot
     //user_log("is_mqtt_connect=%d", (unsigned char)fog_v2_is_mqtt_connect());
//     if(fog_v2_is_mqtt_connect() == true)
//     {
//         mqtt_disconnect_times = 0;
//     }
//     else
//     {
//         mqtt_disconnect_times += 1;
//         if(mqtt_disconnect_times == 60)
//         {
//             //if after 1min, mqtt still not connect to server,reboot
//             user_log("for 1min,mqtt do not connect to server,reboot");
//             MicoSystemReboot();
//         }
//     }
     
      if(get_wifi_status() == true && fog_v2_is_mqtt_connect() == true)
      {      
        MicoGpioOutputLow((mico_gpio_t)MICO_SYS_LED);     
      }
      else 
      {
        MicoGpioOutputHigh((mico_gpio_t)MICO_SYS_LED);
      }  
  }

exit:
  if(kNoErr != err){
    user_log("ERROR: user_main thread exit with err=%d", err);
  }
  mico_rtos_delete_thread(NULL);  // delete current thread
  return err;
}



