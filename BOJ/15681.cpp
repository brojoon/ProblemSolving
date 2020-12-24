#include <iostream>
#include <vector>

using namespace std;

int n, r, q, tmp, u, v;
int dp[100001];
bool visited[100001];
vector<vector<int>> node;

int dfs(int cur)
{
  if (visited[cur])
    return dp[cur];

  visited[cur] = true;

  for (auto next : node[cur])
  {
    if (visited[next])
    {
      continue;
    }
    dp[cur] = dp[cur] + dfs(next);
  }
  return dp[cur];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> r >> q;

  node.resize(n + 1);

  for (int i = 0; i < n - 1; i++)
  {
    cin >> u >> v;
    node[u].push_back(v);
    node[v].push_back(u);
  }

  for (int i = 1; i <= n; i++)
  {
    dp[i] = 1;
  }

  dfs(r);

  for (int i = 0; i < q; i++)
  {
    cin >> tmp;
    cout << dp[tmp] << '\n';
  }

  return 0;
}