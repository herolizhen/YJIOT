/**
******************************************************************************
* @file    user_upstream.h 
* @author  herolizhen
* @version V1.0.0
* @date    28- Otc-2016
* @brief   This header contains the uart interfaces for user. 
  operation
******************************************************************************
*/ 

#ifndef __USER_UPSTREAM_H_
#define __USER_UPSTREAM_H_

#include "mico.h"

#include "user_modbus.h"

#define user_upstream_log(M, ...) custom_log("USER_UPSTREAM", M, ##__VA_ARGS__)
#define user_upstream_trace_log() custom_log_trace("USER_UPSTREAM")

 /*******************************************************************************
 * INTERFACES
 ******************************************************************************/

void user_upstream_thread(mico_thread_arg_t arg);
OSStatus upload_dev_data ( unsigned char *recv_0x41_buf, unsigned char *recv_0x45_buf, mico_Context_t* mico_context ) ;
OSStatus upload_door_data (int door_data,mico_Context_t *mico_context );
#endif  // __USER_UART_H_
