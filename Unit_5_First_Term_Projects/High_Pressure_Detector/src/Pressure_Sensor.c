/**
 * @file Pressure_Sensor.c
 * 
 * @brief this file implements the Pressure sensor module 
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 03-08-2023
 * 
 * @version 1.0
 */
#include "../inc/pressure_Sensor.h"

/*global variables*/
static uint32_t gPsensor_Pval = 0;

define_state(Psensor_init)
{
    /*Set the current state ID*/
    Psensor_state_id = Psensor_init;

    /*Set the next state ID*/
    Psensor_state = state(read_Pval);
}

define_state(read_Pval)
{
    /*Set the current state ID*/
    Psensor_state_id = read_Pval;

    /*Get the pressure value*/
    gPsensor_Pval = getPressureVal();

    /*Set the next state ID*/
    Psensor_state = state(send_Pvalue);    
}

define_state(send_Pvalue)
{
    /*Set the current state ID*/
    Psensor_state_id = send_Pvalue;

    /*Send the pressure value to the main algorithm*/
    send_Pval(gPsensor_Pval);

    /*Set the next state ID*/
    Psensor_state = state(waiting);

}

define_state(waiting)
{
    /*Set the current state ID*/
    Psensor_state_id = waiting;

    /*Delay between readings*/
    Delay(10000);

    /*Set the next state ID*/
    Psensor_state = state(read_Pval);
}
