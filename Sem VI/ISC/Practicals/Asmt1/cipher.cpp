#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int freq[26] = {0};

int setKey(int key) {
    return key % 26;
}

int getKey(char mode, char mode_gen) {
    int key = mode_gen - mode;
    if (key < 0) {
        key = 26 + key;
    }

    return 26 - key;
}

char encrypt(char ch, int key) {
    if (isupper(ch)) {
        return char (int (ch + key - 65) % 26 + 65);
    } else if (islower(ch)) {
        return char (int (ch + key - 97) % 26 + 97);
    }
        
    return ch;
}

string encrypt(string text, int key) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        result += encrypt(text[i], key);
    }

    return result;
}

string decrypt(string text, int key) {
    return encrypt(text, 26 - setKey(key));
}

void setFrequency(string text) {
    for (int i = 0; i < text.length(); i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            freq[text[i] - 97]++;
        }
    }
}

char getMode() {
    int mode = 0;
    for (int i = 1; i < 26; i++) {
        if (freq[i] > freq[i - 1]) {
            mode = i;
        }
    }
    freq[mode] = 0;

    return (char)(97 + mode);
}

void bruteForceAttack(string text) {
    for (int i = 1; i < 26; i++) {
        cout << "Key = " << i << " : \n" << encrypt(text, i) << endl;
    }
}

void frequencyAttack(string S) {
    setFrequency(S);
    string freq_table = "etaoinshrdlcumwfgypbvkjxqz";
    
    int key = 0;
    char mode = '\0';
    for (int i = 1; i < freq_table.length(); i++) {
        mode = getMode();
        key = getKey(mode, freq_table[i]);
        cout << mode << " -> " << freq_table[i] << " : \n" << decrypt(S, key) << endl;
    }
}

int main() {
    string text = "";
    int key = 4;

    fstream new_file;
    new_file.open("input.txt", ios::in);
    if (new_file.is_open()) {
        string tp;
        while(getline(new_file, tp)) {
            text += tp;
            text += "\n";
        }
        new_file.close();
    }

    string enc = encrypt(text, key);
    string dec = decrypt(enc, key);

    cout << text << endl;
    cout << "Key = " << key << endl << endl;
    
    cout << "Encrypting..." << endl << enc << endl;
    cout << "Decrypting..." << endl << dec << endl;

    cout << "\n********** Brute Force Method **********\n";
    bruteForceAttack(enc);

    cout << "\n********** Frequency Analysis Method **********\n";
    frequencyAttack(enc);
}