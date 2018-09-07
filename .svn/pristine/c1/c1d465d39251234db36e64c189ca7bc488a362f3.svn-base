#ifndef __M26_H__
#define __M26_H__

#include "global.h"

#define  M26_WAIT_RESPONSE        1
#define  M26_IDLE                 2

//返回的错误码
#define  M26_OK                   0
#define  M26_BUSY                 1
//#define  M26_TIMEOUT             -2
//#define  M26_ACTIVE_ERROR        -3
//#define  M26_REGISTER_ERROR      -4
//#define  M26_HTTP_CONNECT_ERROR  -5
//#define  M26_HTTP_POST_ERROR     -6
//#define  M26_HTTP_READ_ERROR     -7

#define  M26_SEND_DATA_NULL        -20
#define  M26_CMD_TIME_OUT        -21


//发送指令后的超时时间
#define M26_TIME_OUT              27000


//#define M26_BUSY_CHECK()      {if(IsM26busy) return M26_BUSY;}

#define END_OK        "OK"
#define END_CONNECT   "CONNECT"
#define END_ERROR     "ERROR"

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
#define FIRMWARE_VERSION    "EP600S_M26@001"
//云版本号
#define IOT_VERSION         "1.0.0"


//#define M26_IMEI_LEN              15
#define M26_CCID_LEN              20

#define M26_CMD_END_FLAG           "\r\n"
//显示产品信息 
//#define M26_ATI_CMD                "ATI\r\n"
#define M26_ATI_CMD                "ATI"
//获取信号质量
#define M26_CSQ_CMD                "AT+CSQ"
//请求TA 序列号（IMEI）
#define M26_GSN_CMD                "AT+GSN"
//获取CCID
#define M26_QCCID_CMD                "AT+QCCID"

//读取SIM 卡服务运营商名称
#define M26_QSPN_CMD               "AT+QSPN"

//配置前置场景
#define M26_QIFGCNT_CMD            "AT+QIFGCNT=0"
//设置链接模式
#define M26_QICSGP_CM_CMD          "AT+QICSGP=1,\"CMNET\""
#define M26_QICSGP_CU_CMD          "AT+QICSGP=1,\"CUNET\""

#define M26_QICSGP_CMD             "AT+QICSGP"

//启动任务并设置接入点
#define M26_QIREGAPP_CMD           "AT+QIREGAPP"

//激活网络
#define M26_QIACT_CMD              "AT+QIACT"

//set HTTP Server URL 
#define M26_QHTTPURL_CMD           "AT+QHTTPURL"


//测试服务器
//#define SERVER_ADDR                "http://io.bjyjyz.com:8088" 
//#define M26_ACTIVATE_URL_PAR       "=44,30"
//#define M26_OTA_CHECK_URL_PAR      "=44,30"
//#define M26_UPLOAD_DATA_URL_PAR    "=38,30"
//#define M26_STATUS_SYNC_URL_PAR    "=38,30"
//#define M26_C_CONFIRM_URL_PAR      "=38,30"
//#define M26_FACTORY_CHECK_URL_PAR      "=39,30"


#define SERVER_ADDR                "http://io.bjyjyz.com" 
#define M26_ACTIVATE_URL_PAR       "=39,30"
#define M26_OTA_CHECK_URL_PAR      "=39,30"
#define M26_UPLOAD_DATA_URL_PAR    "=33,30"
#define M26_STATUS_SYNC_URL_PAR    "=33,30"
#define M26_C_CONFIRM_URL_PAR      "=33,30"
#define M26_FACTORY_CHECK_URL_PAR      "=34,30"


//第一个数字是要发送的字符串的长度，如果 SERVER_ADDR或者URL发生变化，则要响应修改长度
//正式服务器
//#define SERVER_ADDR                "http://www.yjiot.net" 
//#define M26_ACTIVATE_URL_PAR           "=39,30"
//#define M26_OTA_CHECK_URL_PAR          "=39,30"
//#define M26_UPLOAD_DATA_URL_PAR        "=33,30"
//#define M26_STATUS_SYNC_URL_PAR        "=33,30"
//#define M26_C_CONFIRM_URL_PAR          "=33,30"
//#define M26_FACTORY_CHECK_URL_PAR      "=34,30"

//http post
#define M26_QHTTPPOST_CMD          "AT+QHTTPPOST"
//#define M26_POST_ACTIVATE_PARA     "=58,50,10"
#define M26_POST_PARA     "=%d,50,10"

//http read
#define M26_QHTTPREAD_CMD          "AT+QHTTPREAD"
#define M26_HTTPREAD_PARA          "=30"



#define M26_ACTIVATE_URL           "/YJIOT/m26/activate"
#define M26_OTA_CHECK_URL          "/YJIOT/m26/otaCheck"
#define M26_UPLOAD_DATA_URL        "/YJIOT/m26/UD"
#define M26_STATUS_SYNC_URL        "/YJIOT/m26/SS"
#define M26_C_CONFIRM_URL          "/YJIOT/m26/CC"
#define M26_FACTORY_CHECK_URL      "/YJIOT/m26/SEI"


//EP600 WIFI product id
//#define PRODUCT_ID         "c4b56172-af28-11e7-9baf-00163e120d98"

//M26 product id
#define PRODUCT_ID         "f7901e54-dbbd-11e7-9baf-00163e120d98"


//#define DID                "45444fce-d12b-4c0d-9ea2-e5a3f3ebc306"
//#define ORDER_NUM          "b0d960a6-74d3-47fe-864b-fd6526a76d05"


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




#define M26_BIT_CHECK(x,x_bit)  ((x & (1 << x_bit))?1:0)

//M26 POWER ON PIN DEFINE
#define M26_POWER_PIN              P3_3
#define M26_POWER_PIN_PORTBIT      3
#define M26_POWER_PIN_PxM0         P3M0
#define M26_POWER_PIN_PxM1         P3M1


//M26 WAKEPU PIN DEFINE
#define M26_WAKEPU_PIN              P3_2
#define M26_WAKEPU_PIN_PORTBIT      2
#define M26_WAKEPU_PIN_PxM0         P3M0
#define M26_WAKEPU_PIN_PxM1         P3M1


//typedef struct{
//  
//    unsigned char Is_wait_data;
//    unsigned char type;
//    char cmd[25];
//    char cmd_para[15];
//    char sendtring[100];
//    unsigned long cmd_send_time;
//    char end_flag[10];
//    //char *end_flag;
//    int cmd_result;
//    unsigned char error_times;
//    unsigned char timeout_times;

//}M26_CMD_Typedef;

typedef struct{
  
    unsigned char Is_wait_data;
    unsigned char type;
    char cmd[25];
    char cmd_para[15];
    char sendtring[120];
    unsigned long cmd_send_time;
    char end_flag[10];
    int cmd_result;
    unsigned char error_times;
    unsigned char timeout_times;

}M26_Cmd_Typedef;


typedef struct{
  
    unsigned char Is_m26_registerd;
    unsigned char step;
  
}M26_RESGISTER_Typedef;




enum M26_DATA_TYPE{

    STRING_TYPE  = 0,
    CMD_TYPE     = 1  

};

enum M26_CMD_RESULT{
  
    CMD_IDLE       = 0,
    CMD_WAIT       = 1,
    CMD_SUCESS     = 2,
    CMD_ERROR      = 3,
    CMD_TIMEOUT    = 4
  
};


void M26_Power_Pin_Init(void);
void M26_Power_On(void);
void M26_Power_Off(void);
void M26_Wakeup_Pin_Init(void);
void M26_Wakeup(void);
void M26_Restart(void);
  

unsigned char make_m26_send_cmd_string(char *str_buff,char *cmd,char *cmd_para);
void clear_wifi_uart_buff(void);
int M26_Send_data(unsigned char type,const char *cmd,const char *str);
int M26_wait_response(void);
void check_m26_cmd_result(void);
int M26_Get_Product_Info(void);
void M26_Register_to_Net(void);

void m26_http_loop(void);

void M26_Get_Signal_Quality(void);

void M26_Get_CCID(void);
void M26_Device_Activate(void);
void M26_Ota_Check(void);
void M26_Upload_Data(void);
void M26_Status_Sync(void);
void M26_Charge_Confirm(void);
unsigned char M26_Upload_Factory_Check_Result(void);

void device_get_ccid(void);
//void device_get_signal_quality(void);
//void device_register_to_net(void);
void device_activate(void);

int string_get_int(const char *string);
long string_get_long(const char *string);
void string_get_string(const char *string,char *dest);

void Wifi_Led_On(void);
void Wifi_Led_Off(void);
//主要检测2G卡是否卡死，如果连续通讯出错则重启，控制WIFI指示灯
void m26_fogcloud_init_and_check(void);
//人工通过外部按键触发检测信息
void m26_signal_check(void);

void m26_fog_service_init(void);





#endif