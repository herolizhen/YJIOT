#include <stdio.h>
#include <string.h>
#include "wifi_uart.h"
#include "global.h"
#include "common.h"
#include "dc_motor.h"
#include "UV.h"
#include "ION.h"
#include "sys_run.h"
#include "debug_uart.h"
#include "TM1620.h"
#include "sys_run.h"
#include "buzzer.h"
#include "step_motor.h"
#include "timer.h"
#include "UART0.h"


union{
  
  unsigned char b[4];
  float f;
  
}cfloat;


#ifdef WIFI_SOFT_UART
void Wifi_Uart_Init(void)
{
   //TXD设为输出
   WIFI_UART_PxM0 &= ~(1 << WIIF_UART_TXD_PORTBIT);
   WIFI_UART_PxM1 &= ~(1 << WIIF_UART_TXD_PORTBIT); 
  
   //RXD设为输入
//   WIFI_UART_PxM0 &= ~(1 << WIFI_UART_RXD_PORTBIT);
//   WIFI_UART_PxM1 |= (1 << WIFI_UART_RXD_PORTBIT); 
  
   WIFI_UART_PxM0 &= ~(1 << WIFI_UART_RXD_PORTBIT);
   WIFI_UART_PxM1 &= ~(1 << WIFI_UART_RXD_PORTBIT); 
  
   WIFI_UART_TXD_PIN = 1;
   WIFI_UART_RXD_PIN = 1;
  
   mymemset(U2RxBuffer,0,U2RxBuff_MAXSIZE);
   
}
#endif



#ifdef WIFI_SOFT_UART    //模拟UART
void Wifi_Uart_Sendbytes(unsigned char *sendbuff,unsigned char sendnum)
{
    unsigned char i = 0;
  
    if(sendnum + U2LdPtr > U2TxBuff_MAXSIZE)
    {
        return;
    }
    for(i = 0;i < sendnum;i++)
    {
        U2TxBuffer[i + U2LdPtr] = sendbuff[i];
    }
    U2LdPtr += sendnum;
    if(IsU2TxBusy == 0)
    {
        U2TxBitCount = 10;
        U2TxRate = 3;
    }

}
#else  //硬件IIC
void Wifi_Uart_Sendbytes(unsigned char *sendbuff,unsigned char sendnum)
{
    unsigned char i = 0;
    
    for(i = 0;i < sendnum;i++)
    {
        UART0_TX(sendbuff[i]);
    }
}

#endif



unsigned char Wifi_Uart_ReceiveOnePackage(unsigned char *receivebuff,unsigned char maxnum)
{
    unsigned char i = 0;
    unsigned char max_receive_num = 0;

  
    unsigned char debug_buff[40] = {0};
  
 #ifdef WIFI_SOFT_UART  //模拟IIC    
    if(IsU2RxBusy)
    {
        return 0;
    }
  
    if(receive_num > U2RxBuff_MAXSIZE)
    {
        max_receive_num = U2RxBuff_MAXSIZE;
    }
    else
    {
        max_receive_num = receive_num;
    }
     
    while(i < U2RxPtr)
    {
        receivebuff[i] = U2RxBuffer[i];
        i += 1;
    }
    
    mymemset(U2RxBuffer,0,i);
    U2RxPtr = 0;
 #else
    
//    if(receive_num > U0RxBuff_MAXSIZE)
//    {
//        max_receive_num = U0RxBuff_MAXSIZE;
//    }
//    else
//    {
//        max_receive_num = receive_num;
//    }
    if(U0RxPtr > maxnum || U0RxPtr >= U0RxBuff_MAXSIZE)
    {   
        mymemset(U0RxBuffer,0,U0RxBuff_MAXSIZE);
        U0RxPtr = 0; 
        return 0;
    }
    
    if(U0RxPtr == 0 || (U0RxPtr != 0 && U0RxBuffer[U0RxPtr -1] != 0x23 )  )
    {
        return 0;
    }
    
    while(i < U0RxPtr)
    {
        receivebuff[i] = U0RxBuffer[i];
        i += 1;
    }
    
//    if(U0RxPtr > temp_index)
//    {
//        for(i = 0;i < (U0RxPtr - temp_index);i++)
//        {
//            receivebuff[temp_index + i] = U0RxBuffer[temp_index + i];
//        }
//        mymemset(debug_buff,0,sizeof(debug_buff));
//        sprintf(debug_buff,"U0RxPtr:%d,temp_index:%d\r\n",(unsigned int)U0RxPtr,(unsigned int)temp_index);
//        DEBUG_Uart_Sendbytes(debug_buff,strlen(debug_buff)); 
//    }
    
    U0RxPtr = 0;  
    
    mymemset(U0RxBuffer,0,i);
    
 #endif    
       
    return i;

}



void Deal_Wifi_Uart_Data(void)
{
    static unsigned char wifi_data_buff[WIFI_DATA_BUFF_SIZE] = {0};
    static unsigned char wifi_buff_index = 0;
    unsigned char get_wifi_data_num = 0;
    unsigned char i,j = 0;
    //unsigned char num = 0;
    unsigned char framelength = 0;
    unsigned char index_temp = 0;
    unsigned char debug_buff[40] = {0};
    
    unsigned char test_data = 0;
  
    //接收的数据长度保证不越界
    get_wifi_data_num = Wifi_Uart_ReceiveOnePackage(wifi_data_buff + wifi_buff_index,(WIFI_DATA_BUFF_SIZE - wifi_buff_index));
    
    if(get_wifi_data_num > 0)
    {
//        mymemset(debug_buff,0,100);
//        sprintf(debug_buff,"get data:%x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x\n",(unsigned int)wifi_data_buff[0],(unsigned int)wifi_data_buff[1],(unsigned int)wifi_data_buff[2],(unsigned int)wifi_data_buff[3],
//                   (unsigned int)wifi_data_buff[4],(unsigned int)wifi_data_buff[5],(unsigned int)wifi_data_buff[6],(unsigned int)wifi_data_buff[7],(unsigned int)wifi_data_buff[8],(unsigned int)wifi_data_buff[9],
//                   (unsigned int)wifi_data_buff[10],(unsigned int)wifi_data_buff[11],(unsigned int)wifi_data_buff[12],(unsigned int)wifi_data_buff[13],(unsigned int)wifi_data_buff[14],(unsigned int)wifi_data_buff[15],
//                   (unsigned int)wifi_data_buff[16],(unsigned int)wifi_data_buff[17],(unsigned int)wifi_data_buff[18],(unsigned int)wifi_data_buff[19]);
//        DEBUG_Uart_Sendbytes(debug_buff,mystrlen(debug_buff));
    }

    
    if(get_wifi_data_num == 0)
    {
        return;
    }
    
    wifi_buff_index += get_wifi_data_num;
    index_temp = wifi_buff_index;
    
    mymemset(debug_buff,0,sizeof(debug_buff));
    sprintf(debug_buff,"get data:");
    DEBUG_Uart_Sendbytes(debug_buff,strlen(debug_buff));
    
    
    for(i = 0;i < wifi_buff_index;i++)
    {
        mymemset(debug_buff,0,sizeof(debug_buff));
        test_data = wifi_data_buff[i];
        sprintf(debug_buff,"%x ",(unsigned int)test_data);
        DEBUG_Uart_Sendbytes(debug_buff,strlen(debug_buff));
    }
    
    mymemset(debug_buff,0,sizeof(debug_buff));
    sprintf(debug_buff,"\r\n");
    DEBUG_Uart_Sendbytes(debug_buff,strlen(debug_buff));
    
    for(i = 0;i < wifi_buff_index;i++)
    {
        if(wifi_data_buff[i] == 0x2A && i != 0)
        {
                   
            framelength = wifi_data_buff[i-1];
          
//            mymemset(debug_buff,0,100);
//            sprintf(debug_buff,"get data:");
//            for(num = 0;num < framelength + 1;num++)
//            {
//                sprintf(debug_buff + 9 + num * 3,"%x ",(unsigned int)wifi_data_buff[i-1 + num]);
//            }
//            sprintf(debug_buff + 9 + num * 3 + 1,"\n");
//            DEBUG_Uart_Sendbytes(debug_buff,mystrlen(debug_buff));

            //正常情况下处理数据帧
            if( (i + framelength) <= wifi_buff_index)
            //if( i < wifi_buff_index)
            {
              
               
                //正确数据帧，而且数据到最后了，后面没有有效数据了
                //deal with data
               //do something
                if(wifi_data_buff[i + framelength - 1] == 0x23)           
                {                  
                    deal_frame_data(wifi_data_buff + i -1);
                  
                    //防止多帧数据的可能
                    i += framelength;
                    if(i < wifi_buff_index)
                    {
                        //后面还有数据，跳出此次循环，继续处理数据
                        continue;
                        
                    }
                    else if(i == wifi_buff_index)
                    {
                        //处理完数据了
                        mymemset(wifi_data_buff,0,wifi_buff_index);
                        wifi_buff_index = 0;                    
                    }   
                    else
                    {
                        //数据没有接收完,把数据搬到最前面，防止溢出
                        //数据没有接收完，而且有效数据不在 wifi_data_buff 数据的起始位置,把数据搬运到数组起始位置，防止数据接收数据满
                        for(j = 0;j < (wifi_buff_index - i + 1);j++)
                        {
                            wifi_data_buff[j] = wifi_data_buff[i - 1 + j];
                            wifi_buff_index = wifi_buff_index - i + 1;
                        
                        }
                        mymemset(wifi_data_buff + wifi_buff_index,0,index_temp - wifi_buff_index);
                        
                    }                      
                }
                else
                {
                             
                             
                }

            }
            
        }
        
        //如果接受buff满，而且没有正确的数据帧，则buff清空，wifi_buff_index清零，否则因为buff满了就不再接受数据了。重置buff后重新接收。
        if(i >= WIFI_DATA_BUFF_SIZE)       
        {
            mymemset(wifi_data_buff,0,wifi_buff_index);
            wifi_buff_index = 0;   
        }
    }
    

}


void deal_frame_data(unsigned char *framebuffer)
{
    unsigned char framelength = 0;
    //unsigned char debug_send_buff[30] = {0};
  
    framelength = framebuffer[0];
    if(framebuffer[1] == 0x2A && framebuffer[framelength] == 0x23)
    {
        if(framebuffer[3] == 0x41)
        {
            f_0x41_data();
          
//            mymemset(debug_send_buff,0,sizeof(debug_send_buff));
//            sprintf(debug_send_buff,"get 0x41 data\n");
//            DEBUG_Uart_Sendbytes(debug_send_buff,mystrlen(debug_send_buff));
        }
        else if(framebuffer[3] == 0x44)
        {
            f_0x44_data();
        }        
        else if(framebuffer[3] == 0x45)
        {           
//            mymemset(debug_send_buff,0,sizeof(debug_send_buff));
//            sprintf(debug_send_buff,"get 0x45 data\n");
//            DEBUG_Uart_Sendbytes(debug_send_buff,mystrlen(debug_send_buff));
          
            f_0x45_data(framebuffer);
        }

        else if(framebuffer[3] == 0x49)
        {
//            mymemset(debug_send_buff,0,30);
//            sprintf(debug_send_buff,"get 0x49 data\n");
//            DEBUG_Uart_Sendbytes(debug_send_buff,mystrlen(debug_send_buff));
          
            f_0x49_data(framebuffer);
        }
    }      

}

#define SENSOR_NUM      4
#define BUFF_SIZE_0x41  (8 + SENSOR_NUM * 5)
//按4个指标的数值发送 PM2.5  PM1.0 PM10和HCHO，以后换传感器后就不用再修改程序
void f_0x41_data(void)
{
    unsigned char sendbuff[BUFF_SIZE_0x41] = {(BUFF_SIZE_0x41 - 1),0x2A,0x01,0x41,0x04};
    unsigned char i,j = 0;
    unsigned char sensor_key = 0;
    
//    sendbuff[0] = BUFF_SIZE_0x41 - 1;
//    sendbuff[1] = 0x2A;
    sendbuff[2] = device_id;
//    sendbuff[3] = 0x41;
//    sendbuff[4] = 0x04;
    
    for(i = 0;i < SENSOR_NUM;i++)
    {
        if(i == 0)
        {
            //cfloat.f = PM25_value;
            cfloat.f = display_pm_value;
            sensor_key = 'P';
        }
        else if(i == 1)
        {
            cfloat.f = PM1_value;
            sensor_key = 'Z';
        }
        else if(i == 2)
        {
            cfloat.f = PM10_value;
            sensor_key = 'O';
        }
        else if(i == 3)
        {
            cfloat.f = HCHO_value;
            sensor_key = 'J';
        }
        
        sendbuff[5 + i * 5] = sensor_key;
        sendbuff[6 + i * 5] = cfloat.b[0];
        sendbuff[7 + i * 5] = cfloat.b[1];
        sendbuff[8 + i * 5] = cfloat.b[2];
        sendbuff[9 + i * 5] = cfloat.b[3];               
    }
    
    sendbuff[BUFF_SIZE_0x41 - 3] = 0x00;
    sendbuff[BUFF_SIZE_0x41 - 2] = 0x00;
    sendbuff[BUFF_SIZE_0x41 - 1] = 0x23;
    
    Wifi_Uart_Sendbytes(sendbuff,BUFF_SIZE_0x41);    
}

void f_0x44_data(void)
{
    unsigned char sendbuff[10] = {0x09,0x2A,0x00,0x44,0x00,0x00,0x01,0x00,0x00,0x23};
    sendbuff[6] = device_id;
    Wifi_Uart_Sendbytes(sendbuff,10);  
}


#define BUFF_SIZE_AF  18
void f_0x45_data(unsigned char *framebuff)
{
    unsigned char child_cmd = 0;
    //unsigned char buff_0xAF[BUFF_SIZE_AF] = {0};
    unsigned char buff_0xAF[BUFF_SIZE_AF] = {(BUFF_SIZE_AF - 1),0x2A,0x01,0x45,0xAF};
    //unsigned char debug_buff[30] = {0};
  
    child_cmd = framebuff[4];

    if(child_cmd <= 0x0A)
    {
        switch (child_cmd)
        {
          case 0x00:
            if(sys_mode == RUNNING)
            {
                sys_stop();
            }
            break;
          case 0x01:
          case 0x02:
          case 0x03:
          case 0x04:
            if(sys_mode == STANDBY)
            {
                sys_start();
                break;
            }
            Set_DC_Motor_Speed(child_cmd);
            TM1620_LED_Control(child_cmd + 1,LED_ON);
            break;
          case 0x05:
            UV_Off();
            break;
          case 0x06:            
            UV_On();
            break;  
          case 0x07:
            ION_Off();
            break;
          case 0x08:
            ION_On();            
            break;
          case 0x09:
            //关闭仓门
            break;
          case 0x0A:
            //打开仓门
            if(Is_Door_Open == 0)
            {
                Door_Open();
            }           
            break;

          default:
            break;                       
        }
        Wifi_Uart_Sendbytes(framebuff,framebuff[0] + 1);          
                
    }
    else if(child_cmd >= 0x10 && child_cmd <= 0x13)
    {
        switch (child_cmd)
        {
            case 0x10:
            if(sys_mode == RUNNING)
            {
                sys_stop();
            }            
            break;
          case 0x11:
            if(sys_mode == STANDBY)
            {
                sys_start();
            }           
            break;
          case 0x12:
            //设置手动模式
            if(run_mode == 1)
            {
                stop_sys_smart_mode();
            }
             
            break;
          case 0x13:
            //设置自动模式
            if(run_mode == 0)
            {
                set_sys_to_smart_mode();
            }
            break; 
          default:
            break;            
        }
        Wifi_Uart_Sendbytes(framebuff,framebuff[0] + 1);    
    }
    else if(child_cmd == 0xAF )
    {
//        buff_0xAF[0] = BUFF_SIZE_AF - 1;
//        buff_0xAF[1] = 0x2A;
        buff_0xAF[2] = device_id;
//        buff_0xAF[3] = 0x45;
//        buff_0xAF[4] = 0xAF;
        buff_0xAF[5] = sys_mode;
        buff_0xAF[6] = run_mode;
        buff_0xAF[7] = speed_dang;
        buff_0xAF[8] = (unsigned char)IsUVOn;
        buff_0xAF[9] = (unsigned char)Is_ION_On;
        buff_0xAF[10] = user_timer_info.timer_state;
        buff_0xAF[11] = (unsigned char)(user_timer_info.set_time / 60);
        buff_0xAF[12] = (unsigned char)(user_timer_info.set_time % 60);
        buff_0xAF[13] = (unsigned char)(user_timer_info.left_time / 60);
        buff_0xAF[14] = (unsigned char)(user_timer_info.left_time % 60);
        buff_0xAF[15] = 0x00;
        buff_0xAF[16] = 0x00;
        buff_0xAF[17] = 0x23;
        Wifi_Uart_Sendbytes(buff_0xAF,BUFF_SIZE_AF);
    }

}


void f_0x49_data(unsigned char *framebuff)
{
    unsigned char send_num = 0;
    unsigned long add_time = 0;
    unsigned long temptime = 0;
    
    if(framebuff[4] == 0x03)
    {
        //wifi_earse_easylink_cmd();
    }
    else if(framebuff[4] == 0x05)
    {
        //设置定时
        f_0x49_05_data(framebuff);
    }
    else if(framebuff[4] == 0x07)
    {
        Buzzer_Get_Charge();
    }
    else if(framebuff[4] == 0x08)
    {
        //设备自动检测
        if(framebuff[5] == 0x01)
        {
            if(is_sys_manual_check == 0)
            {
                //设备自动检测开启
                start_sys_auto_check();
            }
        }
        else if(framebuff[5] == 0x02)
        {
            if(is_sys_auto_check == 1)
            {
                //设备自动检测关闭
                stop_sys_auto_check();
            }           
        }        
        else if(framebuff[5] == 0x03)
        {
            if(is_sys_auto_check == 0)
            {
                //设备手动检测开启
                start_sys_manual_check();
            }           
        }
        else if(framebuff[5] == 0x04)
        {
            if(is_sys_manual_check == 1)
            {
                //设备手动检测关闭
                stop_sys_manual_check();
            }          
        }
    }
    
}

void f_0x49_05_data(unsigned char *framebuff)
{
    unsigned int temp_time = 0;
    unsigned char debug_buff[30] = {0}; 
  
    if(framebuff == NULL)
    {
        return;
    }
    
    if(framebuff[5] == 0)
    {
        stop_user_timer();
    }
    else if(framebuff[5] == 1)
    {
//        user_timer_info.user_timer_start = 1;
//        user_timer_info.timer_state = 1;
//        user_timer_info.set_time = (unsigned int)framebuff[6] * 60 + framebuff[7] ;
//        user_timer_info.left_time = user_timer_info.set_time;
      
        temp_time = user_timer_info.set_time = (unsigned int)framebuff[6] * 60 + framebuff[7] ;
        if(temp_time != 120 && temp_time != 240)
        {
            mymemset(debug_buff,0,sizeof(debug_buff));
            sprintf(debug_buff,"get user time error:%d\r\n",(unsigned int)temp_time);
            DEBUG_Uart_Sendbytes(debug_buff,strlen(debug_buff)); 
            return;
        }
      
        if(temp_time == 120)
        {
            user_timer_type = USER_TIMER_2H;
        }
        else if(temp_time == 240)
        {
            user_timer_type = USER_TIMER_4H;
        }
     
        user_timer_confirm(framebuff);
        
        set_user_timer(user_timer_type);
        
        Buzzer_Get_Charge();
      
        mymemset(debug_buff,0,sizeof(debug_buff));
        sprintf(debug_buff,"user_timer:%d\r\n",(unsigned int)user_timer_info.set_time);
        DEBUG_Uart_Sendbytes(debug_buff,strlen(debug_buff)); 
    }
}




//WIFI模块控制设备自检
//void f_0x49_07_data(unsigned char *framebuff)
//{

//}





void wifi_earse_easylink_cmd(void)
{
    unsigned char sendbuff[8] = {0x07,0x2A,0x01,0x49,0x03,0x00,0x00,0x23};
    
//    sendbuff[0] = 0x07;
//    sendbuff[1] = 0x2A;
    sendbuff[2] = device_id;
//    sendbuff[3] = 0x49;
//    sendbuff[4] = 0x03;
//    sendbuff[5] = 0x00;
//    sendbuff[6] = 0x00;
//    sendbuff[7] = 0x23;
    
    Wifi_Uart_Sendbytes(sendbuff,sizeof(sendbuff));  
}

void user_timer_confirm(const unsigned char *framebuff)
{
    unsigned char sendbuff[11] = {0x0A, 0x2A, 0x01, 0x49, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x23};
    
    sendbuff[2] = device_id;
    sendbuff[5] = framebuff[5];
    sendbuff[6] = framebuff[6];
    sendbuff[7] = framebuff[7];
    
    Wifi_Uart_Sendbytes(sendbuff,sizeof(sendbuff));  
}


void sys_check_auto_result_upload(void)
{
    unsigned char sendbuff[12] = {0x0B,0x2A,0x01,0x49,0x08,0x01,0x00,0x00,0x00,0x00,0x00,0x23};
        
    sendbuff[2] = device_id;
    sendbuff[6] = sys_check_info.status;
    sendbuff[7] = (unsigned char)((unsigned int)PM25_value / 256);
    sendbuff[8] = (unsigned char)((unsigned int)PM25_value % 256);;
    
    //Wifi_Uart_Sendbytes(sendbuff,12); 
    Wifi_Uart_Sendbytes(sendbuff,sizeof(sendbuff));      

}


void sys_check_manual_result_upload(void)
{
    unsigned char sendbuff[10] = {0x09,0x2A,0x01,0x49,0x08,0x03,0x00,0x00,0x00,0x23};
        
    sendbuff[2] = device_id;
    sendbuff[6] = sys_check_info.touch_key_check;
    
    Wifi_Uart_Sendbytes(sendbuff,sizeof(sendbuff));  
    //Wifi_Uart_Sendbytes(sendbuff,10); 

}


