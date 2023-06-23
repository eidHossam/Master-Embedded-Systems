#include <stdio.h>

void main()
{
    float num;

    printf("Enter a numbers: ");
    scanf("%f", &num);

    if (num > 0)
        printf("%g is positive", num);
    else if (num < 0)
        printf("%g is negative", num);
    else
        printf("You entered zero");
}