#include <stdio.h>

int main() 
{
    // Taking input as string
    char str[500] = {'\0'};
    printf("Enter a string: ");
    gets(str);

    // Counting the elements in the string
    int n = 0;
    while (str[n] != '\0') {
        n++;
    }

    // Position where a word is to be inserted
    int position;
    printf("Enter the position at which the word is to be inserted: ");
    scanf("%d", &position);

    // Taking word to be inserted as input
    char word[20];
    printf("Enter the word to be inserted: ");
    scanf("%s", word);

    // Counting the elements in the word
    int m = 0;
    while (word[m] != '\0') {
        m++;
    }
    
    // Creating space for word
    for (int x = 0; x <= m; x++) {
        for (int k = n+x+1; k >= position + x; k--) {
            str[k+1] = str[k];
        }
    }
    for (int x = 0; x <= m; x++) {
        str[position + x] = ' ';
    }

    // Adding word
    for (int x = 0; x < m; x++) {
        str[position + x] = word[x];
    }

    printf("%s\n", str);

    return 0;
}