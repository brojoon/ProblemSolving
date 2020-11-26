#include <iostream>

#define max(a, b) a > b ? a : b
using namespace std;

int stair[301];
long long dp[301];
int n;

int main() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> stair[i];
  }
  dp[1] = stair[1];
  dp[2] = stair[1] + stair[2];
  for(int i = 3; i <= n; i++) {
    dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i] + stair[i - 1]);
  }
  cout << dp[n];
}