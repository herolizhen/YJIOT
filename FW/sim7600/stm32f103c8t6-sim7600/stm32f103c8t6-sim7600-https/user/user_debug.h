#ifndef __USER_DEBUG_H__
#define __USER_DEBUG_H__


#include "ucos_ii.h"

#define user_debug_enabled 1

extern OS_EVENT *stdio_tx_mutex;

/*
#define custom_log(N, M, ...) do {if (mico_debug_enabled==0)break;\
                                      mico_rtos_lock_mutex( &stdio_tx_mutex );\
                                      printf("[%s: %s:%4d] " M "\r\n", N, SHORT_FILE, __LINE__, ##__VA_ARGS__);\
                                      mico_rtos_unlock_mutex( &stdio_tx_mutex );}while(0==1)
*/
                                      
#define custom_log(N, M, ...) do {INT8U err;\
                                      if (user_debug_enabled==0)break;\
                                      OSMutexPend(stdio_tx_mutex,0,&err);\
                                      printf("[%s: %s:%4d] " M "\r\n", N, __FILE__, __LINE__, ##__VA_ARGS__);\
                                      OSMutexPost(stdio_tx_mutex);}while(0==1)
                              
#endif
                        