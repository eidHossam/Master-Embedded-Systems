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
/*
===============================================
*  				GLOBAL VARIABLES
*===============================================
*/
uint8 counter = 0;
uint16 buffer;
char* name = "Eng.Hossam Eid";

/*
===============================================
*  				Functions declarations
*===============================================
*/
void clock_init();
void delay(uint8 delay_Counter);
void USART_Init();
void SPI_Init();

void USART1_RXNE_ISR(void)
{
	MCAL_UART_Get_Data(USART1, &buffer, UART_POLLING_DISABLE);
	MCAL_UART_Send_Data(USART1, &buffer, UART_POLLING_DISABLE);

	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN4, GPIO_PIN_LOW);
	MCAL_SPI_SendData(SPI1, &buffer, PollingEnable);
	MCAL_SPI_WAIT_TC(SPI1);
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN4, GPIO_PIN_HIGH);
}


int main(void)
{
	clock_init();
	USART_Init();
	SPI_Init();


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

void USART_Init()
{
	UART_config_t config;
	config.UART_Mode 	= UART_MODE_TX_RX;
	config.baudRate 	= UART_BAUD_RATE_115200;
	config.wordLength 	= UART_DATA_8bits;
	config.parityCTRL 	= UART_PARITY_NONE;
	config.stopBits 	= UART_STOP_BITS_1;
	config.HW_FlowCTRL 	= UART_FLOW_CTRL_NONE;
	MCAL_UART_Init(USART1, &config);

	MCAL_UART_Interrupt_EN(USART1, USART_IRQ_RXNE , USART1_RXNE_ISR);	
}

void SPI_Init()
{
	SPI_Config_t config;
	config.SPI_Mode = SPI_MODE_MASTER;
	config.SPI_Direction = SPI_DIRECTION_2LINES_FULL_DUPLEX;
	config.SPI_BitOrder = SPI_FIRST_BIT_LSB;
	config.SPI_DataSize = SPI_DATA_SIZE_8BIT;
	config.SPI_BR_Prescaler = SPI_BAUD_RATE_PRESCALER_8;
	config.SPI_ClockPhase = SPI_SAMPLE_SECOND_EDGE;
	config.SPI_ClockPolarity = SPI_IDLE_HIGH;
	config.SPI_NSS_Managment = SPI_NSS_SW_SET;

	MCAL_SPI_Init(SPI1, &config);

	GPIO_Pin_Config_t pin_config;
	pin_config.pinNumber = GPIO_PIN4;
	pin_config.pinMode = GPIO_MODE_GP_OUTPUT_PP_10MHZ;
	MCAL_GPIO_Init(GPIOA, &pin_config);

	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN4, GPIO_PIN_HIGH);
}

