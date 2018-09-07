/**
******************************************************************************
* @file    user_device_control.c
* @author  lixichao
* @version V1.0.0
* @date    4-mar-2016
* @brief   
******************************************************************************
* @attention
*
******************************************************************************
*/ 

#ifndef __USER_FAN_H_
#define __USER_FAN_H_

#include "mico.h"
#include "mico_system.h"


#include "user_uart.h"
#include "user_modbus.h"

#define device_control_user_log(M, ...) custom_log("USER", M, ##__VA_ARGS__)
#define device_control_user_log_trace() custom_log_trace("USER")


typedef struct{

  int sys_mode ;
  int SM_status ; 
  int FA_status ;
  int UV_status ;
  int NI_status ;

}device_status_t;

enum DEVICE_ACTION{
  
  DEVICE_OFF = 0,
  DEVICE_ON  = 1
    
};

/*******************************************************************************
 * INTERFACES
 ******************************************************************************/

 OSStatus execute_fan_val(unsigned int fan_val);
 OSStatus execute_UV_val(unsigned int UV_val);
 OSStatus execute_negative_val(unsigned int negative_val);
 OSStatus execute_door_val ( unsigned int door_val );
 OSStatus execute_fan_status(unsigned int get_fan_status);
 OSStatus execute_EP_val(unsigned int EP_val);
 OSStatus execute_SM_val(unsigned int SM_val);
 OSStatus charge_beep (void);
 void execute_easylink(void);
 void execute_earse_easylink(void);
 
 #endif  // __USER_FAN_H_