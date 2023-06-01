//Program to read a floating-point number.
//Then display the right-most digit of the integral part.

#include <stdio.h>

int main()
{
    float input;
    printf("Enter a number: ");
    scanf("%f", &input);

    int num = input;
    int x = num / 10;
    num = num - (x*10);

    printf("%d\n", num);

    return 0;
}