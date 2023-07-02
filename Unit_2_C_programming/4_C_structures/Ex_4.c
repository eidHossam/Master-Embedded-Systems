#include <stdio.h>

typedef struct Sstudent
{
    char m_name[50];
    int m_rollno;
    float m_marks;
} Sstudent_t;

Sstudent_t get_student_data(int);
void print_student_data(Sstudent_t);

int main(void)
{
    int i;
    Sstudent_t students[10];

    printf("Enter information of students: \n");
    for (i = 0; i < 10; i++)
    {
        printf("\nFor roll number %d\n", i + 1);
        students[i] = get_student_data(i + 1);
    }

    printf("\nDisplaying information: \n");
    for (i = 0; i < 10; i++)
        print_student_data(students[i]);

    return 0;
}

Sstudent_t get_student_data(int roll)
{
    Sstudent_t student;
    printf("Enter name: ");
    scanf("%s", &student.m_name);

    student.m_rollno = roll;

    printf("Enter marks: ");
    scanf("%f", &student.m_marks);

    return student;
}

void print_student_data(Sstudent_t student)
{
    printf("\nInformation for roll number %d:", student.m_rollno);
    printf("\nname: %s\nMarks: %.2f\n", student.m_name, student.m_marks);
}