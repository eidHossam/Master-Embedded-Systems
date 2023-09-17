/*
 * Atmega32_Drivers.c
 *
 * Created: 9/11/2023 4:23:15 PM
 * Author : hp
 */ 
#include "Atmega32.h"
#include "GPIO/Atmega32_GPIO.h"
#include "UART/Atmega32_UART.h"
#include "Atmega32_Drivers/HAL/LCD_Driver/LCD_interface.h"
int main(void)
{
    uint8_t input, buffer[128];
	
    MCAL_USART_Init();
	LCD_Init();
    
	/*Take a string from the USART then echo it*/
	MCAL_USART_Get_String(buffer, 128);
    MCAL_USART_Send_String(buffer);
    
	while (1) 
    {
		/*Print what you send through the UART on the LCD*/
        input = MCAL_USART_Get_Char();
        MCAL_USART_Send_Char(input);
		LCD_Send_Char(input);
    }
}

