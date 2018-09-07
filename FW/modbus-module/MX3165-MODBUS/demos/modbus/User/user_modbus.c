#include "user_modbus.h"


extern system_context_t* sys_context;
extern mico_mutex_t stdio_tx_mutex;
  
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
    //err = f_0x41_04_data ( inBuf, mico_context );
    //require_noerr_action ( err, exit, user_modbus_log ( "ERROR:data_process f_0x41_02_data exit with err=%d", err ) );
  } else if ( 0x45 == frame_comm ) {
    //err = f_0x45_data ( inBuf, mico_context );
    //require_noerr_action ( err, exit, user_modbus_log ( "ERROR:data_process f_0x41_02_data exit with err=%d", err ) );
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


OSStatus f_0x49_data ( unsigned char *recv_buf, mico_Context_t* mico_context ) {

  OSStatus err = kNoErr;
  unsigned char frame_comm_ct = ( int ) recv_buf[4];
  
  if ( frame_comm_ct == 2 ) {
    execute_easylink();
  } else if ( frame_comm_ct == 3 ) {
    execute_earse_easylink();
  } else if ( frame_comm_ct == 4 ) {
    //err = f_0x49_04_data ( recv_buf, sys_context );
    //require_noerr_action ( err, exit, user_modbus_log ( "ERROR: get_wifi_mac exit with err=%d", err ) );
  }else if ( frame_comm_ct == 6 ) {
    //err = f_0x49_06_data ( recv_buf, sys_context );
    //require_noerr_action ( err, exit, user_modbus_log ( "ERROR: send charge info exit with err=%d", err ) );
  }else if ( frame_comm_ct == 8 ) {
    //err = f_0x49_08_data ( recv_buf, sys_context );
    //require_noerr_action ( err, exit, user_modbus_log ( "ERROR: send charge info exit with err=%d", err ) );
  }
  
exit:
  return err;
}









