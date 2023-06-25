#include <stdio.h>

int main()
{
    int matrix[100], size, i, element, index;

    printf("Enter no of elements : ");
    scanf("%d", &size);

    for (i = 0; i < size && i < 100; i++)
    {
        matrix[i] = i + 1;
        printf("%d ", matrix[i]);
    }

    printf("\nEnter the element to be inserted: ");
    scanf("%d", &element);

    printf("Enter the location: ");
    scanf("%d", &index);

    for (i = size - 1; i >= index - 1; i--)
        matrix[i + 1] = matrix[i];

    matrix[index - 1] = element;
    size++;

    for (i = 0; i < size && i < 100; i++)
        printf("%d ", matrix[i]);

    return 0;
}