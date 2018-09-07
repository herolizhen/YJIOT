#include "string.h"
#include "user_usart.h"
#include "user_usart2.h"
#include "user_sim7600_task.h"
#include "ringbuffer.h"
#include "cJSON.h"
#include "malloc.h"
#include "ucos_ii.h" 
#include "modbus_master.h"
#include "user_usart.h"
#include "SIM7600.h"


extern SIM7600_Cmd_Typedef SIM7600_cmd_info;
extern uint8_t is_module_powered;

extern uint8_t is_need_updata_token;

volatile uint16_t uart_sim7600_rx_index;
char uart_sim7600_rx_buff[UART_SIM7600_RX_BUFF_SIZE];


RingBuffer  m_SIM7600_Uasrt_RingBuff;



uint8_t sim7600_usart_rb_initialize(void)
{
	/*初始化ringbuffer相关的配置*/
	rbInitialize(&m_SIM7600_Uasrt_RingBuff, (uint8_t *)uart_sim7600_rx_buff, sizeof(uart_sim7600_rx_buff));
	return 1 ;
}

void sim7600_usart_begin(void)
{  
	 //初始化环形队列
	 sim7600_usart_rb_initialize();
  
   
}

uint8_t sim7600_usart_recv_available(void)
{
		if(m_SIM7600_Uasrt_RingBuff.flagOverflow == 1)
		{
			rbClear(&m_SIM7600_Uasrt_RingBuff);
		}
	  return !rbIsEmpty(&m_SIM7600_Uasrt_RingBuff);
}

uint8_t sim7600_usart_read(void)
{
	uint8_t cur =0xff;
	if( !rbIsEmpty(&m_SIM7600_Uasrt_RingBuff))
	{
		  cur = rbPop(&m_SIM7600_Uasrt_RingBuff);
	}
	return cur;
}

uint8_t sim7600_usart_sendbytes(uint8_t *buff,uint8_t length)
{
    Usart_SendBytes(USART3,buff,length);
  
    return 0;
}

uint8_t sim7600_usart_recv_handler(void)
{
	 uint8_t byte;
  
   byte = USART_ReceiveData(SIM7600_USART); 
   rbPush(&m_SIM7600_Uasrt_RingBuff, (uint8_t)(byte & (uint8_t)0xFF));
  
   return 0;
	 
}


#define RX_BUFF_SIZE   600
void sim7600_task(void *p_arg)
{
    //INT8U err;
    //uint8_t i,j = 0;
    uint16_t index = 0;
    //char recv_buff[RX_BUFF_SIZE] = {0};  
    char *recv_buff = NULL;
    //uint32_t count = 0;
  
    
    //usart3_config(USART3,115200);
  
    usart2_config(SIM7600_USART,115200);
  
    recv_buff = mymalloc(RX_BUFF_SIZE);
    if(recv_buff == NULL)
    {
        printf("SIM7600_task malloc fail,exit\r\n");
        return;
    }  

    memset(recv_buff,0,RX_BUFF_SIZE);
    sim7600_usart_begin(); 
    
//    SIM7600_Reset_Pin_Init();
//    SIM7600_Reset_Pin_High();
    sim7600_powerkey_pin_init();
    sim7600_powerkey_on();
//    goto module_power_on;

//restart:    
//    SIM7600_Restart();     
//  
//module_power_on:  
//    memset(recv_buff,0,RX_BUFF_SIZE);
//    index = 0;
    
    while(1)
    {
        while(sim7600_usart_recv_available())
        {
            if(index < RX_BUFF_SIZE)
            {
                recv_buff[index++] = sim7600_usart_read();
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
        
        sim7600_get_mqtt_message(recv_buff,&index);
        
        sim7600_event_scan();
        
        sim7600_wait_response(recv_buff,&index);
        parse_sim7600_cmd_result(recv_buff,&index);
        sim7600_mqtt_loop();
        sim7600_http_loop();

        
        
        if(index >= RX_BUFF_SIZE)
        {
            printf("SIM7600_task recv data too long\r\n");
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
//            SIM7600_fogcloud_init_and_check();
//            //printf("SIM7600 task heart\r\n");
//            if((SIM7600_cmd_info.error_times >= 20 || SIM7600_cmd_info.timeout_times >= 3))
//            {
//                //重启SIM7600       
//                goto restart;
//        
//            }
//        }
      
    }
}





uint8_t uart_sim7600_sendbytes(const uint8_t *buff,uint16_t length)
{
    return Usart_SendBytes(SIM7600_USART,buff,length);
}


