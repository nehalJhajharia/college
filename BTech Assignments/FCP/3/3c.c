/* Program to divide types of numbers */

#include <stdio.h>

int main() 
{
    float num1;
    int num2;

    printf("Enter a positive floating-point number: ");
    scanf("%f", &num1);
    printf("Enter a negative integer: ");
    scanf("%d", &num2);

    float result = num1 / num2;

    printf("num1 / num2 = %f \n", result);

    return 0;
}