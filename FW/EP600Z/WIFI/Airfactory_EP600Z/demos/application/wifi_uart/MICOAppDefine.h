/**
 ******************************************************************************
 * @file    MICOAppDefine.h
 * @author  William Xu
 * @version V1.0.0
 * @date    05-May-2014
 * @brief   This file create a TCP listener thread, accept every TCP client
 *          connection and create thread for them.
 ******************************************************************************
 *  The MIT License
 *  Copyright (c) 2014 MXCHIP Inc.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is furnished
 *  to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
 *  IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 ******************************************************************************
 */

#pragma once

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Demo C function call C++ function and C++ function call C function */
//#define MICO_C_CPP_MIXING_DEMO

/*User provided configurations*/
#define CONFIGURATION_VERSION               0x00000002 // if default configuration is changed, update this number
#define MAX_QUEUE_NUM                       6  // 1 remote client, 5 local server
#define MAX_QUEUE_LENGTH                    8  // each queue max 8 msg
#define LOCAL_PORT                          8080
#define DEAFULT_REMOTE_SERVER               "192.168.2.254"
#define DEFAULT_REMOTE_SERVER_PORT          8080
#define UART_RECV_TIMEOUT                   500
#define UART_ONE_PACKAGE_LENGTH             1024
#define wlanBufferLen                       1024
#define UART_BUFFER_LENGTH                  2048

#define LOCAL_TCP_SERVER_LOOPBACK_PORT      1000
#define REMOTE_TCP_CLIENT_LOOPBACK_PORT     1002
#define RECVED_UART_DATA_LOOPBACK_PORT      1003

#define BONJOUR_SERVICE                     "_easylink._tcp.local."

/* Define thread stack size */
#define STACK_SIZE_UART_RECV_THREAD           0x2A0
#define STACK_SIZE_LOCAL_TCP_SERVER_THREAD    0x300
#define STACK_SIZE_LOCAL_TCP_CLIENT_THREAD    0x350
#define STACK_SIZE_REMOTE_TCP_CLIENT_THREAD   0x500

typedef struct _socket_msg {
  int ref;
  int len;
  uint8_t data[1];
} socket_msg_t;

/*Application's configuration stores in flash*/
typedef struct
{
  uint32_t          configDataVer;
  uint32_t          localServerPort;

  /*local services*/
  bool              localServerEnable;
  bool              remoteServerEnable;
  char              remoteServerDomain[64];
  int               remoteServerPort;

  /*IO settings*/
  uint32_t          USART_BaudRate;
} application_config_t;


/*Running status*/
typedef struct  {
  /*Local clients port list*/
  mico_queue_t*   socket_out_queue[MAX_QUEUE_NUM];
  mico_mutex_t    queue_mtx;
} current_app_status_t;

typedef struct _app_context_t
{
  /*Flash content*/
  application_config_t*     appConfig;

  /*Running status*/
  current_app_status_t      appStatus;
} app_context_t;


#ifdef __cplusplus
} /*extern "C" */
#endif


