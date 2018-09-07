/**
  ******************************************************************************
  * @file    MICOAppDefine.h 
  * @author  William Xu
  * @version V1.0.0
  * @date    05-May-2014
  * @brief   This file create a TCP listener thread, accept every TCP client
  *          connection and create thread for them.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, MXCHIP Inc. SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2014 MXCHIP Inc.</center></h2>
  ******************************************************************************
  */ 

#ifndef __MICOAPPDEFINE_H
#define __MICOAPPDEFINE_H

#include "mico.h"
#include "user_config.h"
#include "fog_v2_config.h"


/*******************************************************************************
 *                            DEFAULT SETTING
 ******************************************************************************/
    
#ifndef APP_INFO
  #define APP_INFO            "AirFactory-EP1500"
#endif

#ifndef FIRMWARE_REVISION
  #define FIRMWARE_REVISION   "AF-EP1500_1_0"
#endif

#ifndef MANUFACTURER
  #define MANUFACTURER        "YJYZ Inc."
#endif

#ifndef SERIAL_NUMBER
  #define SERIAL_NUMBER       "20160105"
#endif

#ifndef PROTOCOL
  #define PROTOCOL            "airfactory.ep1500"
#endif

/* Wi-Fi configuration mode */
#ifndef MICO_CONFIG_MODE
  #define MICO_CONFIG_MODE     CONFIG_MODE_EASYLINK_WITH_SOFTAP
#endif

/* Define MICO cloud type */
#define CLOUD_DISABLED       (0)
#define CLOUD_FOGCLOUD       (1)
#define CLOUD_ALINK          (2)
    
/* MICO cloud service type */
#ifndef MICO_CLOUD_TYPE
  #define MICO_CLOUD_TYPE    CLOUD_FOGCLOUD
#endif

#ifndef STACK_SIZE_USER_MAIN_THREAD
  #define STACK_SIZE_USER_MAIN_THREAD    0x800
#endif

/*User provided configurations*/
#ifndef CONFIGURATION_VERSION
  #define CONFIGURATION_VERSION          0x00000001 // if default configuration is changed, update this number
#endif

#ifndef BONJOUR_SERVICE_PORT
  #define BONJOUR_SERVICE_PORT           8080
#endif

#ifndef BONJOUR_SERVICE
  #define BONJOUR_SERVICE                "_easylink._tcp.local."
#endif

/* product id/key check */

/*
#ifndef PRODUCT_ID
  #error  "PRODUCT_ID must be set in 'user_config.h'."
#endif

#ifndef PRODUCT_KEY
  #error "PRODUCT_KEY must be set in 'user_config.h'."
#endif

#ifndef DEFAULT_ROM_VERSION
  #error  "DEFAULT_ROM_VERSION must be set in 'user_config.h'."
#endif

#ifndef DEFAULT_DEVICE_NAME
  #error  "DEFAULT_DEVICE_NAME must be set in 'user_config.h'."
#endif
*/

#ifndef FOG_V2_PRODUCT_ID
  #error  "FOG_V2_PRODUCT_ID must be set in 'fog_v2_config.h' or 'user_config.h'."
#endif

#ifndef FOG_V2_REPORT_VER
  #error "PRODUCT_KEY must be set in 'fog_v2_config.h' or 'user_config.h'."
#endif

#ifndef FOG_V2_REPORT_VER_NUM
  #error  "DEFAULT_ROM_VERSION must be set in 'fog_v2_config.h' or 'user_config.h'."
#endif

#ifndef FOG_V2_MODULE_TYPE
  #error  "DEFAULT_DEVICE_NAME must be set in 'fog_v2_config.h'."
#endif


//typedef mico_Context_t app_context_t;


#endif  // __MICOAPPDEFINE_H
