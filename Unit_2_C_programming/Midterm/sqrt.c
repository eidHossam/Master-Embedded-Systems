#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double findSqrt(double x)
{
    double y;
    double z;

    if (x < 2)
        return x;

    y = x;
    z = (y + (x / y)) / 2;

    while (fabs(y - z) >= 0.00001)
    {
        y = z;
        z = (y + (x / y)) / 2;
    }
    return z;
}

int main()
{
    double n, ans;
    printf("Enter a number: ");
    scanf("%lf", &n);
    ans = findSqrt(n);
    printf("%.3lf is the square root of %.0lf\n", ans, n);
    return 0;
}
