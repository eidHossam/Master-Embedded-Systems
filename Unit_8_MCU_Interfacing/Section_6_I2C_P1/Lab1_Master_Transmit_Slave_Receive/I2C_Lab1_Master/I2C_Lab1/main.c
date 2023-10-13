/*
 * I2C_Lab1.c
 *
 * Created: 10/9/2023 10:09:49 PM
 * Author : Hossam Eid
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define PRESCALER 1

void I2C_Init(unsigned long F_SCL);
void I2C_Start();
void I2C_Write(unsigned char word);
void I2C_Stop();

int main(void)
{	
	unsigned char c = 0;
	I2C_Init(0x48);
    while (1) 
    {	
		_delay_ms(500);
		
		I2C_Start();
		I2C_Write(0b11010000 + 0);	//Send the SLA + W
		
		//Wait until we get the right status code
		while(TWSR != 0x18);	  //slave address + W(0) has been transmitted and ACK has been received
		
		I2C_Write(c++);		//Transmit data
		
		//Wait until we get the right status code
		while(TWSR != 0x28);		//data has been transmitted and ACK has been received
		
		I2C_Stop();
    }
}

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
   TWCR = ((1 << TWSTA) | (1 << TWEN) | (1 << TWINT)); 
   
   //Wait for the TWINT flag to be set
   while(!(TWCR & (1 << TWINT)));
	
	//Wait until we get the right status code
	while(TWSR != 0x08);
}

void I2C_Write(unsigned char word)
{
	TWDR = word;

	//Clear the TWINT flag to continue the transmission
	TWCR = ((1 << TWEN) | (1 << TWINT));
	
	//Wait for the TWINT flag to be set
	while(!(TWCR & (1 << TWINT)));
	
}

void I2C_Stop()
{
    TWCR = ((1 << TWSTO) | (1 << TWEN) | (1 << TWINT));
}
