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
#include "user_device_control.h"

extern unsigned char SENSOR_ADDRESS;

extern void PlatformEasyLinkButtonClickedCallback ( void );
extern void PlatformEasyLinkButtonLongPressedCallback ( void );
extern unsigned char recv_0x45_data[DATA_LENGTH_0x45] ;
//extern volatile bool is_modbus_busy_flag;
extern volatile unsigned char is_modbus_busy_flag;
extern int modbus_try_times;

device_status_t device_status;

OSStatus execute_fan_val ( unsigned int fan_val ) {

  OSStatus err = kNoErr;
  unsigned char command_to_send[] = {0x07, 0x2A, 0x01, 0x45, 0x00, 0x00, 0x00, 0x23};
  if ( fan_val >= 5 ) {
    device_control_user_log ( "Received a false fan value!" );
    return -1;
  } else {
    command_to_send[2] = SENSOR_ADDRESS;
    command_to_send[4] = fan_val;
   
    modbus_try_times = 0;
    while ( is_modbus_busy_flag ) {
      if ( modbus_try_times < MODBUS_TRY_COUNT ) {
        modbus_try_times++;
        device_control_user_log ( "command for execute_fan_val waiting %d ms", modbus_try_times * 100 );
        mico_thread_msleep ( MODBUS_SLEEP_MS );
      } else {
        is_modbus_busy_flag = false;
        modbus_try_times = 0;
        device_control_user_log ( "command for execute_fan_val send fail!" );
        return err ;
      }
    }
    
    
    err = user_uart_send ( command_to_send, 8 );
    require_noerr_action ( err, exit, device_control_user_log ( "ERROR: execute_fan_val exit with err=%d", err ) );
    
    recv_0x45_data[7] = fan_val;
    
    is_modbus_busy_flag = true;
  }
exit:
  return err;
}


OSStatus execute_UV_val ( unsigned int UV_val ) {

  OSStatus err = kNoErr;
  unsigned char command_to_send[] = {0x07, 0x2A, 0x01, 0x45, 0x00, 0x00, 0x00, 0x23};
  if ( UV_val >= 2 ) {
    device_control_user_log ( "Received a false UV value!" );
    return -1;
  } else {
    
    /*
     if (recv_0x45_data[5] == 0x00 || recv_0x45_data[7] == 0xFF || recv_0x45_data[7] == 0xFE){
      device_control_user_log ( "Error !Fan state is close OR Module is unsupport!" );
      return 0;
    }
    */
    command_to_send[2] = SENSOR_ADDRESS;
    command_to_send[4] = UV_val + 5;
    
    modbus_try_times = 0;
    while ( is_modbus_busy_flag ) {
      if ( modbus_try_times < MODBUS_TRY_COUNT ) {
        modbus_try_times++;
        device_control_user_log ( "command for execute_UV_val waiting %d ms", modbus_try_times * 100 );
        mico_thread_msleep ( MODBUS_SLEEP_MS );
      } else {
        is_modbus_busy_flag = false;
        modbus_try_times = 0;
        device_control_user_log ( "command for execute_UV_val send fail!" );
        return err ;
      }
    }
    
    err = user_uart_send ( command_to_send, 8 );
    require_noerr_action ( err, exit, device_control_user_log ( "ERROR: execute_UV_val exit with err=%d", err ) );
    recv_0x45_data[8] = UV_val;
    is_modbus_busy_flag = true;
  }
exit:
  return err;
}

OSStatus execute_negative_val ( unsigned int negative_val ) {

  OSStatus err = kNoErr;
  unsigned char command_to_send[] = {0x07, 0x2A, 0x01, 0x45, 0x00, 0x00, 0x00, 0x23};
  if ( negative_val >= 2 ) {
    device_control_user_log ( "Received a false NI value!" );
    return -1;
  } else {
    
    /*
    if (recv_0x45_data[5] == 0x00 || recv_0x45_data[8] == 0xFF || recv_0x45_data[8] == 0xFE){
      device_control_user_log ( "Error !Fan state is close OR Module is unsupport!" );
      return 0;
    }
    */
    
    command_to_send[2] = SENSOR_ADDRESS;
    command_to_send[4] = negative_val + 7;
    
    modbus_try_times = 0;
    while ( is_modbus_busy_flag ) {
      if ( modbus_try_times < MODBUS_TRY_COUNT ) {
        modbus_try_times++;
        device_control_user_log ( "command for execute_negative_val waiting %d ms", modbus_try_times * 100 );
        mico_thread_msleep ( MODBUS_SLEEP_MS );
      } else {
        is_modbus_busy_flag = false;
        modbus_try_times = 0;
        device_control_user_log ( "command for execute_negative_val send fail!" );
        return err ;
      }
    }
    
    err = user_uart_send ( command_to_send, 8 );
    require_noerr_action ( err, exit, device_control_user_log ( "ERROR: execute_UV_val exit with err=%d", err ) );
    recv_0x45_data[9] = negative_val;
    is_modbus_busy_flag = true;
  }
exit:
  return err;
}

OSStatus execute_door_val ( unsigned int door_val ) {
  
  //unsigned char i = 0;

  OSStatus err = kNoErr;
  unsigned char command_to_send[] = {0x07, 0x2A, 0x01, 0x45, 0x00, 0x00, 0x00, 0x23};
  if ( door_val >= 2 ) {
    device_control_user_log ( "Received a false door value!" );
    return -1;
  } else {
    
    command_to_send[2] = SENSOR_ADDRESS;
    command_to_send[4] = door_val + 9;
    
//  mico_rtos_lock_mutex( &stdio_tx_mutex );
//  printf("door_val data:");
//  for(i = 0;i < sizeof(command_to_send);i++)
//  {
//    printf("%x ",command_to_send[i]);
//  }
//  printf("\n");
//  mico_rtos_unlock_mutex( &stdio_tx_mutex );  
    
    err = user_uart_send ( command_to_send, 8 );
    require_noerr_action ( err, exit, device_control_user_log ( "ERROR: execute_door_val exit with err=%d", err ) );
  }
exit:
  return err;
}


OSStatus execute_fan_status ( unsigned int get_fan_status ) {

  OSStatus err = kNoErr;
  unsigned char command_to_send[] = {0x07, 0x2A, 0x01, 0x45, 0x00, 0x00, 0x00, 0x23};
  if ( get_fan_status != 1 ) {
    device_control_user_log ( "Received a false get_fan_status value!" );
    return -1;
  } else {
    command_to_send[2] = SENSOR_ADDRESS;
    command_to_send[4] = 0xAF;
    
    modbus_try_times = 0;
    while ( is_modbus_busy_flag ) {
      if ( modbus_try_times < MODBUS_TRY_COUNT ) {
        modbus_try_times++;
        device_control_user_log ( "command for execute_fan_status waiting %d ms", modbus_try_times * 100 );
        mico_thread_msleep ( MODBUS_SLEEP_MS );
      } else {
        is_modbus_busy_flag = false;
        modbus_try_times = 0;
        device_control_user_log ( "command for execute_fan_status send fail!" );
        return err ;
      }
    }
    
    err = user_uart_send ( command_to_send, 8 );
    require_noerr_action ( err, exit, device_control_user_log ( "ERROR: execute_UV_val exit with err=%d", err ) );
    is_modbus_busy_flag = true;
  }
exit:
  return err;
}


//打开和关闭设备  EP_val：0 关闭，EP_val：1 打开
OSStatus execute_EP_val ( unsigned int EP_val ) {

  OSStatus err = kNoErr;
  unsigned char command_to_send[] = {0x07, 0x2A, 0x01, 0x45, 0x00, 0x00, 0x00, 0x23};
  if ( EP_val >= 2 ) {
    device_control_user_log ( "Received a false EP value!" );
    return -1;
  } else {
    command_to_send[2] = SENSOR_ADDRESS;
    command_to_send[4] = EP_val + 0x10;
    
    modbus_try_times = 0;
    while ( is_modbus_busy_flag ) {
      if ( modbus_try_times < MODBUS_TRY_COUNT ) {
        modbus_try_times++;
        device_control_user_log ( "command for execute_EP_val waiting %d ms", modbus_try_times * 100 );
        mico_thread_msleep ( MODBUS_SLEEP_MS );
      } else {
        is_modbus_busy_flag = false;
        modbus_try_times = 0;
        device_control_user_log ( "command for execute_EP_val send fail!" );
        return err ;
      }
    }
    
    
    err = user_uart_send ( command_to_send, 8 );
    require_noerr_action ( err, exit, device_control_user_log ( "ERROR: execute_UV_val exit with err=%d", err ) );
    is_modbus_busy_flag = true;
  }
exit:
  return err;
}

OSStatus execute_SM_val ( unsigned int SM_val ) {

  OSStatus err = kNoErr;
  unsigned char command_to_send[] = {0x07, 0x2A, 0x01, 0x45, 0x00, 0x00, 0x00, 0x23};
  if ( SM_val >= 2 ) {
    device_control_user_log ( "Received a false SM value!" );
    return -1;
  } else {
    command_to_send[2] = SENSOR_ADDRESS;
    command_to_send[4] = SM_val + 0x12;
    
    modbus_try_times = 0;
    while ( is_modbus_busy_flag ) {
      if ( modbus_try_times < MODBUS_TRY_COUNT ) {
        modbus_try_times++;
        device_control_user_log ( "command for execute_SM_val waiting %d ms", modbus_try_times * 100 );
        mico_thread_msleep ( MODBUS_SLEEP_MS );
      } else {
        is_modbus_busy_flag = false;
        modbus_try_times = 0;
        device_control_user_log ( "command for execute_SM_val send fail!" );
        return err ;
      }
    }
    
    
    err = user_uart_send ( command_to_send, 8 );
    require_noerr_action ( err, exit, device_control_user_log ( "ERROR: execute_SM_val exit with err=%d", err ) );
    is_modbus_busy_flag = true;
  }
exit:
  return err;
}

//WIFI获取到筹码后，发送命令给MCU，MCU控制蜂鸣器响一声
OSStatus charge_beep (void) {

  OSStatus err = kNoErr;
  unsigned char command_to_send[] = {0x07, 0x2A, 0x01, 0x49, 0x07, 0x00, 0x00, 0x23};
  
    command_to_send[2] = SENSOR_ADDRESS;
    
    err = user_uart_send ( command_to_send, 8 );
    require_noerr_action ( err, exit, device_control_user_log ( "ERROR: charge_beep exit with err=%d", err ) );
  
exit:
  return err;
}


void execute_easylink (void) {

  PlatformEasyLinkButtonClickedCallback();
}

void execute_earse_easylink (void) {
  
  device_control_user_log("easylink!!!!!!!!!!");

  PlatformEasyLinkButtonLongPressedCallback(); 
  
}

