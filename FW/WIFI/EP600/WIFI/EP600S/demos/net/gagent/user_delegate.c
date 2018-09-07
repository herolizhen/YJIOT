/**
 ******************************************************************************
 * @file    user_delegate.c
 * @author  Eshen Wang
 * @version V1.0.0
 * @date    15-Dec-2015
 * @brief   This file provide delegate functons for callbacks.
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
#include "CheckSumUtils.h"
#include "user_defines.h"   
#include "gagent.h"

#define user_delegate_log(M, ...) custom_log("Config Delegate", M, ##__VA_ARGS__)
#define user_delegate_log_trace() custom_log_trace("Config Delegate")

#define GREEN_LED_TRIGGER_INTERVAL                        (2000)  // 2s 
#define GREEN_LED_TRIGGER_INTERVAL_GOT_SSID_KEY           (4000)  // 4s 
#define GREEN_LED_TRIGGER_INTERVAL_CLOUD_CONNECTED        (4000)  // 4s

static mico_timer_t _Led_green_timer = {NULL, NULL, NULL};
static mico_timer_t _Led_red_timer =  {NULL, NULL, NULL};

static void _led_green_Timeout_handler( void* arg )
{
  (void)(arg);
  
  // green led bink
   MicoGpioOutputTrigger((mico_gpio_t)MICO_SYS_LED);
}

static void _led_red_Timeout_handler( void* arg )
{
  (void)(arg);
  
  // red led bink
   MicoGpioOutputTrigger((mico_gpio_t)MICO_RF_LED);
}

USED void mico_system_delegate_config_will_start( void )
{
  // red led off
  MicoRfLed(false);  
  
  // green led bink 2s(cycle=4s)
  if(_Led_green_timer.handle){
    mico_stop_timer(&_Led_green_timer);
    mico_deinit_timer( &_Led_green_timer );
    _Led_green_timer.handle = NULL;
  }
  mico_init_timer(&_Led_green_timer, GREEN_LED_TRIGGER_INTERVAL, _led_green_Timeout_handler, NULL);
  mico_start_timer(&_Led_green_timer);
  return;
}

USED void mico_system_delegate_soft_ap_will_start( void )
{
  // red led on
  MicoRfLed(true);  
  
  // green led off
  MicoSysLed(false);  
  
  return;
}

USED void mico_system_delegate_config_will_stop( void )
{
  // green led on
  if(_Led_green_timer.handle){
    mico_stop_timer(&_Led_green_timer);
    mico_deinit_timer( &_Led_green_timer );
    _Led_green_timer.handle = NULL;
  }
  MicoSysLed(true);
  
  return;
}

USED void mico_system_delegate_config_recv_ssid ( char *ssid, char *key )
{
  UNUSED_PARAMETER(ssid);
  UNUSED_PARAMETER(key);
  
  // red led on
  MicoRfLed(true);
  
  // green led bink 4s(cycle=8s)
  if(_Led_green_timer.handle){
    mico_stop_timer(&_Led_green_timer);
    mico_deinit_timer( &_Led_green_timer );
    _Led_green_timer.handle = NULL;
  }
  mico_init_timer(&_Led_green_timer, GREEN_LED_TRIGGER_INTERVAL_GOT_SSID_KEY, _led_green_Timeout_handler, NULL);
  mico_start_timer(&_Led_green_timer);
  return;
}

USED void mico_system_delegate_config_success( mico_config_source_t source )
{
  //system_log( "Configed by %d", source );
  UNUSED_PARAMETER(source);
  
  // red led on
  MicoRfLed(true); 
  
  // green led on
  if(_Led_green_timer.handle){
  mico_stop_timer(&_Led_green_timer);
  mico_deinit_timer( &_Led_green_timer );
  _Led_green_timer.handle = NULL;
  }
  MicoSysLed(true); 
  
  return;
}

void app_set_led_station_up ( void )
{
  // red led on
  if(_Led_red_timer.handle){
    mico_stop_timer(&_Led_red_timer);
    mico_deinit_timer( &_Led_red_timer );
    _Led_red_timer.handle = NULL;
  }
  MicoRfLed(true); 
  
  // green led on
  if(_Led_green_timer.handle){
    mico_stop_timer(&_Led_green_timer);
    mico_deinit_timer( &_Led_green_timer );
    _Led_green_timer.handle = NULL;
  }
  MicoSysLed(true); 
  
  return;
}
  
void app_set_led_station_down ( void )
{
  // red led on
  if(_Led_red_timer.handle){
    mico_stop_timer(&_Led_red_timer);
    mico_deinit_timer( &_Led_red_timer );
    _Led_red_timer.handle = NULL;
  }
  MicoRfLed(true); 
  
  // green led blink 4s
  if(_Led_green_timer.handle){
    mico_stop_timer(&_Led_green_timer);
    mico_deinit_timer( &_Led_green_timer );
    _Led_green_timer.handle = NULL;
  }
  MicoSysLed(false); 
  mico_init_timer(&_Led_green_timer, GREEN_LED_TRIGGER_INTERVAL_GOT_SSID_KEY, _led_green_Timeout_handler, NULL);
  mico_start_timer(&_Led_green_timer);
  
  return;
}

void app_set_led_status_connect_wifi(void)
{
  // red led on
  if(_Led_red_timer.handle){
    mico_stop_timer(&_Led_red_timer);
    mico_deinit_timer( &_Led_red_timer );
    _Led_red_timer.handle = NULL;
  }
  MicoRfLed(true); 
  
  // green led blink 4s
  if(_Led_green_timer.handle){
    mico_stop_timer(&_Led_green_timer);
    mico_deinit_timer( &_Led_green_timer );
    _Led_green_timer.handle = NULL;
  }
  MicoSysLed(false);
  mico_init_timer(&_Led_green_timer, GREEN_LED_TRIGGER_INTERVAL_GOT_SSID_KEY, _led_green_Timeout_handler, NULL);
  mico_start_timer(&_Led_green_timer);
  
  return;
}

//---------------------------- GAGENT delegates --------------------------------
// cloud connected callback
USED void gagent_delegate_cloud_connected ( void )
{
  user_delegate_log("USER: cloud connected.");
    
  // red led blink 4s
  if(_Led_red_timer.handle){
    mico_stop_timer(&_Led_red_timer);
    mico_deinit_timer( &_Led_red_timer );
    _Led_red_timer.handle = NULL;
  }
  MicoRfLed(false);
  mico_init_timer(&_Led_red_timer, GREEN_LED_TRIGGER_INTERVAL_CLOUD_CONNECTED, _led_red_Timeout_handler, NULL);
  mico_start_timer(&_Led_red_timer);
  
  // green led bink 4s
  if(_Led_green_timer.handle){
    mico_stop_timer(&_Led_green_timer);
    mico_deinit_timer( &_Led_green_timer );
    _Led_green_timer.handle = NULL;
  }
  MicoSysLed(true);
  mico_init_timer(&_Led_green_timer, GREEN_LED_TRIGGER_INTERVAL_CLOUD_CONNECTED, _led_green_Timeout_handler, NULL);
  mico_start_timer(&_Led_green_timer);
  
  return;
}

// cloud disconnected callback
USED void gagent_delegate_cloud_disconnected ( void )
{
  LinkStatusTypeDef station_linkstatus;
  user_delegate_log("USER: cloud disconnected.");
    
  // red led on
  if(_Led_red_timer.handle){
    mico_stop_timer(&_Led_red_timer);
    mico_deinit_timer( &_Led_red_timer );
    _Led_red_timer.handle = NULL;
  }
  MicoRfLed(true);
  
  // green led
  if(_Led_green_timer.handle){
    mico_stop_timer(&_Led_green_timer);
    mico_deinit_timer( &_Led_green_timer );
    _Led_green_timer.handle = NULL;
  }
  
  // get current staion link status
  micoWlanGetLinkStatus(&station_linkstatus);
  if(station_linkstatus.is_connected){
    MicoSysLed(true);
  }
  else{  // if station down, green led need bink 4s
    MicoSysLed(false); 
    mico_init_timer(&_Led_green_timer, GREEN_LED_TRIGGER_INTERVAL_GOT_SSID_KEY, _led_green_Timeout_handler, NULL);
    mico_start_timer(&_Led_green_timer);
  }
  
  return;
}

// cloud app2dev data callback
USED void gagent_delegate_process_app2dev_data(uint8_t *payload, uint32_t payload_len)
{
  uint8_t upload_data[2] = {REPORT_ACTION, 0x00};
  app_context_t *app_ctx = get_app_context();
  
  user_delegate_log("USER: PROCESS APP2DEV DATA.");
  
  // do control(switch1~3)
  if((3 == payload_len) && (SET_ACTION == payload[0])){
    if((1<<ATTR_FLAG_BIT_SW1) & payload[1]){
      app_ctx->appConfig->switch_1 = ((1<<ATTR_VAL_BIT_SW1) & payload[2])>>ATTR_VAL_BIT_SW1;
      user_delegate_log("----------->SW1 = %d.", app_ctx->appConfig->switch_1);
    }
    if((1<<ATTR_FLAG_BIT_SW2) & payload[1]){
      app_ctx->appConfig->switch_2 = ((1<<ATTR_VAL_BIT_SW2) & payload[2])>>ATTR_VAL_BIT_SW2;
      user_delegate_log("----------->SW2 = %d.", app_ctx->appConfig->switch_2);
    }
    if((1<<ATTR_FLAG_BIT_SW3) & payload[1]){
      app_ctx->appConfig->switch_3 = ((1<<ATTR_VAL_BIT_SW3) & payload[2])>>ATTR_VAL_BIT_SW3;
      user_delegate_log("----------->SW3 = %d.", app_ctx->appConfig->switch_3);
    }
    mico_system_context_update(mico_system_context_get());
    
    // upload status
    upload_data[1] = (app_ctx->appConfig->switch_1 << ATTR_VAL_BIT_SW1) |
      (app_ctx->appConfig->switch_2 << ATTR_VAL_BIT_SW2) |
        (app_ctx->appConfig->switch_3 << ATTR_VAL_BIT_SW3);
    user_delegate_log("upload new status: ----------> [%02X].", upload_data[1]);
    gagent_upload_mcu_data_to_all_apps(0, upload_data, sizeof(upload_data));  // upload status after operation
  }
}

// cloud app2dev data(need ack) callback
USED void gagent_delegate_process_app2dev_data_with_ack(uint8_t *payload, uint32_t payload_len, uint16_t sn)
{
  uint8_t upload_data[2] = {REPORT_ACTION, 0x00};
  app_context_t *app_ctx = get_app_context();
  
  user_delegate_log("USER: PROCESS APP2DEV DATA(need ACK, sn=%d).", sn);
  
  // do control(switch1~3)
  if((3 == payload_len) && (SET_ACTION == payload[0])){
    if((1<<ATTR_FLAG_BIT_SW1) & payload[1]){
      app_ctx->appConfig->switch_1 = ((1<<ATTR_VAL_BIT_SW1) & payload[2])>>ATTR_VAL_BIT_SW1;
      user_delegate_log("----------->SW1 = %d.", app_ctx->appConfig->switch_1);
    }
    if((1<<ATTR_FLAG_BIT_SW2) & payload[1]){
      app_ctx->appConfig->switch_2 = ((1<<ATTR_VAL_BIT_SW2) & payload[2])>>ATTR_VAL_BIT_SW2;
      user_delegate_log("----------->SW2 = %d.", app_ctx->appConfig->switch_2);
    }
    if((1<<ATTR_FLAG_BIT_SW3) & payload[1]){
      app_ctx->appConfig->switch_3 = ((1<<ATTR_VAL_BIT_SW3) & payload[2])>>ATTR_VAL_BIT_SW3;
      user_delegate_log("----------->SW3 = %d.", app_ctx->appConfig->switch_3);
    }
    mico_system_context_update(mico_system_context_get());
    
    // upload status
    upload_data[1] = (app_ctx->appConfig->switch_1 << ATTR_VAL_BIT_SW1) |
      (app_ctx->appConfig->switch_2 << ATTR_VAL_BIT_SW2) |
        (app_ctx->appConfig->switch_3 << ATTR_VAL_BIT_SW3);
    user_delegate_log("ack && upload new status: ----------> [%02X].", upload_data[1]);
    gagent_app2dev_ack(sn, upload_data, sizeof(upload_data));  // ack && upload data
  }
}

// device id got callback, store in flash
USED void gagent_delegate_update_device_id(int8_t *did, uint16_t did_len)
{
  memset(get_app_context()->appConfig->did, 0, GAGENT_DID_LEN);
  strncpy((char*)get_app_context()->appConfig->did, (char*)did, did_len);
  mico_system_context_update(mico_system_context_get());
  user_delegate_log("USER: did updated in flash, did_len=%d, did=[%s].", did_len, did);
}

// set loglevel callback, store in flash
USED void gagent_delegate_update_loglevel(uint8_t loglevel)
{
  get_app_context()->appConfig->loglevel = loglevel;
  mico_system_context_update(mico_system_context_get());
  user_delegate_log("USER: loglevel update in flash, loglevel=%d.", loglevel);
}

USED void gagent_delegate_cloud_online_app_amount_changed(uint32_t app_amount)
{
  user_delegate_log("USER: cloud online app amount=%d.", app_amount);
  get_app_context()->appStatus.cloud_app_amount = app_amount;
}

// return GAL_TRUE: need ota;
//        GAL_FALSE: not need ota.
USED int32_t gagent_delegate_cloud_ota_version_check(int8_t *soft_ver, int8_t *url, void *hctx)
{
  int32_t rc = GAGENT_FALSE;
  //app_context_t *app_ctx = (app_context_t*)hctx;
  
  // version compare
  if(0 != strncmp((char*)WIFI_SOFTWARE_VER, (char*)soft_ver, strlen((char*)soft_ver))){
    user_delegate_log("[OTA]: new firmware version found, cur_ver=[%s], new_ver=[%s]!", 
                      WIFI_SOFTWARE_VER, soft_ver);
    rc = GAGENT_TRUE;
  }
  else{
    user_delegate_log("[OTA]: no new firmware!");
  }
  
  return rc;  // if GAGENT_TRUE: need ota
}

// return GAL_TRUE: deal data ok;
//        GAL_FALSE: deal data faild.

#define SizePerRW 1024
uint8_t ota_read_data[SizePerRW] = {0};
USED int32_t gagent_delegate_cloud_ota_data_process(uint32_t offset, uint8_t *data, uint32_t data_len, gagent_ota_params_t *ota_params)
{
  int32_t rc = GAGENT_FALSE;
  OSStatus err = kUnknownErr;
  gagent_ota_params_t *ota_context = ota_params;
  mico_logic_partition_t* ota_partition = MicoFlashGetInfo( MICO_PARTITION_OTA_TEMP );
  mico_Context_t* mico_ctx = mico_system_context_get();
  
  md5_context md5;
  unsigned char md5_16[16] = {0};
  char *pmd5_32 = NULL;
  char rom_file_md5[32] = {0};
  volatile uint32_t updateStartAddress = 0;
  uint32_t readLength = 0;
  uint32_t i = 0, size = 0;
  
  // crc16
  CRC16_Context crc16_contex;
  uint16_t ota_crc16 = 0;
  
  // prepare flash
  if( 0 == offset){
    user_delegate_log("[OTA] Flash write start...");
    if(ota_partition->partition_length < ota_context->ota_firmware_size){
      user_delegate_log("ERROR: new firmware size is over OTA area size!!!");
      return GAGENT_FALSE;
    }
    err = MicoFlashErase( MICO_PARTITION_OTA_TEMP, 0x0, ota_partition->partition_length);
    if(kNoErr != err){
      user_delegate_log("ERROR: Erase OTA area err=%d.", err);
      return GAGENT_FALSE;
    }
  }
  
  // write data into flash
  user_delegate_log("[OTA] Flash write data: offset=%d, len=%d, %d/%d.", 
             offset, data_len, ota_context->wrote_offset, ota_context->ota_firmware_size);
  err = MicoFlashWrite( MICO_PARTITION_OTA_TEMP, &ota_context->wrote_offset, (uint8_t *)data, data_len);
  if(kNoErr != err){
    user_delegate_log("ERROR: [OTA] Flash write data: err=%d.", err);
    return GAGENT_FALSE;
  }
  else{
    rc = GAGENT_TRUE;
  }
  
  // flash wrote done, check md5
  if(ota_context->ota_firmware_size == (offset + data_len)){
    user_delegate_log("[OTA] Flash write done!");
    //------------------------------ OTA DATA MD5 && CRC16 check -----------------------------
    // md5 init
    InitMd5(&md5);
    CRC16_Init( &crc16_contex );
    memset(rom_file_md5, 0, 32);
    memset(ota_read_data, 0xFF, SizePerRW);
    updateStartAddress = 0;
    size = (ota_context->ota_firmware_size)/SizePerRW;
    
    // read ota data back from flash, calc md5 && crc16
    for(i = 0; i <= size; i++){
      if( i == size ){
        if( (ota_context->ota_firmware_size)%SizePerRW ){
          readLength = (ota_context->ota_firmware_size)%SizePerRW;
        }
        else{
          break;
        }
      }
      else{
        readLength = SizePerRW;
      }
      err = MicoFlashRead(MICO_PARTITION_OTA_TEMP, &updateStartAddress, ota_read_data, readLength);
      if(kNoErr != err){
        user_delegate_log("ERROR: [OTA] Read back data err=%d, offset=%d, len=%d.", err, updateStartAddress, readLength);
        return GAGENT_FALSE;
      }
      Md5Update(&md5, (uint8_t *)ota_read_data, readLength);
      CRC16_Update( &crc16_contex, ota_read_data, readLength );
    } 
    
    // read done, calc MD5 && crc16
    Md5Final(&md5, md5_16);
    CRC16_Final( &crc16_contex, &ota_crc16 );
    pmd5_32 = _DataToHexStringLowercase(md5_16,  sizeof(md5_16));  //convert hex data to hex string
    if (NULL != pmd5_32){
      user_delegate_log("[OTA] Calc file MD5[%d]=%s", strlen(pmd5_32), pmd5_32);
      strncpy(rom_file_md5, pmd5_32, strlen(pmd5_32));
      free(pmd5_32);
      pmd5_32 = NULL;
    }
    else{
      user_delegate_log("ERROR: [OTA] No memory error when calc md5!");
      return GAGENT_FALSE;
    }
    
    // check md5
    if(0 != strncmp( (char*)ota_context->ota_firmware_md5, (char*)rom_file_md5, 
                    strlen( (char*)ota_context->ota_firmware_md5))){
                      user_delegate_log("ERROR: [OTA] MD5 checksum err!!! origin_md5=[%s], calc_md5=[%s].",
                                 ota_context->ota_firmware_md5, (char*)rom_file_md5);
                      return GAGENT_FALSE;
                    }
    else{
      user_delegate_log("[OTA] MD5 checksum ok, crc16=%d.", ota_crc16);
    }
    //----------------------------------------------------------------------------
    
    // restart to update
    memset(&mico_ctx->bootTable, 0, sizeof(boot_table_t));
    mico_ctx->bootTable.length = ota_context->ota_firmware_size;
    mico_ctx->bootTable.start_address = ota_partition->partition_start_addr;
    mico_ctx->bootTable.type = 'A';
    mico_ctx->bootTable.upgrade_type = 'U';
    mico_ctx->bootTable.crc = ota_crc16;  // pass crc16 to bootloader to check update
    mico_system_context_update( mico_ctx );
    mico_system_power_perform( mico_ctx, eState_Software_Reset );
    mico_thread_sleep( MICO_WAIT_FOREVER );
    
    rc = GAGENT_TRUE;
  }
  
  return rc;  //  deal data success 
}
