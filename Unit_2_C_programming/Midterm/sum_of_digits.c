#include <stdio.h>

int sum_of_digits(int num)
{
    int sum = 0;
    int rem, temp_num = num;
    while (temp_num != 0)
    {
        rem = temp_num % 10;
        sum += rem;
        temp_num /= 10;
    }
    return sum;
}

int main()
{
    int num;
    printf("test case 1: \n");
    scanf("%d", &num);
    printf("%d", sum_of_digits(num));

    printf("\ntest case 2: \n");
    fflush(stdin);
    scanf("%d", &num);
    printf("%d", sum_of_digits(num));
    return 0;
}
