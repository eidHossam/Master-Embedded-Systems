#include <stdio.h>
#include <ctype.h>

void main()
{
    char vowels[] = {'a', 'e', 'i', 'o', 'u'}, c;

    printf("Enter an alphabet: ");
    scanf("%c", &c);

    int i;
    for (i = 0; i < 6; i++)
    {
        if (tolower(c) == vowels[i])
        {
            printf("%c is a vowel.", c);
            return;
        }
    }

    printf("%c is a consonant.", c);
}