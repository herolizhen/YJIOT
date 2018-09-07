#include "FreeRTOS.h"
#include "task.h"
#include "user_sim7600.h"
#include "usart.h"
#include "sim7600.h"

extern void usart2_config(USART_TypeDef* USARTx, uint32_t BaudRate);

extern uint8_t mqtt_init_step;

uint16_t uart_sim7600_rx_index;
char uart_sim7600_rx_buff[UART_SIM7600_RX_BUFF_SIZE];


void uart_sim7600_task(void *para)
{
    //uint8_t result;
   
    usart2_config(USART2,115200);
    SIM7600_PowerKey_Pin_Init();
    SIM7600_PowerKey_On();
  
    mqtt_init_step = MQTT_MAX_STEP;
  
    while(1)
    {
        SIM7600_fogcloud_init_and_check();
      
        SIM7600_wait_response();
        parse_SIM7600_cmd_result();
        SIM7600_http_loop();
      
        SIM7600_Upload_Data();
      
        vTaskDelay(10);   
        
    }


}


uint8_t uart_sim7600_sendbytes(const uint8_t *buff,uint16_t length)
{
    return Usart_SendBytes(USART2,buff,length);
}


