//Program to find area of a triangle.
#include <stdio.h>

int main()
{
    float b, h, area;
    printf("For a triangle\n");
    printf("Base = ");
    scanf("%f", &b);
    printf("Height = ");
    scanf("%f", &h);

    area = b * h / 2;

    printf("Area of the triangle = %.2f\n", area);
    
    return 0;
}