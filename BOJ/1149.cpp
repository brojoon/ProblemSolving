#include <iostream>
#define min(a, b) (a < b ? a : b)

using namespace std;

int n, costs[1001][3], dp[1001][3];

int main() {

	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> costs[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];
	}	

	cout << min(min(dp[n][0], dp[n][1]), dp[n][2]);
}