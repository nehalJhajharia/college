//Program to calculate simple interest.

#include <stdio.h>

int main()
{
    float P, T, R, SI;
    printf("Principal amount = ");
    scanf("%f", &P);
    printf("Rate = ");
    scanf("%f", &R);
    printf("Time (in years) = ");
    scanf("%f", &T);

    SI = P * T * R /100;

    printf("Simple Interest = %.2f\n", SI);
    
    return 0;
}