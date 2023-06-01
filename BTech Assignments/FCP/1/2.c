#include <stdio.h>

int main()
{
    //Program to compute area of a circle.

    float radius;
    printf("Enter radius of the circle: ");
    scanf("%f", &radius);

    float area = 3.14 * radius * radius;

    printf("Area of the cirle of radius %f is %f\n", radius, area);

    return 0;
}