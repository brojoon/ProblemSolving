#include <iostream>
#include <string.h>

using namespace std;

int T, N, M;
int coin[21];
int dp[10001];

void Solution() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		dp[0] = 1;
		for (int j = 0; j < N; j++) {
			cin >> coin[j];
		}

		cin >> M;
		for (int k = 0; k < N; k++) {
			for (int z = coin[k]; z <= M; z++) {
				dp[z] += dp[z - coin[k]];
			}
		}
		cout << dp[M] << endl;
		memset(dp, 0, sizeof(dp));
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solution();
}