#include <stdio.h>

int main() 
{
    int n;

    // Defining sizes of the arrays
    printf("For n * n matrix:- \n");
    printf("n = ");
    scanf("%d", &n);

    int matrix[n][n];

    // Taking input in the matrix
    printf("For the matrix:-\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("a%d%d = ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    int sum = 0;
    // Adding main diagonal elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                sum += matrix[i][j];
            }
        }
    }

    // Printing the matrix
    printf("\n\nYour matrix is:- \n\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf(" %d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nSum of elements of main diagonal = %d \n", sum);

    return 0;
}