/**
 * @file DC_Motor.c
 * 
 * @brief this file implements the API for the DC motor.
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 01-08-2023
 * 
 * @version 1.0
 */

#include "DC_Motor.h"

/*Globla variables*/
int DC_speed = 0;

void DC_init()
{
    printf("DC motor init ========>Done\n");

    current_state = state(DC_idle);
}

void Motor_set_speed(int speed)
{
    /*Set the new motor speed*/
    DC_speed = speed;

    printf("CA ==> DC_motor: speed = %d\n", DC_speed);

    /*Tranistion the state of the motor to the busy state*/
    DC_state = state(DC_busy);    
}

state_define(DC_idle)
{  
    /*Define the state id*/
    DC_state_id = DC_idle;

    /*We will stay in the idle state until we recieve a signal with
        the new motor speed to be set*/
    DC_state = state(DC_idle);

    printf("DC_idle ========== speed = %d\n", DC_speed);
}

state_define(DC_busy)
{
    /*Define the state id*/
    DC_state_id = DC_busy;

    /*Set the new motor speed to 30 and send it the motor module*/
        /*DC_set_speed(CA_speed);*/
    printf("DC_busy =========== speed = %d\n\n", DC_speed);

    /*Go back to the idle state*/
    DC_state = state(DC_idle);
}