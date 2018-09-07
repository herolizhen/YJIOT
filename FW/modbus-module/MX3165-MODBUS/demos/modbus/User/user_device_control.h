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

#ifndef __USER_DEVICE_CONTROL_H__
#define __USER_DEVICE_CONTROL_H__

#include "mico.h"
#include "mico_system.h"


#define device_control_user_log(M, ...) custom_log("USER", M, ##__VA_ARGS__)
#define device_control_user_log_trace() custom_log_trace("USER")


/*******************************************************************************
 * INTERFACES
 ******************************************************************************/


 void execute_easylink(void);
 void execute_earse_easylink(void);
 
 #endif  // __USER_FAN_H_