//Program to check a number if it's positive, negative or zero.

#include <stdio.h>

int main()
{

    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if(num > 0)
    {
        printf("%d is a POSITIVE number.\n", num);
    }
    else if(num < 0)
    {
        printf("%d is a NEGATIVE number.\n", num);
    }
    else
    {
        printf("%d is ZERO.\n", num);
    }

    return 0;
}