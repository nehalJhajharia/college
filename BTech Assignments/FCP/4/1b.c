#include <stdio.h>

int main() {
    int n, result = 0;
    printf("Enter n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        result += (i*i);
    }

    printf("The series results: %d \n", result);

    return 0;
}