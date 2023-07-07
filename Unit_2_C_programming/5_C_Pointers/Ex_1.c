#include <stdio.h>

int main(int argc, char const *argv[])
{
    int m = 29, *ab;
    printf("Address of m: %#X\n", &m);
    printf("Value of m: %d\n", m);

    ab = &m;
    printf("\nNow ab is assigned with the address of m.\n");
    printf("Address of ab: %#X\n", ab);
    printf("Value of ab: %d\n", *ab);

    *ab = 34;
    printf("\nThe value of m assigned to 34 now.\n");
    printf("Address of ab: %#X\n", ab);
    printf("Value of ab: %d\n", *ab);

    *ab = 7;
    printf("\nThe pointer variable ab is assigned with the value 7 now.\n");
    printf("Address of ab: %#X\n", ab);
    printf("Value of ab: %d\n", *ab);

    return 0;
}
