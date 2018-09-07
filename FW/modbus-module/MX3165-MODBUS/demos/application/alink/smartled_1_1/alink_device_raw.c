#include "mico.h"
#include "alink_device.h"
#include "alink_export_rawdata.h"

#define raw_log(M, ...) custom_log("", M, ##__VA_ARGS__)

#ifdef PASS_THROUGH
/*do your job here*/
static struct virtual_dev
{
    char power;
    char temp_value;
    char light_value;
    char time_delay;
    char work_mode;
} virtual_device = {
    0x01, 0x30, 0x50, 0, 0x01 };

static int get_device_status( char *rawdata, int len )
{
    /* do your job here */
    int ret = 0;
    if ( len > 7 )
    {
        rawdata[0] = 0xaa;
        rawdata[1] = 0x07;
        rawdata[2] = virtual_device.power;
        rawdata[3] = virtual_device.work_mode;
        rawdata[4] = virtual_device.temp_value;
        rawdata[5] = virtual_device.light_value;
        rawdata[6] = virtual_device.time_delay;
        rawdata[7] = 0x55;
    } else
    {
        ret = -1;
    }
    /* do your job end */
    return ret;
}

/* this sample save cmd value to virtual_device*/
static int execute_cmd( const char *rawdata, int len )
{
    char rawdata_dump[24];
    int ret = 0, i = 0;
    if ( len < 1 )
        ret = -1;
    sprintf( rawdata_dump, "%02x %02x %02x %02x %02x %02x",
             (unsigned char) rawdata[0],
             (unsigned char) rawdata[1], (unsigned char) rawdata[2],
             (unsigned char) rawdata[3],
             (unsigned char) rawdata[4], (unsigned char) rawdata[5] );
    raw_log("%s", rawdata_dump);
    for ( i = 0; i < len; i++ )
    {
        switch ( i )
        {
            case 2:
                if ( virtual_device.power != rawdata[i] )
                {
                    virtual_device.power = rawdata[i];
                }
                break;
            case 3:
                if ( virtual_device.work_mode != rawdata[i] )
                {
                    virtual_device.work_mode = rawdata[i];
                }
                break;
            case 4:
                if ( virtual_device.temp_value != rawdata[i] )
                {
                    virtual_device.temp_value = rawdata[i];
                }
                break;
            case 5:
                if ( virtual_device.light_value != rawdata[i] )
                {
                    virtual_device.light_value = rawdata[i];
                }
                break;
            case 6:
                if ( virtual_device.time_delay != rawdata[i] )
                {
                    virtual_device.time_delay = rawdata[i];
                }
                break;
            default:
                break;
        }
    }
    return ret;
}

int cloud_get_device_raw_data( const char *in_rawdata, int in_len, char *out_rawdata, int *out_len )
{
    int ret = 0;
    raw_log("function %s, memory %d \n", __FUNCTION__, MicoGetMemoryInfo()->free_memory);
    set_device_state( 1 );
    /*do your job end! */
    return ret;
}

int cloud_set_device_raw_data( char *rawdata, int len )
{
    /* TODO: */
    /*get cmd from server, do your job here! */
    int ret = 0;
    raw_log("function %s, memory %d \n", __FUNCTION__, MicoGetMemoryInfo()->free_memory);
    ret = execute_cmd( rawdata, len );
    /* do your job end! */
    set_device_state( 1 );
    return ret;
}

int alink_device_post_raw_data( void )
{
    /* do your job here */
    int len = 8, ret = 0;
    char rawdata[8] = { 0 };

    raw_log("function %s, memory %d \n", __FUNCTION__, MicoGetMemoryInfo()->free_memory);
    get_device_status( rawdata, len );
    ret = alink_post_device_rawdata( rawdata, len );
    if ( ret )
    {
        raw_log("post failed!\n");
    } else
    {
        raw_log("dev post raw data success!\n");
    }

    /* do your job end */
    return ret;
}
#endif
