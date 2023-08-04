/**
 * @file algo.c
 * 
 * @brief this file implements the module responsible 
 * for deciding whether the pressure is considered 
 * high or low
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 03-08-2023
 * 
 * @version 1.0
 */
#include "../inc/algo.h"

/*Global variables*/
static uint32_t gAlgo_Pval = 0;
static uint32_t gAlgo_threshold = 20;

define_state(get_Pval)
{
    /*Set the current state ID*/
    Algo_state_id = get_Pval;

    /*Decide the next state based on the Pval*/
    (gAlgo_Pval <= gAlgo_threshold)? (Algo_state = state(get_Pval)): (Algo_state = state(High_Pressure_Detected));
}

define_state(High_Pressure_Detected)
{
    /*Set the current state ID*/
    Algo_state_id = High_Pressure_Detected;

    /*Send the alarm manager a hight pressure signal*/
    High_Pressure();

    /*Set the next state*/
    Algo_state = state(get_Pval);
}

void send_Pval(unsigned long Pval)
{
    /*Get the new pressure value.*/
    gAlgo_Pval = Pval;
}