#include <stdio.h>

void main()
{
    float a, b;

    printf("Enter value of a: ");
    scanf("%f", &a);

    printf("Enter value of b: ");
    scanf("%f", &b);

    a += b;
    b = a - b;
    a -= b;

    printf("\nAfter swapping, value of a = %g", a);
    printf("\nAfter swapping, value of b = %g", b);
}