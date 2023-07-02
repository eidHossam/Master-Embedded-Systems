#include <stdio.h>

union job
{
    char name[32];
    float salary;
    int worker_no;
} u;

struct job1
{
    char name[32];
    float salary;
    int worker_no;
} s;

int main()
{
    printf("Size of the union is: %d", sizeof(u));       /*Output: Size of the union is: 32*/
    printf("\nSize of the structure is: %d", sizeof(s)); /*Output: Size of the structure is: 40*/

    return 0;
}
