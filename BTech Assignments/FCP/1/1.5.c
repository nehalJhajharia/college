#include <stdio.h>

int main()
{
    //Program to square a number.

    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    long int sq_num = num * num;
    printf("Square of %d is %d * %d = %ld\n", num, num, num, sq_num);

    return 0;
}