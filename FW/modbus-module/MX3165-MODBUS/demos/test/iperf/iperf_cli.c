/**
 ******************************************************************************
 * @file    iperf_cli.c
 * @author  Libo
 * @version V1.0.0
 * @date    5-Jan-2018
 * @brief   This file provide the iperf command line functions.
 ******************************************************************************
 *
 *  UNPUBLISHED PROPRIETARY SOURCE CODE
 *  Copyright (c) 2016 MXCHIP Inc.
 *
 *  The contents of this file may not be disclosed to third parties, copied or
 *  duplicated in any form, in whole or in part, without the prior written
 *  permission of MXCHIP Corporation.
 ******************************************************************************
 */

#include "mico.h"

#include "iperf_debug.h"
#include "iperf_task.h"

/******************************************************
 *                      Macros
 ******************************************************/

/******************************************************
 *                    Constants
 ******************************************************/


/******************************************************
 *                   Enumerations
 ******************************************************/

/******************************************************
 *                 Type Definitions
 ******************************************************/

/******************************************************
 *                    Structures
 ******************************************************/
void iperf_Command( char *pcWriteBuffer, int xWriteBufferLen, int argc, char **argv );
static void ap_command(char *pcWriteBuffer, int xWriteBufferLen,int argc, char **argv);
static void conn_command(char *pcWriteBuffer, int xWriteBufferLen,int argc, char **argv);

struct cli_command iperf_test_message_cmd[] = {
    {"ap", "<SSID> [<key>] start soft-AP mode", ap_command},
    {"conn", "<SSID> [<key>] connect to an AP", conn_command},
    { "iperf", "iperf test", iperf_Command },
};

/******************************************************
 *               Function Declarations
 ******************************************************/
static void iperf_udp_run_server_thread( mico_thread_arg_t arg );
static void iperf_tcp_run_server_thread( mico_thread_arg_t arg );
static void iperf_udp_run_client_thread( mico_thread_arg_t arg );
static void iperf_tcp_run_client_thread( mico_thread_arg_t arg );

static void _cli_iperf_server_Command( int argc, char **argv );
static void _cli_iperf_client_Command( int argc, char **argv );
static void _cli_iperf_help_Command( int argc, char **argv );

/******************************************************
 *               Variables Definitions
 ******************************************************/
extern uint8_t uap_up;
/******************************************************
 *               Function Definitions
 ******************************************************/

static void iperf_udp_run_server_thread( mico_thread_arg_t arg )
{
    iperf_udp_run_server( (char **) arg );
}

static void iperf_tcp_run_server_thread( mico_thread_arg_t arg )
{
    iperf_tcp_run_server( (char **) arg );
}

static void iperf_udp_run_client_thread( mico_thread_arg_t arg )
{
    iperf_udp_run_client( (char **) arg );
}

static void iperf_tcp_run_client_thread( mico_thread_arg_t arg )
{
    iperf_tcp_run_client( (char **) arg );
}

static void _cli_iperf_server_Command( int argc, char **argv )
{
    int i;
    char **g_iperf_param = NULL;
    int is_create_task = 0;
    int offset = IPERF_COMMAND_BUFFER_SIZE / sizeof(char *);
    g_iperf_param = malloc( IPERF_COMMAND_BUFFER_NUM * IPERF_COMMAND_BUFFER_SIZE );
    if ( g_iperf_param == NULL )
    {
        printf( "Warning: No enough memory to running iperf.\r\n" );
    }
    memset( g_iperf_param, 0, IPERF_COMMAND_BUFFER_NUM * IPERF_COMMAND_BUFFER_SIZE );

    for ( i = 0; i < argc; i++ )
    {
        strcpy( (char *) &g_iperf_param[i * offset], argv[i] );
#if defined(IPERF_DEBUG_INTERNAL)
        printf("_cli_iperf_client, g_iperf_param[%d] is \"%s\"\r\n", i, (char *)&g_iperf_param[i * offset]);
#endif
    }

    for ( i = 0; i < argc; i++ )
    {
        if ( strcmp( argv[i], "-u" ) == 0 )
        {
            printf( "Iperf UDP Server: Start!\r\n" );
            printf( "Iperf UDP Server Receive Timeout = 20 (secs)\r\n" );
            mico_rtos_create_thread( NULL, IPERF_PRIO, IPERF_NAME, iperf_udp_run_server_thread, IPERF_STACKSIZE,
                                     (mico_thread_arg_t) g_iperf_param );
            is_create_task = 1;
            break;
        }
    }
    if ( strcmp( argv[i], "-u" ) != 0 )
    {
        printf( "Iperf TCP Server: Start!\r\n" );
        printf( "Iperf TCP Server Receive Timeout = 20 (secs)\r\n" );
        mico_rtos_create_thread( NULL, IPERF_PRIO, IPERF_NAME, iperf_tcp_run_server_thread, IPERF_STACKSIZE,
                                 (mico_thread_arg_t) g_iperf_param );
        is_create_task = 1;
    }

    if ( is_create_task == 0 )
    {
        free( g_iperf_param );
    }
}

static void _cli_iperf_client_Command( int argc, char **argv )
{
    int i;
    char **g_iperf_param = NULL;
    int is_create_task = 0;
    int offset = IPERF_COMMAND_BUFFER_SIZE / sizeof(char *);

    g_iperf_param = malloc( IPERF_COMMAND_BUFFER_NUM * IPERF_COMMAND_BUFFER_SIZE );
    if ( g_iperf_param == NULL )
    {
        printf( "Warning: No enough memory to running iperf.\r\n" );
    }
    memset( g_iperf_param, 0, IPERF_COMMAND_BUFFER_NUM * IPERF_COMMAND_BUFFER_SIZE );
    for ( i = 0; i < argc; i++ )
    {
        strcpy( (char *) &g_iperf_param[i * offset], argv[i] );
#if defined(IPERF_DEBUG_INTERNAL)
        printf("_cli_iperf_client, g_iperf_param[%d] is \"%s\"\r\n", i, (char *)&g_iperf_param[i * offset]);
#endif
    }

    for ( i = 0; i < argc; i++ )
    {
        if ( strcmp( argv[i], "-u" ) == 0 )
        {
            printf( "Iperf UDP Client: Start!\r\n" );
            mico_rtos_create_thread( NULL, IPERF_PRIO, IPERF_NAME, iperf_udp_run_client_thread, IPERF_STACKSIZE,
                                     (mico_thread_arg_t) g_iperf_param );
            is_create_task = 1;
            break;
        }
    }

    if ( strcmp( argv[i], "-u" ) != 0 )
    {
        printf( "Iperf TCP Client: Start!\r\n" );
        mico_rtos_create_thread( NULL, IPERF_PRIO, IPERF_NAME, iperf_tcp_run_client_thread, IPERF_STACKSIZE,
                                 (mico_thread_arg_t) g_iperf_param );
        is_create_task = 1;
    }

    if ( is_create_task == 0 )
    {
        free( g_iperf_param );
    }
}

static void _cli_iperf_help_Command( int argc, char **argv )
{
    printf( "Usage: iperf [-s|-c] [options]\r\n" );
    printf( "       iperf [-h]\r\n\n" );
    printf( "Client/Server:\r\n" );
    printf( "  -u,        use UDP rather than TCP\r\n" );
    printf( "  -p,        #server port to listen on/connect to (default 5001)\r\n" );
    printf( "  -n,        #[kmKM]    number of bytes to transmit \r\n" );
    printf( "  -b,        #[kmKM]    for UDP, bandwidth to send at in bits/sec\r\n" );
    printf( "  -i,        10 seconds between periodic bandwidth reports \r\n\n" );
    printf( "Server specific:\r\n" );
    printf( "  -s,        run in server mode\r\n" );
    printf( "  -B,        <ip>    bind to <ip>, and join to a multicast group (only Support UDP)\r\n" );
    printf( "  -r,        for UDP, run iperf in tradeoff testing mode, connecting back to client\r\n\n" );
    printf( "Client specific:\r\n" );
    printf( "  -c,        <ip>run in client mode, connecting to <ip>\r\n" );
    printf( "  -w,        #[kmKM]    TCP window size\r\n" );
    printf( "  -l,        #[kmKM]    UDP datagram size\r\n" );
    printf( "  -t,        #time in seconds to transmit for (default 10 secs)\r\n" );
    printf( "  -S,        #the type-of-service of outgoing packets\r\n\n" );
    printf( "Miscellaneous:\r\n" );
    printf( "  -h,        print this message and quit\r\n\n" );
    printf( "[kmKM] Indicates options that support a k/K or m/M suffix for kilo- or mega-\r\n\n" );
    printf( "TOS options for -S parameter:\r\n" );
    printf( "BE: -S 0\r\n" );
    printf( "BK: -S 32\r\n" );
    printf( "VI: -S 160\r\n" );
    printf( "VO: -S 224\r\n\n" );
    printf( "Tradeoff Testing Mode:\r\n" );
    printf( "Command: iperf -s -u -n <bits/bytes> -r \r\n\n" );
    printf( "Example:\r\n" );
    printf( "Iperf TCP Server: iperf -s\r\n" );
    printf( "Iperf UDP Server: iperf -s -u\r\n" );
    printf( "Iperf TCP Client: iperf -c <ip> -w <window size> -t <duration> -p <port> \r\n" );
    printf( "Iperf UDP Client: iperf -c <ip> -u -l <datagram size> -t <duration> -p <port>\r\n" );
}

#if defined(MICO_IPERF_DEBUG_ENABLE)
static uint8_t _cli_iperf_debug(int argc, char **argv)
{
    int debug;
    debug = atoi(argv[0]);
    printf("Set iperf debug to %d(0x%x)\r\n", debug, debug);
    iperf_set_debug_mode(debug);
    return 0;
}
#endif

void iperf_Command( char *pcWriteBuffer, int xWriteBufferLen, int argc, char **argv )
{
    if ( argc < 2 )
    {
        printf( "Invalid command\r\n" );
    }
    if ( strcmp( argv[1], "-s" ) == 0 )
    {
        _cli_iperf_server_Command( argc - 2, &argv[2] );
    }
    else
    if ( strcmp( argv[1], "-c" ) == 0 )
    {
        _cli_iperf_client_Command( argc - 2, &argv[2] );
    }
    else
    if ( strcmp( argv[1], "-h" ) == 0 )
    {
        _cli_iperf_help_Command( argc - 2, &argv[2] );
    }
#if defined(MICO_IPERF_DEBUG_ENABLE)
    else
    if ( strcmp( argv[1], "-d" ) == 0 )
    {
        _cli_iperf_debug( argc - 2, &argv[2] );
    }
#endif
}


OSStatus iperf_cli_register( void )
{
    if( 0 == cli_register_commands( iperf_test_message_cmd, sizeof(iperf_test_message_cmd)/sizeof(struct cli_command) ))
        return kNoErr;
    else
        return kGeneralErr;
}

/*++++++++++++++++ ADD BY SWYANG@MICO@MXCHIP ++++++++++++++++*/
/*
Add CLI commands to connect an AP or start soft-AP
*/

static void connect_ap(char *ssid, char *key)
{
    network_InitTypeDef_adv_st  wNetConfigAdv={0};
    /* Initialize wlan parameters */
    strcpy((char*)wNetConfigAdv.ap_info.ssid, ssid);   /* wlan ssid string */
    if (key) {
        strcpy((char*)wNetConfigAdv.key, key);                /* wlan key string or hex data in WEP mode */
        wNetConfigAdv.key_len = strlen(key);                  /* wlan key length */
    } else {
        wNetConfigAdv.key_len = 0;
    }
    wNetConfigAdv.ap_info.security = SECURITY_TYPE_AUTO;          /* wlan security mode */
    wNetConfigAdv.ap_info.channel = 0;                            /* Select channel automatically */
    wNetConfigAdv.dhcpMode = DHCP_Client;                         /* Fetch Ip address from DHCP server */
    wNetConfigAdv.wifi_retry_interval = 100;                      /* Retry interval after a failure connection */

    /* Connect Now! */
    printf ("connecting to %s...\r\n", wNetConfigAdv.ap_info.ssid);
    micoWlanStartAdv(&wNetConfigAdv);
}

static void ap_start(char *ssid, char *key)
{
    network_InitTypeDef_st wNetConfig;

    memset(&wNetConfig, 0x0, sizeof(network_InitTypeDef_st));

    strcpy((char*)wNetConfig.wifi_ssid, ssid);
    if (key)
        strcpy((char*)wNetConfig.wifi_key, key);

    wNetConfig.wifi_mode = Soft_AP;
    wNetConfig.dhcpMode = DHCP_Server;
    wNetConfig.wifi_retry_interval = 100;
    strcpy((char*)wNetConfig.local_ip_addr, "192.168.0.1");
    strcpy((char*)wNetConfig.net_mask, "255.255.255.0");
    strcpy((char*)wNetConfig.dnsServer_ip_addr, "192.168.0.1");

    printf("ssid:%s  key:%s\r\n", wNetConfig.wifi_ssid, wNetConfig.wifi_key);
    micoWlanStart(&wNetConfig);
}

static void ap_command(char *pcWriteBuffer, int xWriteBufferLen,int argc, char **argv)
{
    if (uap_up == 1)
        return;
    
    if (argc == 2) {
        cmd_printf("start AP ssid=%s\r\n", argv[1]);
        ap_start(argv[1], NULL);
    } else if (argc == 3) {
        cmd_printf("start AP ssid=%s, key=%s\r\n", argv[1], argv[2]);
        ap_start(argv[1], argv[2]);
    } else {
        cmd_printf("Usage: ap <ssid> [<key>]");
    }
}

static void conn_command(char *pcWriteBuffer, int xWriteBufferLen,int argc, char **argv)
{
    if (argc == 2) {
        cmd_printf("Connect to AP ssid=%s\r\n", argv[1]);
        connect_ap(argv[1], NULL);
    } else if (argc == 3) {
        cmd_printf("Connect to AP ssid=%s, key=%s\r\n", argv[1], argv[2]);
        
        connect_ap(argv[1], argv[2]);
    } else {
        cmd_printf("Usage: connect <ssid> [<key>]");
    }
}