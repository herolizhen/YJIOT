#include <stdio.h>
#include <string.h>
#include "sensor.h"
#include "global.h"
#include "debug_uart.h"
#include "sensor_uart.h"

extern bit is_sensor_uart_get_data;


reset_sensor_t reset_sensor_s;


void sensor_contron_pin_init(void)
{
    SENSOR_PIN_PxM0 |= (1 << SENSOR_PIN_PORTBIT);
    SENSOR_PIN_PxM1 &= ~(1 << SENSOR_PIN_PORTBIT);
  
    SENSOR_CONTROL_PIN = 1;
}


void sensor_init(void)
{
    init_UART1();
    sensor_contron_pin_init();
    is_set_senor_mode_success = 0;
    reset_sensor_s.step = 0;
    reset_sensor_s.is_reset_sensor = 0;
    
}


void set_sensor_run(void)
{
    SENSOR_CONTROL_PIN = 1;
}

 
void set_sensor_sleep(void)
{
    SENSOR_CONTROL_PIN = 0;
    is_set_senor_mode_success = 0;
}

void reset_sensor(void)
{
    reset_sensor_s.is_reset_sensor = 1;
    is_set_senor_mode_success = 0;
    reset_sensor_s.step = 0;
}


//此函数1秒执行1次即可
void reset_sensor_loop(void)
{
    if(reset_sensor_s.step == 0)
    {
        set_sensor_sleep();
        reset_sensor_s.step += 1;
        
    }
    else if(reset_sensor_s.step == 1)
    {
        set_sensor_run();
        reset_sensor_s.step += 1;
    }
    else if(reset_sensor_s.step >= 2)
    {
        if(is_set_senor_mode_success == 0)
        {
            set_sensor_to_unactive_mode();
        }
        else
        {
            reset_sensor_s.step = 0;
            reset_sensor_s.is_reset_sensor = 0;
        }        
    }
}


//每次上电后PMS5003S默认是主动上传数据，发送控制命令可以设置为被动模式，设置成通过发送命令的方式读取传感器数据
void set_sensor_to_unactive_mode(void)
{
    unsigned char cmd[7] = {0x42,0x4D,0xE1,0x00,0x00,0x01,0x70};
    Sensor_Uart_Sendbytes(cmd,sizeof(cmd));
}


void get_sensor_data_cmd(void)
{
    unsigned char cmd[7] = {0x42,0x4D,0xE2,0x00,0x00,0x01,0x71};
    
    if(is_set_senor_mode_success == 0)
    {
        return;
    }
    Sensor_Uart_Sendbytes(cmd,sizeof(cmd));
}


unsigned char check_sum(const unsigned char *sensor_buff,unsigned char buff_length)
{
    unsigned char res = 0;
    unsigned int buff_check_sum = 0;
    unsigned int temp_check_sum = 0;
  
    unsigned char i = 0;
  
    //unsigned char debug_buff[40] = {0};
  
    if(sensor_buff == NULL || buff_length < 4)
    {
        res = 2;
        goto exit;
    } 
  
    buff_check_sum = ((int)sensor_buff[buff_length - 2] << 8) | sensor_buff[buff_length - 1];
    
    for(i = 0;i < (buff_length - 2);i++)
    {
        temp_check_sum += sensor_buff[i];
    }
    
    
    if(buff_check_sum != temp_check_sum)
    {
        memset(debug_buff_40,0,sizeof(debug_buff_40));
        sprintf(debug_buff_40,"b_sum:0x%x,t_sum:0x%x\r\n",(unsigned int)buff_check_sum,(unsigned int)temp_check_sum);
        DEBUG_Uart_Sendbytes(debug_buff_40,strlen(debug_buff_40)); 
      
        res = 1;   
    }
    else
    {
        res = 0; 
    }
    
exit:
    
    return res;
}

void calculate_sensor_data(const unsigned char *sensor_buff)
{
    if(sensor_buff[0] != 0x42 || sensor_buff[1] != 0x4D)
    {
        goto error_exit;      
    }
    PM1_value = ((unsigned int)sensor_buff[10] << 8) | sensor_buff[11];
    PM25_value = ((unsigned int)sensor_buff[12] << 8) | sensor_buff[13];
    PM10_value = ((unsigned int)sensor_buff[14] << 8) | sensor_buff[15];
    HCHO_value = (float)(((unsigned int)sensor_buff[28] << 8) | sensor_buff[29]) / 1000;
    
    if(PM25_value < 2)
    {
        display_pm25_value = 2;
    }
    else
    {
        display_pm25_value = PM25_value;
    }
    display_HCHO_value = HCHO_value + 0.01;
       
    memset(debug_buff_40,0,sizeof(debug_buff_40));
    sprintf(debug_buff_40,"pm1:%d,pm25:%d,pm10:%d,HCHO:%f\r\n",(unsigned int)PM1_value,(unsigned int)PM25_value,(unsigned int)PM10_value,HCHO_value);
    DEBUG_Uart_Sendbytes(debug_buff_40,strlen(debug_buff_40)); 
    
   
    return;
    
    
error_exit:
    
    memset(debug_buff_40,0,sizeof(debug_buff_40));
    sprintf(debug_buff_40,"sensor buff err\r\n");
    DEBUG_Uart_Sendbytes(debug_buff_40,strlen(debug_buff_40)); 
    
    PM25_value = 0;
    HCHO_value = 0;


}

void deal_framebuff(const unsigned char *buff,unsigned char length)
{
    if(check_sum(buff,length) == 0)
    {
        if(buff[4] == 0xE1)
        {
            is_set_senor_mode_success = 1;
                          
            memset(debug_buff_40,0,sizeof(debug_buff_40));
            sprintf(debug_buff_40,"set sensor mode success\r\n");
            DEBUG_Uart_Sendbytes(debug_buff_40,strlen(debug_buff_40)); 
        }
        else
        {
            if(buff[3] == (SENSOR_DATA_LENGTH - 4))
            {
                calculate_sensor_data(buff);
            }
        }
    }
    else 
    {
        memset(debug_buff_40,0,sizeof(debug_buff_40));
        sprintf(debug_buff_40,"check sum err\r\n");
        DEBUG_Uart_Sendbytes(debug_buff_40,strlen(debug_buff_40)); 
    }
}


static unsigned char sensor_data[SENSOR_DATA_MAX_LENGTH] = {0};
void get_sensor_data(void)
{
    unsigned char i = 0;
    unsigned int length = 0;
  
    if(is_sensor_uart_get_data == 1)
    {
//        mymemset(debug_buff_40,0,sizeof(debug_buff_40));
//        sprintf(debug_buff_40,"get sensor data\r\n");
//        DEBUG_Uart_Sendbytes(debug_buff_40,mystrlen(debug_buff_40)); 
      
        if(U1RxPtr > sizeof(sensor_data))
        {
            memset(debug_buff_40,0,sizeof(debug_buff_40));
            sprintf(debug_buff_40,"out of buff range\r\n");
            DEBUG_Uart_Sendbytes(debug_buff_40,strlen(debug_buff_40)); 
            return;
        }
        for(i = 0;i < U1RxPtr;i++)
        {
            sensor_data[i] = U1RxBuffer[i];
        }
        length = U1RxPtr;
        
        clear_sensor_uart_buff();
        
        is_sensor_uart_get_data = 0;
        
        deal_framebuff(sensor_data,length);
        
        
        
    }
}


