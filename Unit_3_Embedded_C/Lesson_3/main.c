/**
 * @defgroup   MAIN main
 *
 * @brief      This file implements a simple
 *              lab that toggles an LED on
 *              ARM cortexM3 STM32.
 *
 * @author     Hossam Eid
 * @date       2023
 */

#include <stdint.h>

#define RCC_BASE      0x40021000
#define GPIOA_BASE    0x40010800
#define APB2ENR       *(volatile unsigned int *)(RCC_BASE + 0x18)
#define CRH_R         *(volatile unsigned int *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR     *(volatile unsigned int *)(GPIOA_BASE + 0x0C)
#define IOPAEN        (1 << 2)

typedef union
{
   uint32_t all_pins;
   struct
   {
      uint32_t      : 13;
      uint32_t P_13 : 1;
   }        Pins;
} R_ODR_t;

volatile R_ODR_t *R_ODR = (volatile R_ODR_t *)(GPIOA_BASE + 0x0C);
volatile const char name[] = "Hossam Eid";
volatile int x[100];

void NMI_Handler(void)
{
    
}

int main()
{
   APB2ENR |= IOPAEN;
   CRH_R   |= (CRH_R & 0xFF0FFFFF) + 0x00200000;

   while (1)
   {
      R_ODR->Pins.P_13 = 1;
      for (int i = 0; i < 50000; ++i);
      R_ODR->Pins.P_13 = 0;
      for (int i = 0; i < 50000; ++i);
   }

   return 0;
}
