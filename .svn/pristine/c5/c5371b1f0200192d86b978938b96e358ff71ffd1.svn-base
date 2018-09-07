#include "mico.h"
#include "alink_device.h"

#define raw_log(M, ...) custom_log("", M, ##__VA_ARGS__)

#ifdef PASS_THROUGH

#define post_data_buffer_size    (512)
static uint8_t raw_data_buffer[post_data_buffer_size];
/* rawdata byte order
 *
 * rawdata[0] = 0xaa;
 * rawdata[1] = 0x07;
 * rawdata[2] = device.power;
 * rawdata[3] = device.work_mode;
 * rawdata[4] = device.temp_value;
 * rawdata[5] = device.light_value;
 * rawdata[6] = device.time_delay;
 * rawdata[7] = 0x55;
 */
#define RAW_DATA_SIZE           (8)
uint8_t device_state_raw_data[RAW_DATA_SIZE] = {
    0xaa, 0x07, 1, 8, 10, 50, 10, 0x55
};

static char a2x( char ch )
{
    switch ( ch )
    {
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        case 'A':
            case 'a':
            return 10;
        case 'B':
            case 'b':
            return 11;
        case 'C':
            case 'c':
            return 12;
        case 'D':
            case 'd':
            return 13;
        case 'E':
            case 'e':
            return 14;
        case 'F':
            case 'f':
            return 15;
        default:
            break;
            ;
    }

    return 0;
}

int uart_send( const uint8_t *raw_data, int raw_data_len )
{
    //TODO: implement uart send here
    int i;
    for ( i = 0; i < raw_data_len; i++ )
        printf( "%02x ", raw_data[i] );

    printf( "\r\n" );
    return 0;
}

int raw_data_unserialize( char *json_buffer, uint8_t *raw_data, int *raw_data_len )
{
    int attr_len = 0, i = 0;
    char *attr_str = NULL;

    raw_log("set data: %s", json_buffer);

    attr_str = json_get_value_by_name( json_buffer, strlen( json_buffer ),
                                       "rawData",
                                       &attr_len, NULL );

    if ( !attr_str || !attr_len || attr_len > *raw_data_len * 2 )
        return -1;

    for ( i = 0; i < attr_len; i += 2 )
    {
        raw_data[i / 2] = a2x( attr_str[i] ) << 4;
        raw_data[i / 2] += a2x( attr_str[i + 1] );
    }

    raw_data[i / 2] = '\0';
    *raw_data_len = i / 2;

    return 0;
}

int cloud_get_device_raw_data( char *json_buffer )
{
    raw_log( "function %s, memory %d \n", __FUNCTION__, MicoGetMemoryInfo( )->free_memory );

    set_device_state( 1 );
    return 0;
}

int cloud_set_device_raw_data( char *json_buffer )
{
    int ret = 0, raw_data_len = RAW_DATA_SIZE;
    uint8_t raw_data[RAW_DATA_SIZE] = { 0 };

    raw_log( "function %s, memory %d \n", __FUNCTION__, MicoGetMemoryInfo( )->free_memory );

    ret = raw_data_unserialize( json_buffer, raw_data, &raw_data_len );

    /* update device state */
    memcpy( device_state_raw_data, raw_data, raw_data_len );
    uart_send( raw_data, raw_data_len );

    set_device_state( 1 );
    return ret;
}

int alink_device_post_raw_data( void )
{

    int i, size;
    int len = RAW_DATA_SIZE;
#define RawDataHeader   "{\"rawData\":\""
#define RawDataTail     "\", \"length\":\"%d\"}"

    size = strlen( RawDataHeader );
    strncpy( (char *) raw_data_buffer, RawDataHeader, post_data_buffer_size );
    for ( i = 0; i < len; i++ )
    {
        size += snprintf( (char *) raw_data_buffer + size,
        post_data_buffer_size - size,
                          "%02X", device_state_raw_data[i] );
    }

    size += snprintf( (char *) raw_data_buffer + size,
    post_data_buffer_size - size,
                      RawDataTail, len * 2 );

    return alink_report( Method_PostRawData, (char *) raw_data_buffer );
}
#endif
