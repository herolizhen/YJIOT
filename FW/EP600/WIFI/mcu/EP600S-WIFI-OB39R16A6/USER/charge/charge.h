#ifndef __CHARGE_H__
#define __CHARGE_H__

typedef struct{

  unsigned char IsCostType;
  unsigned char IsHavetime;
  unsigned char left_time_month;
  unsigned char left_time_day;
  unsigned char left_time_hour;
  unsigned char left_time_min;
  unsigned long lefttime;  //单位是分钟
  unsigned long lefttime_bak;
  unsigned char IsChargeStart;
  unsigned char IsGetChargeInfo;
  unsigned char get_charge_info_failtimes;
  unsigned char IsSelfChargeMode;
  unsigned char StartSelfCharge;
  //unsigned char Is_charge_init;
  
}Cost_Typedef;



#define MIN_TO_MS     (60*1000)

#define MONTH_TO_MIN  (30*24*60)
#define DAY_TO_MIN    (24*60)
#define HOUR_TO_MIN   (100)

//获取计费信息的时间间隔，单位ms
#define GET_TIME_INTERVAL   2000

//GET_TIME_INTERVAL 秒钟检测一次，2*60=120秒，如果连续5分钟跟wifi模块无法通讯，则开启MCU自计费模式
#define UART_FAIL_MAX_TIMES   60


void charge_init(void);
void get_charge_info(void);
void mcu_self_charge(void);





#endif