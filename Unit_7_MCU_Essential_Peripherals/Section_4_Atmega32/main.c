/*
 * Atmega32_Drivers.c
 *
 * Created: 9/11/2023 4:23:15 PM
 * Author : hp
 */ 
#include "Atmega32.h"
#include "GPIO/Atmega32_GPIO.h"
#include "Atmega32_Drivers/HAL/LCD_Driver/LCD_interface.h"


int main(void)
{
	LCD_Init();
	LCD_Send_String("Learn in depth!");
	
    while (1) 
    {
		
    }
}

