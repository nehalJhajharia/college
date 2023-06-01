// program accept two matrices and check whether they are equal

#include <stdio.h>

int main()
{
    // two matrices of orders m*n
    int p, q, m, n;

    // orders of second matrix
    printf("For m*n: \n");
    printf("m = ");
    scanf("%d", &m);
    printf("n = ");
    scanf("%d", &n);

    int matrix1[m][n];
    int matrix2[m][n];

    // input for matrix1
    printf("For matrix1:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }

    // input for matrix2
    printf("For matrix2:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }

    // printing the matrices
    printf("The matrices are:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d ", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d ", matrix1[i][j]);
        }
        printf("\n");
    }

    int count = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix1[i][j] == matrix2[i][j])
            {
                count++;
            }
        }
    }

    if (count == m*n)
    {
        printf("The matrices are equal.\n");
    }
    else
    {
        printf("The matrices are NOT equal.\n");
    }

    return 0;
}