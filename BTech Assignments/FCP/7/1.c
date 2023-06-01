// Calculate x^y using recursion

#include <stdio.h>
#include <math.h>

double power(double x, int y);  // Declaration of function power()

int main() 
{
    // Taking input from user
    double x, result;
    int y;
    printf("For x ^ y :- \n\n");
    printf("Enter x: ");
    scanf("%lf", &x);
    printf("Enter y: ");
    scanf("%d", &y);

    result = power(x, y);

    printf("%.2lf ^ %d = %.2lf \n", x, y, result);

    return 0;
}

// Calculation of the expression
double power(double x, int y) 
{
    if (y == 0) {
        return 1;
    }
    else if (y < 0) {
        return (1 / power(x, -y));
    }
    else {
        return (x * power(x, y-1));
    }
}