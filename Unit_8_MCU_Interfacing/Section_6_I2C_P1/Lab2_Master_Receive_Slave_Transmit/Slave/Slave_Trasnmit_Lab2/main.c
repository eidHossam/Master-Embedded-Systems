/*
 * Slave_Trasnmit_Lab2.c
 *
 * Created: 10/13/2023 11:55:21 AM
 * Author : Hossam Eid
 */ 

#include <avr/io.h>
#include "I2C.h"

int main(void)
{
    uint8_t ch = 0;
	I2C_SetAddress(0b11010000);     //Set Slave Address
    
	while (1) 
    {
		I2C_Read(1);
		I2C_Write(ch++);	
    }
}

