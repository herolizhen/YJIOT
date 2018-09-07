#include "stdio.h"
#include "ucos_ii.h"
#include "user_L506.h"
#include "user_usart.h"
#include "L506.h"


extern void usart2_config(USART_TypeDef* USARTx, uint32_t BaudRate);

extern uint8_t mqtt_init_step;

extern uint8_t is_need_updata_token;

uint16_t uart_L506_rx_index;
char uart_L506_rx_buff[UART_L506_RX_BUFF_SIZE];


void uart_L506_task(void *para)
{
    //uint8_t result;
   
    usart2_config(USART2,115200);
    L506_PowerKey_Pin_Init();
    L506_PowerKey_On();
  
    //uint32_t count = 0;
    //uint8_t led_state = 0;
  
    //mqtt_init_step = MQTT_MAX_STEP;
  
    //printf("size of uint32:%d,size of long:%d\r\n",sizeof(uint32_t),sizeof(long));
  
    while(1)
    {
        
      
        if(is_need_updata_token == 1)
        {
            L506_Device_Token_auth();
        }
        
        L506_get_mqtt_message();
        L506_wait_response();
        parse_L506_cmd_result();
        L506_http_loop();
      
        L506_Upload_Data();
      
        OSTimeDlyHMSM(0,0,0,5);;   
        
//        count += 1;
//        
//        if(count % 200 == 0)
//        {
//            L506_fogcloud_init_and_check();
//          
//            if(led_state)
//            {
//                GPIO_ResetBits(GPIOC, GPIO_Pin_13);
//            }
//            else
//            {
//                GPIO_SetBits(GPIOC, GPIO_Pin_13);
//            }
//            
//            led_state = !led_state;
//	
//            printf("FreeHeapSize:%d\r\n",xPortGetFreeHeapSize());        
//        }
        
    }


}


uint8_t uart_L506_sendbytes(const uint8_t *buff,uint16_t length)
{
    return Usart_SendBytes(USART2,buff,length);
}


