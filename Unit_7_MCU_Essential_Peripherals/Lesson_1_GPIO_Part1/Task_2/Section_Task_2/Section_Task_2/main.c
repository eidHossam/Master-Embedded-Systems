/*
 * Section_Task_2.c
 *
 * Created: 8/28/2023 9:30:36 PM
 * Author : Hossam Eid
 */ 

#define  F_CPU 8000000ul
#include "io.h"
#include "Bit_Math.h"
#include <util/delay.h>


int main(void)
{
	unsigned char LED_on_flag = 1, pin = 0;
	
	DDRA = 0xFF;			//Set all pins of PORTA as output
	CLEAR_BIT(DDRD, 0);		//PD0 as input
	
	while (1)
	{
		if(READ_BIT(PIND, 0) == 1)
		{
			if(LED_on_flag)
			{
				SET_BIT(PORTA, pin++);

				if(pin == 8)
				LED_on_flag = 0;
				}else{

				CLEAR_BIT(PORTA, --pin);

				if(pin == 0)
				LED_on_flag = 1;
			}
			
			while(READ_BIT(PIND, 0) == 1);
		}
	}
}

