#ifndef __SYS_RUN_H__
#define __SYS_RUN_H__


//自动模式下PM2.5和风挡的对应关系 0-75静音模式  75-150低档  >150高档
#define PM25_QUIET_SPEED   75
#define PM25_LOW_SPEED     150


//自检status的位定义
#define door_bit   0
#define fan_bit    1
#define uv_bit     2
#define pm25_bit   3

//自检按键的检测touch_key_check的位定义
#define power_bit 0
#define quiet_speed_bit 1
#define low_speed_bit   2
#define mid_speed_bit   3
#define high_speed_bit  4
#define timer_bit 5
#define mode_bit 6
#define wifi_bit 7




typedef struct{

  unsigned char step;
  //status是系统检测标志，bit0表示仓门，bit1表示风机，bit2表示uv灯
  unsigned char status;
  unsigned char fg_count;
  unsigned char fan_check_fault_times;
  //按键检测标志位，bit0:power,bit1:quiet_speed,bit2:low_speed,bit3:mid_speed,bit4:high_speed,bit5:timer,bit6:mode,bit7:wifi
  unsigned char touch_key_check;
  unsigned long start_time;

}sys_check_t;







void sys_init_check(void);

void sys_data_clear(void);

void sys_start(void);
void sys_stop(void);

void sys_run(void);

void display_pm_data(void);

void sys_smart_mode(void);


void check_if_doorclose_manual(void);

void set_sys_to_smart_mode(void);
void stop_sys_smart_mode(void);

void sys_dev_auto_check(void);
void start_sys_auto_check(void);
void start_sys_manual_check(void);
void stop_sys_auto_check(void);
void stop_sys_manual_check(void);



void check_if_stop_manual_check(void);




#endif