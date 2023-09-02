/*
 * Keypad.h
 *
 * Created: 8/31/2023 2:35:11 PM
 *  Author: Hossam Eid
 */ 

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "../io.h"
#include "../Bit_Math.h"
#include "../Platform_Types.h"

/*----------Keypad Ports-----------*/
#define KEYPAD_DATA_PORT        PORTD
#define KEYPAD_DATA_DIR_PORT    DDRD
#define KEYPAD_INPUT_DATA_PORT  PIND

/*-------API----------*/
void Keypad_Init(void);
char Keypad_Get_Char(void);
#endif /* KEYPAD_H_ */
