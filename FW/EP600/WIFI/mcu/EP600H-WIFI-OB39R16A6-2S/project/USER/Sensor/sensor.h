#ifndef __SENSOR_H__
#define __SENSOR_H__


#include "OB39R32T1.h"

#define SENSOR_CONTROL_PIN   P3_2
#define SENSOR_PIN_PORTBIT   2
#define SENSOR_PIN_PxM0      P3M0
#define SENSOR_PIN_PxM1      P3M1


typedef enum {

  SENSOR_HCHO = 1,
  SENSOR_PM25 = 2


}SensorType;


typedef struct{

  unsigned char is_reset_sensor;
  unsigned char step;

}reset_sensor_t;



void sensor_contron_pin_init(void);
void sensor_init(void);
void set_sensor_run(void);
void set_sensor_sleep(void);

void reset_sensor(void);
void reset_sensor_loop(void);


//每次上电后PMS5003S默认是主动上传数据，发送控制命令可以设置为被动模式，设置成通过发送命令的方式读取传感器数据
void set_sensor_to_unactive_mode(void);
void get_sensor_data_cmd(void);

unsigned char check_sum(const unsigned char *sensor_buff,unsigned char buff_length);
void calculate_sensor_data(const unsigned char *sensor_buff);


void deal_framebuff(const unsigned char *buff,unsigned char length);
void get_sensor_data(void);





#endif