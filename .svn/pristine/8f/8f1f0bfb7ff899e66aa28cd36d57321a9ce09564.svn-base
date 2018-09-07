#ifndef __SOFT_IIC_H__
#define __SOFT_IIC_H__

#include "OB39R32T1.h"
//#include "TM1618.h"

/*
#define SOFT_IIC_SCL_PIN   P3_6
#define SOFT_IIC_SDA_PIN   P3_5

#define SOFT_IIC_SCL_PORTBIT    6
#define SOFT_IIC_SDA_PORTBIT    5


#define SOFT_IIC_PxM0      P3M0
#define SOFT_IIC_PxM1      P3M1


#define SCL_1 (SOFT_IIC_SCL_PIN = 1)
#define SCL_0 (SOFT_IIC_SCL_PIN = 0)
#define SDA_1 (SOFT_IIC_SDA_PIN = 1)
#define SDA_0 (SOFT_IIC_SDA_PIN = 0)
#define I2C_SDA_READ (SOFT_IIC_SDA_PIN ? 1 : 0)
*/

#define PIN_INPUT   0
#define PIN_OUTPUT  1

#define I2C_DIR_WR	0		/* Ð´¿ØÖÆbit */
#define I2C_DIR_RD	1		/* ¶Á¿ØÖÆbit */

enum IIC_NUM{

    TOUCH_KEY_IIC   = 0,
    HPD05_IIC       = 1

};



typedef struct{

    unsigned char IIC_NUM;
    void (*Set_SDA_Pin_Mode)(unsigned char mode);
    void (*Set_SCL_Pin_Mode)(unsigned char mode);
    void (*i2c_delay)(void);
    void (*i2c_delay1)(void);
    void (*SDA_1)(void);
    void (*SDA_0)(void);
    void (*SCL_1)(void);
    void (*SCL_0)(void);
    unsigned char (*I2C_SDA_READ)(void);


}IIC_Operations_Typedef;


/*
void Set_SDA_Pin_Mode(unsigned char mode);
void Set_SCL_Pin_Mode(unsigned char mode);
void Soft_IIC_PinConifg(void);

void i2c_delay(void);

void i2c_gpio_init(void);
void I2C_start(void);
void I2C_stop(void);
unsigned char I2C_WaitAck(void);
void I2C_Ack(void);
void I2C_NAck(void);
*/
void I2C_SendOneByte(unsigned char a);
unsigned char I2C_ReadOneByte(void);
unsigned int I2C_ReadBytes(unsigned char ClientAddr, unsigned char* pBuffer,unsigned int NumByteToRead);
unsigned int I2C_WriteBytes(unsigned char ClientAddr, unsigned char* pBuffer, unsigned int NumByteToWrite);






#endif