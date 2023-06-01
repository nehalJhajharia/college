#include <iostream>
#define N 2

using namespace std;

#include "MatrixFunctions.hpp"

int main()
{
    int matrix1[N][N] = {0};
    int matrix2[N][N] = {0};
    int matrixProduct[N][N] = {0};

    cout << "For matrix1 : " << endl;
    Input(matrix1);
    cout << "For matrix1 : " << endl;
    Input(matrix2);
    cout << endl;

    PrintMatrix(matrix1);
    PrintMatrix(matrix2);

    NaiveMultiply(matrix1, matrix2, matrixProduct);
    cout << "Matrix Multiplication with Naive Approach : " << endl;
    PrintMatrix(matrixProduct);

    DnCMultiply(matrix1, matrix2, matrixProduct);
    cout << "Matrix Multiplication with Divide and Conquer Approach : " << endl;
    PrintMatrix(matrixProduct);

    return 0;
}