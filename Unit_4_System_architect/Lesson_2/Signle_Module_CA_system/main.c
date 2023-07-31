/**
 * @file main.c
 * 
 * @brief this file tests the CA system 
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 31-07-2023
 * 
 * @version 1.0
 */

#include "CA.h"

int main(int argc, char const *argv[])
{
    setup();

    while(1)
    {
        (*current_state)();
    }

    return 0;
}
