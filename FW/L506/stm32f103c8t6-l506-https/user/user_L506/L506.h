#ifndef __L506_H__
#define __L506_H__

//#include "global.h"
#include "stdint.h"
#include "stm32f10x_gpio.h"
#include "user_debug.h"


#define L506_LOG(M,...)  custom_log("L506", M, ##__VA_ARGS__)

#define  L506_WAIT_RESPONSE        1
#define  L506_IDLE                 2

//返回的错误码
#define  L506_OK                   0
#define  L506_BUSY                 1



#define  L506_SEND_DATA_NULL        -20
#define  L506_CMD_TIME_OUT        -21

#define  PARAMETER_ERROR           10


//发送指令后的超时时间
#define L506_CMD_TIMEOUT_TIME              (10*1000)


//#define L506_BUSY_CHECK()      {if(IsL506busy) return L506_BUSY;}

#define END_OK        "OK\r\n"
#define END_CONNECT   "CONNECT"
#define END_ERROR     "ERROR"

#define L506_READY    "Call Ready\r\n"

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
#define FIRMWARE_VERSION    "L506@001"
//云版本号
#define IOT_VERSION         "1.0.0"
#define MODULE_NAME         "L506CE"


//#define L506_IMEI_LEN              15
#define L506_CCID_LEN              20

#define L506_CMD_END_FLAG           "\r\n"
//显示产品信息 
//#define L506_ATI_CMD                "ATI\r\n"
#define L506_ATI_CMD                "ATI"

//关闭命令回显
#define L506_DISABLE_CMD_ECHO_CMD      "ATE0"

//获取信号质量
#define L506_CSQ_CMD                "AT+CSQ"
#define L506_CSQ__RES                "+CSQ:"
//请求TA 序列号（IMEI）
#define L506_GSN_CMD                "AT+GSN"
//获取CCID
#define L506_CICCID_CMD                "AT+CICCID"
#define L506_CICCID_RES                "+CICCID:"

//读取SIM 卡服务运营商名称
#define L506_QSPN_CMD               "AT+QSPN"


#define HTTP_HEADER_LENGTH         256
#define HTTP_BODY_LENGTH           400
#define HTTP_JWT_LENGTH            256
#define HTTP_RES_BODY_LENGTH       360

#define HTTPS_SERVER_ADDR                "io.bjyjyz.com" 
#define HTTPS_PORT                      443

#define CMD_RES_OK        "OK\r\n"
#define CMD_RES_CONNECT   "CONNECT"
#define CMD_RES_ERROR     "ERROR"

#define L506_HTTPS_START_CMD            "AT+CHTTPSSTART"
#define L506_HTTPS_START_RES            CMD_RES_OK
#define L506_HTTPSPOSE_CMD              "AT+CHTTPSOPSE"
#define L506_HTTPSPOSE_RES              CMD_RES_OK
#define L506_HTTPSSEND_CMD              "AT+CHTTPSSEND"
//下面两个是虚拟的命令，用于区分发送的 AT+CHTTPSSEND 命令后面是否带长度参数
#define L506_HTTPSSEND_NZ_CMD           "AT+CHTTPSSEND_NZ"
#define L506_HTTPSSEND_NZ_RES           ">>"
#define L506_HTTPSSEND_Z_CMD            "AT+CHTTPSSEND_Z"
#define L506_HTTPSSEND_Z_RES            CMD_RES_OK
//虚拟的发送https请求字符串的命令
#define L506_HTTPS_SEND_REQUEST_CMD     "AT+CHTTPSREQUEST"
#define L506_HTTPS_SEND_REQUEST_RES     CMD_RES_OK
#define L506_HTTPSRECV_CMD              "AT+CHTTPSRECV"
#define L506_HTTPSRECV_RES              CMD_RES_OK
#define L506_HTTPSCLOSE_CMD             "AT+CHTTPSCLSE"
#define L506_HTTPSCLOSE_RES             CMD_RES_OK
#define L506_HTTPSSTOP_CMD              "AT+CHTTPSSTOP"
#define L506_HTTPSSTOP_RES              CMD_RES_OK


#define HTTPS_MAX_STEP                8

#define WAIT_HTTP_RES_MAX_TIME   (L506_CMD_TIMEOUT_TIME + (3*1000))
#define HTTPS_MAX_TRY_TIMES       2


#define TOKEN_WRONG_CODE      1000

#define HTTPS_RES_OK               200

#define HTTPS_DATA_START_FLAG      "\"data\":"
#define HTTPS_RES_START_FLAG       "HTTP/1.1 "

#define HTTPS_RES_BODY_START_FLAG  "\r\n\r\n{"
#define HTTPS_RES_BODY_STOP_FLAG   "+CHTTPSRECV: 0"


//mqtt
//#define MQTT_SERVER_ADDR                  "118.178.233.12"
#define MQTT_SERVER_ADDR                  "io.bjyjyz.com"

#define MQTT_PORT                       1883
#define MQTT_CLIENT_ID                "L506_client"

//0表示断开连接后保存消息，重新连接后继续推送；1表示重新连接时，清除以前的消息
#define MQTT_CLEAN_SESSION              0
//连接时的超时时间，单位是秒
#define MQTT_KEEP_ALIVE_TIME            30
//#define MQTT_CONNECT_TIMEOUT            30

#define MQTT_MESSAGE_QOS                0

#define L506_MQTT_SSL_CMD              "AT+MQTTSSL"
#define L506_MQTT_SSL_RES              CMD_RES_OK
#define L506_MQTT_CONFIG_CMD           "AT+MCONFIG"
#define L506_MQTT_CONFIG_RES           CMD_RES_OK
#define L506_MQTT_START_CMD            "AT+MIPSTART"
#define L506_MQTT_START_RES            "+MIPSTART:SUCCESS,0"
#define L506_MQTT_CONNECT_CMD          "AT+MCONNECT"
#define L506_MQTT_CONNECT_RES          "+MCONNECT:SUCCESS,0"
#define L506_MQTT_SUB_CMD              "AT+MSUB"
#define L506_MQTT_SUB_RES              "+MSUB:SUCCESS" 

//#define L506_MQTT_DISCONNECT_CMD       "AT+MDISCONNECT"
#define L506_MQTT_CLOSE_CMD            "AT+MIPCLOSE"
#define L506_MQTT_CLOSE_RES            CMD_RES_OK

#define L506_MQTT_GET_STATUS_CMD           "AT+MQTTSTATU"
#define L506_MQTT_GET_STATUS_RES           CMD_RES_OK
#define L506_MQTT_STATUS_START_FLAG        "+MQTTSTATU:"

#define WAIT_MQTT_INIT_RES_MAX_TIME         (L506_CMD_TIMEOUT_TIME + (1*1000))
#define WAIT_MQTT_GET_STATUS_RES_MAX_TIME         (L506_CMD_TIMEOUT_TIME + (1*1000))

#define MQTT_INIT_TRY_MAX_TIME                1
#define MQTT_GET_STATUS_TRY_MAX_TIME          MQTT_INIT_TRY_MAX_TIME




//接收mqtt消息超时时间
//#define L506_MQTT_TIMEOUT                    30
//#define L506_MQTT_DELAY_TIME                 5


#define L506_PAYLOAD_MAX_LENGTH              149
#define L506_PAYLAOD_BUFF_SIZE               (L506_PAYLOAD_MAX_LENGTH + 1)

#define MQTT_MAX_STEP                  5

#define MQTT_MSG_START_FLAG           "+MSUB:"
#define MQTT_MSG_STOP_FLAG            "\r\n"
#define MQTT_PAYLOAD_START_FLAG       "bytes,"




#define HTTP_HEAD_METHOD_POST               "POST"

#define FOG_V2_ACTIVATE_URI                 ("/YJIOT/device/activate/")
#define FOG_V2_GET_TOKEN_URI                ("/YJIOT/device/token-auth/")
#define FOG_V2_SEND_EVENT_URI               ("/YJIOT/device/sendeventadv/")
#define FOG_V2_OTA_UP_DATA_URI              ("/YJIOT/device/updatecheck/")
#define FOG_V2_CHIPS_CONFIRM_URI            ("/YJIOT/device/chipsConfirm/")
#define FOG_V2_EXAM_UPLOAD_URI              ("/YJIOT/device/saveExamItem/")



//L506 product id
#define PRODUCT_ID         "caef583f-f0d5-4f79-bfef-29c78ba802e1"

#define MXCHIPSN           "L506"


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




#define L506_BIT_CHECK(x,x_bit)  ((x & (1 << x_bit))?1:0)

//L506 POWER KEY PIN DEFINE
#define POWER_KEY_GPIO_CLK        RCC_APB2Periph_GPIOC
#define POWER_KEY_PORT            GPIOC
#define POWER_KEY_PIN             GPIO_Pin_14

#define POWER_KEY_HIGH()          GPIO_SetBits(POWER_KEY_PORT,POWER_KEY_PIN)
#define POWER_KEY_LOW()           GPIO_ResetBits(POWER_KEY_PORT,POWER_KEY_PIN)

#define L506_RESET_GPIO_CLK       RCC_APB2Periph_GPIOC
#define L506_RESET_PORT           GPIOC
#define L506_RESET_PIN            GPIO_Pin_15

#define L506_RESET_HIGH()         GPIO_SetBits(L506_RESET_PORT,L506_RESET_PIN)
#define L506_RESET_LOW()          GPIO_ResetBits(L506_RESET_PORT,L506_RESET_PIN)





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

}L506_Cmd_Typedef;


typedef struct{
  
    unsigned char Is_L506_registerd;
  
}L506_RESGISTER_Typedef;




enum L506_DATA_TYPE{

    STRING_TYPE  = 0,
    CMD_TYPE     = 1  

};

enum L506_CMD_RESULT{
  
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


//void L506_Reset_Pin_Init(void);
//void L506_Reset_Pin_High(void);
//void L506_Reset_Pin_Low(void);
//void L650_Reset(void);
void L506_PowerKey_Pin_Init(void);
//开机
void L506_PowerKey_On(void);
//关机
void L506_PowerKey_Off(void);
void L506_Restart(void);
  

void empty_rx_buff(char *buff,uint16_t *index);

int L506_Send_data(unsigned char type,const char *cmd,const char *http_requeset,uint16_t http_requeset_length);
int L506_wait_response(char *rx_buff,uint16_t *index);
void parse_L506_cmd_result(char *rx_buff,uint16_t *index);
//int L506_Get_Product_Info(void);

void L506_http_loop(void);

//void L506_Get_Signal_Quality(void);

void L506_Disnable_Command_Echo(void);
void L506_Get_CCID(void);
void L506_http_close(void);

void device_get_ccid(void);
//void device_get_signal_quality(void);


int string_get_int(const char *string);
long string_get_long(const char *string);
void string_get_string(const char *string,char *dest);

void Wifi_Led_On(void);
void Wifi_Led_Off(void);
//主要fog初始化和mqtt信息监测
void L506_fogcloud_init_and_monitor_task(void *para);
//人工通过外部按键触发检测信息
void L506_signal_check(void);


void L506_mqtt_loop(void);
void L506_get_mqtt_message(char *rx_buff,uint16_t *index);


void L506_mqtt_close(void);

void L506_Event_Scan(void);

uint8_t device_activate_event(void);
uint8_t device_get_token_event(void);
uint8_t device_ota_check_event(void);
uint8_t upload_data_event(const char *upload_data,uint8_t save_flag,upload_res_t *res_msg);

uint8_t mqtt_init_event(void);
uint8_t get_mqtt_connect_status_event(uint8_t *mqtt_status);

void user_set_module_restart(void);

#endif

