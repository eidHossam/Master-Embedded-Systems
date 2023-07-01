#include <stdio.h>

int max_num_of_ones(int num)
{
    int count = 0, firstZero = 0, maxCount = -1, zero_one = -1;

    while (num > 0)
    {
        zero_one = num & 1;
        if (zero_one == 0 && !firstZero)
            firstZero = 1;
        else if (firstZero)
        {
            if (zero_one == 1)
                count++;
            else
            {
                if (count > maxCount)
                {
                    maxCount = count;
                    count = 0;
                }
            }
        }
        num >>= 1;
    }
    return (count > maxCount) ? count : maxCount;
}

int main()
{
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    printf("Max number of ones: %d\n", max_num_of_ones(num));

    return 0;
}
