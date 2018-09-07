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
#define MAX_TOPIC_LENGTH  100
#define MAX_PAYLOAD_LENGTH  256

typedef struct{

  char topic[MAX_TOPIC_LENGTH];
  char payload[MAX_PAYLOAD_LENGTH];
  //uint16_t length;

}mqtt_msg_t;

enum wifi_cmd_t{
  
  cmd_read    = 1,
  cmd_write   = 2

};

enum op_type_t{
  
  coil_type    = 1,
  reg_type     = 2

};

 
void user_downstream_thread(mico_thread_arg_t arg);

OSStatus fog_v2_device_recv_mqtt_message(mqtt_msg_t *p_mqtt_msg,uint16_t topic_len,uint16_t payload_len,uint32_t timeout );
OSStatus parse_mqtt_msg(const mqtt_msg_t *p_mqtt_msg,uint8_t *mcu_res_buff,uint8_t max_length,uint8_t *res_buff_length);
 
#endif  // __USER_FAN_H_