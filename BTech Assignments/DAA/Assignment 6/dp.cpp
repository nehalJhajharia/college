#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;

struct Job {
    int start;
    int end;
    int profit;
};

void FillProfit(Job list[], int N) {
    for (int i = 0; i < N; i++) {
        list[i].profit = (rand() % 1000);
    }
}

void FillTimeline(Job list[], int N) {
    for (int i = 0; i < N; i++) {
        int num1 = (rand() % 1000);
        int num2 = (rand() % 1000);
        if (num1 > num2) {
            list[i].end = num1;
            list[i].start = num2;
        }
        else {
            list[i].end = num2;
            list[i].start = num1;
        }
    }
}

void Output(Job list[], int N) {
    for (int i = 0; i < N; i++) {
        cout << list[i].start << "     |     ";
        cout << list[i].end << "     |     ";
        cout << list[i].profit << "\n"; 
    }
    cout << "\n";
}

bool comparison(Job job1, Job job2) {
    return (job1.end < job2.end);
}

int nonConflictJob(Job list[], int i) {
    for (int j=i-1; j>=0; j--) {
        if (list[j].end <= list[i-1].start)
            return j;
    }

    return -1;
}

void dpSchedule(Job list[], int N) {
    sort(list, list + N, comparison);

    int *table = new int[N];
    table[0] = list[0].profit;

    for (int i = 1; i < N; i++) {
        int addProfit = list[i].profit;
        int l = nonConflictJob(list, i);
        if (l != -1)
            addProfit += table[l];
        table[i] = (addProfit>table[i-1]) ? addProfit:table[i-1];
    }

    int result = table[N-1];
    delete[] table;

    cout << "Maximum Profit = " << result << "\n";
}

int main() 
{
    int N = 0;
    cout << "Enter the number of jobs : ";
    cin >> N;
    Job list[N];
    FillTimeline(list, N);
    FillProfit(list, N);

    int show_output = 0;
    cout << "Enter 1 to show list : ";
    cin >> show_output;
    if (show_output == 1)
        Output(list, N);

    dpSchedule(list, N);

    return 0;
}
//clang++ -std=c++17 dp.cpp