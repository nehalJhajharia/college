#include <stdio.h>

int main() 
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int myArray[n];

    // Taking input for the array
    for (int i = 0; i < n; i++) {
        printf("Enter %dth element of the array: ", i);
        scanf("%d", &myArray[i]);
    }

    int odd = 0, even = 0;
    // Counting the numbers odd and even entries.
    for (int i = 0; i < n; i++) {
        if (myArray[i] % 2 == 0) {
            even++;
        }
        else {
            odd++;
        }
    }

    printf("Number of odd entries: %d \n", odd);
    printf("Number of even entries: %d \n", even);

    return 0;
}