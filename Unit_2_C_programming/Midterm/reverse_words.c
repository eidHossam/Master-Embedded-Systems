#include <stdio.h>
#include <string.h>

void reverse_words(char string[], int size)
{
    int i;
    char reverse[100] = "", tmp[100];
    string[size - 1] = 0;
    for (i = 0; i < size && i < 100; i++)
    {
        tmp[i] = string[i];

        if (string[i] == ' ')
            break;
    }

    tmp[i] = 0;
    strcat(reverse, (string + i));
    strcat(reverse, " ");
    strcat(reverse, tmp);

    printf("Reversed string: %s", reverse);
}

int main()
{
    char string[100];
    printf("Enter a string: ");
    fgets(string, 100, stdin);
    reverse_words(string, strlen(string));
    return 0;
}
