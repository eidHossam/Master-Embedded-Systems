/*
 * I2C.h
 *
 * Created: 10/13/2023 11:55:48 AM
 *  Author: Hossam Eid
 */ 


#ifndef I2C_H_
#define I2C_H_
#include <avr/io.h>

void I2C_SetAddress(uint8_t address);
uint8_t I2C_Read(uint8_t ack);
void I2C_Write(uint8_t cByte);

#endif /* I2C_H_ */