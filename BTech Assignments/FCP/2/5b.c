//Program to swap two numbers without using a temporary variable.

#include <stdio.h>

int main()
{
    int num;
    printf("Enter a 2-digit number: ");
    scanf("%d", &num);

    num = ((num - ((num/10) * 10)) * 10) + (num/10);

    printf("Swapped number is %d\n", num);

    return 0;
}