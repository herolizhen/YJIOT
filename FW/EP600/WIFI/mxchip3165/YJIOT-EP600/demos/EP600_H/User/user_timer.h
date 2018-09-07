#ifndef __USER_TIMER__
#define __USER_TIMER__

#include "mico.h"

typedef struct{
  
  int type;
  int set_time;
  //int left_time;

}user_set_timer_t;

typedef struct{
  
  int type;
  int set_time;
  int left_time;

}user_upload_timer_t;


//void set_timer_thread(mico_thread_arg_t arg);



#endif