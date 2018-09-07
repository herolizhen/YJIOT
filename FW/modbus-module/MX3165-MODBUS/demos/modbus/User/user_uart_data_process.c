#include "string.h"
#include "user_uart.h"
#include "user_uart_data_process.h"
#include "user_device_control.h"
#include "user_upstream.h"
#include "fog_v2_include.h"
#include "mico.h"

#define WAIT_MCU_RES_MAX_TIME (5*1000)

user_ring_buffer_t user_ring_buff;
uint8_t wifi_uart_rx_buff[USER_UART_BUFFER_LENGTH];

modbus_devs_t modbus_devs;

mico_queue_t wifi_uart_rx_queue = NULL;
mico_queue_t modbus_real_data_queue = NULL;

static mico_mutex_t wifi_uart_tx_mutex;


extern FOG_DES_S *fog_des_g;

uint8_t user_uart_rb_initialize(void)
{
    /*初始化ringbuffer相关的配置*/
    rb_initialize(&user_ring_buff, wifi_uart_rx_buff, sizeof(wifi_uart_rx_buff));
    return 1 ;
}

uint8_t user_uart_recv_available(void)
{
    if(user_ring_buff.flagoverflow == 1)
    {
	rb_clear(&user_ring_buff);
    }
    return !rb_is_empty(&user_ring_buff);
}

uint8_t user_uart_read(void)
{
    uint8_t cur =0xff;
    if( !rb_is_empty(&user_ring_buff))
    {
	cur = rb_pop(&user_ring_buff);
    }
    return cur;
}

void empty_rx_buff(uint8_t *rx_buff,uint16_t *index)
{
    if(rx_buff == NULL)
    {
        return;
    }
    memset(rx_buff,0,*index);
    *index = 0;
}

extern FOG_DES_S *fog_des_g;

//设备激活
OSStatus modbus_devices_activate(device_t *dev)
{
    OSStatus err = kGeneralErr;
    const char* device_activate_body = "{\"product_id\":\"%s\",\"mac\":\"%s\",\"devicepw\":\"%s\",\"mxchipsn\":\"%s\"}";
    char http_body[256] = {0};
    int32_t code = -1;
    FOG_HTTP_RESPONSE_SETTING_S user_http_res;
    uint8_t retry = 0;

    memset(&user_http_res, 0, sizeof(user_http_res));

    if((dev->is_activate == true))
    {
        return kNoErr;
    }

 start_actiavte:
    while(get_wifi_status() == false)
    {
        user_uart_data_process_log("https disconnect, fog_v2_device_activate is waitting...");
        err = kGeneralErr;
        goto exit;
    }

    sprintf(dev->devicepw, "%04ld", (mico_rtos_get_time()) % 10000);

    sprintf(http_body, device_activate_body, fog_des_g->product_id, dev->device_mac, dev->devicepw, fog_des_g->mxchip_sn);

    user_uart_data_process_log("=====> %d device_activate send ======>",dev->num);

    err = fog_v2_push_http_req_mutex(false, FOG_V2_ACTIVATE_METHOD, FOG_V2_ACTIVATE_URI, FOG_V2_HTTP_DOMAIN_NAME, http_body, &user_http_res);
    require_noerr( err, exit );

    //处理返回结果
    err = process_response_body_string(user_http_res.fog_response_body, &code, "deviceid", dev->device_id, sizeof(dev->device_id));
    require_noerr( err, exit );

    require_action(code == FOG_HTTP_SUCCESS, exit, err = kGeneralErr);

    dev->is_activate = true;
    //err = mico_system_context_update(mico_system_context_get());
    //require_noerr( err, exit );
    user_uart_data_process_log("%d activate success, device_id: %s, pw:%s", dev->num,dev->device_id, dev->devicepw);
    //app_log("<===== device_activate success <======");

 exit:
     if(user_http_res.fog_response_body != NULL) //释放资源
     {
         free(user_http_res.fog_response_body);
         user_http_res.fog_response_body = NULL;
     }

    if(err != kNoErr)
    {
        if ( (code == FOG_HTTP_PRODUCTI_ID_ERROR) || (code == FOG_HTTP_PRODUCTI_ID_NOT_SUB) || (code == FOG_HTTP_PRODUCTI_ID_NOT_GATEWAY))
        {
            user_uart_data_process_log("product id is error! code = %ld", code);
            //app_log("<===== device_activate error <======");
            return err;
        }

        dev->is_activate = false;
        memset(dev->devicepw, 0, sizeof(dev->devicepw));
        //mico_system_context_update(mico_system_context_get());

        user_uart_data_process_log("<===== %d device_activate error <======",dev->num);

        mico_thread_msleep(200);

        retry ++;
        if(retry >= HTTP_MAX_RETRY_TIMES)
        {
            return kGeneralErr;
        }

        goto start_actiavte;
    }

    return err;
}

#define MAX_UART_RESPONSE_DATA    32
#define MAX_MODBUS_REAL_DATA_WQ_SIZE   5
void user_uart_data_process_thread(mico_thread_arg_t arg)
{
    uint16_t index = 0;
    uint8_t recv_buff[USER_UART_BUFFER_LENGTH] = {0}; 
    OSStatus err = kGeneralErr;
    uint8_t length = 0;
    uint8_t frame_length = 0;
    wifi_uart_rx_msg_t *wifi_uart_rx_msg = NULL;
    uint8_t func = 0;
    uint8_t *sendbuff = NULL;
    uint16_t checksum = 0;
    uint16_t temp_checksum = 0;
    uint8_t res = 0;
    
    user_uart_data_process_log_trace();  
    arg = arg;
    
    //user_uart_rb_initialize();
    
    mico_rtos_init_mutex( &wifi_uart_tx_mutex );
    
    err = mico_rtos_init_queue( &modbus_real_data_queue, "modbus_real_data_queue", sizeof(wifi_uart_rx_msg_t *), MAX_MODBUS_REAL_DATA_WQ_SIZE);
    
    err = mico_rtos_init_queue( &wifi_uart_rx_queue, "wifi_uart_rx_queue", sizeof(wifi_uart_rx_msg_t *), 1);
    
    while(1)
    {
        if(user_uart_recv_available())
        {           
            if(index < USER_UART_BUFFER_LENGTH)
            {
                recv_buff[index++] = user_uart_read();
                if(index == 1 && recv_buff[0] != 0x2A)
                {
                    empty_rx_buff(recv_buff,&index);
                    continue;
                }
            }        
        }
        
        if(index == 2)
        {
            length = recv_buff[1];
        }
        
        if(index < (length + 3))
        {
            if(index >= USER_UART_BUFFER_LENGTH)
            {
                user_uart_data_process_log("recv_buff full,flush buff");
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
                        
        
        //receive one frame data complete
        //debug
        //uart_printf_array("get frame",recv_buff,index);
                    
        //check sum
        res = calculate_check_sum(recv_buff + 1,recv_buff[1] - 1,&checksum);
        if(res != 0)
        {
            user_uart_data_process_log("calculate_check_sum fail,res=%d",res);
            empty_rx_buff(recv_buff,&index);
            continue;
        }
            
        temp_checksum = (uint16_t)recv_buff[index - 2] << 8 | recv_buff[index - 3];
        if(checksum != temp_checksum)
        {
            user_uart_data_process_log("check sum error");
            empty_rx_buff(recv_buff,&index);
            continue;
        }
        
        func = recv_buff[2];
        if(func <= 0)
        {
            user_uart_data_process_log("func <= 0,func:0x%x",func);
        }
        else if(func < 0x10)
        {
            if(func > 0x04)
            {
                user_uart_data_process_log("func > 0x04,func:0x%x",func);
                empty_rx_buff(recv_buff,&index);                
                continue;
            }
          
            sendbuff = malloc(MAX_UART_RESPONSE_DATA);
            if(sendbuff == NULL)
            {
                user_uart_data_process_log("malloc sendbuff fail");
                mico_thread_sleep(1);
                continue;
            }
            memset(sendbuff,0,MAX_UART_RESPONSE_DATA);
            sendbuff[0] = 0x2A;
            
            if(func == 0x01)
            {
                frame_length = 0x07;
                sendbuff[3] = recv_buff[3]; 
                //user_uart_data_process_log("get 0x01 data");
                //uart_printf_array("0x01 data",recv_buff,index);
                push_modbus_device_real_data_to_queue(recv_buff,index);
            }
            else if(func == 0x02)
            {
                frame_length = strlen(fog_des_g->device_mac) + 0x06;
                sprintf((char*)(sendbuff + 3),"%s",fog_des_g->device_mac);                
            }
            else if(func == 0x03 || func == 0x04)
            {
                frame_length = 0x06;
            }
                       
            sendbuff[1] = frame_length - 3;
            sendbuff[2] = recv_buff[2];
            
            //check sum           
            res = calculate_check_sum(sendbuff + 1,sendbuff[1] - 1,&checksum);
            if(res != 0)
            {               
                if(sendbuff != NULL)
                {
                    free(sendbuff);
                    sendbuff = NULL;
                }
                user_uart_data_process_log("check sum fail");
                empty_rx_buff(recv_buff,&index);
                continue;
            }
            
            sendbuff[frame_length -3] = (uint8_t)(checksum & 0xFF);
            sendbuff[frame_length -2] = (uint8_t)((checksum >> 8) & 0xFF);
            sendbuff[frame_length - 1] = 0x23;
            
            uart_printf_array("sendbuff_1",sendbuff,frame_length);
            
            err = user_uart_send(sendbuff,frame_length);
            if(err != 0)
            {
                user_uart_data_process_log("user_uart_send fail,err = %d",err);
            }
            
            if(sendbuff != NULL)
            {
                free(sendbuff);
                sendbuff = NULL;
            }                      
        }
        else
        {
            if(func > 0x14)
            {
                user_uart_data_process_log("func > 0x14,func:0x%x",func);
                empty_rx_buff(recv_buff,&index);                
                continue;
            }
            
            if(mico_rtos_is_queue_full(&wifi_uart_rx_queue) == true)
            {
                err = mico_rtos_pop_from_queue(&wifi_uart_rx_queue, &wifi_uart_rx_msg, 10);
                if(err == kNoErr)
                {               
                    if(wifi_uart_rx_msg != NULL)
                    {
                        free(wifi_uart_rx_msg);
                        wifi_uart_rx_msg = NULL;
                    }
                
                    user_uart_data_process_log("wifi_uart_rx_queue full,pop one successful");               
                }
                else
                {
                    user_uart_data_process_log("wifi_uart_rx_queue full,pop one fail");
                    mico_thread_sleep(1);
                    continue;
                }
            }
            
            frame_length = index;
            //从wifi_uart_rx_queue队列中pop出消息后，必须释放内存
            //申请的的内存大小包括 wifi_uart_rx_msg->data_buff
            wifi_uart_rx_msg = malloc(sizeof(wifi_uart_rx_msg_t) + frame_length);
            wifi_uart_rx_msg->data_buff = (uint8_t *)wifi_uart_rx_msg + sizeof(wifi_uart_rx_msg_t);
            wifi_uart_rx_msg->length = frame_length;
            memcpy(wifi_uart_rx_msg->data_buff,recv_buff,frame_length);
            
            err = mico_rtos_push_to_queue(&wifi_uart_rx_queue, &wifi_uart_rx_msg, 10);
            if(err != 0)
            {
                free(wifi_uart_rx_msg);
                wifi_uart_rx_msg = NULL;
                
            }
            
            mico_thread_msleep(5);
        }
        empty_rx_buff(recv_buff,&index);     
        

    }
}


uint8_t calculate_check_sum(uint8_t *data_buff,uint8_t length,uint16_t *checksum)
{
    uint8_t i = 0;
    uint16_t temp_checksum = 0;
  
    if(data_buff == NULL || length <= 0 || checksum == NULL)
    {
        return 1;
    }
    
    for(i = 0;i < length;i++)
    {
        temp_checksum += data_buff[i];
    }
    
    *checksum = temp_checksum;
    
    return 0;

}

//if user_buff != NULL,copy uart frame data to user_buff
uint8_t wifi_send_data_to_mcu_event(wifi_to_mcu_cmd_t *wifi_to_mcu_cmd,uint8_t *user_buff,uint8_t max_length,uint8_t *buff_length)
{
    uint8_t ret = 0;
    uint8_t res = 0;
    uint8_t *sendbuff = NULL;
    uint8_t frame_length = 0;
    uint16_t check_sum = 0;
    uint8_t i = 0;
    wifi_uart_rx_msg_t *wifi_uart_rx_msg = NULL;
    
    mico_rtos_lock_mutex( &wifi_uart_tx_mutex );                           
    
    if(wifi_to_mcu_cmd == NULL)
    {
        user_uart_data_process_log("wifi_to_mcu_cmd == NULL");
        ret = 1;
        goto exit;
    }  
   
    sendbuff = malloc(64);
    if(sendbuff == NULL)
    {
        user_uart_data_process_log("wifi_send_data_to_mcu_event malloc fail");
        ret = 2;
        goto exit;
    }
    memset(sendbuff,0,64);
    
    sendbuff[0] = 0x2A;
    sendbuff[2] = wifi_to_mcu_cmd->func;
    
    if(wifi_to_mcu_cmd->func >= 0x10 && wifi_to_mcu_cmd->func <= 0x10)
    {
        if(wifi_to_mcu_cmd->slave == 0 || wifi_to_mcu_cmd->slave > modbus_devs.dev_nums || wifi_to_mcu_cmd->quantity == 0 || wifi_to_mcu_cmd->quantity > MAX_OP_COILS_NUM)
        {
            user_uart_data_process_log("0x10-0x13 para error");
            ret = 3;
            goto exit;
        }    
    }       
    
    if(wifi_to_mcu_cmd->func == 0x10 || wifi_to_mcu_cmd->func == 0x12)
    {       
        frame_length = 0x0A;       
        sendbuff[3] = wifi_to_mcu_cmd->slave;
        sendbuff[4] = (uint8_t)(wifi_to_mcu_cmd->addr >> 8);
        sendbuff[5] = (uint8_t)(wifi_to_mcu_cmd->addr & 0xFF);
        sendbuff[6] = wifi_to_mcu_cmd->quantity;
        
    }
    else if(wifi_to_mcu_cmd->func == 0x11 || wifi_to_mcu_cmd->func == 0x13)
    {
        if(wifi_to_mcu_cmd->databuff == NULL)
        {
            user_uart_data_process_log("0x11/0x13 databuff = NULL");
            ret = 4;
            goto exit;
        }
                 
        sendbuff[3] = wifi_to_mcu_cmd->slave;
        sendbuff[4] = (uint8_t)(wifi_to_mcu_cmd->addr >> 8);
        sendbuff[5] = (uint8_t)(wifi_to_mcu_cmd->addr & 0xFF);
        sendbuff[6] = wifi_to_mcu_cmd->quantity;  
        if(wifi_to_mcu_cmd->func == 0x11)
        {
            frame_length = 0x0C; 
            sendbuff[7] = (uint8_t)(wifi_to_mcu_cmd->databuff[0] >> 8);
            sendbuff[8] = (uint8_t)(wifi_to_mcu_cmd->databuff[0] & 0xFF);
        }
        else 
        {
            frame_length = wifi_to_mcu_cmd->quantity * 2 + 10;
            for(i = 0;i < wifi_to_mcu_cmd->quantity;i++)
            {
                sendbuff[7 + 2 * i] = (uint8_t)(wifi_to_mcu_cmd->databuff[i] >> 8);
                sendbuff[8 + 2 * i] = (uint8_t)(wifi_to_mcu_cmd->databuff[i] & 0xFF);
            }
        }       
    }
    else if(wifi_to_mcu_cmd->func == 0x14)
    {
        frame_length = 0x06;        
    }
    else
    {
        user_uart_data_process_log("unrecognized func");
        ret = 5;
        goto exit;
    }
    
    sendbuff[1] = frame_length - 3;
    
    res = calculate_check_sum(sendbuff + 1,sendbuff[1] - 1,&check_sum);
    if(res != 0)
    {
        user_uart_data_process_log("check sum fail");
        ret = 6;
        goto exit;
    }
    
    sendbuff[frame_length -3] = (uint8_t)(check_sum & 0xFF);
    sendbuff[frame_length -2] = (uint8_t)((check_sum >> 8) & 0xFF);
    sendbuff[frame_length -1] = 0x23;

    if(mico_rtos_is_queue_full(&wifi_uart_rx_queue) == true)
    {
        res = mico_rtos_pop_from_queue(&wifi_uart_rx_queue, &wifi_uart_rx_msg, 10);
        if(res == kNoErr)
        {               
            if(wifi_uart_rx_msg != NULL)
            {
                free(wifi_uart_rx_msg);
                wifi_uart_rx_msg = NULL;
            }               
            user_uart_data_process_log("wifi_uart_rx_queue full,pop one successful");               
        }
        else
        {
            user_uart_data_process_log("wifi_uart_rx_queue full,pop one fail");
            ret = 6;
            goto exit;
        }
    }        
    
    uart_printf_array("sendbuff",sendbuff,frame_length);
    
    res = user_uart_send(sendbuff,frame_length);
    if(res != 0)
    {
        user_uart_data_process_log("user_uart_send data fail");
        ret = 7;
        goto exit;
    }
       
    res = mico_rtos_pop_from_queue( &wifi_uart_rx_queue, &wifi_uart_rx_msg, WAIT_MCU_RES_MAX_TIME);
    if(res != kNoErr)
    {
        user_uart_data_process_log("wait mcu response timeout");
        ret = 8;
        goto exit; 
    }
    
    if(wifi_to_mcu_cmd->func != wifi_uart_rx_msg->data_buff[2])
    {
        user_uart_data_process_log("mcu response func error");
        ret = 9;
        goto exit; 
    }
    
    if(user_buff != NULL)
    {
        *buff_length = (max_length > wifi_uart_rx_msg->length) ? wifi_uart_rx_msg->length : max_length;
        //memcpy(user_buff,wifi_uart_rx_msg->data_buff,(max_length > wifi_uart_rx_msg->length) ? wifi_uart_rx_msg->length : max_length);
        memcpy(user_buff,wifi_uart_rx_msg->data_buff, *buff_length);
    }
      
    ret = 0;
    
exit:
  
    if(wifi_uart_rx_msg != NULL)
    {
        free(wifi_uart_rx_msg);
        wifi_uart_rx_msg = NULL;
    }
  
    if(sendbuff != NULL)
    {
        free(sendbuff);
        sendbuff = NULL;
    }
    
    mico_rtos_unlock_mutex( &wifi_uart_tx_mutex );
    
    return ret;
}

extern mico_mutex_t stdio_tx_mutex;
void uart_printf_array(char *name,uint8_t *databuff,uint8_t length)
{
    uint8_t i = 0;
    if(databuff == NULL || length == 0)
    {
        return;
    }
    mico_rtos_lock_mutex( &stdio_tx_mutex );
    printf("%s:",name);
    for(i = 0;i < length;i++)
    {
        printf("0x%02x ",databuff[i]);
    }
    printf("\r\n");
    
    mico_rtos_unlock_mutex( &stdio_tx_mutex );
    
}


uint8_t push_modbus_device_real_data_to_queue(uint8_t *databuff,uint8_t length)
{
    uint8_t res = 0;
    uint8_t err = 0;
    wifi_uart_rx_msg_t *real_data_msg = NULL;
    
    
    if(databuff == NULL || length <= 0)
    {
        user_uart_data_process_log("para error"); 
        res = 1;
        goto exit;        
    }
    
    if(mico_rtos_is_queue_full(&modbus_real_data_queue) == true)
    {
        err = mico_rtos_pop_from_queue(&modbus_real_data_queue, &real_data_msg, 10);
        if(err == kNoErr)
        {               
            if(real_data_msg != NULL)
            {
                free(real_data_msg);
                real_data_msg = NULL;
            }
                
            user_uart_data_process_log("modbus_real_data_queue full,pop one successful");               
        }
        else
        {
            user_uart_data_process_log("wifi_uart_rx_queue full,pop one fail");
            res = 2;
            goto exit; ;
        }
    }
    
    real_data_msg = malloc(sizeof(wifi_uart_rx_msg_t) + length);
    if(real_data_msg == NULL)
    {
        user_uart_data_process_log("malloc real_data_msg fail");
        res = 3;
        goto exit;
    }
    real_data_msg->length = length;
    real_data_msg->data_buff = (uint8_t *)real_data_msg + sizeof(wifi_uart_rx_msg_t);
    memcpy(real_data_msg->data_buff,databuff,length);
    
    err = mico_rtos_push_to_queue(&modbus_real_data_queue, &real_data_msg, 10);
    if(err != 0)
    {
        user_uart_data_process_log("push real_data_msg to queue fail");
        free(real_data_msg);
        real_data_msg = NULL;
        goto exit;
    } 
   
    return 0;
    
exit:
  
    if(real_data_msg != NULL)
    {
        free(real_data_msg);
        real_data_msg = NULL;
    }
  
    return res;
}
