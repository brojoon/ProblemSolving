#include <iostream>

using namespace std;

int n, best = -987654321;

int dp[100000];

int Max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> dp[i];
	}
	for(int i = 1; i < n; i++) {
		if(dp[i - 1] > 0 && dp[i] + dp[i - 1] > 0) {
			dp[i] += dp[i - 1];
		}
		best = Max(best, dp[i]);
	}
	best = Max(best, dp[0]);
	cout << best;
	
	return 0;
}