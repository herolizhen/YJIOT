#ifndef __USER_CONFIG_H__
#define __USER_CONFIG_H__

#include "stdint.h"
#include "user_flash.h"

#define USER_CONFIG_USART   USART3

#define USER_CONFIG_BUFF_SIZE  150

//空格ASCII码
#define ASCII_SPACE     0x20

#define KEY_MAX_LEN     7
#define KEY_BUFF_SIZE     8
#define MAX_KEY_NUM       8


#define  DEVICE_ID_LEN      40
#define  KEY_STRING_LEN     (KEY_BUFF_SIZE * MAX_KEY_NUM)


//#define PARTITION_LENGTH    120
#define PARTITION_LENGTH    (DEVICE_ID_LEN + KEY_STRING_LEN + 40)
//#define MAX_CONFIG_NUM      ((USER_FLASH_END_ADDR - USER_FLASH_START_ADDR + 1) / PARTITION_LENGTH)
#define MAX_CONFIG_NUM      5

#define PARTITION_0_START_ADDR   (USER_FLASH_START_ADDR)
#define PARTITION_1_START_ADDR   (PARTITION_0_START_ADDR + PARTITION_LENGTH)
#define PARTITION_2_START_ADDR   (PARTITION_1_START_ADDR + PARTITION_LENGTH)
#define PARTITION_3_START_ADDR   (PARTITION_2_START_ADDR + PARTITION_LENGTH)
#define PARTITION_4_START_ADDR   (PARTITION_3_START_ADDR + PARTITION_LENGTH)


#define PARSE_KEY_SUCCESS             0
#define PARSE_KEY_PARA_ERR            1
#define PARSE_KEY_MALLOC_FAIL         2
#define KEY_LENGTH_TOO_LONG           3

#define FRAME_START_FLAG       0x2A
#define FRAME_STOP_FLAG        0x23


enum config_func{

  STOP_USER_CONFIG    = 0,
  START_USER_CONFIG   = 1,
  WRITE_USER_CONFIG   = 2,
  CONFIG_MAX_NUM      = 3

};

enum config_response_state{

  CMD_RES_SUCCESS  = 0,
  CMD_RES_FAIL     = 1,
  CMD_RES_MAX_NUM  = 2

};



/*
typedef struct{
  
  uint32_t flag;    //从FLASH的配置信息分区读出数据后，通过来标志位判断该分区是否有配置信息,1表示有，其他值表示空  
  uint32_t slave_addr;
  uint32_t fanc_code;
  uint32_t start_addr;
  uint32_t length;
  uint32_t timeinterval;
  uint32_t timeout;
  char device_id[DEVICE_ID_LEN];
  union{
  
    char string_key[KEY_STRING_LEN];
    char keys[KEY_STRING_LEN/KEY_BUFF_SIZE][KEY_BUFF_SIZE];
     
  }key;
  uint32_t key_num;


}user_config_t;
*/


//该结构体长度是4字节的整数倍
typedef struct{
  
  uint8_t flag;    //从FLASH的配置信息分区读出数据后，通过来标志位判断该分区是否有配置信息,1表示有，其他值表示空  
  uint8_t slave_addr;
  uint8_t fanc_code;  //modbus功能码
  uint8_t timeout;   //超时时间，单位s
  uint32_t start_addr;
  uint16_t length;  
  uint16_t timeinterval;   //采集周期，单位s
  char device_id[DEVICE_ID_LEN];
  union{
  
    char string_key[KEY_STRING_LEN];
    char keys[KEY_STRING_LEN/KEY_BUFF_SIZE][KEY_BUFF_SIZE];
     
  }key;
  uint16_t division[MAX_KEY_NUM];
  uint32_t key_num;


}user_config_t;


typedef struct{

  uint32_t start_addr;
  uint32_t length;

}user_flash_partition_t;


typedef struct{

  uint8_t is_start_config;
  uint8_t is_need_earse;
  uint8_t write_patition;

}flash_info_t;


enum partition{

  partition0      = 0,
  partition1      = 1,
  partition2      = 2,
  partition3      = 3,
  partition4      = 4,
  max_partition   = 5,

};


typedef struct{
  
    uint8_t config_num;
    user_config_t *user_configs[MAX_CONFIG_NUM];

}user_configs_info_t;

void user_flash_page_earse(void);
int read_user_one_config(uint8_t partition,user_config_t **pconfigbuff);
int write_user_config(const user_config_t *config,uint8_t partition);

uint8_t read_user_configs(void);

uint8_t parse_string_key(char *string_key,uint32_t buff_size,uint8_t *key_num);

void deal_user_config_info(void);
uint8_t frame_check(const uint8_t *buff);
void clear_rx_buff(uint8_t *buff,uint8_t size);
uint8_t user_config_uart_sendbytes(const uint8_t *buff,uint8_t length);
uint8_t user_config_response(uint8_t func,uint8_t state);

void print_config(user_config_t *pconfig,char *name,uint8_t keytype);

void user_config_usart_handler(void);



void flash_test(void);


#endif

