//Program to add two numbers.

#include <stdio.h>

int main()
{
    float a, b;
    printf("Enter a: ");
    scanf("%f", &a);
    printf("Enter b: ");
    scanf("%f", &b);
    float sum = a + b;
    printf("%.2f + %.2f = %.2f.\n", a, b, sum);

    return 0;
}