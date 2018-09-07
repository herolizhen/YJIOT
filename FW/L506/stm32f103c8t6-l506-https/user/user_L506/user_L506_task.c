#include "string.h"
#include "user_usart.h"
#include "user_usart3.h"
#include "user_L506_task.h"
#include "ringbuffer.h"
#include "cJSON.h"
#include "malloc.h"
#include "ucos_ii.h" 
#include "modbus_master.h"
#include "user_usart.h"
#include "L506.h"

extern L506_Cmd_Typedef L506_cmd_info;
extern uint8_t is_module_powered;

extern uint8_t is_need_updata_token;

volatile uint16_t uart_L506_rx_index;
char uart_L506_rx_buff[UART_L506_RX_BUFF_SIZE];


RingBuffer  m_L506_Uasrt_RingBuff;



uint8_t L506_USART_RB_Initialize(void)
{
	/*初始化ringbuffer相关的配置*/
	rbInitialize(&m_L506_Uasrt_RingBuff, (uint8_t *)uart_L506_rx_buff, sizeof(uart_L506_rx_buff));
	return 1 ;
}

void L506_usart_begin(void)
{  
	 //初始化环形队列
	 L506_USART_RB_Initialize();
  
   
}

uint8_t L506_usart_recv_available(void)
{
		if(m_L506_Uasrt_RingBuff.flagOverflow == 1)
		{
			rbClear(&m_L506_Uasrt_RingBuff);
		}
	  return !rbIsEmpty(&m_L506_Uasrt_RingBuff);
}

uint8_t L506_usart_read(void)
{
	uint8_t cur =0xff;
	if( !rbIsEmpty(&m_L506_Uasrt_RingBuff))
	{
		  cur = rbPop(&m_L506_Uasrt_RingBuff);
	}
	return cur;
}

uint8_t L506_usart_sendbytes(uint8_t *buff,uint8_t length)
{
    Usart_SendBytes(USART3,buff,length);
  
    return 0;
}

uint8_t L506_usart_recv_handler(void)
{
	 uint8_t byte;
  
   byte = USART_ReceiveData(USART3); 
   rbPush(&m_L506_Uasrt_RingBuff, (uint8_t)(byte & (uint8_t)0xFF));
  
   return 0;
	 
}


#define RX_BUFF_SIZE   600
void L506_task(void *p_arg)
{
    //INT8U err;
    //uint8_t i,j = 0;
    uint16_t index = 0;
    //char recv_buff[RX_BUFF_SIZE] = {0};  
    char *recv_buff = NULL;
    //uint32_t count = 0;
  
    
    usart3_config(USART3,115200);
  
    recv_buff = mymalloc(RX_BUFF_SIZE);
    if(recv_buff == NULL)
    {
        printf("L506_task malloc fail,exit\r\n");
        return;
    }  

    memset(recv_buff,0,RX_BUFF_SIZE);
    L506_usart_begin(); 
    
//    L506_Reset_Pin_Init();
//    L506_Reset_Pin_High();
    L506_PowerKey_Pin_Init();
    L506_PowerKey_On();
//    goto module_power_on;

//restart:    
//    L506_Restart();     
//  
//module_power_on:  
//    memset(recv_buff,0,RX_BUFF_SIZE);
//    index = 0;
    
    while(1)
    {
        while(L506_usart_recv_available())
        {
            if(index < RX_BUFF_SIZE)
            {
                recv_buff[index++] = L506_usart_read();
                //刚上电时串口可能会收到0
                if(index == 1 && (recv_buff[0] == 0 || recv_buff[0] == '\r' || recv_buff[0] == '\n'))
                {
                    empty_rx_buff(recv_buff,&index);
                }
                
            }
            else
            {
                break;
            }
        }
        
        L506_get_mqtt_message(recv_buff,&index);
        
        L506_Event_Scan();
        
        L506_wait_response(recv_buff,&index);
        parse_L506_cmd_result(recv_buff,&index);
        L506_mqtt_loop();
        L506_http_loop();

        
        
        if(index >= RX_BUFF_SIZE)
        {
            printf("L506_task recv data too long\r\n");
            empty_rx_buff(recv_buff,&index);
        }
        
        if(is_module_powered == 0)
        {
            if(index != 0)
            {
                empty_rx_buff(recv_buff,&index);
            }
        }
      
        OSTimeDlyHMSM(0,0,0,2);
        
//        count += 1;
//        if(count % 1000 == 0)
//        {
//            L506_fogcloud_init_and_check();
//            //printf("L506 task heart\r\n");
//            if((L506_cmd_info.error_times >= 20 || L506_cmd_info.timeout_times >= 3))
//            {
//                //重启L506       
//                goto restart;
//        
//            }
//        }
      
    }
}





uint8_t uart_L506_sendbytes(const uint8_t *buff,uint16_t length)
{
    return Usart_SendBytes(USART3,buff,length);
}


