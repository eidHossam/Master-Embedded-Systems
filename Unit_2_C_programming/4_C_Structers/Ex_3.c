#include <stdio.h>

struct Scomplex_number
{
    float m_real;
    float m_img;
};

struct Scomplex_number add_complex(struct Scomplex_number, struct Scomplex_number);

int main(int argc, char const *argv[])
{
    struct Scomplex_number number1, number2, sum;

    printf("For 1st complex number:\n");
    printf("Enter real and imaginary respectively: ");
    scanf("%f %f", &number1.m_real, &number1.m_img);

    printf("For 2st complex number:\n");
    printf("Enter real and imaginary respectively: ");
    scanf("%f %f", &number2.m_real, &number2.m_img);

    sum = add_complex(number1, number2);

    printf("Sum = %.1f + %.1fi", sum.m_real, sum.m_img);
    return 0;
}

struct Scomplex_number add_complex(struct Scomplex_number num1, struct Scomplex_number num2)
{
    struct Scomplex_number sum;

    sum.m_real = num1.m_real + num2.m_real;
    sum.m_img = num1.m_img + num2.m_img;

    return sum;
}