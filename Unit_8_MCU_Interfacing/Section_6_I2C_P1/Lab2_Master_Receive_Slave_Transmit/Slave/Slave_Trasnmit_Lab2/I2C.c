/*
 * I2C.c
 *
 * Created: 10/13/2023 11:55:39 AM
 *  Author: Hossam Eid
 */ 

#include "I2C.h"

void I2C_SetAddress(uint8_t address)
{
	//Set the slave address
	TWAR = address;
}

uint8_t I2C_Read(uint8_t ack)
{
	/*TWEN must be written to one to enable the TWI.
	The TWEA bit must be written to one to enable the acknowledgment
	 of the device’s own slave address
	or the general call address. TWSTA and TWSTO must be written to zero.*/
	TWCR = ((ack << TWEA) | (1 << TWEN) | (1 << TWINT));
	
	while(!(TWCR & (1 << TWINT)));
	
	return TWDR;
}

void I2C_Write(uint8_t cByte)
{
	TWDR = cByte;
	/*TWEN must be written to one to enable the TWI.
	The TWEA bit must be written to one to enable the acknowledgment
	 of the device’s own slave address
	or the general call address. TWSTA and TWSTO must be written to zero.*/
	TWCR = ((1 << TWINT) | (1 << TWEN));
	
	while(!(TWCR & (1 << TWINT)));
}