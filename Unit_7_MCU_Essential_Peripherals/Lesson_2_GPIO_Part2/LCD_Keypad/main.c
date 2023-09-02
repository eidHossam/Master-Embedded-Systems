/*
 * LCD_Keypad.c
 *
 * Created: 8/30/2023 3:53:20 PM
 * Author : Hossam Eid
 */ 

#include "LCD_Driver/LCD.h"
#include "Keypad_Driver/Keypad.h"

int main(void)
{
    uint8 pressedKey;
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

