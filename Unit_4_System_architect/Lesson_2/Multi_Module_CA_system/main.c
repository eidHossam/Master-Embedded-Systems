/**
 * @file main.c
 * 
 * @brief this file tests the CA system 
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 31-07-2023
 * 
 * @version 2.0
 */

#include "CA.h"
#include "US_Sensor.h"
#include "DC_Motor.h"

int main(int argc, char const *argv[])
{
    int i;
    setup();

    for (i = 0; i < 10; i++)
    {
        (*US_state)();
        (*CA_state)();
        (*DC_state)();
    }

    return 0;
}


void setup()
{
    US_init();
    DC_init();
    CA_init();
}