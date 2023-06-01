// Longest palindrome subsequence problem

#include <iostream>
#include <string>
using namespace std;

#define N 1000


int dp[N][N];

class PSP {
    public:
    string src;
    string reverseSrc;
    string pal;
    bool oddFlag; // 1 if odd
    int size;

    void input() {
        cout << "Enter the string : ";
        cin >> src;
    }

    void copyStr(string str) {
        for (int i = 0; i < str.length(); i++) {
            src.push_back(str[i]);
        }
    }

    void reverseStr() {
        for (int i = src.length() - 1; i >= 0 ; i--) {
            reverseSrc.push_back(src[i]);
        }
    }

    void setdp() {
        for (int i = 0; i <= src.length(); i++) {
            for (int j = 0; j <= src.length(); j++) {
                dp[i][j] = -1;
            }
        }
    }

    int findChar(char ch, int end) {
        for (int i = end-1; i >= 0; i--) {
            if (src[i] == ch) return i;
        }
        return -1;
    }

    void fillPal(string partialStr) {
        int i = 0;
        for (i = 0; i < partialStr.length(); i++) {
            pal.push_back(partialStr[i]);
        }
        if (oddFlag == 0) {
            pal.push_back(partialStr[partialStr.length() - 1]);
        }
        for (i = partialStr.length() - 2; i >= 0; i--) {
            pal.push_back(partialStr[i]);
        }

        if (pal.length() > size) {
            size = pal.length();
        }
        // cout << "\n" << pal << "\n";
    }

    // ITERATIVE
    void iterLP() {
        for (int i = 0; i < src.length(); i++) {
            oddFlag = 0;
            string temp;
            int end = src.length();
            for (int begin = i; begin < src.length(); begin++) {
                if (begin == end) {
                    break;
                }
                temp.push_back(src[begin]);
                end = findChar(src[begin], end);
                if (begin == end) {
                    oddFlag = 1;
                    break;
                }
            }
            // cout << "\n" << temp << " - " << oddFlag;
            fillPal(temp);
            pal.clear();
        }
    }

    int max(int num1, int num2) {
        if (num1 >= num2) return num1;
        return num2;
    }

    // RECURSIVE
    int recuLP(int begin, int end) {
        if (begin == end) return 1;

        if (src[begin] == src[end]) {
            if (begin + 1 == end) return 2;

            return (recuLP(begin + 1, end - 1) + 2);
        }

        return max(recuLP(begin, end - 1), recuLP(begin + 1, end));
    }

    // DYNAMIC PROGRAMMING
    // BOTTOM UP
    int bu() {
        int cl = 0;
        int L[src.length()][src.length()];

        for (int i = 0; i < src.length(); i++) {
            L[i][i] = 1;
        }

        int j = 0;
        for (cl = 2; cl <= src.length(); cl++) {
            for (int i = 0; i < src.length() - (cl - 1); i++) {
                j = i + cl - 1;
                if (src[i] == src[j]) {
                    if (cl == 2) 
                        L[i][j] = 2;
                    else
                        L[i][j] = L[i + 1][j - 1] + 2;
                }
                else {
                    L[i][j] = max(L[i][j - 1], L[i + 1][j]);
                }
            }
        }
        return L[0][src.length() - 1];
    }

    void printdp() {
        for (int i = 0; i <= src.length(); i++) {
            for (int j = 0; j <= src.length(); j++) {
                cout << dp[i][j] << "   ";
            }
            cout << "\n";
        }
        cout << "-------------------------\n";
    }

    // TOP DOWN
    int td(int n1, int n2) {
        // printdp();
        if (n1 == 0 || n2 == 0) {
            return 0;
        }

        if (dp[n1][n2] != -1) {
            return dp[n1][n2];
        }

        if (src[n1 - 1] == reverseSrc[n2 - 1]) {
            dp[n1][n2] = (1 + td(n1 - 1, n2 - 1));
            return dp[n1][n2];
        }
        
        dp[n1][n2] = max(td(n1 - 1, n2), td(n1, n2 - 1));
        return dp[n1][n2];
    }
};

int main() {
    PSP iterPal;
    iterPal.input();
    iterPal.size = 0;
    iterPal.iterLP();
    cout << "ITERATIVE\nLongest Palindrome Sequence size : " << iterPal.size << "\n";

    PSP recuPal;
    recuPal.copyStr(iterPal.src);
    recuPal.size = recuPal.recuLP(0, recuPal.src.length() - 1);
    cout << "\nRECURSIVE\nLongest Palindrome Sequence size : " << recuPal.size << "\n";

    PSP dpBU;
    dpBU.copyStr(iterPal.src);
    dpBU.size = dpBU.bu();
    cout << "\nDP BOTTOM-UP\nLongest Palindrome Sequence size : " << dpBU.size << "\n";

    PSP dpTD;
    dpTD.copyStr(iterPal.src);
    dpTD.reverseStr();
    dpTD.setdp();
    dpTD.size = dpTD.td(dpTD.src.length(), dpTD.src.length());
    cout << "\nDP TOP-DOWN\nLongest Palindrome Sequence size : " << dpTD.size << "\n";

    return 0;
}