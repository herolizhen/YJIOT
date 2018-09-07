/**
 ******************************************************************************
 * @file    SppProtocol.c
 * @author  William Xu
 * @version V1.0.0
 * @date    05-May-2014
 * @brief   SPP protocol deliver any data received from UART to wlan and deliver
 * wlan data to UART.
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

#include "mico.h"
#include "SppProtocol.h"
#include "SocketUtils.h"
#include "debug.h"

#define MAX_SOCK_MSG_LEN (10*1024)
int sockmsg_len = 0;
#define spp_log(M, ...) custom_log("SPP", M, ##__VA_ARGS__)
#define spp_log_trace() custom_log_trace("SPP")

void socket_msg_take(socket_msg_t*msg);
void socket_msg_free(socket_msg_t*msg);


OSStatus sppProtocolInit(app_context_t * const inContext)
{
  int i;
  
  spp_log_trace();
  (void)inContext;

  for(i=0; i < MAX_QUEUE_NUM; i++) {
    inContext->appStatus.socket_out_queue[i] = NULL;
  }
  mico_rtos_init_mutex(&inContext->appStatus.queue_mtx);
  return kNoErr;
}

OSStatus sppWlanCommandProcess(unsigned char *inBuf, int *inBufLen, int inSocketFd, app_context_t * const inContext)
{
  spp_log_trace();
  (void)inSocketFd;
  (void)inContext;
  OSStatus err = kUnknownErr;

  err = MicoUartSend(UART_FOR_APP, inBuf, *inBufLen);

  *inBufLen = 0;
  return err;
}

OSStatus sppUartCommandProcess(uint8_t *inBuf, int inLen, app_context_t * const inContext)
{
  spp_log_trace();
  OSStatus err = kNoErr;
  int i;
  mico_queue_t* p_queue=NULL;
  socket_msg_t *real_msg;

  for(i=0; i < MAX_QUEUE_NUM; i++) {
    p_queue = inContext->appStatus.socket_out_queue[i];
    if(p_queue  != NULL ){
      break;
    }
  }
  if (p_queue == NULL)
    return kNoErr;
  
  if (MAX_SOCK_MSG_LEN < sockmsg_len)
    return kNoMemoryErr;
  real_msg = (socket_msg_t*)malloc(sizeof(socket_msg_t) - 1 + inLen);

  if (real_msg == NULL)
    return kNoMemoryErr;
  sockmsg_len += (sizeof(socket_msg_t) - 1 + inLen);
  real_msg->len = inLen;
  memcpy(real_msg->data, inBuf, inLen);
  real_msg->ref = 0;
  
  mico_rtos_lock_mutex(&inContext->appStatus.queue_mtx);
  socket_msg_take(real_msg);
  for(i=0; i < MAX_QUEUE_NUM; i++) {
    p_queue = inContext->appStatus.socket_out_queue[i];
    if(p_queue  != NULL ){
      socket_msg_take(real_msg);
      if (kNoErr != mico_rtos_push_to_queue(p_queue, &real_msg, 0)) {
        socket_msg_free(real_msg);
    }
  }
  }        
  socket_msg_free(real_msg);
  mico_rtos_unlock_mutex(&inContext->appStatus.queue_mtx);
  return err;
}

void socket_msg_take(socket_msg_t*msg)
{
    msg->ref++;
}

void socket_msg_free(socket_msg_t*msg)
{
    msg->ref--;
    if (msg->ref == 0) {
        sockmsg_len -= (sizeof(socket_msg_t) - 1 + msg->len);
        free(msg);
    
    }
}

int socket_queue_create(app_context_t * const inContext, mico_queue_t *queue)
{
    OSStatus err;
    int i;
    mico_queue_t *p_queue;
    
    err = mico_rtos_init_queue(queue, "sockqueue", sizeof(int), MAX_QUEUE_LENGTH);
    if (err != kNoErr)
        return -1;
    mico_rtos_lock_mutex(&inContext->appStatus.queue_mtx);
    for(i=0; i < MAX_QUEUE_NUM; i++) {
        p_queue = inContext->appStatus.socket_out_queue[i];
        if(p_queue == NULL ){
            inContext->appStatus.socket_out_queue[i] = queue;
            mico_rtos_unlock_mutex(&inContext->appStatus.queue_mtx);
            return 0;
        }
    }        
    mico_rtos_unlock_mutex(&inContext->appStatus.queue_mtx);
    mico_rtos_deinit_queue(queue);
    return -1;
}

int socket_queue_delete(app_context_t * const inContext, mico_queue_t *queue)
{
    int i;
    socket_msg_t *msg;
    int ret = -1;

    mico_rtos_lock_mutex(&inContext->appStatus.queue_mtx);
    // remove queue
    for(i=0; i < MAX_QUEUE_NUM; i++) {
        if (queue == inContext->appStatus.socket_out_queue[i]) {
            inContext->appStatus.socket_out_queue[i] = NULL;
            ret = 0;
        }
    }
    mico_rtos_unlock_mutex(&inContext->appStatus.queue_mtx);
    // free queue buffer
    while(kNoErr == mico_rtos_pop_from_queue( queue, &msg, 0)) {
        socket_msg_free(msg);
    }

    // deinit queue
    mico_rtos_deinit_queue(queue);
    
    return ret;
}

