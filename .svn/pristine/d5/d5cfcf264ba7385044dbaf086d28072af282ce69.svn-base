/****************************************
 * 文件名  ：main.c
 * 描述    ：建立2个任务，任务控制一个LED，以固定的频率轮流闪烁（频率可调）本板子带一个LED，另外一个建立一个任务，可以根据自己需要增加任务内容         
 * 实验平台：MINI STM32开发板 基于STM32F103C8T6
 * 库版本  ：ST3.0.0
 
**********************************************************************************/	

#include "includes.h"

OS_EVENT *stdio_tx_mutex;

OS_STK startup_task_stk[STARTUP_TASK_STK_SIZE];		  //定义栈

  
int main(void)
{
  	BSP_Init();
    mem_init(SRAMIN);		//初始化内部内存池
	  OSInit();
	  OSTaskCreate(Task_Start,(void *)0,
	     &startup_task_stk[STARTUP_TASK_STK_SIZE-1], STARTUP_TASK_PRIO);
    
	  OSStart();
    return 0;
}


