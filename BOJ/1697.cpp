#include <iostream>
#include <queue>

using namespace std;

int n, k, pos;
int visited[100001];
queue <int> q;

int bfs() {
	q.push(n); visited[n] = 1;
	while(!q.empty()) {
		
	    pos = q.front(); q.pop();
		
		if (pos == k) return visited[pos] - 1;
		
		if (pos + 1 < 100001 && visited[pos + 1] == 0) {
			q.push(pos + 1);
			visited[pos + 1] = visited[pos] + 1;
		}
		if (pos - 1 >= 0 && visited[pos - 1] == 0) {
			q.push(pos - 1);
			visited[pos - 1] = visited[pos] + 1;
		}
		if (pos * 2 < 100001 && visited[pos * 2] == 0) {
			q.push(pos * 2);
			visited[pos * 2] = visited[pos] + 1;
		}		
	}
}

int main() {
	cin >> n >> k;
	cout << bfs();
}