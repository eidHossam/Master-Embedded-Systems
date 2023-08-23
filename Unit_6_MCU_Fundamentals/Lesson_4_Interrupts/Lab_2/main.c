/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : his file implements a simple
 *                 : lab that toggles an LED on
 *                 : ARM cortexM3 STM32.
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

#include <stdint.h>

/*Clock Register*/
#define RCC_BASE      	0x40021000
#define APB2ENR       	*(volatile unsigned int *)(RCC_BASE + 0x18)

/*NVIC registers*/
#define NVIC_BASE 		0xE0000000
#define NVIC_ISER0		*(volatile unsigned int *)(NVIC_BASE + 0xE100)

/*EXTI Registers*/
#define EXTI_BASE		0x40010400
#define EXTI_RTSR 	  	*(volatile unsigned int *)(EXTI_BASE + 0x08)
#define EXTI_IMR 	  	*(volatile unsigned int *)(EXTI_BASE + 0x00)
#define EXTI_PR 	  	*(volatile unsigned int *)(EXTI_BASE + 0x14)

/*GPIOA Register*/
#define GPIOA_BASE    	0x40010800
#define CRH_R         	*(volatile unsigned int *)(GPIOA_BASE + 0x04)
#define GPIOA_CRL        *(volatile unsigned int *)(GPIOA_BASE + 0x00)
#define GPIOA_ODR		*(volatile unsigned int *)(GPIOA_BASE + 0x0C)
#define IOPAEN			(1 << 2)
#define PA13		 	(1<<13)

/*AFIO Registers*/
#define AFIO_BASE		0x40010000	
#define AFIO_EXTICR1	*(volatile unsigned int *)(AFIO_BASE + 0x0C)


/*Functions declarations*/
void clock_init();
void GPIO_init();
void interrupt_init();

int main()
{
	clock_init();
	GPIO_init();
	interrupt_init();
	
	while (1)
	{
	}

	return 0;
}

void clock_init()
{
   	/*Enable GPIO_A*/
	APB2ENR |= IOPAEN;
	/*Enable AFIO*/
	APB2ENR |= (1 << 0);
}

void GPIO_init()
{
   /*PA_13 as output*/
   CRH_R   |= (CRH_R & 0xFF0FFFFF) + 0x00200000;

   /*PA_0 as input*/
   GPIOA_CRL = ((GPIOA_CRL & 0xFFFFFFF0) + 0b0100);
}

void interrupt_init()
{
	EXTI_RTSR 	|= (1 << 0);	/*Setting the interrupt to be rising edge triggered*/
	AFIO_EXTICR1 = 0;			/*Choose PA0 to be the external interrupt*/ 
	EXTI_IMR 	|= (1 << 0);	/*Enable the mask on the EXTI0 line*/

	NVIC_ISER0 	|= (1 << 6);	/*Enable the irq6 in NVIC*/
}

void EXTI0_IRQHandler(void)
{
	/*Toggle the LED*/
    GPIOA_ODR ^= PA13;

	/*Acknowledge the intterupt by writting 1 to the register*/
	EXTI_PR |= (1 << 0);	
}	