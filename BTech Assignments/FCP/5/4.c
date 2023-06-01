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

    // Searching the index of minimum(m) and maximun(M) elements
    int min = myArray[0], max = myArray[0];
    int m = 0, M = 0;
    for (int i = 0; i < n; i++) {
        if (myArray[i] > max) {
            max = myArray[i];
            M = i;
        }
    }
    for (int i = 0; i < n; i++) {
        if (myArray[i] < min) {
            min = myArray[i];
            m = i;
        }
    }

    // Swapping the maximum and minimum elements
    myArray[m] = max;
    myArray[M] = min;

    // Printing the new array
    for (int i = 0; i < n; i++) {
        printf(" %d ", myArray[i]);
    }
    printf("\n"); // Taking a line-break

    return 0;
}