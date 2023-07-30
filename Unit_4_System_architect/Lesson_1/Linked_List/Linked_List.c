/**
 * @file Linked_List.c
 * 
 * @brief this file implements the 
 *  API for creating a students
 *  database using a daynamic linked list 
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 29-07-2023
 * 
 * @version 1.0
 */

#include "Linked_List.h"

eStatus_t add_student()
{
    SNode_t * new_node, *traverse_nodes;
    new_node = (SNode_t *)malloc(sizeof(SNode_t ));

    /*Check if we allocated memory in the heap successfully*/
    if(!new_node)
        return heap_full;

    fill_student_data(new_node);
    
    /*Initialize the list if we add a student for the first time*/
    if(!gp_Students_db)
    {
        gp_Students_db = (SLinked_List_t *)malloc(sizeof(SLinked_List_t));    
        gp_Students_db->head = new_node;

        gp_Students_db->size++;
        return success;
    }

    traverse_nodes = gp_Students_db->head;

    /*Traverse the list untill we reach the last node*/
    while(traverse_nodes->pNext_node )
        traverse_nodes = traverse_nodes->pNext_node;
    
    traverse_nodes->pNext_node = new_node;
    gp_Students_db->size++;
 
    return success;
}

void fill_student_data(SNode_t* node)
{
    char temp[40];
    printf("Enter the student's ID: ");
    fgets(temp, 40, stdin);
    node->student.ID = atoi(temp);

    printf("Enter the student's name: ");
    fgets(node->student.name, 40, stdin);

    printf("Enter the student's height: ");
    fgets(temp, 40, stdin);
    node->student.height = atof(temp);

    node->pNext_node = NULL;
}

eStatus_t delete_student()
{
    uint32_t id;
    SNode_t *traverse_nodes, *prev_node = NULL;

    if(!gp_Students_db || !gp_Students_db->head)
        return List_empty;

    traverse_nodes = gp_Students_db->head;
    printf("Enter the id of the student to delete: ");
    scanf("%d", &id);

    while(traverse_nodes)
    {
        if(traverse_nodes->student.ID == id)
        {
            /*If the node to be deleted isn't the head of the list*/
            if(prev_node)
                prev_node->pNext_node = traverse_nodes->pNext_node;
            else
                /*If the node to be deleted is the head of the list*/
                gp_Students_db->head = traverse_nodes->pNext_node;
            
            free(traverse_nodes);
            gp_Students_db->size--;
            return success;
        }

        prev_node = traverse_nodes;
        traverse_nodes = traverse_nodes->pNext_node;
    }
    
    return student_not_found;
}

eStatus_t delete_all_students()
{
    SNode_t *current_node, *delete_node = NULL;

    if(!gp_Students_db || !gp_Students_db->head)
        return List_empty;

    current_node = gp_Students_db->head;
    while(current_node)
    {
        delete_node = current_node;
        current_node = current_node->pNext_node;

        free(delete_node);
        gp_Students_db->size--;
    }

    free(gp_Students_db);
    gp_Students_db = NULL;
    return success;
}

eStatus_t print_students_data()
{
    SNode_t *traverse_nodes;

    if(!gp_Students_db || !gp_Students_db->head)
    {
        printf("List is empty\n");
        return List_empty;
    }

    traverse_nodes = gp_Students_db->head;
    while(traverse_nodes)
    {
        printf("\nID: %d\nName: %sHeight: %f\n", traverse_nodes->student.ID,
        traverse_nodes->student.name,traverse_nodes->student.height);
        
        traverse_nodes = traverse_nodes->pNext_node;
    }
    return success;
}

eStatus_t get_Nth_node()
{
    uint32_t index, i;
    SNode_t *traverse_nodes;
    
    if(!gp_Students_db || !gp_Students_db->head)
        return List_empty;    
    
    printf("Enter the required node's index: ");
    scanf("%d", &index);

    traverse_nodes = gp_Students_db->head;

    for (i = 0; i < index; i++)
    {
        if (!traverse_nodes)
            return student_not_found;
        
        traverse_nodes = traverse_nodes->pNext_node;
    }

    printf("Student's data at index %d:\n", index);
    printf("ID: %d\nName: %sHeight: %f\n", traverse_nodes->student.ID,
        traverse_nodes->student.name,traverse_nodes->student.height);
    
    return success;
}

eStatus_t Nth_last_node()
{
    uint32_t index, i = 1;
    SNode_t *traverse_nodes, *tail_node;
    
    if(!gp_Students_db || !gp_Students_db->head)
        return List_empty;    
    
    printf("Enter the required node's index: ");
    scanf("%d", &index);

    traverse_nodes = gp_Students_db->head;
    tail_node = gp_Students_db->head;
    
    while(traverse_nodes)
    {
        if(i++ > index)
            tail_node = tail_node->pNext_node;
        
        traverse_nodes = traverse_nodes->pNext_node;
    }

    printf("Student's data at index %d from the end :\n", index);
    printf("ID: %d\nName: %sHeight: %f\n", tail_node->student.ID,
        tail_node->student.name,tail_node->student.height);

    return success;
}

eStatus_t list_length_iterative()
{
    uint32_t count = 0;
    SNode_t *traverse_nodes;
    
    if(!gp_Students_db || !gp_Students_db->head)
    {
        printf("The list is empty.\n");
        return List_empty;    
    }

    traverse_nodes = gp_Students_db->head;
    
    while(traverse_nodes)
    {
        count++;
        traverse_nodes = traverse_nodes->pNext_node;
    }

    printf("There is %d nodes in the list (iterative).\n", count);
    printf("There is %d nodes in the list (Recursive).\n", list_length_recursive(gp_Students_db->head));

    return success;
}

int list_length_recursive(SNode_t *traverse_nodes)
{
    
    if(!gp_Students_db || !gp_Students_db->head)
    {
        printf("The list is empty.\n");
        return 0;    
    }

    if(!traverse_nodes)
        return 0;

    return 1 + list_length_recursive(traverse_nodes->pNext_node);
}

eStatus_t middle_of_list()
{
    uint32_t i = 0;
    SNode_t *fast_node, *slow_node;
    
    if(!gp_Students_db || !gp_Students_db->head)
        return List_empty;    
    
    fast_node = gp_Students_db->head;
    slow_node = gp_Students_db->head;

    while(fast_node && fast_node->pNext_node)
    {
        fast_node = fast_node->pNext_node->pNext_node;
        slow_node = slow_node->pNext_node;
        i++;
    }

    printf("Student's data at index %d:\n", i);
    printf("ID: %d\nName: %sHeight: %f\n", slow_node->student.ID,
        slow_node->student.name,slow_node->student.height);

    return success;
}

eStatus_t detect_loop()
{
    SNode_t *fast_node, *slow_node;
    
    if(!gp_Students_db || !gp_Students_db->head)
        return List_empty;    
    
    fast_node = gp_Students_db->head;
    slow_node = gp_Students_db->head;

    while(fast_node && fast_node->pNext_node)
    {
        if(fast_node == slow_node)
            return loop_detected;

        fast_node = fast_node->pNext_node->pNext_node;
        slow_node = slow_node->pNext_node;
    }
    return no_loop;
}

eStatus_t reverse_list()
{
    SNode_t *next_node, *current_node, *prev_node;
    
    if(!gp_Students_db || !gp_Students_db->head)
        return List_empty;    
    
    current_node = gp_Students_db->head;
    prev_node = NULL;

    while(current_node)
    {
        next_node = current_node->pNext_node;
        current_node->pNext_node = prev_node;
        prev_node = current_node;
        current_node = next_node;
    }

    gp_Students_db->head = prev_node;
    printf("List reversed successfully!\n");
    return success;
}