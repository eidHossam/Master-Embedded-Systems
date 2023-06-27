#include <stdio.h>

int calculate_power(int base, int power);

int main()
{
    int base, power;
    printf("Enter base number: ");
    scanf("%d", &base);

    printf("Enter power number(positive number): ");
    scanf("%d", &power);

    if (power >= 0)
        printf("%d^%d = %d", base, power, calculate_power(base, power));

    return 0;
}

int calculate_power(int base, int power)
{
    if (power == 0)
        return 1;

    return base * calculate_power(base, --power);
}