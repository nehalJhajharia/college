#include <stdio.h>

int main()
{
    // Program to calculate simple interest
    // S.I. = P * R * T

    int P;
    float R;
    int T;

    printf("Enter the principal amount: ");
    scanf("%d", &P);
    printf("Enter the interest rate: ");
    scanf("%f", &R);
    printf("Enter the number of years: ");
    scanf("%d", &T);

    float SI = (P * R * T) / 100;

    printf("Simple Interest = %f\n", SI);

    return 0;
}