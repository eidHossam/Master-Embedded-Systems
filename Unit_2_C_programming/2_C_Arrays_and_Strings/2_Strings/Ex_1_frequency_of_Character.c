#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char string[100], find;
    int i, frequency = 0;

    printf("Enter a string: ");
    gets(string);

    printf("Enter a character to find frequency: ");
    scanf("%c", &find);

    for (i = 0; i < strlen(string); i++)
    {
        if (tolower(string[i]) == find)
            frequency++;
    }

    printf("Frequency of %c = %d", find, frequency);
    return 0;
}