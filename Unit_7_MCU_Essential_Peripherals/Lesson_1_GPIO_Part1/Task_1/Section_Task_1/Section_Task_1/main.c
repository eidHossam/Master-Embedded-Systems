/*
 * Section_Task_1.c
 *
 * Created: 8/28/2023 8:32:48 PM
 * Author : Hossam Eid
 */ 

#define F_CPU 8000000ul
#include "io.h"
#include "Bit_Math.h"
#include <util/delay.h>

int main(void)
{
    unsigned char LED_on_flag = 1, pin = 0;
    //Set all pins of PORTA as output
    DDRA = 0xFF;

    while (1) 
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
		_delay_ms(500);
    }
}

