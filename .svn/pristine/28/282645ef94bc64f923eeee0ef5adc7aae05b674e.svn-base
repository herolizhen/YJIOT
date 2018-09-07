#ifndef __SENSOR_H__
#define __SENSOR_H__


#include "OB39R32T1.h"

//HK°å×Ó
//#define SENSOR_IIC_SCL_PORTBIT    3
//#define SENSOR_IIC_SDA_PORTBIT    2

//#define SENSOR_IIC_SCL_PIN    P3_3
//#define SENSOR_IIC_SDA_PIN    P3_2


//#define SENSOR_IIC_PxM0        P3M0
//#define SENSOR_IIC_PxM1        P3M1




//#define SENSOR_IIC_SCL_PORTBIT    6
//#define SENSOR_IIC_SDA_PORTBIT    5
//#define SENSOR_IIC_SCL_PIN    P3_6
//#define SENSOR_IIC_SDA_PIN    P3_5

//wifi board
//#define SENSOR_IIC_SCL_PORTBIT    5
//#define SENSOR_IIC_SDA_PORTBIT    6

//#define SENSOR_IIC_SCL_PIN    P3_5
//#define SENSOR_IIC_SDA_PIN    P3_6


//#define SENSOR_IIC_PxM0        P3M0
//#define SENSOR_IIC_PxM1        P3M1

//m26 board
//#define SENSOR_IIC_SCL_PORTBIT    6
//#define SENSOR_IIC_SDA_PORTBIT    5

//#define SENSOR_IIC_SCL_PIN    P2_6
//#define SENSOR_IIC_SDA_PIN    P2_5

#define SENSOR_IIC_SCL_PORTBIT    5
#define SENSOR_IIC_SDA_PORTBIT    6

#define SENSOR_IIC_SCL_PIN    P2_5
#define SENSOR_IIC_SDA_PIN    P2_6


#define SENSOR_IIC_PxM0        P2M0
#define SENSOR_IIC_PxM1        P2M1

#define SENSOR_POWER_PIN       P3_5
#define SENSOR_POWER_PORTBIT   5
#define SENSOR_POWER_PxM0        P3M0
#define SENSOR_POWER_PxM1        P3M1

#define HPD05_ADDRESS      (0x9A >> 1)

#define HPD05_DATA_START_ADDR    0x23
#define HPD05_DATA_ADDR    0x26


typedef enum {

  SENSOR_HCHO = 1,
  SENSOR_PM25 = 2


}SensorType;


void SENSOR_IIC_PinConifg(void);

void Sensor_Power_On(void);
void Sensor_Power_Off(void);

void Set_Sensor_SDA_Pin_Mode(unsigned char mode);
void Set_Sensor_SCL_Pin_Mode(unsigned char mode);

void sensor_i2c_delay(void);
void Sensor_IIC_SDA_1(void);
void Sensor_IIC_SDA_0(void);
void Sensor_IIC_SCL_1(void);
void Sensor_IIC_SCL_0(void);
unsigned char Sensor_IIC_SDA_READ(void);



unsigned int Read_PMSensor_Data(void);


#endif