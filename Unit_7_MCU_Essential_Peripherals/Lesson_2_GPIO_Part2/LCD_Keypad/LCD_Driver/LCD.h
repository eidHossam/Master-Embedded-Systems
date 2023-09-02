/*
 * LCD.h
 *
 * Created: 8/30/2023 4:00:56 PM
 *  Author: Hossam Eid
 */ 


#ifndef LCD_H_
#define LCD_H_
#define F_CPU 8000000ul

#include "../io.h"
#include "../Platform_Types.h"
#include <util/delay.h>

/*------------------LCD MODE SELECTION--------------*/
#define EIGHT_BIT_MODE  8
#define FOUR_BIT_MODE   4
#define LCD_MODE_       FOUR_BIT_MODE

/*------------------LCD ports--------------------*/
#define LCD_DATA_PORT       PORTA
#define LCD_DAtA_DIR_PORT   DDRA
#define LCD_CTRL_PORT       PORTB
#define LCD_CTRL_DIR_PORT   DDRB

/*------------------LCD signals------------------*/
#define RS PIN1         /*Select register PIN (INS, Data)*/
#define RW PIN2         /*Read or write*/
#define EN PIN3    

#define LCD_INS_REG     0
#define LCD_DATA_REG    1
#define LCD_WRITE       0
#define LCD_READ        1

/*define useful symbolic names for LCD commands */
#define LCD_CLEAR_SCREEN        0x01
#define RETURN_HOME             0x02
#define moveCursorRight         0x06
#define moveCursorLeft          0x08
#define shiftDisplayRight       0x1C
#define shiftDisplayLeft        0x18
#define DISPLAY_ON_CURSOR_BLINK 0x0F
#define cursorOff               0x0C
#define cursorOn                0x0E
#define LCD_FUNC_4BIT_2LINES    0x28
#define LCD_FUNC_8BIT_2LINES    0x38
#define ENTRY_MODE              0x06
#define Function_8_bit          0x32
#define Set5x7FontSize          0x20
#define LCD_BEGIN_AT_FIRST_ROW  0x80
#define LCD_BEGIN_AT_SECOND_ROW 0xC0

/*LCD state*/
#define LCD_NOT_BUSY  0
#define LCD_BUSY   1

/*---------------API-------------------*/
void LCD_Init(void);
void LCD_Send_Command(uint8 command);
void LCD_Send_Char(uint8 data);
void LCD_Send_String(char* string);
void LCD_Cursor_XY(uint8 line, uint8 col);
void LCD_Busy_Wait();
void LCD_Clear_Screen();

#endif /* LCD_H_ */