/**
 * @file LIFO_Buff.c
 * 
 * @brief this file implements the LIFO interface
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 29-07-2023
 * 
 * @version 1.0
 */
#include "LIFO_Buff.h"

eLIFO_status_t LIFO_init(sLIFO_Buff_t* lifo_buff, element_type* buff, uint32_t capacity)
{
    /*Check if the given buffer is valid*/
    if(!buff)
        return LIFO_NULL;

    lifo_buff->base = buff;
    lifo_buff->head = buff;
    lifo_buff->capacity = capacity;
    lifo_buff->size = 0;

    return LIFO_no_error;
}

eLIFO_status_t LIFO_push(sLIFO_Buff_t* lifo_buff, element_type item)
{
    /*Check if the given LIFO buffer had been initialized*/
    if(!lifo_buff || !lifo_buff->base || !lifo_buff->head)
        return LIFO_NULL;

    if(lifo_buff->size >= lifo_buff->capacity)
        return LIFO_full;
    
    *(lifo_buff->head++) = item;
    lifo_buff->size++;

    return LIFO_no_error;
}

eLIFO_status_t LIFO_pop(sLIFO_Buff_t* lifo_buff, element_type* item)
{
    /*Check if the given LIFO buffer had been initialized*/
    if(!lifo_buff || !lifo_buff->base || !lifo_buff->head)
        return LIFO_NULL;

    if(lifo_buff->size == 0)
        return LIFO_empty;
    
    *item = *(--lifo_buff->head);
    lifo_buff->size--;

    return LIFO_no_error;
}
