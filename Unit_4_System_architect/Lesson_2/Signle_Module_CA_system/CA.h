/**
 * @file CA.h
 * 
 * @brief this file is the header for the
 * collision avoidance system. 
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 31-07-2023
 * 
 * @version 1.0
 */

#ifndef CA_H_
#define CA_H_

#include <stdio.h>
#include <stdlib.h>

/*Function names and declaration generators */
#define state(state_id) ST_##state_id
#define state_define(state_id) void state(state_id)()

enum {
    CA_waiting,
    CA_driving
}CA_state_id;

void (* current_state)();

void setup();
state_define(CA_waiting);
state_define(CA_driving);

#endif /* CA_H_ */