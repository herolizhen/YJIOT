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
//OSStatus upload_dev_data (char *json_string,uint8_t save_flag);
OSStatus upload_dev_data (const char *device_id,char *json_string,uint8_t save_flag);
#endif  // __USER_UART_H_
