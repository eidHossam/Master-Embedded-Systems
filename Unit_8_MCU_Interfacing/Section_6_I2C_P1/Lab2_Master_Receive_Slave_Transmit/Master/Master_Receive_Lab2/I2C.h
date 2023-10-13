/*
 * I2C.h
 *
 * Created: 10/13/2023 11:44:24 AM
 *  Author: Hossam Eid
 */ 


#ifndef I2C_H_
#define I2C_H_
#include <avr/io.h>

void I2C_Init(unsigned long F_SCL);
void I2C_Start();
void I2C_Write(uint8_t word);
uint8_t I2C_Read(uint8_t ACK);
void I2C_Stop();

#endif /* I2C_H_ */