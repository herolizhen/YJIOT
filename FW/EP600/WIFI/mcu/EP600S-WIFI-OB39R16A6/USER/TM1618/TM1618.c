#include "TM1618.h"
#include "sensor.h"

//buff[0]-buff[9]分别表示显示0-9，buff[10]表示数码管灭
const unsigned char led_display_buff[11][2] = {
 //0-4
{0x1F,0x08},{0x06,0x00},{0x1B,0x10},{0x0F,0x10},{0x06,0x18},
//5-9
{0x0D,0x18},{0x1C,0x18},{0x07,0x00},{0x1F,0x18},{0x07,0x18},
//灭
{0x00,0x00}


};

static void mydelay(int num)
{
    while(num--);
}
  
void TM1618_Pin_Config(void)
{
    //PIN设置为推挽输出，PxM0对应的位置1，PxM1对应的位置0
    P1M0 |= ((1 << 3) | (1 << 4) | (1 << 5));
    P1M1 &= ~((1 << 3) | (1 << 4) | (1 << 5));
    TM1618_STB_PIN = 1;
    TM1618_CLK_PIN = 1;
    TM1618_DIO_PIN = 1;
  
}



//刚上电后设置显示模式5位7段，把TM1618的显示寄存器0xC0-0xCD全部写0
void TM1618_Init(void)
{
    TM1618_Pin_Config();
    TM1618_SetMode();
    TM1618_Clear_Framebuff();
    TM1618_Display_On();
}


void TM1618_WriteOneByte(unsigned char senddata)
{
    unsigned char i = 0;
    unsigned char tempdata = 0;
  
    tempdata = senddata;
    //TM1618_STB_PIN = 0;
  
    
    for(i = 0;i < 8;i++)
    {
        TM1618_CLK_PIN = 0;
        if(tempdata & 0x01)
        {
            TM1618_DIO_PIN = 1;
        }
        else
        {
            TM1618_DIO_PIN = 0;
        }
        //TM1618_CLK_PIN = 0;
        mydelay(1);
        TM1618_CLK_PIN = 1;
        mydelay(1);
        
        tempdata = tempdata >> 1;       
    }
    //TM1618_STB_PIN = 1;    
}

/*
void TM1618_WriteBytes(const unsigned char *senddata,unsigned char num)
{
    unsigned char i,j = 0;
    unsigned char tempdata = 0;
  
    //TM1618_STB_PIN = 0;
  
    for(j = 0;j < num;j++)
    {
        tempdata = *(senddata + j);
        for(i = 0;i < 8;i++)
        {
            TM1618_CLK_PIN = 0;
            if(tempdata & 0x01)
            {
                TM1618_DIO_PIN = 1;
            }
            else
            {
                TM1618_DIO_PIN = 0;
            }           
            mydelay(2);
            TM1618_CLK_PIN = 1;
            mydelay(1);
        
            tempdata = tempdata >> 1;       
        }
    }
    //TM1618_STB_PIN = 1;    
}
*/

//设置为5位7段模式
void TM1618_SetMode(void)
{
    TM1618_STB_PIN = 0;
    TM1618_WriteOneByte(TM1618_MODE_CMD);
    TM1618_STB_PIN = 1;
}

//设置数据命令
void TM1618_SetDataMode(void)
{
    TM1618_STB_PIN = 0;
    TM1618_WriteOneByte(TM1618_DATA_CMD);
    TM1618_STB_PIN = 1;
}

//往TM1618的显示寄存器中写数据
void TM1618_WriteFrameRegister(unsigned char *displaybuff,unsigned char lednum)
{
    unsigned char i,j = 0;
  
    TM1618_SetDataMode();
    mydelay(2);
    TM1618_STB_PIN = 0; 
    //设置数据传送寄存器首地址  
    TM1618_WriteOneByte(TM1618_SET_ADDR_CMD);
    for(i = 0;i < lednum;i++)
    {
        for(j = 0;j < 2;j++)
        {
            TM1618_WriteOneByte(led_display_buff[displaybuff[i]][j]);
        }
        
    }  
    TM1618_STB_PIN = 1;
}

//把显示寄存器清零
void TM1618_Clear_Framebuff(void)
{
    unsigned char i = 0;
  
    TM1618_SetDataMode();
  
    TM1618_STB_PIN = 0;
    TM1618_WriteOneByte(TM1618_SET_ADDR_CMD);
    for(i = 0;i < 14;i++)
    {
        TM1618_WriteOneByte(0x00);
    }     
    TM1618_STB_PIN = 1;
  
}

void TM1618_Display_On(void)
{
    TM1618_STB_PIN = 0;
    TM1618_WriteOneByte(TM1618_PULSE_WIDTH_10_16);
    TM1618_STB_PIN = 1;
}

/*
void TM1618_Display_Off(void)
{
    TM1618_STB_PIN = 0;
    TM1618_WriteOneByte(TM1618_OFF);
    TM1618_STB_PIN = 1;
}
*/

void TM1618_DispalyData(unsigned char sensor,float sensordata)
{
    unsigned char j = 0;
    unsigned char displaybuff[3] = {0};
    unsigned int displaydata = 0;
    if(sensor == SENSOR_HCHO)
    {
        if(sensordata >= 10)
        {
            displaydata = 999;         
        }
        else
        {
            displaydata = (int)(sensordata * 100);
        }

    }
    else if(sensor == SENSOR_PM25)
    {
        if(sensordata >= 1000)
        {
            displaydata = 999;
        }
        else
        {
            displaydata = (int)sensordata;
        }
    }
    

    displaybuff[2] = displaydata / 100;
    displaybuff[1] = (displaydata % 100) / 10;
    displaybuff[0] = displaydata % 10;
    
    if(sensor == SENSOR_HCHO)
    {
//        TM1618_WriteFrameRegister(displaybuff,1);
//        //显示甲醛数据的时候要显示小数点
//        LED1_DP_PIN = 1;
//        mydelay(3);
//        LED1_DP_PIN = 0;
//        TM1618_WriteFrameRegister(displaybuff,1);
        
    }
    else if(sensor == SENSOR_PM25)
    {

    }
    
    TM1618_WriteFrameRegister(displaybuff,3);
    
    
}


