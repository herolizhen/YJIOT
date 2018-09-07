#include "stdio.h"
#include "FreeRTOS.h"
#include "task.h"
#include "user_sim7600.h"
#include "usart.h"
#include "sim7600.h"

extern void usart2_config(USART_TypeDef* USARTx, uint32_t BaudRate);

extern uint8_t mqtt_init_step;

extern uint8_t is_need_updata_token;

uint16_t uart_sim7600_rx_index;
char uart_sim7600_rx_buff[UART_SIM7600_RX_BUFF_SIZE];


void uart_sim7600_task(void *para)
{
    //uint8_t result;
   
    usart2_config(USART2,115200);
    SIM7600_PowerKey_Pin_Init();
    SIM7600_PowerKey_On();
  
    uint32_t count = 0;
    uint8_t led_state = 0;
  
    //mqtt_init_step = MQTT_MAX_STEP;
  
    //printf("size of uint32:%d,size of long:%d\r\n",sizeof(uint32_t),sizeof(long));
  
    while(1)
    {
        
      
        if(is_need_updata_token == 1)
        {
            SIM7600_Device_Token_auth();
        }
        
        SIM7600_get_mqtt_message();
        SIM7600_wait_response();
        parse_SIM7600_cmd_result();
        SIM7600_http_loop();
      
        SIM7600_Upload_Data();
      
        vTaskDelay(5);   
        
        count += 1;
        
        if(count % 200 == 0)
        {
            SIM7600_fogcloud_init_and_check();
          
            if(led_state)
            {
                GPIO_ResetBits(GPIOC, GPIO_Pin_13);
            }
            else
            {
                GPIO_SetBits(GPIOC, GPIO_Pin_13);
            }
            
            led_state = !led_state;
	
            printf("FreeHeapSize:%d\r\n",xPortGetFreeHeapSize());        
        }
        
    }


}


uint8_t uart_sim7600_sendbytes(const uint8_t *buff,uint16_t length)
{
    return Usart_SendBytes(USART2,buff,length);
}


