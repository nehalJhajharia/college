#include <stdio.h>

int main() 
{
    // Taking input as a string
    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);

    // Counting the elements in the string
    int n = 0;
    while (name[n] != '\0') {
        n++;
    }

    // Reversing the string
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            char temp = name[j+1];
            name[j+1] = name[j];
            name[j] = temp;
        }
    }

    printf("Reverse of your name is %s.\n", name);

    return 0;
}