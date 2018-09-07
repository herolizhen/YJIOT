#ifndef __USER_FLASH_H__
#define __USER_FLASH_H__


#include "stm32f0xx_flash.h"


#define USER_FLASH_START_ADDR     0x800FC00
#define USER_FLASH_END_ADDR       0x800FFFF


#define EMBEDDED_FLASH_START_ADDR       0x8000000
#define EMBEDDED_FLASH_MAX_ADDR         0x8010000

#define USER_FLASH_ADDR_ERROR     -1
#define PARAMETER_ERROR           -2
#define FLASH_ADDR_OUT            -3

#define USER_FLASH_ADDR_CHECK(x) {if(x < USER_FLASH_START_ADDR || x > USER_FLASH_END_ADDR) return USER_FLASH_ADDR_ERROR;}

//#define USER_FLASH_ADDR_CHECK(x) {if(x < 0x800FBFF || x > 0x800FFFF) return -1;}


int flash_embedded_read(uint8_t *buff,uint32_t start_addr,uint32_t length);
int flash_embedded_write(uint32_t *buff,uint32_t start_addr,uint32_t length);






#endif
