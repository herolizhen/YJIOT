/**
******************************************************************************
* @file    uart.c
* @author  herolizhen
* @version V1.0.0
* @date    17-Mar-2016
* @brief   This file contains the implementations of uart interfaces for user. 
  operation
******************************************************************************
*/ 

#include "user_uart.h"

volatile ring_buffer_t  rx_buffer;
volatile uint8_t        rx_data[USER_UART_BUFFER_LENGTH];
static size_t _uart_get_one_packet(uint8_t* buf, int maxlen);


OSStatus user_uart_init(void)
{
  OSStatus err = kUnknownErr;
  mico_uart_config_t uart_config;
  
  //USART init
  uart_config.baud_rate    = 9600;
  uart_config.data_width   = DATA_WIDTH_8BIT;
  uart_config.parity       = NO_PARITY;
  uart_config.stop_bits    = STOP_BITS_1;
  uart_config.flow_control = FLOW_CONTROL_DISABLED;
  uart_config.flags = UART_WAKEUP_DISABLE;
  
  err = ring_buffer_init( (ring_buffer_t *)&rx_buffer, (uint8_t *)rx_data, USER_UART_BUFFER_LENGTH );
  require_noerr_action( err, exit, user_uart_log("ERROR: user_uart_init exit with err=%d", err) );
  
  err = MicoUartInitialize(UART_FOR_APP, &uart_config, (ring_buffer_t *)&rx_buffer );
  require_noerr_action( err, exit, user_uart_log("ERROR: user_uart_init exit with err=%d", err));
  
exit:
  return err;
}

OSStatus user_uart_send(unsigned char *inBuf, unsigned int inBufLen)
{
  OSStatus err = kParamErr;
  require( inBuf, exit );
  err = MicoUartSend(UART_FOR_APP, inBuf, inBufLen);
  require_noerr_action(err, exit, user_uart_log("ERROR: user_uart_send error! err=%d", err) );
  
exit:
  return err;
}

uint32_t user_uart_recv(unsigned char *outBuf, unsigned int getLen)
{
  OSStatus err = kParamErr;
 
  unsigned int data_len = 0;
  err = MicoUartRecv(UART_FOR_APP, outBuf, getLen, USER_UART_RECV_TIMEOUT);
  if( err == kNoErr ){
    data_len = getLen;
  }
  else{
    data_len = MicoUartGetLengthInBuffer(UART_FOR_APP);
    if(data_len){
      err = MicoUartRecv(UART_FOR_APP, outBuf, data_len, USER_UART_RECV_TIMEOUT);
      require_noerr_action(err, exit, user_uart_log("ERROR: user_uart_recv error! err=%d", err) );
    }
    else{
      data_len = 0;
    }
  }
  
 exit:
  return data_len;
}


void uart_recv_thread(mico_thread_arg_t arg)
{
  user_uart_log_trace();
  
  OSStatus err = kNoErr;
  
  mico_Context_t *mico_context = (mico_Context_t *)arg;

  int recvlen;
  unsigned char *inDataBuffer;
  
  inDataBuffer = malloc(USER_UART_ONE_PACKAGE_LENGTH);
  require(inDataBuffer, exit);
  
  mico_thread_msleep(500);
  err = user_uart_init();
  require_noerr_action( err, exit, user_uart_log("ERROR: user_uartInit err = %d.", err) );
  
  err = get_device_addr();
  require_noerr_action( err, exit, user_uart_log("ERROR: get_divice_addr err = %d.", err) );
  
  while(1) {
    recvlen = _uart_get_one_packet(inDataBuffer, USER_UART_ONE_PACKAGE_LENGTH);
    if (recvlen <= 0)
      continue; 
  
    frame_data(inDataBuffer, recvlen,mico_context);
     
  }
  
exit:
  if(inDataBuffer) free(inDataBuffer);
    mico_rtos_delete_thread(NULL);
}

size_t _uart_get_one_packet(unsigned char *inBuf, int inBufLen)
{
  int datalen;
  while(1) {
    if( MicoUartRecv( UART_FOR_APP, inBuf, inBufLen, USER_UART_RECV_TIMEOUT) == kNoErr){
      return inBufLen;
    }
   else{
     datalen = MicoUartGetLengthInBuffer( UART_FOR_APP );
     if(datalen){
       MicoUartRecv(UART_FOR_APP, inBuf, datalen, USER_UART_RECV_TIMEOUT);
       return datalen;
     }
   }
  }
}
