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

#include <stdint.h>

/*Clock Register*/
#define RCC_BASE      0x40021000
#define APB2ENR       *(volatile unsigned int *)(RCC_BASE + 0x18)

/*GPIOA Registers*/
#define GPIOA_BASE    0x40010800
#define GPIOA_CRH     *(volatile unsigned int *)(GPIOA_BASE + 0x04)
#define GPIOA_CRL     *(volatile unsigned int *)(GPIOA_BASE + 0x00)
#define GPIOA_ODR     *(volatile unsigned int *)(GPIOA_BASE + 0x0C)
#define GPIOA_IDR     *(volatile unsigned int *)(GPIOA_BASE + 0x08)
#define IOPAEN        (1 << 2)
#define PA13          (1 << 13)

/*GPIOB Registers*/
#define GPIOB_BASE    0x40010C00
#define GPIOB_CRH     *(volatile unsigned int *)(GPIOB_BASE + 0x04)
#define GPIOB_CRL     *(volatile unsigned int *)(GPIOB_BASE + 0x00)
#define GPIOB_ODR     *(volatile unsigned int *)(GPIOB_BASE + 0x0C)
#define GPIOB_IDR     *(volatile unsigned int *)(GPIOB_BASE + 0x08)
#define IOPBEN        (1 << 3)


/*Functions declarations*/
void clock_init();
void GPIO_init();

int main()
{
   volatile int i;
   clock_init();
   GPIO_init();

   while (1)
   {
      /*If the button at PA1 is pressed*/
      if(((GPIOA_IDR & (1 << 1)) >> 1) == 0)
      {
         GPIOB_ODR ^= (1 << 1); /*Toggle the LED*/

         /*A loop for the button to be a signle press*/
         while(((GPIOA_IDR & (1 << 1)) >> 1) == 0);
      }

      /*If the button at PA13 is pressed*/
      if(((GPIOA_IDR & (1 << 13)) >> 13) == 1)
      {
         GPIOB_ODR ^= (1 << 13); /*Toggle the LED*/
      }

      /*Simple delay*/
      for(i = 0;  i < 500; i++);
   }

   return 0;
}


void clock_init()
{
   /*Enable GPIO_A*/
   APB2ENR |= IOPAEN;

   /*Enable GPIO_B*/
   APB2ENR |= IOPBEN;
}


void GPIO_init()
{
   /*PA_13 as floating input*/
   GPIOA_CRH &= ~(0b11 << 20);
   GPIOA_CRH |= (0b01 << 22);

   /*PA_1 as floating input*/
   GPIOA_CRL &= ~(0b11 << 4);
   GPIOA_CRL |= (0b01 << 6);

   /*PB1 as output*/
   GPIOB_CRL |= (0b01 << 4);
   GPIOB_CRL &= ~(0b11 << 6);

   /*PB13 as output*/
   GPIOB_CRH |= (0b01 << 20);
   GPIOB_CRH &= ~(0b11 << 22);   
}
