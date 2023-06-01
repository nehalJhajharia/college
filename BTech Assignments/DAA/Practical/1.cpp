#include <iostream>

using namespace std;

void ans(int res)
{
    cout << res << "\n";
}

void print(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        cout << arr[i] << "   ";
    }
    cout << "\n";
}

int main()
{
    int n = 0;
    cout << "Enter size of array : ";
    cin >> n;
    int k = 0;
    cout << "k = ";
    cin >> k;
    int array[n];

    for (int i = 0; i < n; i++)
        cin >> array[i];

    int x = 0;
    int y = 0;
    int z = 0;

    if (n < 3)
    {
        ans(n);
        return 0;
    }

    int flag = 1;
    int N = n;

    while (flag == 1)
    {
        flag = 0;
        for (int i = 0; i < N - 2; i++)
        {
            if (N < 3) {
                ans(N);
                return 0;
            }
            if (flag == 1) break;

            x = array[i];
            y = array[i + 1];
            z = array[i + 2];
            int xy = y - x;
            int yz = z - y;

            if (xy == k)
            {
                if (yz == k)
                {
                    flag = 1;
                    int arr2[N - 3];
                    int k = 0;
                    for (int j = 0; j < N; j++)
                    {
                        if (j == i)
                        {
                            k += k + 3;
                        }
                        arr2[j] = array[k];
                        k++;
                    }

                    for (int j = 0; j < N - 3; j++)
                    {
                        array[j] = arr2[j];
                    }
                    //print(array, N);
                    N -= 3;
                }
            }
        }
    }

    ans(N);

    return 0;
}
// clang++ 1.cpp
