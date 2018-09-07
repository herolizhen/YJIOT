/**
******************************************************************************
* @file    user_modbus.c 
* @author  herolizhen
* @version V1.0.0
* @date    24-otc-2015
* @brief   
******************************************************************************
* @attention
*
******************************************************************************
*/ 

#ifndef __USER_MODBUS_H_
#define __USER_MODBUS_H_



#include "user_uart.h"
#include "user_device_control.h"
#include "system_internal.h"

#define  MODBUS_TRY_COUNT         20
#define  MODBUS_SLEEP_MS          100
#define  RECEIVE_BUFFER_LENGTH    128
//#define  DATA_LENGTH_0x41         53
#define  DATA_LENGTH_0x41         50
#define  DATA_LENGTH_0x44         10
#define  DATA_LENGTH_0x45         25

#define  UPLOAD_TRY_COUNT                 60   // every time is 5s   so   60*5s = 3min


#define user_modbus_log(M, ...) custom_log("USER", M, ##__VA_ARGS__)
#define user_modbus_log_trace() custom_log_trace("USER")
/*******************************************************************************
 * INTERFACES
 ******************************************************************************/

OSStatus get_device_addr(void);
OSStatus f_0x41_04_cmd(void);
OSStatus f_0x45_cmd(void);
OSStatus f_0x41_04_data(unsigned char *recv_buf, mico_Context_t* mico_context);
OSStatus f_0x45_data(unsigned char *recv_buf,mico_Context_t* mico_context);
OSStatus f_0x49_data(unsigned char *recv_buf,mico_Context_t* mico_context);
OSStatus f_0x49_04_data(unsigned char *recv_buf, system_context_t * const inContext);
OSStatus f_0x49_06_data ( unsigned char *recv_buf, system_context_t * const inContext );
OSStatus f_0x49_08_01_cmd (void);
OSStatus f_0x49_08_02_cmd (void);
OSStatus f_0x49_08_03_cmd (void);
OSStatus f_0x49_08_04_cmd (void);
OSStatus f_0x49_08_data ( unsigned char *recv_buf, system_context_t * const inContext );
OSStatus data_process(unsigned char  *inBuf, mico_Context_t* mico_context);
void frame_data ( unsigned char  *inBuf, int inLen , mico_Context_t* mico_context ) ;
#endif  // __USER_MODBUS_H_
