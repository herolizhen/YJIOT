/**
******************************************************************************
* @file    user_downstream.h
* @author  herolizhen
* @version V1.0.0
* @date    4-mar-2016
* @brief   
******************************************************************************
*/ 
#ifndef __USER_DOWNSTREAM_H_
#define __USER_DOWNSTREAM_H_

#include "mico.h"

#include "user_device_control.h"

#define user_downstream_log(M, ...) custom_log("USER_DOWNSTREAM", M, ##__VA_ARGS__)
#define user_downstream_log_trace() custom_log_trace("USER_DOWNSTREAM")

/*******************************************************************************
 * INTERFACES
 ******************************************************************************/
 
void user_downstream_thread(mico_thread_arg_t arg);
 
#endif  // __USER_FAN_H_