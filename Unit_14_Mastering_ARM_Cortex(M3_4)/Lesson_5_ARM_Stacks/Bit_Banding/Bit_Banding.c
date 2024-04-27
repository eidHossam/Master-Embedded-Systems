/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Hossam Eid
 * @brief          : Main program body
 ******************************************************************************
 */

/*
 *===============================================
 *                   Includes
 *===============================================
 */

#include "GPIO/stm32f103x6_GPIO.h"
#include "EXTI/stm32f103x6_EXTI.h"

/*
===============================================
 *  				Global variables and MACROS
 *===============================================
 */

#define BIT_BAND_ALIAS_BASE         0x42000000u

uint32 *GPIO_Bit0Address;

/*
===============================================
 *  				Functions declarations
 *===============================================
 */
void clock_init();

void GPIO_Init(void);

void EXTI_Init(void);

void EXTI9_ISR(void)
{
	*GPIO_Bit0Address ^= 0x1u;
}

int main(void)
{
	clock_init();
	GPIO_Init();
	EXTI_Init();

	uint32 address = (uint32)&GPIOA->ODR;
	uint32 offset = (((address - 0x40000000) * 0x20) + (GPIO_PIN0 * 0x4u));
	GPIO_Bit0Address = (uint32 *)(BIT_BAND_ALIAS_BASE + offset);

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

void GPIO_Init(void)
{
	GPIO_Pin_Config_t init;
	init.pinNumber = GPIO_PIN0;
	init.pinMode = GPIO_MODE_GP_OUTPUT_PP_2MHZ;
	MCAL_GPIO_Init(GPIOA, &init);
}

void EXTI_Init(void)
{
	EXTI_config_t config;
	config.PinConfig = EXTI_GPIOB_PIN9;
	config.EXTI_Trigger_Mode = EXTI_TRIGGER_RISING_EDGE;
	config.EXTI_Priority = 0;
	config.P_callback_func = EXTI9_ISR;
	config.EXTI_En = EXTI_ENABLE;
	MCAL_EXTI_Enable(&config);
}
