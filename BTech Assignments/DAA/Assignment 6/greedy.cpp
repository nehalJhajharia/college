#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;

struct Job {
    int id;
    int profit;
    int ddl;
};

void FillId(Job list[], int N) {
    for (int i = 0; i < N; i++) {
        list[i].id = i+1;
    }
}

void FillDdl(Job list[], int N) {
    for (int i = 0; i < N; i++) {
        int temp = N / 2;
        list[i].ddl = (rand() % temp);
    }
}

void FillProfit(Job list[], int N) {
    for (int i = 0; i < N; i++) {
        list[i].profit = (rand() % 1000);
    }
}

void Output(Job list[], int N) {
    for (int i = 0; i < N; i++) {
        cout << list[i].id << "     |     ";
        cout << list[i].profit << "     |     ";
        cout << list[i].ddl << "\n"; 
    }
    cout << "\n";
}

bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

int min(int a, int b) {
    if (a > b) return b;
    return a;
}

void greedySchedule(Job list[], int N) {
    sort(list, list + N, comparison);

    int result[N];
    bool slot[N];

    for (int i = 0; i < N; i++)
        slot[i] = false;

    for (int i = 0; i < N; i++) {
        for (int j = min(N, list[i].ddl) - 1; j >= 0; j--) {
            if (slot[j] == false) {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    //cout << "Jobs are scheduled as : \n"; 
    int max_profit = 0;
    for (int i = 0; i < N; i++) {
        if (slot[i]) {
            //cout << list[result[i]].id << "     |     ";
            //cout << list[result[i]].ddl << "     |     ";
            //cout << list[result[i]].profit << "\n";
            max_profit += list[result[i]].profit;
        }
    }
    cout << "\nMaximum Profit = " << max_profit << "\n";
}

int main() 
{
    int N = 0;
    cout << "Enter the number of jobs : ";
    cin >> N;
    Job list[N];
    FillId(list, N);
    FillProfit(list, N);
    FillDdl(list, N);

    int show_output = 0;
    cout << "Enter 1 to show list : ";
    cin >> show_output;
    if (show_output == 1)
        Output(list, N);
    
    greedySchedule(list, N);

    return 0;
}

//clang++ -std=c++17 greedy.cpp