#include <stdio.h>

int main()
{
    int matrix1[10][10], matrix2[10][10];
    int row, col, i, j;

    printf("Enter rows and column of matrix: ");
    scanf("%d %d", &row, &col);

    /*Input of matrix*/
    printf("Enter the elements of matrix\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("Enter elements a%d%d: ", i + 1, j + 1);
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Entered Matrix:\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d\t", matrix1[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < col; i++)
    {
        for (j = 0; j < row; j++)
        {
            matrix2[i][j] = matrix1[j][i];
        }
    }

    printf("Transpose of Matrix:\n");
    for (i = 0; i < col; i++)
    {
        for (j = 0; j < row; j++)
        {
            printf("%d\t", matrix2[i][j]);
        }
        printf("\n");
    }

    return 0;
}