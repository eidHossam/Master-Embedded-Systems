/**
 * @file CA.c
 * 
 * @brief this file implements the API for creating
 * the collision avoidance system.
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 31-07-2023
 * 
 * @version 1.0
 */

#include "CA.h"

/*Functions protoypes*/
int US_get_distance(int l, int r);

/*Globla variables*/
int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;

void setup()
{
    printf("US init ==============> Done\n");
    printf("DC motor init ========>Done\n");

    current_state = state(CA_waiting);
}

state_define(CA_waiting)
{  
    /*Define the state id*/
    CA_state_id = CA_waiting;

    /*Set the new motor speed to zero and send it the motor module*/
    CA_speed = 0;
    /*DC_set_speed(CA_speed);*/

    printf("CA_waiting ======== distance = %d =========== speed = %d\n",CA_distance, CA_speed);

    /*Read the new distance from the ultrasonic sensor*/
    CA_distance = US_get_distance(45, 55);

    /*Determine the next state based on the distance we got*/
    (CA_distance <= CA_threshold)? (current_state = state(CA_waiting)): (current_state = state(CA_driving));
}

state_define(CA_driving)
{
    /*Define the state id*/
    CA_state_id = CA_driving;

    /*Set the new motor speed to 30 and send it the motor module*/
    CA_speed = 30;
    /*DC_set_speed(CA_speed);*/

    printf("CA_driving ======== distance = %d =========== speed = %d\n",CA_distance, CA_speed);

    /*Read the new distance from the ultrasonic sensor*/
    CA_distance = US_get_distance(45, 55);

    /*Determine the next state based on the distance we got*/
    (CA_distance <= CA_threshold)? (current_state = state(CA_waiting)): (current_state = state(CA_driving));
}

/**
 * @brief this functions generates a random number between
 *  two numbers inputted by the user
 * 
 * @param l     beggining of range
 * @param r     end of range 
 * @return int  random number
 */
int US_get_distance(int l, int r)
{
    return (rand() % (r - l + 1) + l);
}