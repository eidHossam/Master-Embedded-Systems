#include <stdio.h>

int main()
{
    int matrix[100], size, i, element, index = -1;

    printf("Enter no of elements : ");
    scanf("%d", &size);

    for (i = 0; i < size && i < 100; i++)
    {
        matrix[i] = (i + 1) * 11;
        printf("%d ", matrix[i]);
    }

    printf("\nEnter the element to be searched: ");
    scanf("%d", &element);

    for (i = 0; i < size; i++)
    {
        if (matrix[i] == element)
        {
            index = i + 1;
            break;
        }
    }

    (index != -1) ? printf("Number found at the location = %d", index) : printf("Number isn't in the list1.");
    return 0;
}