#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char string[100];
    int i = 0, len = 0;

    printf("Enter a string: ");
    gets(string);

    while (string[i] != 0)
        len++, i++;

    printf("Length of string: %d", len);
    return 0;
}