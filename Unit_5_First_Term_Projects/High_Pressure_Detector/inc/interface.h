/**
 * @file interface.h
 * 
 * @brief this file is the API interface between the 
 * different modules. 
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 03-08-2023
 * 
 * @version 1.0
 */
#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <stdint.h>

#define state(state_name) st_ ## state_name
#define define_state(state_name) void st_ ## state_name()

void send_Pval(unsigned long Pval);
void High_Pressure();
void alarm_LED_on();
void alarm_LED_off();
void setup();

#endif /*INTERFACE_H_*/