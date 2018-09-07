#include <stdio.h>
#include "sensor.h"
#include "SOFT_IIC.h"
#include "global.h"
#include "debug_uart.h"



#define SENSOR_IIC_DELAY_COUNT  2

void sensor_i2c_delay(void)
{
	int i = 0;
	for(i = 0;i < SENSOR_IIC_DELAY_COUNT;i++);
}


void SENSOR_IIC_PinConifg(void)
{
    //PIN设置为推挽输出，PxM0对应的位置1，PxM1对应的位置0  
    SENSOR_IIC_PxM0 &= ~((1 << SENSOR_IIC_SDA_PORTBIT) | (1 << SENSOR_IIC_SCL_PORTBIT));
    SENSOR_IIC_PxM1 &= ~((1 << SENSOR_IIC_SDA_PORTBIT) | (1 << SENSOR_IIC_SCL_PORTBIT));
  
    SENSOR_IIC_SCL_PIN = 1;
    SENSOR_IIC_SDA_PIN = 1;
}



void Set_Sensor_SDA_Pin_Mode(unsigned char mode)
{
    if(mode == PIN_INPUT)
    {
        //PIN设置为输入时，PxM0对应的位置0，PxM1对应的位置1
        SENSOR_IIC_PxM0 &= ~(1 << SENSOR_IIC_SDA_PORTBIT);
        SENSOR_IIC_PxM1 |= (1 << SENSOR_IIC_SDA_PORTBIT);
    }
    else if(mode == PIN_OUTPUT)
    {      
        SENSOR_IIC_PxM0 &= ~(1 << SENSOR_IIC_SDA_PORTBIT);
        SENSOR_IIC_PxM1 &= ~(1 << SENSOR_IIC_SDA_PORTBIT);
    }
}
  
void Set_Sensor_SCL_Pin_Mode(unsigned char mode)
{
    if(mode == PIN_INPUT)
    {
        //PIN设置为输入时，PxM0对应的位置0，PxM1对应的位置1
        SENSOR_IIC_PxM0 &= ~(1 << SENSOR_IIC_SCL_PORTBIT);
        SENSOR_IIC_PxM1 |= ((1 << SENSOR_IIC_SCL_PORTBIT));
    }
    else if(mode == PIN_OUTPUT)
    {      
        SENSOR_IIC_PxM0 &= ~(1 << SENSOR_IIC_SCL_PORTBIT);
        SENSOR_IIC_PxM1 &= ~(1 << SENSOR_IIC_SCL_PORTBIT);     
    }

}


void Sensor_IIC_SDA_1(void)
{
    SENSOR_IIC_SDA_PIN = 1;
}

void Sensor_IIC_SDA_0(void)
{
    SENSOR_IIC_SDA_PIN = 0;
}

void Sensor_IIC_SCL_1(void)
{
    SENSOR_IIC_SCL_PIN = 1;
}
void Sensor_IIC_SCL_0(void)
{
    SENSOR_IIC_SCL_PIN = 0;
}


unsigned char Sensor_IIC_SDA_READ(void)
{
    return (SENSOR_IIC_SDA_PIN ? 1 : 0);
}

/*
HPD05传感器寄存器0x26存放的当前粉尘浓度的低8位，寄存器0x27存放的是当前粉尘浓度的高8位
地址为0x9A 通讯波特率最大100kbps
*/
unsigned int Read_PMSensor_Data(void)
{
    static unsigned int last_pm_data = 0;
    unsigned char readaddr = HPD05_DATA_START_ADDR;
    unsigned char res = 1;
    unsigned int pm_data = 0;
  
    unsigned char readbuff[5] = {0};
    
    //unsigned char debug_buff[30] = {0};

    IIC_Operations.IIC_NUM = HPD05_IIC;
    IIC_Operations.Set_SDA_Pin_Mode = Set_Sensor_SDA_Pin_Mode;
    IIC_Operations.Set_SCL_Pin_Mode = Set_Sensor_SCL_Pin_Mode;
    IIC_Operations.i2c_delay = sensor_i2c_delay;
    IIC_Operations.SDA_1 = Sensor_IIC_SDA_1;
    IIC_Operations.SDA_0 = Sensor_IIC_SDA_0;
    IIC_Operations.SCL_1 = Sensor_IIC_SCL_1;
    IIC_Operations.SCL_0 = Sensor_IIC_SCL_0;
    IIC_Operations.I2C_SDA_READ = Sensor_IIC_SDA_READ;
  
    res = I2C_WriteBytes(HPD05_ADDRESS,&readaddr,1);
   
    if(res == 0)
    {
        res = I2C_ReadBytes(HPD05_ADDRESS,readbuff,5);     
    }
    
    
    if(readbuff[0] & 0x01)
    {
        pm_data = ((unsigned int)readbuff[1]) << 8 | readbuff[2]; 
        if(pm_data == 0)
        {
            pm_data = last_pm_data;
        }
      
//        mymemset(debug_buff,0,30);
//        sprintf(debug_buff,"buff:%x %x,pm_data:%d\n",(unsigned int)readbuff[1],(unsigned int)readbuff[2],(unsigned int)pm_data);
//        DEBUG_Uart_Sendbytes(debug_buff,mystrlen(debug_buff));
      
      
//        if(pm_data == 0)
//        {
//            pm_data = 2;
//        }          
    }
    else
    {
        pm_data = last_pm_data;
        
    }
    
    last_pm_data = pm_data;
    
    /*
    if(pm_data <= 5)
    {
        pm_data = 5;
    } 
    else if(pm_data <= 10)
    {
        pm_data = 10;
    }
    else if(pm_data <= 15)
    {
        pm_data = 15;
    } 
    else if(pm_data <= 20)
    {
        pm_data = 20;
    }
    */
    
    return pm_data;

}

