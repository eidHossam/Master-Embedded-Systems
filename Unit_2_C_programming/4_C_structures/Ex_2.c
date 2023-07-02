#include <stdio.h>

struct Sdistance
{
    float m_feet;
    float m_inches;
};

int main(void)
{
    struct Sdistance distance1, distance2, sum;

    printf("Enter information for 1st distance: \n");
    printf("Enter feet: ");
    scanf("%f", &distance1.m_feet);
    printf("Enter inches: ");
    scanf("%f", &distance1.m_inches);

    printf("Enter information for 2nd distance: \n");
    printf("Enter feet: ");
    scanf("%f", &distance2.m_feet);
    printf("Enter inches: ");
    scanf("%f", &distance2.m_inches);

    sum.m_feet = distance1.m_feet + distance2.m_feet;
    sum.m_inches = distance1.m_inches + distance2.m_inches;

    if (sum.m_inches > 12)
    {
        sum.m_feet++;
        sum.m_inches -= 12;
    }

    printf("Sum of distances= %.0f' -%.1f\"", sum.m_feet, sum.m_inches);
    return 0;
}