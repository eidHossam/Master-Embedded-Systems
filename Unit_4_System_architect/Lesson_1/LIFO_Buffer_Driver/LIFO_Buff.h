/**
 * @defgroup   LIFO_BUFF LIFO Buffer
 *
 * @brief      This file is the header of
 *  LIFO Buffer (stack).
 *
 * @author     Hossam Eid (eidhossam7@gmail.com)
 * @date       07/29/23
 */

/**
 * @brief 
 * 
 */

#ifndef LIFO_BUFF_h
#define LIFO_BUFF_h

#include <stdint.h>

/*Choose the element width*/
#define element_type uint8_t 

typedef struct {
    uint32_t capacity;
    uint32_t size;
    element_type *base;
    element_type *head;

} sLIFO_Buff_t;

typedef enum {
    LIFO_full,
    LIFO_empty,
    LIFO_no_error,
    LIFO_NULL
}eLIFO_status_t;

/*API's headers*/
eLIFO_status_t LIFO_init(sLIFO_Buff_t* lifo_buff, element_type* buff, uint32_t capacity);
eLIFO_status_t LIFO_push(sLIFO_Buff_t* lifo_buff, element_type item);
eLIFO_status_t LIFO_pop(sLIFO_Buff_t* lifo_buff, element_type* item);

#endif
