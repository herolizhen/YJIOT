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

//http start
#define SIM7600_HTTP_ACT_CMD           "AT+CHTTPACT"
#define SIM7600_HTTP_ACT_RES           "REQUEST\r\n"

//http stop
//虚构的一个命令，其实并没有这个命令，真正发送的是结束标志0x1A，因为0x1A不好进行字符串处理
#define SIM7600_HTTP_END_CMD            "AT+CHTTPSTOP"
#define SIM7600_HTTP_END_FLAG           0x1A
//#define SIM7600_HTTP_END_RES           "OK\r\n"
#define SIM7600_HTTP_END_RES           "0\r\n\r\n"
#define SIM7600_HTTP_STOP_FLAG          "+CHTTPACT: 0\r\n"

#define HTTP_MAX_STEP                3 






//mqtt
#define SIM7600_MQTT_SSL_CMD              "AT+MQTTSSL"
#define SIM7600_MQTT_CONFIG_CMD           "AT+MCONFIG"
#define SIM7600_MQTT_START_CMD            "AT+MIPSTART"
#define SIM7600_MQTT_CONNECT_CMD          "AT+MCONNECT"
#define SIM7600_MQTT_SUB_CMD              "AT+MSUB"

#define SIM7600_MQTT_DISCONNECT_CMD       "AT+MDISCONNECT"
#define SIM7600_MQTT_CLOSE_CMD            "AT+MIPCLOSE"

#define SIM7600_MQTT_STATUS               "AT+MQTTSTATU"

#define MQTT_CMD_SUCCESS               "SUCCESS"
#define MQTT_MAX_STEP                  5


#define MQTT_SERVER_ADDR                "io.bjyjyz.com" 



//测试服务器
//#define SERVER_ADDR                "http://io.bjyjyz.com:8088" 
//#define SIM7600_ACTIVATE_URL_PAR       "=44,30"
//#define SIM7600_OTA_CHECK_URL_PAR      "=44,30"
//#define SIM7600_UPLOAD_DATA_URL_PAR    "=38,30"
//#define SIM7600_STATUS_SYNC_URL_PAR    "=38,30"
//#define SIM7600_C_CONFIRM_URL_PAR      "=38,30"
//#define SIM7600_FACTORY_CHECK_URL_PAR      "=39,30"


//#define SERVER_ADDR                "http://io.bjyjyz.com" 
//#define SIM7600_ACTIVATE_URL_PAR       "=39,30"
//#define SIM7600_OTA_CHECK_URL_PAR      "=39,30"
//#define SIM7600_UPLOAD_DATA_URL_PAR    "=33,30"
//#define SIM7600_STATUS_SYNC_URL_PAR    "=33,30"
//#define SIM7600_C_CONFIRM_URL_PAR      "=33,30"
//#define SIM7600_FACTORY_CHECK_URL_PAR      "=34,30"


//第一个数字是要发送的字符串的长度，如果 SERVER_ADDR或者URL发生变化，则要响应修改长度
//正式服务器
//#define HTTP_SERVER_ADDR                "www.yjiot.net" 
#define HTTP_SERVER_ADDR                  "io.bjyjyz.com" 
#define HTTP_SERVER_ADDR_1                "\"io.bjyjyz.com\"" 

#define HTTP_PORT                  80
#define MQTT_PORT                  "1883"



#define HTTP_HEAD_METHOD_POST               "POST"

#define FOG_V2_ACTIVATE_URI                 ("/YJIOT/device/activate/")
#define FOG_V2_SEND_EVENT_URI               ("/YJIOT/device/sendeventadv/")
#define FOG_V2_OTA_UP_DATA_URI              ("/YJIOT/device/updatecheck/")
#define FOG_V2_CHIPS_CONFIRM_URI              ("/YJIOT/device/chipsConfirm/")
#define FOG_V2_EXAM_UPLOAD_URI              ("/YJIOT/device/saveExamItem/")

//#define SIM7600_ACTIVATE_URL           "/YJIOT/device/activate"
//#define SIM7600_OTA_CHECK_URL          "/YJIOT/SIM7600/otaCheck"
//#define SIM7600_UPLOAD_DATA_URL        "/YJIOT/SIM7600/UD"
//#define SIM7600_STATUS_SYNC_URL        "/YJIOT/SIM7600/SS"
//#define SIM7600_C_CONFIRM_URL          "/YJIOT/SIM7600/CC"
//#define SIM7600_FACTORY_CHECK_URL      "/YJIOT/SIM7600/SEI"



//#define SIM7600_ACTIVATE_URL           "/YJIOT/m26/activate"
//#define SIM7600_OTA_CHECK_URL          "/YJIOT/m26/otaCheck"
//#define SIM7600_UPLOAD_DATA_URL        "/YJIOT/m26/UD"
//#define SIM7600_STATUS_SYNC_URL        "/YJIOT/m26/SS"
//#define SIM7600_C_CONFIRM_URL          "/YJIOT/m26/CC"
//#define SIM7600_FACTORY_CHECK_URL      "/YJIOT/m26/SEI"


//EP600 WIFI product id
//#define PRODUCT_ID         "c4b56172-af28-11e7-9baf-00163e120d98"

//SIM7600 product id
#define PRODUCT_ID         "caef583f-f0d5-4f79-bfef-29c78ba802e1"

#define MXCHIPSN           "SIM7600CE"


//http事件位定义
#define HTTP_ACTIVATE           0
#define HTTP_OTA                1
#define HTTP_UPLOAD_DATA        2
#define HTTP_SYNC               3
#define HTTP_C_CONFIRM          4
#define HTTP_FACTORY_CHECK      5


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
    unsigned char is_read_http_data;
    unsigned char type;
    char cmd[15];
    //char cmd_para[15];
    unsigned char string_length;
    char sendtring[120];
    unsigned long cmd_send_time;
    char end_flag[15];
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
int SIM7600_Send_data(unsigned char type,const char *cmd,const char *http_requeset);
int SIM7600_wait_response(void);
void parse_SIM7600_cmd_result(void);
int SIM7600_Get_Product_Info(void);

void SIM7600_http_loop(void);

void SIM7600_Get_Signal_Quality(void);

void SIM7600_Get_CCID(void);
void SIM7600_http_close(void);
void SIM7600_Device_Activate(void);
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


//void SIM7600_mqtt_init(void);
//void SIM7600_mqtt_message_check(void);
//void SIM7600_mqtt_close(void);
//void SIM7600_get_mqtt_connect_status_cmd(void);
//void check_mqtt_status(void);




#endif

