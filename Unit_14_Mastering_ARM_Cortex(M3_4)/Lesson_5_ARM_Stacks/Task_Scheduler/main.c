/**
 * @file main.c
 * 
 * @brief 
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

#include "GPIO/stm32f103x6_GPIO.h"
#include "EXTI/stm32f103x6_EXTI.h"
#include "SYSTICK/Cortex_m3_SYSTICK_Interface.h"

/** @defgroup GLOBAL_MACROS
  * @{
  */
#define MAIN_STACK_SIZE    		512

#define TASKA_STACK_SIZE     	100
#define TASKB_STACK_SIZE     	100


#define OS_SET_PSP(address)         __asm volatile("MSR PSP, %[in]" : : [in] "r" (address))
#define OS_USE_PSP                  __asm volatile("MRS R0, CONTROL \n\t ORR R0, R0, #0x02 \n\t MSR CONTROL, R0")
#define OS_USE_MSP                  __asm volatile("MRS R0, CONTROL \n\t AND R0, R0, #0xFD \n\t MSR CONTROL, R0")
#define OS_UNPRIVILEGED_ACCESS 		__asm volatile("MRS R0, CONTROL \n\t ORR R0, R0, #0x1  \n\t MSR CONTROL, R0")
#define OS_PRIVILEGED_ACCESS        __asm volatile("MRS R0, CONTROL \n\t LSR R0, R0, #0x1  \n\t \
												    LSL R0, R0,#0x1 \n\t MSR CONTROL, R0")
/**
  * @}
  */

/** @defgroup GLOBAL_Variables
  * @{
  */

/**
 * @brief Symbol containing the start address of the stack. which is calculated by the linker script.
 */
extern uint32 _estack;			

/** @defgroup  Main stack pointer region.
  * @{
  */
uint32 _s_MSP;
uint32 _e_MSP;
/**
  * @}
  */

/** @defgroup Task A stack region in the process stack.
  * @{
  */
uint32 _s_TA_PSP;
uint32 _e_TA_PSP;
/**
  * @}
  */

/** @defgroup Task B stack region in the process stack.
  * @{
  */
uint32 _s_TB_PSP;
uint32 _e_TB_PSP;
/**
  * @}
  */

uint8 Glob_u8TaskAFlag;
uint8 Glob_u8TaskBFlag;
/**
  * @}
  */

/** @defgroup Functions_Declarations
  * @{
  */
void clock_init();

void GPIO_Init(void);

void EXTI_Init(void);

void EXTI9_ISR_Callback(void);

/**
 * @brief Task A toggles GPIOB bit_0 
 * 
 */
void TaskA(void);

/**
 * @brief Task B toggles GPIOB bit_1 
 * 
 */
void TaskB(void);

/**
 * @brief Chooses which task (A, B) to run.
 * 
 */
void OS_Scheduler(void);
/**
  * @}
  */


int main(void)
{
	/** @defgroup Initialization
	  * @{
	  */
	clock_init();
	GPIO_Init();
	EXTI_Init();
	/**
	  * @}
	  */

	OS_Scheduler();
}

/*
===============================================
*  				Functions definitions
*===============================================
*/

void clock_init()
{
	/*Enable GPIO_B*/
	APB2_PERI_CLOCK_EN(APB2_IOPB);

	/*Enable AFIO*/
	APB2_PERI_CLOCK_EN(APB2_AFIO);
}

void GPIO_Init(void)
{
	GPIO_Pin_Config_t init;
	init.pinNumber = GPIO_PIN0;
	init.pinMode = GPIO_MODE_GP_OUTPUT_PP_2MHZ;
	MCAL_GPIO_Init(GPIOB, &init);

	init.pinNumber = GPIO_PIN1;
	MCAL_GPIO_Init(GPIOB, &init);
}

void EXTI9_ISR_Callback(void)
{
	static uint8 sLOC_u8ISRFlag = 0;

	if(sLOC_u8ISRFlag == 0)
	{
		Glob_u8TaskAFlag = 1;
		sLOC_u8ISRFlag = 1;

	}else if(sLOC_u8ISRFlag == 1)
	{

		Glob_u8TaskBFlag = 1;
		sLOC_u8ISRFlag = 0;
	}
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

void OS_Scheduler(void)
{
	/*Setting the stack space*/
	_s_MSP = (uint32)&_estack;	/*Put the start of the stack as the start of the main stack pointer*/
	_e_MSP = (_s_MSP - MAIN_STACK_SIZE);

	/*Set TaskA stack region to begin after 8 bytes from the end of the main stack*/
	_s_TA_PSP = (_e_MSP - 8);
	_e_TA_PSP = (_s_TA_PSP - TASKA_STACK_SIZE);

	/*Set TaskB stack region to begin after 8 bytes from the end of the TaskA stack*/
	_s_TB_PSP = (_e_TA_PSP - 8);
	_e_TB_PSP = (_s_TB_PSP - TASKB_STACK_SIZE);

	/*To use the systick timer to switch between the tasks instead of doing it 
	manually using EXTI.*/
	//MCAL_SYST_SetIntervalPeriodic(1000, EXTI9_ISR_Callback);

	while(1)
	{
		if(Glob_u8TaskAFlag == 1)
		{
			/*Reset the flag to prevent us from executing TaskA more than once*/
			Glob_u8TaskAFlag = 0;
			
			/*Load the TaskA PSP value into the PSP register*/
			OS_SET_PSP(_s_TA_PSP);

			/*Switch to using the process stack instead of the main stack*/
			OS_USE_PSP;

			/*Switch to unprivileged access level*/
			OS_UNPRIVILEGED_ACCESS;

			/*Call Task A*/
			TaskA();

			/*Generate an interrupt to return to privileged mode*/
			__asm("SVC #0x00");

			/*Switch back to the main stack instead of the process stack */
			OS_USE_MSP;

		}else if(Glob_u8TaskBFlag == 1)
		{
			/*Reset the flag to prevent us from executing TaskB more than once*/
			Glob_u8TaskBFlag = 0;
			
			/*Load the TaskB PSP value into the PSP register*/
			OS_SET_PSP(_s_TB_PSP);

			/*Switch to using the process stack instead of the main stack*/
			OS_USE_PSP;

			/*Switch to unprivileged access level*/
			OS_UNPRIVILEGED_ACCESS;

			/*Call Task B*/
			TaskB();

			/*Generate an interrupt to return to privileged mode*/
			__asm("SVC #0x00");

			/*Switch back to the main stack instead of the process stack */
			OS_USE_MSP;

		}
	}
}

void TaskA(void)
{
	MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN0);
}

void TaskB(void)
{
	MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN1);
}

/**
 * @brief Handler for the SuperVisor call IRQ to go back to privileged access 
 * 
 */
void SVC_Handler(void)
{
	OS_PRIVILEGED_ACCESS;
}