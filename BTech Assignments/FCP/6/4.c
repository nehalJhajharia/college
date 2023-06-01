#include <stdio.h>

int main() 
{
    // Taking input as strings
    char str1[50], str2[50], str3[100];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    // Adding first string to third string
    int i;
    for (i = 0; str1[i] != '\0'; i++) {
        str3[i] = str1[i];
    }
    str3[i] = ' ';
    i++;
    // Adding second string to third string
    int j;
    for (j = 0; str2[j] != '\0'; j++) {
        str3[i + j] = str2[j];
    }
    str3[i + j] = '\0';

    printf("%s \n", str3);

    return 0;
}