/* Program to compute F(x) */

#include <stdio.h>

int main() 
{
    int a, b, c, d, x, k, y;
    printf("For F(x)\n");
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    printf("c = ");
    scanf("%d", &c);
    printf("d = ");
    scanf("%d", &d);
    printf("x = ");
    scanf("%d", &x);
    printf("k = ");
    scanf("%d", &k);

    y = (a * (x*x*x)) - (b * (x*x)) + (c*x) - d;

    if(x > k) {
        y = y;
    }
    else if(x == k) {
        y = 0;
    }
    else {
        y = -y;
    }

    printf("f(x) = %d\n", y);

    return 0;
}