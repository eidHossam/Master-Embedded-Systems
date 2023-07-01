#include <stdio.h>

int reverse_digits(int num)
{
    int reverse = 0;
    while (num != 0)
    {
        reverse *= 10;
        reverse += num % 10;
        num /= 10;
    }
    return reverse;
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Reverse number = %d", reverse_digits(num));
    return 0;
}