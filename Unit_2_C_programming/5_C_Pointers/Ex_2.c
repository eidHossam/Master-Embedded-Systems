#include <stdio.h>

int main()
{
    char alphabet[26];
    char *ptr = alphabet;
    int i;

    for (i = 0; i < 26; i++)
        *(ptr + i) = (char)('A' + i);

    for (i = 0; i < 26; i++)
        printf("%c ", *(ptr + i));

    return 0;
}