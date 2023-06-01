#include <iostream>
#include <chrono>
// #include <stdlib.h>
using namespace std;
using namespace std::chrono;

#include "Functions.hpp"

int main()
{
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds> (stop - start);

    int N = 0;

    cin >> N;

    int arrB[N];
    int arrS[N];

    Input(arrB, N);
    ReverseSort(arrB, N);
    CopyArray(arrS, arrB, N);
    cout << endl << endl << endl;

    /********** WORST TIME **********/

    // Linear Search
    int key = 0;
    cin >> key;
    start = high_resolution_clock::now();
    LinearSearch(arrB, N, key);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds> (stop - start);
    cout << "Worst time for Linear Search : ";
    cout << duration.count();
    cout << " microseconds" << endl;

    // Bubble Sort
    start = high_resolution_clock::now();
    BubbleSort(arrB, N);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds> (stop - start);
    cout << "Worst time for Bubble Sort : ";
    cout << duration.count();
    cout << " microseconds" << endl;

    // Selection Sort
    start = high_resolution_clock::now();
    SelectionSort(arrS, N);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds> (stop - start);
    cout << "Worst time for Selection Sort : ";
    cout << duration.count();
    cout << " microseconds" << endl;

    /********** BEST TIME **********/


    // Linear Search
    cin >> key;
    start = high_resolution_clock::now();
    LinearSearch(arrB, N, key);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds> (stop - start);
    cout << "Best time for Linear Search : ";
    cout << duration.count();
    cout << " microseconds" << endl;

    // Bubble Sort
    start = high_resolution_clock::now();
    BubbleSort(arrB, N);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds> (stop - start);
    cout << "Best time for Bubble Sort : ";
    cout << duration.count();
    cout << " microseconds" << endl;

    // Selection Sort
    start = high_resolution_clock::now();
    SelectionSort(arrS, N);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds> (stop - start);
    cout << "Best time for Selection Sort : ";
    cout << duration.count();
    cout << " microseconds" << endl;

    return 0;
}

// clang++ -std=c++17 main.cpp