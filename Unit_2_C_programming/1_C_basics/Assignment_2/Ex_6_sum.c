#include <stdio.h>

void main()
{
    int num, i, sum = 0;

    printf("Enter an integer: ");
    scanf("%d", &num);

    for (i = 1; i <= num; i++)
        sum += i;

    printf("Sum = %d", sum);
}