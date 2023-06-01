//Program to calculate area of a rectangle.

#include <stdio.h>

int main()
{
    float l, b, A;
    printf("Enter length: ");
    scanf("%f", &l);
    printf("Enter breadth: ");
    scanf("%f", &b);

    A = l * b;

    printf("Area = %.2f\n", A);
    
    return 0;
}