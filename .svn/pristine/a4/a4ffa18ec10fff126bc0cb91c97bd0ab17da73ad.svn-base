#include "string.h"
#include "user_usart.h"
#include "user_usart3.h"
#include "user_usart_wifi.h"
#include "ringbuffer.h"
#include "user_config.h"
#include "cJSON.h"
#include "malloc.h"
#include "ucos_ii.h" 
#include "modbus_master.h"
#include "app.h"
#include "user_modbus.h"
#include "user_config.h"


#define WIFI_USART_RES_MESSAGE_NUM  1
#define WIFI_REQUEST_MESSAGE_NUM 1
#define WAIT_WIFI_RES_MAX_TIME  1000

#define MOSBUS_PARA_ERROR   0xFF
#define MAX_READ_COILS_NUM  16
#define MAX_READ_REGISTERS_NUM  16

extern OS_EVENT *modbus_mutex;

//static wifi_data_t wifi_tx_data;
//static wifi_data_t wifi_res_data;
OS_EVENT *wifi_usart_tx_mutex;

OS_EVENT *wifi_usart_res_queue;
OS_EVENT *wifi_request_queue;
void *wifi_usart_res_msg[WIFI_USART_RES_MESSAGE_NUM];
void *wifi_request_msg[WIFI_REQUEST_MESSAGE_NUM];

uint8_t wifi_usart_rx_index;
uint8_t wifi_usart_rx_buff[WIFI_RX_BUFF_SIZE];

RingBuffer  m_Wifi_Uasrt_RingBuff;


extern user_configs_info_t user_configs_info;
extern uint16_t _u16TransmitBuffer[ku8MaxBufferSize]; 
extern uint16_t ku16MBResponseTimeout;
extern uint16_t _u16ResponseBuffer[ku8MaxBufferSize];  

extern user_configs_info_t user_configs_info;


uint8_t WIFI_USART_RB_Initialize(void)
{
	/*初始化ringbuffer相关的配置*/
	rbInitialize(&m_Wifi_Uasrt_RingBuff, wifi_usart_rx_buff, sizeof(wifi_usart_rx_buff));
	return 1 ;
}

void wifi_usart_begin(void)
{  
	 //初始化环形队列
	 WIFI_USART_RB_Initialize();
  
   
}

uint8_t wifi_usart_recv_available(void)
{
		if(m_Wifi_Uasrt_RingBuff.flagOverflow==1)
		{
			rbClear(&m_Wifi_Uasrt_RingBuff);
		}
	  return !rbIsEmpty(&m_Wifi_Uasrt_RingBuff);
}

uint8_t wifi_usart_read(void)
{
	uint8_t cur =0xff;
	if( !rbIsEmpty(&m_Wifi_Uasrt_RingBuff))
	{
		  cur = rbPop(&m_Wifi_Uasrt_RingBuff);
	}
	return cur;
}

uint8_t wifi_usart_sendbytes(uint8_t *buff,uint8_t length)
{
    if(buff == NULL || length <= 0)
    {
        return 1;
    }
    
    Usart_SendBytes(WIFI_USART,buff,length);
  
    return 0;
}

uint8_t wifi_usart_recv_handler(void)
{
	 uint8_t byte;
  
   byte = USART_ReceiveData(WIFI_USART); 
   rbPush(&m_Wifi_Uasrt_RingBuff, (uint8_t)(byte & (uint8_t)0xFF));
  
   return 0;
	 
}

void wifi_usart_handler(void)
{  
    if(USART_GetITStatus(WIFI_USART, USART_IT_RXNE) != RESET)
    {          
        wifi_usart_recv_handler();
      
        USART_ClearITPendingBit(WIFI_USART, USART_IT_RXNE);  
    }
    else if(USART_GetITStatus(WIFI_USART, USART_IT_TXE) != RESET)
    {
        USART_ClearITPendingBit(WIFI_USART, USART_IT_TXE);  
    }
}

void Task_usart_wifi(void *p_arg)
{
    INT8U err;
    uint8_t index = 0;
    char recv_buff[WIFI_RX_BUFF_SIZE] = {0};
//    uint8_t slave_addr = 0;
//    uint8_t cmd = 0;
//    uint8_t obj_type = 0;

    uint8_t length = 0;
    uint8_t frame_length = 0;
    
    wifi_data_msg_t *res_msg = NULL;
    wifi_data_msg_t *temp_res_msg = NULL;
    OS_EVENT *temp_queue;
       
    wifi_usart_tx_mutex = OSMutexCreate(WIFI_USART_TX_MUTEX_PRIO,&err);
    
    wifi_usart_res_queue = OSQCreate(&wifi_usart_res_msg[0],WIFI_USART_RES_MESSAGE_NUM);
    if(wifi_usart_res_queue == NULL)
    {
        WIFI_UART_LOG("create wifi_usart_res_queue fail");
        goto exit;
    }
    
    wifi_request_queue = OSQCreate(&wifi_request_msg[0],WIFI_REQUEST_MESSAGE_NUM);
    if(wifi_request_queue == NULL)
    {
        WIFI_UART_LOG("create wifi_request_queue fail");
        goto exit;
    }
    
    wifi_usart_begin();
    while(1)
    {
        if(wifi_usart_recv_available())
        {
            if(index < WIFI_RX_BUFF_SIZE)
            {
                recv_buff[index++] = wifi_usart_read();
                if(index == 1 && recv_buff[0] != 0x2A)
                {
                    empty_rx_buff(recv_buff,&index);
                    continue;
                }
            }
            
            if(index == 2)
            {
                length = recv_buff[1];
            }
            
            if(index < (length + 3))
            {
                if(index >= WIFI_RX_BUFF_SIZE)
                {
                    uart_printf_array("full_rx_buf",(uint8_t *)recv_buff,index);
                    WIFI_UART_LOG("recv_buff full,flush buff");
                    empty_rx_buff(recv_buff,&index);
                }
                continue;
            }
            else if(index > (length + 3))
            {
                empty_rx_buff(recv_buff,&index);
                continue;
            }
            else
            {
                if(recv_buff[index - 1] != 0x23)
                {
                    empty_rx_buff(recv_buff,&index);
                    continue;
                }
            }          
            
            frame_length = index;
                      
            res_msg = mymalloc(sizeof(wifi_data_msg_t));
            if(res_msg == NULL)
            {
                WIFI_UART_LOG("wifi usart malloc res_msg fail");
                goto malloc_fail;
            }
            
            res_msg->databuff = mymalloc(frame_length); 
            if(res_msg->databuff == NULL)
            {
                WIFI_UART_LOG("wifi usart malloc res_msg databuff fail");
                goto malloc_fail;
            }
            
            memcpy(res_msg->databuff,recv_buff,frame_length);
            
            res_msg->length = frame_length;
            res_msg->func = recv_buff[2];
            if(res_msg->func < 0x10)
            {
                temp_queue = wifi_usart_res_queue;
            }
            else
            {
                temp_queue = wifi_request_queue;
                //err = OSQPost(wifi_request_queue,res_msg);
            }
            
            
            if(is_queue_full(temp_queue) == QUEUE_FULL)
            {
                WIFI_UART_LOG("%s full,pop one msg",(temp_queue == wifi_request_queue) ? "wifi_request_queue" : "wifi_usart_res_queue");
                temp_res_msg = OSQPend(temp_queue,10,&err);
                if(err != OS_ERR_NONE)
                {
                    goto pop_msg_fail;
                }
                
                if(temp_res_msg->databuff != NULL)
                {
                    myfree(temp_res_msg->databuff);
                    temp_res_msg->databuff = NULL;
                }
            
                if(temp_res_msg != NULL)
                {
                    myfree(temp_res_msg);
                    temp_res_msg = NULL;
                }
            }
            
            err = OSQPost(temp_queue,res_msg);
            if(err != OS_ERR_NONE)
            {
                WIFI_UART_LOG("push msg to queue error");
                goto push_msg_error;
            }
            
            //uart_printf_array("get frame",(uint8_t *)recv_buff,index);
            
            empty_rx_buff(recv_buff,&index);
            continue;
            
            push_msg_error:
            
            pop_msg_fail:
            
            malloc_fail:
            if(res_msg->databuff != NULL)
            {
                myfree(res_msg->databuff);
                res_msg->databuff = NULL;
            }
            
            if(res_msg != NULL)
            {
                myfree(res_msg);
                res_msg = NULL;
            }
            
            empty_rx_buff(recv_buff,&index);
            WIFI_UART_LOG("deal one wifi usart msg fail");
            //延时等待其他线程把队列取出来
            OSTimeDlyHMSM(0,0,0,5);
       
            
        }
        else 
        {
            OSTimeDlyHMSM(0,0,0,1);
        }
        
        if(index >= WIFI_RX_BUFF_SIZE)
        {
            empty_rx_buff(recv_buff,&index);
        }
      
    }
    
exit:
    WIFI_UART_LOG("Task_usart_wifi exit");
    OSTaskDel(TASK_USART_WIFI_PRIO);
}



void empty_rx_buff(char *rx_buff,uint8_t *index)
{
    if(rx_buff == NULL)
    {
        return;
    }
    memset(rx_buff,0,strlen(rx_buff));
    *index = 0;
}


uint8_t wifi_usart_send_data_event(const uint8_t *data_buff,uint8_t length,uint8_t is_sub_device,uint8_t *res_buff,uint8_t size)
{
    INT8U err;
    uint8_t res = 0;
    wifi_data_msg_t *wifi_res_msg = NULL;
    uint8_t send_func = 0;
    uint8_t sub_device = 0;
  
    if(data_buff == NULL || length == 0)
    {
        res = WIFI_USART_PARA_ERR;
        goto exit;
    }
    
    OSMutexPend(modbus_mutex,0,&err); 
    
    send_func = data_buff[2];
    if(is_sub_device == 1)
    {
        sub_device = data_buff[3];
    }
    
    
    wifi_usart_sendbytes((unsigned char *)data_buff,length);
    
    wifi_res_msg = OSQPend(wifi_usart_res_queue,WAIT_WIFI_RES_MAX_TIME,&err);
    if(err != OS_ERR_NONE)
    {
        if(err == OS_ERR_TIMEOUT)
        {
            WIFI_UART_LOG("wifi usart send data timeout");
            res = WIFI_USART_TIMEOUT;
        }
        else
        {
            WIFI_UART_LOG("push from wifi res queue err:%d",err);
            res = err;
        }

        goto exit;
    }
    
    if(wifi_res_msg == NULL)
    {
        WIFI_UART_LOG("get msg from wifi res queue fail");
        res = WIFI_USART_GET_MSG_FAIL;
        goto exit;
    }
    
    if(send_func != wifi_res_msg->func)
    {
        WIFI_UART_LOG("msg func error");
        res = WIFI_USART_FUNC_ERR;
        goto exit;
    }
    
    if(is_sub_device == 1)
    {
        if(sub_device != wifi_res_msg->databuff[3])
        {
            WIFI_UART_LOG("msg sub device num error");
            res = WIFI_USART_SLAVE_ERR;
            goto exit;
        }
    }
    
    res = WIFI_USART_SUCCESS;
        
exit:
    
    if(wifi_res_msg != NULL)
    {
        if(wifi_res_msg->databuff != NULL)
        {
            myfree(wifi_res_msg->databuff);
            wifi_res_msg->databuff = NULL;
        }        
        myfree(wifi_res_msg);
        wifi_res_msg = NULL;
    }
    
    OSMutexPost(modbus_mutex); 
    
    return res;
}

void Task_wifi_request(void *p_arg)
{
    INT8U err;
    uint8_t res = 0;
    //uint8_t result = 0;
    //uint8_t frame_length = 0;
    
    wifi_data_msg_t *wifi_data_msg = NULL;
    uint8_t func = 0;
    //uint8_t sub_func = 0;
    uint8_t slave = 0;
    uint8_t slave_num = 0;
    uint16_t address = 0;
    uint8_t quantity = 0;
    uint8_t u16_tx_buff_length = 9;
    uint8_t i = 0;
    wifi_request_t wifi_request;
    uint16_t checksum = 0;
    uint16_t temp = 0;
  
    while(1)
    {
        if(!is_queue_empty(wifi_request_queue))
        {
            wifi_data_msg = OSQPend(wifi_request_queue,10,&err);
            if(err != OS_ERR_NONE)
            {
                WIFI_UART_LOG("pop one msg from wifi request queue error:%d",err);
                goto delay;
            }
            
            if(wifi_data_msg == NULL)
            {
                WIFI_UART_LOG("wifi request msg NULL,error");
                goto delay;
            }
            
            //校验
            res = calculate_check_sum(wifi_data_msg->databuff + 1,wifi_data_msg->databuff[1] - 1,&checksum);
            if(res != 0)
            {
                WIFI_UART_LOG("calculate_check_sum fail,res=%d",res);
                goto free_wifi_data_msg;
            }
            
            
            uart_printf_array("wifi_request_msg",wifi_data_msg->databuff,wifi_data_msg->length);
            
            temp = (uint16_t)wifi_data_msg->databuff[wifi_data_msg->length - 2] << 8 | wifi_data_msg->databuff[wifi_data_msg->length - 3];
            
            WIFI_UART_LOG("checksum:0x%04x,temp:0x%04x",checksum,temp);
            //WIFI_UART_LOG("high byte:");
            
            if(checksum != temp)
            {
                WIFI_UART_LOG("check sum error");
                goto free_wifi_data_msg;
            }
            
            
            func = wifi_data_msg->databuff[2];
            
            wifi_request.func = func;
            
            OSMutexPend(modbus_mutex,0,&err);      
            
            if(func < 0x10)
            {
                WIFI_UART_LOG("func error,func = %d",func);
                //goto loop_contiune;
            }
            else if(func < 0x13)
            {
                slave_num = wifi_data_msg->databuff[3];
                if(slave_num > user_configs_info.config_num)
                {
                    WIFI_UART_LOG("slave_num = %d,error",slave_num);
                    goto slave_num_error;
                }
                slave = (uint8_t)(user_configs_info.user_configs[slave_num]->slave_addr & 0xFF);
                address = (uint16_t)wifi_data_msg->databuff[4] << 8 | wifi_data_msg->databuff[5];
                quantity = wifi_data_msg->databuff[6];
              
                wifi_request.slave = slave;               
                wifi_request.addr = address;
                wifi_request.quantity = quantity;
              
                if(func == 0x10)    //read coil
                {
                    if(quantity > MAX_READ_COILS_NUM)
                    {
                        WIFI_UART_LOG("quantity > MAX_READ_COILS_NUM");
                    }
                    else
                    {
                        res = ModbusMaster_readCoils(slave,address,quantity);
                        if(res != 0)
                        {
                            WIFI_UART_LOG("0x10 fail,res=%d",res);
                        }
                        else
                        {
                            res = send_response_data_to_wifi(&wifi_request,_u16ResponseBuffer,1);
                        }
                    }
                }
                else if(func == 0x11)     //write coil
                {
                    if(quantity > ku8MaxBufferSize)
                    {
                        WIFI_UART_LOG("0x11 quantity > ku8MaxBufferSize");
                    }
                    else
                    {
                        u16_tx_buff_length = (quantity % 16) ? (quantity / 16 + 1) : (quantity / 16);
                        for(i = 0;i < u16_tx_buff_length;i++)
                        {
                            //write coils时，_u16TransmitBuffer数组中的16位数据bit0-bit15分别代表线圈0-15，无需调换高低字节顺序，
                            //因为在ModbusMaster_ModbusMasterTransaction函数中发送数据时，会先发送_u16TransmitBuffer中数据的低字节
                            _u16TransmitBuffer[i] = (uint16_t)wifi_data_msg->databuff[7 + i * 2] << 8 | wifi_data_msg->databuff[8 + i * 2];
                        }
                        
                        if(quantity == 0)
                        {
                            WIFI_UART_LOG("0x11 coil quantity == 0");
                        }
                        else if(quantity == 1)
                        {
                            if(_u16TransmitBuffer[0] == 0xFF00)
                            {
                                res = ModbusMaster_writeSingleCoil(slave,address,1);
                            }
                            else if(_u16TransmitBuffer[0] == 0x0000)
                            {
                                res = ModbusMaster_writeSingleCoil(slave,address,1);
                            }
                            else
                            {
                                res = MOSBUS_PARA_ERROR;
                            }
                        }
                        else 
                        {
                            res = ModbusMaster_writeMultipleCoils(slave,address,quantity);
                        }
                        
                        if(res != 0)
                        {
                            WIFI_UART_LOG("0x11 func fail,res = %d",res);
                        }
                        else
                        {
                            res = send_response_data_to_wifi(&wifi_request,NULL,0);
                        }
                    }

                } 
                else if(func == 0x12)   //read register
                {
                    if(quantity > MAX_READ_REGISTERS_NUM)
                    {
                        WIFI_UART_LOG("quantity > MAX_READ_REGISTERS_NUM");
                    }
                    else 
                    {
                        WIFI_UART_LOG("slave:%d,address:%d,quantity:%d",slave,address,quantity);
                        res = ModbusMaster_readInputRegisters(slave,address,quantity);
                        if(res != 0)
                        {
                            WIFI_UART_LOG("0x12 fail,res=%d",res);
                        }
                        else 
                        {
                            res = send_response_data_to_wifi(&wifi_request,_u16ResponseBuffer,quantity);
                        }                       
                    }                   
                }
                else if(func == 0x13)
                {
                    if(quantity > ku8MaxBufferSize)
                    {
                        WIFI_UART_LOG("0x13 quantity > ku8MaxBufferSize");
                    }
                    else
                    {
                        for(i = 0;i < quantity;i++)
                        {
                            _u16TransmitBuffer[i] = (uint16_t)wifi_data_msg->databuff[7 + i * 2] << 8 | wifi_data_msg->databuff[8 + i * 2];
                        }
                        
                        if(quantity == 1)
                        {
                            res = ModbusMaster_writeSingleRegister(slave,address,_u16TransmitBuffer[0]);
                        }
                        else 
                        {
                            res = ModbusMaster_writeMultipleRegisters(slave,address,quantity);
                        }
                        
                        if(res != 0)
                        {
                            WIFI_UART_LOG("0x13 func fail,res = %d",res);
                        }
                        else 
                        {
                            res = send_response_data_to_wifi(&wifi_request,NULL,0);
                        }
                    }               
                }
            }
            else if(func == 0x14)   //wifi get modbus device num
            {
                res = send_response_data_to_wifi(&wifi_request,NULL,0);
            }
            
            slave_num_error:
            
            OSTimeDlyHMSM(0,0,0,300);   
            OSMutexPost(modbus_mutex);
            
            free_wifi_data_msg:

            if(wifi_data_msg->databuff != NULL)
            {
                myfree(wifi_data_msg->databuff);
                wifi_data_msg->databuff = NULL;
            }
            if(wifi_data_msg != NULL)
            {
                myfree(wifi_data_msg);
                wifi_data_msg = NULL;
            }
        }
        
        delay:
        OSTimeDlyHMSM(0,0,0,1);   
    }
}

#define SEND_BUFF_SIZE   (MAX_READ_REGISTERS_NUM * 2 + 20)
uint8_t send_response_data_to_wifi(wifi_request_t *wifi_request,const uint16_t *u16_data_buff,uint8_t u16_data_length)
{
    uint8_t *sendbuff = NULL;
    uint8_t res = 0;
    //uint8_t index = 0;
    uint8_t frame_length = 0;
    uint8_t i = 0;
    uint16_t check_sum = 0;
   
    if(wifi_request == NULL || u16_data_length > MAX_READ_REGISTERS_NUM)
    {
        WIFI_UART_LOG("para 1 error");
        res = 1;
        goto exit;
    }
    
    if(wifi_request->func < 0x14 && (wifi_request->slave == 0 || wifi_request->slave > user_configs_info.config_num))
    {
        WIFI_UART_LOG("salve num error");
        res = 2;
        goto exit;
    }
      
    sendbuff = mymalloc(SEND_BUFF_SIZE);
    memset(sendbuff,0,SEND_BUFF_SIZE);
    
    sendbuff[0] = 0x2A;
    if(wifi_request->func == 0x10 || wifi_request->func == 0x12)
    {
        if(u16_data_buff == NULL || u16_data_length == 0)
        {
            WIFI_UART_LOG("para 2 error");
            res = 3;
            goto exit;
        }
        frame_length = u16_data_length * 2 + 10;
        sendbuff[1] = frame_length - 3;
        sendbuff[2] = wifi_request->func;
        sendbuff[3] = wifi_request->slave;
        sendbuff[4] = (uint8_t)(wifi_request->addr >> 8);
        sendbuff[5] = (uint8_t)(wifi_request->addr & 0xFF);
        sendbuff[6] = u16_data_length;
        for(i = 0;i < u16_data_length;i++)
        {
            sendbuff[7 + i * 2] = (uint8_t)(u16_data_buff[i] >> 8);
            sendbuff[8 + i * 2] = (uint8_t)(u16_data_buff[i] & 0xFF);
        }
    }
    else if(wifi_request->func == 0x11 || wifi_request->func == 0x13)
    {
        frame_length = 0x0B;
        sendbuff[1] = 0x08;
        sendbuff[2] = wifi_request->func;
        sendbuff[3] = wifi_request->slave;
        sendbuff[4] = (uint8_t)(wifi_request->addr >> 8);
        sendbuff[5] = (uint8_t)(wifi_request->addr & 0xFF);
        sendbuff[6] = wifi_request->quantity;
        sendbuff[7] = 1;     
    }
    else if(wifi_request->func == 0x14)
    {
        sendbuff[1] = 0x04;
        sendbuff[2] = 0x14;
        sendbuff[3] = user_configs_info.config_num;
        frame_length = 7;
    }
    else
    {
        WIFI_UART_LOG("func error");
        res = 4;
        goto exit;
    }

    res = calculate_check_sum(sendbuff + 1,sendbuff[1] - 1,&check_sum);
    if(res != 0)
    {
        WIFI_UART_LOG("check sum fail");
        res = 5;
        goto exit;
    }
    
    sendbuff[frame_length -3] = (uint8_t)(check_sum & 0xFF);
    sendbuff[frame_length -2] = (uint8_t)((check_sum >> 8) & 0xFF);
    sendbuff[frame_length -1] = 0x23;
    
    wifi_usart_sendbytes(sendbuff,frame_length);
    WIFI_UART_LOG("send 0x%02x data",wifi_request->func);
    uart_printf_array("res_to_wifi",sendbuff,frame_length);
    
    if(sendbuff != NULL)
    {
        myfree(sendbuff);
    }
    
    
    return 0;
    
exit:
    
    if(sendbuff != NULL)
    {
        myfree(sendbuff);
    }
    
    return res;
}



void uart_printf_array(char *name,uint8_t *databuff,uint8_t length)
{
    INT8U err;
    uint8_t i = 0;
    if(databuff == NULL || length == 0)
    {
        return;
    }
    OSMutexPend(stdio_tx_mutex,0,&err);
    printf("%s:",name);
    for(i = 0;i < length;i++)
    {
        printf("0x%02x ",databuff[i]);
    }
    printf("\r\n");
    
    OSMutexPost(stdio_tx_mutex);
    
}
