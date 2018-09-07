#include "dc_motor.h"
#include "global.h"
#include "UV.h"
#include "M26.h"
#include "sys_run.h"



bit g_1ms_flag = 0;
bit g_2ms_flag = 0;
bit g_10ms_flag = 0;
bit g_100ms_flag = 0;
bit g_1s_flag = 0;
unsigned long g_1s_times = 0;
//bit g_1min_flag = 0;
unsigned long idata g_sys_time_ms = 0;



//风机反馈信号FG的计数
unsigned char idata FGcount = 0;


unsigned char idata speedBak = 0;	    //电机控制
bit gbMotorFGEn = 0;  //是否根据FG调节转速标志      
unsigned char  idata gBMotorFGSet = 0;    
unsigned char	idata speed_dang = 0;
bit	sys_mode = 0; //系统运行模式，分为待机和运行	
bit	run_mode = 0; //运行模式分为自动和手动
bit gbMotorDelay = 0;
bit IsSpeedChanged = 0;  
bit IsFanRunning = 0;
unsigned int pwmDLbak = 0;     //当前PWM输出的占空比

signed long beats = 0;

unsigned int gBuzzerTimes_cnt = 0;
unsigned int gBuzzerEdge_cnt = 0;  //该变量调节模拟PWM的占空比


//硬件UART0
char idata U0RxBuffer[U0RxBuff_MAXSIZE] = {0};
unsigned char idata U0RxPtr = 0;



#ifdef WIFI_SOFT_IIC
//模拟UART2
unsigned char U2RxBuffer[U2RxBuff_MAXSIZE];
unsigned char U2RxPtr = 0;
unsigned char U2TxBuffer[U2TxBuff_MAXSIZE];
unsigned char U2TxPtr = 0;
unsigned char U2LdPtr = 0;
unsigned char U2TxBitCount = 0;
unsigned char U2TxRate = 0;
//IsU2TxBusy = 1时，表示模拟UART2正在发送数据，如果有数据要发送，发送缓冲区有数据，发送的数据不能放在发送缓冲区buffer第0个字节，而是放在正在发送的数据后面
bit IsU2TxBusy = 0;
bit IsU2RxBusy = 0;
#endif

//模拟UART3
#ifdef DEBUG_UART_RX
unsigned char U3RxBuffer[U3RxBuff_MAXSIZE];
unsigned char U3RxPtr = 0;
bit IsU3RxBusy = 0;
#endif
unsigned char U3TxBuffer[U3TxBuff_MAXSIZE];
unsigned char U3TxPtr = 0;
unsigned char U3LdPtr = 0;
unsigned char U3TxBitCount = 0;
unsigned char U3TxRate = 0;
//IsU2TxBusy = 1时，表示模拟UART2正在发送数据，如果有数据要发送，发送缓冲区有数据，发送的数据不能放在发送缓冲区buffer第0个字节，而是放在正在发送的数据后面
bit IsU3TxBusy = 0; 


//bit IsSysFault = 0;
bit IsStepMotorBusy = 0;


//UV
bit IsUVOn = 0;
bit IsUVfault = 0;
//UV灯检测时间间隔10分钟，每次启动UV灯10秒后检测第一次，以防止UV灯有问题，以后每隔10分钟检测一次
//每次UV启动是必须设置 uv_check_timeinterval = UV_CHECK_TIME_INTERVAL - 10,在UV_On()函数中
unsigned int uv_check_timeinterval = UV_CHECK_TIME_INTERVAL - 10;
bit IsUVCheck = 0;
bit uv_check_flag = 0;
//UV反馈电压检测：每个一段时间连续检测3秒，每秒检测一次，间隔时间在UV.h中的 UV_CHECK_TIME_INTERVAL 宏定义
//每次刚上电时，第一次检测到的ADC的值为0，所以初始化为-1，上电后最开始检测4次，忽略第1次，以后每次都是检测3次
char uv_check_times = -1; 

//负氧离子工作状态
bit Is_ION_On = 0;

//仓门打开标志，次标志是扫码时下发的打开仓门标志
bit Is_Door_Open = 0;

//打开仓门的时间
unsigned long door_open_time = 0;

//传感器数据
unsigned int PM25_value = 0;
unsigned int PM25_value_bak = 0; //用于记录开机时PM2.5的数据
//float PM1_value = 0;
//float PM10_value = 0;
//float HCHO_value = 0;


//系统自检标志位
//bit Is_selfcheck = 0;


//系统启动时间，用于处理传感器数据
unsigned long sys_start_time = 0;
//系统关闭时间，用于处理传感器数据
unsigned long sys_stop_time = 0;


unsigned int display_pm_value = 0;


//M26 IMEI号   字符串形式保存
//char M26_IMEI[20] = {0};
//因RAM空间限制，CCID和CHECK_ID公用同一个数组
char ccid[40] = {0};
bit Is_Get_CCID = 0;
char device_id[40] = {0};
//bit Is_Get_IMEI = 0;
bit Is_device_activate = 0;
bit Is_m26_wakeup = 0;

//读取信号质量时，检测误码率是否是0
bit Is_signal_err_code_zero = 0;

//m26启动后和服务器通讯的初始化工作是否结束
bit is_m26_fogcloud_init = 0;


unsigned long nowtime_ms = 0;
unsigned long nowtime_s = 0;




//设备状态
bit dev_status = 0;
//bit Is_status_sync = 0;
bit sync_this_loop = 0;
//如果同步数据上传错误或者超时，则下一次sync还需要上传设备状态
bit resync = 0;


//收到筹码标志位
bit charge_confirm = 0;
//收到DR命令后，需返回DR，收到DR标志位
bit dr_confirm = 0;
bit Is_send_dr_confirm = 0;

char order_num[41] = {0};

//用于计算上传数据的时间
unsigned long next_upload_data_time = 0;

//wifi指示灯状态
bit wifi_led_state = 0;

//是否被手动关闭标志位，包括手动关闭仓门和手动通过按键关闭
bit Is_close_by_man = 0;


//下次执行同步事件的时间
unsigned long next_sync_stime = 0;
//快速或者慢速同步状态标志位，当收到开仓门指令后同步时间间隔变为5秒，持续3分钟
bit is_fast_sync = 0;
//快速同步的开始时间
unsigned long fast_sync_start_time = 0;

//检测2G卡信号标志位
bit Is_signal_check = 0;
//检测信号时，和服务器通讯成功的次数
unsigned char signal_check_err_times = 0;


//wifi控制MCU系统自检标志位
bit is_sys_auto_check = 0;
bit is_auto_check_complete = 0;

//wifi控制MCU系统自检标志位
bit is_sys_manual_check = 0;

sys_check_t sys_check_info;


//上传自动测试结果标志位
bit is_upload_auto_check_result = 0;

//上传手动测试结果标志位
bit is_upload_manual_check_result = 0;



