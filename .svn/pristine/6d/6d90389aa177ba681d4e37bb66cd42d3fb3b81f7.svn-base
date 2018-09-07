#ifndef __SIM7600_H__
#define __SIM7600_H__

//#include "global.h"
#include "stdint.h"
#include "stm32f10x_gpio.h"
#include "user_debug.h"


#define SIM7600_LOG(M,...)  custom_log("SIM7600", M, ##__VA_ARGS__)

#define SIM7600_USART    USART2

#define  SIM7600_WAIT_RESPONSE        1
#define  SIM7600_IDLE                 2

//返回的错误码
#define  SIM7600_OK                   0
#define  SIM7600_BUSY                 1



#define  SIM7600_SEND_DATA_NULL        -20
#define  SIM7600_CMD_TIME_OUT        -21

#define  PARAMETER_ERROR           10


//发送指令后的超时时间
#define SIM7600_CMD_TIMEOUT_TIME              (10*1000)


//#define SIM7600_BUSY_CHECK()      {if(IsSIM7600busy) return SIM7600_BUSY;}

#define END_OK        "OK\r\n"
#define END_CONNECT   "CONNECT"
#define END_ERROR     "ERROR"

#define SIM7600_READY    "PB DONE\r\n"

/*
\r回车符 ASCII码 0x0D
\n换行符 ASCII码 0x0A
\"双引号 ASCII码 0x22
:冒号    ASCII码 0x3A
,逗号    ASCII码 0x2C

*/
//双引号
#define ASCII_QUOTES         0x22
//冒号
#define ASCII_COLONS         0x3A
//逗号
#define ASCII_COMMA          0x2C
//开花括号
#define ASCII_BRANCE_OPEN    0x7B
//闭花括号
#define ASCII_BRANCE_CLOSE   0x7D
// \r回车符 ASCII码 0x0D
#define ASCII_RETURN         0x0D
// \n换行符 ASCII码 0x0A
#define ASCII_NEW_LINE       0x0A

#define ASCII_SPACE          0x20


//固件版本号
#define FIRMWARE_VERSION    "SIM7600@001"
//云版本号
#define IOT_VERSION         "1.0.0"
#define MODULE_NAME         "SIM7600CE"


//#define SIM7600_IMEI_LEN              15
#define SIM7600_CCID_LEN              20

#define SIM7600_CMD_END_FLAG           "\r\n"
//显示产品信息 
//#define SIM7600_ATI_CMD                "ATI\r\n"
#define SIM7600_ATI_CMD                "ATI"

//关闭命令回显
#define SIM7600_DISABLE_CMD_ECHO_CMD      "ATE0"
#define SIM7600_DISABLE_CMD_ECHO_RES      CMD_RES_OK

//获取信号质量
#define SIM7600_CSQ_CMD                "AT+CSQ"
#define SIM7600_CSQ__RES                "+CSQ:"
//请求TA 序列号（IMEI）
#define SIM7600_GSN_CMD                "AT+GSN"
//获取CCID
#define SIM7600_CICCID_CMD                "AT+CICCID"
#define SIM7600_CICCID_RES                CMD_RES_OK
#define SIM7600_CICCID_START_FLAG         "+ICCID:"

//读取SIM 卡服务运营商名称
#define SIM7600_QSPN_CMD               "AT+QSPN"


#define HTTP_HEADER_LENGTH         256
#define HTTP_BODY_LENGTH           400
#define HTTP_JWT_LENGTH            256
#define HTTP_RES_BODY_LENGTH       360

#define HTTPS_SERVER_ADDR                "io.bjyjyz.com" 
#define HTTPS_PORT                      443

#define CMD_RES_OK        "OK\r\n"
#define CMD_RES_CONNECT   "CONNECT"
#define CMD_RES_ERROR     "ERROR"

#define SIM7600_HTTPS_START_CMD            "AT+CHTTPSSTART"
#define SIM7600_HTTPS_START_RES            "+CHTTPSSTART: 0\r\n"
#define SIM7600_HTTPSPOSE_CMD              "AT+CHTTPSOPSE"
#define SIM7600_HTTPSPOSE_RES              "+CHTTPSOPSE: 0\r\n"
#define SIM7600_HTTPSSEND_CMD              "AT+CHTTPSSEND"
//#define SIM7600_HTTPSSEND_RES              ">"
//下面两个是虚拟的命令，用于区分发送的 AT+CHTTPSSEND 命令后面是否带长度参数
#define SIM7600_HTTPSSEND_NZ_CMD           "AT+CHTTPSSEND_NZ"
#define SIM7600_HTTPSSEND_NZ_RES           ">"
#define SIM7600_HTTPSSEND_Z_CMD            "AT+CHTTPSSEND_Z"
//#define SIM7600_HTTPSSEND_Z_RES            "+CHTTPSSEND: 0\r\n"
#define SIM7600_HTTPSSEND_Z_RES            "RECV EVENT\r\n"
//虚拟的发送https请求字符串的命令
#define SIM7600_HTTPS_SEND_REQUEST_CMD     "AT+CHTTPSREQUEST"
//#define SIM7600_HTTPS_SEND_REQUEST_RES     CMD_RES_OK
#define SIM7600_HTTPS_SEND_REQUEST_RES     "RECV EVENT\r\n"
#define SIM7600_HTTPSRECV_CMD              "AT+CHTTPSRECV"
#define SIM7600_HTTPSRECV_RES              "+CHTTPSRECV: 0\r\n"
#define SIM7600_HTTPSCLOSE_CMD             "AT+CHTTPSCLSE"
#define SIM7600_HTTPSCLOSE_RES             "+CHTTPSCLSE: 0\r\n"
#define SIM7600_HTTPSSTOP_CMD              "AT+CHTTPSSTOP"
#define SIM7600_HTTPSSTOP_RES              CMD_RES_OK


#define HTTPS_MAX_STEP                7

#define WAIT_HTTP_RES_MAX_TIME   (SIM7600_CMD_TIMEOUT_TIME + (3*1000))
#define HTTPS_MAX_TRY_TIMES       2


#define TOKEN_WRONG_CODE      1000

#define HTTPS_RES_OK               200

#define HTTPS_DATA_START_FLAG      "\"data\":"
#define HTTPS_RES_START_FLAG       "HTTP/1.1 "

#define HTTPS_RES_BODY_START_FLAG  "\r\n{"
//#define HTTPS_RES_BODY_STOP_FLAG   "+CHTTPSRECV: 0"
#define HTTPS_RES_BODY_STOP_FLAG   "\r\n0\r\n"


//mqtt
#define MQTT_SERVER_ADDR                  "118.178.233.12"
//#define MQTT_SERVER_ADDR                  "io.bjyjyz.com"

#define MQTT_PORT                       1883
#define MQTT_CLIENT_ID                "SIM7600_client"

//0表示断开连接后保存消息，重新连接后继续推送；1表示重新连接时，清除以前的消息
//#define MQTT_CLEAN_SESSION              0
//连接时的超时时间，单位是秒
//#define MQTT_KEEP_ALIVE_TIME            30
//#define MQTT_CONNECT_TIMEOUT            30

//#define MQTT_MESSAGE_QOS                0

#define SIM7600_MQTT_START_CMD                  "AT+CMQTTSTART"
#define SIM7600_MQTT_START_RES                  "+CMQTTSTART: 0\r\n"
#define SIM7600_MQTT_ACCQ_CMD                   "AT+CMQTTACCQ"
#define SIM7600_MQTT_CNCTTIMEOUT_CMD            "AT+CMQTTCNCTTIMEOUT"
#define SIM7600_MQTT_CONNECT_TIMEOUT            60
#define SIM7600_MQTT_CONNECT_CMD                "AT+CMQTTCONNECT"
#define SIM7600_MQTT_KEEPALIVE_TIME             20
#define SIM7600_MQTT_CLEAN_SESSION                   0
#define SIM7600_MQTT_SUB_CMD                    "AT+CMQTTSUB"
#define SIM7600_MQTT_SUB_RES                    ">"

//虚拟出来的指令，其实并没有这个AT指令，执行该命令时发送订阅的topic
#define SIM7600_MQTT_SEND_TOPIC_CMD             "AT+CMQTTSTOPIC"
#define SIM7600_MQTT_SEND_TOPIC_RES             "+CMQTTSUB: 0,0\r\n"

#define SIM7600_MQTT_DISCONNECT_CMD             "AT+CMQTTDISC"
#define SIM7600_MQTT_STOP_CMD                   "AT+CMQTTSTOP"

#define SIM7600_MQTT_GET_STATUS_CMD           "AT+MQTTSTATU"
#define SIM7600_MQTT_GET_STATUS_RES           CMD_RES_OK
#define SIM7600_MQTT_STATUS_START_FLAG        "+MQTTSTATU:"

#define WAIT_MQTT_INIT_RES_MAX_TIME         (SIM7600_CMD_TIMEOUT_TIME + (1*1000))
#define WAIT_MQTT_GET_STATUS_RES_MAX_TIME         (SIM7600_CMD_TIMEOUT_TIME + (1*1000))

#define MQTT_INIT_TRY_MAX_TIME                1
#define MQTT_GET_STATUS_TRY_MAX_TIME          MQTT_INIT_TRY_MAX_TIME




//接收mqtt消息超时时间
//#define SIM7600_MQTT_TIMEOUT                    30
//#define SIM7600_MQTT_DELAY_TIME                 5


#define SIM7600_PAYLOAD_MAX_LENGTH              149
#define SIM7600_PAYLAOD_BUFF_SIZE               (SIM7600_PAYLOAD_MAX_LENGTH + 1)

#define MQTT_MAX_STEP                  6

#define SIM7600_MQTT_RX_START_FLAG              "+CMQTTRXSTART:"
#define SIM7600_MQTT_RX_TOPIC_FLAG              "+CMQTTRXTOPIC:"
#define SIM7600_MQTT_RX_PAYLOAD_FLAG            "+CMQTTRXPAYLOAD:"
#define SIM7600_MQTT_RX_STOP_FLAG               "+CMQTTRXEND: 0\r\n"




#define HTTP_HEAD_METHOD_POST               "POST"

#define FOG_V2_ACTIVATE_URI                 ("/YJIOT/device/activate/")
#define FOG_V2_GET_TOKEN_URI                ("/YJIOT/device/token-auth/")
#define FOG_V2_SEND_EVENT_URI               ("/YJIOT/device/sendeventadv/")
#define FOG_V2_OTA_UP_DATA_URI              ("/YJIOT/device/updatecheck/")
#define FOG_V2_CHIPS_CONFIRM_URI            ("/YJIOT/device/chipsConfirm/")
#define FOG_V2_EXAM_UPLOAD_URI              ("/YJIOT/device/saveExamItem/")



//SIM7600 product id
#define PRODUCT_ID         "caef583f-f0d5-4f79-bfef-29c78ba802e1"

#define MXCHIPSN           "SIM7600"


//http事件位定义
#define HTTP_ACTIVATE           0
#define HTTP_TOKEN_AUTH         1
#define HTTP_OTA                2
#define HTTP_UPLOAD_DATA        3
#define HTTP_SYNC               4
#define HTTP_C_CONFIRM          5
#define HTTP_FACTORY_CHECK      6


#define TOKEN_BUFF_SIZE    200
#define DEVICE_ID_LEN    36
#define CHECK_ID_LEN    36


#define UPLOAD_TIME_INTERVAL  60




#define SIM7600_BIT_CHECK(x,x_bit)  ((x & (1 << x_bit))?1:0)

//SIM7600 POWER KEY PIN DEFINE
//#define POWER_KEY_GPIO_CLK        RCC_APB2Periph_GPIOC
//#define POWER_KEY_PORT            GPIOC
//#define POWER_KEY_PIN             GPIO_Pin_14

#define POWER_KEY_GPIO_CLK        RCC_APB2Periph_GPIOB
#define POWER_KEY_PORT            GPIOB
#define POWER_KEY_PIN             GPIO_Pin_9

#define POWER_KEY_HIGH()          GPIO_SetBits(POWER_KEY_PORT,POWER_KEY_PIN)
#define POWER_KEY_LOW()           GPIO_ResetBits(POWER_KEY_PORT,POWER_KEY_PIN)

//#define SIM7600_RESET_GPIO_CLK       RCC_APB2Periph_GPIOC
//#define SIM7600_RESET_PORT           GPIOC
//#define SIM7600_RESET_PIN            GPIO_Pin_15

#define SIM7600_RESET_GPIO_CLK        RCC_APB2Periph_GPIOB
#define SIM7600_RESET_PORT            GPIOB
#define SIM7600_RESET_PIN             GPIO_Pin_8

#define SIM7600_RESET_HIGH()         GPIO_SetBits(SIM7600_RESET_PORT,SIM7600_RESET_PIN)
#define SIM7600_RESET_LOW()          GPIO_ResetBits(SIM7600_RESET_PORT,SIM7600_RESET_PIN)





typedef struct{
  
    unsigned char Is_wait_data;
    unsigned char type;
    char cmd[25];
    unsigned char string_length;
    char sendtring[50];
    unsigned long cmd_send_time;
    char end_flag[20];
    int cmd_result;
    unsigned char error_times;
    unsigned char timeout_times;

}SIM7600_Cmd_Typedef;


typedef struct{
  
    unsigned char is_sim7600_registerd;
  
}SIM7600_RESGISTER_Typedef;




enum SIM7600_DATA_TYPE{

    STRING_TYPE  = 0,
    CMD_TYPE     = 1  

};

enum SIM7600_CMD_RESULT{
  
    CMD_IDLE       = 0,
    CMD_WAIT       = 1,
    CMD_SUCCESS     = 2,
    CMD_ERROR      = 3,
    CMD_TIMEOUT    = 4
  
};


typedef struct{

    uint32_t http_id;
    uint8_t action;
    uint8_t save_flag;
    uint8_t is_jwt;
    char *payload;  

}upload_data_msg_t;

typedef struct{

    uint32_t http_id;
    uint8_t code;
    char *http_body;

}upload_res_t;

typedef struct{

    upload_data_msg_t *upload_msg;
    char *header;
    char *http_body;
    char *jwt;
    upload_res_t upload_res;


}https_requeset_res_t;


enum upload_data_result{
 
  UPLOAD_SUCCESS        = 0,
  UPLOAD_PARA_ERR       = 1,
  UPLOAD_TIMEOUT        = 2,
  UPLAOD_REQ_QUEUE_ERR  = 3,
  UPLAOD_RES_QUEUE_ERR  = 4,
  NET_WORK_ERR          = 5,
  UPLOAD_RES_NULL       = 6,
  UPLOAD_RES_ID_ERR     = 7,
  MODULE_NOT_UP         = 8,
  JSON_ITEM_ERR         = 9

};

enum mqtt_cmd{

  MQTT_INIT_ACTION                  = 1,
  MQTT_GET_CONNECT_STATUS_ACTION    = 2

};

enum mqtt_action_result{

  MQTT_ACTION_SUCCESS          = 0,
  MQTT_ACTION_FAIL             = 1,
  MQTT_CMD_QUEUE_ERR           = 2,
  MQTT_CMD_RES_TIMEOUT         = 3,
  MQTT_CMD_RES_NULL            = 4,
  MQTT_NOT_INIT                = 5

};

enum mqtt_connect_status{
  
  MQTT_DISCONNECT   = 0,
  MQTT_CONNECT      = 1,
  MQTT_TRY_CONNECT  = 2

};

typedef struct{

  uint8_t cmd;

}mqtt_action_cmd_t;

typedef struct{

  uint8_t cmd;
  uint8_t result;  
  uint8_t status;
  
}mqtt_action_res_t;


void sim7600_reset_pin_init(void);
void sim76000_reset_pin_high(void);
void sim7600_reset_pin_low(void);
void sim76000_reset(void);

void sim7600_powerkey_pin_init(void);
//开机
void sim7600_powerkey_on(void);
//关机
void sim7600_powerkey_off(void);
void sim7600_power_restart(void);
  

void empty_rx_buff(char *buff,uint16_t *index);

int sim7600_send_data(unsigned char type,const char *cmd,const char *http_requeset,uint16_t http_requeset_length);
int sim7600_wait_response(char *rx_buff,uint16_t *index);
void parse_sim7600_cmd_result(char *rx_buff,uint16_t *index);
//int SIM7600_Get_Product_Info(void);

void sim7600_http_loop(void);

//void SIM7600_Get_Signal_Quality(void);

void sim7600_disnable_command_echo(void);
void sim7600_get_ccid(void);
void sim7600_http_close(void);

//void device_get_ccid(void);
//void device_get_signal_quality(void);


int string_get_int(const char *string);
long string_get_long(const char *string);
void string_get_string(const char *string,char *dest);

void wifi_led_on(void);
void wifi_led_off(void);
//主要fog初始化和mqtt信息监测
void sim7600_fogcloud_init_and_monitor_task(void *para);
//人工通过外部按键触发检测信息
void sim7600_signal_check(void);


void sim7600_mqtt_loop(void);
void sim7600_get_mqtt_message(char *rx_buff,uint16_t *index);


void sim7600_mqtt_close(void);

void sim7600_event_scan(void);

uint8_t device_activate_event(void);
uint8_t device_get_token_event(void);
uint8_t device_ota_check_event(void);
uint8_t upload_data_event(const char *upload_data,uint8_t save_flag,upload_res_t *res_msg);

uint8_t mqtt_init_event(void);
uint8_t get_mqtt_connect_status_event(uint8_t *mqtt_status);

void user_set_module_restart(void);

#endif

