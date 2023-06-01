//Program to check a character for an alphabet.
//We use ASCII values to compare characters.
//Alphabets range between 65-90 and 97-122.

#include <stdio.h>

int main()
{
    char character;
    printf("Enter a character: ");
    scanf("%c", &character);

    int num = character;

    if((num>=65 && num<=90) || (num>=97 && num<=122))
    {
        printf("%c is an alphabet.\n", character);
    }
    else
    {
        printf("%c is NOT an alphabet.\n", character);
    }

    return 0;
}