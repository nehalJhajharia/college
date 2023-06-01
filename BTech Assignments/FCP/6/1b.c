#include <stdio.h>

int main() 
{
    // Taking input as stings
    char str1[50];
    printf("Enter first string: ");
    scanf("%s", str1);
    char str2[50];
    printf("Enter second string: ");
    scanf("%s", str2);

    // Comparing strings
    int i = 0;
    while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0') {
        i++;
    }
    
    // Concluding result
    if (str1[i] == str2[i]) {
        printf("Strings are EQUAL. \n");
    }
    else {
        printf("Strings are NOT equal. \n");
    }

    return 0;
}