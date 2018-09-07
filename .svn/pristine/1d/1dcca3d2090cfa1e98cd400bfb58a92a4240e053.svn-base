/**
 ******************************************************************************
 * @file    user_defines.h
 * @author  Eshen Wang
 * @version V1.0.0
 * @date    15-Dec-2015
 * @brief   This file contains user defines for application.
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
 */

#pragma once

#include "mico.h"
#include "gagent_def.h"

#ifdef __cplusplus
extern "C" {
#endif
  
/*----------------------------- GAGENT PRODUCT INFO --------------------------*/
#define WIFI_GENERAL_PROTOCOL_VER       "04000000"    // APP<->Wi-Fi general protocol v4
#define WIFI_HARDWARE_VER               MODEL    // softare ver(V4-MAIN-SUB-REV)
#define WIFI_SOFTWARE_VER               "04000001"    // softare ver(V4-MAIN-SUB-REV)
#define WIFI_FIRMWARE_VER               "15121619"    // firmware ver(release date: YYMMDDHH)

#define MCU_GENERAL_PROTOCOL_VER        "04000900"    // Wi-Fi<->MCU uart protocol v4.0.9
#define BUSINESS_PROTOCOL_VER           "04000801"    // user-defined product data point on gizwits(v4.0.8, 01)
#define MCU_HARDWARE_VER                WIFI_HARDWARE_VER  // here use wifi mcu
#define MCU_SOFTWARE_VER                "00000001"    // device operation(01)
  
#define PRODUCT_KEY                     "41f3eefa4f0d4050968f844e8e38891e"  // product key for product on gizwits
#define BINDABLE_TIME                   (60)  // bindable in 60s after startup

/*----------------------------- Application defines --------------------------*/
/*User provided configurations*/
#define CONFIGURATION_VERSION               0x00000001 // if default configuration is changed, update this number
#define BONJOUR_SERVICE                     "_easylink._tcp.local."

// base-on MCU && business protocol
#define SET_ACTION          (0x01)
#define REPORT_ACTION       (0x04)
#define ATTR_FLAG_BIT_SW1   (0)
#define ATTR_FLAG_BIT_SW2   (1)
#define ATTR_FLAG_BIT_SW3   (2)

#define ATTR_VAL_BIT_SW1   (0)
#define ATTR_VAL_BIT_SW2   (1)
#define ATTR_VAL_BIT_SW3   (2)
  
/*Application's configuration stores in flash*/
typedef struct
{
  uint32_t          configDataVer;
  
  int8_t            passcode[GAGENT_PASSCODE_MAXLEN];
  int8_t            did[GAGENT_DID_LEN];
  uint8_t           loglevel;
  
  // borad control switch 1~3
  int8_t                  switch_1;  // 0: off, 1: on
  int8_t                  switch_2;  // 0: off, 1: on
  int8_t                  switch_3;  // 0: off, 1: on
} application_config_t;

/*Running status*/
typedef struct  {
  uint32_t               cloud_app_amount;
} current_app_status_t;

typedef struct _app_context_t
{
  /*Flash content*/
  application_config_t*     appConfig;

  /*Running status*/
  current_app_status_t      appStatus;
} app_context_t;

app_context_t* get_app_context( void );

#ifdef __cplusplus
} /*extern "C" */
#endif
