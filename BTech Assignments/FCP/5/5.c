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

    int del;
    loop: // Loop to ensure the validity of the index
    printf("(Remember: index >= 0 and < %d) \n", n);
    printf("Enter the index of the element of the array to be deleted: ");
    scanf("%d", &del);
    if (del < 0 || del >= n) {
        goto loop;
    }

    // Deleting (del)th element and shifting the later elements
    for (int i = del; i < n-1; i++) {
        myArray[i] = myArray[i+1];
    }

    myArray[n-1] = 0; // Giving null value to the last place

    // Printing the new array
    for (int i = 0; i < n-1; i++) {
        printf(" %d ", myArray[i]);
    }
    printf("\n"); // Taking a line-break

    return 0;
}