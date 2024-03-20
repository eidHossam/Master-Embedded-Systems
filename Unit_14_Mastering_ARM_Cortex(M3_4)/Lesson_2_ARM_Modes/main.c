/**
******************************************************************************
* @file           : main.c
* @author         : Hossam Eid
* @brief          : Main program body
******************************************************************************
* @attention
*
* <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
* All rights reserved.</center></h2>
*
* This software component is licensed by ST under BSD 3-Clause license,
* the "License"; You may not use this file except in compliance with the
* License. You may obtain a copy of the License at:
*                        opensource.org/licenses/BSD-3-Clause
*
******************************************************************************
*/

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

/*
*===============================================
*                   Includes
*===============================================
*/

#include "stm32f103x6.h"
#include "GPIO/stm32f103x6_GPIO.h"
#include "LCD_Driver/LCD_interface.h"
#include "Keypad_Driver/Keypad_interface.h"
#include "AFIO/stm32f103x6_AFIO.h"
#include "NVIC/stm32f103x6_NVIC.h"
#include "EXTI/stm32f103x6_EXTI.h"

/*
===============================================
*  				GLOBAL VARIABLES
*===============================================
*/
uint8 IRQ_Flag = 0;
/*
===============================================
*  				Functions declarations
*===============================================
*/
void clock_init();
void delay(uint8 delay_Counter);

void EXTI9_ISR(void)
{
	IRQ_Flag = 1;
	LCD_Send_String("IRQ9 has happened _|- ");
	delay(1000);
}

int main(void)
{
	clock_init();
	LCD_Init();

	EXTI_config_t config;
	config.PinConfig = EXTI_GPIOB_PIN9;
	config.EXTI_Trigger_Mode = EXTI_TRIGGER_RISING_EDGE;
	config.EXTI_Priority = 0;
	config.P_callback_func = EXTI9_ISR;
	config.EXTI_En = EXTI_ENABLE;
	MCAL_EXTI_Enable(&config);

	while(1)
	{
		if(IRQ_Flag)
		{
			LCD_Clear_Screen();
			IRQ_Flag = 0;
		}
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


void delay(uint8 delay_Counter)
{
	volatile uint8 i, j;
	for(i = 0; i < delay_Counter; i++)
	{
		for ( j = 0; j < 255; j++)
		{
		}
	}
}
