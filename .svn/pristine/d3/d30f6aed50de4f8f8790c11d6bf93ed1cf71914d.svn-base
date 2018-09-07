#include "stdio.h"
#include "user_flash.h"


//按32位读取数据
int flash_embedded_read(uint8_t *buff,uint32_t start_addr,uint32_t length)
{  
    //uint32_t temp = 0;

    //__IO uint32_t* p_flash = NULL;
  
    uint32_t p_flash = 0;
  
    //uint8_t value = 0;
  
    if(buff == NULL || length == 0)
    {
        return PARAMETER_ERROR;
    }
    
    if(start_addr < EMBEDDED_FLASH_START_ADDR || (start_addr + length) >= EMBEDDED_FLASH_MAX_ADDR )
    {
        return FLASH_ADDR_OUT;
    }
  
    //USER_FLASH_ADDR_CHECK(start_addr);
  
    FLASH_Unlock();
    
 
    //p_flash = (__IO uint32_t*)start_addr;
    p_flash = start_addr;
  
    while(length--)
    {
        //*buff++ = *p_flash++;    
        //*buff++ = *(__IO uint32_t*)p_flash;   
        *buff++  = *(__IO uint8_t*)p_flash++;
        //p_flash += 4;
    };
  
    FLASH_Lock();
    
    return 0;
}


//按32位写数据
//注：FLASH_ProgramWord的传递的起始地址参数必须是2地址对齐的，否则会死机
int flash_embedded_write(uint32_t *buff,uint32_t start_addr,uint32_t length)
{
    int status = FLASH_COMPLETE;
  
    //uint32_t *p_buff = NULL;

    uint32_t p_flash = NULL;
    uint32_t temp = 0;
    uint32_t i = 0;
  
    if(buff == NULL || length == 0)
    {
        return PARAMETER_ERROR;
    }
    
    if(start_addr < EMBEDDED_FLASH_START_ADDR || (start_addr + length * 4) >= EMBEDDED_FLASH_MAX_ADDR )
    {
        return FLASH_ADDR_OUT;
    }
  
    USER_FLASH_ADDR_CHECK(start_addr);
  
    FLASH_Unlock();
    
    printf("step0\r\n");
    
    FLASH_ClearFlag(FLASH_FLAG_PGERR | FLASH_FLAG_WRPERR | FLASH_FLAG_EOP);
    
    FLASH_ErasePage(start_addr);
    //FLASH_ErasePage(0x800FC00);
    
    //FLASH_Lock();
    
    printf("step1\r\n");
    
    //p_buff = buff;
    p_flash = start_addr;
    
    //FLASH_Unlock();
    
    
  
    while(length--)
    {
        temp = buff[i];
        FLASH_Unlock();
        status = FLASH_ProgramWord(p_flash,temp);  
        FLASH_Lock();
        if(status != FLASH_COMPLETE)
        {
            goto exit;
        }
        p_flash += 4;
        i+= 1;
    };

    //FLASH_ProgramWord(0x800FBFF,49); 
    
    printf("step2\r\n");
  
    FLASH_Lock();
    
    status = 0;
    
exit:
    
    return status;
}






