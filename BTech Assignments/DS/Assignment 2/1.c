// Program to display the following
// 1 2 3 4 5
// 1 2 3 4 
// 1 2 3 
// 1 2 
// 1

#include <stdio.h>

int main()
{
    int tempJ = 0;
    for (int i = 0; i < 5; i++) 
    {
        printf("     ");
        for (int j = 0; j < 5-i; j++) 
        {
            printf("%4d", j+1);
            tempJ = j;
        }
        printf("\n");
        printf("i = %d\n", i);
        printf("j = %d\n", tempJ);
    }

    return 0;
}