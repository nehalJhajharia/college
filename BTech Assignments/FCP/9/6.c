//Program to calculate third angle of a triangle.

#include <stdio.h>

int main()
{
    float A, B, C;
    printf("For a triangle\n");
    printf("First angle (in degrees) = ");
    scanf("%f", &A);
    printf("Second angle (in degrees) = ");
    scanf("%f", &B);

    C = 180 - A - B;

    printf("Third angle (in degrees) = %.2f\n", C);
    
    return 0;
}