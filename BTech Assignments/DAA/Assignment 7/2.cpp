// Edit distance problem

#include <iostream>
#include <string>

using namespace std;

#define N 1000

int dp[N][N] = {-1};

class S {
	public:
	string s1;
	string s2;

	void input() {
		cout << "S1 : ";
		cin >> s1;
		cout << "S2 : ";
		cin >> s2;
	}

	void copyStrings(string str1, string str2) {
		for (int i = 0; i < str1.length(); i++) {
			s1.push_back(str1[i]);
		}
		for (int i = 0; i < str2.length(); i++) {
			s2.push_back(str2[i]);
		}
	}

	int min(int num1, int num2, int num3) {
		if (num1 < num2) num2 = num1;
		if (num2 < num3) num3 = num2;
		return num3;
	}

	// RECURSION
	int recursion(int n, int m) {
		if (n == 0) return m;
		if (m == 0) return n;

		if (s1[n - 1] == s2[m - 1]) {
			return recursion(n - 1, m - 1);
		}

		return (1 + min(recursion(n, m - 1), recursion(n - 1, m), recursion(n - 1, m - 1)));
	}

	// DYNAMIC PROGRAMMING
	// BOTTOM UP
	int buD() {
		int dp[s1.length() + 1][s2.length() + 1];

		for (int i = 0; i <= s1.length(); i++) {
			for (int j = 0; j <= s2.length(); j++) {
				if (i == 0) dp[i][j] = j;
				else if (j == 0) dp[i][j] = i;
				else if (s1[i - 1] == s2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
			}
		}

		return dp[s1.length()][s2.length()];
	}

	// TOP DOWN
	int tdD(int n, int m) {
		if (n == 0) return m;
		if (m == 0) return n;
		if (dp[n][m] != -1) return dp[n][m];

		if (s1[n - 1] == s2[m - 1]) {
			if (dp[n - 1][m - 1] == -1) {
				return dp[n][m] = tdD(n - 1, m - 1);
			}
			else 
				return dp[n][m] = dp[n - 1][m - 1];
		}
		else {
			int m1 = 0;
			int m2 = 0;
			int m3 = 0;
			if (dp[n][m - 1] != -1) {
				m1 = dp[n - 1][m];
			}
			else {
				m1 = tdD(n -1, m);
			}

			if (dp[n][m - 1] != -1) {
				m2 = dp[n][m - 1];
			}
			else {
				m2 = tdD(n, m - 1);
			}

			if (dp[n - 1][m - 1] != -1) {
				m3 = dp[n - 1][m - 1];
			}
			else {
				m3 = tdD(n - 1, m - 1);
			}
			return dp[n][m] = 1 + min(m1, m2, m3);
		}
	}
};

int main() {
	S recu;
	recu.input();
	cout << "RECURSIVE\n";
	cout << recu.recursion(recu.s1.length(), recu.s2.length()) << "\n";

	S bu;
	bu.copyStrings(recu.s1, recu.s2);
	cout << "BOTTOM UP\n";
	cout << bu.buD() << "\n";

	S td;
	td.copyStrings(recu.s1, recu.s2);
	cout << "TOP DOWN\n";
	cout << td.tdD(td.s1.length(), td.s2.length()) << "\n";

	return 0;
}