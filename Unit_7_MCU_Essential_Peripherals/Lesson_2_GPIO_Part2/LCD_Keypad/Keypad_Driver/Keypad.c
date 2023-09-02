/*
 * Keypad.c
 *
 * Created: 8/31/2023 2:34:50 PM
 *  Author: Hossam Eid
 */ 

#include "Keypad.h"

/*Global Variables*/
static uint8 keypad_chars[] = {
    '7', '8', '9', '/',
    '4', '5', '6', '*',
    '1', '2', '3', '-',
    'C', '0', '=', '+'};

void Keypad_Init(void)
{
    /*D0 to D3 as input (Rows)*/
    KEYPAD_DATA_DIR_PORT &= ~((1 << PIN0) | (1 << PIN1) | (1 << PIN2) | (1 << PIN3));
    /*D4 to D7 as input (Cols)*/
    KEYPAD_DATA_DIR_PORT |= ((1 << PIN4) | (1 << PIN5) | (1 << PIN6) | (1 << PIN7));
    
    //High on D4 to D7 and Pull-up resistance on D0  to D3
    KEYPAD_DATA_PORT = 0xFF;
}

char Keypad_Get_Char(void)
{
    uint8 col, row;
    for(col = 0; col < 4; col++)
    {
        /*High on D4 to D7 */
        KEYPAD_DATA_PORT |= ((1 << PIN4) | (1 << PIN5) | (1 << PIN6) | (1 << PIN7));
        CLEAR_BIT(KEYPAD_DATA_PORT, (4 + col));

        for(row = 0; row < 4; row++)
        {
            /*Loop on all the buttons in this coloumn to 
            see if any of them dropped to ground*/
            if(READ_BIT(KEYPAD_INPUT_DATA_PORT, row) == 0)
            {
                while(READ_BIT(KEYPAD_INPUT_DATA_PORT, row) == 0);
                return keypad_chars[(row * 4) + col];
            }
        }
    }
    return 'N';
}