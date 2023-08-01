/**
 * @file US_Sensor.h
 * 
 * @brief this file is the API for the Ultrasonic sensor. 
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 01-08-2023
 * 
 * @version 1.0
 */
#ifndef US_SENSOR_H_
#define US_SENSOR_H_

#include "state.h"

enum {
    US_busy
}US_state_id;

void (* US_state)();

void US_init();
state_define(US_busy);

#endif /* US_SENSOR_H_ */