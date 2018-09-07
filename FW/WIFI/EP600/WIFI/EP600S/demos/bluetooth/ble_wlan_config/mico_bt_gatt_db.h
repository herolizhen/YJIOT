/**
 ******************************************************************************
 * @file    mico_bt_gatt_db.h
 * @author  William Xu
 * @version V1.0.0
 * @date    27-Apr-2016
 * @brief   BLE vender specific device GATT UUID and handler definition
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

#pragma once
#include "mico.h"
#include "mico_bt.h"

#ifdef __cplusplus
extern "C" {
#endif

// Test service UUID: 4554
#define UUID_SERVCLASS_TEST        0x4554
// Test service read characteristic UUID: 0x4555
#define GATT_UUID_TEST_READ        0x4555

// WiFI manager service UUID: 0783B03E-8535-B5A0-7140-A304D2495CB7
#define UUID_SERVCLASS_WIFI_MANAGER  0xB7, 0x5C, 0x49, 0xD2, 0x04, 0xA3, 0x40, 0x71, 0xA0, 0xB5, 0x35, 0x85, 0x3E, 0xB0, 0x83, 0x07       
// WiFI manager characteristic (command write) UUID: 0783B03E-8535-B5A0-7140-A304D2495CBA
#define GATT_UUID_WIFI_MANAGER_CMD_WRITE  0xBA, 0x5C, 0x49, 0xD2, 0x04, 0xA3, 0x40, 0x71, 0xA0, 0xB5, 0x35, 0x85, 0x3E, 0xB0, 0x83, 0x07
// WiFI manager characteristic (command respond) UUID: 0783B03E-8535-B5A0-7140-A304D2495CB8
#define GATT_UUID_WIFI_MANAGER_CMD_RESPOND  0xB8, 0x5C, 0x49, 0xD2, 0x04, 0xA3, 0x40, 0x71, 0xA0, 0xB5, 0x35, 0x85, 0x3E, 0xB0, 0x83, 0x07

// WiFI manager service UUID: 0783B03E-8535-B5A0-7140-A304D2495CB7
#define UUID_SERVCLASS_WIFI_MANAGER2  0xA7, 0x5C, 0x49, 0xD2, 0x04, 0xA3, 0x40, 0x71, 0xA0, 0xB5, 0x35, 0x85, 0x3E, 0xB0, 0x83, 0x07       
// WiFI manager characteristic (command write) UUID: 0783B03E-8535-B5A0-7140-A304D2495CBA
#define GATT_UUID_WIFI_MANAGER_CMD_WRITE2  0xAA, 0x5C, 0x49, 0xD2, 0x04, 0xA3, 0x40, 0x71, 0xA0, 0xB5, 0x35, 0x85, 0x3E, 0xB0, 0x83, 0x07
// WiFI manager characteristic (command respond) UUID: 0783B03E-8535-B5A0-7140-A304D2495CB8
#define GATT_UUID_WIFI_MANAGER_CMD_RESPOND2  0xA8, 0x5C, 0x49, 0xD2, 0x04, 0xA3, 0x40, 0x71, 0xA0, 0xB5, 0x35, 0x85, 0x3E, 0xB0, 0x83, 0x07

enum {
    // ***** Primary service 'Generic Access'
    HDLS_GENERIC_ACCESS,
    HDLC_GENERIC_ACCESS_DEVICE_NAME,
    HDLC_GENERIC_ACCESS_DEVICE_NAME_VALUE,
    HDLC_GENERIC_ACCESS_APPEARANCE,
    HDLC_GENERIC_ACCESS_APPEARANCE_VALUE,

    // ***** WLAN CONFIG service
    HDLS_WIFI_MANAGER,
    HDLC_WIFI_MANAGER_CMD_WRITE,
    HDLC_WIFI_MANAGER_CMD_WRITE_VALUE,
    HDLC_WIFI_MANAGER_CMD_WRITE_DESCRIPTION,
    HDLC_WIFI_MANAGER_CMD_RESPOND,
    HDLC_WIFI_MANAGER_CMD_RESPOND_VALUE,
    HDLC_WIFI_MANAGER_CMD_RESPOND_DESCRIPTION,
};


extern const uint8_t  gatt_db[];
extern const uint16_t gatt_db_size;

#ifdef __cplusplus
}
#endif
