#include <stdio.h>

int main()
{
    //Program to take input and show output.

    char name[20];
    printf("Enter your name: ");
    gets(name);
    printf("You entered your name as --> %s\n", name);

    return 0;
}