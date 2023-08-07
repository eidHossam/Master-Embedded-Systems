/**
 * @file Student_DB.c
 * 
 * @brief this file implements the APi for
 * the students database.
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 06-08-2023
 * 
 * @version 1.0
 */

#include "../inc/Student_DB.h"

/*Functios declarations that will be used in this file only*/
static void get_student_data(sStudentData_t* student);


void add_student_file()
{
    FILE *student_data_file;
    int roll, i;
    sStudentData_t* newStudent;
    student_data_file = fopen("student_data.txt", "r");

    if(student_data_file)
    {
        /*Reading students until end of file this using of feof == Check end of file*/
        while (!feof(student_data_file)) {

            newStudent = (sStudentData_t *) malloc(sizeof(sStudentData_t));
            
            fscanf(student_data_file, "%d", &newStudent->roll);
            
            /*Make sure there are no students with the same roll number*/
            if(search_queue(SEARCH_ROLL, newStudent->roll) == student_found)
            {
                printf("----------------------------\n");
                printf("Error\n");
                printf("----------------------------\n");

                /*Ignore the rest of the line*/
			    fscanf(student_data_file, "%*[^\n]");
                continue;
            }

            /* Reading data first name, last name and GPA sequential*/
		    fscanf(student_data_file, "%s", newStudent->fName);
		    fscanf(student_data_file, "%s", newStudent->lName);
		    fscanf(student_data_file, "%f", &newStudent->GPA);

		    /* Reading course IDs*/
		    for (i = 0; i < 5; ++i)
		    {
			    fscanf(student_data_file, "%d", &newStudent->Cid[i]);
		    }

            FIFO_enqueue(newStudent);
        }

        printf("Students added successfully\n");
        printf("[INFO]Total number of students = %d\n", students_db->size);
        printf("[INFO]Empty space available = %d\n", (students_db->capacity - students_db->size));

        fclose(student_data_file);
    }
    else   
        printf("failed to Open data file\n");
}

void add_student_manually()
{
    sStudentData_t* newStudent = (sStudentData_t *) malloc(sizeof(sStudentData_t));

    /*Check if we successfully located memory in the heap for the new student*/
    if(!newStudent)
    {
        printf("\nCouldn't allocate memory for the student\n");
        return;
    } 

    get_student_data(newStudent);

    /*Check if the roll number we got exists in our database*/
    if(search_queue(SEARCH_ROLL, newStudent->roll) == student_found)
    {
        printf("\n[FAILED] This roll number is already in the database!.\n");
        return;
    }

    if(FIFO_enqueue(newStudent) == FIFO_no_error)
    {
        printf("Student added successfully\n");
        printf("[INFO]Total number of students = %d\n", students_db->size);
        printf("[INFO]Empty space available = %d\n", (students_db->capacity - students_db->size));
    }else
    {
        printf("Failed to add the new students\n");
    }
}

void find_roll()
{
    int rollNumber;
    
    fflush(stdin);
    printf("Enter the roll number to search for: ");
    scanf("%d", &rollNumber);

    if(search_queue(SEARCH_ROLL, rollNumber) != student_found)
    {
        printf("Could not find student with roll number %d\n", rollNumber);
    }
}

void find_fName()
{ 
    if(search_queue(SEARCH_FNAME, SEARCH_FNAME) != student_found)
    {
        printf("Could not find the student\n");
    }
}

void find_students_inCourse()
{
    int Cid;
    
    fflush(stdin);
    printf("Enter the course ID to search for: ");
    scanf("%d", &Cid);

    printf("List of students in this course: ");
    search_queue(SEARCH_COURSE_ID, Cid);    
}

void total_students()
{
    printf("[INFO]Total number of students = %d\n", students_db->size);
    printf("[INFO]Empty space available = %d\n", (students_db->capacity - students_db->size));

}

void delete_student()
{
    if(delete_node() == student_not_found)
    {
        printf("There is no student with the given roll number.\n");
    }else{
        printf("The student with the given roll number was deleted successfully.\n");
    }
}

void update_student()
{
    if(update_node() == student_not_found)
    {
        printf("There is no student with the given roll number.\n");
    }else{
        printf("The student with the given roll number was updated successfully.\n");
    }
}

void show_students()
{
    eFIFO_status_t status = print_FIFO(); 
    if(status == FIFO_empty ||status  == FIFO_NULL)
    {
        printf("\nThe list of students is empty!.\n");
    }
}

static void get_student_data(sStudentData_t* student)
{
    int i;

    fflush(stdin);
	fflush(stdout);
    printf("Enter first name: ");
    scanf("%s", student->fName);
        
    fflush(stdin);
	fflush(stdout);
    printf("Enter last name: ");
    scanf("%s", student->lName);
    
    fflush(stdin);
	fflush(stdout);
    printf("Enter roll number: ");
    scanf("%d", &student->roll);

    fflush(stdin);
	fflush(stdout);
    printf("Enter GPA: ");
    scanf("%f", &student->GPA);
        
    for(i = 0; i < 5; i++)
    {
        fflush(stdin);
	    fflush(stdout);
        printf("Enter course %d ID: ", i + 1);
        scanf("%d", &student->Cid[i]);
    }   
}