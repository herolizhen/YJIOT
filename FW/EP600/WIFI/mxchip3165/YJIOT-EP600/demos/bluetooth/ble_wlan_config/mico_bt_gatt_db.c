/**
 ******************************************************************************
 * @file    mico_bt_gatt_db.c
 * @author  William Xu
 * @version V1.0.0
 * @date    27-Apr-2016
 * @brief   BLE vender specific device GATT database definition
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

#include "mico_bt_gatt.h"
#include "gattdefs.h"
#include "sdpdefs.h"
#include "mico_bt_cfg.h"
#include "mico_bt_gatt_db.h"

/* GATT database */
const PACKED uint8_t gatt_db[] =
{
  // Generic Access service
  PRIMARY_SERVICE_UUID16( HDLS_GENERIC_ACCESS, UUID_SERVCLASS_GAP_SERVER),

  CHARACTERISTIC_UUID16 ( HDLC_GENERIC_ACCESS_DEVICE_NAME,
                          HDLC_GENERIC_ACCESS_DEVICE_NAME_VALUE,
                          GATT_UUID_GAP_DEVICE_NAME,
                          LEGATTDB_CHAR_PROP_READ,
                          LEGATTDB_PERM_READABLE),

  CHARACTERISTIC_UUID16 ( HDLC_GENERIC_ACCESS_APPEARANCE,
                          HDLC_GENERIC_ACCESS_APPEARANCE_VALUE,
                          GATT_UUID_GAP_ICON,
                          LEGATTDB_CHAR_PROP_READ,
                          LEGATTDB_PERM_READABLE),

  // ***** WLAN CONFIG service
  PRIMARY_SERVICE_UUID128 ( HDLS_WIFI_MANAGER, UUID_SERVCLASS_WIFI_MANAGER ),

  CHARACTERISTIC_UUID128_WRITABLE ( HDLC_WIFI_MANAGER_CMD_WRITE,
                                    HDLC_WIFI_MANAGER_CMD_WRITE_VALUE,
                                    GATT_UUID_WIFI_MANAGER_CMD_WRITE,
                                    LEGATTDB_CHAR_PROP_WRITE,
                                    LEGATTDB_PERM_WRITE_CMD | LEGATTDB_PERM_WRITE_REQ),
  CHAR_DESCRIPTOR_UUID16  ( HDLC_WIFI_MANAGER_CMD_WRITE_DESCRIPTION, 
                            GATT_UUID_CHAR_DESCRIPTION,
                            LEGATTDB_PERM_READABLE ),
  
  CHARACTERISTIC_UUID128  ( HDLC_WIFI_MANAGER_CMD_RESPOND,
                            HDLC_WIFI_MANAGER_CMD_RESPOND_VALUE,
                            GATT_UUID_WIFI_MANAGER_CMD_RESPOND,
                            LEGATTDB_CHAR_PROP_INDICATE | LEGATTDB_CHAR_PROP_NOTIFY,
                            LEGATTDB_PERM_NONE ),
  CHAR_DESCRIPTOR_UUID16  ( HDLC_WIFI_MANAGER_CMD_RESPOND_DESCRIPTION, 
                            GATT_UUID_CHAR_DESCRIPTION,
                            LEGATTDB_PERM_READABLE ),
};

const uint16_t gatt_db_size = sizeof(gatt_db);




