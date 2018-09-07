/**
 ******************************************************************************
 * @file    SppProtocol.h
 * @author  William Xu
 * @version V1.0.0
 * @date    05-May-2014
 * @brief    This file provides all the headers of SPP data convert protocol.
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

#ifndef __SPPPROTOCOL_H
#define __SPPPROTOCOL_H

#include "common.h"
#include "MICOAppDefine.h"

OSStatus sppProtocolInit(app_context_t * const inContext);
int is_network_state(int state);
OSStatus sppWlanCommandProcess(unsigned char *inBuf, int *inBufLen, int inSocketFd, app_context_t * const inContext);
OSStatus sppUartCommandProcess(uint8_t *inBuf, int inLen, app_context_t * const inContext);


void set_network_state(int state, int on);
int socket_queue_create(app_context_t * const inContext, mico_queue_t *queue);
int socket_queue_delete(app_context_t * const inContext, mico_queue_t *queue);
void socket_msg_free(socket_msg_t*msg);
void socket_msg_take(socket_msg_t*msg);

#endif
