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
#define FLASH_MEMORY_BASE                             0x08000000UL
#define SYSTEM_MEMORY_BASE                            0x08000000UL
#define SRAM_MEMORY_BASE                              0x20000000UL
#define PERIPHERAL_MEMORY_BASE                        0x20000000UL
#define CORTEX_M3_INTERNAL_PERIPHERALS_MEMORY_BASE    0x20000000UL

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
#define AFIO_BASE 0x40011800ul

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
	vuint32_t EVCR;          /*Event control register*/
	vuint32_t MAPR;          /*AF remap and debug I/O configuration register 1*/
	vuint32_t EXTICR1;       /*External interrupt configuration register 1*/
	vuint32_t EXTICR2;       /*External interrupt configuration register 2*/
	vuint32_t EXTICR3;       /*External interrupt configuration register 3*/
	vuint32_t EXTICR4;       /*External interrupt configuration register 4*/
	vuint32_t :    32;       /*Reserved space*/
	vuint32_t MAPR2;         /*AF remap and debug I/O configuration register 2*/
}AFIO_t;



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

/*----------AFIO-----------------*/
#define AFIO        ((volatile AFIO_t *)(AFIO_BASE))


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
