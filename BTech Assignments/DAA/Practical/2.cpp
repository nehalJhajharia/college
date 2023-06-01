#include <iostream>
#include <string>

using namespace std;

string tem;
int point = 0;

int fact(int num) {
    if (num <= 0) return 1;
    int mul = num - 1;
    while (mul > 0) {
        num *= mul;
        mul--;
    }

    return num;
}

void anagram(string str);
void ana(string str) {
    int pointer = 0;
    for (int i = 0; i < str.length(); i++) {
        anagram(str);
        pointer++;
        int j = pointer;
        while (j > 0 && pointer < str.length()) {
            int temp = str[pointer];
            str[pointer] = str[pointer - 1];
            str[pointer - 1] = temp;
            j--;
        }
    }
}

void anagram(string str) {
    if (str.length() == 1) {
        tem[tem.length() - 1] = str[0];
        cout << tem << "\n";
        point = 0;
        return;
    }
    string str2;
    for (int i = 1; i < str.length(); i++) {
        str2.push_back(str[i]);
    }
    tem[point] = str[0];
    point++;
    ana(str2);
}

int main() {
    string word;
    cout << "Enter a string : ";
    cin >> word;
    tem = word;

    ana(word);
    
    return 0;
}
// clang++ 2.cpp