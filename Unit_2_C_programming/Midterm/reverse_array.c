#include <stdio.h>

void reverse(int arr[], int size)
{
    int i, temp, j;
    for (i = 0, j = size - 1; i < j; i++, j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main()
{
    int arr[100], size, i;
    printf("Enter the size of array: ");
    scanf("%d", &size);

    printf("Enter the elements of array: \n");
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("The array you entered : \n");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);

    reverse(arr, size);

    printf("\nThe array after reverse : \n");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    return 0;
}