#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a, b;
int big, small;
int number[100001], sum[100001];
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  fill(&number[1], &number[n], 0);
  for (int i = 1; i <= n; i++) {
    cin >> number[i];
    sum[i] = sum[i - 1] + number[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> a >> b;
    cout << sum[b] - sum[a - 1] << '\n';
  }
}