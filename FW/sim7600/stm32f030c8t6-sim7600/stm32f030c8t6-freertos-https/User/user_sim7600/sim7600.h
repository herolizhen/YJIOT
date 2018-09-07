#ifndef __SIM7600_H__
#define __SIM7600_H__

//#include "global.h"
#include "stdint.h"
#include "stm32f0xx_gpio.h"

#define  SIM7600_WAIT_RESPONSE        1
#define  SIM7600_IDLE                 2

//返回的错误码
#define  SIM7600_OK                   0
#define  SIM7600_BUSY                 1



#define  SIM7600_SEND_DATA_NULL        -20
#define  SIM7600_CMD_TIME_OUT        -21

#define  PARAMETER_ERROR           10


//发送指令后的超时时间
#define SIM7600_TIME_OUT              27000


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
#define ASCII_NEW_LINE         0x0A


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

//获取信号质量
#define SIM7600_CSQ_CMD                "AT+CSQ"
#define SIM7600_CSQ__RES                "+CSQ:"
//请求TA 序列号（IMEI）
#define SIM7600_GSN_CMD                "AT+GSN"
//获取CCID
#define SIM7600_CICCID_CMD                "AT+CICCID"
#define SIM7600_CICCID_RES                "+ICCID:"

//读取SIM 卡服务运营商名称
#define SIM7600_QSPN_CMD               "AT+QSPN"


#define HTTP_REQUEST_LENGTH   700
#define HTTP_BODY_LENGTH      300

#define HTTPS_SERVER_ADDR                "io.bjyjyz.com" 
#define HTTPS_PORT                      443

#define SIM7600_HTTPS_START_CMD            "AT+CHTTPSSTART"
#define SIM7600_HTTPSPOSE_CMD              "AT+CHTTPSOPSE"
#define SIM7600_HTTPSPOSE_RES              "+CHTTPSOPSE: 0\r\n"
#define SIM7600_HTTPSSEND_CMD              "AT+CHTTPSSEND"
#define SIM7600_HTTPSRECV_CMD              "AT+CHTTPSRECV"
#define SIM7600_HTTPSRECV_RES              "+CHTTPSRECV: 0\r\n"
#define SIM7600_HTTPSCLOSE_CMD             "AT+CHTTPSCLSE"
#define SIM7600_HTTPSCLOSE_RES             "+CHTTPSCLSE: 0\r\n" 
#define SIM7600_HTTPSSTOP_CMD              "AT+CHTTPSSTOP"

//虚构出来的命令，发送https request后使用该命令作为标志，方便进行处理
#define SIM7600_HTTSSTRING_CMD             "AT+CHTTPSSTRING"
#define SIM7600_HTTSSTRING_RES             "RECV EVENT\r\n"

#define HTTP_MAX_STEP                7


#define TOKEN_WRONG_CODE      1000



//mqtt
//#define SIM7600_MQTT_SSL_CMD              "AT+MQTTSSL"
//#define SIM7600_MQTT_CONFIG_CMD           "AT+MCONFIG"
//#define SIM7600_MQTT_START_CMD            "AT+MIPSTART"
//#define SIM7600_MQTT_CONNECT_CMD          "AT+MCONNECT"
//#define SIM7600_MQTT_SUB_CMD              "AT+MSUB"

//#define SIM7600_MQTT_DISCONNECT_CMD       "AT+MDISCONNECT"
//#define SIM7600_MQTT_CLOSE_CMD            "AT+MIPCLOSE"

//#define SIM7600_MQTT_STATUS               "AT+MQTTSTATU"

//#define MQTT_CMD_SUCCESS               "SUCCESS"
//#define MQTT_MAX_STEP                  5

//#define MQTT_SERVER_ADDR                "io.bjyjyz.com" 
#define MQTT_SERVER_ADDR                  "118.178.233.12"
#define MQTT_PORT                       1883
#define MQTT_CLIENT_NAME                "sim7600_client"

#define SIM7600_MQTT_START_CMD                  "AT+CMQTTSTART"
#define SIM7600_MQTT_START_RES                  "+CMQTTSTART: 0\r\n"
#define SIM7600_MQTT_ACCQ_CMD                   "AT+CMQTTACCQ"
#define SIM7600_MQTT_CNCTTIMEOUT_CMD            "AT+CMQTTCNCTTIMEOUT"
#define SIM7600_MQTT_CONNECT_TIMEOUT            60
#define SIM7600_MQTT_CONNECT_CMD                "AT+CMQTTCONNECT"
#define SIM7600_MQTT_KEEPALIVE_TIME             20
#define SIM7600_CLEAN_SESSION                   0
#define SIM7600_MQTT_SUB_CMD                    "AT+CMQTTSUB"
#define SIM7600_MQTT_SUB_RES                    ">"

//虚拟出来的指令，其实并没有这个AT指令，执行该命令时发送订阅的topic
#define SIM7600_MQTT_SEND_TOPIC_CMD             "AT+CMQTTSTOPIC"
#define SIM7600_MQTT_SEND_TOPIC_RES             "+CMQTTSUB: 0,0\r\n"

#define SIM7600_MQTT_DISCONNECT_CMD             "AT+CMQTTDISC"
#define SIM7600_MQTT_STOP_CMD                   "AT+CMQTTSTOP"

#define SIM7600_MQTT_RX_START_FLAG              "+CMQTTRXSTART:"
#define SIM7600_MQTT_RX_TOPIC_FLAG              "+CMQTTRXTOPIC:"
#define SIM7600_MQTT_RX_PAYLOAD_FLAG            "+CMQTTRXPAYLOAD:"
#define SIM7600_MQTT_RX_STOP_FLAG               "+CMQTTRXEND: 0\r\n"

//接收mqtt消息超时时间
#define SIM7600_MQTT_TIMEOUT                    30
#define SIM7600_MQTT_DELAY_TIME                 5


#define SIM7600_PAYLOAD_MAX_LENGTH              99
#define SIM7600_PAYLAOD_BUFF_SIZE               (SIM7600_PAYLOAD_MAX_LENGTH + 1)

#define MQTT_MAX_STEP                           6








//第一个数字是要发送的字符串的长度，如果 SERVER_ADDR或者URL发生变化，则要响应修改长度
//正式服务器
//#define HTTP_SERVER_ADDR                "www.yjiot.net" 
#define HTTP_SERVER_ADDR                  "io.bjyjyz.com" 
#define HTTP_SERVER_ADDR_1                "\"io.bjyjyz.com\"" 

#define HTTP_PORT                  80




#define HTTP_HEAD_METHOD_POST               "POST"

#define FOG_V2_ACTIVATE_URI                 ("/YJIOT/device/activate/")
#define FOG_V2_GET_TOKEN_URI                ("/YJIOT/device/token-auth/")
#define FOG_V2_SEND_EVENT_URI               ("/YJIOT/device/sendeventadv/")
#define FOG_V2_OTA_UP_DATA_URI              ("/YJIOT/device/updatecheck/")
#define FOG_V2_CHIPS_CONFIRM_URI            ("/YJIOT/device/chipsConfirm/")
#define FOG_V2_EXAM_UPLOAD_URI              ("/YJIOT/device/saveExamItem/")



//SIM7600 product id
#define PRODUCT_ID         "caef583f-f0d5-4f79-bfef-29c78ba802e1"

#define MXCHIPSN           "SIM7600CE"


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
#define POWER_KEY_GPIO_CLK      RCC_AHBPeriph_GPIOC
#define POWER_KEY_PORT          GPIOC
#define POWER_KEY_PIN           GPIO_Pin_14

#define POWER_KEY_HIGH()            GPIO_SetBits(POWER_KEY_PORT,POWER_KEY_PIN)
#define POWER_KEY_LOW()           GPIO_ResetBits(POWER_KEY_PORT,POWER_KEY_PIN)





typedef struct{
  
    unsigned char Is_wait_data;
    //unsigned char is_read_http_data;
    unsigned char type;
    char cmd[20];
    //char cmd_para[15];
    unsigned char string_length;
    char sendtring[50];
    unsigned long cmd_send_time;
    char end_flag[20];
    int cmd_result;
    unsigned char error_times;
    unsigned char timeout_times;

}SIM7600_Cmd_Typedef;


typedef struct{
  
    unsigned char Is_SIM7600_registerd;
  
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


//void SIM7600_Reset_Pin_Init(void);
//void SIM7600_Set(void);
//void SIM7600_Reset(void);
void SIM7600_PowerKey_Pin_Init(void);
//开机
void SIM7600_PowerKey_On(void);
//关机
void SIM7600_PowerKey_Off(void);
void SIM7600_Restart(void);
  

//unsigned char make_SIM7600_send_cmd_string(char *str_buff,char *cmd,char *cmd_para);
void clear_sim7600_uart_buff(void);
//int SIM7600_Send_data(unsigned char type,const char *cmd,const char *str);
//int SIM7600_Send_data(unsigned char type,const char *cmd,char *str,unsigned char string_length);
int SIM7600_Send_data(unsigned char type,const char *cmd,const char *http_requeset,uint16_t http_requeset_length);
int SIM7600_wait_response(void);
void parse_SIM7600_cmd_result(void);
int SIM7600_Get_Product_Info(void);

void SIM7600_http_loop(void);

void SIM7600_Get_Signal_Quality(void);

void SIM7600_Disnable_Command_Echo(void);
void SIM7600_Get_CCID(void);
void SIM7600_http_close(void);
void SIM7600_Device_Activate(void);
void SIM7600_Device_Token_auth(void);
void SIM7600_Ota_Check(void);
void SIM7600_Upload_Data(void);
void SIM7600_Status_Sync(void);
void SIM7600_Charge_Confirm(void);
unsigned char SIM7600_Upload_Factory_Check_Result(void);

void device_get_ccid(void);
//void device_get_signal_quality(void);
//void device_register_to_net(void);
//void device_activate(void);

int string_get_int(const char *string);
long string_get_long(const char *string);
void string_get_string(const char *string,char *dest);

void Wifi_Led_On(void);
void Wifi_Led_Off(void);
//主要检测2G卡是否卡死，如果连续通讯出错则重启，控制WIFI指示灯
void SIM7600_fogcloud_init_and_check(void);
//人工通过外部按键触发检测信息
void SIM7600_signal_check(void);

void SIM7600_fog_service_init(void);


void SIM7600_mqtt_init(void);
void SIM7600_get_mqtt_message(void);
//void SIM7600_mqtt_message_check(void);

//void SIM7600_get_mqtt_connect_status_cmd(void);
//void check_mqtt_status(void);


void SIM7600_mqtt_close(void);

#endif

