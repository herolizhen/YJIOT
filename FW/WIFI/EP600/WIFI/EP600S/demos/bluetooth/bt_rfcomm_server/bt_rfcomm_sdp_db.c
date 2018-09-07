/**
 ******************************************************************************
 * @file    bt_rfcomm_sdp_db.c
 * @author  Jian Zhang
 * @version V1.0.0
 * @date    2-April-2016
 * @brief   Pre-built SDP server database
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

#include "mico_bt_cfg.h"
#include "bt_rfcomm_server.h"
#include "mico_bt_sdp.h"

/******************************************************
 *                     Macros
*******************************************************/

/******************************************************
 *               Variables Definitions
 *****************************************************/

const uint8_t mico_bt_sdp_db_rfcomm[] = {
    SDP_ATTR_SEQUENCE_1(166),                                           // length is the sum of all records

    // first SDP record Serial Port
    SDP_ATTR_SEQUENCE_1(93),                                            // 2 bytes, length of the record
    SDP_ATTR_RECORD_HANDLE(0x10001),                                    // 8 byte
    SDP_ATTR_CLASS_ID(UUID_SERVCLASS_SERIAL_PORT),                      // 8
    SDP_ATTR_RFCOMM_PROTOCOL_DESC_LIST(BT_RFCOMM_SERVER_APP_SCN),       // 17
    SDP_ATTR_BROWSE_LIST,                                               // 8
    SDP_ATTR_LANGUAGE_BASE_ATTR_ID_LIST,                                // 14
    SDP_ATTR_PROFILE_DESC_LIST(0x1101, 0x0100),                         // 13
    SDP_ATTR_SERVICE_NAME(4),                                           // 9
        'P', 'o', 'r', 't',
    SDP_ATTR_SERVICE_DESCRIPTION(11),                                   // 16
        'S', 'e', 'r', 'i', 'a', 'l', ' ', 'P', 'o', 'r', 't',

    // second SDP record Device ID
    SDP_ATTR_SEQUENCE_1(69),                                            // 2 bytes, length of the record
    SDP_ATTR_RECORD_HANDLE(0x10002),                                    // 8 byte
    SDP_ATTR_CLASS_ID(UUID_SERVCLASS_PNP_INFORMATION),                  // 8
    SDP_ATTR_PROTOCOL_DESC_LIST(1),                                     // 18
    SDP_ATTR_UINT2(ATTR_ID_SPECIFICATION_ID, 0x103),                    // 6
    SDP_ATTR_UINT2(ATTR_ID_VENDOR_ID, 0x0f),                            // 6
    SDP_ATTR_UINT2(ATTR_ID_PRODUCT_ID, 0x0144),                         // 6
    SDP_ATTR_UINT2(ATTR_ID_PRODUCT_VERSION, 0x0001),                    // 6
    SDP_ATTR_BOOLEAN(ATTR_ID_PRIMARY_RECORD, 0x01),                     // 5
    SDP_ATTR_UINT2(ATTR_ID_VENDOR_ID_SOURCE, DI_VENDOR_ID_SOURCE_BTSIG) // 6
};

const uint16_t mico_bt_sdp_db_size_rfcomm = sizeof(mico_bt_sdp_db_rfcomm);


/******************************************************
 *                   Enumerations
 ******************************************************/

/******************************************************
 *                 Type Definitions
 ******************************************************/

/******************************************************
 *                    Structures
 ******************************************************/

/******************************************************
 *                 Global Variables
 ******************************************************/

/******************************************************
 *               Function Declarations
 ******************************************************/

