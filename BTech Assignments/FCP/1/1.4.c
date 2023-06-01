#include <stdio.h>

int main()
{
    //Program to take input and show output.

    double num;
    printf("Enter a number: ");
    scanf("%lf", &num);
    printf("You entered --> %.2lf\n", num);

    return 0;
}