#include "stdio.h"
#include "ucos_ii.h"
#include "user_sim7600.h"
#include "user_usart.h"
#include "sim7600.h"

/*
extern void usart2_config(USART_TypeDef* USARTx, uint32_t BaudRate);

extern uint8_t mqtt_init_step;

extern uint8_t is_need_updata_token;

uint16_t uart_L506_rx_index;
char uart_L506_rx_buff[UART_L506_RX_BUFF_SIZE];


void uart_L506_task(void *para)
{
    //uint8_t result;
   
    usart2_config(USART2,115200);
    sim7600_powerkey_pin_init();
    sim7600_powerkey_on();
  
    //uint32_t count = 0;
  
    while(1)
    {
        
      
//        if(is_need_updata_token == 1)
//        {
//            L506_Device_Token_auth();
//        }
        
//        sim7600_get_mqtt_message();
//        sim7600_wait_response();
//        parse_sim7600_cmd_result();
//        sim7600_http_loop();
      
        //L506_Upload_Data();
      
        OSTimeDlyHMSM(0,0,0,5);;   
        
//        count += 1;        
        
    }


}


uint8_t uart_L506_sendbytes(const uint8_t *buff,uint16_t length)
{
    return Usart_SendBytes(USART2,buff,length);
}

*/


