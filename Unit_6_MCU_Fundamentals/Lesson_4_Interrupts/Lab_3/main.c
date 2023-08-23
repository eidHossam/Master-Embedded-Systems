/*
* main.c
*
* Created: 8/23/2023 5:26:01 PM
*  Author: Hossam Eid
*/

#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

/*Functions declarations*/
void interrupt_init();
void GPIO_init();

int main(void)
{
	interrupt_init();
	GPIO_init();
	while(1)
	{
		//TODO:: Please write your application code
	}
}

void interrupt_init()
{
	/*Setting the triggering edge for INT0 and INT1*/
	MCUCR	|= (1 << 0);					//INT0 any logical change
	MCUCR	&= ~(1<<1);
	MCUCR	|= (1 << 2 | 1 << 3);			//INT1 rising edge
	MCUCSR	&= ~(1 << 6);					//INT2 falling edge
	
	//Mask INT0 : 2
	GICR |= (1 << 7 | 1 << 6 | 1 << 5);
	
	//Enable global interrupts
	SREG |= (1 << 7);
}

void GPIO_init()
{ 
	DDRD	&= ~(0b11 << 2);								//PD2, PD3 as input
	
	DDRD	|= (1 << 7 | 1 << 6 | 1 << 5);					//PD5 : 7 as output
	PORTD	&= ~((1 << 7 | 1 << 6 | 1 << 5));				//LEDS initially off
}

ISR(INT0_vect)
{
	PORTD |= (1 << 5);	//LED0 On
	
	_delay_ms(1000);
	
	PORTD &= ~(1 << 5);	//LED0 off
}

ISR(INT1_vect)
{
	PORTD |= (1 << 6);	//LED1 On
	
	_delay_ms(1000);
	
	PORTD &= ~(1 << 6);	//LED1 off
}

ISR(INT2_vect)
{
	PORTD |= (1 << 7);	//LED2 On
	
	_delay_ms(1000);
	
	PORTD &= ~(1 << 7);	//LED2 off	
}