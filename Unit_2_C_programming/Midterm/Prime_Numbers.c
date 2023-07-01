#include <stdio.h>

int get_prime_numbers(int beg, int end);

int main()
{
    int beg, end;
    printf("Enter two numbers (intervals): ");
    scanf("%d %d", &beg, &end);

    printf("Prime numbers between %d and %d are: ", beg, end);
    get_prime_numbers(beg, end);
    return 0;
}

int get_prime_numbers(int beg, int end)
{
    int i, prime;
    for (; beg <= end; beg++)
    {
        prime = 1;
        for (i = 2; i < beg; i++)
        {
            if (beg % i == 0)
            {
                prime = 0;
                break;
            }
        }
        if (prime)
            printf("%d ", beg);
    }
}