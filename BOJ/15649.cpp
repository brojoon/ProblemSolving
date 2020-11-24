#include <iostream>

using namespace std;

int n, m;
int buf[8];
bool visited[8];

void dfs(int depth) {
  if (depth ==  m) {
    for(int i = 0; i < m; i++) 
      cout << buf[i] << ' ';
    cout << '\n';
    return;
  }
  for(int i = 0; i < n; i++) {
    if (!visited[i]) {
      visited[i] = true;
      buf[depth] = i + 1;
      dfs(depth + 1);
      visited[i] = false;
    }
  }
}

int main() {
  cin >> n >> m;
  dfs(0);
  return 0;
}