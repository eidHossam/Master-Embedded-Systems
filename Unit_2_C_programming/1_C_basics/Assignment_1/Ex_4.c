#include <stdio.h>

void main()
{
    float num1, num2, sum;

    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);

    sum = num1 * num2;
    printf("sum: %f", sum);
}