/* Program to divide types of numbers */

#include <stdio.h>

int main() 
{
    int num1;
    float num2;

    printf("Enter a negative integer: ");
    scanf("%d", &num1);
    printf("Enter a positive floating-point number: ");
    scanf("%f", &num2);

    int result = num1 / num2;

    printf("num1 / num2 = %d \n", result);

    return 0;
}