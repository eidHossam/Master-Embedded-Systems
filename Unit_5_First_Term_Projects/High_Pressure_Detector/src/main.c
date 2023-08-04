/**
 * @file main.c
 * 
 * @brief this file tests the program 
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 03-08-2023
 * 
 * @version 1.0
 */
#include <stdint.h>
#include <stdio.h>

#include "../inc/Alarm_Manager.h"
#include "../inc/algo.h"
#include "../inc/GPIO.h"
#include "../inc/interface.h"
#include "../inc/LED_Driver.h"
#include "../inc/Pressure_Sensor.h"

int main ()
{
	setup();
	
	while (1)
	{
		(*Psensor_state)(); 
		(*Algo_state)(); 
		(*AlarmMang_state)(); 
		(*LED_state)(); 
	}
	return 0;
}	


void setup()
{
	GPIO_INITIALIZATION();
	state(LED_Off)();
	state(Psensor_init)();
	Algo_state = state(get_Pval);
	AlarmMang_state = state(idle);
}