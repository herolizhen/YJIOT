#include "TM1620.h"
#include "sensor.h"

//buff[0]-buff[9]分别表示显示0-9，buff[10]表示数码管灭
const unsigned char led_display_buff[11] = {
 //0-4
 0x3F,0x06,0x5B,0x4F,0x66,
//5-9
0x6D,0x7D,0x07,0x7F,0x6F,
//灭
0x00


};

static void mydelay(int num)
{
    while(num--);
}
  
void TM1620_Pin_Config(void)
{
    //PIN设置为推挽输出，PxM0对应的位置1，PxM1对应的位置0
    P1M0 |= ((1 << 3) | (1 << 4) | (1 << 5));
    P1M1 &= ~((1 << 3) | (1 << 4) | (1 << 5));
    TM1620_STB_PIN = 1;
    TM1620_CLK_PIN = 1;
    TM1620_DIO_PIN = 1;
  
}



//刚上电后设置显示模式5位7段，把TM1620的显示寄存器0xC0-0xCD全部写0
void TM1620_Init(void)
{
    TM1620_Pin_Config();
    TM1620_SetMode();
    TM1620_Clear_Framebuff();
    TM1620_Display_On();
}


void TM1620_WriteOneByte(unsigned char senddata)
{
    unsigned char i = 0;
    unsigned char tempdata = 0;
  
    tempdata = senddata;
    //TM1620_STB_PIN = 0;
  
    
    for(i = 0;i < 8;i++)
    {
        TM1620_CLK_PIN = 0;
        if(tempdata & 0x01)
        {
            TM1620_DIO_PIN = 1;
        }
        else
        {
            TM1620_DIO_PIN = 0;
        }
        //TM1620_CLK_PIN = 0;
        mydelay(1);
        TM1620_CLK_PIN = 1;
        mydelay(1);
        
        tempdata = tempdata >> 1;       
    }
    //TM1620_STB_PIN = 1;    
}

/*
void TM1620_WriteBytes(const unsigned char *senddata,unsigned char num)
{
    unsigned char i,j = 0;
    unsigned char tempdata = 0;
  
    //TM1620_STB_PIN = 0;
  
    for(j = 0;j < num;j++)
    {
        tempdata = *(senddata + j);
        for(i = 0;i < 8;i++)
        {
            TM1620_CLK_PIN = 0;
            if(tempdata & 0x01)
            {
                TM1620_DIO_PIN = 1;
            }
            else
            {
                TM1620_DIO_PIN = 0;
            }           
            mydelay(2);
            TM1620_CLK_PIN = 1;
            mydelay(1);
        
            tempdata = tempdata >> 1;       
        }
    }
    //TM1620_STB_PIN = 1;    
}
*/

//设置为5位7段模式
void TM1620_SetMode(void)
{
    TM1620_STB_PIN = 0;
    TM1620_WriteOneByte(TM1620_MODE_CMD);
    TM1620_STB_PIN = 1;
}

//设置数据命令
void TM1620_SetDataMode(void)
{
    TM1620_STB_PIN = 0;
    TM1620_WriteOneByte(TM1620_DATA_CMD);
    TM1620_STB_PIN = 1;
}

//往TM1620的显示寄存器中写数据，该函数指针对GRID1 GRID2 GRID3控制的数码管
void TM1620_WriteFrameRegister(unsigned char sensortype,unsigned char grid_num,unsigned char *displaybuff,unsigned char bufferlength)
{
    unsigned char i = 0;
    unsigned char address = 0;
    unsigned char senddata = 0;
   
    if(grid_num >= GRID_MAX || grid_num == 0)
    {
        return;
    }
    
    if(bufferlength > ((7 - grid_num) * 2))
    {
        //采用的是6位8段模式，要写入显示寄存器的长度不能超过显示寄存器的范围
        return;
    }
    
    address = TM1620_ADDR_CMD_BASE + (grid_num - 1) * 2;
  
    TM1620_SetDataMode();
    mydelay(2);
    TM1620_STB_PIN = 0; 
    //设置数据传送寄存器首地址  
    TM1620_WriteOneByte(address);
    for(i = 0;i < bufferlength;i++)
    { 
        senddata = 0;
      
        if(sensortype == SENSOR_HCHO && i == 4)
        {
            //显示甲醛数据的话需要增加小数点
            senddata = led_display_buff[displaybuff[i]] | (1 << 7);
        }
        else
        {
            senddata = led_display_buff[displaybuff[i]];
        }          
        //TM1620_WriteOneByte(led_display_buff[displaybuff[i]] | (1 << 7)); 
        TM1620_WriteOneByte(senddata);  
            
    }
    TM1620_STB_PIN = 1;
}

//把显示寄存器清零
void TM1620_Clear_Framebuff(void)
{
    unsigned char i = 0;
  
    TM1620_SetDataMode();
  
    TM1620_STB_PIN = 0;
    TM1620_WriteOneByte(TM1620_ADDR_CMD_BASE);
    for(i = 0;i < 12;i++)
    {
        TM1620_WriteOneByte(0x00);
    }     
    TM1620_STB_PIN = 1;
  
}

void TM1620_Display_On(void)
{
    TM1620_STB_PIN = 0;
    TM1620_WriteOneByte(TM1620_PULSE_WIDTH_10_16);
    TM1620_STB_PIN = 1;
}

/*
void TM1620_Display_Off(void)
{
    TM1620_STB_PIN = 0;
    TM1620_WriteOneByte(TM1620_OFF);
    TM1620_STB_PIN = 1;
}
*/

void TM1620_DispalyData(unsigned char sensor,float sensordata)
{
    unsigned char j = 0;
    unsigned char displaybuff[5] = {0};
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
    

//    displaybuff[2] = displaydata / 100;
//    displaybuff[1] = (displaydata % 100) / 10;
//    displaybuff[0] = displaydata % 10;
    //最左边数码管显示的数据
    displaybuff[4] = displaydata / 100;
    //displaybuff[1] = displaydata / 100;
    //中间数码管显示的数据
    displaybuff[2] = (displaydata % 100) / 10;
    //最右边数码管显示的数据
    displaybuff[0] = displaydata % 10;
    
    if(sensor == SENSOR_HCHO)
    {
//        TM1620_WriteFrameRegister(displaybuff,1);
//        //显示甲醛数据的时候要显示小数点
//        LED1_DP_PIN = 1;
//        mydelay(3);
//        LED1_DP_PIN = 0;
//        TM1620_WriteFrameRegister(displaybuff,1);
        
    }
    else if(sensor == SENSOR_PM25)
    {

    }
    
    TM1620_WriteFrameRegister(sensor,GRID1,displaybuff,5);
    
    
}


void TM1620_LED_Control(unsigned char led,unsigned char on_off)
{
    
    //static unsigned char led_group_data[4] = {0};
    static unsigned char led_group1_data = 0;
    static unsigned char led_group2_data = 0;
  
    unsigned char register_addr = 0x00;
    unsigned char register_data = 0x00;
    //unsigned char grid = 0;
      
    if(led >= LED_MAX_NUM || on_off >= 2)
    {
        return;
    }
    
    if(led <= LED_UV)
    {
        //register_addr = TM1620_ADDR_CMD_BASE + (LED_GROUP1_GRID_NUM - 1) * 2;  
        if(on_off == 1)
        {
            if(led >= LED_QUIET && led <= LED_SPEED_HIGH)
            {
                led_group1_data &= ~((1 << LED_QUIET) | (1 << LED_SPEED_LOW) | (1 << LED_SPEED_MID) | (1 << LED_SPEED_HIGH));
            }
            led_group1_data |= (1 << led);
        } 
        else
        {
            led_group1_data &= ~(1 << led);
        } 
        register_addr = TM1620_ADDR_CMD_BASE + 0x08;  
        register_data = led_group1_data; 
               
    }
    else if(led < LED_ALL)
    {
        //register_addr = TM1620_ADDR_CMD_BASE + (LED_GROUP2_GRID_NUM - 1) * 2;   
        if(on_off == 1)
        {
            led_group2_data |= (1 << (led - LED_ION));
            if(led == LED_TIMER_2H)
            {
                led_group2_data &= ~(1 << (led - LED_ION + 1));
            }
            else if(led == LED_TIMER_4H)
            {
                led_group2_data &= ~(1 << (led - LED_ION -1));
            }
            
        } 
        else
        {
            led_group2_data &= ~(1 << (led - LED_ION));
        } 
        register_addr = TM1620_ADDR_CMD_BASE + 0x0A;  
        register_data = led_group2_data;         
    }
    else if(led == LED_ALL)
    {
        if(on_off == 1)
        {
            led_group1_data = 0x7F;
            led_group2_data = 0x7F;
        } 
        else
        {
            led_group1_data = (1 << LED_POWER);
            led_group2_data = 0x00;
        } 
        register_addr = TM1620_ADDR_CMD_BASE + 0x08;           
    }
    
    //TM1620_WriteFrameRegister(GRID5,led_group_data,1);
    TM1620_SetDataMode();
    mydelay(2);
    TM1620_STB_PIN = 0; 
    //设置数据传送寄存器首地址  
    TM1620_WriteOneByte(register_addr);
    if(led != LED_ALL)
    {
        TM1620_WriteOneByte(register_data);   
    }
    else
    {
        TM1620_WriteOneByte(led_group1_data);
        TM1620_WriteOneByte(led_group2_data);
    }

    TM1620_STB_PIN = 1;
    
}


