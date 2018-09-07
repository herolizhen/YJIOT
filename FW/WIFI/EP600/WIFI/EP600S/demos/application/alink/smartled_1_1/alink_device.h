#ifndef __ALINK_DEVICE_H
#define __ALINK_DEVICE_H

#include "alink_config.h"
#include "common.h"
#include "alink_export.h"
#include "product.h"
#ifdef PASS_THROUGH
#include "alink_export_rawdata.h"
#endif

OSStatus start_alink( void );

void alink_device_reset( void );

int get_device_state( void );

int set_device_state( int state );

#ifdef PASS_THROUGH
int cloud_get_device_raw_data( const char *in_rawdata, int in_len, char *out_rawdata,
                               int *out_len );

int cloud_set_device_raw_data( char *rawdata, int len );

int alink_device_post_raw_data( void );
#else
int cloud_get_device_json_data( alink_down_cmd_ptr down_cmd );

int cloud_set_device_json_data( alink_down_cmd_ptr down_cmd );

int alink_device_post_json_data(void);
#endif

#endif
