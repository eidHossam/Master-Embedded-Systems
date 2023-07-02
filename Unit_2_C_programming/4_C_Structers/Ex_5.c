#include <stdio.h>

#define pi 3.14
#define circle_area(r) pi *r *r

int main()
{
    float radius, area;
    printf("Enter the raduis: ");
    scanf("%f", &radius);

    printf("Area = %.2f", circle_area(radius));
}