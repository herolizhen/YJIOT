#include "MICO.h"
#include "alink_device.h"

#define alink_main_log(M, ...) custom_log("alink_main", M, ##__VA_ARGS__)

static void *alink_sample_mutex;
static char device_status_change = 1;
static int device_logged = 0;
static void* post_sem = NULL;

void alink_device_reset( void )
{
    if ( device_logged )
        alink_factory_reset( );
}

int get_device_state( void )
{
    int ret = 0;
    platform_mutex_lock( alink_sample_mutex );
    ret = device_status_change;
    device_status_change = 0;
    platform_mutex_unlock( alink_sample_mutex );
    return ret;
}

int set_device_state( int state )
{
    platform_mutex_lock( alink_sample_mutex );
    device_status_change = state;
    platform_mutex_unlock( alink_sample_mutex );
    if ( state == 1 )
    {
        platform_semaphore_post( post_sem );
        alink_main_log("set_device_state %d", state);
    }
    return state;
}

int alink_handler_systemstates_callback( void *dev_mac, void *sys_state )
{
    char uuid[33] = { 0 };
    char *mac = (char *) dev_mac;
    enum ALINK_STATUS *state = (enum ALINK_STATUS *) sys_state;
    device_logged = 0;
    switch ( *state )
    {
        case ALINK_STATUS_INITED:
            break;
        case ALINK_STATUS_REGISTERED:
            sprintf( uuid, "%s", alink_get_uuid( NULL ) );
            alink_main_log("ALINK_STATUS_REGISTERED, mac %s uuid %s \n", mac,
                uuid);
            break;
        case ALINK_STATUS_LOGGED:
            sprintf( uuid, "%s", alink_get_uuid( NULL ) );
            alink_main_log("ALINK_STATUS_LOGGED, mac %s uuid %s\n", mac, uuid);
            device_logged = 1;
            break;
        default:
            break;
    }
    return 0;
}

void alink_fill_deviceinfo( struct device_info *deviceinfo )
{ /*fill main device info here */
    product_get_name( deviceinfo->name );
    product_get_sn( deviceinfo->sn );
    product_get_key( deviceinfo->key );
    product_get_model( deviceinfo->model );
    product_get_secret( deviceinfo->secret );
    product_get_type( deviceinfo->type );
    product_get_version( deviceinfo->version );
    product_get_category( deviceinfo->category );
    product_get_manufacturer( deviceinfo->manufacturer );
    product_get_debug_key( deviceinfo->key_sandbox );
    product_get_debug_secret( deviceinfo->secret_sandbox );
    platform_wifi_get_mac( deviceinfo->mac );
    product_get_cid( deviceinfo->cid );
    alink_main_log("DEV_MODEL:%s", deviceinfo->model);
    alink_main_log("PRODUCT DEVICE VERSION:%s\n", product_dev_version);
}

static void alink_main( uint32_t arg )
{
    struct device_info *main_dev;
    main_dev = platform_malloc( sizeof(struct device_info) );
    alink_sample_mutex = platform_mutex_init( );
    post_sem = platform_semaphore_init( );
    memset( main_dev, 0, sizeof(struct device_info) );
    alink_fill_deviceinfo( main_dev );

    alink_set_loglevel( ALINK_LL_DEBUG | ALINK_LL_INFO | ALINK_LL_ERROR );
//    alink_set_loglevel(ALINK_LL_NONE);

    main_dev->sys_callback[ALINK_FUNC_SERVER_STATUS] = alink_handler_systemstates_callback;

#ifndef PASS_THROUGH
    main_dev->dev_callback[ACB_GET_DEVICE_STATUS] = cloud_get_device_json_data;
    main_dev->dev_callback[ACB_SET_DEVICE_STATUS] = cloud_set_device_json_data;
#endif

    /*start alink-sdk */
#ifdef PASS_THROUGH
    alink_start_rawdata( main_dev, cloud_get_device_raw_data, cloud_set_device_raw_data );
#else
    alink_start( main_dev );
#endif
    platform_free( main_dev );

    alink_main_log("wait main device login");
    /*wait main device login, -1 means wait forever */
    alink_wait_connect( NULL, ALINK_WAIT_FOREVER );

    while ( 1 )
    {
        if ( get_device_state( ) )
        {
            alink_main_log("device status changed, free memory %d", MicoGetMemoryInfo()->free_memory);
#ifdef PASS_THROUGH
            alink_device_post_raw_data( );
#else
            alink_device_post_json_data();
#endif
        }
        platform_semaphore_wait( post_sem, 500 );
    }

    alink_end( );
    platform_mutex_destroy( alink_sample_mutex );
    platform_semaphore_destroy( post_sem );
    mico_rtos_delete_thread( NULL );
}

OSStatus start_alink( void )
{
    return mico_rtos_create_thread( NULL, MICO_APPLICATION_PRIORITY, "alink main", alink_main,
                                    0x2000,
                                    0 );
}

