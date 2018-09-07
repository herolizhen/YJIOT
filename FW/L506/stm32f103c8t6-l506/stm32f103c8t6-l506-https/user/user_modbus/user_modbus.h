#ifndef __USER_MODBUS_H__
#define __USER_MODBUS_H__

#include "stdint.h"




void moubus_loop(void);
uint8_t send_data_to_wifi(const uint16_t *data_buff,uint8_t which_config);
void Task_modbus(void *p_arg);





#endif

