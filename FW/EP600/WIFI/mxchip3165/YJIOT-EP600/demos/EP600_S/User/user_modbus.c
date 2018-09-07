/**
******************************************************************************
* @file    user_modbus.c
* @author  herolizhen
* @version V1.0.0
* @date    24-06-2016
* @brief
******************************************************************************
*/

#include "user_modbus.h"
#include "user_charge.h"
#include "user_device_check.h"

extern user_charge_t user_charge;
extern system_context_t* sys_context;
extern mico_mutex_t stdio_tx_mutex;

extern device_check_t device_check;
  
unsigned char SENSOR_ADDRESS = NULL;
unsigned char recv_0x41_data[DATA_LENGTH_0x41] = NULL;
unsigned char recv_0x45_data[DATA_LENGTH_0x45] = NULL;

bool is_recv_0x41_data = false;
bool is_recv_0x45_data = false;
bool is_modbus_busy_flag = false ;
int  modbus_try_times = 0 ;
unsigned char  ReciveBuffer[RECEIVE_BUFFER_LENGTH];
int   ReciveIndex = 0 ;


extern void execute_easylink(void);
extern void execute_earse_easylink(void);
//extern OSStatus get_wifi_mac ( app_context_t *app_context );
//extern int wifi_get_mac_address(char * mac);
extern OSStatus upload_dev_data ( unsigned char *recv_0x41_buf, unsigned char *recv_0x45_buf, mico_Context_t *mico_context ) ;

OSStatus get_device_addr (void) {
  OSStatus err = kNoErr;
  unsigned char command_to_send[] = {0x08, 0x2A, 0x00, 0x44, 0x00, 0x00, 0x00, 0x00, 0x23};
  unsigned char  recv_data[DATA_LENGTH_0x44];
  int   recv_len = 0;
  
  err = user_uart_send ( command_to_send, 9 );
  require_noerr_action ( err, exit, user_modbus_log ( "ERROR: get_divice_addr exit with err=%d", err ) );
  
  user_modbus_log ( "Waiting for sensor address... " );
  mico_thread_msleep ( 100 );
  
  while ( recv_len == 0 ) {
    recv_len = user_uart_recv ( recv_data, 10 );
    if ( recv_len > 0 ) {
      if ( recv_data[1] == 0x2A && recv_data[3] == 0x44 || recv_len == recv_data[0] + 1 ) {
        SENSOR_ADDRESS = recv_data[6];
        user_modbus_log ( "Received SENSOR_ADDRESS is :%d", SENSOR_ADDRESS );
      } else {
        user_modbus_log ( "Recvived SENSOR_ADDRESS Error!!" );
        recv_len = 0;
        mico_thread_msleep ( 200 );
        err = user_uart_send ( command_to_send, 9 );
        require_noerr_action ( err, exit, user_modbus_log ( "ERROR: get_divice_addr exit with err=%d", err ) );
      }
    } else {
      user_modbus_log ( "Waiting for sensor address... " );
      mico_thread_msleep ( 100 );
      err = user_uart_send ( command_to_send, 9 );
      require_noerr_action ( err, exit, user_modbus_log ( "ERROR: get_divice_addr exit with err=%d", err ) );
    }
  }
  
exit:
  return err;
}

void frame_data ( unsigned char  *inBuf, int inLen , mico_Context_t* mico_context ) {

  for ( int i = 0; i < inLen; i++ ) {
    ReciveBuffer[ReciveIndex + i] = inBuf[i];
  }
  
  ReciveIndex += inLen;
  
  if ( ReciveBuffer[0] == ( ReciveIndex - 1 ) && ReciveBuffer[ReciveIndex - 1] == 0x23 ) {
    
     data_process (ReciveBuffer, mico_context );
     
     for ( int i = 0; i < RECEIVE_BUFFER_LENGTH; i++ ) {
        ReciveBuffer[i] = 0x00;
      }
     ReciveIndex = 0 ;
     
  } else if ( ReciveIndex - 1 > ReciveBuffer[0] && ReciveBuffer[ReciveIndex - 1] == 0x23 ) {
    
    user_modbus_log ( "INFO: MayBe Receive Multi Frame !" );
    
//    for ( int i = 0; i < inLen; i++ ) {
//      printf ( "%02x ", inBuf[i] );
//    }
//    printf ( "\r\n" );
    
    for ( int i = 0; i < RECEIVE_BUFFER_LENGTH; i++ ) {
      printf ( "%02x ", ReciveBuffer[i] );
    }
    printf ( "\r\n" );
    
    int frameCout = 0 ;
    int framesSize = 0 ;
    
    while (framesSize < ReciveIndex){
       framesSize += ReciveBuffer[framesSize] + 1 ;
       frameCout  += 1 ;
    }
      
    if(framesSize == ReciveIndex){
       user_modbus_log ( "INFO: Multi Frame Revive Cout=%d!" , frameCout );
       
       for( int i = 1 ; i <= frameCout ; i++ ){        
         user_modbus_log ( "INFO: Multi Frame  Deal Frame=%d!" , i );         
         data_process (ReciveBuffer, mico_context );        
         
         int frameSize = ReciveBuffer[0] + 1;       
         for(int m = 0 ; m + frameSize < RECEIVE_BUFFER_LENGTH ; m++){
            ReciveBuffer[m] = ReciveBuffer[m + frameSize];
         }     
       }     
      
    }else{
       user_modbus_log ( "ERROR: data frame  error!" );
    }
    
    for ( int i = 0; i < RECEIVE_BUFFER_LENGTH; i++ ) {
      ReciveBuffer[i] = 0x00;
    }   
    ReciveIndex = 0;
    
  } else {
    user_modbus_log ( "INFO: Data Frame Continue Receive! +++++" );
  } 
}

OSStatus data_process ( unsigned char  *inBuf, mico_Context_t* mico_context ) {

  OSStatus err = kUnknownErr;
  unsigned char frame_comm ;
  unsigned char frame_comm_ct;
  
  frame_comm  = inBuf[3];
  frame_comm_ct = inBuf[4];
  
//  for ( int i = 0; i < RECEIVE_BUFFER_LENGTH; i++ ) {
//      printf ( "%02x ", ReciveBuffer[i] );
//  }
//  printf ( "\r\n" );

  if ( 0x41 == frame_comm  &&  0x04 == frame_comm_ct ) {
    err = f_0x41_04_data ( inBuf, mico_context );
    require_noerr_action ( err, exit, user_modbus_log ( "ERROR:data_process f_0x41_02_data exit with err=%d", err ) );
  } else if ( 0x45 == frame_comm ) {
    err = f_0x45_data ( inBuf, mico_context );
    require_noerr_action ( err, exit, user_modbus_log ( "ERROR:data_process f_0x41_02_data exit with err=%d", err ) );
  } else if ( 0x49 == frame_comm ) {
    err = f_0x49_data ( inBuf, mico_context );
    require_noerr_action ( err, exit, user_modbus_log ( "ERROR:data_process f_0x41_02_data exit with err=%d", err ) );
  } else {
    user_modbus_log ( "ERROR:received data frame_len=%d  frame_data:", ReciveIndex + 1 );
    for ( int i = 0; i < inBuf[0]+1; i++ ) {
      printf ( "%02x ", inBuf[i] );   
    }
    printf ( "\r\n" );
  }
  
exit:
  is_modbus_busy_flag = false;
  return err;
}

OSStatus f_0x41_04_data ( unsigned char *recv_buf, mico_Context_t* mico_context ) {

  //unsigned char i = 0;
  
  unsigned int frame_size = ( int ) recv_buf[0] + 1;
  
  for ( int i = 0; i < frame_size; i++ ) {
    recv_0x41_data[i] = recv_buf[i];
  }
  is_recv_0x41_data = true;
  
//  mico_rtos_lock_mutex( &stdio_tx_mutex );
//  printf("0x41 buff:");
//  for(i = 0;i < frame_size;i ++)
//  {
//      printf("%x ",recv_buf[i]);
//  }
//  printf("\n");
//  mico_rtos_unlock_mutex( &stdio_tx_mutex );
  
  return 0 ;
}

OSStatus f_0x41_04_cmd (void) {

  OSStatus err = kUnknownErr;
  unsigned char command_to_send[] = {0x07, 0x2A, 0x01, 0x41, 0x04, 0x00, 0x00, 0x23};
  command_to_send[2] = SENSOR_ADDRESS;
  
  modbus_try_times = 0;
  while ( is_modbus_busy_flag ) {
    if ( modbus_try_times < MODBUS_TRY_COUNT ) {
      modbus_try_times++;
      user_modbus_log ( "command for f_0x41_04_cmd waiting %d ms", modbus_try_times * 100 );
      mico_thread_msleep ( MODBUS_SLEEP_MS );
    } else {
      is_recv_0x41_data = false;
      is_modbus_busy_flag = false;
      modbus_try_times = 0;
      user_modbus_log ( "command for f_0x41_04_cmd send fail!" );
      return err ;
    }
  }
  
  user_modbus_log ( "command for get sensor data to be send" );
  err = user_uart_send ( command_to_send, 8 );
  require_noerr_action ( err, exit, user_modbus_log ( "ERROR: f_0x41_02_cmd exit with err=%d", err ) );
  
  is_modbus_busy_flag = true;
  
exit:
  return err;
  
}

OSStatus f_0x45_cmd (void) {

  OSStatus err = kUnknownErr;
  unsigned char command_to_send[] = {0x07, 0x2A, 0x01, 0x45, 0xAF, 0x00, 0x00, 0x23};
  command_to_send[2] = SENSOR_ADDRESS;
  
  modbus_try_times = 0;
  while ( is_modbus_busy_flag ) {
    if ( modbus_try_times < MODBUS_TRY_COUNT ) {
      modbus_try_times++;
      user_modbus_log ( "command for f_0x45_cmd waiting %d ms", modbus_try_times * 100 );
      mico_thread_msleep ( MODBUS_SLEEP_MS );
    } else {
      is_recv_0x45_data = false;
      is_modbus_busy_flag = false;
      modbus_try_times = 0;
      user_modbus_log ( "command for f_0x45_cmd send fail!" );
      return err ;
    }
  }
  
  user_modbus_log ( "command for get device status data to be send" );
  err = user_uart_send ( command_to_send, 8 );
  require_noerr_action ( err, exit, user_modbus_log ( "ERROR: f_0x45_cmd exit with err=%d", err ) );
  
  is_modbus_busy_flag = true;
  
exit:
  return err;
}

OSStatus f_0x45_data ( unsigned char *recv_buf, mico_Context_t* mico_context ) {

  unsigned int frame_size = ( int ) recv_buf[0] + 1;
  unsigned char frame_comm_ct = ( int ) recv_buf[4];
  
  if ( frame_comm_ct == 0xAF ) {
  
    for ( int i = 0; i < frame_size; i++ ) {
      recv_0x45_data[i] = recv_buf[i];
    }
    is_recv_0x45_data = true;
  } else  {
  
//    upload_dev_data ( recv_0x41_data, recv_0x45_data, mico_context );
//    user_modbus_log ( "Device state have changed!" );
    
  }
  
  return 0 ;
}

OSStatus f_0x49_data ( unsigned char *recv_buf, mico_Context_t* mico_context ) {

  OSStatus err = kNoErr;
  unsigned char frame_comm_ct = ( int ) recv_buf[4];
  
  if ( frame_comm_ct == 2 ) {
    execute_easylink();
  } else if ( frame_comm_ct == 3 ) {
    execute_earse_easylink();
  } else if ( frame_comm_ct == 4 ) {
    err = f_0x49_04_data ( recv_buf, sys_context );
    require_noerr_action ( err, exit, user_modbus_log ( "ERROR: get_wifi_mac exit with err=%d", err ) );
  }else if ( frame_comm_ct == 6 ) {
    err = f_0x49_06_data ( recv_buf, sys_context );
    require_noerr_action ( err, exit, user_modbus_log ( "ERROR: send charge info exit with err=%d", err ) );
  }else if ( frame_comm_ct == 8 ) {
    err = f_0x49_08_data ( recv_buf, sys_context );
    //require_noerr_action ( err, exit, user_modbus_log ( "ERROR: send charge info exit with err=%d", err ) );
  }
  
exit:
  return err;
}

OSStatus f_0x49_04_data ( unsigned char *recv_buf, system_context_t * const inContext ) {
  
  OSStatus err = kUnknownErr;
  char *data_to_send  = inContext->micoStatus.mac;
  //char mac[32];
  char command_head[] = {0x18, 0x2A, SENSOR_ADDRESS, 0x49, 0x04};
  char *command_to_send = malloc ( strlen ( command_head ) + strlen ( data_to_send ) + 3 + 1 );
  memset(command_to_send,0,sizeof(command_to_send));
  //char *command_to_send = malloc ( strlen ( command_head ) + strlen ( mac ) + 3 + 1 );
   
  strcpy ( command_to_send, command_head );
  strcat ( command_to_send, data_to_send );
  command_to_send[22] = 0x00;
  command_to_send[23] = 0x00;
  command_to_send[24] = 0x23;
  
  
  modbus_try_times = 0;
  while ( is_modbus_busy_flag ) {
    if ( modbus_try_times < MODBUS_TRY_COUNT ) {
      modbus_try_times++;
      user_modbus_log ( "command for f_0x49_04_data waiting %d ms", modbus_try_times * 100 );
      mico_thread_msleep ( MODBUS_SLEEP_MS );
    } else {
      is_modbus_busy_flag = false;
      modbus_try_times = 0;
      user_modbus_log ( "command for f_0x49_04_data send fail!" );
      return err ;
    }
  }
  
  user_modbus_log ( "data for WIFI MAC  to be send = %s", command_to_send );
  err = user_uart_send ( ( unsigned char* ) command_to_send, 25 );
  require_noerr_action ( err, exit, user_modbus_log ( "ERROR: f_0x49_04_data exit with err=%d", err ) );
  
exit:
  if(NULL != command_to_send){
    free(command_to_send);
    command_to_send = NULL ;
  }
  return err;
  
}

//给MCU发送计费信息
OSStatus f_0x49_06_data ( unsigned char *recv_buf, system_context_t * const inContext ) {
  
  //unsigned char i = 0;
  
  OSStatus err = kUnknownErr;
  unsigned char data_to_send[13] = {0x0C, 0x2A, SENSOR_ADDRESS, 0x49, 0x06};
  data_to_send[5] = user_charge.lefttime.IsChargeType;
  data_to_send[6] = user_charge.lefttime.left_time_mon;
  data_to_send[7] = user_charge.lefttime.left_time_day;
  data_to_send[8] = user_charge.lefttime.left_time_hour;
  data_to_send[9] = user_charge.lefttime.left_time_min;
  data_to_send[10] = 0x00;
  data_to_send[11] = 0x00;
  data_to_send[12] = 0x23;
  
//  mico_rtos_lock_mutex( &stdio_tx_mutex );
//  printf("f_0x49_06_data:");
//  for(i = 0;i < sizeof(data_to_send);i++)
//  {
//    printf("%x ",data_to_send[i]);
//  }
//  printf("\n");
//  mico_rtos_unlock_mutex( &stdio_tx_mutex );  
  
  err = user_uart_send ( ( unsigned char* ) data_to_send, sizeof(data_to_send) );
  require_noerr_action ( err, exit, user_modbus_log ( "ERROR: f_0x49_04_data exit with err=%d", err ) );
  
exit:
  return err;
  
}


//给MCU进行系统自动检测
OSStatus f_0x49_08_01_cmd (void) {
  
  //unsigned char i = 0;
  
  OSStatus err = kUnknownErr;
  unsigned char data_to_send[9] = {0x08, 0x2A, SENSOR_ADDRESS, 0x49, 0x08,0x01,0x00,0x00,0x23};
  
//  mico_rtos_lock_mutex( &stdio_tx_mutex );
//  printf("f_0x49_06_data:");
//  for(i = 0;i < sizeof(data_to_send);i++)
//  {
//    printf("%x ",data_to_send[i]);
//  }
//  printf("\n");
//  mico_rtos_unlock_mutex( &stdio_tx_mutex );  
  
  err = user_uart_send ( ( unsigned char* ) data_to_send, sizeof(data_to_send) );
  require_noerr_action ( err, exit, user_modbus_log ( "ERROR: f_0x49_08_01_cmd exit with err=%d", err ) );
  
exit:
  return err;
  
}


//给MCU进行系统停止自动检测
OSStatus f_0x49_08_02_cmd (void) {
  
  OSStatus err = kUnknownErr;
  unsigned char data_to_send[9] = {0x08, 0x2A, SENSOR_ADDRESS, 0x49, 0x08,0x02,0x00,0x00,0x23};
  
  err = user_uart_send ( ( unsigned char* ) data_to_send, sizeof(data_to_send) );
  require_noerr_action ( err, exit, user_modbus_log ( "ERROR: f_0x49_08_02_cmd exit with err=%d", err ) );
  
exit:
  return err;
  
}

//给MCU进行系统手动检测
OSStatus f_0x49_08_03_cmd (void) {
  
  OSStatus err = kUnknownErr;
  unsigned char data_to_send[9] = {0x08, 0x2A, SENSOR_ADDRESS, 0x49, 0x08,0x03,0x00,0x00,0x23};
  
  err = user_uart_send ( ( unsigned char* ) data_to_send, sizeof(data_to_send) );
  require_noerr_action ( err, exit, user_modbus_log ( "ERROR: f_0x49_08_03_cmd exit with err=%d", err ) );
  
exit:
  return err;
  
}

//给MCU进行系统停止手动检测
OSStatus f_0x49_08_04_cmd (void) {
  
  OSStatus err = kUnknownErr;
  unsigned char data_to_send[9] = {0x08, 0x2A, SENSOR_ADDRESS, 0x49, 0x08,0x04,0x00,0x00,0x23};
  
  err = user_uart_send ( ( unsigned char* ) data_to_send, sizeof(data_to_send) );
  require_noerr_action ( err, exit, user_modbus_log ( "ERROR: f_0x49_08_04_cmd exit with err=%d", err ) );
  
exit:
  return err;
  
}


//MCU的自检信息，其中buff[5]是检测的结果，bit0表示仓门，bit1表示风机，bit2表示uv灯
OSStatus f_0x49_08_data ( unsigned char *recv_buf, system_context_t * const inContext ) {
  
  unsigned char result = 0;
  unsigned char child_code = 0;
  unsigned int pm25_data = 0;
  unsigned char check_type = 0;
  
  OSStatus err = kNoErr;
  
  child_code = recv_buf[5];
  
  if(child_code == 0x01 || child_code == 0x03)
  {
    if(child_code == 0x01)
    {
      //自动检测结果
      //对应的bit位为1表示故障，0表示正常
      result = recv_buf[6];
      user_modbus_log("recv_buf[7]:0x%x,recv_buf[8]:0x%x",recv_buf[7],recv_buf[8]);
      pm25_data = ((unsigned int)recv_buf[7] << 8) | ((unsigned int)recv_buf[8]);
      user_modbus_log("check result:0x%x,door:%s,fan;%s,uv:%s,pm_bit:%s,pm:%d",result,AUTO_CHECK_0(result,door_bit),AUTO_CHECK_0(result,fan_bit),
                    AUTO_CHECK_0(result,uv_bit),AUTO_CHECK_0(result,pm25_bit),pm25_data);
    
      check_type = auto_check;
      
      device_check.pm25_value = pm25_data;
    }
    else if(child_code == 0x03)
    {
      //手动检测结果
      //对应的bit位1表示检测过，0表示没有检测
      result = recv_buf[6];
      user_modbus_log("check result:0x%x,power:%s,quiet_p;%s,low_p;%s,mid_p;%s,high_p;%s,timer:%s,mode:%s,wifi:%s",result,MAN_CHECK_0(result,power_bit),MAN_CHECK_0(result,quiet_speed_bit),
                    MAN_CHECK_0(result,low_speed_bit),MAN_CHECK_0(result,mid_speed_bit),MAN_CHECK_0(result,high_speed_bit),
                    MAN_CHECK_0(result,timer_bit),MAN_CHECK_0(result,mode_bit),MAN_CHECK_0(result,wifi_bit));
    
      check_type = man_check;
    
    } 
    device_check.check_result = recv_buf[6];
    device_check.check_type = check_type;
    //不能在此处调用fog_v2_device_check_result_upload(),因为该函数占用栈空间特别大，会导致模块死机，UART线程也的栈不能加大到0x800，否则会导致不能OTA
    //fog_v2_device_check_result_upload(check_type);
  }

  
  
 

  
//  mico_rtos_lock_mutex( &stdio_tx_mutex );
//  printf("f_0x49_06_data:");
//  for(i = 0;i < sizeof(data_to_send);i++)
//  {
//    printf("%x ",data_to_send[i]);
//  }
//  printf("\n");
//  mico_rtos_unlock_mutex( &stdio_tx_mutex );  
  
//  err = user_uart_send ( ( unsigned char* ) data_to_send, sizeof(data_to_send) );
//  require_noerr_action ( err, exit, user_modbus_log ( "ERROR: f_0x49_04_data exit with err=%d", err ) );
  

  return err;
  
}