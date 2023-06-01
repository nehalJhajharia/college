//Program to calculate diameter, circumference and area of a circle.

#include <stdio.h>

int main()
{
    float r, D, C, A;
    printf("Enter radius: ");
    scanf("%f", &r);

    D = 2 * r;
    C = 3.14 * D;
    A = 3.14 * r * r;

    printf("Diameter = %.2f\n", D);
    printf("Circumference = %.2f\n", C);
    printf("Area = %.2f\n", A);
    
    return 0;
}