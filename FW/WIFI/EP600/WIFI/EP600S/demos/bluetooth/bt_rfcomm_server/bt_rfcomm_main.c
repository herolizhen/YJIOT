/**
 ******************************************************************************
 * @file    bt_rfcomm_main.c
 * @author  Jian Zhang
 * @version V1.0.0
 * @date    2-April-2016
 * @brief   Bluetooth Classic RFCOMM Server sample application.
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

#include <string.h>
#include <stdio.h>

#include "mico.h"
#include "mico_bt_cfg.h"
#include "mico_bt_dev.h"
#include "mico_bt_stack.h"
#include "bt_rfcomm_server.h"

#include "StringUtils.h"

/******************************************************
 *                      Macros
 ******************************************************/

#define mico_bt_app_log(M, ...) custom_log("APPLOG", M, ##__VA_ARGS__)


/******************************************************
 *                    Constants
 ******************************************************/

#define MICO_BLUETOOTH_DEVICE_NAME      "MiCO3238 RFCOMM"


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
 *               Static Function Declarations
 ******************************************************/


/******************************************************
 *               Function Declarations
 ******************************************************/

// BT Stack Event Handle
static mico_bt_dev_status_t 
bt_server_management_cback(mico_bt_management_evt_t event,
                           mico_bt_management_evt_data_t *p_event_data);

// BT Stack initialization
static void bt_server_init(void);
static void paired_list ( void );


/******************************************************
 *               Variable Definitions
 ******************************************************/

uint8_t bluetooth_device_name[] = MICO_BLUETOOTH_DEVICE_NAME;

/******************************************************
 *               Function Definitions
 ******************************************************/

int application_start(void)
{
    OSStatus err = kNoErr;
    mico_bt_app_log("BT RFCOMM SERVER DEMO");
    
    /* MiCO system initialize */
    err = mico_system_init(mico_system_context_init(0));
    require_noerr(err, exit);
    
    /* Initialize Bluetooth Controller and host stack. */
    mico_bt_stack_init(bt_server_management_cback, 
                       &mico_bt_cfg_settings_rfcomm, 
                       mico_bt_cfg_buf_pools_rfcomm);
    
exit:
    mico_rtos_delete_thread(NULL);
    return err;
}


static void bt_server_init(void)
{
    bt_rfcomm_server_init();
}

static void bt_set_bdaddr_cback(void *pl)
{
    UNUSED_PARAMETER(pl);
    mico_bt_device_address_t  bda;
    
    /* Local device address */
    mico_bt_dev_read_local_addr(bda);
    mico_bt_app_log("Local Bluetooth Address: [%02x:%02x:%02x:%02x:%02x:%02x]\n",
                    bda[0], bda[1], bda[2], bda[3], bda[4], bda[5]);
    
    /* Initialize Server */
    bt_server_init();
}

static mico_bt_dev_status_t 
bt_server_management_cback(mico_bt_management_evt_t event, 
                           mico_bt_management_evt_data_t *p_event_data)
{
    mico_bt_dev_status_t      status = MICO_BT_SUCCESS;
    BD_ADDR address;

    switch (event) {
    case BTM_ENABLED_EVT:

        /* Bluetooth controller and host stack is enabled */
        
        mico_bt_app_log("Bluetooth enabled (%s)\n", 
                          ((p_event_data->enabled.status == MICO_BT_SUCCESS) ? "success" : "failure"));

        if (p_event_data->enabled.status == MICO_BT_SUCCESS) 
        {
            paired_list();                       
            /* Set Bluetooth Device address & Enable RFCOMM Server */
            mico_bt_dev_read_local_addr(address);
            /* Re-write address to make BR/EDR pair works, DO NOT KNOW WHY! */
            mico_bt_dev_set_local_device_address((uint8_t *)address, bt_set_bdaddr_cback);
        }
        break;

    case BTM_PAIRED_DEVICE_LINK_KEYS_REQUEST_EVT:
        /* Request for stored link keys for remote device (if any) */
        mico_bt_app_log("Request device link keys");
        status = MICO_BT_UNKNOWN_ADDR;
        break;

    case BTM_PAIRED_DEVICE_LINK_KEYS_UPDATE_EVT:
        /* Request store newly generated pairing link keys to NVRAM */
        mico_bt_app_log("Update device link keys");
        break;

    case BTM_LOCAL_IDENTITY_KEYS_REQUEST_EVT:
        /* Request to restore local identity keys from NVRAM (requested during Bluetooth start up) */
        mico_bt_app_log("Request indetity keys");
        status = MICO_BT_NO_RESOURCES;
        break;

    case BTM_LOCAL_IDENTITY_KEYS_UPDATE_EVT:
        /* Request to store newly generated local identity keys to NVRAM */
        mico_bt_app_log("Update identity keys");
        break;

    case BTM_PAIRING_IO_CAPABILITIES_BR_EDR_REQUEST_EVT:        
        p_event_data->pairing_io_capabilities_br_edr_request.local_io_cap  = BTM_IO_CAPABILIES_DISPLAY_ONLY;
        p_event_data->pairing_io_capabilities_br_edr_request.oob_data      = BTM_OOB_NONE;
        p_event_data->pairing_io_capabilities_br_edr_request.auth_req      = 5;//BTM_AUTH_SPGB_YES;//BTM_LE_AUTH_REQ_BOND | BTM_LE_AUTH_REQ_MITM;
        p_event_data->pairing_io_capabilities_br_edr_request.is_orig       = FALSE;
        break;

    case BTM_PAIRING_IO_CAPABILITIES_BR_EDR_RESPONSE_EVT:
        mico_bt_app_log("The Peer device IO_CAP is 0x%x\n", 
                        p_event_data->pairing_io_capabilities_br_edr_response.io_cap);
        break;

    case BTM_USER_CONFIRMATION_REQUEST_EVT:
        /* User confirmation request for pairing */
        mico_bt_app_log("User confirmation request: numeric = %d, %s", 
                        p_event_data->user_confirmation_request.numeric_value, 
                        p_event_data->user_confirmation_request.just_works == MICO_TRUE ? "Just works" : "Not just works");
        
        mico_bt_dev_confirm_req_reply(MICO_BT_SUCCESS, p_event_data->user_confirmation_request.bd_addr);
        break;

    case BTM_PAIRING_COMPLETE_EVT:
        mico_bt_app_log("Bluetooth pairing complete, bonding_status = %d, pairing_complete_info_status = 0x%x",
                        p_event_data->pairing_complete.bonding_status,
                        p_event_data->pairing_complete.pairing_complete_info.br_edr.status);
        paired_list();
        break;

    default:
        mico_bt_app_log("Unhandled Bluetooth Management Event: 0x%x\n", event);
        break;
    }

    return status;
}

/* Helper, print info for paired devices
 */
static void printf_device_data( uint8_t *address )
{
    char* debug_str = NULL;
    debug_str = DataToHexStringWithSpaces(address, BD_ADDR_LEN);
    printf("===============Peer Device:[%s]=====================\r\n", debug_str);
    free(debug_str);
}

static void printf_key_data( char *name, uint8_t *p_data, uint16_t len )
{
    char* debug_str = NULL;
    debug_str = DataToHexStringWithSpaces(p_data, len);
    printf("    %s:[%s]\r\n", name, debug_str);
    free(debug_str);
}

static void printf_key_number( char *name, uint32_t number )
{
    printf("    %s:%d\r\n", name, number);
}

static void paired_list ( void )
{
    OSStatus err = kNoErr;
    mico_bt_dev_bonded_device_info_t device_info[20];
    uint16_t i, num_devices = 20;
    mico_bt_security_key_value_t p_sec_keys;

    err = mico_bt_dev_get_bonded_devices(device_info, &num_devices);
    require_noerr(err, exit);

    for ( i = 0; i < num_devices; i++ )
    {
        printf_device_data( device_info[i].bd_addr );

        if( kNoErr == mico_bt_dev_get_key_by_keytype(device_info[i].bd_addr, BTM_BR_EDR_LKEY, &p_sec_keys) )
        {
            printf(" BT ER/EDR Link key:\r\n");
            printf_key_number   ( "BR/EDR KEY type ", p_sec_keys.br_edr_key.br_edr_key_type );
            printf_key_data     ( "BR/EDR KEY      ", p_sec_keys.br_edr_key.br_edr_key,   BT_OCTET16_LEN );
        }
    }

exit:
    return;
}



