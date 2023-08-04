/**
 * @file LED_Driver.h
 * 
 * @brief this file is the API for the LED driver. 
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 03-08-2023
 * 
 * @version 1.0
 */
#ifndef LED_DRIVER_H_
#define LED_DRIVER_H_

#include "interface.h"
#include "GPIO.h"

enum{
    LED_init,
    LED_Off,
    LED_On
}LED_state_ID;

void (* LED_state)();

define_state(LED_init);
define_state(LED_Off);
define_state(LED_On);

#endif /*LED_DRIVER_H_*/