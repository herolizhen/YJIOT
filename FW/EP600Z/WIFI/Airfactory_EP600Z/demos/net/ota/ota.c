/**
 ******************************************************************************
 * @file    ota.c
 * @author  QQ ding
 * @version V1.0.0
 * @date    219-Oct-2016
 * @brief   Firmware update example
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
#include "ota_server.h"

#define ota_log(M, ...) custom_log("OTA", M, ##__VA_ARGS__)

static mico_semaphore_t wait_sem = NULL;
static char ota_url[50];
static char ota_md5[33];

static void micoNotify_WifiStatusHandler( WiFiEvent status, void* const inContext )
{
    switch ( status )
    {
        case NOTIFY_STATION_UP:
            mico_rtos_set_semaphore( &wait_sem );
            break;
        case NOTIFY_STATION_DOWN:
            case NOTIFY_AP_UP:
            case NOTIFY_AP_DOWN:
            break;
    }
}

static void ota_server_status_handler(OTA_STATE_E state, float progress)
{
    switch ( state )
    {
        case OTA_LOADING:
            ota_log("ota server is loading, progress %.2f%%", progress);
            break;
        case OTA_SUCCE:
            ota_log("ota server daemons success");
            break;
        case OTA_FAIL:
            ota_log("ota server daemons failed");
            break;
        default:
            break;
    }
}

static void ota_set_url(char *pcWriteBuffer, int xWriteBufferLen,int argc, char **argv)
{
    strcpy(ota_url, argv[1]);
}

static void ota_set_md5(char *pcWriteBuffer, int xWriteBufferLen,int argc, char **argv)
{
    strcpy(ota_md5, argv[1]);
}

static void ota_server_option(char *pcWriteBuffer, int xWriteBufferLen,int argc, char **argv)
{
    if( !strcmp(argv[1], "start") ){
        ota_server_start(ota_url, ota_md5, ota_server_status_handler);
    }else if( !strcmp(argv[1], "pause") ){
        ota_server_pause();
    }else if( !strcmp(argv[1], "continue") ){
        ota_server_continue();
    }else if( !strcmp(argv[1], "stop") ){
        ota_server_stop();
    }
}

static const struct cli_command ota_clis[] = {
    {"ota_url", "set ota server download url", ota_set_url},
    {"ota_md5", "set update file check", ota_set_md5},
    {"ota_op", "ota server option", ota_server_option},
};

int application_start( void )
{
    OSStatus err = kNoErr;

    mico_rtos_init_semaphore( &wait_sem, 1 );

    /*Register user function for MiCO nitification: WiFi status changed */
    err = mico_system_notify_register( mico_notify_WIFI_STATUS_CHANGED,
                                       (void *) micoNotify_WifiStatusHandler,
                                       NULL );
    require_noerr( err, exit );

    /* Start MiCO system functions according to mico_config.h*/
    err = mico_system_init( mico_system_context_init( 0 ) );
    require_noerr( err, exit );

    /* Wait for wlan connection*/
    mico_rtos_get_semaphore( &wait_sem, MICO_WAIT_FOREVER );
    ota_log( "wifi connected successful" );

    cli_register_commands(ota_clis, sizeof(ota_clis)/sizeof(struct cli_command));

    exit:
    if ( wait_sem != NULL )
        mico_rtos_deinit_semaphore( &wait_sem );
    mico_rtos_delete_thread( NULL );
    return err;
}

