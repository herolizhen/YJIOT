#include <stdio.h>
#include "global.h"
#include "sys_run.h"
#include "dc_motor.h"
#include "step_motor.h"
#include "sensor.h"
#include "buzzer.h"
#include "UV.h"
#include "wifi_uart.h"
//#include "common.h"
#include "ION.h"
#include "debug_uart.h"
#include "TM1620.h"
#include "timer.h"






//防止仓门坏了，开机时必须进行仓门检测。如果仓门坏了再打开风机可能会烧坏风机
void sys_init_check(void)
{
    //unsigned char delay_1s_times = 0;

    if(!DOOR_CHECK_PIN)
    {
        //此处加的Is_Door_Open = 1，因为刚上电情况下Is_Door_Open=0，Door_Close()函数中会判断如果况下Is_Door_Open==0，则直接返回
        Is_Door_Open = 1;
        Door_Close();
    }
    else
    {
        return;
    }
    while(1)
    {
        if(_test_timeflag(g_2ms_flag))
        {
            g_2ms_flag = 0;
            TurnMotor();           
        } 
      
        if(_test_timeflag(g_1s_flag))
        {
            g_1s_flag = 0;
            //delay_1s_times += 1;
            if(beats == 0)
            {
                //IsSysFault = 0;
                return;
            }           
        }
    }
}



void sys_start(void)
{
    sys_start_time = get_sys_stime();
    UV_On();
    ION_On();
  
    Buzzer_Power_On();  
  
    //开启UV灯后延时一段时间，不让所有设备同时启动  
    while(get_sys_stime() < (sys_start_time + 2)) ;
  
    

    if(Is_Door_Open == 0 || (Is_Door_Open == 1 && DOOR_CHECK_PIN == 1))
    {
        Door_Open();
    }
    Start_DC_Motor();
    
    
    sys_mode = RUNNING;
    IsFanRunning = 1;
    IsSpeedChanged = 1;
    TM1620_LED_Control(LED_SLEEP_MODE,LED_OFF);
    TM1620_LED_Control(LED_SPEED_LOW,LED_ON);
    
    Is_close_by_man = 0;
}

void sys_stop(void)
{
    sys_stop_time = get_sys_stime();
    Buzzer_Power_Off();
    sys_mode = STANDBY;
    Stop_DC_Motor();
    Door_Close();
    UV_Off();
    ION_Off();  
    IsSpeedChanged = 1;

    TM1620_LED_Control(LED_ALL,LED_OFF);
    TM1620_LED_Control(LED_SLEEP_MODE,LED_ON);
  
    if(run_mode == 1)
    {  
       stop_sys_smart_mode();
    }
    
    if(is_sys_auto_check == 1)
    {
        stop_sys_auto_check();
    }
  
    IsUVfault = 0;
    Is_close_by_man = 1;
}


void sys_run(void)
{
    unsigned char set_speed = 0;
   
    //wifi配网永远有效,wifi配网需组合按键持续按下超过2秒才进入配网模式，防止误操作
    if(key_info.IsTouchedKey == 1 && key_info.WhichKey == KEY_WIFI)
    {
        wifi_earse_easylink_cmd();
        Clear_Touch_Info();
    }
    
    //如果有人把仓门关闭了，则机器进入待机状态
    if(is_sys_auto_check == 0)
    {
        check_if_doorclose_manual();
    }
  
  
    if(key_info.IsTouchedKey == 1)
    {
        switch(key_info.WhichKey)
        {
          case KEY_POWER:
            if(is_sys_manual_check == 1)
            {
                sys_check_info.touch_key_check |= (1 << power_bit);
            }
            
            if(sys_mode == STANDBY)
            {
                sys_start();             
            }
            else if(sys_mode == RUNNING)
            { 
                sys_stop();              
            }
            break;
          case KEY_SPEED:
            if(sys_mode == RUNNING)
            {
                Buzzer_Speed();
                set_speed = speed_dang;
                if(speed_dang < HIGH_SPEED )
                {
                    set_speed++;
                }
                else if(speed_dang == HIGH_SPEED)
                {
                    set_speed = QUIET_SPEED;
                }
                else
                {
                    set_speed = 0;
                }
                Set_DC_Motor_Speed(set_speed);
                
                if(is_sys_manual_check == 1)
                {
                    if(speed_dang == QUIET_SPEED)
                    {
                        sys_check_info.touch_key_check |= (1 << quiet_speed_bit);
                    }
                    else if(speed_dang == LOW_SPEED)
                    {
                        sys_check_info.touch_key_check |= (1 << low_speed_bit);
                    }
                    else if(speed_dang == MID_SPEED)
                    {
                        sys_check_info.touch_key_check |= (1 << mid_speed_bit);
                    }
                    else if(speed_dang == HIGH_SPEED)
                    {
                        sys_check_info.touch_key_check |= (1 << high_speed_bit);
                    }
                } 
                
                
                //在自动模式下，如果手动调节风量了，则取消自动模式
                if(run_mode == 1)
                {
                    stop_sys_smart_mode();
                }
                
            }
            else
            {
                break;
            }
            break;
          case KEY_TIMER:  
            if(is_sys_manual_check == 1)
            {
                sys_check_info.touch_key_check |= (1 << timer_bit);
            }

            if(sys_mode == RUNNING)
            {
                if(user_timer_type < USER_TIMER_4H)
                {
                    user_timer_type += 1;
                    set_user_timer(user_timer_type);
                }
                else
                {
                    stop_user_timer();
                }
                Buzzer_Touch_Key();               
            }             
            break;
          case KEY_MODE: 
            if(is_sys_manual_check == 1)
            {
                sys_check_info.touch_key_check |= (1 << mode_bit);
            } 
            if(sys_mode == RUNNING)
            {
                run_mode = !run_mode;
                if(run_mode == 0)
                {
                    stop_sys_smart_mode();
                }
                else
                {
                    set_sys_to_smart_mode();
                }
                Buzzer_Touch_Key();     
            }             
            break;
          case KEY_WIFI:
            //control wifi to easylink mode  
            if(is_sys_manual_check == 1)
            {
                sys_check_info.touch_key_check |= (1 << wifi_bit);
            }           
            break;            
            
            
          default:
            break;
            
        
        }
        if(key_info.IsTouchedKey == 1 && key_info.WhichKey != KEY_WIFI)
        {
            Clear_Touch_Info();
        }
        
    }
    
    if(run_mode == 1)
    {
        sys_smart_mode();
    }

}


void display_sensor_data(void)
{  
    if(is_sys_auto_check == 1)
    {
        return;
    }
   
    nowtime_s = get_sys_stime();
    
    if(nowtime_s % 10 == 0)
    {
        TM1620_DispalyData(SENSOR_PM25,(float)display_pm25_value);
    }
    else if(nowtime_s % 10 == 5)
    {
        TM1620_DispalyData(SENSOR_HCHO,display_HCHO_value);
    }    
}




//在自动模式下，风机档位切换后10秒钟内不允许再次切换，否则PM在临界值时会非常频繁的切换档位，体验不好
void sys_smart_mode(void)
{
    
    static bit speed_changed = 0;   //防止PM浓度在临界值时，频繁切换档位
    static bit IsLedChange = 0;
    static unsigned long speed_changed_time = 0;   //上次切换风挡时的时间
  
    const unsigned char code speed_continue_time = 10;  //10秒钟内不能再次切换风挡
    
  
    
    nowtime_s = get_sys_stime();
    
    if(speed_changed == 1)
    {
        //风机档位刚切换过，10秒以后才能切换
        if(nowtime_s <= (speed_changed_time + speed_continue_time))
        {
            return;
        }
        else
        {
            speed_changed = 0;
        }
        
    }
    
    if(display_pm25_value < PM25_QUIET_SPEED )
    {
        if(speed_dang != QUIET_SPEED)
        {
            speed_dang = QUIET_SPEED;
            IsSpeedChanged = 1;
            speed_changed = 1;
            IsLedChange = 1;
        }       
    }
    else if(display_pm25_value < PM25_LOW_SPEED)
    {
        if(speed_dang != LOW_SPEED)
        {
            speed_dang = LOW_SPEED;
            IsSpeedChanged = 1;
            speed_changed = 1;
            IsLedChange = 1;
        }  
    }
    else
    {
        if(speed_dang != HIGH_SPEED)
        {
            speed_dang = HIGH_SPEED;
            IsSpeedChanged = 1;
            speed_changed = 1;
            IsLedChange = 1;
        }
    }   

    if(IsLedChange == 1)
    {
        //自动模式下，风挡变后，LED灯也要相应的变化
        TM1620_LED_Control(speed_dang + 1,LED_ON);
        IsLedChange = 0;       
    }  

    

}





//系统运行时，如果有人手动把仓门关闭了，则机器进入待机模式
//检测方法：100ms检测一次仓门，如果连续2秒钟仓门都是关闭的，则机器进入待机模式
#define MAX_DOOR_CLOSE_TIMES    20
void check_if_doorclose_manual(void)
{
    static unsigned char check_doorclose_times = 0;
 
    if(sys_mode == RUNNING)
    {
        nowtime_s = get_sys_stime();
        if(nowtime_s >= (sys_start_time + 10))
        {
            if(g_100ms_flag == 1)
            {
                if(DOOR_CHECK_PIN == 1)
                {
                    check_doorclose_times += 1;
                }
                else
                {
                    check_doorclose_times = 0;
                }
                
                if(check_doorclose_times >= MAX_DOOR_CLOSE_TIMES)
                {
                    if(sys_mode == RUNNING)
                    {
                        sys_stop();
                        Is_close_by_man = 1;
                        check_doorclose_times = 0;
                    }

                }
            }
        }
    }

}


void set_sys_to_smart_mode(void)
{
    run_mode = 1;
    TM1620_LED_Control(LED_AUTO_MODE,LED_ON);
}

void stop_sys_smart_mode(void)
{
    run_mode = 0;
    TM1620_LED_Control(LED_AUTO_MODE,LED_OFF);
}




//系统自检
//当仓门关闭时，仓门检测引脚是高电平；当仓门打开时，仓门检测引脚是低电平
//status是系统检测标志，bit0表示仓门，bit1表示风机，bit2表示uv灯

//sys_check_info.status的bit位为1表示检测设备有问题，0表示正常

//此函数的执行间隔必须是100ms，因为FGcount的采集周期是100ms
void sys_dev_auto_check(void)
{

    //系统检测UV和风机的时间
    static const unsigned long sys_check_time = 30;
    unsigned long nowtime = 0;
  
    sys_check_info.fg_count = FGcount;
    FGcount = 0;  

  
    //step0  关机
    if(sys_check_info.step == 0)
    {
        if(sys_mode == RUNNING)
        {
            sys_stop();
            is_sys_auto_check = 1;
        }
        sys_check_info.step += 1;
        is_auto_check_complete = 0;
    }     
    else if(sys_check_info.step == 1)  //step1  检测仓门是否可以关闭或者检测开关是否有问题
    {        
        if(beats == 0)
        {
            if(DOOR_CHECK_PIN == 0)
            {
                //仓门故障
                //sys_check_info.status = ((1 << door_bit) | (1 << fan_bit) | (1 << uv_bit));
                is_auto_check_complete = 1;
                goto exit;
            }
            else
            {               
                sys_check_info.step += 1;
            }
        }        
    }
    else if(sys_check_info.step == 2)    //step2  打开机器
    {       
        sys_start();
        sys_check_info.step += 1;             
    }
    else if(sys_check_info.step == 3)    //step3 检测仓门是否打开
    {
        if(beats == 0)
        {
            if(DOOR_CHECK_PIN == 0)
            {
                //仓门正常,对应的bit位清零
                sys_check_info.status &= ~(1 << door_bit);
                //sys_check_info.status = 0;
                sys_check_info.step += 1;
            }
            else
            {  
                //sys_check_info.status = ((1 << door_bit) | (1 << fan_bit) | (1 << uv_bit));
                is_auto_check_complete = 1;
                goto exit;
            }
        }
          
        
    }
    else if(sys_check_info.step == 4)    //step4  检测风机和UV灯
    {
        nowtime = get_sys_stime();
        //检测风机和UV灯有效时间20秒
        if(nowtime >= (sys_start_time + 10) && nowtime <= (sys_start_time + sys_check_time))
        {
//            if(IsUVfault == 1)
//            {
//                sys_check_info.status |= (1 << uv_bit);
//            }
            

            if(sys_check_info.fg_count < (SPEED_FG_COUNT2 - 1) || sys_check_info.fg_count > (SPEED_FG_COUNT2 + 1))
            //if(sys_check_info.fg_count < 12 || sys_check_info.fg_count > 14)
            {              
                if(sys_check_info.fan_check_fault_times < 0xFF)
                {
                    sys_check_info.fan_check_fault_times += 1;
                }
            }
                         
                        
        }
        else if(nowtime > (sys_start_time + sys_check_time))
        {
            //在Dcmoto_adj()函数中判断FGcount反馈信号，100ms检测一次，20秒共检测200次，反馈信号并不是一个固定值，而是在一定范围内波动，按出错概率进行检测
          
            if(IsUVfault == 0)
            {
                sys_check_info.status &= ~(1 << uv_bit);
            }
            
            if(sys_check_info.fan_check_fault_times < 30)
            {
                sys_check_info.status &= ~(1 << fan_bit);
            }
            if((int)PM25_value > 0)
            {
                sys_check_info.status &= ~(1 << pm25_bit);
            }
            is_auto_check_complete = 1;
        }
    }

    
    
    
    
exit:
    if(is_auto_check_complete == 1)
    {
        stop_sys_auto_check();        
    }
}


void start_sys_auto_check(void)
{
    is_sys_auto_check = 1;
    sys_check_info.step = 0;
    sys_check_info.status = 0xFF;
    sys_check_info.fan_check_fault_times = 0;  
    
}

void stop_sys_auto_check(void)
{
    is_sys_auto_check = 0;
    
    if(is_auto_check_complete == 1)
    {
        sys_check_auto_result_upload();
    }
    is_auto_check_complete = 0;
    if(sys_mode == RUNNING)
    {
        sys_stop();
    }
}

void start_sys_manual_check(void)
{
    is_sys_manual_check = 1;
    sys_check_info.touch_key_check = 0;
    sys_check_info.start_time = get_sys_stime();
    Buzzer_Get_Charge();
    
}

void check_if_stop_manual_check(void)
{
    //手动检测的最大时间，如果3分钟内不停止则自动停止
    const unsigned long check_max_time = 180;
    if(get_sys_stime() >= (sys_check_info.start_time + check_max_time))
    {        
        stop_sys_manual_check();
    }
}


void stop_sys_manual_check(void)
{
    is_sys_manual_check = 0;
    sys_check_manual_result_upload();
    Buzzer_Get_Charge();
}
















