#include <iostream>
#include <vector>
#include <time.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class randomArray {
    public:
    int n;
    vector<int> array;

    void setSize() {
        cout << "Enter size of array : ";
        cin >> n;
    }

    void inputArray() {
        int temp = 0;
        for (int i = 0; i < n; i++) {
            cout << "array[" << i << "] : ";
            cin >> temp;
            array.push_back(temp);
        }
    }

    void fillArray() {
        srand(time(0));
        // for range [p, q]
        int p = -9;
        int q = 9;
        int temp = 0;
        for (int i = 0; i < n; i++) {
            // integers between -9 to 9
            temp = (rand() % (q-p+1)) + p;
            array.push_back(temp);
        }
    }

    void printArray() {
        int check = 0;
        cout << "Enter '1' to print the array : ";
        cin >> check;
        if (check != 1) return;

        for (int i = 0; i < n; i++) {
            cout << array[i] << "  ";
        }
        cout << endl;
    }

    int naiveMaxSumSubarray() {
        int max_sum = INT_MIN;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum = sum + array[j];
                if (sum > max_sum)
                    max_sum = sum;
            }
        }

        return max_sum;
    }

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    int max(int a, int b, int c) {
        return max(max(a, b), c);
    }

    int maxSumCrossing(int l, int m, int h) {
        int sum = 0;
        int left_sum = INT_MIN;
        for (int i = m; i >= l; i--) {
            sum = sum + array[i];
            if (sum > left_sum)
                left_sum = sum;
        }

        sum = 0;
        int right_sum = INT_MIN;
        for (int i = m+1; i <= h; i++) {
            sum = sum + array[i];
            if (sum > right_sum)
                right_sum = sum;
        }

        return max(left_sum + right_sum, left_sum, right_sum);
    }

    int maxSumSubarray(int l, int h) {
        if (l == h) 
            return array[l];

        int m = (l + h) / 2;

        return max(maxSumSubarray(l, m), 
                   maxSumSubarray(m+1, h),
                   maxSumCrossing(l, m, h));
    }
};

int main()
{
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    randomArray array;
    array.setSize();
    //array.inputArray();
    array.fillArray();
    array.printArray();
    int max_sum = 0;

    // Brute Force (Naive Approach)
    cout << "\nBrute Force (Naive Approach) -->\n\n";
    start = high_resolution_clock::now();
    max_sum = array.naiveMaxSumSubarray();
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);

    cout << "Largest sum of contiguous subarray = ";
    cout << max_sum << endl;

    cout << "Time taken : ";
    cout << duration.count();
    cout << " milliseconds" << endl;

    // Divide and Conquer Approach
    cout << "\nDivide and Conquer Approach -->\n\n";
    start = high_resolution_clock::now();
    max_sum = array.maxSumSubarray(0, (array.n)-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);

    cout << "Largest sum of contiguous subarray = ";
    cout << max_sum << endl;

    cout << "Time taken : ";
    cout << duration.count();
    cout << " milliseconds" << endl;
    return 0;
}
//clang++ -std=c++17 main.cpp