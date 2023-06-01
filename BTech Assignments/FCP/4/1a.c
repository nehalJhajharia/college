#include <stdio.h>

int main()
{
    int n, result = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    if (n > 0)
    {
        result = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
        {   
            result += (i*i);
        }
        else
        {
            result -= (i*i);
        }
    }

    printf("The series results: %d \n", result);

    return 0;
}