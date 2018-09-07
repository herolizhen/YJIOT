#ifndef __USER_USART_WIFI_H__
#define __USER_USART_WIFI_H__


#include "stm32f10x.h"
#include "user_debug.h"

#define WIFI_UART_LOG(M,...)  custom_log("WIFI", M, ##__VA_ARGS__)


#define WIFI_USART    USART2


#define WIFI_RX_BUFF_SIZE   200

//#define WIFI_UART_START     "AT+"
//#define WIFI_UART_STOP      "\r\n"

//#define DATA_CMD                 "DATA:"
//#define SLAVE               "SLAVE"
//#define EASYLINK_CMD             "EASYLINK"
//#define EARSE_EASYLINK_CMD       "EARSE-EASYLINK"
//#define MAC_CMD                  "MAC"
//#define SLAVES_INFO_CMD          "SLAVES-INFO"

//#define WR_CMD      "wr"
//#define RD_CMD      "rd"


//#define OBJ_COIL     "coil"
//#define OBJ_REG      "reg"

#define MAX_WR_COILS    16
#define MAX_WR_REGS     5


enum WIFI_CMD{

  wifi_wr_cmd = 1,
  wifi_rd_cmd = 2

};

enum obj_type{

  obj_coil = 1,
  obj_reg  = 2

};


typedef struct{

  //uint8_t id;
  uint8_t func;
  uint8_t *databuff;
  uint8_t length;

}wifi_data_msg_t;

typedef struct{

  uint8_t slave;
  uint8_t func;
  uint16_t addr;
  uint8_t quantity;

}wifi_request_t;


enum wifi_send_data_result{

  WIFI_USART_SUCCESS       = 0,
  WIFI_USART_PARA_ERR      = 1,
  WIFI_USART_TIMEOUT       = 2,
  WIFI_USART_GET_MSG_FAIL  = 3,
  WIFI_USART_FUNC_ERR      = 4,
  WIFI_USART_SLAVE_ERR     = 5

};




extern uint8_t wifi_usart_rx_index;
extern uint8_t wifi_usart_rx_buff[WIFI_RX_BUFF_SIZE];

uint8_t WIFI_USART_RB_Initialize(void);
void wifi_usart_begin(void);
uint8_t wifi_usart_recv_available(void);
uint8_t wifi_usart_read(void);


uint8_t wifi_usart_sendbytes(uint8_t *buff,uint8_t length);

uint8_t wifi_usart_recv_handler(void);
void wifi_usart_handler(void);

void Task_usart_wifi(void *p_arg);
void empty_rx_buff(char *rx_buff,uint8_t *index);

uint8_t wifi_usart_send_data_event(const uint8_t *data_buff,uint8_t length,uint8_t is_sub_device,uint8_t *res_buff,uint8_t size);

void Task_wifi_request(void *p_arg);

uint8_t send_response_data_to_wifi(wifi_request_t *wif_request,const uint16_t *u16_data_buff,uint8_t u16_data_length);



void uart_printf_array(char *name,uint8_t *databuff,uint8_t length);


#endif




