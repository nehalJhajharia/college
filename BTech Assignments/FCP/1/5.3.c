#include <stdio.h>

int main()
{
    // Program to compute aaa + bbb + ccc - 3abc

    int a, b, c, result;
    printf("For \"aaa + bbb + ccc - 3abc\" \n");
    printf("Enter value of a: ");
    scanf("%d", &a);
    printf("Enter value of b: ");
    scanf("%d", &b);
    printf("Enter value of c: ");
    scanf("%d", &c);

    result = (a*a*a) + (b*b*b) + (c*c*c) - (3*a*b*c);

    printf("Computed result is %d\n", result);

    return 0;
}