/*
 * I2C_Lab1_Slave.c
 *
 * Created: 10/10/2023 1:48:39 AM
 * Author : hp
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>

void I2C_SetAddress(unsigned char SLA);
unsigned char I2C_Read(unsigned char ack);

int main(void)
{
    DDRA = 0xFF;	//PortA as output
	I2C_SetAddress(0b11010000);
    while (1) 
    {
		PORTA = I2C_Read(1);
    }
}

void I2C_SetAddress(unsigned char SLA)
{
	//Set the slave address
	TWAR = SLA;
}

unsigned char I2C_Read(unsigned char ack)
{
	unsigned char x;
	 TWCR |= ((ack << TWEA) | (1 << TWEN) | (1 << TWINT));
	 
	 //Wait for the TWINT flag to be set
	 while(!(TWCR & (1 << TWINT)));
	 
	 //Wait until we get the right status code
	 while(TWSR != 0x60) x = TWSR; 

	 TWCR |= ((ack << TWEA) | (1 << TWEN) | (1 << TWINT));
	 
	  //Wait for the TWINT flag to be set
	  while(!(TWCR & (1 << TWINT)));
	  
	   //Wait until we get the right status code
	   while(TWSR != 0x80) x = TWSR;
	   
	   return TWDR;
}