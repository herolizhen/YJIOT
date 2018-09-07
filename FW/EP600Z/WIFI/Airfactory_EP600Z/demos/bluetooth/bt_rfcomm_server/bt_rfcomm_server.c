/**
 ******************************************************************************
 * @file    bt_rfcomm_server.c
 * @author  Jian Zhang
 * @version V1.0.0
 * @date    2-April-2016
 * @brief   RFCOMM Server Sample Application
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

#include <string.h>
#include <stdio.h>

#include "mico.h"
//#include "mico_bt.h"
#include "mico_bt_cfg.h"
#include "mico_bt_dev.h"
#include "mico_bt_ble.h"
#include "mico_bt_gatt.h"
#include "mico_bt_sdp.h"
#include "mico_bt_stack.h"
#include "mico_bt_rfcomm.h"
#include "bt_rfcomm_server.h"

#include "StringUtils.h"


/******************************************************
 *                      Macros
 ******************************************************/

#define mico_bt_app_log(M, ...) custom_log("APPLOG", M, ##__VA_ARGS__)

/******************************************************
 *                    Constants
 ******************************************************/

/* Mask of RFCOMM events handled by APP Callback */
#define BT_RFCOMM_SERVER_EVT_MASK               ((mico_bt_rfcomm_port_event_t) \
                                                  (MICO_BT_RFCOMM_EV_FC | MICO_BT_RFCOMM_EV_FCS | MICO_BT_RFCOMM_EV_RXCHAR \
                                                  | MICO_BT_RFCOMM_EV_TXEMPTY | MICO_BT_RFCOMM_EV_CTS | MICO_BT_RFCOMM_EV_DSR \
                                                  | MICO_BT_RFCOMM_EV_RING | MICO_BT_RFCOMM_EV_CTSS | MICO_BT_RFCOMM_EV_DSRS))


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
 *               Function Declarations
 ******************************************************/

static void bt_rfcomm_server_log_data(uint8_t *p_data, uint16_t len);
static void bt_rfcomm_server_conn_cback(mico_bt_rfcomm_result_t code, uint16_t port_handle);
static void bt_rfcomm_server_evt_cback(mico_bt_rfcomm_port_event_t event, uint16_t port_handle);
static int  bt_rfcomm_server_data_cback(uint16_t port_handle, void *p_data, uint16_t len);

/******************************************************
 *               Variable Definitions
 ******************************************************/

uint16_t bt_rfcomm_server_handle;

/******************************************************
 *               Function Definitions
 ******************************************************/

/* Initialize the RFCOMM server */
void bt_rfcomm_server_init(void)
{
    mico_bt_device_address_t bd_addr = {0};

    /* Initialize SDP Server database */
    mico_bt_sdp_db_init((uint8_t *)mico_bt_sdp_db_rfcomm, (uint16_t)mico_bt_sdp_db_size_rfcomm);

    /* Create RFCOMM server connection */
    mico_bt_rfcomm_create_connection(UUID_SERVCLASS_SERIAL_PORT,        // uuid
                                     BT_RFCOMM_SERVER_APP_SCN,          // scn (Service Class Number)
                                     TRUE,                              // is_server
                                     BT_RFCOMM_SERVER_APP_MTU,          // mtu
                                     bd_addr,                           // bd_addr
                                     &bt_rfcomm_server_handle,          // handle
                                     bt_rfcomm_server_conn_cback);      // callback

    /* Set data callback RFCOMM */
    mico_bt_rfcomm_set_data_callback(bt_rfcomm_server_handle, bt_rfcomm_server_data_cback);

    /* Set event callback RFCOMM, and events to be notified of */
    mico_bt_rfcomm_set_event_mask(bt_rfcomm_server_handle, BT_RFCOMM_SERVER_EVT_MASK);
    mico_bt_rfcomm_set_event_callback(bt_rfcomm_server_handle, bt_rfcomm_server_evt_cback);

    /* Enable connectablity (use default connectablity window/interval) */
    mico_bt_dev_set_connectability(BTM_CONNECTABLE, 0, 0);

    /* Enable discoverablity (use default discoverablity window/interval */
    mico_bt_dev_set_discoverability(BTM_GENERAL_DISCOVERABLE, 0, 0);

    mico_bt_app_log("Waiting for RFCOMM connection (scn = %d)...\n", BT_RFCOMM_SERVER_APP_SCN);
}

/* RFCOMM Connection management call back */
static void bt_rfcomm_server_conn_cback(mico_bt_rfcomm_result_t code, uint16_t port_handle)
{
    if (code == MICO_BT_RFCOMM_SUCCESS) {
        /* RFCOMM Connection established. Send test string to remote device */
        mico_bt_app_log("RFCOMM Connection establihsed.\n");
    } else if (code == MICO_BT_RFCOMM_CLOSED) {
        mico_bt_app_log("RFCOMM Connection closed.\n");
    } else {
        mico_bt_app_log("%s unhandled code = 0x%x\n", __FUNCTION__, code);
    }
}

/* RFCOMM port event callback */
static void bt_rfcomm_server_evt_cback(mico_bt_rfcomm_port_event_t event, uint16_t port_handle)
{
    mico_bt_app_log("RFCOMM Event: 0x%x\n", (int)event);
}

/* RFCOMM Data RX Callback */
static int bt_rfcomm_server_data_cback(uint16_t port_handle, void *p_data, uint16_t len)
{
    uint16_t len_sent;
    char     echo[] = "echo from server: ";
    
    mico_bt_app_log("RFCOMM RX (len = %i)\n", len);
    bt_rfcomm_server_log_data(p_data, len);

    /* Echo back to client */
    mico_bt_app_log("RFCOMM TX (len = %i)\n", len);
    bt_rfcomm_server_log_data(p_data, len);

    mico_bt_rfcomm_write_data(port_handle, (char *)echo, sizeof(echo), &len_sent);
    mico_bt_rfcomm_write_data(port_handle, (char *)p_data, len, &len_sent);
    bt_rfcomm_server_log_data(p_data, len);

    return 0;
}

/* LOG data */
static void bt_rfcomm_server_log_data(uint8_t *p_data, uint16_t len)
{
    uint16_t i, j, offset = 0;

    /* Display incoming data */
    while (len > 0) {
        mico_bt_app_log("   %04X: ", offset);

        j = 16;
        if (len < 16) j = len;

        for (i = 0; i < j; i++) {
            mico_bt_app_log("%02X ", ((uint8_t *)p_data)[offset+i]);
        }

        mico_bt_app_log("\n");
        offset += j;
        len -= j;
    }
}

