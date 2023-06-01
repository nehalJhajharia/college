#include <stdio.h>
#include "q1.h"
#include "q2.h"
#include "q3.h"
#include "q4.h"

int main()
{
    //Q1
    int n, b;
    printf("Enter a decimal number: ");
    scanf("%d", &n);
    b = decimal_to_unsigned_binary_U20CS093(n);
    printf("%d in binary: %d\n", n, b);

    // Q2
    int o = binary_to_octal(b);
    printf("%d in octal: %d\n", n, o);
    // Q3

    int b1, b2;
    printf("Enter the 2 binary numbers: ");
    scanf("%d %d", &b1, &b2);
    int res = subtraction_unsigned_binary_numbers_U20CS093(b1, b2);
    printf("Result unsigned: %d\n", res);
    
    // Q4
    printf("Enter the 2 binary numbers: ");
    scanf("%d %d", &b1, &b2);
    res = subtraction_signed_binary_numbers_U20CS093(b1, b2);
    printf("Result signed: %d\n", res);
}