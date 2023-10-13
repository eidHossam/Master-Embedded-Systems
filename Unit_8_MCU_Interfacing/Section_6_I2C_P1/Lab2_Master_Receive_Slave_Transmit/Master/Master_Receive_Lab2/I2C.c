/*
 * I2C.c
 *
 * Created: 10/13/2023 11:44:35 AM
 *  Author: Hossam Eid
 */ 

#include "I2C.h"

#define PRESCALER 1
#define F_CPU 8000000UL


void I2C_Init(unsigned long F_SCL)
{
	//Set the bit-rate in TWBR register
	TWBR = ((F_CPU / F_SCL) - 16) / (2 * PRESCALER);
	
	//Set the prescaler value in the TWSR register
	if(PRESCALER == 1)
	TWSR = 0;
	else if(PRESCALER == 4)
	TWSR = 1;
	else if(PRESCALER == 16)
	TWSR = 2;
	else if(PRESCALER == 64)
	TWSR = 3;
}

void I2C_Start()
{
	/*A START condition is sent by writing to the TWI Control register (TWCR) a value of the type
	TWCR=1x10x10x:
	• TWCR.TWEN must be written to '1' to enable the 2-wire Serial Interface
	• TWCR.TWSTA must be written to '1' to transmit a START condition
	• TWCR.TWINT must be cleared by writing a '1' to it.*/
	TWCR = ((1 << TWEN) | (1 << TWSTA) | (1 << TWINT)); 
	
	/*Wait for the TWINT flag to be set*/
	while(!(TWCR & (1 << TWINT)));
	
	/*Wait for the right status message*/
	while(TWSR != 0x08);
}

void I2C_Write(uint8_t word)
{
	/*Load the data register with the data*/
	TWDR = word;
	
	/*Clear the TWINT flag to begin the transmission*/
	TWCR = ((1 << TWEN) | (1 << TWINT));
	
	/*Wait for the TWINT flag to be set*/
	while(!(TWCR & (1 << TWINT)));
}

uint8_t I2C_Read(uint8_t ACK)
{
	/*Clear the TWINT flag to continue the transmission*/
	TWCR = ((1 << TWEN) | (1 << TWINT) | (ACK << TWEA));
	
	/*Wait for the TWINT flag to be set*/
	while(!(TWCR & (1 << TWINT)));
	
	return TWDR;
}

void I2C_Stop()
{
	/*Send a stop condition*/
	TWCR = ((1 << TWEN) | (1 << TWINT) | (1 << TWSTO));
}