#ifndef __USER_TIMER_H__
#define __USER_TIMER_H__

typedef struct{

  unsigned char user_timer_start;
  unsigned char timer_state;
  unsigned int set_time;
  unsigned int left_time;
    
}user_timer_t;


enum user_timer_type_t{

  USER_TIMER_NONE = 0,
  USER_TIMER_2H   = 1,
  USER_TIMER_4H   = 2

};



//#define MIN_TO_MS     (60*1000)

//#define MONTH_TO_MIN  (30*24*60)
//#define DAY_TO_MIN    (24*60)
//#define HOUR_TO_MIN   (100)



void user_timer_init(void);
void user_timer_count(void);
void stop_user_timer(void);

void set_user_timer(unsigned char timer_type);





#endif