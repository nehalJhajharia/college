#include <stdio.h>

int main()
{
    // Program to convert Fahrenheit into Celcius
    // (F-32) * (5/9) = C

    float F;
     printf("Enter temperature in Fahrenheit: ");
     scanf("%f", &F);

     float C = ((F-32) * 5) / 9;

     printf("%.1f temperature in Fahrenheit is %.1f Celcius\n", F, C);

    return 0;
}