#include <stdio.h>

int ones_in_binary(int num)
{
    int count = 0;
    while (num > 0)
    {
        (num & 1) ? count++ : count;
        num >>= 1;
    }
}

int main()
{
    int num;
    printf("Enter a integer: ");
    scanf("%d", &num);
    printf("%d", ones_in_binary(num));
    return 0;
}