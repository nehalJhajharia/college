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

    // Arranging the elements of the array in DESCENDING order.
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i; j++) {
            if (myArray[j] < myArray[j+1]) {
                int temp = myArray[j];
                myArray[j] = myArray[j+1];
                myArray[j+1] = temp;
            }
        }
    }

    // Printing the arranged array
    for (int i = 0; i < n; i++) {
        printf(" %d ", myArray[i]);
    }
    printf("\n"); // To give a line-break

    return 0;
}