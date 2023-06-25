#include <stdio.h>

int main()
{
    float nums[100], sum = 0;
    int size, i;
    printf("Enter the numbers of data: ");
    scanf("%d", &size);

    for (i = 0; i < size && i < 100; i++)
    {
        printf("%d. Enter number: ", i + 1);
        scanf("%f", &nums[i]);
    }

    for (i = 0; i < size; i++)
        sum += nums[i];

    printf("Average = %.2f", sum / size);
    return 0;
}