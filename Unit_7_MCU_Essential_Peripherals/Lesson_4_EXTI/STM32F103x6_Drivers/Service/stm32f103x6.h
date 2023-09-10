/*
**************************************************************************************************************************
* brief     : MCU Device Header for the stm32f103x6.
* Author    : Hossam Eid
* Created on: 26 Feb 2022
**************************************************************************************************************************
* Description: This file contains the memory map for the MCU
* with each peripheral base address and registers and instances of each peripheral
* note: This header file is intended for use with the STM32F103xx MCU series,
* but may be adapted for use with other compatible processors.
**************************************************************************************************************************
*/

#ifndef STM32F103X6_H_
#define STM32F103X6_H_

//-----------------------------
//Includes
//-----------------------------
#include "Bit_Math.h"
#include "Platform_Types.h"

/*================================================================*/
//-----------------------------
//Base addresses for Memories
//-----------------------------
#define FLASH_MEMORY_BASE                             	0x08000000UL
#define SYSTEM_MEMORY_BASE                            	0x08000000UL
#define SRAM_MEMORY_BASE                              	0x20000000UL
#define PERIPHERAL_MEMORY_BASE                        	0x20000000UL
/*
*===============================================
*  	Cortex-M3 base addresses
*===============================================
*/
#define CORTEX_M3_INTERNAL_PERIPHERALS_MEMORY_BASE    	0xE0000000UL
#define NVIC_BASE										(CORTEX_M3_INTERNAL_PERIPHERALS_MEMORY_BASE + 0xE100)
/*================================================================*/
//--------------------------------------
//Base addresses for AHB BUS Peripherals
//--------------------------------------
#define RCC_BASE 0x40021000ul

//--------------------------------------
//Base addresses for APB1 BUS Peripherals
//--------------------------------------

//--------------------------------------
//Base addresses for APB2 BUS Peripherals
//--------------------------------------

/*----------GPIO-------------------
Note: LQFP48 package has PORT(A, B)
,part of PORT(C,D) and PORTE isn't
used*/
#define GPIOA_BASE 0x40010800ul
#define GPIOB_BASE 0x40010C00ul
#define GPIOC_BASE 0x40011000ul
#define GPIOD_BASE 0x40011400ul
#define GPIOE_BASE 0x40011800ul

/*----------AFIO-----------------*/
#define AFIO_BASE 0x40010000ul

/*----------EXTI-----------------*/
#define EXTI_BASE 0x40010400ul

/*================================================================*/
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*-

/*----------RCC registers-----------------*/
typedef struct{
	vuint32_t CR;           /*Clock control register*/
	vuint32_t CFGR;         /*Clock configuration register*/
	vuint32_t CIR;          /*Clock interrupt register*/
	vuint32_t APB2RSTR;     /*APB2 peripheral reset register*/
	vuint32_t APB1RSTR;     /*APB1 peripheral reset register*/
	vuint32_t AHBENR;       /*AHB Peripheral Clock enable register*/
	vuint32_t APB2ENR;      /*APB2 Peripheral Clock enable register*/
	vuint32_t APB1ENR;      /*APB1 Peripheral Clock enable register*/
	vuint32_t BDCR;         /*Backup domain control register*/
	vuint32_t CSR;          /*Control/status register*/
	vuint32_t AHBSTR;       /*AHB peripheral clock reset register*/
	vuint32_t CFGR2;        /*Clock configuration register2*/
}RCC_t;

/*----------NVIC registers-----------------*/
#define NVIC_ISER_BASE       ((volatile uint32 *)(NVIC_BASE + 0x000))	/*Interrupt set-enable registers base*/
#define NVIC_ISER0          *((volatile uint32 *)(NVIC_BASE + 0x000))	/*Interrupt[0 : 31] set-enable register*/
#define NVIC_ISER1          *((volatile uint32 *)(NVIC_BASE + 0x004))	/*Interrupt[32 : 63] set-enable register*/
#define NVIC_ISER2          *((volatile uint32 *)(NVIC_BASE + 0x008))	/*Interrupt[64 : 80] set-enable register*/


#define NVIC_ICER_BASE       ((volatile uint32 *)(NVIC_BASE + 0x080))	/*Interrupt clear-enable registers base*/
#define NVIC_ICER0          *((volatile uint32 *)(NVIC_BASE + 0x080))	/*Interrupt[0 : 31]  clear-enable register*/
#define NVIC_ICER1          *((volatile uint32 *)(NVIC_BASE + 0x084))	/*Interrupt[32 : 63] clear-enable register*/
#define NVIC_ICER2          *((volatile uint32 *)(NVIC_BASE + 0x088))	/*Interrupt[64 : 80] clear-enable register*/

#define NVIC_ISPR_BASE		 ((volatile uint32 *)(NVIC_BASE + 0x100))	/*Interrupt set-pending registers base*/
#define NVIC_ISPR0			*((volatile uint32 *)(NVIC_BASE + 0x100))	/*Interrupt[0 : 31]  set-pending register*/
#define NVIC_ISPR1			*((volatile uint32 *)(NVIC_BASE + 0x104))	/*Interrupt[32 : 63] set-pending register*/
#define NVIC_ISPR2			*((volatile uint32 *)(NVIC_BASE + 0x108))	/*Interrupt[64 : 80] set-pending register*/

#define NVIC_ICPR_BASE		 ((volatile uint32 *)(NVIC_BASE + 0x180))	/*Interrupt clear-pending registers base*/
#define NVIC_ICPR0			*((volatile uint32 *)(NVIC_BASE + 0x180))	/*Interrupt[0 : 31]  clear-pending register*/
#define NVIC_ICPR1			*((volatile uint32 *)(NVIC_BASE + 0x184))	/*Interrupt[32 : 63] clear-pending register*/
#define NVIC_ICPR2			*((volatile uint32 *)(NVIC_BASE + 0x188))	/*Interrupt[64 : 80] clear-pending register*/

#define NVIC_IABR_BASE		 ((volatile uint32 *)(NVIC_BASE + 0x200))	/*Interrupt active bit registers base*/
#define NVIC_IABR0			*((volatile uint32 *)(NVIC_BASE + 0x200))	/*Interrupt[0 : 31]  active bit register*/
#define NVIC_IABR1			*((volatile uint32 *)(NVIC_BASE + 0x204))	/*Interrupt[32 : 63] active bit register*/
#define NVIC_IABR2			*((volatile uint32 *)(NVIC_BASE + 0x208))	/*Interrupt[64 : 80] active bit register*/

#define NVIC_IPR_BASE		 ((volatile uint32 *)(NVIC_BASE + 0x300))	/*Interrupt set-priority registers base*/
#define NVIC_IPR0			*((volatile uint32 *)(NVIC_BASE + 0x300))	/*Interrupt[0  : 3 ] set-priority register*/
#define NVIC_IPR1			*((volatile uint32 *)(NVIC_BASE + 0x304))	/*Interrupt[4  : 7 ] set-priority register*/	
#define NVIC_IPR2			*((volatile uint32 *)(NVIC_BASE + 0x308))	/*Interrupt[8  : 11] set-priority register*/
#define NVIC_IPR3			*((volatile uint32 *)(NVIC_BASE + 0x30C))	/*Interrupt[12 : 15] set-priority register*/
#define NVIC_IPR4			*((volatile uint32 *)(NVIC_BASE + 0x310))	/*Interrupt[16 : 19] set-priority register*/
#define NVIC_IPR5			*((volatile uint32 *)(NVIC_BASE + 0x314))	/*Interrupt[20 : 23] set-priority register*/
#define NVIC_IPR6			*((volatile uint32 *)(NVIC_BASE + 0x318))	/*Interrupt[24 : 27] set-priority register*/
#define NVIC_IPR7			*((volatile uint32 *)(NVIC_BASE + 0x31C))	/*Interrupt[28 : 31] set-priority register*/
#define NVIC_IPR8			*((volatile uint32 *)(NVIC_BASE + 0x320))	/*Interrupt[32 : 35] set-priority register*/
#define NVIC_IPR9			*((volatile uint32 *)(NVIC_BASE + 0x324))	/*Interrupt[36 : 39] set-priority register*/
#define NVIC_IPR10			*((volatile uint32 *)(NVIC_BASE + 0x328))	/*Interrupt[40 : 43] set-priority register*/
#define NVIC_IPR11			*((volatile uint32 *)(NVIC_BASE + 0x32C))	/*Interrupt[44 : 47] set-priority register*/
#define NVIC_IPR12			*((volatile uint32 *)(NVIC_BASE + 0x330))	/*Interrupt[48 : 51] set-priority register*/
#define NVIC_IPR13			*((volatile uint32 *)(NVIC_BASE + 0x334))	/*Interrupt[52 : 55] set-priority register*/
#define NVIC_IPR14			*((volatile uint32 *)(NVIC_BASE + 0x338))	/*Interrupt[56 : 59] set-priority register*/
#define NVIC_IPR15			*((volatile uint32 *)(NVIC_BASE + 0x33C))	/*Interrupt[60 : 63] set-priority register*/
#define NVIC_IPR16			*((volatile uint32 *)(NVIC_BASE + 0x340))	/*Interrupt[64 : 67] set-priority register*/
#define NVIC_IPR17			*((volatile uint32 *)(NVIC_BASE + 0x344))	/*Interrupt[68 : 71] set-priority register*/
#define NVIC_IPR18			*((volatile uint32 *)(NVIC_BASE + 0x348))	/*Interrupt[72 : 75] set-priority register*/
#define NVIC_IPR19			*((volatile uint32 *)(NVIC_BASE + 0x34C))	/*Interrupt[76 : 79] set-priority register*/
#define NVIC_IPR20			*((volatile uint32 *)(NVIC_BASE + 0x350))	/*Interrupt[80] 	 set-priority register*/

#define NVIC_STIR			*((volatile uint32 *)(0xE000EF00 + 0xE00))	/*Software trigger interrupt register*/

/*----------GPIO registers-----------------*/
typedef struct{
	vuint32_t CRL;          /*Control register for bits (0 to 7)*/
	vuint32_t CRH;          /*Control register for bits (8 to 15)*/
	vuint32_t IDR;          /*Input data register*/
	vuint32_t ODR;          /*Output data register*/
	vuint32_t BSRR;         /*Bit set/reset register*/
	vuint32_t BRR;          /*Bit reset register*/
	vuint32_t LCKR;         /*Bit configuration lock register*/
}GPIO_t;


/*----------AFIO registers-----------------*/
typedef struct{
	vuint32_t EVCR;          	/*Event control register*/
	vuint32_t MAPR;          	/*AF remap and debug I/O configuration register 1*/
	vuint32_t EXTICR[4];       	/*External interrupt configuration registers*/
	vuint32_t :    32;       	/*Reserved space*/
	vuint32_t MAPR2;         	/*AF remap and debug I/O configuration register 2*/
}AFIO_t;

/*----------EXTI registers-----------------*/
typedef struct{
	vuint32_t IMR;				/*Interrupt mask register (Enable, Disable)*/
	vuint32_t EMR;				/*Event mask register (Enable, Disable)*/
	vuint32_t RTSR;				/*Rising trigger selection register*/
	vuint32_t FTSR;				/*Falling trigger selection register*/
	vuint32_t SWIER;			/*Software interrupt event register*/
	vuint32_t PR;				/*Pending register*/
}EXTI_t;


/*================================================================*/
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*

/*----------RCC-----------------*/
#define RCC          ((volatile RCC_t *)(RCC_BASE))

/*----------GPIO-------------------
Note: LQFP48 package has PORT(A, B)
,part of PORT(C,D) and PORTE isn't
used*/
#define GPIOA        ((volatile GPIO_t *)(GPIOA_BASE))
#define GPIOB        ((volatile GPIO_t *)(GPIOB_BASE))
#define GPIOC        ((volatile GPIO_t *)(GPIOC_BASE))
#define GPIOD        ((volatile GPIO_t *)(GPIOD_BASE))
#define GPIOE        ((volatile GPIO_t *)(GPIOE_BASE))

/*----------------------AFIO---------------------------*/
#define AFIO        ((volatile AFIO_t *)(AFIO_BASE))

/*---------------------EXTI---------------------------*/
#define EXTI 		((volatile EXTI_t *)(EXTI_BASE))

/*================================================================*/
//Delete this part after making RCC driver
//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable/reset Macros:
//-*-*-*-*-*-*-*-*-*-*-*

/*----------GPIO-----------------*/
#define APB2_PERI_CLOCK_EN(periID) (SET_BIT(RCC->APB2ENR, periID))  /*PeriID must be a value of @ref APB2_ID*/

#define APB2_PERI_RESET(periID) (SET_BIT(RCC->APB2RSTR, periID)); \
                                (CLEAR_BIT(RCC->APB2RSTR, periID)) /*PeriID must be a value of @ref APB2_ID*/


/*================================================================*/
//---------------------------------
//Macros Configuration References
//---------------------------------
/*================================================================*/

/*@ref APB2_ID-------------*/
#define APB2_AFIO 0
#define APB2_IOPA 2
#define APB2_IOPB 3
#define APB2_IOPC 4
#define APB2_IOPD 5
#define APB2_IOPE 6

/*================================================================*/
//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*

/*================================================================*/
#endif /* STM32F103X6_H_ */
