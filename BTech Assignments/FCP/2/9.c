//Program to check property of a triangle.

#include <stdio.h>

int main()
{
    int a, b, c;
    printf("Enter sides of the triangle corresponding to \"a\" , \"b\" , \"c\" :\n");
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    printf("c = ");
    scanf("%d", &c);

    if(a == b)
    {
        if(a == c)
        {
            printf("Equilateral triangle\n");
        }
        else
        {
            printf("Isosceles triangle\n");
        }
    }
    else if(a == c || b == c)
    {
        printf("Isosceles triangle\n");
    }
    else
    {
        printf("Scalene triangle\n");
    }

    return 0;
}