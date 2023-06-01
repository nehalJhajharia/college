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

    // Finding the sum of the modulos
    int moduloSum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            moduloSum += arr[i] % arr[j];
        }
    }

    printf("%d \n", moduloSum); // Printing the sum

    return 0;
}