#ifndef __MICO_APP_DEFINE_H
#define __MICO_APP_DEFINE_H

#include "alink_config.h"
#include "Common.h"
#include "Debug.h"

#define MANUFACTURER_NAME "EMB"
#define PRODUCT_TYPE "SMARTLED"
#define PRODUCT_MODEL "TEST"

/*Application's configuration stores in flash*/
typedef struct
{
    alink_config_t         alink_config;
} application_config_t;

typedef struct _app_context_t
{
  /*Flash content*/
  application_config_t*     appConfig;

} app_context_t;



#endif

