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

#include "stm32f103x6.h"
#include "GPIO/stm32f103x6_GPIO.h"
#include "LCD_Driver/LCD_interface.h"
#include "Keypad_Driver/Keypad_interface.h"

/*Functions declarations*/
void clock_init();
void GPIO_init();

int main(void)
{
    uint8 pressedKey;
	clock_init();
    LCD_Init();
    LCD_Clear_Screen();
    Keypad_Init();
    
	while (1) 
    {
        pressedKey = Keypad_Get_Char();
        if(pressedKey != 'N')
        {
            if(pressedKey == 'C')
            {
                LCD_Clear_Screen();
            }else{
                LCD_Send_Char(pressedKey);
            }
        }
    }
}



void clock_init()
{
	/*Enable GPIO_A*/
	APB2_PERI_CLOCK_EN(APB2_IOPA);

	/*Enable GPIO_B*/
	APB2_PERI_CLOCK_EN(APB2_IOPB);
}


void GPIO_init()
{
	GPIO_Pin_Config_t config;

	/*PA_13 as floating input*/
	config.pinNumber = GPIO_PIN13;
	config.pinMode = GPIO_MODE_INPUT_FLOATING;
	MCAL_GPIO_Init(GPIOA, &config);

	/*PA_1 as floating input*/
	config.pinNumber = GPIO_PIN1;
	config.pinMode = GPIO_MODE_INPUT_FLOATING;
	MCAL_GPIO_Init(GPIOA, &config);

	/*PB1 as output push-pull 10MHZ*/
	config.pinNumber = GPIO_PIN1;
	config.pinMode = GPIO_MODE_GP_OUTPUT_PP_10MHZ;
	MCAL_GPIO_Init(GPIOB, &config);

	/*PB13 as output push-pull 10MHZ*/
	config.pinNumber = GPIO_PIN13;
	config.pinMode = GPIO_MODE_GP_OUTPUT_PP_10MHZ;
	MCAL_GPIO_Init(GPIOB, &config);
}
