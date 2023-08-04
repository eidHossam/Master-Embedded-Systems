/**
 * @file Pressure_Sensor.h
 * 
 * @brief this file is the API for the Pressure sensor. 
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 03-08-2023
 * 
 * @version 1.0
 */
#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include "GPIO.h"
#include "interface.h"

enum {
    Psensor_init,
    read_Pval,
    send_Pvalue,
    waiting
}Psensor_state_id;

void (* Psensor_state) ();

define_state(Psensor_init);
define_state(read_Pval);
define_state(send_Pvalue);
define_state(waiting);

#endif /*PRESSURE_SENSOR_H_*/