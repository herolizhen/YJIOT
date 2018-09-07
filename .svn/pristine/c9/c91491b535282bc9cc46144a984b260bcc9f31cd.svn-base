/**
 ******************************************************************************
 * @file    MICOAppEntrance.c
 * @author  William Xu
 * @version V1.0.0
 * @date    05-May-2014
 * @brief   Mico application entrance, addd user application functons and threads.
 ******************************************************************************
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

#include "StringUtils.h"
#include "SppProtocol.h"
#include "cfunctions.h"
#include "cppfunctions.h"
#include "MICOAppDefine.h"

#define app_log(M, ...) custom_log("APP", M, ##__VA_ARGS__)
#define app_log_trace() custom_log_trace("APP")

volatile ring_buffer_t rx_buffer;
volatile uint8_t rx_data[UART_BUFFER_LENGTH];

extern void localTcpServer_thread( uint32_t inContext );

extern void remoteTcpClient_thread( uint32_t inContext );

extern void uartRecv_thread( uint32_t inContext );

extern OSStatus MICOStartBonjourService( WiFi_Interface interface, app_context_t * const inContext );

/* MICO system callback: Restore default configuration provided by application */
void appRestoreDefault_callback( void * const user_config_data, uint32_t size )
{
    UNUSED_PARAMETER( size );
    application_config_t* appConfig = user_config_data;
    appConfig->configDataVer = CONFIGURATION_VERSION;
    appConfig->localServerPort = LOCAL_PORT;
    appConfig->localServerEnable = true;
    appConfig->USART_BaudRate = 115200;
    appConfig->remoteServerEnable = true;
    sprintf( appConfig->remoteServerDomain, DEAFULT_REMOTE_SERVER );
    appConfig->remoteServerPort = DEFAULT_REMOTE_SERVER_PORT;
}

/* EasyLink callback: Notify wlan configuration type */
USED void mico_system_delegate_config_success( mico_config_source_t source )
{
    app_log( "Configured by %d", source );
}

/* Config server callback: Current Device configuration sent to config client */
USED void config_server_delegate_report( json_object *app_menu, mico_Context_t *in_context )
{
    OSStatus err = kNoErr;
    application_config_t *appConfig = mico_system_context_get_user_data( in_context );

    // SPP protocol remote server connection enable
    err = config_server_create_bool_cell( app_menu, "Connect SPP Server", appConfig->remoteServerEnable, "RW" );
    require_noerr( err, exit );

    //Server address cell
    err = config_server_create_string_cell( app_menu, "SPP Server", appConfig->remoteServerDomain, "RW", NULL );
    require_noerr( err, exit );

    //Server port cell
    err = config_server_create_number_cell( app_menu, "SPP Server Port", appConfig->remoteServerPort, "RW", NULL );
    require_noerr( err, exit );

    /*UART Baurdrate cell*/
    json_object *selectArray;
    selectArray = json_object_new_array( );
    require( selectArray, exit );
    json_object_array_add( selectArray, json_object_new_int( 9600 ) );
    json_object_array_add( selectArray, json_object_new_int( 19200 ) );
    json_object_array_add( selectArray, json_object_new_int( 38400 ) );
    json_object_array_add( selectArray, json_object_new_int( 57600 ) );
    json_object_array_add( selectArray, json_object_new_int( 115200 ) );
    err = config_server_create_number_cell( app_menu, "Baurdrate", appConfig->USART_BaudRate, "RW", selectArray );
    require_noerr( err, exit );

    exit:
    return;
}

/* Config server callback: New Device configuration received from config client */
USED void config_server_delegate_recv( const char *key, json_object *value, bool *need_reboot,
                                       mico_Context_t *in_context )
{
    application_config_t *appConfig = mico_system_context_get_user_data( in_context );

    if ( !strcmp( key, "Connect SPP Server" ) )
    {
        appConfig->remoteServerEnable = json_object_get_boolean( value );
        *need_reboot = true;
    } else if ( !strcmp( key, "SPP Server" ) )
    {
        strncpy( appConfig->remoteServerDomain, json_object_get_string( value ), 64 );
        *need_reboot = true;
    } else if ( !strcmp( key, "SPP Server Port" ) )
    {
        appConfig->remoteServerPort = json_object_get_int( value );
        *need_reboot = true;
    } else if ( !strcmp( key, "Baurdrate" ) )
    {
        appConfig->USART_BaudRate = json_object_get_int( value );
        *need_reboot = true;
    }
}

int application_start( void )
{
    app_log_trace();
    OSStatus err = kNoErr;
    mico_uart_config_t uart_config;
    app_context_t* app_context;
    mico_Context_t* mico_context;

    /* Create application context */
    app_context = (app_context_t *) calloc( 1, sizeof(app_context_t) );
    require_action( app_context, exit, err = kNoMemoryErr );

    /* Create mico system context and read application's config data from flash */
    mico_context = mico_system_context_init( sizeof(application_config_t) );
    app_context->appConfig = mico_system_context_get_user_data( mico_context );

    /* mico system initialize */
    err = mico_system_init( mico_context );
    require_noerr( err, exit );

    /* Initialize service discovery */
    err = MICOStartBonjourService( Station, app_context );
    require_noerr( err, exit );

    /* Protocol initialize */
    sppProtocolInit( app_context );

    /*UART receive thread*/
    uart_config.baud_rate = app_context->appConfig->USART_BaudRate;
    uart_config.data_width = DATA_WIDTH_8BIT;
    uart_config.parity = NO_PARITY;
    uart_config.stop_bits = STOP_BITS_1;
    uart_config.flow_control = FLOW_CONTROL_DISABLED;
    if ( mico_context->micoSystemConfig.mcuPowerSaveEnable == true )
        uart_config.flags = UART_WAKEUP_ENABLE;
    else
        uart_config.flags = UART_WAKEUP_DISABLE;

    ring_buffer_init( (ring_buffer_t *) &rx_buffer, (uint8_t *) rx_data, UART_BUFFER_LENGTH );
    MicoUartInitialize( UART_FOR_APP, &uart_config, (ring_buffer_t *) &rx_buffer );
    err = mico_rtos_create_thread( NULL, MICO_APPLICATION_PRIORITY, "UART Recv", uartRecv_thread,
                                   STACK_SIZE_UART_RECV_THREAD, (mico_thread_arg_t)app_context );
    require_noerr_action( err, exit, app_log("ERROR: Unable to start the uart recv thread.") );

    /* Local TCP server thread */
    if ( app_context->appConfig->localServerEnable == true )
    {
        err = mico_rtos_create_thread( NULL, MICO_APPLICATION_PRIORITY, "Local Server", localTcpServer_thread,
                                       STACK_SIZE_LOCAL_TCP_SERVER_THREAD, (mico_thread_arg_t)app_context );
        require_noerr_action( err, exit, app_log("ERROR: Unable to start the local server thread.") );
    }

    /* Remote TCP client thread */
    if ( app_context->appConfig->remoteServerEnable == true )
    {
        err = mico_rtos_create_thread( NULL, MICO_APPLICATION_PRIORITY, "Remote Client", remoteTcpClient_thread,
                                       STACK_SIZE_REMOTE_TCP_CLIENT_THREAD, (mico_thread_arg_t)app_context );
        require_noerr_action( err, exit, app_log("ERROR: Unable to start the remote client thread.") );
    }

exit:
    mico_rtos_delete_thread( NULL );
    return err;
}
