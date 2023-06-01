void Input(int matrix[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << "a" << i << j << " : ";
            cin >> matrix[i][j];
        }
    }
}

void PrintMatrix(int matrix[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << matrix[i][j] << "    ";
        }
        cout << endl;
    }
    cout << endl;
}

void NaiveMultiply(int M1[N][N], int M2[N][N], int MProduct[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            MProduct[i][j] = 0;
            for (int k = 0; k < N; k++)
            {
                MProduct[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }
}

void DnCMultiply(int M1[N][N], int M2[N][N], int MProduct[N][N])
{
    int S1 = (M1[0][0] + M1[1][1]) * (M2[0][0] + M2[1][1]);
    int S2 = (M1[0][0] + M1[1][1]) * M2[0][0];
    int S3 = M1[0][0] * (M2[0][1] - M2[1][1]);
    int S4 = M1[1][1] * (M2[1][0] - M2[0][0]);
    int S5 = (M1[0][0] + M1[0][1]) * M2[1][1];
    int S6 = (M1[1][0] - M1[0][0]) * (M2[0][0] + M2[0][1]);
    int S7 = (M1[0][1] - M1[1][1]) * (M2[1][0] + M2[1][1]);

    MProduct[0][0] = S1 + S4 - S5 + S7;
    MProduct[0][1] = S3 + S5;
    MProduct[1][0] = S2 + S4;
    MProduct[1][1] = S1 + S3 - S2 + S6;
}
