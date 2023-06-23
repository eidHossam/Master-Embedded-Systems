#include <stdio.h>

void main()
{
    float num1, num2;
    char operator;

    printf("Enter operator either + or - or * or /: ");
    scanf("%c", &operator);

    printf("Enter two operands: ");
    scanf("%f %f", &num1, &num2);

    switch (operator)
    {
    case '+':
        printf("%g + %g = %g", num1, num2, num1 + num2);
        break;
    case '-':
        printf("%g - %g = %g", num1, num2, num1 - num2);
        break;
    case '*':
        printf("%g * %g = %g", num1, num2, num1 * num2);
        break;
    case '/':
        printf("%g / %g = %g", num1, num2, num1 / num2);
        break;
    default:
        printf("Invalid operator!.");
        return;
    }
}