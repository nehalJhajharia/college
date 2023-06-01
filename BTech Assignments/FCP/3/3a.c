/* Program to divide types of numbers */

#include <stdio.h>

int main() 
{
    float num1, num2;

    printf("Enter num1: ");
    scanf("%f", &num1);
    printf("Enter num2: ");
    scanf("%f", &num2);

    //int result = num1 / num2;

    printf("num1 / num2 = %d \n", (int)(num1 / num2));

    return 0;
}