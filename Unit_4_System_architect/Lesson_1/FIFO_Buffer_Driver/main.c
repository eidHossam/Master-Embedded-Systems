/**
 * @file main.c
 * 
 * @brief this file tests the FIFO Buffer driver 
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 29-07-2023
 * 
 * @version 1.0
 */

#include "FIFO_Buff.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    sFIFO_Buf_t queue;
    element_width buffer[5], i, temp;

    FIFO_init(&queue, buffer, 5);

     for (i = 0; i < 7; i++)
    {
        if(FIFO_enqueue(&queue, i) == FIFO_no_error)
            printf("FIFO enqueue ===========> Done\n");
        else
            printf("FIFO full\n");
    }
    
    print_FIFO(&queue);

    printf("\n\n");
    
    FIFO_dequeue(&queue, &temp);
    FIFO_dequeue(&queue, &temp);

    print_FIFO(&queue);

    printf("\n\n");
    
    FIFO_enqueue(&queue, 5);
    FIFO_enqueue(&queue, 6);
    
    print_FIFO(&queue);
    return 0;
}
