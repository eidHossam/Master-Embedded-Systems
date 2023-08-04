/**
 * @file algo.h
 * 
 * @brief this file is the API for the main algorithm. 
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 03-08-2023
 * 
 * @version 1.0
 */
#ifndef ALGO_H_
#define ALGO_H_

#include "interface.h"

enum {
    get_Pval,
    High_Pressure_Detected
}Algo_state_id;

void (* Algo_state) ();

define_state(get_Pval);
define_state(High_Pressure_Detected);

#endif /*ALGO_H_*/