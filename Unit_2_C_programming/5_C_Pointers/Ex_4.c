#include <stdio.h>

int main(int argc, char const *argv[])
{
    int arr[15], size, *ptr, i = 0;

    printf("Input the number of elements to store in the array (max 15): ");
    scanf("%d", &size);

    for (i = 0; i < size; i++)
    {
        printf("element - %d: ", i + 1);
        scanf("%d", arr + i);
    }

    ptr = arr + (size - 1);

    printf("\nThe elements of array in reverse order are: \n");
    while (i > 0)
        printf("element - %d: %d\n", i--, *ptr--);

    return 0;
}
