/**
 * @file CA.c
 * 
 * @brief this file implements the API for creating
 * the collision avoidance App.
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 31-07-2023
 * 
 * @version 2.0
 */

#include "CA.h"

/*Globla variables*/
int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;


void CA_init()
{
    CA_state = state(CA_waiting);
}

void US_get_distance(int distance)
{
    CA_distance = distance;
    
    printf("US_sensor ==> CA: distance = %d\n", CA_distance);

    /*Determine the next state based on the distance we got*/
    (CA_distance <= CA_threshold)? (CA_state = state(CA_waiting)): (CA_state = state(CA_driving));

}

state_define(CA_waiting)
{  
    /*Define the state id*/
    CA_state_id = CA_waiting;

    printf("CA_waiting ======== distance = %d =========== speed = %d\n",CA_distance, CA_speed);
    
    /*Set the new motor speed to zero and send it the motor module*/
    CA_speed = 0;

    Motor_set_speed(CA_speed);
}

state_define(CA_driving)
{
    /*Define the state id*/
    CA_state_id = CA_driving;
    
    printf("CA_driving ======== distance = %d =========== speed = %d\n",CA_distance, CA_speed);

    /*Set the new motor speed to 30 and send it the motor module*/
    CA_speed = 30;
    Motor_set_speed(CA_speed);
}