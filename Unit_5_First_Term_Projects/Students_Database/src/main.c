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
		DPRINTF("\n=============================================");
		DPRINTF("\nChoose one of the following Options \n");
		DPRINTF("\n 1: Add Students data from a file");
		DPRINTF("\n 2: Add Students data manually");
		DPRINTF("\n 3: Find a student by his roll number");
		DPRINTF("\n 4: Find a student by his first name");
		DPRINTF("\n 5: Find all the students in a specific course");
		DPRINTF("\n 6: Get the total number of students");
		DPRINTF("\n 7: Delete a student by his roll number");
		DPRINTF("\n 8: Update a student's data");
		DPRINTF("\n 9: Show all the students data");
		DPRINTF("\n 0: Exit\n");
		

		scanf("%d", &choice);

		if(choice == 0)
		{
			 DPRINTF("Thank you for using this service\n");
            return 0;
        }
		
        (*func_ptr[choice - 1])();
        system("pause");
	}
	
    return 0;
}