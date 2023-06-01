#include <stdio.h>

int main() 
{
    // Taking input as string
    char str[500];
    printf("Enter a string: ");
    gets(str);

    // Counting the elements in the string
    int n = 0;
    while (str[n] != '\0') {
        n++;
    }

    // Taking word as input
    char word[20];
    printf("Enter the word to be searched: ");
    scanf("%s", word);


    // Counting the elements in the word
    int m = 0;
    while (word[m] != '\0') {
        m++;
    }

    // Counting the number of times word appears in the string
    int i = 0;
    int mode;
    while (i < n) {
        int count = 0;
        for (int j = i; j < m+i; j++) {
            if (word[j-i] == str[j]) {
                count++;
            }
        }
        if (count == m) {
            mode++;
        }
        i++;
    }
    
    printf("%d\n", mode-1);

    return 0;
}