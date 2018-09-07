#include "mico.h"
#include "user_downstream.h"
#include "fog_v2_include.h"
#include "micokit_ext.h"
#include "user_upstream.h"
#include "user_uart.h"
#include "user_uart_data_process.h"
#include "fog_mqtt.h"

#define MCU_RES_DATA_MAX_LENGTH   100


//#define FOG_V2_RECV_BUFF_LEN 100

extern modbus_devs_t modbus_devs;

extern bool get_wifi_status(void);



/* Handle user message from cloud
 * Receive msg from cloud && do hardware operation, like rgbled
 */
void user_downstream_thread(mico_thread_arg_t arg)
{ 
  OSStatus err = kUnknownErr;
  uint8_t res = 0;
  mqtt_msg_t *recv_msg = NULL;  
  uint8_t *mcu_res_databuff = NULL;
  uint8_t mcu_res_length = 0;
  
  mico_Context_t *mico_context = (mico_Context_t *)arg;
  require(mico_context, exit);
  
  recv_msg = malloc( sizeof(mqtt_msg_t) );
  require( recv_msg != NULL, exit );
  while(1) {    
    mico_thread_msleep(200);
    
    // check fogcloud connect status
    if(get_wifi_status() == false || fog_v2_is_mqtt_connect() == false) {
      continue;
    }
    //err = fog_v2_device_recv_command( recv_msg, FOG_V2_RECV_BUFF_LEN, MICO_NEVER_TIMEOUT );
    err = fog_v2_device_recv_mqtt_message(recv_msg,MAX_TOPIC_LENGTH,MAX_PAYLOAD_LENGTH,MICO_NEVER_TIMEOUT);  
    if(kNoErr == err) {   
      user_downstream_log("recv topic:%s", recv_msg->topic);
      user_downstream_log("recv payload:%s", recv_msg->payload);
          
      //user_uart_send((unsigned char *)recv_msg,strlen(recv_msg));
      
      mcu_res_databuff = malloc(MCU_RES_DATA_MAX_LENGTH);
      res = parse_mqtt_msg(recv_msg,mcu_res_databuff,MCU_RES_DATA_MAX_LENGTH,&mcu_res_length);
      if(res == 0)
      {
          uart_printf_array("mcu res",mcu_res_databuff,mcu_res_length);
      }
      
      if(mcu_res_databuff != NULL)
      {
          free(mcu_res_databuff);
          mcu_res_databuff = NULL;
      }
      
      memset(recv_msg, 0, sizeof(mqtt_msg_t));
    }

  }
exit:
  if(recv_msg != NULL)
  {
    free(recv_msg);
    recv_msg = NULL;
  }

  user_downstream_log("ERROR: user_downstream_thread exit with err=%d", err);
}


extern mqtt_context_t *mqtt_context;
//功能：从云端接收数据
//参数： payload - 接收数据缓冲区地址
//参数： payload_len - 接收数据缓冲区地址的长度
//参数： timeout - 接收数据等待时间
//返回值：kNoErr为成功 其他值为失败
OSStatus fog_v2_device_recv_mqtt_message(mqtt_msg_t *p_mqtt_msg,uint16_t topic_len,uint16_t payload_len,uint32_t timeout )
{
    OSStatus err = kUnknownErr;
    p_mqtt_recv_msg_t p_recv_msg = NULL;

    require_action( mqtt_context != NULL, exit, err = kGeneralErr );
    require_action( p_mqtt_msg != NULL, exit, err = kGeneralErr );

    memset(p_mqtt_msg, 0, sizeof(mqtt_msg_t));

    // get msg from recv queue
    err = mico_rtos_pop_from_queue( &(mqtt_context->mqtt_msg_recv_queue), &p_recv_msg, timeout );
    require_noerr( err, exit );

    if ( p_recv_msg )
    {
        //app_log("user get data success! from_topic=[%s], msg=[%d][%s].", p_recv_msg->topic, p_recv_msg->datalen, p_recv_msg->data);

        //require_action( topic_len > strlen(p_recv_msg->topic), exit, err = kGeneralErr );
        //require_action( payload_len > p_recv_msg->datalen, exit, err = kGeneralErr );
    
        if(topic_len < strlen(p_recv_msg->topic))
        {
            user_downstream_log("topic too long: %s", p_recv_msg->topic);
            goto exit;
        }
    
        if(payload_len < p_recv_msg->datalen)
        {
            user_downstream_log("payload too long: %s", p_recv_msg->data);
            goto exit;
        }

        memcpy( p_mqtt_msg->topic, p_recv_msg->topic, strlen(p_recv_msg->topic) );
        memcpy( p_mqtt_msg->payload, p_recv_msg->data, p_recv_msg->datalen );

        //user_downstream_log("[RECV] topic: %s", p_recv_msg->topic);
        //user_downstream_log("[RECV] payload: %s", p_recv_msg->data);

        // release msg mem resource
        free( p_recv_msg );
        p_recv_msg = NULL;
    } else
    {
        user_downstream_log("[RECV] ERROR!");
    }

    exit:
    return err;
}

#define MAX_DATA_NUM   8
OSStatus parse_mqtt_msg(const mqtt_msg_t *p_mqtt_msg,uint8_t *mcu_res_buff,uint8_t max_length,uint8_t *res_buff_length)
{
    OSStatus err = 1;
    uint8_t i = 0;
    json_object *recv_json_object = NULL;
    int key_value = 0;
    int cmd = -1;
    int op_type = -1;
    int addr = -1;
    int quantity = -1;
    uint16_t *pdata = NULL;
    uint8_t get_data_num = 0;
    wifi_to_mcu_cmd_t wifi_to_mcu_cmd = {0};
    uint8_t res = 0;
    
    pdata = malloc(sizeof(uint16_t) * MAX_DATA_NUM);
    if(pdata == NULL)
    {
        user_downstream_log("malloc pdata fail");
        err = 1;
        goto exit;
    }
    
    for(i = 0;i < modbus_devs.dev_nums;i++)
    {
        if(strstr(p_mqtt_msg->topic,modbus_devs.devices[i]->device_id) != NULL)
        {
            wifi_to_mcu_cmd.slave = i;
            break;
        }
    }
    
    if(i >= modbus_devs.dev_nums)
    {
        user_downstream_log("not find device via topic");
        err = 2;
        goto exit;
    }
    
    recv_json_object = json_tokener_parse(p_mqtt_msg->payload);
    if (NULL != recv_json_object) {
        json_object_object_foreach(recv_json_object, key, val)
        {
            key_value = json_object_get_int(val);     
            if(!strcmp(key, "CMD"))
            {
                cmd = key_value;
            }
            else if(!strcmp(key, "OTP"))     //operate type:coil or register
            {
                op_type = key_value;     
            }
            else if(!strcmp(key, "ADDR"))
            {
                addr = key_value;     
            }
            else if(!strcmp(key, "QTY"))
            {
                quantity = key_value;     
            }
            else if(!strcmp(key, "DATA0"))
            {
                pdata[0] = (uint16_t)key_value;
                get_data_num += 1;
            }
            else if(!strcmp(key, "DATA1"))
            {
                pdata[1] = (uint16_t)key_value;
                get_data_num += 1;
            }
            else if(!strcmp(key, "DATA2"))
            {
                pdata[2] = (uint16_t)key_value;
                get_data_num += 1;
            }
            else if(!strcmp(key, "DATA3"))
            {
                pdata[3] = (uint16_t)key_value;
                get_data_num += 1;
            }
            else if(!strcmp(key, "DATA4"))
            {
                pdata[4] = (uint16_t)key_value;
                get_data_num += 1;
            }
            else if(!strcmp(key, "DATA5"))
            {
                pdata[5] = (uint16_t)key_value;
                get_data_num += 1;
            }
            else if(!strcmp(key, "DATA6"))
            {
                pdata[6] = (uint16_t)key_value;
                get_data_num += 1;
            }
            else if(!strcmp(key, "DATA7"))
            {
                pdata[7] = (uint16_t)key_value;
                get_data_num += 1;
            }            
        }
    }else{
        user_downstream_log("Do not get date from fogcloud!");
        err = 3;
        goto exit;
    }
    
    if(cmd == cmd_read)
    {
        if(addr < 0)
        {
            user_downstream_log("addr error:%d",addr);
            err = 4;
            goto exit;
        }
        
        if(op_type == coil_type || op_type == reg_type)
        {
            if(op_type == coil_type)
            {
                wifi_to_mcu_cmd.func = 0x10;
            }
            else
            {
                wifi_to_mcu_cmd.func = 0x12;
            }
            wifi_to_mcu_cmd.addr = addr;
            wifi_to_mcu_cmd.quantity = quantity;
        }
        else
        {
            user_downstream_log("read type code err,type = %d",op_type);
            err = 5;
            goto exit;
        }
    }
    else if(cmd == cmd_write)
    {
        if(addr < 0)
        {
            user_downstream_log("addr error:%d",addr);
            err = 6;
            goto exit;
        }
        
        if(op_type == coil_type || op_type == reg_type)
        {
            if(op_type == coil_type)
            {
                wifi_to_mcu_cmd.func = 0x11;   
                if(get_data_num != 1)
                {
                    user_downstream_log("get_data_num != 1,get_data_num = %d",get_data_num);
                    err = 7;
                    goto exit;
                }
            }
            else
            {
                wifi_to_mcu_cmd.func = 0x13;
                if(get_data_num != quantity)
                {
                    user_downstream_log("get_data_num != quantity,get_data_num = %d",get_data_num);
                    err = 8;
                    goto exit;
                }
            }
            
            wifi_to_mcu_cmd.addr = addr;
            wifi_to_mcu_cmd.quantity = quantity;
            wifi_to_mcu_cmd.databuff = pdata;
        }
        else
        {
            user_downstream_log("write type code err,type = %d",op_type);
            err = 9;
            goto exit;
        }
    }
    else
    {
        user_downstream_log("wifi cmd error,cmd = %d",cmd);
        err = 10;
        goto exit;
    }
    
    res = wifi_send_data_to_mcu_event(&wifi_to_mcu_cmd,mcu_res_buff,max_length,res_buff_length);
    if(res != 0)
    {
        user_downstream_log("wifi cmd fail");
        err = 11;
        goto exit;
    }
    
    err = 0;
    
exit:    
    if(recv_json_object != NULL)
    {
      json_object_put(recv_json_object);
      recv_json_object = NULL;
    }
    
    if(pdata != NULL)
    {
        free(pdata);
        pdata = NULL;
    }
    
    return err;
      
}


