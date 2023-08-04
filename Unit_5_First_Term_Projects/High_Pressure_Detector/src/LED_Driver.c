/**
 * @file LED_Driver.c
 * 
 * @brief this file implements the LED driver 
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 03-08-2023
 * 
 * @version 1.0
 */

#include "../inc/LED_Driver.h"

define_state(LED_init)
{
    /*Set the current state ID*/
    LED_state_ID = LED_init;

    LED_state = state(LED_Off);
}

define_state(LED_Off)
{
    /*Set the current state ID*/
    LED_state_ID = LED_Off;

    /*Turn off the LED*/
    Set_Alarm_actuator(1);

    /*Stay in this state untill you get an LED_on signal*/
    LED_state = state(LED_Off);
}

define_state(LED_On)
{
    /*Set the current state ID*/
    LED_state_ID = LED_On;

    /*Turn off the LED*/
    Set_Alarm_actuator(0);

    /*Stay in this state untill you get an LED_on signal*/
    LED_state = state(LED_On);
}

void alarm_LED_on()
{
    LED_state = state(LED_On);
}

void alarm_LED_off()
{
    LED_state = state(LED_Off); 
}

