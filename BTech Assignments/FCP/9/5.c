//Program to compute x^y.

#include <stdio.h>
#include <math.h>

int main()
{
    float x, y, power;
    printf("In the expression \"x^y\"\n");
    printf("x = ");
    scanf("%f", &x);
    printf("y = ");
    scanf("%f", &y);

    power = pow(x, y);

    printf("%.2f^%.2f = %.2f\n", x, y, power);
    
    return 0;
}