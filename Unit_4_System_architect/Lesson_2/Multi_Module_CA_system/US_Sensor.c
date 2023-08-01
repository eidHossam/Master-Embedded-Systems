/**
 * @file US_Sensor.c
 * 
 * @brief this file implements the API for
 * the ultrasonic sensor. 
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 01-08-2023
 * 
 * @version 1.0
 */

#include "US_Sensor.h"

/*Functions protoypes*/
int US_get_random_value(int l, int r);

/*Globla variables*/
int US_distance = 0;

void US_init()
{
    printf("US init ==============> Done\n");
    US_state = state(US_busy);
}

state_define(US_busy)
{  
    /*Define the state id*/
    US_state_id = US_busy;

    /*Read the new distance from the ultrasonic sensor*/
    US_distance = US_get_random_value(45, 55);

    printf("US_busy ======== distance = %d\n",US_distance);

    /*Send the new value of the distance to the app*/
    US_get_distance(US_distance);

    /*Set the next state*/
    US_state = state(US_busy);
}


/**
 * @brief this functions generates a random number between
 *  two numbers inputted by the user
 * 
 * @param l     beggining of range
 * @param r     end of range 
 * @return int  random number
 */
int US_get_random_value(int l, int r)
{
    return (rand() % (r - l + 1) + l);
}