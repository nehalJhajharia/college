#include <stdio.h>

int main() 
{
    // Taking input as string
    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);

    // Converting into ASCII
    int i = 0;
    int sum = 0;
    while (name[i] != '\0') {
        sum += (int)name[i];
        printf("| %d ", name[i]);
        i++;
    }
    
    printf("\nASCII code of your name is %d. \n", sum);

    return 0;
}