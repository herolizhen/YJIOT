/**
  ******************************************************************************
  * @file    user_config.h 
  * @author  Eshen Wang
  * @version V1.0.0
  * @date    14-May2015
  * @brief   User configuration file.
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

#ifndef __USER_CONFIG_H_
#define __USER_CONFIG_H_

//#include "mico_config.h"

/*******************************************************************************
 *                             APP INFO
 ******************************************************************************/

/*------------------------------ product -------------------------------------*/
/*
#ifdef MICOKIT_3288
// wes' product, replace it with your own product
  #define PRODUCT_ID                   "e0ef908d"
  #define PRODUCT_KEY                  "86cc4e1b-b581-442f-bc73-e6d91df77dd8"
#elif  MICOKIT_3165
  //#define PRODUCT_ID                   "cf0fa23b" 
 // #define PRODUCT_KEY                  "f1e2afc9-4414-4f8e-a471-0d08fe1019b5"
 #define PRODUCT_ID                    "227256da"
 #define PRODUCT_KEY                   "77ea1561-e360-40d7-8e8e-83cf50932c5d"
#elif  MICOKIT_G55
  #define PRODUCT_ID                   "5e0f6691"
  #define PRODUCT_KEY                  "14cf3d82-cdf2-4954-8dc6-0009cc9365f2"
#else

#endif
*/

/*******************************************************************************
*                             REDEFINED  MODEL
******************************************************************************/
#if defined  MODEL
#undef MODEL
#define MODEL                          "MODBUS"
//#define MODEL                          "EP1500"
#endif

//重新定义产品ID
#if defined  FOG_V2_PRODUCT_ID
#undef FOG_V2_PRODUCT_ID
#endif

#define FOG_V2_PRODUCT_ID                          ("caef583f-f0d5-4f79-bfef-29c78ba802e1")


//重新定义固件主版本号
#if defined  FOG_V2_REPORT_VER
#undef FOG_V2_REPORT_VER
#endif
#define FOG_V2_REPORT_VER                          ("modbus@") 
//#define FOG_V2_REPORT_VER                          ("EP1500FV2@") 

//重新定义固件次版本号
#if defined  FOG_V2_REPORT_VER_NUM
#undef FOG_V2_REPORT_VER_NUM
#endif
#define FOG_V2_REPORT_VER_NUM                          ("001")

/*******************************************************************************
 *                             CONNECTING
 ******************************************************************************/

/* MICO cloud service */
//#define MICO_CLOUD_TYPE               CLOUD_FOGCLOUD

/* Firmware update check
 * If need to check new firmware on server after wifi on, comment out this macro
 */
//#define DISABLE_FOGCLOUD_OTA_CHECK


/*******************************************************************************
 *                             RESOURCES
 ******************************************************************************/

/* stack size of the user_main thread */
#define STACK_SIZE_USER_MAIN_THREAD    0x800

//#define STACK_SIZE_USER_DOWNSTREAM_THREAD 0x400
#define STACK_SIZE_USER_DOWNSTREAM_THREAD 0x800
//#define STACK_SIZE_USER_UPSTREAM_THREAD   0x400
//fogcloud v2 upstream_thread栈设置为0x400会溢出，需加大
#define STACK_SIZE_USER_UPSTREAM_THREAD   0x800
//UART_RECV_THREADH和CHARGE_THREAD两个线程建立的比OTA线程早，如果这两个线程的栈空间和大于0x800会导致不能OTA，出现ssl connect错误，此处需特别注意
//#define STACK_SIZE_UART_RECV_THREAD       0x400
#define STACK_SIZE_UART_RECV_THREAD       0x400

#define STACK_SIZE_USER_UART_DATA_PROCESS_THREAD 0x800

/* User provided configurations seed
 * If user configuration(params in flash) is changed, update this number to
 * indicate the bootloader to clean params in flash next time restart.
 */
#define CONFIGURATION_VERSION          0x00000003


#endif  // __USER_CONFIG_H_

