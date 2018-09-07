#include "dc_motor.h"
#include "global.h"
#include "UV.h"
#include "sys_run.h"

const unsigned char device_id = 1;

bit g_1ms_flag = 0;
bit g_2ms_flag = 0;
bit g_10ms_flag = 0;
bit g_100ms_flag = 0;
bit g_1s_flag = 0;
unsigned long g_1s_times = 0;
bit g_1min_flag = 0;
unsigned long g_sys_time_ms = 0;
//unsigned long g_sys_time_s = 0;


//��������ź�FG�ļ���
unsigned char FGcount = 0;


unsigned char speedBak = 0;	    //�������
bit gbMotorFGEn = 0;  //�Ƿ����FG����ת�ٱ�־      
unsigned char gBMotorFGSet = 0;    
unsigned char	speed_dang = 0;
bit	sys_mode = 0; //ϵͳ����ģʽ����Ϊ����������	
bit	run_mode = 0; //����ģʽ��Ϊ�Զ����ֶ�
bit gbMotorDelay = 0;
bit IsSpeedChanged = 0;  
bit IsFanRunning = 0;
unsigned int pwmDLbak = 0;     //��ǰPWM�����ռ�ձ�

signed long beats = 0;

unsigned int gBuzzerTimes_cnt = 0;
unsigned int gBuzzerEdge_cnt = 0;  //�ñ�������ģ��PWM��ռ�ձ�


//Ӳ��UART0
unsigned char U0RxBuffer[U0RxBuff_MAXSIZE] = {0};
unsigned char U0RxPtr = 0;

#ifdef WIFI_SOFT_UART
//ģ��UART2
unsigned char U2RxBuffer[U2RxBuff_MAXSIZE];
unsigned char U2RxPtr = 0;
unsigned char U2TxBuffer[U2TxBuff_MAXSIZE];
unsigned char U2TxPtr = 0;
unsigned char U2LdPtr = 0;
unsigned char U2TxBitCount = 0;
unsigned char U2TxRate = 0;
//IsU2TxBusy = 1ʱ����ʾģ��UART2���ڷ������ݣ����������Ҫ���ͣ����ͻ����������ݣ����͵����ݲ��ܷ��ڷ��ͻ�����buffer��0���ֽڣ����Ƿ������ڷ��͵����ݺ���
bit IsU2TxBusy = 0;
bit IsU2RxBusy = 0;
#endif

//ģ��UART3
unsigned char U3RxBuffer[U3RxBuff_MAXSIZE];
unsigned char U3RxPtr = 0;
unsigned char U3TxBuffer[U3TxBuff_MAXSIZE];
unsigned char U3TxPtr = 0;
unsigned char U3LdPtr = 0;
unsigned char U3TxBitCount = 0;
unsigned char U3TxRate = 0;
//IsU2TxBusy = 1ʱ����ʾģ��UART2���ڷ������ݣ����������Ҫ���ͣ����ͻ����������ݣ����͵����ݲ��ܷ��ڷ��ͻ�����buffer��0���ֽڣ����Ƿ������ڷ��͵����ݺ���
bit IsU3TxBusy = 0; 
bit IsU3RxBusy = 0;

bit IsSysFault = 0;
bit IsStepMotorBusy = 0;

//UV
bit IsUVOn = 0;
bit IsUVfault = 0;
//UV�Ƽ��ʱ����10���ӣ�ÿ������UV��10������һ�Σ��Է�ֹUV�������⣬�Ժ�ÿ��10���Ӽ��һ��
//ÿ��UV�����Ǳ������� uv_check_timeinterval = UV_CHECK_TIME_INTERVAL - 10,��UV_On()������
unsigned int uv_check_timeinterval = UV_CHECK_TIME_INTERVAL - 10;
bit IsUVCheck = 0;
bit uv_check_flag = 0;
//UV������ѹ��⣺ÿ��һ��ʱ���������3�룬ÿ����һ�Σ����ʱ����UV.h�е� UV_CHECK_TIME_INTERVAL �궨��
//ÿ�θ��ϵ�ʱ����һ�μ�⵽��ADC��ֵΪ0�����Գ�ʼ��Ϊ-1���ϵ���ʼ���4�Σ����Ե�1�Σ��Ժ�ÿ�ζ��Ǽ��3��
char uv_check_times = -1; 

//�������ӹ���״̬
bit Is_ION_On = 0;

//���Ŵ򿪱�־���α�־��ɨ��ʱ�·��Ĵ򿪲��ű�־
bit Is_Door_Open = 0;
//�򿪲��ŵ�ʱ��
unsigned long door_open_time = 0;

//����������
float PM25_value = 0;
float PM25_value_bak = 0; //���ڼ�¼����ʱPM2.5������
//float PM1_value = 0;
//float PM10_value = 0;
//float HCHO_value = 0;


//ϵͳ�Լ��־λ
bit Is_selfcheck = 0;


//ϵͳ����ʱ�䣬���ڴ�������������
unsigned long sys_start_time = 0;
//ϵͳ�ر�ʱ�䣬���ڴ�������������
unsigned long sys_stop_time = 0;


unsigned int display_pm_value = 0;



//wifi����MCUϵͳ�Լ��־λ
bit is_sys_auto_check = 0;
bit is_auto_check_complete = 0;
//wifi����MCUϵͳ�Լ��־λ
bit is_sys_manual_check = 0;

sys_check_t sys_check_info;







