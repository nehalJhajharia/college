#include <stdio.h>

int main() 
{
    // Taking input as strings
    char first_name[50], last_name[50], name[100];
    printf("Enter your first name: ");
    scanf("%s", first_name);
    printf("Enter your last name: ");
    scanf("%s", last_name);

    // Adding first_name to name
    int i;
    for (i = 0; first_name[i] != '\0'; i++) {
        name[i] = first_name[i];
    }
    name[i] = ' ';
    i++;
    // Adding last_name to name
    int j;
    for (j = 0; last_name[j] != '\0'; j++) {
        name[i + j] = last_name[j];
    }
    name[i + j] = '\0';

    printf("Your full name is %s. \n", name);

    return 0;
}