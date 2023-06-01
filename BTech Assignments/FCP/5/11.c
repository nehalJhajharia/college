#include <stdio.h>

int main() 
{
    int rows, cols;

    // Defining sizes of the arrays
    printf("For the size of the 2-D array:- \n");
    printf("rows = ");
    scanf("%d", &rows);
    printf("columns = ");
    scanf("%d", &cols);

    int arr1[rows][cols], arr2[rows][cols], arrSub[rows][cols];

    // Taking input in the FIRST array
    printf("For the first array:-\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("a%d%d = ", i+1, j+1);
            scanf("%d", &arr1[i][j]);
        }
    }

    // Taking input in the SECOND array
    printf("For the second array:-\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("a%d%d = ", i+1, j+1);
            scanf("%d", &arr2[i][j]);
        }
    }

    // Subtracting the arrays and filling arrSub[]
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arrSub[i][j] = arr1[i][j] - arr2[i][j];
        }
    }

    // Printing arrSub[]
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf(" %d ", arrSub[i][j]);
        }
        printf("\n");
    }

    return 0;
}