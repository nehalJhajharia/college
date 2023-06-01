#include <stdio.h>

int main() 
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Taking input for the array
    for (int i = 0; i < n; i++) {
        printf("Enter %dth element of the array: ", i);
        scanf("%d", &arr[i]);
    }

    // Checking for palindromic order
    int count = 0;
    int m = n / 2; 
    for (int i = 0; i < m; i++) {
        if (arr[i] != arr[n-i-1]) {
            count += 1;
        }
    }

    if (count == 0) {
        printf("Palindromic order is followed.\n");
    }
    else {
        printf("Palindromic order is NOT followed.\n");
    }

    return 0;
}