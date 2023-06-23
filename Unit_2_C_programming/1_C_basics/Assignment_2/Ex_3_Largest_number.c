#include <stdio.h>

void main()
{
    float num1, num2, num3;

    printf("Enter three numbers: ");
    scanf("%f %f %f", &num1, &num2, &num3);

    if (num1 >= num2 && num1 >= num3)
        printf("Largest number = %g", num1);
    else if (num2 >= num1 && num2 >= num3)
        printf("Largest number = %g", num2);
    else
        printf("Largest number = %g", num3);
}