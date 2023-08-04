/**
 * @file Alarm_Manager.c
 * 
 * @brief this file implements the API for
 * the module responsible for 
 * controlling the alarm LED 
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 03-08-2023
 * 
 * @version 1.0
 */

#include "../inc/Alarm_Manager.h"


define_state(idle)
{
    /*Set the current state ID*/
    AlarmMang_state_id = idle;

    /*Stay in the idle state until you get a high pressure signal*/
    AlarmMang_state = state(idle);
}

define_state(Alarm_On)
{
    /*Set the current state ID*/
    AlarmMang_state_id = Alarm_On;

    alarm_LED_on();

    AlarmMang_state = state(Alarm_Off);
}

define_state(Alarm_Off)
{
    /*Set the current state ID*/
    AlarmMang_state_id = Alarm_Off;

    alarm_LED_off();

	Delay(1000000);

    AlarmMang_state = state(idle);
}

void High_Pressure()
{
    AlarmMang_state = state(Alarm_On);
}