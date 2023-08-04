/**
 * @file Alarm_Manager.h
 * 
 * @brief this file is the API for managing the alarm 
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 03-08-2023
 * 
 * @version 1.0
 */
#ifndef AlARM_MANAGER_H_
#define AlARM_MANAGER_H_

#include "interface.h"
#include "GPIO.h"

enum {
    idle,
    Alarm_On,
    Alarm_Off
}AlarmMang_state_id;

void (* AlarmMang_state) ();

define_state(idle);
define_state(Alarm_On);
define_state(Alarm_Off);

#endif /*AlARM_MANAGER_H_*/