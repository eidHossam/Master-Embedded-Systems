#include <stdio.h>

void main()
{
    float num1, num2, result;
    char operator;

    printf("Enter operator either + or - or * or /: ");
    scanf("%c", &operator);
    printf("%c", operator);

    printf("Enter two operands: ");
    scanf("%f %f", &num1, &num2);

    switch (operator)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        result = num1 / num2;
        break;
    default:
        printf("Invalid operator!.");
        return;
    }

    printf("%g %c %g = %g", num1, num2, operator, result);
}