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
#include "RCC/stm32f103x6_RCC.h"
#include "USART/stm32f103x6_USART.h"
#include "SPI/stm32f103x8_SPI.h"
#include "I2C/stm32f103x6_I2C.h"
#include "E2PROM/E2PROM_Controller_interface.h"

/*
===============================================
*  				GLOBAL VARIABLES
*===============================================
*/

/*
===============================================
*  				Functions declarations
*===============================================
*/

void clock_init();
void delay(uint8 delay_Counter);

int main(void)
{
	uint8 buffer[7] = {1, 2, 3, 4, 5, 6, 7};
	uint8 rec[7];
	clock_init();
	E2PROM_Init();
	
	E2PROM_write_Nbytes(0x1A, buffer, 7);
	E2PROM_read_nbytes(0x1A, rec, 7);


	buffer[0] = 0xA;
	buffer[1] = 0xB;
	buffer[2] = 0xC;
	buffer[3] = 0xD;

	E2PROM_write_Nbytes(0xFF0A, buffer, 4);
	E2PROM_read_nbytes(0xFF0A, rec, 4);

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
	/*Enable GPIO_B*/
	APB2_PERI_CLOCK_EN(APB2_IOPB);

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
