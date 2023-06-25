#include <stdio.h>

int main()
{
    float matrix1[2][2], matrix2[2][2];
    int row, col;

    /*Input of matrix 1*/
    printf("Enter the elements of 1st matrix\n");
    for (row = 0; row < 2; row++)
    {
        for (col = 0; col < 2; col++)
        {
            printf("Enter a%d%d: ", row + 1, col + 1);
            scanf("%f", &matrix1[row][col]);
        }
    }

    /*Input of matrix 2*/
    printf("\nEnter the elements of 2nd matrix\n");
    for (row = 0; row < 2; row++)
    {
        for (col = 0; col < 2; col++)
        {
            printf("Enter b%d%d: ", row + 1, col + 1);
            scanf("%f", &matrix2[row][col]);
        }
    }

    printf("\nSum of Matrix:\n");
    for (row = 0; row < 2; row++)
    {
        for (col = 0; col < 2; col++)
        {
            printf("%.1f\t", matrix1[row][col] + matrix2[row][col]);
        }
        printf("\n");
    }

    return 0;
}