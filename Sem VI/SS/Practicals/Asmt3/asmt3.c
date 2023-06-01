// Write a C program to recognizes strings under ‘a*’ & ‘a*b+’.
// Acceptable forms are a, aa, aaa, b, ab, abbb, aaaaabbb
// can start and end with either a or b
// continuous repetition of a and b

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>

bool accepted(char str[]) {
    int i = 0;
    int n = strlen(str);

    while (i < n && str[i] == 'a') {
        i++;
    }

    if (i < n && str[i] != 'b') {
        return false;
    }

    while (i < n && str[i] == 'b') {
        i++;
    }

    if (i == n) {
        return true;
    }

    return false;
}

int main() {
    bool flag = true;

    char str[20];
    
    printf("Enter a string : ");
    scanf("%s", str);

    if (accepted(str)) {
        printf("%s is ", str);
    } else {
        printf("%s is NOT ", str);
    }

    printf("acceptable under a*, a*b+\n");

    return 0;
}
