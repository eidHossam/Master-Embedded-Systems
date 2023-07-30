/**
 * @file FIFO_Buff.h
 * 
 * @brief this file implements the header for FIFO driver
 * (Queue) 
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 29-07-2023
 * 
 * @version 1.0
 */

#ifndef FIFO_BUFF_H
#define FIFO_BUFF_H

#include <stdint.h>

/*Choosing the element width*/
#define element_width uint8_t

/*Template for the FIFO buffer*/
typedef struct {
    element_width* base;
    element_width* head;
    element_width* tail;
    uint32_t capacity;
    uint32_t size;
}sFIFO_Buf_t;

typedef enum {
    FIFO_full,
    FIFO_empty,
    FIFO_no_error,
    FIFO_NULL
}eFIFO_status_t;

/*API*/
eFIFO_status_t FIFO_init(sFIFO_Buf_t* fifo_buf, element_width* buf, uint32_t capacity);
eFIFO_status_t FIFO_enqueue(sFIFO_Buf_t* fifo_buf, element_width item);
eFIFO_status_t FIFO_dequeue(sFIFO_Buf_t* fifo_buf, element_width* item);
eFIFO_status_t print_FIFO(sFIFO_Buf_t* fifo_buf);

#endif