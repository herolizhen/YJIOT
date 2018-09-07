/**
 ******************************************************************************
 * @file    mico_main.c
 * @author  Eshen Wang
 * @version V1.0.0
 * @date    15-Dec-2015
 * @brief   mico application entrance file.
 ******************************************************************************
 *
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
 *
 ******************************************************************************
 **/

#include "mico.h"

#define app_log(M, ...) custom_log("APP", M, ##__VA_ARGS__)

extern OSStatus bt_smart_init_wlanconfig( void );

int application_start( void )
{
  OSStatus err = kNoErr;
  mico_Context_t* mico_context = NULL;

  /* Create mico system context and read application's config data from flash */
  mico_context = mico_system_context_init( 0 );
  
  /* mico system initialize */
  err = mico_system_init( mico_context );
  require_noerr( err, exit );
  
  /* Start bluetooth sub-system */
  bt_smart_init_wlanconfig( );

exit:
  mico_rtos_delete_thread( NULL );
  return err;
}
