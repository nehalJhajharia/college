#include <stdio.h>

int main() 
{
    // Taking input as string
    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);

    // counting number of elements in the string
    int n = 0;
    while (name[n] != '\0') {
        n++;
    }

    // Sorting the array
    char temp1;
    char temp2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            temp1 = name[j];
            temp2 = name[j+1];
            if (temp1 > temp2) {
                name[j+1] = temp1;
                name[j] = temp2;
            }
        }
    }

    printf("%s\n", name);

    return 0;
}