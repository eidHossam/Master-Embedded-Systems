#include <stdio.h>

void reverse_string(void);

int main()
{
    reverse_string();
    return 0;
}

void reverse_string(void)
{
    char c;
    scanf("%c", &c);
    if (c != '\n')
    {
        reverse_string();
        printf("%c", c);
    }
}