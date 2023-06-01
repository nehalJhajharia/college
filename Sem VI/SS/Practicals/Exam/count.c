// Write a lex program to identify and count the positive, negative and natural numbers.

#include <stdio.h>

int main() {
    int pos = 0;
    int neg = 0;
    int nat = 0;

    printf("Enter the numbers, 0 to exit :- \n");
    int t = 1;
    while (t != 0) {
        printf("Number : ");
        scanf("%d", &t);

        if (t < 0) {
            neg++;
        } else if (t > 0) {
            pos++;
            nat++;
        }
    }

    printf("Positive numbers: %d\n", pos);
    printf("Negative numbers: %d\n", neg);
    printf("Natural numbers: %d\n", nat);
}