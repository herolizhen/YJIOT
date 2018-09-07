/**
 ******************************************************************************
 * @file    tls_server.c
 * @author  William Xu
 * @version V1.0.0
 * @date    21-May-2015
 * @brief   MiCO tcp server Demo
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
#include "SocketUtils.h"

#define tls_server_log(M, ...) custom_log("TLS", M, ##__VA_ARGS__)

#define SERVER_PORT 443 /*set up a tls server,port at 443*/

#define cert_pem "-----BEGIN CERTIFICATE-----\r\n\
MIIC3DCCAkWgAwIBAgIJAI+KgJoqr9gmMA0GCSqGSIb3DQEBCwUAMIGGMQswCQYD\r\n\
VQQGEwJHQjEQMA4GA1UECAwHRXJld2hvbjETMBEGA1UEBwwKQWxsIGFyb3VuZDEb\r\n\
MBkGA1UECgwSbGlid2Vic29ja2V0cy10ZXN0MRIwEAYDVQQDDAlsb2NhbGhvc3Qx\r\n\
HzAdBgkqhkiG9w0BCQEWEG5vbmVAaW52YWxpZC5vcmcwHhcNMTYxMTE4MDcwODU5\r\n\
WhcNNDQwNDA1MDcwODU5WjCBhjELMAkGA1UEBhMCR0IxEDAOBgNVBAgMB0VyZXdo\r\n\
b24xEzARBgNVBAcMCkFsbCBhcm91bmQxGzAZBgNVBAoMEmxpYndlYnNvY2tldHMt\r\n\
dGVzdDESMBAGA1UEAwwJbG9jYWxob3N0MR8wHQYJKoZIhvcNAQkBFhBub25lQGlu\r\n\
dmFsaWQub3JnMIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQCz2pzZPJsslfjE\r\n\
Z/8VWEKIOwnKYMxmqyo4IuABxOjdHwYPnBtme9TLcg2dXFQzq109dV187qd9hP83\r\n\
WIecoG0k/kG1s1pEkRN/AvsBdu4EUknYKc0rHBaHUWl2kjVYqzwubjP1IM7TkPOW\r\n\
0e5T3pwVqmhUWt9+p09ADzocoBtbMwIDAQABo1AwTjAdBgNVHQ4EFgQU0sutlHNN\r\n\
ov4rfUaUBnvaCYSwSxowHwYDVR0jBBgwFoAU0sutlHNNov4rfUaUBnvaCYSwSxow\r\n\
DAYDVR0TBAUwAwEB/zANBgkqhkiG9w0BAQsFAAOBgQA9Rd/7Kud97HPSpU9NHO3k\r\n\
Zxaimmg4nncRA63cZWH2KpWSuirAhJT0iSNCnSW6BYNOeD/lZd0mg8Zn1b269tQ7\r\n\
RgyGEuB0ySOYUSkCOuzNvPAl4Yd6tYcG1j3St30pTf7Uwp/O8LTno+gH0f0aOdV9\r\n\
M/p2+n43tReJYl4D0o2T7A==\r\n\
-----END CERTIFICATE-----\r\n"

#define key_pem "-----BEGIN PRIVATE KEY-----\r\n\
MIICdwIBADANBgkqhkiG9w0BAQEFAASCAmEwggJdAgEAAoGBALPanNk8myyV+MRn\r\n\
/xVYQog7CcpgzGarKjgi4AHE6N0fBg+cG2Z71MtyDZ1cVDOrXT11XXzup32E/zdY\r\n\
h5ygbST+QbWzWkSRE38C+wF27gRSSdgpzSscFodRaXaSNVirPC5uM/UgztOQ85bR\r\n\
7lPenBWqaFRa336nT0APOhygG1szAgMBAAECgYAwH87YUd8zju2BoFIg4/zpduKn\r\n\
xD7tOd+SJcLKtmWYxTRZ+OtcAMZvqZT7BjmBmdjZGQ5q33DxpSSlKose3c5WJCkn\r\n\
+eYItG6wLowQXNy00f4NM4OQajqfawLeCaC/7ghlQZi53WXAh/OnOXrLaXC2zsp0\r\n\
tZvyRwinHEj7R5VoAQJBAO+0ToHr4MCV9m45mRVMGEO4q902++aIThWKIFIJRrzA\r\n\
FhqpCLqccE5mQ7rzgkNfSPbaldoGw0NcoolX3ztA8RsCQQDAFLNLYyPlK7bentq0\r\n\
ILrKjeosk1L6iHoV/+fR8RG3PTcDOMVNcXvRrGb8UpJ6l+QQ90UK4X4mW4SxGBXp\r\n\
R/fJAkEApxSGGHdC7NpasBADzV2CGEozuXkm8lSWINtrleMTZGN7xM+H3xNGEM+l\r\n\
bD1p0e4r3K0WAKfwGRcL0DHoztOAewJBAILyGcD9F012XbaqySIfZfgMg2ZcESem\r\n\
vsQcr2daVt96pfRWUXuYL/ci9xpxGFbnEZ3XVIQ0cZGotm8comNkorECQAlbYKXX\r\n\
2XWwDQMjqIR+jz2jsQSGxLTcI4xkFlRhCV784fJ9/DYj8EW8T8fCKin7M6NuEZHQ\r\n\
DaxVdjwndTrK4UU=\r\n\
-----END PRIVATE KEY-----\r\n"

void micoNotify_WifiStatusHandler( WiFiEvent event, void* const inContext )
{
    IPStatusTypedef para;
    switch ( event )
    {
        case NOTIFY_STATION_UP:
            micoWlanGetIPStatus( &para, Station );
            tls_server_log("Server established at ip: %s port: %d",para.ip, SERVER_PORT);
            break;
        case NOTIFY_STATION_DOWN:
            case NOTIFY_AP_UP:
            case NOTIFY_AP_DOWN:
            break;
    }
}

void tls_client_thread( mico_thread_arg_t arg )
{
    OSStatus err = kNoErr;
    mico_ssl_t ssl = (mico_ssl_t) arg;
    int inSock = ssl_socket( ssl );
    int len = 0;
    fd_set readfds;
    char *buf = NULL;
    struct timeval t;

    buf = (char*) malloc( 1024 );
    require_action( buf, exit, err = kNoMemoryErr );
    
    t.tv_sec = 5;
    t.tv_usec = 0;
    
    while ( 1 )
    {
        FD_ZERO( &readfds );
        FD_SET( inSock, &readfds );

        require_action( select( inSock+1, &readfds, NULL, NULL, &t) >= 0, exit, err = kConnectionErr );

        if ( FD_ISSET( inSock, &readfds ) ) /*one client has data*/
        {
            len = ssl_recv( ssl, buf, 1024 );
            require_action( len >= 0, exit, err = kConnectionErr );

            if ( len == 0 )
            {
                tls_server_log( "TLS Client is disconnected, fd: %d", inSock );
                goto exit;
            }

            tls_server_log("fd: %d, recv data %d from client", inSock, len);
            len = ssl_send( ssl, buf, len);
            tls_server_log("fd: %d, send data %d to client", inSock, len);
        }
    }
    exit:
    if ( err != kNoErr ) tls_server_log( "TLS client thread exit with err: %d", err );
    if ( buf != NULL ) free( buf );
    SocketClose( &inSock );
    ssl_close( ssl );
    mico_rtos_delete_thread( NULL );
}

/* TLS server listener thread */
void tls_server_thread( mico_thread_arg_t arg )
{
    UNUSED_PARAMETER( arg );
    OSStatus err = kNoErr;
    struct sockaddr_in server_addr, client_addr;
    socklen_t sockaddr_t_size = sizeof(client_addr);
    char client_ip_str[16];
    int tls_listen_fd = -1, client_fd = -1;
    fd_set readfds;
    mico_ssl_t client_ssl = NULL;

    ssl_set_cert( cert_pem, key_pem );

    tls_listen_fd = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
    require_action( IsValidSocket( tls_listen_fd ), exit, err = kNoResourcesErr );

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;/* Accept conenction request on all network interface */
    server_addr.sin_port = htons( SERVER_PORT );/* Server listen on port: 443 */

    err = bind( tls_listen_fd, (struct sockaddr *) &server_addr, sizeof(server_addr) );
    require_noerr( err, exit );
    
    err = listen( tls_listen_fd, 0 );
    require_noerr( err, exit );
    
    while ( 1 )
    {
        FD_ZERO( &readfds );
        FD_SET( tls_listen_fd, &readfds );

        require( select( tls_listen_fd + 1, &readfds, NULL, NULL, NULL) >= 0, exit );

        if ( FD_ISSET( tls_listen_fd, &readfds ) )
        {
            client_fd = accept( tls_listen_fd, (struct sockaddr *) &client_addr, &sockaddr_t_size );
            client_ssl = ssl_accept( client_fd );
            if ( IsValidSocket( client_fd ) && (client_ssl != NULL) )
            {
                strcpy( client_ip_str, inet_ntoa( client_addr.sin_addr ) );
                tls_server_log( "TLS Client %s:%d connected, fd: %d",
                                client_ip_str, client_addr.sin_port, client_fd );
                if ( kNoErr != mico_rtos_create_thread( NULL, MICO_APPLICATION_PRIORITY,
                                                        "TLS Clients",
                                                        tls_client_thread,
                                                        0x2000,
                                                        (uint32_t)client_ssl ) )
                {
                    SocketClose( &client_fd );
                    ssl_close( client_ssl );
                }

            }else{
                SocketClose( &client_fd );
                if( client_ssl != NULL )
                {
                    ssl_close( client_ssl );
                    client_ssl = NULL;
                }
            }
        }
    }
    exit:
    if ( err != kNoErr ) tls_server_log( "Server listerner thread exit with err: %d", err );
    SocketClose( &tls_listen_fd );
    mico_rtos_delete_thread( NULL );
}

int application_start( void )
{
    OSStatus err = kNoErr;

    /*Register user function for MiCO nitification: WiFi status changed */
    err = mico_system_notify_register( mico_notify_WIFI_STATUS_CHANGED,
                                       (void *) micoNotify_WifiStatusHandler,
                                       NULL );
    require_noerr( err, exit );

    /* Start MiCO system functions according to mico_config.h */
    err = mico_system_init( mico_system_context_init( 0 ) );
    require_noerr( err, exit );

    /* Start TCP server listener thread*/
    err = mico_rtos_create_thread( NULL, MICO_APPLICATION_PRIORITY,
                                   "TLS_server",
                                   tls_server_thread,
                                   0x2000,
                                   0 );
    require_noerr_string( err, exit, "ERROR: Unable to start the tls server thread." );

    exit:
    mico_rtos_delete_thread( NULL );
    return err;
}

