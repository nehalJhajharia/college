#include <stdio.h>

int main() 
{
    int m, n, p;
    printf("Enter the size of first array: ");
    scanf("%d", &m);
    printf("Enter the size of second array: ");
    scanf("%d", &n);
    p = m + n;

    int arr1[m], arr2[n], myArray[p];

    // Taking input for the first array 
    for (int i = 0; i < m; i++) {
        printf("Enter %dth element of the array: ", i);
        scanf("%d", &arr1[i]);
    }
    // Taking input for the second array 
    for (int i = 0; i < n; i++) {
        printf("Enter %dth element of the array: ", i);
        scanf("%d", &arr2[i]);
    }

    // Combining the two arrays into myArray
    for (int i = 0; i < m; i++) {
        myArray[i] = arr1[i];
    }
    for (int i = 0; i < n; i++) {
        myArray[m+i] = arr2[i];
    }

    // Sorting myArray
    for (int i = 0; i < p-1; i++) {
        for (int j = 0; j < p-i; j++) {
            if (myArray[j] < myArray[j+1]) {
                int temp = myArray[j];
                myArray[j] = myArray[j+1];
                myArray[j+1] = temp;
            }
        }
    }

    // Printing the sorted array
    for (int i = 0; i < p; i++) {
        printf(" %d ", myArray[i]);
    }
    printf("\n"); // To give a line-break

    return 0;
}