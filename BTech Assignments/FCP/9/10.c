//Program to compute quotient and remainder.

#include <stdio.h>

int main()
{
    int num, div, Q, R;
    printf("Enter the number: ");
    scanf("%d", &num);
    printf("Enter the divisor: ");
    scanf("%d", &div);

    Q = num / div;
    R = num % div;

    printf("Quotient = %d\n", Q);
    printf("Remainder = %d\n", R);
    
    return 0;
}