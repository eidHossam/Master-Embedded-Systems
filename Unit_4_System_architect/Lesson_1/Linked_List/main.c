/**
 * @file main.c
 * 
 * @brief this file tests the students database 
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 30-07-2023
 * 
 * @version 1.0
 */
#include "Linked_List.h"
#include <windows.h>

int main(int argc, char const *argv[])
{
    eStatus_t (* func_ptr[]) () = {add_student, delete_student, print_students_data
                                    , delete_all_students, get_Nth_node,
                                     Nth_last_node, list_length_iterative,
                                     middle_of_list, detect_loop, reverse_list};
    int choice;

	while (1)
	{
        system("cls");
		printf("\n======================");
		printf("\n\t Choose one of the following Options \n");
		printf("\n 1: Add Student");
		printf("\n 2: Delete Student");
		printf("\n 3: view Students");
		printf("\n 4: Delete All Students");
		printf("\n 5: Get a node at a certain index");
		printf("\n 6: Get a node at a certain index from the end");
		printf("\n 7: Get list length");
		printf("\n 8: Get the middle of the list");
		printf("\n 9: Detect a loop in the list");
		printf("\n 10: Reverse the list");
		printf("\n 0: Exit\n");

        fflush(stdin);
        scanf("%d", &choice);
        fflush(stdin);

        if(choice == 0)
        {
            printf("Thank you for using this service\n");
            return 0;
        }

        (*func_ptr[choice - 1])();
        system("pause");
    }
    return 0;
}
