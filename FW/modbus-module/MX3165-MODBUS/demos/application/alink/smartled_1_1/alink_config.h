/*************************************************
 ALINK CONFIG
 *************************************************/
#include "common.h"

#pragma once

#define PASS_THROUGH

//TODO: update these product info
#define product_dev_name        "ALINKTEST"
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

#define product_dev_sn          "12345678"
#define product_dev_version     "1.0.7"
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
