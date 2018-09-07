/**
 ******************************************************************************
 * @file    bt_wlan_config.c
 * @author  William Xu
 * @version V1.0.0
 * @date    27-Apr-2016
 * @brief   Reveive wlan configuration command from BLE peripheral framework
 *          and setup wlan connection
 ******************************************************************************
 *
 *  The MIT License
 *  Copyright (c) 2015 MXCHIP Inc.
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
#include "mico_bt_gatt_db.h"
#include "mico_bt.h"
#include "mico_bt_peripheral.h"
#include "mico_bt_cfg.h"

#include "StringUtils.h"
#include "LinkListUtils.h"

/******************************************************
 *                      Macros
 ******************************************************/

#define wlan_connfig_log(M, ...) custom_log("Wlan Config", M, ##__VA_ARGS__)

#define EOC_WIFI_MANAGER_CMD              0xCA
#define EOC_WIFI_MANAGER_CMD_RESPOND      0xCB

#define SOC_WIFI_MANAGER_CMD_SCAN         0xEA
#define EOC_WIFI_MANAGER_CMD_SCAN_SSID    0xEC
#define EOC_WIFI_MANAGER_CMD_SCAN_SIGNAL  0xED
#define EOC_WIFI_MANAGER_CMD_SCAN_RECORD  0xEE
#define EOC_WIFI_MANAGER_CMD_SCAN         0xEB

#define CMD_QUEUE_MSG_SIZE(len)            ( sizeof(cmd_queue_msg) + len - 1 )

/******************************************************
 *                    Constants
 ******************************************************/

typedef enum{
  WIFI_MANAGER_CMD_NONE,
  WIFI_MANAGER_CMD_SSID,
  WIFI_MANAGER_CMD_KEY,
  WIFI_MANAGER_CMD_SERVER_IP,
  WIFI_MANAGER_CMD_SERVER_PORT,
  WIFI_MANAGER_CMD_CONNECT,
  WIFI_MANAGER_CMD_SCAN,
  WIFI_MANAGER_CMD_UPLOAD_START,
  WIFI_MANAGER_CMD_UPLOAD_STOP,
  WIFI_MANAGER_CMD_NOT_FOUND,
  /*internal command*/
  WIFI_MANAGER_CMD_STATUS
} wifi_manager_cmd_e;

typedef enum{
  WIFI_MANAGER_CMD_RESPOND_NONE,
  WIFI_MANAGER_CMD_RESPOND_SSID,
  WIFI_MANAGER_CMD_RESPOND_KEY,
  WIFI_MANAGER_CMD_RESPOND_SERVER_IP,
  WIFI_MANAGER_CMD_RESPOND_SERVER_PORT,
  WIFI_MANAGER_CMD_RESPOND_CONNECT,
  WIFI_MANAGER_CMD_RESPOND_SCAN,
  WIFI_MANAGER_CMD_RESPOND_UPLOAD_START,
  WIFI_MANAGER_CMD_RESPOND_UPLOAD_STOP,
  WIFI_MANAGER_CMD_RESPOND_NOT_FOUND,
  /*internal command*/
  WIFI_MANAGER_CMD_RESPOND_STATUS_WIFI_CONNECTING, 
  WIFI_MANAGER_CMD_RESPOND_STATUS_WIFI_CONNECT_SUCCESS,
  WIFI_MANAGER_CMD_RESPOND_STATUS_WIFI_CONNECT_FAILED,
  WIFI_MANAGER_CMD_RESPOND_STATUS_DNS_SUCCESS,
  WIFI_MANAGER_CMD_RESPOND_STATUS_DNS_FAILED,
  WIFI_MANAGER_CMD_RESPOND_STATUS_SERVER_SUCCESS,
  WIFI_MANAGER_CMD_RESPOND_STATUS_SERVER_FAILED,
  WIFI_MANAGER_CMD_RESPOND_STATUS_WIFI_DISCONNECTED,
  WIFI_MANAGER_CMD_RESPOND_STATUS_WIFI_CONNECTED
} wifi_manager_cmd_respond_e;

typedef enum{
  WIFI_MANAGER_CMD,
  WIFI_MANAGER_CMD_RESPOND,
} wifi_manager_cmd_type_e;

typedef uint8_t wifi_manager_cmd_type;

/******************************************************
 *                   Enumerations
 ******************************************************/

/******************************************************
 *                 Type Definitions
 ******************************************************/
/* wlan config command messages sent to command queue and handled by commann excute handler */
typedef PACKED struct _cmd_queue_msg
{
  linked_list_node_t      this_node;      /**< Linked-list node of this msg */
  wifi_manager_cmd_type   cmd_type;       /**< Command or respond */
  uint16_t                cmd_len;        /**< Command length */
  uint8_t                 cmd[1];         /**< Command body */
} cmd_queue_msg;

/******************************************************
 *                    Structures
 ******************************************************/

/* Peripheral security settings */
static const mico_bt_smart_security_settings_t security_settings =
{
    .timeout_second              = 15,
    .io_capabilities             = BT_SMART_IO_DISPLAY_ONLY,
    .authentication_requirements = BT_SMART_AUTH_REQ_BONDING,
    .oob_authentication          = BT_SMART_OOB_AUTH_NONE,
    .max_encryption_key_size     = 16,
    .master_key_distribution     = BT_SMART_DISTRIBUTE_ALL_KEYS,
    .slave_key_distribution      = BT_SMART_DISTRIBUTE_ALL_KEYS,
};

/******************************************************
 *               Static Function Declarations
 ******************************************************/
/* Wlan config command respond */
static OSStatus wifi_manager_send_response( wifi_manager_cmd_e cmd, wifi_manager_cmd_respond_e status );

/* Ble connection handler*/
static OSStatus connection_handler( mico_bt_peripheral_socket_t* socket );
static OSStatus disconnection_handler( mico_bt_peripheral_socket_t* socket );

/* Wlan config command received handler, this function is called by ble stack */
static mico_bt_gatt_status_t cmd_write_characteristic_handler( mico_bt_ext_attribute_value_t * attribute, mico_bt_gatt_request_type_t op );

/* Command queue management, massage should be freed manually after dequeue */
static OSStatus command_queue_add( wifi_manager_cmd_type type, uint16_t cmd_len, uint8_t *p_cmd );
static OSStatus command_queue_get( cmd_queue_msg **queue_message );

/* Command message event handler, dequeue commands from queue and excute */
static OSStatus wifi_manager_cmmmand_event_handler( void *arg );


/******************************************************
 *               Function Declarations
 ******************************************************/

/******************************************************
 *               Variable Definitions
 ******************************************************/
static bool     initialized           = false;
static bool     wifi_connecting       = false;
static uint8_t  connection_err_count  = 0;

static uint16_t cmd_cur = WIFI_MANAGER_CMD_NONE;

extern mico_bt_cfg_settings_t         mico_bt_cfg_settings;
static mico_bt_peripheral_socket_t    peripheral_socket;             /* MiCO BT smart peripheral connection controller */
static mico_bt_ext_attribute_value_t* cmd_respond_attribute = NULL;  /* WiFi config command respond GATT attribute */

/* Command excute queue */
static linked_list_t cmd_queue_list;
static mico_worker_thread_t  command_excute_worker_thread; /* Worker thread to manage connection events */


/* Ble auto advertising settings */
static mico_bt_smart_advertising_settings_t advertising_settings =
{
    .type                     =  BT_SMART_UNDIRECTED_ADVERTISING,                 /**< Advertising type                                               */
    .use_high_duty            =  MICO_TRUE,                                       /**< Using high duty to start advertising                           */
    .high_duty_interval       =  MICO_BT_CFG_DEFAULT_HIGH_DUTY_ADV_MIN_INTERVAL,  /**< High duty advertising interval                                 */
    .high_duty_duration       =  30,                                              /**< High duty advertising duration in seconds (0 for infinite)     */
    .low_duty_interval        =  MICO_BT_CFG_DEFAULT_LOW_DUTY_ADV_MIN_INTERVAL,   /**< Low duty advertising interval                                  */
    .low_duty_duration        =  0,                                               /**< Low duty advertising duration in seconds (0 for infinite)      */
};

/******************************************************
 *               Function Definitions
 ******************************************************/
/* Wi-Fi states changed handler, send current Wi-Fi state using BT */
static void wifi_manager_wifi_status_changed_cb(WiFiEvent event, void* arg)
{
  UNUSED_PARAMETER(arg);
  switch (event) {
  case NOTIFY_STATION_UP:
    connection_err_count = 0;
     if( wifi_connecting == true ){
       wifi_connecting = false;
       wifi_manager_send_response( WIFI_MANAGER_CMD_STATUS, WIFI_MANAGER_CMD_RESPOND_STATUS_WIFI_CONNECT_SUCCESS );
     }else{
       wifi_manager_send_response( WIFI_MANAGER_CMD_STATUS, WIFI_MANAGER_CMD_RESPOND_STATUS_WIFI_CONNECTED );
     }
    break;
  case NOTIFY_STATION_DOWN:
    if( wifi_connecting == false )
      wifi_manager_send_response( WIFI_MANAGER_CMD_STATUS, WIFI_MANAGER_CMD_RESPOND_STATUS_WIFI_DISCONNECTED );
    break;
  default:
    break;
  }
  return;
}

/* Wi-Fi connection failed handler, send respond using BT */
static void wifi_manager_wifi_connect_failed_cb(OSStatus err, void* arg)
{
  UNUSED_PARAMETER(err);
  UNUSED_PARAMETER(arg);
  if( wifi_connecting == true ){
    connection_err_count++;
    if( connection_err_count == 5)
      wifi_manager_send_response( WIFI_MANAGER_CMD_STATUS, WIFI_MANAGER_CMD_RESPOND_STATUS_WIFI_CONNECT_FAILED );
  }
}

/* Wi-Fi scan result, send scan command respond using BT */
static void wifi_manager_scan_complete_cb(ScanResult_adv *pApList, void* arg)
{
  (void)arg;
  uint8_t *cmd_respond, *p;
  uint16_t cmd_respond_len = 0;
  uint8_t i;

  if( cmd_cur != WIFI_MANAGER_CMD_SCAN )
    return;

  /* Create a buffer to create a scan respond */
  cmd_respond = malloc(1024);
  if(cmd_respond == NULL)
    return;

  p = cmd_respond;

  *(p++) = SOC_WIFI_MANAGER_CMD_SCAN;

  for( i = 0; i < pApList->ApNum; i++){
    strncpy( (char *)p, pApList->ApList[i].ssid, 32);
    p += MIN(strlen(pApList->ApList[i].ssid), 32);

    *(p++) = EOC_WIFI_MANAGER_CMD_SCAN_SSID;

    sprintf((char *)p, "%d", pApList->ApList[i].ApPower);
    p += strlen( (char *)p);

    *(p++) = EOC_WIFI_MANAGER_CMD_SCAN_SIGNAL;

    sprintf((char *)p, "%d", pApList->ApList[i].security);
    p += strlen( (char *)p);

    *(p++) = EOC_WIFI_MANAGER_CMD_SCAN_RECORD;
  }

  *p = EOC_WIFI_MANAGER_CMD_SCAN;

  cmd_respond_len = p - cmd_respond + 1;

  command_queue_add( WIFI_MANAGER_CMD_RESPOND, cmd_respond_len, cmd_respond );
  mico_rtos_send_asynchronous_event( &command_excute_worker_thread, wifi_manager_cmmmand_event_handler, NULL );
  free(cmd_respond);
    
  cmd_cur = WIFI_MANAGER_CMD_NONE;
}

/* Send command excute respond using BT */
OSStatus wifi_manager_send_response( wifi_manager_cmd_e cmd, wifi_manager_cmd_respond_e status )
{
  OSStatus err = kNoErr;
  uint16_t cmd_previous = cmd;
  uint8_t cmd_respond[2];
  uint16_t cmd_respond_len = 2;

  require_action( cmd_cur == WIFI_MANAGER_CMD_NONE, exit, err = kStateErr );

  cmd_cur = cmd;
  cmd_respond[0] = status;
  cmd_respond[1] = EOC_WIFI_MANAGER_CMD_RESPOND;

  command_queue_add( WIFI_MANAGER_CMD_RESPOND, cmd_respond_len, cmd_respond );
  mico_rtos_send_asynchronous_event( &command_excute_worker_thread, wifi_manager_cmmmand_event_handler, NULL );

  cmd_cur = WIFI_MANAGER_CMD_NONE;

  /* Send a status respond after connect command */
  if( cmd_previous == WIFI_MANAGER_CMD_CONNECT )
  {
      wifi_manager_send_response( WIFI_MANAGER_CMD_STATUS, WIFI_MANAGER_CMD_RESPOND_STATUS_WIFI_CONNECTING );
  }

  /* Connect to wifi after send a status respond */
  if( cmd_previous == WIFI_MANAGER_CMD_STATUS && cmd_respond[0] == WIFI_MANAGER_CMD_RESPOND_STATUS_WIFI_CONNECTING)
  {
      system_connect_wifi_normal( mico_system_context_get() );
  }

exit:
  return err;
}

/* Wi-Fi config command handler, dequeue command and excute */
OSStatus wifi_manager_cmmmand_event_handler( void *arg )
{
  UNUSED_PARAMETER( arg );
  uint8_t *cmd;
  uint16_t len;
  mico_Context_t *context = mico_system_context_get();
  cmd_queue_msg *queue_message;

  while(1)
  {
    if( kNoErr != command_queue_get( &queue_message ) )
      return kNoErr;

    cmd = queue_message->cmd;
    len = queue_message->cmd_len;

    if( queue_message->cmd_type == WIFI_MANAGER_CMD_RESPOND )
    {
      mico_bt_peripheral_ext_attribute_value_write(cmd_respond_attribute, len, 0, cmd);
      mico_bt_peripheral_gatt_indicate_attribute_value( &peripheral_socket, cmd_respond_attribute );     
    }
    else
    {
      if( cmd_cur != WIFI_MANAGER_CMD_NONE )
      {
        free(queue_message);
        continue;
      }

      if( cmd[len-1] != EOC_WIFI_MANAGER_CMD ){
        wifi_manager_send_response( WIFI_MANAGER_CMD_NOT_FOUND, WIFI_MANAGER_CMD_RESPOND_NOT_FOUND );
        free(queue_message);
        continue;
      }

      switch ( *cmd ){
        case WIFI_MANAGER_CMD_SSID:
          cmd[len-1] = 0x0;
          wlan_connfig_log("Recv ssid: %s", &cmd[1]);
          strncpy(context->micoSystemConfig.ssid, (char *)&cmd[1], maxSsidLen);
          memset(context->micoSystemConfig.bssid, 0x0, 6);
          wifi_manager_send_response( WIFI_MANAGER_CMD_SSID, WIFI_MANAGER_CMD_RESPOND_SSID );
          break;

        case WIFI_MANAGER_CMD_KEY:
          cmd[len-1] = 0x0;
          wlan_connfig_log("Recv key: %s", &cmd[1]);
          strncpy(context->micoSystemConfig.user_key, (char *)&cmd[1], maxKeyLen);
          context->micoSystemConfig.user_keyLength = strlen((char *)&cmd[1]);
          wifi_manager_send_response( WIFI_MANAGER_CMD_KEY, WIFI_MANAGER_CMD_RESPOND_KEY );
          break;

        case WIFI_MANAGER_CMD_SERVER_IP:
          cmd[len-1] = 0x0;
          wlan_connfig_log("Recv server ip: %s", &cmd[1]);
          wifi_manager_send_response( WIFI_MANAGER_CMD_SERVER_IP, WIFI_MANAGER_CMD_RESPOND_SERVER_IP );
          break;

        case WIFI_MANAGER_CMD_SERVER_PORT:
          cmd[len-1] = 0x0;
          wlan_connfig_log("Recv server port: %s", &cmd[1]);
          wifi_manager_send_response( WIFI_MANAGER_CMD_SERVER_PORT, WIFI_MANAGER_CMD_RESPOND_SERVER_PORT );
          break;

        case WIFI_MANAGER_CMD_CONNECT:
          wlan_connfig_log("Connect wlan");
          context->micoSystemConfig.dhcpEnable = true;
          mico_system_delegate_config_recv_ssid(context->micoSystemConfig.ssid, context->micoSystemConfig.user_key);
          
          wifi_connecting = true;
          wifi_manager_send_response( WIFI_MANAGER_CMD_CONNECT, WIFI_MANAGER_CMD_RESPOND_CONNECT );
          break;

        case WIFI_MANAGER_CMD_SCAN:
          cmd_cur = WIFI_MANAGER_CMD_SCAN;
          wlan_connfig_log("Scan");
          micoWlanStartScanAdv();
          break;

        default:
          wifi_manager_send_response( WIFI_MANAGER_CMD_NOT_FOUND, WIFI_MANAGER_CMD_RESPOND_NOT_FOUND);
          break;
      }
    }    
    free(queue_message);
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////      BT SMARTPERIPHERAL STACK AND DATABASE ESTABLISH      /////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////


static void wlan_config_set_advertisement_data( void )
{
  mico_bt_ble_advert_data_t adv_data;
  mico_bt_ble_128service_t adver_services_128 = { .list_cmpl = false, .uuid128 = { UUID_SERVCLASS_WIFI_MANAGER }};

  /* Set advertising data: device name and discoverable flag */
  adv_data.flag = BTM_BLE_GENERAL_DISCOVERABLE_FLAG | BTM_BLE_BREDR_NOT_SUPPORTED;
  adv_data.p_services_128b = &adver_services_128;

  mico_bt_ble_set_advertisement_data( BTM_BLE_ADVERT_BIT_DEV_NAME|BTM_BLE_ADVERT_BIT_FLAGS, &adv_data);
  
  mico_bt_ble_set_scan_response_data( BTM_BLE_ADVERT_BIT_SERVICE_128, &adv_data);
}

static void mico_bt_peripheral_create_ext_attribute_values( void )
{
  uint8_t appearance_name[2] = { BIT16_TO_8(APPEARANCE_GENERIC_TAG) };

  mico_bt_peripheral_ext_attribute_add( HDLC_GENERIC_ACCESS_DEVICE_NAME_VALUE, strlen((char *)mico_bt_cfg_settings.device_name), mico_bt_cfg_settings.device_name, NULL );
  mico_bt_peripheral_ext_attribute_add( HDLC_GENERIC_ACCESS_APPEARANCE_VALUE, sizeof(appearance_name), appearance_name, NULL );

  // ***** WiFi Manager service
  /* Wi-Fi config command input attribute */
  mico_bt_peripheral_ext_attribute_add( HDLC_WIFI_MANAGER_CMD_WRITE_VALUE, 0, NULL, cmd_write_characteristic_handler );
  mico_bt_peripheral_ext_attribute_add( HDLC_WIFI_MANAGER_CMD_WRITE_DESCRIPTION, strlen("WLAN CONFIG WRITE"), (uint8_t *)"WLAN CONFIG WRITE", NULL );

  /* Wi-Fi config command respond attribute */
  mico_bt_peripheral_ext_attribute_add( HDLC_WIFI_MANAGER_CMD_RESPOND_VALUE, 0, NULL, NULL );
  mico_bt_peripheral_ext_attribute_add( HDLC_WIFI_MANAGER_CMD_RESPOND_DESCRIPTION, strlen("WLAN CONFIG RESPOND"), (uint8_t *)"WLAN CONFIG RESPOND", NULL );

  mico_bt_peripheral_ext_attribute_find_by_handle(HDLC_WIFI_MANAGER_CMD_RESPOND_VALUE, &cmd_respond_attribute);
}

/* Application entrance */
OSStatus bt_smart_init_wlanconfig( void )
{
  OSStatus err = kNoErr;

  /* Initialise MiCO Bluetooth Framework */
  err = mico_bt_init( MICO_BT_HCI_MODE, "MiCOKit EMW3238", 0, 1 );
  require_noerr_string( err, exit, "Error initializing MiCO Bluetooth Framework" );

  mico_bt_peripheral_init( &peripheral_socket, &security_settings, connection_handler, disconnection_handler, NULL );

  /* Build BT stack layer GATT database (handle, uuid, permission, properity)*/
  mico_bt_gatt_db_init( gatt_db, gatt_db_size );

  /* Build BT application layer GATT database ( extenal value, callback functions )*/
  mico_bt_peripheral_create_ext_attribute_values( );

  /* Register wlan callbacks */
  mico_system_notify_register( mico_notify_WIFI_STATUS_CHANGED, (void *)wifi_manager_wifi_status_changed_cb, NULL );
  mico_system_notify_register( mico_notify_WIFI_SCAN_ADV_COMPLETED, (void *)wifi_manager_scan_complete_cb, NULL );
  mico_system_notify_register( mico_notify_WIFI_CONNECT_FAILED, (void *)wifi_manager_wifi_connect_failed_cb, NULL );

  /* Set the advertising parameters and make the device discoverable */
  wlan_config_set_advertisement_data();
  mico_bt_peripheral_start_advertisements( &advertising_settings, NULL );

  /* Create wlan config command excute queue and thread */
  err = linked_list_init(&cmd_queue_list);
  require_noerr(err, exit);

  /* Create a worker thread for making a connection and control event */
  mico_rtos_create_worker_thread( &command_excute_worker_thread, MICO_DEFAULT_WORKER_PRIORITY, 2048, 1 );

  initialized = true;

exit:
  return err;
}

OSStatus connection_handler( mico_bt_peripheral_socket_t* socket )
{
  OSStatus result;
  wlan_connfig_log( "bt_conn_up id:0x%4x:", socket->connection_handle );

  /* Stop advertising */
  result =  mico_bt_peripheral_stop_advertisements( );
  wlan_connfig_log( "Stopping Advertisements %d", result);

  return result;
}

OSStatus disconnection_handler( mico_bt_peripheral_socket_t* socket )
{
  OSStatus result;
  UNUSED_PARAMETER(socket);

  /* Start infinit advertising */
  result = mico_bt_peripheral_start_advertisements( &advertising_settings, NULL );
  wlan_connfig_log( "mico_bt_start_advertisements %d", result );

  return result;
}

mico_bt_gatt_status_t cmd_write_characteristic_handler( mico_bt_ext_attribute_value_t* attribute, mico_bt_gatt_request_type_t op )
{
  if( op != GATTS_REQ_TYPE_WRITE )
  {
      return MICO_BT_GATT_REQ_NOT_SUPPORTED;
  }
  
  if( initialized == true ) 
  {
    /* Push wlan config command to queue */
    command_queue_add( WIFI_MANAGER_CMD, attribute->value_length, attribute->p_value );
    mico_rtos_send_asynchronous_event( &command_excute_worker_thread, wifi_manager_cmmmand_event_handler, NULL );
  }
  return MICO_BT_GATT_SUCCESS;
}


static OSStatus command_queue_add( wifi_manager_cmd_type type, uint16_t cmd_len, uint8_t *p_cmd )
{
    OSStatus err = kNoErr;

    cmd_queue_msg *queue_message = malloc( CMD_QUEUE_MSG_SIZE(cmd_len) );
    require_action( queue_message, exit, err = kNoMemoryErr );

    queue_message->cmd_type = type;
    queue_message->cmd_len = cmd_len;
    memcpy( queue_message->cmd, p_cmd, cmd_len );

    err = linked_list_insert_node_at_rear( &cmd_queue_list, &queue_message->this_node );
    require_noerr(err, exit);

exit:
    return err;
}

static OSStatus command_queue_get( cmd_queue_msg **queue_message )
{
    OSStatus err = kNoErr;

    err = linked_list_remove_node_from_front( &cmd_queue_list, (linked_list_node_t **)queue_message );
    require_noerr_quiet(err, exit);

exit:
    return err;
}





