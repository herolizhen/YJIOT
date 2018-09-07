#ifndef __USER_MODBUS_H__
#define __USER_MODBUS_H__

#include "stdint.h"
#include "stm32f10x.h"


#define MODBUS_USART  USART1


#define RS485_CONTROL_GPIO_CLK        RCC_APB2Periph_GPIOC
#define RS485_CONTROL_PORT            GPIOC
#define RS485_CONTROL_PIN             GPIO_Pin_13

#define RS485_CONTROL_PIN_HIGH()         GPIO_SetBits(RS485_CONTROL_PORT,RS485_CONTROL_PIN); 
#define RS485_CONTROL_PIN_LOW()          GPIO_ResetBits(RS485_CONTROL_PORT,RS485_CONTROL_PIN); 

void rs485_control_pin_config(void);
uint8_t MODBUS_RS485_SendBytes( USART_TypeDef * pUSARTx,const uint8_t *buff,uint8_t length);

void moubus_loop(void);
//uint8_t send_data_to_wifi(const uint16_t *data_buff,uint8_t which_config);
uint8_t calculate_check_sum(uint8_t *data_buff,uint8_t length,uint16_t *checksum);
uint8_t send_data_to_buffer(uint8_t *uart_buff,const uint16_t *data_buff,uint8_t which_config,uint8_t *frame_length);
void Task_modbus(void *p_arg);

void modbus_usart_handler(void);





#endif

