/**
 * @file DC_Motor.h
 * 
 * @brief this file is the API for the DC_Motor 
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 01-08-2023
 * 
 * @version 1.0
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "state.h"


enum {
    DC_idle,
    DC_busy
}DC_state_id;

void (* DC_state)();

void DC_init();
state_define(DC_idle);
state_define(DC_busy);

#endif /* DC_MOTOR_H_ */