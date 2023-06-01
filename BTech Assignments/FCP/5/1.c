#include <stdio.h>

int main()
{
    int n, m, p;

    // Defining sizes of the two arrays
    printf("Enter size of first array: ");
    scanf("%d", &n);
    printf("Enter size of second array: ");
    scanf("%d", &m);

    // Defining size of the third array
    if (m > n) {
        p = n;
    }
    else {
        p = m;
    }

    int arrayOne[n];
    int arrayTwo[m];
    int arraySum[p];

    // Taking input for FIRST array
    for (int i = 0; i < n; i++) {
        printf("Enter %dth element for I array: ", i);
        scanf("%d", &arrayOne[i]);
    }

    // Taking input for SECOND array
    for (int j = 0; j < m; j++) {
        printf("Enter %dth element for II array: ", j);
        scanf("%d", &arrayTwo[j]);
    }

    // Filling the THIRD array
    // Extra entries in the larger array will be discarded.
    int sum = 0;
    for (int k = 0; k < p; k++) {
        arraySum[k] = arrayOne[k] + arrayTwo[k];
        sum += arraySum[k];
    }

    printf("Average of the array = %d \n", (int)(sum/p));

    return 0;
}