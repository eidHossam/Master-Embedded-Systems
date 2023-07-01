#include <stdio.h>

int sum_of_numbers(int num)
{
    if (num == 0)
        return 0;

    return num + sum_of_numbers(num - 1);
}

int main()
{
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    printf("Sum = %d", sum_of_numbers(num));
    return 0;
}
