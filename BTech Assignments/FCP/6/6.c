#include <stdio.h>

int main() 
{
    // Taking input as string
    char str[500] = {'\0'};
    printf("Enter a string: ");
    gets(str);

    // Counting the elements in the string
    int t = 0;
    while (str[t] != '\0') {
        t++;
    }

    // Taking word_before as input
    char word_before[20];
    printf("Enter the word to be removed: ");
    scanf("%s", word_before);

    // Taking word_after as input
    char word_after[20];
    printf("Enter the word to be placed: ");
    scanf("%s", word_after);

    // Counting the elements in the word_before
    int m = 0;
    while (word_before[m] != '\0') {
        m++;
    }
    // Counting the elements in the word_after
    int n = 0;
    while (word_after[n] != '\0') {
        n++;
    }

    // Spotting the word to be removed
    int i = 0;
    int p;
    while (str[i] != '\0') {
        int count = 0;
        for (int j = i; j < m+i; j++) {
            if (word_before[j-i] == str[j]) {
                count++;
            }
        }
        if (count == m) {
            p = i;
        }
        i++;
    }

    // Removing the word_before
    int j = p;
    while (str[j] != '\0') {
        str[j] = str[j+m+1];
        j++;
    }
    
    // Creating space for word_after
    j = p;
    for (int x = 0; x <= n; x++) {
        for (int k = t+x+1; k >= p+x; k--) {
            str[k+1] = str[k];
        }
    }
    for (int x = 0; x <= n; x++) {
        str[p+x] = ' ';
    }

    // Adding word_after
    for (int x = 0; x < n; x++) {
        str[p+x] = word_after[x];
    }

    printf("%s\n", str);

    return 0;
}