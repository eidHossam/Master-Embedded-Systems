/**
 * @file Linked_List.h
 * 
 * @brief API for creating a students
 *  database using a daynamic linked list  
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 29-07-2023
 * 
 * @version 1.0
 */

#ifndef Linked_List_H
#define Linked_List_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    uint32_t ID;
    char name[40];
    float height;
}Sstudent_t;

typedef struct node{
    Sstudent_t student;
    struct node* pNext_node;
}SNode_t;

typedef struct{
    SNode_t* head;
    uint32_t size;
}SLinked_List_t;

typedef enum {
    heap_full,
    success,
    List_empty,
    student_not_found,
    loop_detected,
    no_loop
}eStatus_t;

SLinked_List_t* gp_Students_db;

/*Functions protoypes*/
eStatus_t add_student();
eStatus_t delete_student();
eStatus_t delete_all_students();
void fill_student_data(SNode_t* node);
eStatus_t print_students_data();
eStatus_t get_Nth_node();
eStatus_t Nth_last_node();
eStatus_t list_length_iterative();
int list_length_recursive(SNode_t *traverse_nodes);
eStatus_t middle_of_list();
eStatus_t detect_loop();
eStatus_t reverse_list();

#endif