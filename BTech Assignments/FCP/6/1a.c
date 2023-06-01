#include <stdio.h>

int main() 
{
    // Taking input as string
    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);

    // Copying the string into another string
    char name_copy[50];
    int i;
    for (i = 0; name[i] != '\0'; i++) {
        name_copy[i] = name[i];
    }
    name_copy[i] = '\0';

    printf("Your name is %s. \n", name_copy);

    return 0;
}