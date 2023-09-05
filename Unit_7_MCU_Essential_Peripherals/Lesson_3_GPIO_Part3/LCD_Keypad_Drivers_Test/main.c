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

/*
===============================================
*  				GLOBAL VARIABLES
*===============================================
*/
uint8 sevenSegNumCodes[] = {0x3F, 0x06, 0x5B, 0x4F, 0X66, 0x6D, 0x7C, 0x07, 0x7F, 0x67};

/*
===============================================
*  				Functions declarations
*===============================================
*/
void clock_init();
void delay(uint8 delay_Counter);
void SevenSeg_init();
void display_count();

int main(void)
{
	uint8 pressedKey;
	
	clock_init();
	LCD_Init();
	SevenSeg_init();
	Keypad_Init();
	
	display_count();
	while (1) 
	{
		 pressedKey = Keypad_Get_Char();
		 if(pressedKey != 'N')
		 {
		 	if(pressedKey == 'C')
		 	{
		 		LCD_Clear_Screen();
		 	}else{
		 		if(pressedKey >= '0' && pressedKey <= '9')
		 		{
		 			MCAL_GPIO_WriteByte(GPIOB,sevenSegNumCodes[(pressedKey - '0')], GPIO_PIN9);					
		 		}
		 		LCD_Send_Char(pressedKey);
		 	}
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
}

void SevenSeg_init()
{
	GPIO_Pin_Config_t config;

	config.pinNumber = GPIO_PIN9;
	config.pinMode = GPIO_MODE_GP_OUTPUT_PP_10MHZ;
	MCAL_GPIO_Init(GPIOB, &config);	
	
	config.pinNumber = GPIO_PIN10;
	config.pinMode = GPIO_MODE_GP_OUTPUT_PP_10MHZ;
	MCAL_GPIO_Init(GPIOB, &config);	
	
	config.pinNumber = GPIO_PIN11;
	config.pinMode = GPIO_MODE_GP_OUTPUT_PP_10MHZ;
	MCAL_GPIO_Init(GPIOB, &config);	
	
	config.pinNumber = GPIO_PIN12;
	config.pinMode = GPIO_MODE_GP_OUTPUT_PP_10MHZ;
	MCAL_GPIO_Init(GPIOB, &config);	
	
	config.pinNumber = GPIO_PIN13;
	config.pinMode = GPIO_MODE_GP_OUTPUT_PP_10MHZ;
	MCAL_GPIO_Init(GPIOB, &config);	
	
	config.pinNumber = GPIO_PIN14;
	config.pinMode = GPIO_MODE_GP_OUTPUT_PP_10MHZ;
	MCAL_GPIO_Init(GPIOB, &config);	
	
	config.pinNumber = GPIO_PIN15;
	config.pinMode = GPIO_MODE_GP_OUTPUT_PP_10MHZ;
	MCAL_GPIO_Init(GPIOB, &config);	
}

void display_count()
{
	uint8 i;
	for(i = 0 ; i < 10; i++)
	{
		LCD_Send_Char((i +'0'));
		MCAL_GPIO_WriteByte(GPIOB,sevenSegNumCodes[i], GPIO_PIN9);					
		delay(100);
	}

	LCD_Clear_Screen();
	LCD_Send_String("Keypad Is Ready");
	delay(100);
	LCD_Clear_Screen();
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
