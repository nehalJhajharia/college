#include <stdio.h>

int main()
{
    // Program to compute aa - 2ab + bb

    int a, b, result;
    printf("For \"aa - 2ab + bb\" \n");
    printf("Enter value of a: ");
    scanf("%d", &a);
    printf("Enter value of b: ");
    scanf("%d", &b);

    result = a - b;

    printf("Computed result is %d\n", (result * result));

    return 0;
}