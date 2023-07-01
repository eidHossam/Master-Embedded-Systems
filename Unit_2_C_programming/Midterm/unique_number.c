#include <stdio.h>

int findUnique(int arr[], int size)
{
    int i, result = 0;

    for (i = 0; i < size; i++)
        result ^= arr[i];

    return result;
}

int main()
{
    int arr[] = {4, 2, 5, 2, 5, 7, 4};
    int arr2[] = {4, 2, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    int unique = findUnique(arr, size);
    printf("Test Case 1\n", unique);
    printf("The unique element is: %d\n", unique);

    size = sizeof(arr2) / sizeof(arr2[0]);

    unique = findUnique(arr2, size);
    printf("Test Case 2\n", unique);
    printf("The unique element is: %d\n", unique);

    return 0;
}
