/*--------------------------------------------------------------------------
global.H

 extern global resource for C51.
--------------------------------------------------------------------------*/
#ifndef		_GLOBAL_H
#define		_GLOBAL_H

#include "touch_key.h"
#include "SOFT_IIC.h"
#include "common.h"
#include "user_timer.h"
#include "sys_run.h"


/*------------------------------------------------------------------------------------------
;								datastruct.c
;-----------------------------------------------------------------------------------------*/

//----------------------------�ƾڵ��c--------------------------------------------------------
typedef	unsigned char	Byte;
typedef	unsigned int	Word;
typedef	unsigned long	Dword;
//////////////////////////////////////////////////////////
typedef unsigned char BYTE;
typedef unsigned int  WORD;
typedef unsigned long DWORD;

typedef unsigned char uchar;
typedef unsigned int  uint;
typedef unsigned long ulong;

typedef unsigned char u8;
typedef unsigned char U8;
typedef unsigned int u16;
typedef unsigned int  U16;

//#define	uCHAR	unsigned char
//#define	sCHAR	signed   char
//#define	uINT	unsigned short
//#define	sINT	signed   short
//#define	uLONG	unsigned long
//#define	sLONG	signed long
//#define	npage	xdata
//#define	zpage	data
////////////////////////////////////////////////////

// mode SYS
#define  				STANDBY				0 //����
#define  				RUNNING				1 //������



#define _test_timeflag(x)    ((x == 1)?1:0) 


extern const unsigned char device_id ;

//Ӳ��UART0�������ݻ��������鳤�ȶ���
#define U0RxBuff_MAXSIZE   80
extern unsigned char U0RxBuffer[U0RxBuff_MAXSIZE];
extern volatile unsigned char U0RxPtr;


//ģ��UART2�������ݻ��������鳤�ȶ���
#define U2RxBuff_MAXSIZE   100
extern unsigned char U2RxBuffer[U2RxBuff_MAXSIZE];
extern unsigned char U2RxPtr;

#ifdef WIFI_SOFT_UART
#define U2TxBuff_MAXSIZE   100
extern unsigned char U2TxBuffer[U2TxBuff_MAXSIZE];
extern unsigned char U2TxPtr;
extern unsigned char U2LdPtr;
extern unsigned char U2TxBitCount;
extern unsigned char U2TxRate;
extern bit IsU2TxBusy;
extern bit IsU2RxBusy;
#endif

//ģ��UART3�������ݻ��������鳤�ȶ���
#define U3RxBuff_MAXSIZE   60
extern unsigned char U3RxBuffer[U3RxBuff_MAXSIZE];
extern unsigned char U3RxPtr;


#define U3TxBuff_MAXSIZE   200
extern unsigned char U3TxBuffer[U3TxBuff_MAXSIZE];
extern unsigned char U3TxPtr;
extern unsigned char U3LdPtr;
extern unsigned char U3TxBitCount;
extern unsigned char U3TxRate;
extern bit IsU3TxBusy;
extern bit IsU3RxBusy;


extern bit g_1ms_flag;
extern bit g_2ms_flag;
extern bit g_10ms_flag;
extern bit g_100ms_flag;
extern bit g_1s_flag;
extern unsigned long g_1s_times;
extern bit g_1min_flag;
extern unsigned long g_sys_time_ms;

extern unsigned char FGcount;

extern unsigned char speedBak;	//�������
extern bit gbMotorFGEn;
extern unsigned char gBMotorFGSet;
extern unsigned char speed_dang;
extern bit sys_mode;
extern bit run_mode;
extern bit gbMotorDelay;
//extern unsigned char	motor_startcnt; 
extern bit IsSpeedChanged;
extern bit IsFanRunning; 

extern unsigned int pwmDLbak;

extern signed long beats;

extern unsigned int gBuzzerTimes_cnt;
extern unsigned int gBuzzerEdge_cnt;

extern KEY_INFO_Typedef key_info;
extern IIC_Operations_Typedef IIC_Operations;

//extern bit IsSysFault;
extern bit IsStepMotorBusy;

//ADC
extern unsigned int n_data;
extern bit ADCfinish;
//UV
extern bit IsUVOn;
extern bit IsUVfault;
extern unsigned int uv_check_timeinterval;
extern bit IsUVCheck;
extern bit uv_check_flag;
extern char uv_check_times;

//�������ӹ���״̬λ
extern bit Is_ION_On;

//���Ŵ򿪱�־���α�־��ɨ��ʱ�·��Ĵ򿪲��ű�־
extern bit Is_Door_Open;
//�򿪲��ŵ�ʱ��
extern unsigned long door_open_time;

//����������
extern float PM25_value;
extern float PM25_value_bak;
extern float PM1_value;
extern float PM10_value;
extern float HCHO_value;

//��ʱ����
extern user_timer_t user_timer_info;


extern bit Is_selfcheck;

extern unsigned long sys_start_time;
extern unsigned long sys_stop_time;

//�������ʾ��PM����
extern unsigned int display_pm_value;


//�û���ʱ������
extern unsigned char user_timer_type;


//wifi����MCUϵͳ�Լ��־λ
extern bit is_sys_auto_check;
extern bit is_auto_check_complete;
//wifi����MCUϵͳ�Լ��־λ
extern bit is_sys_manual_check;

extern sys_check_t sys_check_info;


#endif