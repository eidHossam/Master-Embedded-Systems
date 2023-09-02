/*
 * LCD.c
 *
 * Created: 8/30/2023 4:01:04 PM
 *  Author: Hossam Eid
 */ 

#include "lcd.h"
#include "../Bit_Math.h"
/*Global variables*/
static uint8 charCounter = 0, lineCounter = 0;

/*Local functions*/
void LCD_Enable_Pulse()
{
    SET_BIT(LCD_CTRL_PORT, EN);
    _delay_ms(50);
    CLEAR_BIT(LCD_CTRL_PORT, EN);
}

void Check_End_Of_Line()
{
    //If the first line is full go to the next line
    if(charCounter >= 16 && lineCounter == 0)
    {
        LCD_Cursor_XY(1, 0);
        charCounter = 0;
        lineCounter++;
    }else if(charCounter >= 16 && lineCounter == 1)
    {
        LCD_Clear_Screen();
        LCD_Send_Command(LCD_BEGIN_AT_FIRST_ROW);
        charCounter = 0;
        lineCounter = 0;
    }
}

/*Initializes the LCD in the required mode (4, 8) bit */
void LCD_Init(void)
{
    //Wait for the VCC to rise to the required value
    _delay_ms(20);
    LCD_CTRL_DIR_PORT |= ((1 << RS) | (1 << RW) | (1 << EN));   //Set all CTRL bits as output
    
    /*Select ins register, Write operation and Enable zero*/
    LCD_CTRL_PORT &= ~((1 << RS) | (1 << RW) | (1 << EN));
    _delay_ms(15);

    LCD_Clear_Screen();
#if LCD_MODE_ == EIGHT_BIT_MODE
    //In case of 8 bits mode all the data pins are Output
    LCD_DAtA_DIR_PORT = 0xFF;

    LCD_Send_Command(LCD_FUNC_8BIT_2LINES);    
#elif LCD_MODE_ == FOUR_BIT_MODE
    //In case of 4 bits mode the upper 4 pins of the port are output
    SET_BITS(LCD_DAtA_DIR_PORT, 4, 0xF); 
    _delay_ms(5);
    
    LCD_Send_Command(RETURN_HOME);
    LCD_Send_Command(LCD_FUNC_4BIT_2LINES);    
#endif

    LCD_Send_Command(ENTRY_MODE);    
    LCD_Send_Command(LCD_BEGIN_AT_FIRST_ROW);
    LCD_Send_Command(DISPLAY_ON_CURSOR_BLINK);    
}

void LCD_Send_Command(uint8 command)
{
    //Check if the LCD is busy
    //LCD_Busy_Wait();

    /*Select ins register, Write operation and Enable zero*/
    LCD_CTRL_PORT &= ~((1 << RS) | (1 << RW) | (1 << EN));

#if LCD_MODE_ == EIGHT_BIT_MODE
    LCD_DATA_PORT = command;

    LCD_Enable_Pulse();
#elif LCD_MODE_ == FOUR_BIT_MODE
    LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (command & 0xF0);
    LCD_Enable_Pulse();
    
    LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (command << 4);
    LCD_Enable_Pulse();
#endif
}

void LCD_Send_Char(uint8 data)
{
    //Check if the LCD is busy
    // LCD_Busy_Wait();
    Check_End_Of_Line();

    /*Write operation and Enable zero*/
    LCD_CTRL_PORT &= ~(1 << RW);
    /*Data register*/
    SET_BIT(LCD_CTRL_PORT, RS);


#if LCD_MODE_ == EIGHT_BIT_MODE
    LCD_DATA_PORT = data;

    LCD_Enable_Pulse();
#elif LCD_MODE_ == FOUR_BIT_MODE
    LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (data & 0xF0);
    LCD_Enable_Pulse();
    
    LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (data  << 4);
    LCD_Enable_Pulse();
#endif
    charCounter++;  
}

void LCD_Busy_Wait()
{
#if LCD_MODE_ == EIGHT_BIT_MODE
    //In case of 8 bits mode all the data pins are input
    LCD_DAtA_DIR_PORT = 0;  
#elif LCD_MODE_ == FOUR_BIT_MODE
    //In case of 4 bits mode the upper 4 pins of the port are input
    CLEAR_BITS(LCD_DAtA_DIR_PORT, 4, 0xF); 
#endif
    CLEAR_BIT(LCD_CTRL_PORT, RS);       //RS = 0      INS register
    SET_BIT(LCD_CTRL_PORT, RW);         //RW = 1      Read from LCD

    LCD_Enable_Pulse();    
    
#if LCD_MODE_ == EIGHT_BIT_MODE
    //In case of 8 bits mode all the data pins are output
    LCD_DAtA_DIR_PORT = 0xFF;  
#elif LCD_MODE_ == FOUR_BIT_MODE
    //In case of 4 bits mode the upper 4 pins of the port are output
    SET_BITS(LCD_DAtA_DIR_PORT, 4, 0xF); 
#endif
}

void LCD_Clear_Screen()
{
    LCD_Send_Command(LCD_CLEAR_SCREEN);
    charCounter = 0;
}

void LCD_Send_String(char* string)
{
    while(*string)
    {
        LCD_Send_Char(*string++);
    }
}

void LCD_Cursor_XY(uint8 line, uint8 col)
{
    if((col >= 16 ) || (col < 0))
        return;

    if(line == 0)
    {
        LCD_Send_Command(LCD_BEGIN_AT_FIRST_ROW + col);
    }
    else if(line == 1)
    {
        LCD_Send_Command(LCD_BEGIN_AT_SECOND_ROW + col);
    }
}
