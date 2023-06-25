#include <stdio.h>
#include <string.h>

int main()
{
    char string[100], reverse[100];
    int i, j, size;

    printf("Enter a string: ");
    gets(string);

    size = strlen(string);
    for (i = 0, j = size - 1; i < size; i++, j--)
        reverse[i] = string[j];

    reverse[i] = 0;

    printf("Reverse string is : %s", reverse);
    return 0;
}