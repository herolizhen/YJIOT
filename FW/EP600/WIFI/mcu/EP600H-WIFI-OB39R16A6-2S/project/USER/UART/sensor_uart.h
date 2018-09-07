#ifndef __SENSOR_UART_H__
#define __SENSOR_UART_H__


#define SENSOR_DATA_LENGTH   32
#define SENSOR_DATA_MAX_LENGTH   32
#define SENSOR_MAX_BUFF_LENGTH  32


void UART1_TX(unsigned char n_temp0);
void init_UART1(void);

void clear_sensor_uart_buff(void);
void Sensor_Uart_Sendbytes(const unsigned char *sendbuff,unsigned char sendnum);







#endif