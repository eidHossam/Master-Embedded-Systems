#include <stdio.h>

void main()
{
    int num, i, factorial = 1;

    printf("Enter an integer: ");
    scanf("%d", &num);

    if (num < 0)
    {
        printf("Error!!! Factorial of negative number doesn't exist");
        return;
    }

    for (i = 1; i <= num; i++)
        factorial *= i;

    printf("Factorial = %d", factorial);
}