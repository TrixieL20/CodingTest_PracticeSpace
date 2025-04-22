#include <bits/stdc++.h>
using namespace std;

int dp[104][10];
const int MOD = 1e9;

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j - 1 >= 0) {
				dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
			}
			if (j + 1 <= 9) {
				dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
			}
		}
	}

	int answer = 0;
	for (int i = 0; i <= 9; i++) {
		answer = (answer + dp[n][i]) % MOD;
	}

	cout << answer << "\n";
}
