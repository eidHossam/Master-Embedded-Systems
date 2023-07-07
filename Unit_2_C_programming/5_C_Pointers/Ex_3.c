#include <stdio.h>

int main()
{
    char string[100], *ptr = string;
    int i = 1;

    printf("Input a string: ");
    fgets(string, 100, stdin);

    while (*++ptr)
        i++;

    printf("Reverse of the string is: ");
    ptr--;

    while (i--)
        printf("%c", *--ptr);

    return 0;
}