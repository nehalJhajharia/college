//Program to compute largest number among 3.

#include <stdio.h>

int main()
{
    int a, b, c;
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    printf("c = ");
    scanf("%d", &c);

    if(a > b)
    {
        if(a > c)
        {
            printf("Largest number among %d, %d and %d is %d\n", a, b, c, a);
        }
        else
        {
            printf("Largest number among %d, %d and %d is %d\n", a, b, c, c);
        }
    }
    else if(b > c)
    {
        printf("Largest number among %d, %d and %d is %d\n", a, b, c, b);
    }
    else
    {
        printf("Largest number among %d, %d and %d is %d\n", a, b, c, c);
    }
    
    return 0;
}