/**
 * @file students_dbf.c
 * 
 * @brief this file implements the FIFO interface
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 05-08-2023
 * 
 * @version 1.0
 */

#include "../inc/FIFO_Buff.h"

/*Functions declarations*/
static eFIFO_status_t search_roll(sStudentData_t*, int);
static eFIFO_status_t search_courseID(sStudentData_t*, int);
static eFIFO_status_t search_fName(sStudentData_t*, int);

static void update_roll(sStudentData_t*);
static void update_fName(sStudentData_t*);
static void update_lName(sStudentData_t*);
static void update_gpa(sStudentData_t*);
static void update_Clist(sStudentData_t*);

/*Global variables*/
eFIFO_status_t (* p_search_funcs[]) (sStudentData_t* student_data, int) = {
    search_roll,
    search_courseID,
    search_fName
};
void (* p_update_funcs[]) (sStudentData_t *) = {
    update_roll,
    update_fName,
    update_lName,
    update_gpa,
    update_Clist
};
int first_time_in_func = 1;

/*Functions defenitions*/
eFIFO_status_t FIFO_init()
{
    students_db = (sFIFO_Buf_t *) malloc(sizeof(sFIFO_Buf_t));
   
    /*Check if the buffer is valid*/
    if (!students_db)
        return FIFO_NULL;
    
    /*Initialize the FIFO buffer*/
    students_db->head = NULL;
    students_db->tail = NULL;
    students_db->capacity = MAX_CAPACITY;
    students_db->size = 0;

    return FIFO_no_error;
}

eFIFO_status_t FIFO_enqueue(sStudentData_t* newStudent)
{
    SNode_t* newNode;

    /*Check if the FIFO buffer is valid*/
    if (!students_db)
        return FIFO_NULL;
    
    /*Check if there is space left in the buffer*/
    if (students_db->size >= students_db->capacity)
        return FIFO_full;
    
    newNode = (SNode_t *)(malloc(sizeof(SNode_t)));

    /*Check if it is the first node*/
    if(!students_db->head)
    {
        students_db->head = newNode;
        students_db->tail = newNode;
    }else{
        students_db->tail->pNext_node = newNode;
        students_db->tail = students_db->tail->pNext_node;
    }
    students_db->tail->pNext_node = NULL;
    newNode->student = newStudent;
    students_db->size++;

    /*DPRINTF("Student added successfully!.\n");*/
    return FIFO_no_error;
}

eFIFO_status_t FIFO_dequeue()
{
    SNode_t* delNode;
    /*Check if the FIFO buffer is valid*/
    if (!students_db || !students_db->head || !students_db->tail)
        return FIFO_NULL;
    
    /*Check if the buffer is empty*/
    if (students_db->size == 0)
        return FIFO_empty;
    
    delNode = students_db->head;
    students_db->head = students_db->head->pNext_node;
    free(delNode);

    students_db->size--;

    /*DPRINTF("Student Deleted successfully!.\n");*/
    return FIFO_no_error;
}

eFIFO_status_t delete_node()
{
    int id;
    SNode_t *traverse_nodes, *prev_node = NULL;
    
    /*Check if the FIFO buffer is valid*/
    if (!students_db || !students_db->head || !students_db->tail)
        return FIFO_NULL;
    
    /*Check if the buffer is empty*/
    if (students_db->size == 0)
        return FIFO_empty;

    traverse_nodes = students_db->head;
    DPRINTF("Enter the roll number of the student to delete: ");
    scanf("%d", &id);

    while(traverse_nodes)
    {
        if(traverse_nodes->student->roll == id)
        {
            /*If the node to be deleted isn't the head of the list*/
            if(prev_node)
                prev_node->pNext_node = traverse_nodes->pNext_node;
            else
            {
                /*If the node to be deleted is the head of the list*/
                students_db->head = traverse_nodes->pNext_node;
                students_db->tail = traverse_nodes->pNext_node;
            }
            
            free(traverse_nodes);
            students_db->size--;
            return FIFO_no_error;
        }

        prev_node = traverse_nodes;
        traverse_nodes = traverse_nodes->pNext_node;
    }
    
    return student_not_found;
}

eFIFO_status_t update_node()
{
    int id, choice;
    SNode_t *traverse_nodes;
    
    /*Check if the FIFO buffer is valid*/
    if (!students_db || !students_db->head || !students_db->tail)
        return FIFO_NULL;
    
    /*Check if the buffer is empty*/
    if (students_db->size == 0)
        return FIFO_empty;

    traverse_nodes = students_db->head;
    DPRINTF("Enter the roll number of the student to update: ");
    scanf("%d", &id);

    while(traverse_nodes)
    {
        if(traverse_nodes->student->roll == id)
        {
            DPRINTF("\nWhich date do you want to change ?\n");
	        DPRINTF("\t 1: The Roll Number\n");
	        DPRINTF("\t 2: The First Name\n");
	        DPRINTF("\t 3: The Second Name\n");
	        DPRINTF("\t 4: The GPA Score\n");
	        DPRINTF("\t 5: The Courses ID\n");
	        DPRINTF("Enter your option: ");   
            scanf("%d", &choice);

            (* p_update_funcs[choice - 1]) (traverse_nodes->student);

            return update_successfull;
        }

        traverse_nodes = traverse_nodes->pNext_node;
    }
    
    return student_not_found;
}

eFIFO_status_t search_queue(int search_method, int search_for)
{
    SNode_t* currentElement;
    int8_t i;
    /*Check if the FIFO buffer is valid*/
    if (!students_db || !students_db->head || !students_db->tail)
        return FIFO_NULL;

        /*Check if the buffer is empty*/
    if (students_db->size == 0)
        return FIFO_empty;

    currentElement = students_db->head;
    first_time_in_func = 1;

    while(currentElement)
    {
        /*Check if we are searching by roll number and already found the student stop the search
        to increase the performence*/
        if((* p_search_funcs[search_method])(currentElement->student, search_for) == student_found 
            && search_method != SEARCH_COURSE_ID)
            {
                return student_found;
            }
        
        currentElement = currentElement->pNext_node;
    }
    return FIFO_no_error;
}

eFIFO_status_t print_FIFO()
{
    SNode_t* currentElement;
    int i;

    /*Check if the FIFO buffer is valid*/
    if (!students_db || !students_db->head || !students_db->tail)
        return FIFO_NULL;

        /*Check if the buffer is empty*/
    if (students_db->size == 0)
        return FIFO_empty;

    currentElement = students_db->head;

    while(currentElement)
    {
        print_student(currentElement->student);
        currentElement = currentElement->pNext_node;
    }
    return FIFO_no_error;
}

eFIFO_status_t print_student(sStudentData_t* newStudent)
{
    int i;
    if(!newStudent)
        return FIFO_NULL;

    DPRINTF("\nFirst name: %s\nLast name: %s\n",newStudent->fName, newStudent->lName);
    DPRINTF("Roll number: %d\nGPa: %f\n", newStudent->roll, newStudent->GPA);
    DPRINTF("List of courses:\n");

    for(i = 0; i < 5; i++)
    {
        DPRINTF("%d-Course ID: %d\n", (i + 1), newStudent->Cid[i]);
    }
}

static eFIFO_status_t search_roll(sStudentData_t* student_data, int rollNum)
{
    if(student_data->roll == rollNum)
    {
        DPRINTF("Student with this roll number found:");
        print_student(student_data);
        return student_found;
    }
    return FIFO_no_error;
}

static eFIFO_status_t search_courseID(sStudentData_t* student_data, int Cid)
{
    int i;
    for(i = 0; i < 5; i++)
    {
        if(student_data->Cid[i] == Cid)
        {
            DPRINTF("\n-------------------------------------------------");
            print_student(student_data);
            break;
        }
    }
    return FIFO_no_error;
}

static eFIFO_status_t search_fName(sStudentData_t* student_data, int empty)
{
    static char name[50];
    if(first_time_in_func == 1)
    {
        DPRINTF("Enter the first name of the student: ");
        scanf("%s", name);
        first_time_in_func = 0;
    }

    if(strcasecmp(student_data->fName, name) == 0)
    {
        DPRINTF("Student with this first name found:");
        print_student(student_data);
        return student_found;
    }
    return FIFO_no_error;
}

static void update_roll(sStudentData_t* student)
{
    DPRINTF("Enter roll number: ");
    scanf("%d", &student->roll);

}

static void update_fName(sStudentData_t* student)
{
    DPRINTF("Enter first name: ");
    scanf("%s", student->fName);
}

static void update_lName(sStudentData_t* student)
{
    DPRINTF("Enter last name: ");
    scanf("%s", student->lName);
}

static void update_gpa(sStudentData_t* student)
{
    DPRINTF("Enter GPA: ");
    scanf("%f", &student->GPA);
}

static void update_Clist(sStudentData_t* student)
{
    int i;
    for(i = 0; i < 5; i++)
    {
        DPRINTF("Enter course %d ID: ", i + 1);
        scanf("%d", &student->Cid[i]);
    }   

}

