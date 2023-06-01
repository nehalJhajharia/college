#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

#include "Functions.cpp"

int main()
{
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    int N = 0;
    cin >> N;

    int arr[N];
    Input(arr, N);
    cout << endl;

    int reverseArr[N];

    /********** AVERAGE TIME **********/
    start = high_resolution_clock::now();
    MergeSort(arr, 0, N-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Average time for Merge Sort : ";
    cout << duration.count();
    cout << " microseconds" << endl;

    /********** BEST TIME **********/
    start = high_resolution_clock::now();
    MergeSort(arr, 0, N-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Best time for Merge Sort : ";
    cout << duration.count();
    cout << " microseconds" << endl;

    /********** WORST TIME **********/
    ReverseSort(arr, reverseArr, N);
    start = high_resolution_clock::now();
    MergeSort(arr, 0, N-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Worst time for Merge Sort : ";
    cout << duration.count();
    cout << " microseconds" << endl;

    cout << endl;

    return 0;
}

// clang++ -std=c++17 twoWayMergeSort.cpp