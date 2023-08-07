/**
 * @file main.c
 * 
 * @brief this file implements 
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 05-08-2023
 * 
 * @version 1.0
 */

#include "../inc/FIFO_Buff.h"
#include "../inc/Student_DB.h"
#include <windows.h>

int main()
{
    void (* func_ptr[])() = {add_student_file, add_student_manually, find_roll, find_fName,
                         find_students_inCourse, total_students, delete_student,
                          update_student, show_students};
    int choice;
    FIFO_init();
	
	while (1)
	{
		system("cls");
		printf("\n=============================================");
		printf("\nChoose one of the following Options \n");
		printf("\n 1: Add Students data from a file");
		printf("\n 2: Add Students data manually");
		printf("\n 3: Find a student by his roll number");
		printf("\n 4: Find a student by his first name");
		printf("\n 5: Find all the students in a specific course");
		printf("\n 6: Get the total number of students");
		printf("\n 7: Delete a student by his roll number");
		printf("\n 8: Update a student's data");
		printf("\n 9: Show all the students data");
		printf("\n 0: Exit\n");
		

		fflush(stdin);
		fflush(stdout);
		scanf("%d", &choice);

		if(choice == 0)
		{
			 printf("Thank you for using this service\n");
            return 0;
        }
		
		fflush(stdin);
		fflush(stdout);
        (*func_ptr[choice - 1])();
		fflush(stdin);
		fflush(stdout);
        system("pause");
	}
	
    return 0;
}