/**
 * @file main.c
 * 
 * @brief This program demonstrates how to change the CPU access level from privileged to unprivileged and vice versa.
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 07-04-2024
 * 
 * @version 1.0
 */

/*
*===============================================
*                   Includes
*===============================================
*/

#include "EXTI/stm32f103x6_EXTI.h"
#include "CONTROL/Cortex_m_CONTROL.h"


/** @defgroup Functions_Declarations
  * @{
  */
void clock_init();

void EXTI_Init(void);

void EXTI9_ISR_Callback(void);
/**
  * @}
  */


int main(void)
{
	/** @defgroup Initialization
	  * @{
	  */
	clock_init();
	EXTI_Init();
	/**
	  * @}
	  */

	/*Switch to unprivileged*/
	CPU_changeAccessLevel(unprivilegedAccess);

	/*Switch to privileged*/
	CPU_changeAccessLevel(privilegedAccess);

	while(1)
	{

	}
}

/*
===============================================
*  				Functions definitions
*===============================================
*/

void clock_init()
{
	/*Enable GPIO_A*/
	APB2_PERI_CLOCK_EN(APB2_IOPA);

	/*Enable GPIO_B*/
	APB2_PERI_CLOCK_EN(APB2_IOPB);

	/*Enable GPIO_B*/
	APB2_PERI_CLOCK_EN(APB2_IOPC);

	/*Enable AFIO*/
	APB2_PERI_CLOCK_EN(APB2_AFIO);
}

void EXTI9_ISR_Callback(void)
{
	CPU_changeAccessLevel(privilegedAccess);
}

void EXTI_Init(void)
{
	EXTI_config_t config;
	config.PinConfig = EXTI_GPIOB_PIN9;
	config.EXTI_Trigger_Mode = EXTI_TRIGGER_RISING_EDGE;
	config.EXTI_Priority = 0;
	config.P_callback_func = EXTI9_ISR_Callback;
	config.EXTI_En = EXTI_ENABLE;
	MCAL_EXTI_Enable(&config);
}