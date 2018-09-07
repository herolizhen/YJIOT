/**
******************************************************************************
* @file    user_downstream.c
* @author  herolizhen
* @version V1.0.0
* @date    14-May-2015
* @brief   user main functons in user_main thread.
******************************************************************************
*/
#include "mico.h"
#include "user_downstream.h"
#include "fog_v2_include.h"
#include "micokit_ext.h"
#include "user_charge.h"
#include "user_upstream.h"
#include "user_device_check.h"

#define FOG_V2_RECV_BUFF_LEN 100

char last_ordno[50] = {0};

#define DOOR_CHECK_TIME  7000
volatile unsigned long last_open_door_time = 0;

//http是否获得开仓门指令，如果获得则上传数据改为5秒钟一次
volatile unsigned char is_http_get_dr_cmd = 0;
extern volatile unsigned char dr_upload_data_time_control;

extern bool get_wifi_status(void);

extern device_check_t device_check;

/* Handle user message from cloud
 * Receive msg from cloud && do hardware operation, like rgbled
 */
void user_downstream_thread(mico_thread_arg_t arg)
{

  unsigned long nowtime = 0;
  char ordno[50] = {0};
  
  OSStatus err = kUnknownErr;

  char *recv_msg = NULL;
  //char jons_data[100] = {0};
  //unsigned int recv_msg_length = 0;
  //int i ,j = 0;
  int temp_charge_time = -1;
  int charge_type = -1;
  int charge_status = 0;
  int check_type = -1;
  int check_state = -1;
  
  json_object *recv_json_object = NULL;
  
  mico_Context_t *mico_context = (mico_Context_t *)arg;
  require(mico_context, exit);
  recv_msg = malloc( FOG_V2_RECV_BUFF_LEN );
  require( recv_msg != NULL, exit );
  while(1) {
    memset(recv_msg, 0, FOG_V2_RECV_BUFF_LEN);
    
    //memset(jons_data, 0, sizeof(jons_data));
    //recv_msg_length = 0;
    
    mico_thread_msleep(200);
    
    // check fogcloud connect status
    if(get_wifi_status() == false || fog_v2_is_mqtt_connect() == false) {
      continue;
    }
    err = fog_v2_device_recv_command( recv_msg, FOG_V2_RECV_BUFF_LEN, MICO_NEVER_TIMEOUT );
    
    //continue;
    
    //err = MiCOFogCloudMsgRecv(app_context, &recv_msg, 100);
    if(kNoErr == err) {
      // debug log in MICO dubug uart
      
      user_downstream_log("user_downstream_thread recv:%s", recv_msg);
      
      
      /*
      if(*recv_msg != 0 && *(recv_msg+1) != 0){
            //user_downstream_log("Cloud => Module: %s",recv_msg);
          //user_downstream_log("user_downstream_thread recv:%s", recv_msg);
        
          if(*(recv_msg + 10) == '\\' && strncmp(recv_msg + 2,"data",4) == 0)
          {
              recv_msg_length = strlen(recv_msg);
              printf("recv_msg_length = %d\n",recv_msg_length);
          
              strcpy(jons_data,recv_msg + 9);
          
              jons_data[strlen(jons_data) -2] = '\0';
          
              printf("jons_data:%s",jons_data);
          
              i = 0;
              j = 0;
              while(*(jons_data + i) != '\0')
              {
                  if(*(jons_data + i) == '\\')
                  {
                      j = i;
                      while(*(jons_data + j) != '\0')
                      {
                        *(jons_data + j) = *(jons_data + j + 1);
                        j += 1;
                      }             
                  }
              
                  i += 1;

              }
                 
              printf("jons_data:%s\n",jons_data);            
          }
          else 
          {
              strcpy(jons_data,recv_msg);
              //jons_data[strlen(jons_data) -2] = '\0';
          }         
      }
      */
     
      
      
      // parse json data from the msg, get led control value
      //recv_json_object = json_tokener_parse((const char*)(jons_data));
      recv_json_object = json_tokener_parse((const char*)(recv_msg));
      if (NULL != recv_json_object) {
        int key_value = 0;
        json_object_object_foreach(recv_json_object, key, val)
        {
            //计费功能设置
          if(!strcmp(key, "ORDERNO"))
          {           
              memset(ordno,0,sizeof(ordno));   
              strcpy(ordno,json_object_get_string(val));
              user_downstream_log("ordno:%s", ordno);
          }
          else if(!strcmp(key, "EXAMID"))
          {           
              memset(device_check.check_id,0,sizeof(device_check.check_id));   
              strcpy(device_check.check_id,json_object_get_string(val));
              user_downstream_log("device_check.check_id:%s", device_check.check_id);
          }
          else
          {
            key_value = json_object_get_int(val);        
            if(!strcmp(key, "FA")) {
              execute_fan_val(key_value);
            }
            else if(!strcmp(key, "UV")) {
              execute_UV_val(key_value);
            }
            else if(!strcmp(key, "NI")) {
              execute_negative_val(key_value);
            }
            else if(!strcmp(key, "DR")) {
              if(key_value == 1)
              {
                is_http_get_dr_cmd = 1;
                nowtime = mico_rtos_get_time();
                if(nowtime < last_open_door_time || nowtime >= (last_open_door_time + DOOR_CHECK_TIME))
                {
                  //时间溢出了，正常情况下mico_rtos_get_time() > last_open_door_time
                  last_open_door_time = nowtime;
                  upload_door_data(key_value,NULL);
                  execute_door_val(key_value);
                  
                }        
              }            
            }
            else if(!strcmp(key, "AF")) {
              execute_fan_status(key_value);
            }
            else if(!strcmp(key, "EP")) {
            //系统设备风机 UV等关闭，待机和打开的控制
              user_downstream_log("download key: EP,value:%d",key_value);
              execute_EP_val(key_value);
            }
            else if(!strcmp(key, "SM")) {
              //共享模式不支持自动模式
              execute_SM_val(key_value);
            }   
            else if(!strcmp(key, "EARSE"))
            {
              charge_flash_erase(LEFT_TIME_ADDR_BASE,RECORD_ADDR_BASE + LEFT_TIME_MAX_OFFSET);
              stop_charge_mode();
            }
            else if(!strcmp(key, "CHIPS")) {
              if(key_value >= 0)
              {
                temp_charge_time = key_value;
              }
              
            }
            else if(!strcmp(key, "TYPE")) {
              charge_type = key_value;
            }
            else if(!strcmp(key, "STATUS")) {
              charge_status = key_value;
            }
            else if(!strcmp(key, "EXAMTYPE")) {
              check_type = key_value;
            }
            else if(!strcmp(key, "EXAMSTATE")) {
              check_state = key_value;
            }
//            else if(!strcmp(key, "ACKS")) {
//              f_0x49_08_01_cmd();
//            }
//            else if(!strcmp(key, "ACKP")) {
//              f_0x49_08_02_cmd();
//            }
//            else if(!strcmp(key, "MCKS")) {
//              f_0x49_08_03_cmd();
//            }
//            else if(!strcmp(key, "MCKP")) {
//              f_0x49_08_04_cmd();
//            }
          }
         

        }
        
        if((check_state == 0 || check_state == 1) && (check_type == 1 || check_type == 2))
        {
          
//          device_check.check_type = (char)check_type;
//          device_check.check_state = (char)check_state;
//          
//          if(device_check.check_state == 0)   //停止
//          {
//            if(device_check.check_type == auto_check)
//            {
//              //停止自动检测
//              f_0x49_08_02_cmd();
//              user_downstream_log("stop auto check");
//            }
//            else if(device_check.check_type == man_check)
//            {
//              //停止手动检测
//              f_0x49_08_04_cmd();
//              user_downstream_log("stop manul check");
//            }        
//          }
//          else if(device_check.check_state == 1)   //开始
//          {          
//            if(device_check.check_type == auto_check)
//            {
//              //开始自动检测
//              f_0x49_08_01_cmd();
//              user_downstream_log("start auto check");
//            }
//            else if(device_check.check_type == man_check)
//            {
//              //开始手动检测
//              f_0x49_08_03_cmd();
//              user_downstream_log("start manul check");
//            }
//          }
          
          
          if(check_state == 0)   //停止
          {
            if(check_type == auto_check)
            {
              //停止自动检测
              f_0x49_08_02_cmd();
              user_downstream_log("stop auto check");
            }
            else if(check_type == man_check)
            {
              //停止手动检测
              f_0x49_08_04_cmd();
              user_downstream_log("stop manul check");
            }        
          }
          else if(check_state == 1)   //开始
          {          
            if(check_type == auto_check)
            {
              //开始自动检测
              f_0x49_08_01_cmd();
              user_downstream_log("start auto check");
            }
            else if(check_type == man_check)
            {
              //开始手动检测
              f_0x49_08_03_cmd();
              user_downstream_log("start manul check");
            }
          }
          
          check_type = -1;
          check_state = -1;
        }

        
        if(temp_charge_time != -1)
        {
            charge_info_confirm(ordno,1,temp_charge_time);
        }
        
        
        if(strcmp(ordno,last_ordno) != 0 && charge_status == 1)
        {
          if(charge_type != -1 && temp_charge_time != -1)
          {    
            //控制蜂鸣器响一声
            charge_beep();
            
            updata_charge_timedata(ordno,(char)charge_type,(unsigned long)temp_charge_time);
            charge_type = -1;
            temp_charge_time = -1;
            charge_status = 0;
          
            memset(last_ordno,0,sizeof(last_ordno));
            strcpy(last_ordno,ordno);
            //打开设备
            //execute_EP_val(1);
          }        
        }

      }
      else {
        user_downstream_log("Do not get date from fogcloud!");
      }
    }

   // free memory of json object
    if(recv_json_object != NULL)
    {
      json_object_put(recv_json_object);
      recv_json_object = NULL;
    }
    
    if(temp_charge_time != -1)
    {
        temp_charge_time = -1;
    }

  }
exit:
  if(recv_json_object != NULL)
  {
    json_object_put(recv_json_object);
    recv_json_object = NULL;
  }
  if(recv_msg != NULL)
  {
    free(recv_msg);
    recv_msg = NULL;
  }

  user_downstream_log("ERROR: user_downstream_thread exit with err=%d", err);
}



//解析返回结果 
OSStatus user_process_response_body(const char *http_body, int32_t *code)
{
    int temp_charge_time = -1;
    int charge_type = -1;
    int charge_status = 0;
    int key_value = 0;
    char ordno[50] = {0};
    unsigned long nowtime = 0;
    unsigned char is_get_ordernum = 0;
    unsigned char is_get_dr_cmd = 0;
    
    OSStatus err = kGeneralErr;
    json_object *http_body_json_obj = NULL;
    json_object *data_json_obj = NULL;

    require_string(http_body != NULL, exit, "body is NULL ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");

    require_string(((*http_body == '{') && (*(http_body + strlen(http_body) - 1) == '}')), exit, "http body JSON format error");

    http_body_json_obj = json_tokener_parse(http_body);
    //    require_string(http_body_json_obj != NULL, exit, "json_tokener_parse error");
    if(http_body_json_obj == NULL)
    {
        user_downstream_log("http_body_json_obj == NULL");
        err = kGeneralErr;
        goto exit;
    }
    else
    {
        data_json_obj = json_object_object_get(http_body_json_obj, "data");
        if(data_json_obj == NULL)
        {
            goto exit;
        }

        json_object_object_foreach(data_json_obj, key, val)
        {
            //计费功能设置
          if(!strcmp(key, "orderInfo"))
          { 
            
            json_object_object_foreach(val, key_charge, val_charge)
            {
            
                if(!strcmp(key_charge, "orderNo"))
                {
                  is_get_ordernum = 1;
                  
                  memset(ordno,0,sizeof(ordno));   
                  strcpy(ordno,json_object_get_string(val_charge));
                  user_downstream_log("ordno:%s", ordno);              
                }
                else
                {
                    key_value = json_object_get_int(val_charge);
                    
                    if(!strcmp(key_charge,"chips")) {
                      if(key_value >= 0)
                      {
                        temp_charge_time = key_value;
                      }
              
                    }
                    else if(!strcmp(key_charge,"type")) {
                        charge_type = key_value;
                    }
                    else if(!strcmp(key_charge,"status")) {
                      charge_status = key_value;
                    } 
            
                }           
            }
          }
          else if(!strcmp(key, "statusInfo"))
          {
            json_object_object_foreach(val, key_charge, val_charge)
            {
              key_value = json_object_get_int(val_charge);        
              if(!strcmp(key_charge, "FA")) {
                execute_fan_val(key_value);
              }
              else if(!strcmp(key_charge,"UV")) {
                execute_UV_val(key_value);
              }
              else if(!strcmp(key_charge,"NI")) {
                execute_negative_val(key_value);
              }
              else if(!strcmp(key_charge,"DR")) {
                
                is_get_dr_cmd = 1;
                is_http_get_dr_cmd = 1;
                dr_upload_data_time_control = 0;
                
                
//                if(key_value == 1)
//                {
//                  nowtime = mico_rtos_get_time();
//                  if(nowtime < last_open_door_time || nowtime >= (last_open_door_time + DOOR_CHECK_TIME))
//                  {
//                    //时间溢出了，正常情况下mico_rtos_get_time() > last_open_door_time
//                    last_open_door_time = nowtime;                   
//                    execute_door_val(key_value);
//                      upload_door_data(key_value,NULL);
//                  
//                  }
//                  else
//                  {
//                    user_downstream_log("nowtime < last_open_door_time + DOOR_CHECK_TIME,do not deal");
//                  }
//               }                
              }
              else if(!strcmp(key_charge,"AF")) {
                execute_fan_status(key_value);
              }
              else if(!strcmp(key_charge,"EP")) {
                //系统设备风机 UV等关闭，待机和打开的控制
                user_downstream_log("download key: EP,value:%d",key_value);
                execute_EP_val(key_value);
              }
              else if(!strcmp(key_charge,"SM")) {
                execute_SM_val(key_value);
              }   
              else if(!strcmp(key_charge,"EARSE")){
                charge_flash_erase(LEFT_TIME_ADDR_BASE,RECORD_ADDR_BASE + LEFT_TIME_MAX_OFFSET);
                stop_charge_mode();
              }           
            }

          }
         

        }
        
        if(is_get_ordernum == 0 && is_get_dr_cmd == 1)
        {
            nowtime = mico_rtos_get_time();
            if(nowtime < last_open_door_time || nowtime >= (last_open_door_time + DOOR_CHECK_TIME))
            {
              last_open_door_time = nowtime;                   
              execute_door_val(key_value);
              upload_door_data(1,NULL);
            }
            else
            {
              user_downstream_log("nowtime < last_open_door_time + DOOR_CHECK_TIME,do not deal");
            }
            
        }
        
        
        if(temp_charge_time != -1)
        {
            charge_info_confirm(ordno,1,temp_charge_time);
        }
        

        
        
        if(strcmp(ordno,last_ordno) != 0 && charge_status == 1)
        {
          if(charge_type != -1 && temp_charge_time != -1)
          {    
            //控制蜂鸣器响一声
            charge_beep();
            
            updata_charge_timedata(ordno,(char)charge_type,(unsigned long)temp_charge_time);
            charge_type = -1;
            temp_charge_time = -1;
            charge_status = 0;
          
            memset(last_ordno,0,sizeof(last_ordno));
            strcpy(last_ordno,ordno);
            
            //打开设备
            //execute_EP_val(1);
          }        
        }    
    }


    err = kNoErr;

 exit:
    if(data_json_obj != NULL)
    {
        json_object_put(data_json_obj);
        data_json_obj = NULL;
    }
    if(http_body_json_obj != NULL)
    {
        json_object_put(http_body_json_obj);
        http_body_json_obj = NULL;
    }

    return err;
}
