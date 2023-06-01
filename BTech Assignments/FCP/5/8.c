#include <stdio.h>

int main() 
{
    int arr1[3][3];
    int arr2[3][3];
    int arrProduct[3][3] = {{0}};

    // Taking input for the FIRST matrix
    printf("For the first matrix: \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Enter a%d%d = ", i+1, j+1);
            scanf("%d", &arr1[i][j]);
        }
    }
    // Taking input for the SECOND matrix
    printf("For the second matrix:- \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Enter a%d%d = ", i+1, j+1);
            scanf("%d", &arr2[i][j]);
        }
    }

    // Printing the matrices
    printf("Your first matrix is:- \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %d ", arr1[i][j]);
        }
        printf("\n");
    }
    printf("Your second matrix is: \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %d ", arr2[i][j]);
        }
        printf("\n");
    }

    // Multiplying the matrices
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arrProduct[i][j] += arr1[i][0] * arr2[0][j];
            arrProduct[i][j] += arr1[i][1] * arr2[1][j];
            arrProduct[i][j] += arr1[i][2] * arr2[2][j];
        }
    }

    // Printing the product matrix
    printf("Your matrices, multiplied, results in the following matrix: \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %d ", arrProduct[i][j]);
        }
        printf("\n");
    }

    return 0;
}