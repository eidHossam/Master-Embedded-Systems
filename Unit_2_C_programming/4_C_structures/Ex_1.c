#include <stdio.h>

typedef struct Sstudent
{
    char m_name[50];
    int m_rollno;
    float m_marks;
} Sstudent_t;

Sstudent_t get_student_data(void);

int main(void)
{
    Sstudent_t student;
    printf("Enter information of students: \n");
    student = get_student_data();

    printf("\nDisplaying information: \n");
    printf("name: %s\nroll: %d\nMarks: %.2f\n", student.m_name, student.m_rollno, student.m_marks);
    return 0;
}

Sstudent_t get_student_data(void)
{
    Sstudent_t student;
    printf("Enter name: ");
    scanf("%s", &student.m_name);

    printf("Enter roll number: ");
    scanf("%d", &student.m_rollno);

    printf("Enter makrs: ");
    scanf("%f", &student.m_marks);

    return student;
}
