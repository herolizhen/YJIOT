#include "fog_v2_include.h"
#include "mico.h"
#include "user_charge.h"
#include "mico_platform.h"
#include "spi_flash.h"
#include "user_device_control.h"

#define app_log(M, ...)                     custom_log("FOG_V2", M, ##__VA_ARGS__)


extern device_status_t device_status;


user_charge_t user_charge;

extern mico_mutex_t stdio_tx_mutex;

sflash_handle_t mysflash_handle = {0x0, 0x0, SFLASH_WRITE_NOT_ALLOWED};



const mico_logic_partition_t user_partitions[] =
{
  [0] =
  {
    .partition_owner           = MICO_FLASH_SPI,
    .partition_description     = "USERDATA",
    .partition_start_addr      = 0xC0000,
    .partition_length          = 0x400, //64K bytes
    .partition_options         = PAR_OPT_READ_EN | PAR_OPT_WRITE_EN,
  }



};


extern platform_flash_driver_t platform_flash_drivers[MICO_FLASH_MAX];
extern const platform_flash_t           platform_flash_peripherals[];


static void my_printf_array(char *buff_name,unsigned char *buff,unsigned char length)
{
  unsigned char i = 0;
  
  mico_rtos_lock_mutex( &stdio_tx_mutex );
  printf("%s:",buff_name);
  for(i = 0;i < length;i++)
  {
    printf("%x ",buff[i]);
    if(i % 8 == 7)
    {
      printf("  ");
    }
  }
  printf("\n");
  mico_rtos_unlock_mutex( &stdio_tx_mutex );  
  
}



OSStatus charge_flash_erase(uint32_t start_addr, uint32_t end_addr )
{
  OSStatus err = kNoErr;
  mico_rtos_lock_mutex( &platform_flash_drivers[ user_partitions[0].partition_owner ].flash_mutex );
  err = platform_flash_erase( &platform_flash_peripherals[ user_partitions[0].partition_owner ], start_addr, end_addr );
  mico_rtos_unlock_mutex( &platform_flash_drivers[ user_partitions[0].partition_owner ].flash_mutex );
  return err;
}



OSStatus charge_flash_write( uint32_t start_address, uint8_t* data ,uint32_t length )
{
  OSStatus err = kNoErr;
  uint32_t start_addr = 0; 
  
  start_addr = start_address;
  mico_rtos_lock_mutex( &platform_flash_drivers[ user_partitions[0].partition_owner ].flash_mutex );
  err = platform_flash_write( &platform_flash_peripherals[ user_partitions[0].partition_owner ], &start_addr, data, length ); 
  mico_rtos_unlock_mutex( &platform_flash_drivers[ user_partitions[0].partition_owner ].flash_mutex );
  if(err != 0)
  {
    err = FLASH_WRITE_ERR;
    goto exit;
  }
  
exit:
  return err;
}


OSStatus charge_flash_read( uint32_t start_address, uint8_t* data ,uint32_t length )
{
  OSStatus err = kNoErr;
  uint32_t start_addr = 0;
  start_addr = start_address;
  mico_rtos_lock_mutex( &platform_flash_drivers[ user_partitions[0].partition_owner ].flash_mutex );
  err = platform_flash_read( &platform_flash_peripherals[ user_partitions[0].partition_owner ], &start_addr, data, length ); 
  mico_rtos_unlock_mutex( &platform_flash_drivers[ user_partitions[0].partition_owner ].flash_mutex );
  if(err != 0)
  {
    err = FLASH_READ_ERR;
  }
  return err;
}

OSStatus charge_flash_init(void)
{
  OSStatus err = kNoErr;
  
  if(platform_flash_drivers[ user_partitions[0].partition_owner ].initialized == false)
  {
    mico_rtos_init_mutex( &platform_flash_drivers[ user_partitions[0].partition_owner ].flash_mutex );
    mico_rtos_lock_mutex( &platform_flash_drivers[ user_partitions[0].partition_owner ].flash_mutex );  
    err = platform_flash_init( &platform_flash_peripherals[ user_partitions[0].partition_owner ] );
    platform_flash_drivers[ user_partitions[0].partition_owner ].peripheral = (platform_flash_t *)&platform_flash_peripherals[ user_partitions[0].partition_owner ];
    platform_flash_drivers[ user_partitions[0].partition_owner ].initialized = true;
    mico_rtos_unlock_mutex( &platform_flash_drivers[ user_partitions[0].partition_owner ].flash_mutex );  
  }

  
  
  return err;
}


//读取用于保存 SAVE_TIME_INTERVAL 分钟更新一次的left time
OSStatus get_lefttime_register_data(void)
{
  unsigned char buff[LEFT_TIME_MAX_OFFSET] = {0};
  unsigned char offset = 0;
  OSStatus err = kNoErr;
  unsigned char i,j = 0;
  union{ 
    unsigned char b[4];
    unsigned long l; 
  }cl;
  
  memset(buff,0,sizeof(buff));
  err = charge_flash_read(LEFT_TIME_ADDR_BASE,buff,sizeof(buff));
  if(err != kNoErr)
  {
    user_charge_log("read flash letftime address failed");
    goto exit;
  }
  for(j = 0;j < sizeof(buff);j += 10)
  {
    if((buff[j + 0] & buff[j + 1] & buff[j + 2] & buff[j + 3]) == 0xFF)
    {
      if(j == 0)
      {
        //只要初始化过以后，该扇区的前10个字节都不会是0xFF,有可能是flash坏了，或者是在刚擦除玩该扇区时断电了
        user_charge_log("left time sector first 8byte all 0xFF");
        err = -1;
        goto exit;
      }
      else if(j < (LEFT_TIME_MAX_OFFSET - 10))
      {
        if((buff[j + 10] & buff[j + 11] & buff[j + 12] & buff[j + 13]) == 0xFF )
        {
          //正常情况
          user_charge_log("find lefttime sector offset = %d",j);        
          break;
        }
        else
        {
          continue;
        }
      }
      else if(j == (LEFT_TIME_MAX_OFFSET - 10))
      {
        break;
      }
    }
  }
  
  
  if(j == 10)
  {
    offset = j - 10;
    user_charge.lefttime.in_sector_offset = j;  
    user_charge.lefttime.IsChargeType = buff[offset];
    user_charge.lefttime.IsHaveTime = buff[offset + 1];
    for(i = 0;i < 4;i++)
    {
      cl.b[i] = buff[offset + 2 + i];
    }
    user_charge.lefttime.left_time = cl.l;
    
    for(i = 0;i < 4;i++)
    {
      cl.b[i] = buff[offset + 6 + i];
    }
    user_charge.lefttime.flash_write_times = cl.l;
  }
  else if(j <= LEFT_TIME_MAX_OFFSET)
  {
    //读取前边倒数第二组的数据，防止前边倒数第一组数据没有写完就断电了
    if(buff[j - 5] == 0xFF || buff[j -1] == 0xFF)
    {
      //此种情况应该是找到的offset前一组数据出问题了，读取倒数第二组的数据
      offset = j - 20;
    }
    else
    {
      offset = j - 10;
    }
    user_charge.lefttime.in_sector_offset = j;  
    user_charge.lefttime.IsChargeType = buff[offset];
    user_charge.lefttime.IsHaveTime = buff[offset + 1];
    for(i = 0;i < 4;i++)
    {
      cl.b[i] = buff[offset + 2 + i];
    }
    user_charge.lefttime.left_time = cl.l;
    for(i = 0;i < 4;i++)
    {
      cl.b[i] = buff[offset + 6 + i];
    }
    user_charge.lefttime.flash_write_times = cl.l;
 

  }
   
  
  
  
  
  


exit: 
//  if(err != kNoErr)
//  {
//    user_charge_log("get_lefttime_register_data failed");
//  }
  return err;
}



//读取保存计数扇区地址的寄存器内容
OSStatus get_record_address_register_data(void)
{
  unsigned char buff[8] = {0};
  OSStatus err = kNoErr;
  unsigned char i = 0;
  union{ 
    unsigned char b[4];
    unsigned long l; 
  }cl;
  
  memset(buff,0,sizeof(buff));
  err = charge_flash_read(RECORD_ADDR_BASE,buff,sizeof(buff));
  if(err != kNoErr)
  {
    user_charge_log("read flash record address failed");
    goto exit;
  }
  for(i = 0;i < 4;i++)
  {
    cl.b[i] = buff[i];
  }
  user_charge.count.count_sector_addr_base = cl.l;
    
  for(i = 0;i < 4;i++)
  {
    cl.b[i] = buff[i+4];
  }
  user_charge.count.flash_write_times = cl.l;
  

exit: 
//  if(err != kNoErr)
//  {
//    user_charge_log("get_record_address_register_data failed");
//  }
  return err;
}




//修改从0xC0000-0xC0007保存的计费信息，系统在正常计费模式下 SAVE_TIME_INTERVAL 分钟修改一次
OSStatus updata_charge_lefttime_register(void)
{
  OSStatus err = kNoErr;
  unsigned char i = 0;
  unsigned char buff[10] = {0};
  unsigned char buff_check[10] = {0};
  uint32_t start_addr = 0;
  char *name = "lefttime_buff";
  union{ 
    unsigned char b[4];
    unsigned long l; 
  }cl;
  
 
  //如果5组记录区都写满了，则先擦除，然后再写
  if(user_charge.lefttime.in_sector_offset >= LEFT_TIME_MAX_OFFSET)
  {
    start_addr = LEFT_TIME_ADDR_BASE;
    err = charge_flash_erase(start_addr,start_addr + LEFT_TIME_MAX_OFFSET);
    if(kNoErr != err)
    {
      user_charge_log("updata_charge_lefttime_register earse flash failed,err = %d",err);
      goto exit;
    }
    user_charge.lefttime.in_sector_offset = 0;
    user_charge.lefttime.flash_write_times += 2;
  }
  
  
  mico_rtos_lock_mutex( &user_charge.charge_mutex );
  buff[0] = user_charge.lefttime.IsChargeType;
  buff[1] = user_charge.lefttime.IsHaveTime;
  user_charge.lefttime.left_time = user_charge.count.left_time;
  cl.l = user_charge.lefttime.left_time; 
  for(i = 0;i < 4;i++)
  {
    buff[2 + i] = cl.b[i];
  }
  cl.l = user_charge.lefttime.flash_write_times;
  for(i = 0;i < 4;i++)
  {
    buff[6 + i] = cl.b[i];
  }
  mico_rtos_unlock_mutex( &user_charge.charge_mutex );

  start_addr = LEFT_TIME_ADDR_BASE + user_charge.lefttime.in_sector_offset;
  err = charge_flash_write(start_addr,buff,sizeof(buff)); 
  if(kNoErr != err)
  {
    user_charge_log("updata_charge_lefttime_register write flash failed,err = %d",err);
    goto exit;
  }
  
  //写完后再把数据读出来，检验是否写成功或者该地址是否损坏 
  memset(buff_check,0,sizeof(buff_check));
  err = charge_flash_read(start_addr,buff_check,sizeof(buff_check));
  if(kNoErr != err)
  {
    user_charge_log("updata_charge_lefttime_register read flash failed,err = %d",err);
    goto exit;
  }
  
  my_printf_array(name,buff_check,sizeof(buff_check));
  
  if(strncmp((char *)buff,(char *)buff_check,sizeof(buff)))
  {    
    err = FLASH_UNKNOWN_ERR;
    user_charge_log("updata_charge_lefttime_register readdata not equal writedata,err = %d",err);
  }
  
  
exit:
  
  user_charge.lefttime.in_sector_offset += 10;
  
  user_charge_log("left.lefttime:%d,flash_writetimes:%d,offset:%d",
                  user_charge.lefttime.left_time,user_charge.lefttime.flash_write_times,user_charge.lefttime.in_sector_offset);
  
  

  return err;
  
}

OSStatus count_sector_earse_restart(void)
{
  OSStatus err = kNoErr;
  user_charge.count.in_sector_offset = IN_SECTOR_MAX_OFFSET;
  err = updata_charge_count_register();               
  if(err != kNoErr)
  {
    user_charge_log("init:count sector bad,chagne to next sector");
    err = charge_change_to_next_count_sector();
    if(err != kNoErr)
    {
      user_charge_log("init:count sector bad,chagne to next sector failed");
      goto exit;
    }
                  
  }

exit:
  return err;

}

//修改1min修改一次的寄存器中的数据，系统在正常计费模式下1分钟修改一次
OSStatus updata_charge_count_register(void)
{
  OSStatus err = kNoErr;
  unsigned char i = 0;
  unsigned char buff[8] = {0};
  unsigned char buff_check[8] = {0};
  //unsigned char trytimes = 0;
  uint32_t start_addr = 0;
  char *name_write = "count_lefttime_write_buff";
  char *name_read = "count_lefttime_read_buff";
  union{ 
    unsigned char b[4];
    unsigned long l; 
  }cl;
  

  //mico_rtos_lock_mutex( &user_charge.charge_mutex );
  if(user_charge.count.in_sector_offset >= IN_SECTOR_MAX_OFFSET && user_charge.count.flash_write_times < FLASH_MAX_WRITE_TIMES)
  {
    user_charge_log("in_sector_offset out of range,offset = %d",user_charge.count.in_sector_offset);
    //超出120的范围后，重新从sector的首地址开始计数，并且需要先擦除扇区
    err = charge_flash_erase(user_charge.count.count_sector_addr_base,user_charge.count.count_sector_addr_base + IN_SECTOR_MAX_OFFSET);
    mico_thread_msleep(10);
    if(err != kNoErr)
    {
      goto exit;
    }
    user_charge.count.flash_write_times += 2;
    user_charge.count.in_sector_offset = 0;
  }
  else if(user_charge.count.in_sector_offset >= IN_SECTOR_MAX_OFFSET && user_charge.count.flash_write_times >= FLASH_MAX_WRITE_TIMES)
  {
    user_charge_log("ready to change to next sector");
    //如果写的次数超过 FLASH_MAX_WRITE_TIMES ，则计数扇区更换到下一组扇区
    if(user_charge.count.count_sector_addr_base < CHARGE_FLASH_MAX_ADDR)
    {
      err = charge_change_to_next_count_sector();  
      if(err != kNoErr)
      {
        user_charge_log("change to next count sector failed");
          //do something or return
        return FLASH_UNKNOWN_ERR;
      }
      user_charge_log("change to next count sector sucessful");
      
    }
    else
    {
      //do something
      err = COUNT_ADDR_BEYOND;
      user_charge.FlashFault = COUNT_ADDR_BEYOND;
      user_charge_log("count_sector_addr_base out of range,count_sector_addr_base:0x%x",user_charge.count.count_sector_addr_base);
      goto exit;
    }  
  }
  
  cl.l = user_charge.count.left_time; 
  for(i = 0;i < 4;i++)
  {
    buff[i] = cl.b[i];
  }
  cl.l = user_charge.count.flash_write_times;
  for(i = 0;i < 4;i++)
  {
    buff[4 + i] = cl.b[i];
  }
  start_addr = user_charge.count.count_sector_addr_base + user_charge.count.in_sector_offset;
  //mico_rtos_unlock_mutex( &user_charge.charge_mutex );
  
  
  //1min计数的sector写之前不擦除，因为是在该扇区的8*120个字节的数据区轮询写，8*120写满后再擦除，然后再从头开始写。
  
  err = charge_flash_write(start_addr,buff,sizeof(buff)); 
  if(kNoErr != err)
  {
    user_charge_log("updata_charge_lefttime_register write flash failed,err = %d",err);
    goto exit;
  }
  
    user_charge_log("count.lefttime:%d,flash_writetimes:%d,sector_base:0x%x,offset:%d,fault_times:%d",
                  user_charge.count.left_time,user_charge.count.flash_write_times,user_charge.count.count_sector_addr_base,user_charge.count.in_sector_offset,user_charge.count.count_flash_fault_times);
  
  

  
  //写完后再把数据读出来，检验是否写成功或者该地址是否损坏 
  memset(buff_check,0,sizeof(buff_check));
  err = charge_flash_read(start_addr,buff_check,sizeof(buff_check));
  if(kNoErr != err)
  {
    user_charge_log("updata_charge_lefttime_register read flash failed,err = %d",err);
    goto exit;
  }
  
  
  
  if(strncmp((char *)buff,(char *)buff_check,sizeof(buff_check)))
  {    
    err = FLASH_UNKNOWN_ERR;
    user_charge_log("updata_charge_lefttime_register readdata not equal writedata,err = %d",err);
    my_printf_array(name_write,buff,sizeof(buff_check));
    my_printf_array(name_read,buff_check,sizeof(buff_check));
    goto exit;
  }

  
  

exit:
  user_charge.count.in_sector_offset += 8;
  if(err != kNoErr)
  {
    user_charge.count.count_flash_fault_times += 1;
    if(user_charge.count.count_flash_fault_times >= 30)
    {
      charge_change_to_next_count_sector();
      user_charge.count.count_flash_fault_times = 0;
    }
  }
  return err;
  
}


//修改用于记录计费地址的寄存器
OSStatus updata_charge_record_address_register(void)
{
  OSStatus err = kNoErr;
  unsigned char i = 0;
  unsigned char buff[8] = {0};
  unsigned char buff_check[8] = {0};
  uint32_t start_addr = 0;
  //char *name = "record_buff";
  union{ 
    unsigned char b[4];
    unsigned long l; 
  }cl;
  
  
  mico_rtos_lock_mutex( &user_charge.charge_mutex );
  cl.l = user_charge.count.count_sector_addr_base; 
  for(i = 0;i < 4;i++)
  {
    buff[i] = cl.b[i];
  }
  cl.l = user_charge.record_flash_write_times;
  for(i = 0;i < 4;i++)
  {
    buff[4 + i] = cl.b[i];
  }
  mico_rtos_unlock_mutex( &user_charge.charge_mutex );

  start_addr = RECORD_ADDR_BASE;
  //写之前先把该sector擦除
  err = charge_flash_erase(start_addr,start_addr + 8);
  mico_thread_msleep(10);
  if(kNoErr != err)
  {
    user_charge_log("updata_charge_record_address_register earse flash failed,err = %d",err);
    goto exit;
  }
  
  err = charge_flash_write(start_addr,buff,sizeof(buff)); 
  if(kNoErr != err)
  {
    user_charge_log("updata_charge_record_address_register write flash failed,err = %d",err);
    goto exit;
  }
  
  //写完后再把数据读出来，检验是否写成功或者该地址是否损坏 
  memset(buff_check,0,sizeof(buff_check));
  err = charge_flash_read(start_addr,buff_check,sizeof(buff_check));
  if(kNoErr != err)
  {
    user_charge_log("updata_charge_record_address_register read flash failed,err = %d",err);
    goto exit;
  }
  
  //my_printf_array(name,buff_check,sizeof(buff_check));
  
  if(strncmp((char *)buff,(char *)buff_check,8))
  {    
    err = FLASH_UNKNOWN_ERR;
    user_charge_log("updata_charge_record_address_register readdata not equal writedata,err = %d",err);
  }
  
  
exit:
  
  return err;
  
}

//用于1Min计数的扇区更换到下一个扇区
OSStatus charge_change_to_next_count_sector(void)
{
  OSStatus err = kNoErr;
  unsigned char trytimes = 0;
  
  if(user_charge.count.count_sector_addr_base >= CHARGE_FLASH_MAX_ADDR || user_charge.count.count_sector_addr_base < TIMING_ADDR_BASE)
  {
    user_charge.FlashFault = COUNT_ADDR_BEYOND;
    user_charge_log("count_sector_address out of range");
    return COUNT_ADDR_BEYOND;
  }
  else
  {
    user_charge.count.count_sector_addr_base += FLASH_SECTOR_SIZE;

  }
  
  //擦除下一个用于计数的扇区
  while(trytimes < 4)
  {
    err = charge_flash_erase(user_charge.count.count_sector_addr_base,user_charge.count.count_sector_addr_base + FLASH_SECTOR_SIZE);
    if(err != kNoErr)
    {
      trytimes += 1;
      if(trytimes == 4)
      {
        user_charge_log("charge_change_to_next_count_sector earse failed");
        goto exit;
      }  
      mico_thread_msleep(100);
    }
    else
    {
      break;
    }
  }
  
  
  trytimes = 0;
  while(trytimes < 4)
  {
    //此处不能获取信号量，因为updata_charge_record_address_register函数中也获取信号量
    user_charge_log("trytimes = %d",trytimes);
    user_charge.record_flash_write_times += 2;
    err = updata_charge_record_address_register();
    if(err != kNoErr)
    {
       user_charge_log("err != kNoErr");
       trytimes += 1;
       if(trytimes >= 4)
       {
           goto exit;
       }
       mico_thread_msleep(100);
       continue;
    }
    user_charge.count.flash_write_times = 0;
    user_charge.count.in_sector_offset = 0;
    user_charge.count.count_flash_fault_times = 0;
    break;
  }
  
  //切换下一个sector时，30分钟更新一次的剩余信息页更新
  trytimes = 0;
  while(trytimes < 4)
  {
    //user_charge.lefttime.flash_write_times += 2;
    err = updata_charge_lefttime_register();
    if(err != kNoErr)
    {
       trytimes += 1;
       mico_thread_msleep(100);
       continue;
    }
    break;
  }
  
  
  
exit:
  if(trytimes == 4 || err != kNoErr)
  {
    user_charge.FlashFault = err;
    user_charge_log("charge flash bad");
    user_charge.count.count_sector_addr_base -= FLASH_SECTOR_SIZE;
    user_charge.record_flash_write_times += 2;
    updata_charge_record_address_register();
  }
   
  user_charge_log("charge_change_to_next_count_sector,sector_base:0x%x",user_charge.count.count_sector_addr_base);
  return err;
}




OSStatus charge_init(void)
{
  unsigned char buff[LEFT_TIME_MAX_OFFSET] = {0};
  //unsigned char buff_40[40] = {0};
  OSStatus err = kNoErr;
  unsigned char *init_buff = NULL;
  unsigned int length = 0;
  unsigned char readtimes = 0;
  unsigned int i,j = 0;
  uint32_t start_addr = 0;
  unsigned char init_times = 0;
  
  union{ 
    unsigned char b[4];
    unsigned long l; 
  }cl;

  
  mico_rtos_init_mutex( &user_charge.charge_mutex );
  
  
 
init_start:
  
  cl.l = 0;
   
  if( platform_flash_drivers[ user_partitions[0].partition_owner ].initialized == false )
  {
    err = charge_flash_init();
    require_noerr_quiet( err, exit );
  }
  
  //charge_flash_erase(CHARGE_FLASH_BASE,CHARGE_FLASH_BASE+10);
  
  start_addr = LEFT_TIME_ADDR_BASE;
  err = charge_flash_read(start_addr,buff,sizeof(buff));
  
  
  mico_rtos_lock_mutex( &stdio_tx_mutex );
  printf("read lefttime sector 50 bytes data:");
  for(i = 0;i < sizeof(buff);i++)
  {
    printf("%x ",buff[i]);
    if(i != 0 && (i % 10 == 9))
    {
      printf("  ");
    }
  }
  printf("\n");
  mico_rtos_unlock_mutex( &stdio_tx_mutex );

   
  
  if(buff[0] == 0xFF && buff[1] == 0xFF && buff[8] == 0xFF && buff[9] == 0xFF)
  {

    user_charge_log("charge flash not init");
   //第一次上电初始化，初始化flash中对应的计费存储空间，初始化到地址寄存器第一组，后面的99组无需初始化
    
    user_charge.lefttime.IsChargeType = 0;
    user_charge.lefttime.IsHaveTime = 0;
    user_charge.lefttime.left_time = 0;
    user_charge.lefttime.flash_write_times = 0;
    user_charge.lefttime.in_sector_offset = 0;
    user_charge.count.count_sector_addr_base = TIMING_ADDR_BASE;
    user_charge.record_flash_write_times = 0; 
    user_charge.count.left_time = 0;
    user_charge.count.flash_write_times = 0;
    user_charge.count.in_sector_offset = 0;
    
    memset(buff,0,sizeof(buff));
    err = charge_flash_erase(LEFT_TIME_ADDR_BASE,RECORD_ADDR_BASE + LEFT_TIME_MAX_OFFSET);
    if(err != kNoErr)
    {
      user_charge_log("init: lefttime sector earse failed");
      goto exit;
    }
    //err = charge_flash_write(LEFT_TIME_ADDR_BASE,buff,sizeof(buff));
    err = updata_charge_lefttime_register();
    if(err != kNoErr)
    {
      user_charge_log("init: lefttime sector write failed");
      goto exit;
    }
    
 
    err = updata_charge_record_address_register();
    if(err != kNoErr)
    {
      user_charge_log("init updata_charge_record_address_register failed");
      goto exit;
    }
    
    //err = updata_charge_count_register();
    err = charge_flash_erase(user_charge.count.count_sector_addr_base,user_charge.count.count_sector_addr_base + IN_SECTOR_MAX_OFFSET);
    if(err != kNoErr)
    {
      user_charge_log("init updata_charge_count_register failed");
      goto exit;
    }

    //goto exit;    
    
  } 
  else
  {
    err = get_lefttime_register_data();
    if(err != kNoErr)
    {
      user_charge_log("get_lefttime_register_data failed");
      goto exit;
    }
    user_charge_log("init:IsChargeType = %d,IsHaveTime = %d,lefttime = %d,writetimes:%d,offset:%d",user_charge.lefttime.IsChargeType,
                  user_charge.lefttime.IsHaveTime,user_charge.lefttime.left_time,user_charge.lefttime.flash_write_times,user_charge.lefttime.in_sector_offset);
    
    err = get_record_address_register_data();
    if(err != kNoErr)
    {
      user_charge_log("init:get_record_address_register_data failed");
      goto exit;
    }
    user_charge_log("init:count addr = %x,writes = %d",user_charge.count.count_sector_addr_base,user_charge.count.flash_write_times);
    if(user_charge.count.count_sector_addr_base >= CHARGE_FLASH_MAX_ADDR)
    {
      err = COUNT_ADDR_BEYOND;
      user_charge.FlashFault = COUNT_ADDR_BEYOND;
      user_charge_log("init:count_sector_addr_base out of range,count_sector_addr_base:0x%x",user_charge.count.count_sector_addr_base);
      //althought error happened,but lefttime != 0,work on until lefttime ==0, then stop
      //if need read back last address data?????????????? 
     
      user_charge.count.left_time = user_charge.lefttime.left_time;
      goto exit;
    }
    else
    {
      user_charge.FlashFault = 0;
    }
    
    //8*120 bytes字节分8次读取，防止malloc失败
    start_addr = user_charge.count.count_sector_addr_base;
    readtimes = 1;
    length = IN_SECTOR_MAX_OFFSET / readtimes;
    if(init_buff != NULL)
    {
      free(init_buff);
      init_buff = NULL;
    }
    init_buff = malloc(length);
    if(init_buff == NULL)
    {
      user_charge_log("malloc for init_buff failed");
      err = -1;
      goto exit;
    }
    memset(init_buff,0,length);
    err = charge_flash_read(start_addr,init_buff,length);
    if(err != kNoErr)
    {
       user_charge_log("init read count sector data failed");
       goto exit;       
    }
    for(j = 0;j < length;j += 8)
    {
      if(init_buff[j] == 0xFF && init_buff[j+1] == 0xFF && init_buff[j+2] == 0xFF && init_buff[j+3] == 0xFF)
      {
        user_charge_log("init:j = %d",j);
        my_printf_array("init_buff",init_buff+j,8);
        
        if(j == 0)
        {         
          user_charge_log("init:find offset == 0");
          
          if((init_buff[j+8] & init_buff[j+9] & init_buff[j+10] & init_buff[j+11]) == 0xFF)
          {
            user_charge_log("init:way 1");
            if(user_charge.count.count_sector_addr_base == TIMING_ADDR_BASE)
            {
              user_charge.count.left_time = 0;
              user_charge.count.flash_write_times = 0;
              user_charge.count.in_sector_offset = 0;
            }
            else if(user_charge.count.count_sector_addr_base > TIMING_ADDR_BASE && user_charge.count.count_sector_addr_base < CHARGE_FLASH_MAX_ADDR)
            {
              user_charge_log("init:way 2");
              //此种情况可能是刚换到另一个扇区断电了
              //是否读上一个扇区的数据进行比较 ？？？？？？？
              user_charge.count.left_time = user_charge.lefttime.left_time;
              user_charge.count.flash_write_times = 0;
              user_charge.count.in_sector_offset = 0;             
            }
            else
            {
              user_charge_log("init:way 3");
              err = COUNT_ADDR_BEYOND;
              user_charge_log("init:count sector address out of range");
              goto exit;
            }

          }
        }
        else
        {
          user_charge_log("init:way 4-0");
          if((init_buff[j-8] & init_buff[j-7] & init_buff[j-6] & init_buff[j-5]) != 0xFF )
          {
            user_charge_log("init:way 4");
            
            if(j < (length - 8) && (init_buff[j+8] & init_buff[j+9] & init_buff[j+10] & init_buff[j+11]) != 0xFF)
            {
              continue;
            }
            
            
            for(i = 0;i < 4;i++)
            {
              cl.b[i] = init_buff[j - 8 + i];
            }
            user_charge.count.left_time = cl.l;
            for(i = 0;i < 4;i++)
            {
              cl.b[i] = init_buff[j -4 + i];
            }
            
            
            
            user_charge.count.flash_write_times = cl.l;
            user_charge.count.in_sector_offset = j;
            user_charge_log("init:user_charge.count.left_time:%d,user_charge.count.in_sector_offset:%d",user_charge.count.left_time,user_charge.count.in_sector_offset);
            //正常情况下，user_charge.count.left_time - user_charge.lefttime.left_time <= SAVE_TIME_INTERVAL
            if(user_charge.count.left_time <= user_charge.lefttime.left_time)
            {
              if((user_charge.lefttime.left_time - user_charge.count.left_time) <= SAVE_TIME_INTERVAL)
              {
                user_charge_log("init:way 5");
                if( user_charge.lefttime.left_time == user_charge.count.left_time)
                {
                    goto exit; 
                }
                else
                {
                    user_charge_log("user_charge.lefttime.left_time not equal user_charge.count.left_time");
                }
                user_charge.lefttime.left_time = user_charge.count.left_time;
                //user_charge.lefttime.flash_write_times += 2;
                err = updata_charge_lefttime_register();
                {
                  if(err != kNoErr)
                  {
                    user_charge_log("init: updata_charge_lefttime_register failed");
                    goto exit;       
                  }
                }
                
              }
              else
              {
                user_charge_log("init:way 6");
                //此种情况应该是出错了
                user_charge.count.left_time = user_charge.lefttime.left_time;
                //记录的时间出问题后，擦除该扇区，重新计费
                user_charge.count.in_sector_offset = IN_SECTOR_MAX_OFFSET;
                err = updata_charge_count_register();               
                if(err != kNoErr)
                {
                  user_charge_log("init:count sector bad,chagne to next sector");
                  err = charge_change_to_next_count_sector();
                  if(err != kNoErr)
                  {
                    user_charge_log("init:count sector bad,chagne to next sector failed");
                    goto exit;
                  }
                  
                }
              }
            }
          }
          else if((init_buff[j-8] & init_buff[j-7] & init_buff[j-6] & init_buff[j-5]) != 0xFF && (init_buff[j+8] & init_buff[j+9] & init_buff[j+10] & init_buff[j+11]) != 0xFF)
          {
            //此种情况可能是该8个字节没有写成功，而后面的写成功了，继续往后找
            continue;
          }
          else
          {
            user_charge_log("init:way 7");
             //出现此种情况，用于计时的sector已经坏掉了，有可能有一部分时间没有减掉，但是没有办法找回，时间不会超过30分钟。更换到下个计时扇区
             user_charge.count.left_time = user_charge.lefttime.left_time;
                //记录的时间出问题后，擦除该扇区，重新计费
             err = count_sector_earse_restart();
             if(err != kNoErr)
             {
               user_charge_log("init:count sector bad,and chagne to next sector failed");
               goto exit;
             }
          }
        }
        break;   
      }
      else
      {
        continue;
      }
            
    }
    if(j == length && (init_buff[j-16] & init_buff[j-15] & init_buff[j-14] & init_buff[j-13]) != 0xFF)
    {
      //没有找到上次计数到哪了，只能是重新从开始地址开始计时,也许是本身就记录到最后8个字节断电了
      //此时不取最后8个字节的数据，防止最后8个字节没有写完就断电了，取倒数第二组的数据，然后再把取到的剩余时间减1
      user_charge_log("init:j == length,not find offset");
      
      if(init_buff[j - 1] == 0xFF)
      {
        //此种情况FLASH没写完就断电了
        for(i = 0;i < 4;i++)
        {
          cl.b[i] = init_buff[j - 16 + i];
        }
        user_charge.count.left_time = cl.l - 1;
      
        for(i = 0;i < 4;i++)
        {
          cl.b[i] = init_buff[j - 12 + i];
        }
        user_charge.count.flash_write_times = cl.l;
      }
      else
      {
        for(i = 0;i < 4;i++)
        {
          cl.b[i] = init_buff[j - 8 + i];
        }
        user_charge.count.left_time = cl.l;
      
        for(i = 0;i < 4;i++)
        {
          cl.b[i] = init_buff[j - 4 + i];
        }
        user_charge.count.flash_write_times = cl.l;     
      }
      


      if(user_charge.count.left_time < user_charge.lefttime.left_time)
      {
        user_charge_log("user_charge.lefttime.left_time - user_charge.count.left_time = %d",(user_charge.lefttime.left_time - user_charge.count.left_time));
        user_charge_log("user_charge.count.left_time = %d,user_charge.count.flash_write_times:%d",user_charge.count.left_time,user_charge.count.flash_write_times);
        if((user_charge.lefttime.left_time - user_charge.count.left_time) <= SAVE_TIME_INTERVAL)
        {
          user_charge.lefttime.left_time = user_charge.count.left_time;         
          updata_charge_lefttime_register();
          //赋值user_charge.count.in_sector_offset = IN_SECTOR_MAX_OFFSET后，下一分钟更新时间时会自动从该扇区前8个字节开始计费
          user_charge.count.in_sector_offset = IN_SECTOR_MAX_OFFSET;
        }
        else
        {
          user_charge.count.left_time = user_charge.lefttime.left_time;
          err = count_sector_earse_restart();
          if(err != kNoErr)
          {
             user_charge_log("init:count sector bad,chagne to next sector failed");
             goto exit;
          }          
        }
        
      }
      else
      {
        user_charge_log("user_charge.count.left_time > user_charge.lefttime.left_time,err,change to next sector");
        user_charge.count.left_time = user_charge.lefttime.left_time;
        charge_change_to_next_count_sector();
      }
           
    }
    else
    {
      user_charge_log("j = %d",j);
    }
   
  }
  
 
    
exit:
  updata_timedata();
  if(init_buff != NULL)
  {
    free(init_buff);
  }
  
  if(err != kNoErr)
  {
    init_times += 1;
    if(init_times < 4)
    {
      goto init_start;
    }
    else
    {
      user_charge_log("charge flash init failed");
    }
  }
  else
  {
    user_charge.IsChargeInit = 1;
    user_charge_log("charge flash init sucessful");
    user_charge.count.left_time = user_charge.lefttime.left_time;
  }
  
  
  return err;
  
  
  
}


void stop_charge_mode(void)
{
    user_charge.lefttime.IsChargeType = 0;
    user_charge.lefttime.IsHaveTime = 0;
    user_charge.lefttime.left_time_mon = 0;
    user_charge.lefttime.left_time_day = 0;
    user_charge.lefttime.left_time_hour = 0;
    user_charge.lefttime.left_time_min = 0;
    user_charge.lefttime.left_time = 0;
    
    user_charge.count.left_time = 0;
    

}


void updata_timedata(void)
{
    unsigned int temp_time = 0;
    
    user_charge.lefttime.left_time_mon = user_charge.lefttime.left_time / MONTH_TO_MIN;
    temp_time = user_charge.lefttime.left_time % MONTH_TO_MIN;
    user_charge.lefttime.left_time_day = temp_time / DAY_TO_MIN;
    temp_time = temp_time % DAY_TO_MIN;
    user_charge.lefttime.left_time_hour = temp_time / HOUR_TO_MIN;
    user_charge.lefttime.left_time_min = temp_time % HOUR_TO_MIN;

}




//确认收到筹码
static OSStatus fog_v2_device_chips_confirm(char *orderNo,int chips)
{
    OSStatus err = kGeneralErr;
    int32_t code = -1;
    const char* device_chips_confirm_body = "{\"orderNo\":\"%s\",\"type\":\"1\",\"status\":\"2\",\"chips\":%d}";
    char http_body[256] = {0};
    FOG_HTTP_RESPONSE_SETTING_S user_http_res;
    uint8_t retry = 0;
 
    memset(&user_http_res, 0, sizeof(user_http_res));
 
start_chips_confirm:
    while(get_wifi_status() == false)
    {
        app_log("https disconnect, fog_v2_device_chips_confirm is waitting...");
        err = kGeneralErr;
        goto exit;
    }
 
    sprintf(http_body, device_chips_confirm_body, orderNo, chips);
 
    app_log("=====> device_chips_confirm send ======>");
    app_log("upload:%s",http_body);
   
    err = fog_v2_push_http_req_mutex(true, FOG_V2_CHIPS_CONFIRM_METHOD, FOG_V2_CHIPS_CONFIRM_URI, FOG_V2_HTTP_DOMAIN_NAME, http_body, &user_http_res);
    require_noerr( err, exit );
 
    //处理返回结果
    err = process_response_body(user_http_res.fog_response_body, &code);
    require_noerr( err, exit );
 
    err = check_http_body_code(code);   //如果是token过期是错误问题，函数内部会处理完成之后再返回
    require_noerr( err, exit );
 
    app_log("<===== device_sync_status success <======");
 
exit:
    if ( user_http_res.fog_response_body != NULL ) //释放资源
    {
        free( user_http_res.fog_response_body );
        user_http_res.fog_response_body = NULL;
   }
 
    if(err != kNoErr)
    {
        app_log("<===== device_chips_confirm error <======");
 
        mico_thread_msleep(200);
 
        retry ++;
        if(retry >= HTTP_MAX_RETRY_TIMES)
        {
            return kGeneralErr;
        }
 
        goto start_chips_confirm;
    }
 
    return err;
}




OSStatus charge_info_confirm(char *ordno, char type,unsigned long charge_time)
{
    OSStatus err = kNoErr;
    
    err = fog_v2_device_chips_confirm(ordno,charge_time);
    
    
    return err;
}


OSStatus updata_charge_timedata(const char *ordno, char type,unsigned long charge_time)
{
    OSStatus err = kNoErr;
    
    user_charge_log ( "get new charge info: type = %d,charge_time = %d",type,charge_time);
       
    if(type == 0)
    {
        stop_charge_mode();
    }
    else if(type == 1)
    {
        user_charge.lefttime.IsChargeType = 1;
        user_charge.lefttime.left_time += charge_time;
        if(user_charge.lefttime.left_time == 0)
        {
            user_charge.lefttime.IsHaveTime = 0;
        }
        else
        {
            user_charge.lefttime.IsHaveTime = 1;
        }
        user_charge.count.left_time = user_charge.lefttime.left_time;
    }
    else
    {
        user_charge_log("parameter type error");
        err = -1;
        goto exit;
    }
    

    updata_charge_lefttime_register();
    updata_charge_count_register();
    updata_timedata();
    err = kNoErr;
     
exit:
    
    return err;
}









void charge_thread(mico_thread_arg_t arg)
{
    static unsigned int lefttime_count_times = 0;
    OSStatus err = kNoErr;
    uint32_t now_time = 0;
    uint32_t next_1min_time = 60000;
    uint32_t temp = 0;
    //const unsigned int min_to_ms = 5*1000;
    const unsigned int min_to_ms = 60*1000;

    
    
    //建立任务后，立刻读取flash中保存的计费的相关数据
    err = charge_init();

    
    while(1)
    {
        
        now_time = mico_rtos_get_time();
        //user_charge_log("now_time:%d",now_time);
        
        //user_charge_log("IsChargeType = %d,IsHaveTime= %d",user_charge.lefttime.IsChargeType,user_charge.lefttime.IsHaveTime);     
      
        if(user_charge.lefttime.IsChargeType == 1 && user_charge.lefttime.IsHaveTime == 1)
        {
            //防止时间计数溢出
            if((now_time <= min_to_ms) && (next_1min_time >= (0xFFFFFFFF - min_to_ms)) )
            {
                temp = 0xFFFFFFFF - next_1min_time;
                temp += now_time;
                //正常情况下此时temp应该小于等于min_to_ms，
                //也有可能时间刚溢出时而且到了1分钟的计费时间，但是系统没有调度到此任务耽误了一点时间，而导致temp大于min_to_ms，但是temp肯定应该小于 2 * min_to_ms
                if(temp <= min_to_ms)
                {
                    next_1min_time = min_to_ms - temp;
                }
                else if(temp < (2 * min_to_ms))
                {
                    next_1min_time = 2 * min_to_ms - temp + now_time;
                    
                    mico_rtos_lock_mutex( &user_charge.charge_mutex );
                    user_charge.lefttime.left_time -= 1;
                    mico_rtos_unlock_mutex( &user_charge.charge_mutex );
                    
                    //此处就不刷新flash了，只做减去1分钟处理，下次刷新flash时相当于减去了2分钟
                    
                }
                else
                {
                    //如果时间出错了，立刻重新刷新时间数据
                    next_1min_time = now_time + min_to_ms;
                }
            }
            
            //1分钟记一次时间，并把剩余时间写入flash中
            if(now_time >= next_1min_time)
            {
              
                //user_charge_log("1min come");              
                lefttime_count_times += 1;
               
                if(user_charge.count.left_time > 0)
                { 
                    mico_rtos_lock_mutex( &user_charge.charge_mutex );
                    user_charge.count.left_time -= 1;
                    user_charge.lefttime.left_time = user_charge.count.left_time;
                    mico_rtos_unlock_mutex( &user_charge.charge_mutex );
                }
                
                if(user_charge.lefttime.left_time == 0)
                {
                    mico_rtos_lock_mutex( &user_charge.charge_mutex );
                    user_charge.lefttime.IsHaveTime = 0;
                    mico_rtos_unlock_mutex( &user_charge.charge_mutex );
                    //updata_charge_lefttime_register 函数中有获取信号量，获取信号量的函数不能再包含获取该信号量的函数
                    updata_charge_lefttime_register();
                    //关闭设备
                    user_charge_log("lefttime == 0,device stop");
                    //execute_EP_val(DEVICE_OFF);                    
                }
                
                updata_timedata();
              
                next_1min_time += min_to_ms;
             
                //user_charge_log("user_charge.lefttime.left_time:%d",user_charge.lefttime.left_time);
               
                //写flash
                err = updata_charge_count_register();
                if(err != kNoErr)
                {
                        //如果用于计数的寄存器操作错误超过 FLASH_MAX_FAULT_TIMES 次，则判定为改组寄存器存在问题了
                    user_charge.flash_fault_times += 1;
                    if(user_charge.count.count_flash_fault_times >= FLASH_MAX_FAULT_TIMES)
                    {
                        charge_change_to_next_count_sector();
                        user_charge.flash_fault_times = 0;
                    }
                }
                
                if(lefttime_count_times >= SAVE_TIME_INTERVAL)
                {
                    lefttime_count_times = 0;
                    updata_charge_lefttime_register();  
                }
             
            }
         
        }
        else
        {
            next_1min_time = now_time + min_to_ms;
        }
        mico_thread_sleep(1);
        
        //WIFI模块连接网络正常的状态下，指示灯闪烁间隔1秒钟
        if(get_wifi_status() == true)
        {
            //MicoGpioOutputTrigger((mico_gpio_t)MICO_SYS_LED);
            MicoGpioOutputLow((mico_gpio_t)MICO_SYS_LED);
        }
        else
        {
            MicoGpioOutputHigh((mico_gpio_t)MICO_SYS_LED);
        }
    }
}





