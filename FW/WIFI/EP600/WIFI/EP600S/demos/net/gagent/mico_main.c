/**
 ******************************************************************************
 * @file    mico_mian.c
 * @author  Eshen Wang
 * @version V1.0.0
 * @date    15-Dec-2015
 * @brief   MiCO application entrance file.
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
 ******************************************************************************
 */

#include "mico.h"
#include "user_defines.h"
#include "gagent.h"

#define app_log(M, ...) custom_log("APP", M, ##__VA_ARGS__)

uint8_t force_upload_data[2] = {REPORT_ACTION, 0x00};

static app_context_t* app_context = NULL;
static mico_semaphore_t wifi_on_semaphore = NULL;

extern void app_set_led_station_up(void);
extern void app_set_led_station_down(void);
extern void app_set_led_status_connect_wifi(void);

extern OSStatus bt_smart_init_wlanconfig( void );

app_context_t* get_app_context( void )
{
  return app_context;
}

static void appNotify_WifiStatusHandler( WiFiEvent status, void* const inContext )
{
  UNUSED_PARAMETER(inContext);
  
  switch (status) {
  case NOTIFY_STATION_UP:
    mico_rtos_set_semaphore( &wifi_on_semaphore );
    app_set_led_station_up();
    break;
  case NOTIFY_STATION_DOWN:
    app_set_led_station_down();
    break;
  default:
    break;
  }
}

/* MICO system callback: Restore default configuration provided by application */
void appRestoreDefault_callback(void * const user_config_data, uint32_t size)
{
  UNUSED_PARAMETER(size);
  mico_system_context_get()->micoSystemConfig.dhcpEnable = true;
  
  application_config_t* appConfig = user_config_data;
  appConfig->configDataVer = CONFIGURATION_VERSION;
  
  // restore board control
  appConfig->switch_1 = 0;
  appConfig->switch_2 = 0;
  appConfig->switch_3 = 0;
  
  // restore gagent configurations
  gagent_connection_reset();
  
  memset(appConfig->did, 0, GAGENT_DID_LEN);
  memset(appConfig->passcode, 0, GAGENT_PASSCODE_MAXLEN);
  appConfig->loglevel = GAGENT_LOG_LEVEL_NONE;   // default: no log
  make_rand_passcode(appConfig->passcode);  // generate new passcode
}

int application_start( void )
{
  OSStatus err = kNoErr;
  int32_t rc = GAGENT_OK;
  mico_Context_t* mico_context = NULL;
  gagent_context gagent_conn_ctx;
  int8_t test_upload_log[100] = {0};
  uint32_t gagent_sdk_ver = 0;
  mico_system_status_wlan_t* wlan_status;

  /* Create application context */
  app_context = ( app_context_t *)calloc(1, sizeof(app_context_t) );
  require_action( app_context, exit, err = kNoMemoryErr );

  /* Create mico system context and read application's config data from flash */
  mico_context = mico_system_context_init( sizeof( application_config_t) );
  app_context->appConfig = mico_system_context_get_user_data( mico_context );
  
  /* user params restore check */
  if(app_context->appConfig->configDataVer != CONFIGURATION_VERSION){
    app_log("WARNGIN: user params restored! %d", app_context->appConfig->configDataVer);
    err = mico_system_context_restore(mico_context);
    require_noerr( err, exit );
  }
  
  /* wifi semaphore init */
  mico_rtos_init_semaphore(&wifi_on_semaphore, 1);
  err = mico_system_notify_register( mico_notify_WIFI_STATUS_CHANGED, 
                                    (void *)appNotify_WifiStatusHandler, app_context );
  require_noerr( err, exit );
  
  /* mico system initialize */
  err = mico_system_init( mico_context );
  require_noerr( err, exit );

  /* wait for wifi station on */
  err = mico_rtos_get_semaphore(&wifi_on_semaphore, MICO_WAIT_FOREVER);
  require_noerr( err, exit );
  
  app_context->appStatus.cloud_app_amount = 0;
  
  /* get sdk version */
  gagent_sdk_ver = gagent_sdk_version();
  app_log("GAGENT SDK version: [%d.%d.%d]", 0xFF & (gagent_sdk_ver >> 16), 
                                            0xFF & (gagent_sdk_ver >> 8), 
                                            0xFF &  gagent_sdk_ver);
  
  /* start gagent connection */
  // set gagent connetion context
  memset(&gagent_conn_ctx, 0, sizeof(gagent_conn_ctx));
  // set wifi info
  mico_system_get_status_wlan( &wlan_status );
  _format_mac((char*)gagent_conn_ctx.wifi_info.mac, wlan_status->mac, GAGENT_MAC_LEN);
  strncpy((char*)gagent_conn_ctx.wifi_info.general_protocol_ver, WIFI_GENERAL_PROTOCOL_VER, GAGENT_GENERAL_PROTOCOL_VER_LEN);
  strncpy((char*)gagent_conn_ctx.wifi_info.hardware_ver, WIFI_HARDWARE_VER, GAGENT_HARDWARE_VER_LEN);
  strncpy((char*)gagent_conn_ctx.wifi_info.software_ver, WIFI_SOFTWARE_VER, GAGENT_SOFTWARE_VER_LEN);
  // set mcu info
  gagent_conn_ctx.mcu_info.bindable_time = BINDABLE_TIME;  // default bindable time
  strncpy((char*)gagent_conn_ctx.mcu_info.product_key, PRODUCT_KEY, GAGENT_PRODUCT_KEY_LEN);
  strncpy((char*)gagent_conn_ctx.mcu_info.general_protocol_ver, MCU_GENERAL_PROTOCOL_VER, GAGENT_GENERAL_PROTOCOL_VER_LEN);
  strncpy((char*)gagent_conn_ctx.mcu_info.business_protocol_ver, BUSINESS_PROTOCOL_VER, GAGENT_BUSINESS_PROTOCOL_VER_LEN);
  strncpy((char*)gagent_conn_ctx.mcu_info.hardware_ver, MCU_HARDWARE_VER, GAGENT_HARDWARE_VER_LEN);
  strncpy((char*)gagent_conn_ctx.mcu_info.software_ver, MCU_SOFTWARE_VER, GAGENT_SOFTWARE_VER_LEN);
  // set passcode/did/firmware_ver/loglevel/user_context
  strncpy((char*)gagent_conn_ctx.passcode, (char*)app_context->appConfig->passcode, GAGENT_PASSCODE_MAXLEN);
  strncpy((char*)gagent_conn_ctx.did, (char*)app_context->appConfig->did, GAGENT_DID_LEN);
  strncpy((char*)gagent_conn_ctx.FirmwareVer, WIFI_FIRMWARE_VER, GAGENT_FIRMWARELEN);
  gagent_conn_ctx.loglevel = app_context->appConfig->loglevel;
  gagent_conn_ctx.user_context = app_context;
 
  rc = gagent_connection_start(&gagent_conn_ctx);
  require_action((GAGENT_OK == rc), exit, 
                 app_log("ERROR: gagent_connection_start err=%d.", rc));
  
  mico_thread_sleep(5);
  while(1){
    // upload data
    force_upload_data[1] = (app_context->appConfig->switch_1 << ATTR_VAL_BIT_SW1) |
      (app_context->appConfig->switch_2 << ATTR_VAL_BIT_SW2) |
        (app_context->appConfig->switch_3 << ATTR_VAL_BIT_SW3);
    app_log("force upload: ----------> [%02X].", force_upload_data[1]);
    gagent_upload_mcu_data_to_all_apps(0, force_upload_data, sizeof(force_upload_data));
    
    mico_thread_sleep(3);
    // test upload log
    snprintf((char*)test_upload_log, 100, "Cloud data upload.");
    rc = gagent_upload_log(GAGENT_LOG_TYPE_ALL, GAGENT_LOG_INFO, 
                           "GAGENT", "CLOUD", test_upload_log, 
                           strlen((char*)test_upload_log));
    if(GAGENT_OK != rc){
      app_log("ERROR: upload log err=%d.", rc);
    }
    mico_thread_sleep(12);
  }

exit:
  mico_rtos_delete_thread( NULL );
  return err;
}
