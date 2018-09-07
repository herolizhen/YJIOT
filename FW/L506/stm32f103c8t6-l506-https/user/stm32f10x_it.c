/**
  ******************************************************************************
  * @file    Project/Template/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.0.0
  * @date    04/06/2009
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2009 STMicroelectronics</center></h2>
  */ 

/* Includes ------------------------------------------------------------------*/
//#include "stm32f10x_it.h"
//#include  "ucos_ii.h" 
#include "includes.h"
#include "trans_recieve_buff_control.h"
#include "user_L506_task.h"
/** @addtogroup Template_Project
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval : None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval : None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval : None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval : None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval : None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval : None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval : None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval : None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval : None
  */
void SysTick_Handler(void)
{
    OSIntEnter(); 
    OSTimeTick(); 
    OSIntExit(); 
}

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval : None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 



//extern volatile uint8_t config_rx_index; 
//extern uint8_t user_config_rx_buff[USER_CONFIG_BUFF_SIZE];

void USART1_IRQHandler(void)
{
    OSIntEnter();
  
    if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
    {          
//        if(config_rx_index < USER_CONFIG_BUFF_SIZE)
//        {
//            user_config_rx_buff[config_rx_index++] = USART_ReceiveData(USART1); 
//        }
      
        USART_ClearITPendingBit(USART1, USART_IT_RXNE);  
    }
    else if(USART_GetITStatus(USART1, USART_IT_TXE) != RESET)
    {
        USART_ClearITPendingBit(USART1, USART_IT_TXE);  
    }
    
    OSIntExit();
}



uint8_t rx_index; 
extern uint8_t  m_Modbus_Master_RX_Buff[RX_Buff_SIZE];
//extern uint32_t recv_data_num;  
void USART2_IRQHandler(void)
{
    OSIntEnter();
  
    if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)
    {          
        //recv_data_num ++;
        Modbus_Master_Rece_Handler();
      
        USART_ClearITPendingBit(USART2, USART_IT_RXNE);  
    }
    else if(USART_GetITStatus(USART2, USART_IT_TXE) != RESET)
    {
        USART_ClearITPendingBit(USART2, USART_IT_TXE);  
    }
    
    OSIntExit();
}


extern volatile uint16_t uart_L506_rx_index;
void USART3_IRQHandler(void)
{
    OSIntEnter();
  
    if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
    {   
        uart_L506_rx_index += 1;
        L506_usart_recv_handler();
      
        USART_ClearITPendingBit(USART3, USART_IT_RXNE);  
    }
    else if(USART_GetITStatus(USART3, USART_IT_TXE) != RESET)
    {
        USART_ClearITPendingBit(USART3, USART_IT_TXE);  
    }
    
    OSIntExit();
}



/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
