#ifndef __ALINK_DEVICE_H
#define __ALINK_DEVICE_H

#include "alink_config.h"
#include "common.h"
#include "alink_export.h"
#include "alink_platform.h"
#include "alink_json.h"
#include "product.h"

OSStatus start_alink_emb( void );

void alink_device_reset( void );

int get_device_state( void );

int set_device_state( int state );

#ifdef PASS_THROUGH
int cloud_get_device_raw_data( char *json_buffer );

int cloud_set_device_raw_data( char *json_buffer );

int alink_device_post_raw_data( void );
#endif
int cloud_get_device_json_data( char *json_buffer );

int cloud_set_device_json_data( char *json_buffer );

void alink_device_post_json_data( void );
#endif
