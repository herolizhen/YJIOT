#ifndef __USER_MQTT_TASK_H__
#define __USER_MQTT_TASK_H__

#include "user_debug.h"

#define MQTT_LOG(M,...)  custom_log("MQTT", M, ##__VA_ARGS__)


void user_mqtt_task(void *para);





#endif

