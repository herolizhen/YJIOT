/*************************************************
 ALINK CONFIG
 *************************************************/
#include "common.h"

#pragma once

/* raw data device means device post byte stream to cloud,
 * cloud translate byte stream to json value by lua script
 * for each product model, vendor need to sumbit a lua script
 * doing this job
 *
 * undefine RAW_DATA_DEVICE, sample will post json string to cloud
 */
#define PASS_THROUGH

#define Method_PostData    "postDeviceData"
#define Method_PostRawData "postDeviceRawData"
#define Method_GetAlinkTime "getAlinkTime"

//TODO: update these product info
#define product_dev_name        "alink_product"
#ifdef PASS_THROUGH
#define product_model         "ALINKTEST_LIVING_LIGHT_SMARTLED_LUA"
#define product_key             "bIjq3G1NcgjSfF9uSeK2"
#define product_secret            "W6tXrtzgQHGZqksvJLMdCPArmkecBAdcr2F5tjuF"
#else
#define product_model         "ALINKTEST_LIVING_LIGHT_SMARTLED"
#define product_key             "ljB6vqoLzmP8fGkE6pon"
#define product_secret            "YJJZjytOCXDhtQqip4EjWbhR95zTgI92RVjzjyZF"
#endif
#define product_debug_key       "dpZZEpm9eBfqzK7yVeLq"
#define product_debug_secret    "THnfRRsU5vu6g6m9X6uFyAjUWflgZ0iyGjdEneKm"

#define product_dev_sn          "6923450656860"
#define product_dev_version     "1.3"
#define product_dev_type        "LIGHT"
#define product_dev_category    "LIVING"
#define product_dev_manufacturer "ALINKTEST"
#define product_dev_cid         "2D0044000F47333139373038"

/* device info */
#define product_dev_ DEV_CATEGORY "LIVING"
#define DEV_TYPE "LIGHT"
#define DEV_MANUFACTURE "ALINKTEST"

typedef struct _alink_config_t
{
    uint8_t alink_config_data[2048];
} alink_config_t;
