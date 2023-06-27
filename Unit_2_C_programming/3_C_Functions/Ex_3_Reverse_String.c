#include <stdio.h>

void reverse_string(char c[]);

int main()
{
    char string[100];
    fgets(string, 100, stdin);
    reverse_string(string);
    return 0;
}

void reverse_string(char c[])
{
    if (*c == 0)
        return;

    reverse_string(c + 1);
    printf("%c", *c);
}