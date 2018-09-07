#include "stdio.h"
#include "string.h"
#include "ucos_ii.h" 
#include "user_flash.h"
#include "user_config.h"
#include "trans_recieve_buff_control.h"
#include "malloc.h"
#include "user_usart.h"

//extern uint8_t rx_index; 
//extern uint8_t m_Modbus_Master_RX_Buff[RX_Buff_SIZE];

volatile uint8_t config_rx_index; 
uint8_t user_config_rx_buff[USER_CONFIG_BUFF_SIZE];



//user_config_t user_config = {

//    .flag = 1,
//    .slave_addr = 1,
//    .fanc_code = 3,
//    .start_addr = 0x01,
//    .length = 10,
//    .timeout = 2,
//    .device_id = "device_id_1",
//    .key.string_key = "key1 key2 key3 key4"

//};




//struct{
//  
//    uint8_t config_num;
//    user_config_t *user_configs[MAX_CONFIG_NUM];

//}user_configs_info;

user_configs_info_t user_configs_info;


//用于标识配置信息区的flash是否需要擦除和下一次写哪个分区
static flash_info_t flash_info; 


const user_flash_partition_t user_flash_partition[MAX_CONFIG_NUM] = {

  {
      .start_addr = PARTITION_0_START_ADDR,
      .length = PARTITION_LENGTH  
  },{
      .start_addr = PARTITION_1_START_ADDR,
      .length = PARTITION_LENGTH  
  },{
      .start_addr = PARTITION_2_START_ADDR,
      .length = PARTITION_LENGTH  
  },{
      .start_addr = PARTITION_3_START_ADDR,
      .length = PARTITION_LENGTH  
  },{
      .start_addr = PARTITION_4_START_ADDR,
      .length = PARTITION_LENGTH  
  }

};


void user_flash_page_earse(void)
{
    FLASH_Unlock();
    FLASH_ClearFlag(FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR | FLASH_FLAG_EOP);
    FLASH_ErasePage(USER_FLASH_START_ADDR);
    FLASH_Lock();
}

int read_user_one_config(uint8_t partition,user_config_t **pconfigbuff)
{
    int ret = 0;
    //uint8_t i = 0;
    uint8_t key_num = 0;
  
    uint8_t *pbuff = NULL;
    user_config_t *pconfig = NULL;

  
    uint32_t start_addr = 0;
   
    uint32_t length = 0;
  
    if(pconfigbuff == NULL || partition >= max_partition)
    {
        ret = 1;
        goto exit;
    }
  
    *pconfigbuff = NULL;
    
    length = (uint32_t)sizeof(user_config_t);
    
    //printf("malloc %d bytes\r\n",length);
    pbuff = mymalloc(length);
    memset(pbuff,0,length);
  
    if(pbuff == NULL)
    {
        ret = 2;
        printf("read_user_config malloc fail");
        goto exit;
    }
    
    switch(partition)
    {
       case 0:
        start_addr = PARTITION_0_START_ADDR;
        break;
       case 1:
        start_addr = PARTITION_1_START_ADDR;
        break;
       case 2:
        start_addr = PARTITION_2_START_ADDR;
        break;
       case 3:
        start_addr = PARTITION_3_START_ADDR;
        break;
       case 4:
        start_addr = PARTITION_4_START_ADDR;
        break;
      
      default:
        break;
    }
    
    //printf("start_addr = %x\r\n",start_addr);
    
    //start_addr = USER_FLASH_START_ADDR;
    ret = flash_embedded_read(pbuff,start_addr,(sizeof(user_config_t)));  
    if(ret != 0)
    {
        ret = 3;
        printf("read flash err:%d\r\n",ret);
        goto exit;
    }
    
    printf("read one config success\r\n");
    
    pconfig = (user_config_t *)pbuff;
       
    parse_string_key(pconfig->key.string_key,sizeof(pconfig->key.string_key),&key_num);
    
    pconfig->key_num = key_num;
    
    if(pconfig->flag == 1)
    {
        *pconfigbuff = pconfig;
    }
    else 
    {
        myfree(pconfig);
    }
    
    

    
    
exit:
    if(ret != 0)
    {
        if(pbuff != NULL)
        {
            myfree(pconfig);
        }
    }

    
    return ret;
}




int write_user_config(const user_config_t *config,uint8_t partition)
{
    int ret = 0;
  
    uint32_t *pconfig = NULL;
  
    uint32_t start_addr = 0;
     
    if(config == NULL)
    {
        ret = -1;
        goto exit;
    }
    
    if(partition >= max_partition )
    {
        ret = -2;
        goto exit;
    }
    
    printf("write user_config:\r\n");
    printf("device id:%s\r\n",config->device_id);
    printf("slave:%d  func_code:%d\r\n",config->slave_addr,config->fanc_code);  
    printf("start_add:%d  length:%d\r\n",config->start_addr,config->length);  
    printf("key:%s\r\n",config->key.string_key);
    
    pconfig = (uint32_t *)config;
    
    switch(partition)
    {
       case 0:
        start_addr = PARTITION_0_START_ADDR;
        break;
       case 1:
        start_addr = PARTITION_1_START_ADDR;
        break;
       case 2:
        start_addr = PARTITION_2_START_ADDR;
        break;
       case 3:
        start_addr = PARTITION_3_START_ADDR;
        break;
       case 4:
        start_addr = PARTITION_4_START_ADDR;
        break;
      
      default:
        break;
    }
    
    
    ret = flash_embedded_write((uint32_t *)pconfig,start_addr,(sizeof(user_config_t))/4); 
    if(ret != 0)
    {
        printf("write flash err:%d\r\n",ret);
    }
    
    printf("write config success\r\n");   
    
exit:
    
    return ret;
}


uint8_t read_user_configs(void)
{
    uint8_t i = 0;
    int ret = 0;
    char buff[10] = {0};
  
  
    for(i = 0;i < MAX_CONFIG_NUM;i++)
    {
        ret = read_user_one_config(i,&user_configs_info.user_configs[i]);
        if(ret == 0)
        {
            if(user_configs_info.user_configs[i]->flag == 1)
            {
                user_configs_info.config_num += 1;
                
                memset(buff,0,strlen(buff));
                sprintf(buff,"config %d",i);
                print_config(user_configs_info.user_configs[i],buff,1);
            }
            else
            {
                break;
            }
        }
        else
        {
            printf("init:read %d config fail\r\n",i);
            break;
        }
    }
    
    printf("init:total %d configs\r\n",i);
    
    return ret;
}



uint8_t parse_string_key(char *string_key,uint32_t buff_size,uint8_t *key_num)
{
    uint8_t result = PARSE_KEY_SUCCESS; 
    char *pbuff = NULL;
    char *key_start = NULL;
    uint8_t key_len = 0;
    uint32_t i = 0;
  
    if(string_key == NULL || buff_size <= 0)
    {
        result = PARSE_KEY_PARA_ERR;
        goto para_err;
    }
    
    pbuff = mymalloc(buff_size);
    if(pbuff == NULL)
    {        
        result = PARSE_KEY_MALLOC_FAIL;
        goto malloc_fail;
    }
    
    memset(pbuff,0,buff_size);
    strcpy(pbuff,string_key);
    
    memset(string_key,0,buff_size);
    
    
    *key_num = 0;
    key_start = pbuff;
    for(i = 0;i < buff_size;i++)
    {  
        if(*(pbuff + i) == '\0')
        {
            if(key_len > 0)
            {
                strncpy(string_key + KEY_BUFF_SIZE * (*key_num),key_start,key_len);           
                *key_num += 1;
            }
            goto end;
        }
        else if(*(pbuff + i) == ASCII_SPACE)
        {
            if(key_len > KEY_MAX_LEN)
            {
                result = KEY_LENGTH_TOO_LONG;               
                goto key_too_long;
            }
            
            if(key_len == 0)
            {
                //此种情况可能是pbuff[0]是空格，或者连续两个空格，如果连续两个空格则直接处理下一个字符
                key_start++;
                continue;
            }
            
            strncpy(string_key + KEY_BUFF_SIZE * (*key_num),key_start,key_len);
            
            *key_num += 1;
            key_len = 0;
                       
            key_start = pbuff + i + 1;
        }
        else
        {
            key_len++;
        }
    }
    
    
    
end:  
    if(pbuff != NULL)
    {
        myfree(pbuff);
      
    }
    
    return PARSE_KEY_SUCCESS; 
    
key_too_long:
    
    if(pbuff != NULL)
    {
        myfree(pbuff);
      
    }
    
    if(result != PARSE_KEY_SUCCESS)
    {
        //因为string_key数组中的数据已经被清零，回复该字符串的数据
        memset(string_key,0,buff_size);
        strcpy(string_key,pbuff);
    }
    
malloc_fail:
        
para_err:
    
    return result; 

}

//get user config data via usart,then write to flash
void deal_user_config_info(void)
{  
    uint8_t position = 0;
    uint8_t pos = 0;
    uint8_t i = 0;
    uint8_t data_length = 0;
    user_config_t *pconfig = NULL;
    uint8_t func = 0;
  
    int ret = 0;
  
    if(config_rx_index > 0)
    {
        printf("config_rx_index:%d\r\n",config_rx_index);
        if(user_config_rx_buff[0] != FRAME_START_FLAG)
        {
            clear_rx_buff(user_config_rx_buff,sizeof(user_config_rx_buff));
        }
    }
  
    for(position = 0;position < config_rx_index && config_rx_index > 1;position++)
    {
        if(user_config_rx_buff[position] == FRAME_START_FLAG)
        {
            data_length = user_config_rx_buff[position + 1];
          
            printf("data_length:%d\r\n",data_length);
              
            if((data_length + 2) <= config_rx_index)
            {
                if(user_config_rx_buff[position + data_length + 1] == FRAME_STOP_FLAG)
                {
                    printf("get frame data complete\r\n");
                  
                    func = user_config_rx_buff[position + 2];
                  
                    if(!frame_check(user_config_rx_buff + position))
                    {
                        //checksum right
                        printf("checksum right\r\n");
                      
                        if(func == START_USER_CONFIG)
                        {
                            flash_info.is_start_config = 1;
                            flash_info.is_need_earse = 1;
                            flash_info.write_patition = partition0;
                          
                            //user_config_response(func,CMD_RES_SUCCESS);
                            goto success;
                        }
                        else if(func == STOP_USER_CONFIG)
                        {
                            flash_info.is_start_config = 0;
                            flash_info.is_need_earse = 0;
                            flash_info.write_patition = partition0;
                          
                            //user_config_response(func,CMD_RES_SUCCESS);
                            goto success;
                        }
                        else if(func == WRITE_USER_CONFIG)
                        {
                            pconfig = mymalloc(sizeof(user_config_t));
                            if(pconfig == NULL)
                            {
                                //clear_rx_buff(user_config_rx_buff,sizeof(user_config_rx_buff));
                                printf("get_user_config_info malloc fail\r\n");
                                //user_config_response(func,CMD_RES_FAIL);
                                goto error;
                            }
                            pconfig->flag = 1;
                            pconfig->slave_addr = user_config_rx_buff[position + 4];
                            pconfig->fanc_code = user_config_rx_buff[position + 5];
                            pconfig->start_addr = user_config_rx_buff[position + 6];
                            pconfig->length = user_config_rx_buff[position + 7];
                            pconfig->timeinterval = user_config_rx_buff[position + 8];
                            pconfig->timeout = user_config_rx_buff[position + 9];
                            strncpy(pconfig->device_id,(char *)(user_config_rx_buff + position + 10),sizeof(pconfig->device_id));
                            strncpy(pconfig->key.string_key,(char *)(user_config_rx_buff + position + 10 + sizeof(pconfig->device_id)),sizeof(pconfig->key.string_key));
                            
                            pos = position + 10 + sizeof(pconfig->device_id) + sizeof(pconfig->key.string_key);
                            for(i = 0;i < MAX_KEY_NUM;i++)
                            {
                                pconfig->division[i] = (uint16_t)user_config_rx_buff[pos + 2 * i] << 8 | user_config_rx_buff[pos + 2 * i + 1];
                                if(pconfig->division[i] == 0)
                                {
                                    pconfig->division[i] = 1;
                                }
                            }
                            
                            print_config(pconfig,"modbus config",0);
                            
                            clear_rx_buff(user_config_rx_buff,sizeof(user_config_rx_buff));
                            printf("postion:%d,index:%d\r\n",position,config_rx_index);
                            
                            if(flash_info.is_start_config == 0)
                            {
                                //没有发送开始命令
                                printf("not get start cmd\r\n");
                                goto error;
                            }
                            else
                            {
                                //write user config
                                if(flash_info.is_need_earse == 1)
                                {
                                    user_flash_page_earse();
                                    flash_info.is_need_earse = 0;
                                }
                                
                                if(flash_info.write_patition < max_partition)
                                {
                                    ret = write_user_config(pconfig,flash_info.write_patition);
                                    if(ret == 0)
                                    {
                                        flash_info.write_patition += 1;        
                                    }
                                    else
                                    {
                                        goto error;
                                    }                                                                     
                                }
                                else
                                {
                                    goto error;
                                }

                            }
                            
                            goto success;
                        }                      
                          
                    }
                    else
                    {
                        printf("checksum error\r\n");
                        goto error;
                    }
                }
            }
        }            
    }
    
    
    if(config_rx_index >= USER_CONFIG_BUFF_SIZE)
    {
        printf("config buff overflow\r\n");
        clear_rx_buff(user_config_rx_buff,sizeof(user_config_rx_buff));
    }
      
    if(pconfig != NULL)
    {
        myfree(pconfig);
    }
    
    return;
    
success:
    if(pconfig != NULL)
    {
        myfree(pconfig);
    }
    clear_rx_buff(user_config_rx_buff,sizeof(user_config_rx_buff));
    user_config_response(func,CMD_RES_SUCCESS);
    
error:
    
    if(pconfig != NULL)
    {
        myfree(pconfig);
    }
    clear_rx_buff(user_config_rx_buff,sizeof(user_config_rx_buff));
    user_config_response(func,CMD_RES_FAIL);
    
}

void clear_rx_buff(uint8_t *buff,uint8_t size)
{
    if(buff == NULL || size == 0)
    {
        return;
    }
    memset(buff,0,size);
    config_rx_index = 0;
}

uint16_t calculate_checksum(const uint8_t *buff)
{
    uint16_t checksum = 0;
    uint8_t data_length = 0;
    uint8_t i = 0;
  
    if(buff == NULL)
    {
        return 0;
    }
  
    data_length = buff[1];
  
    for(i = 0;i < (data_length - 2);i++)
    {
        checksum += buff[1 + i];
    } 
    
    return checksum;
}

uint8_t frame_check(const uint8_t *buff)
{
    uint16_t checksum = 0;
    uint8_t data_length = 0;
  
    if(buff == NULL)
    {
        return 1;
    }
  
    data_length = buff[1];

  
    checksum = calculate_checksum(buff);
    
    if(checksum != ((uint16_t)buff[data_length - 1] << 8 | buff[data_length]))
    {
        return 2;
    }
    
    return 0;
}


uint8_t user_config_uart_sendbytes(const uint8_t *buff,uint8_t length)
{
    if(buff == NULL || length == 0)
    {
        return 1;
    }
    while(length--)
    {
        Usart_SendOneByte(USER_CONFIG_USART,*buff++);
    }
    return 0;
}

uint8_t user_config_response(uint8_t func,uint8_t state)
{
    uint8_t buff[6] = {0x2A,0x03,0x00,0x00,0x00,0x23};
    uint16_t checksum = 0;
    
    if(func >= CONFIG_MAX_NUM || state > CMD_RES_MAX_NUM)
    {
        return 1;
    }
    
    if(state == CMD_RES_SUCCESS)
    {
        buff[2] = func;
    }
    else
    {
        buff[2] = func + 0x80;
    }
    
    checksum = calculate_checksum(buff);
    
    buff[3] = (checksum >> 8) & 0xFF;    
    buff[4] = checksum & 0xFF;
    
    
    user_config_uart_sendbytes(buff,sizeof(buff));
    
    return 0;
    
    
}

//keytpe 0:keystring 1:all keys
void print_config(user_config_t *pconfig,char *name,uint8_t keytype)
{
    uint8_t i = 0;
    printf("%s:\r\n",name);
    printf("slave:%d  func_code:%d\r\n",pconfig->slave_addr,pconfig->fanc_code);  
    printf("start_add:%d  length:%d\r\n",pconfig->start_addr,pconfig->length);
    printf("interval:%d  timeout:%d\r\n",pconfig->timeinterval,pconfig->timeout);
    printf("device id:%s\r\n",pconfig->device_id);  
    if(keytype == 0)
    {
        printf("key:%s\r\n",pconfig->key.string_key);
    }
    else
    {
        for(i = 0;i < pconfig->key_num;i++)
        {
            printf("key%d:%s  ",i,pconfig->key.keys[i]);
        }
        printf("\r\n");
    }
    
    for(i = 0;i < pconfig->key_num;i++)
    {
        printf("div%d:%d  ",i,pconfig->division[i]);
    }
    printf("\r\n");
    

}


void user_config_usart_handler(void)
{
    //printf("come in\r\n");

    if(USART_GetITStatus(USER_CONFIG_USART, USART_IT_RXNE) != RESET)
    {          
        if(config_rx_index < USER_CONFIG_BUFF_SIZE)
        {
            user_config_rx_buff[config_rx_index++] = USART_ReceiveData(USER_CONFIG_USART); 
        }
      
        USART_ClearITPendingBit(USER_CONFIG_USART, USART_IT_RXNE);  
    }
    else if(USART_GetITStatus(USER_CONFIG_USART, USART_IT_TXE) != RESET)
    {
        USART_ClearITPendingBit(USER_CONFIG_USART, USART_IT_TXE);  
    }

}






