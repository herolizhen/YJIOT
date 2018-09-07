#ifndef __USER_UART_DATA_PROCESS_H__
#define __USER_UART_DATA_PROCESS_H__

#include "mico.h"
#include "user_stack.h"

#define user_uart_data_process_log(M, ...) custom_log("UART_DATA_PROCESS", M, ##__VA_ARGS__)
#define user_uart_data_process_log_trace() custom_log_trace("UART_DATA_PROCESS")

#define UART_DATA_START          "AT+"
#define UART_DATA_STOP           "\r\n"

#define DATA_CMD                 "DATA:"
#define EASYLINK_CMD             "EASYLINK"
#define EARSE_EASYLINK_CMD       "EARSE-EASYLINK"
#define MAC_CMD                  "MAC"

#define MODBUS_DEVS_MAX_NUMS     8

#define USE_MODBOS_DEVICES

#define MAX_OP_COILS_NUM  16
#define MAX_OP_REGISTERS_NUM  16

typedef struct{
  
  uint8_t num;
  uint8_t is_activate;
  uint8_t is_sub;
  char device_id[40];
  char devicepw[8];          //…Ë±∏√‹¬Î
  char device_mac[16];

}device_t;

typedef struct{

  uint8_t dev_nums;
  uint8_t is_all_devs_activate;
  uint8_t is_all_devs_sub;
  device_t *devices[MODBUS_DEVS_MAX_NUMS];

}modbus_devs_t;

typedef struct{

  uint8_t *data_buff;
  uint8_t length;

}wifi_uart_rx_msg_t;

typedef struct{

  uint8_t func;
  uint8_t slave;
  uint16_t addr;
  uint8_t quantity;
  uint16_t *databuff;

}wifi_to_mcu_cmd_t;

uint8_t user_uart_rb_initialize(void);
uint8_t user_uart_recv_available(void);
uint8_t user_uart_read(void);

void empty_rx_buff(uint8_t *rx_buff,uint16_t *index);
void user_uart_data_process_thread(mico_thread_arg_t arg);

OSStatus modbus_devices_activate(device_t *dev);
uint8_t calculate_check_sum(uint8_t *data_buff,uint8_t length,uint16_t *checksum);
//uint8_t wifi_send_data_to_mcu_event(wifi_to_mcu_cmd_t *wifi_to_mcu_cmd);
uint8_t wifi_send_data_to_mcu_event(wifi_to_mcu_cmd_t *wifi_to_mcu_cmd,uint8_t *user_buff,uint8_t max_length,uint8_t *buff_length);

void uart_printf_array(char *name,uint8_t *databuff,uint8_t length);

uint8_t push_modbus_device_real_data_to_queue(uint8_t *databuff,uint8_t length);


#endif
