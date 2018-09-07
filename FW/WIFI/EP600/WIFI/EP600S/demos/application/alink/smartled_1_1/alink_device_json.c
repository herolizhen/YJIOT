#include "mico.h"
#include "alink_device.h"

#define json_log(M, ...) custom_log("", M, ##__VA_ARGS__)

#ifndef PASS_THROUGH
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

const char *main_dev_params =
"{\"OnOff_Power\": { \"value\": \"%d\" }, \"Color_Temperature\": { \"value\": \"%d\" }, \"Light_Brightness\": { \"value\": \"%d\" }, \"TimeDelay_PowerOff\": { \"value\": \"%d\"}, \"WorkMode_MasterLight\": { \"value\": \"%d\"}}";

static void get_device_status( alink_up_cmd_ptr up_cmd )
{
    sprintf( (char *) post_data_buffer, main_dev_params, virtual_device.power,
        virtual_device.temp_value,
        virtual_device.light_value,
        virtual_device.time_delay,
        virtual_device.work_mode );
    up_cmd->param = (const char *) post_data_buffer;
}

static int execute_cmd( alink_down_cmd_ptr down_cmd )
{
    int attrLen = 0, valueLen = 0, value = 0, i = 0;
    char *valueStr = NULL, *attrStr = NULL;

    json_log("set json: %s", down_cmd->param);

    for ( i = 0; i < 5; i++ )
    {
        attrStr = alink_JsonGetValueByName( down_cmd->param, strlen( down_cmd->param ),
            device_attr[i], &attrLen, 0 );
        valueStr = alink_JsonGetValueByName( attrStr, attrLen, "value", &valueLen, 0 );

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

int cloud_get_device_json_data( alink_down_cmd_ptr down_cmd )
{
    int ret = 0;
    json_log("function %s, memory %d \n", __FUNCTION__, MicoGetMemoryInfo()->free_memory);
    set_device_state( 1 );
    /*do your job end! */
    return ret;
}

int cloud_set_device_json_data( alink_down_cmd_ptr down_cmd )
{
    /* TODO: */
    /*get cmd from server, do your job here! */
    int ret = 0;
    json_log("function %s, memory %d \n", __FUNCTION__, MicoGetMemoryInfo()->free_memory);
    ret = execute_cmd( down_cmd );
    /* do your job end! */
    set_device_state( 1 );
    return ret;
}

int alink_device_post_json_data( void )
{
    /* do your job here */
    int ret = 0;
    alink_up_cmd up_cmd;

    json_log("function %s, memory %d \n", __FUNCTION__, MicoGetMemoryInfo()->free_memory);
    get_device_status( &up_cmd );
    up_cmd.target = NULL;
    up_cmd.resp_id = -1;
    ret = alink_post_device_data( &up_cmd );
    if ( ret )
    {
        json_log("post failed!\n");
    } else
    {
        json_log("dev post json data success!\n");
    }

    /* do your job end */
    return ret;
}
#endif
