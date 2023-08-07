/**
 * @file FIFO_Buff.h
 * 
 * @brief this file implements the header for FIFO driver
 * (Queue) dynamically  
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 05-08-2023
 * 
 * @version 1.0
 */

#ifndef FIFO_BUFF_H
#define FIFO_BUFF_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define MAX_CAPACITY 50

#define SEARCH_ROLL 0
#define SEARCH_COURSE_ID 1
#define SEARCH_FNAME 2

#define DPRINTF(...) {fflush(stdout); \
					  fflush(stdin); \
					  printf(__VA_ARGS__); \
					  fflush(stdout); \
					  fflush(stdin);}

typedef struct{
    char fName[50];
    char lName[50];
    int roll;
    float GPA;
    int Cid[5];
}sStudentData_t;

typedef struct node{
    sStudentData_t* student;
    struct node* pNext_node;
}SNode_t;

/*Template for the FIFO buffer*/
typedef struct {
    SNode_t* head;
    SNode_t* tail;
    uint32_t capacity;
    uint32_t size;
}sFIFO_Buf_t;

typedef enum {
    FIFO_full,
    FIFO_empty,
    FIFO_no_error,
    FIFO_NULL,
    student_found,
    student_not_found,
    update_successfull
}eFIFO_status_t;

sFIFO_Buf_t* students_db;

/*API*/
eFIFO_status_t FIFO_init();
eFIFO_status_t FIFO_enqueue(sStudentData_t* newStudent);
eFIFO_status_t FIFO_dequeue();
eFIFO_status_t delete_node();
eFIFO_status_t update_node();
eFIFO_status_t search_queue(int search_method, int search_for);
eFIFO_status_t print_FIFO();
eFIFO_status_t print_student(sStudentData_t* newStudent);

#endif