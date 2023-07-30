/**
 * @file main.c
 * 
 * @brief this file tests the LIFO driver 
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 29-07-2023
 * 
 * @version 1.0
 */

#include "LIFO_Buff.h"
#include <stdio.h>

int main()
{
    sLIFO_Buff_t stack;
    element_type buffer[5], i, temp;

    LIFO_init(&stack, buffer, 5);

    for (i = 0; i < 7; i++)
    {
        if(LIFO_push(&stack, i) == LIFO_no_error)
            printf("%d\n", i);
        else
            printf("LIFO full\n");
    }

    for (i = 0; i < 7; i++)
    {
        if(LIFO_pop(&stack, &temp) == LIFO_no_error)
            printf("\n%d", temp);
        else
            printf("\nLifo Empty");
    }

    return 0;
}

