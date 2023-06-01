//Program to calculate perimeter of a rectangle.

#include <stdio.h>

int main()
{
    float l, b, P;
    printf("Enter length: ");
    scanf("%f", &l);
    printf("Enter breadth: ");
    scanf("%f", &b);

    P = 2 * (l + b);

    printf("Perimeter = %.2f\n", P);

    return 0;
}