// Write a yacc and lex program to recognise string of {a^nb^n | n >= 1}

#include <stdio.h>
#include <string.h>

int check(char input[], int n) {
    if (n % 2 == 1 || n == 0) {
        return 1;
    }
    int j = n / 2;

    for (int i = 0; i < n / 2; i++) {
        if (input[i] != 'a' || input[j + i] != 'b') {
            return 1;
        }
    }

    return 0;
}

int main() {
    int n = 0;
    printf("Enter size of string : ");
    scanf("%d", &n);

    char input[n];

    printf("Enter string : ");
    scanf("%s", input);

    if (check(input, n) == 1) {
        printf("NOT ACCEPTED!!!\n");
    } else {
        printf("ACCEPTED\n");
    }

    return 0;
}