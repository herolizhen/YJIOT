#ifndef  __INCLUDES_H__
#define  __INCLUDES_H__

#include "stdio.h"
#include "string.h"

#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_usart.h"
#include "stm32f10x_it.h"

#include  "ucos_ii.h"  		//uC/OS-II系统函数头文件
#include "malloc.h"
#include "cJSON.h"

#include  	"BSP.h"			//与开发板相关的函数
#include 	"app.h"			//用户任务函数
#include 	"led.h"			//LED驱动函数

#include "user_usart2.h"
#include "user_usart3.h"
#include "modbus_master.h"
#include "trans_recieve_buff_control.h"

#include "user_usart1.h"
#include "user_usart.h"

#include "user_config.h"

#include "user_usart_wifi.h"

#include "user_modbus.h"

#endif //__INCLUDES_H__
