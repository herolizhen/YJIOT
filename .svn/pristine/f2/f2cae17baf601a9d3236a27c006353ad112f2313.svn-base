#include <stdio.h>
#include <string.h>
#include "charge.h"
#include "global.h"
#include "timer.h"
#include "wifi_uart.h"
#include "common.h"
#include "debug_uart.h"
#include "touch_key.h"
#include "sys_run.h"
#include "EEPROM.h"
#include "M26.h"

/*flash中存储方式大端法
charge_info.lefttime.l_time = 2，则 charge_info.lefttime.c_time[0] = 0,charge_info.lefttime.c_time[1] = 0,
charge_info.lefttime.c_time[2] = 0,charge_info.lefttime.c_time[3] = 2

*/

Charge_Typedef charge_info;

extern M26_Cmd_Typedef m26_cmd_info;

#define CHARGE_INFO_LENGTH   5


void charge_init(void)
{
    //unsigned char i = 0; 
    unsigned char readbuff[10] ={0};
    unsigned int eeprom_addr = 0;
    
    eeprom_addr = EEPROM_START_ADDR | 0x00;
  
    mymemset(readbuff,0,sizeof(readbuff));
    EEPROM_Read_Bytes(readbuff,eeprom_addr,CHARGE_INFO_LENGTH);
  
//    mymemset(m26_cmd_info.sendtring,0,sizeof(m26_cmd_info.sendtring));
//    sprintf(m26_cmd_info.sendtring,"read data:%d %d %d %d %d\r\n",(unsigned int)m26_cmd_info.cmd[0],(unsigned int)m26_cmd_info.cmd[1],
//             (unsigned int)m26_cmd_info.cmd[2],(unsigned int)m26_cmd_info.cmd[3],(unsigned int)m26_cmd_info.cmd[4]);
//    DEBUG_Uart_Sendbytes(m26_cmd_info.sendtring,strlen(m26_cmd_info.sendtring));
    
//    mymemset(m26_cmd_info.sendtring,0,sizeof(m26_cmd_info.sendtring));
//    sprintf(m26_cmd_info.sendtring,"read data:%x %x %x %x %x\r\n",(unsigned int)readbuff[0],(unsigned int)readbuff[1],
//             (unsigned int)readbuff[2],(unsigned int)readbuff[3],(unsigned int)readbuff[4]);
//    DEBUG_Uart_Sendbytes(m26_cmd_info.sendtring,strlen(m26_cmd_info.sendtring));
    

    
    if(readbuff[0] > 1)
    {
        //EEPROM_Page_Erase(EEPROM_START_ADDR);
        //mymemset(readbuff,0,sizeof(readbuff));
        //EEPROM_Read_Bytes(readbuff,eeprom_addr,CHARGE_INFO_LENGTH);
      
//     mymemset(m26_cmd_info.sendtring,0,sizeof(m26_cmd_info.sendtring));
//    sprintf(m26_cmd_info.sendtring,"read data:%x %x %x %x %x\r\n",(unsigned int)readbuff[0],(unsigned int)readbuff[1],
//             (unsigned int)readbuff[2],(unsigned int)readbuff[3],(unsigned int)readbuff[4]);
//    DEBUG_Uart_Sendbytes(m26_cmd_info.sendtring,strlen(m26_cmd_info.sendtring));
    }
      
    if(readbuff[0] == 0xFF)
    {
      
        mymemset(m26_cmd_info.sendtring,0,sizeof(m26_cmd_info.sendtring));
        sprintf(m26_cmd_info.sendtring,"way0\r\n");
        DEBUG_Uart_Sendbytes(m26_cmd_info.sendtring,strlen(m26_cmd_info.sendtring));
        //此种情况是第一次上电，设置为默认形式的家用机
        //防止该page有的数据不是0xFF，所以执行一次擦除操作
        EEPROM_Page_Erase(EEPROM_START_ADDR);
          
        mymemset(readbuff,0,sizeof(readbuff));
        EEPROM_Write_Bytes(readbuff,EEPROM_START_ADDR,CHARGE_INFO_LENGTH);
        //EEPROM_Write_Bytes(readbuff,EEPROM_START_ADDR,5);
        //EEPROM_Byte_Program(EEPROM_START_ADDR,0);
      
    mymemset(readbuff,3,sizeof(readbuff));
    EEPROM_Read_Bytes(readbuff,(unsigned int)(EEPROM_START_ADDR),10);
//    readbuff[0] = EEPROM_Byte_Read(EEPROM_START_ADDR);
//    readbuff[1] = EEPROM_Byte_Read(EEPROM_START_ADDR + 1);
    mymemset(m26_cmd_info.sendtring,0,sizeof(m26_cmd_info.sendtring));
    sprintf(m26_cmd_info.sendtring,"read data:%x %x %x %x %x %x\r\n",(unsigned int)readbuff[0],(unsigned int)readbuff[1],
             (unsigned int)readbuff[2],(unsigned int)readbuff[3],(unsigned int)readbuff[4],(unsigned int)readbuff[5]);
    DEBUG_Uart_Sendbytes(m26_cmd_info.sendtring,strlen(m26_cmd_info.sendtring));
          
        charge_info.IsChargeType = 0;
        charge_info.lefttime.l_time = 0;
        charge_info.eeprom_next_write_addr = eeprom_addr + CHARGE_INFO_LENGTH;
          
        goto exit;
           
    }
    else
    {
        eeprom_addr = eeprom_addr + CHARGE_INFO_LENGTH;
      
        do{
              mymemset(m26_cmd_info.sendtring,0,sizeof(m26_cmd_info.sendtring));
              sprintf(m26_cmd_info.sendtring,"way3\r\n");
              DEBUG_Uart_Sendbytes(m26_cmd_info.sendtring,strlen(m26_cmd_info.sendtring));
              //每次读取2组数据，10个字节
              mymemset(readbuff,0,sizeof(readbuff));
              //EEPROM_Read_Bytes(readbuff,eeprom_addr,(CHARGE_INFO_LENGTH * 2));
              EEPROM_Read_Bytes(readbuff,eeprom_addr,10);
      
              if(readbuff[0] == 0xFF || readbuff[5] == 0xFF)
              {               
                  if(readbuff[0] == 0xFF)
                  {
                      mymemset(readbuff,0,sizeof(readbuff));
                      EEPROM_Read_Bytes(readbuff,(eeprom_addr - CHARGE_INFO_LENGTH),CHARGE_INFO_LENGTH);  
          
                      charge_info.eeprom_next_write_addr = eeprom_addr;
                    
                      mymemset(m26_cmd_info.sendtring,0,sizeof(m26_cmd_info.sendtring));
                      sprintf(m26_cmd_info.sendtring,"way1\r\n");
                      DEBUG_Uart_Sendbytes(m26_cmd_info.sendtring,strlen(m26_cmd_info.sendtring));
                  }
                  else
                  {
                      charge_info.eeprom_next_write_addr = eeprom_addr + CHARGE_INFO_LENGTH;
                    
                      mymemset(m26_cmd_info.sendtring,0,sizeof(m26_cmd_info.sendtring));
                      sprintf(m26_cmd_info.sendtring,"way2\r\n");
                      DEBUG_Uart_Sendbytes(m26_cmd_info.sendtring,strlen(m26_cmd_info.sendtring));
                  }                    
         
                  charge_info.IsChargeType = readbuff[0];
                  charge_info.lefttime.c_time[0] = readbuff[4];
                  charge_info.lefttime.c_time[1] = readbuff[3];
                  charge_info.lefttime.c_time[2] = readbuff[2];
                  charge_info.lefttime.c_time[3] = readbuff[1];
                            
                  goto exit;         
              }
              
              if(eeprom_addr < (EEPROM_END_ADDR - 9))
              {
                  eeprom_addr += (CHARGE_INFO_LENGTH * 2);
              }
              else if(eeprom_addr == (EEPROM_END_ADDR - 9))              
              {
                  //此种情况是有效数据是最后一组数据
                  charge_info.IsChargeType = readbuff[5];
                  charge_info.lefttime.c_time[0] = readbuff[9];
                  charge_info.lefttime.c_time[1] = readbuff[8];
                  charge_info.lefttime.c_time[2] = readbuff[7];
                  charge_info.lefttime.c_time[3] = readbuff[6];
                  //如果在执行flash写操作时，如果 charge_info.eeprom_write_addr == EEPROM_START_ADDR时，该页被写满了，则需要先擦除，然后再从起始地址写
                  charge_info.eeprom_next_write_addr = EEPROM_START_ADDR;
                
                  mymemset(m26_cmd_info.sendtring,0,sizeof(m26_cmd_info.sendtring));
                  sprintf(m26_cmd_info.sendtring,"page full,re-write\r\n");
                  DEBUG_Uart_Sendbytes(m26_cmd_info.sendtring,strlen(m26_cmd_info.sendtring));
                
                  goto exit;
              }
              else
              {
                  //肯定出错了
                  mymemset(m26_cmd_info.sendtring,0,sizeof(m26_cmd_info.sendtring));
                  sprintf(m26_cmd_info.sendtring,"eeprom addr out of range\r\n");
                  DEBUG_Uart_Sendbytes(m26_cmd_info.sendtring,strlen(m26_cmd_info.sendtring));
                
                  charge_info.IsChargeType = 1;
                  charge_info.lefttime.l_time = 0;
                
                  charge_info.eeprom_next_write_addr = EEPROM_START_ADDR;
     
                  goto exit;
              }             
    
        }while(eeprom_addr < EEPROM_END_ADDR);    
    }
exit:

    charge_info.next_1min_time = get_sys_stime() + (MIN_TO_S | 0x00);
    
    mymemset(m26_cmd_info.sendtring,0,sizeof(m26_cmd_info.sendtring));
    sprintf(m26_cmd_info.sendtring,"find addr:%x\r\n",(unsigned int)charge_info.eeprom_next_write_addr);
    DEBUG_Uart_Sendbytes(m26_cmd_info.sendtring,strlen(m26_cmd_info.sendtring));
    
    mymemset(readbuff,0,sizeof(readbuff));
    EEPROM_Read_Bytes(readbuff,(unsigned int)(charge_info.eeprom_next_write_addr-5),10);
    mymemset(m26_cmd_info.sendtring,0,sizeof(m26_cmd_info.sendtring));
    sprintf(m26_cmd_info.sendtring,"read data:%x %x %x %x %x %x\r\n",(unsigned int)readbuff[0],(unsigned int)readbuff[1],
             (unsigned int)readbuff[2],(unsigned int)readbuff[3],(unsigned int)readbuff[4],(unsigned int)readbuff[5]);
    DEBUG_Uart_Sendbytes(m26_cmd_info.sendtring,strlen(m26_cmd_info.sendtring));
    
    mymemset(m26_cmd_info.sendtring,0,sizeof(m26_cmd_info.sendtring));
    sprintf(m26_cmd_info.sendtring,"type:%d,time:%d\r\n",(unsigned int)charge_info.IsChargeType,(unsigned int)charge_info.lefttime.l_time);
    DEBUG_Uart_Sendbytes(m26_cmd_info.sendtring,strlen(m26_cmd_info.sendtring));
    
    
}


void charge_lefttime_flash_write(void)
{
    unsigned char i = 0;
  
    if(charge_info.eeprom_next_write_addr == EEPROM_START_ADDR)
    {
        EEPROM_Page_Erase(EEPROM_START_ADDR);
    }
    
    for(i = 0;i < CHARGE_INFO_LENGTH;i++)
    {
        if(i == 0)
        {
            EEPROM_Byte_Program(charge_info.eeprom_next_write_addr,(unsigned char)charge_info.IsChargeType);
        }
        else
        {
            EEPROM_Byte_Program(charge_info.eeprom_next_write_addr + i,charge_info.lefttime.c_time[4-i]);
        }
    }
    
    if(charge_info.eeprom_next_write_addr > (EEPROM_END_ADDR - CHARGE_INFO_LENGTH))
    {
        charge_info.eeprom_next_write_addr = EEPROM_START_ADDR;
    }
    else
    {
        charge_info.eeprom_next_write_addr += CHARGE_INFO_LENGTH;
    }
}


void charge_lefttime_count(void)
{
    unsigned char readbuff[5] = {0};
    if(charge_info.IsChargeType == 0)
    {
        return;
    }
    
    if(charge_info.lefttime.l_time == 0)
    {
        return;
    }
    
    nowtime_s = get_sys_stime();   
    //防止时间溢出，正常情况下此处不会溢出
    if(nowtime_s < (MIN_TO_S | 0x00) && charge_info.next_1min_time >= 0xF0000000)
    {
        charge_info.next_1min_time = nowtime_s + (MIN_TO_S | 0x00);
    }
    if(nowtime_s >= charge_info.next_1min_time)
    {
        charge_info.lefttime.l_time -= 1;
        charge_info.next_1min_time += (MIN_TO_S | 0x00);
      
        if(charge_info.lefttime.l_time == 0)
        {
            charge_lefttime_flash_write();
        }
        
        mymemset(m26_cmd_info.sendtring,0,sizeof(m26_cmd_info.sendtring));
        sprintf(m26_cmd_info.sendtring,"lefttime:%d\r\n",(unsigned int)(charge_info.lefttime.l_time));
        DEBUG_Uart_Sendbytes(m26_cmd_info.sendtring,strlen(m26_cmd_info.sendtring));
      
//        charge_lefttime_flash_write();
//        mymemset(readbuff,0,sizeof(readbuff));
//        EEPROM_Read_Bytes(readbuff,(unsigned int)(charge_info.eeprom_next_write_addr-5),5);
//        mymemset(m26_cmd_info.sendtring,0,sizeof(m26_cmd_info.sendtring));
//        sprintf(m26_cmd_info.sendtring,"read data:%x %x %x %x %x\r\n",(unsigned int)readbuff[0],(unsigned int)readbuff[1],
//             (unsigned int)readbuff[2],(unsigned int)readbuff[3],(unsigned int)readbuff[4]);
//        DEBUG_Uart_Sendbytes(m26_cmd_info.sendtring,strlen(m26_cmd_info.sendtring));
    }    
}










