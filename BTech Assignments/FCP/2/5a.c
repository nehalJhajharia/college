//Program to swap two numbers using a temporary variable.

#include <stdio.h>

int main()
{
    int num;
    printf("Enter a 2-digit number: ");
    scanf("%d", &num);

    int temp = num / 10;
    num = ((num - (temp*10))*10) + temp;

    printf("Swapped number is %d\n", num);

    return 0;
}