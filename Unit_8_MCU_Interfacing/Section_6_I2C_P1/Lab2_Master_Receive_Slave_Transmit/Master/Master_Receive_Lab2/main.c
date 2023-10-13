/*
 * Master_Receive_Lab2.c
 *
 * Created: 10/13/2023 11:28:22 AM
 * Author : Hossam Eid
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "I2C.h"


int main(void)
{
	uint8_t receivedWord;
	DDRA = 0xFF;		//The entire port is output to the 7Seg display
	
	I2C_Init(0x48);
    while (1) 
    {
		_delay_ms(1000);
		I2C_Start();
		I2C_Write(0b11010000 + 1);	//Send the slave address + the read command
		receivedWord = I2C_Read(0);	//Read the data and send NOT ACk to stop the operation
		I2C_Stop();
		PORTA = receivedWord;		//Display the received msg on the 7Seg display
    }
}

