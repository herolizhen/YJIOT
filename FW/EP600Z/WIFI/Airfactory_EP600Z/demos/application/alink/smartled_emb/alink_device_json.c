#include "mico.h"
#include "alink_device.h"

#define json_log(M, ...) custom_log("", M, ##__VA_ARGS__)

#ifndef PASS_THROUGH

#define PostDataFormat      "{\"OnOff_Power\":{\"value\":\"%d\"},\"Color_Temperature\":{\"value\":\"%d\"},\"Light_Brightness\":{\"value\":\"%d\"},\"TimeDelay_PowerOff\":{\"value\":\"%d\"},\"WorkMode_MasterLight\":{\"value\":\"%d\"}}"

#define post_data_buffer_size    (512)
static uint8_t post_data_buffer[post_data_buffer_size];

/*do your job here*/
static struct virtual_dev
{
    char power;
    char temp_value;
    char light_value;
    char time_delay;
    char work_mode;
}virtual_device =
{
    0x01, 0x30, 0x50, 0, 0x01};

char *device_attr[5] =
{   "OnOff_Power", "Color_Temperature", "Light_Brightness",
    "TimeDelay_PowerOff", "WorkMode_MasterLight"
};

static int execute_cmd( char *json_buffer )
{
    int attrLen = 0, valueLen = 0, value = 0, i = 0;
    char *valueStr = NULL, *attrStr = NULL;

    json_log("set data: %s", json_buffer);

    for ( i = 0; i < 5; i++ )
    {
        attrStr = json_get_value_by_name( json_buffer, strlen( json_buffer ),
            device_attr[i], &attrLen, 0 );
        valueStr = json_get_value_by_name( attrStr, attrLen, "value", &valueLen, 0 );

        if ( valueStr && valueLen > 0 )
        {
            char lastChar = *(valueStr + valueLen);
            *(valueStr + valueLen) = 0;
            value = atoi( valueStr );
            *(valueStr + valueLen) = lastChar;
            switch ( i )
            {
                case 0:
                virtual_device.power = value;
                break;
                case 1:
                virtual_device.temp_value = value;
                break;
                case 2:
                virtual_device.light_value = value;
                break;
                case 3:
                virtual_device.time_delay = value;
                break;
                case 4:
                virtual_device.work_mode = value;
                break;
                default:
                break;
            }
        }
    }
    return 0;
}

int cloud_get_device_json_data( char *json_buffer )
{
    json_log( "function %s, memory %d \n", __FUNCTION__, MicoGetMemoryInfo( )->free_memory );

    set_device_state( 1 );
    return 0;
}

int cloud_set_device_json_data( char *json_buffer )
{
    int ret = 0;

    json_log( "function %s, memory %d \n", __FUNCTION__, MicoGetMemoryInfo( )->free_memory );
    ret = execute_cmd( json_buffer );
    set_device_state( 1 );
    return ret;
}

void alink_device_post_json_data( void )
{
    /* sample for json data device */
    snprintf( (char *) post_data_buffer, post_data_buffer_size, PostDataFormat,
        virtual_device.power,
        virtual_device.temp_value,
        virtual_device.light_value,
        virtual_device.time_delay,
        virtual_device.work_mode );

    alink_report( Method_PostData, (const char *) post_data_buffer );
}
#endif
