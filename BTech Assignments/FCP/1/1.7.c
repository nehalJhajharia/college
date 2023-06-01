#include <stdio.h>

int main()
{
    //Program to take input and show output.

    char col_name[50];
    printf("Enter your college name: ");
    gets(col_name);
    printf("You entered your college name as --> \n%s\n", col_name);

    return 0;
}