#include <iostream>
#include <string.h>

using namespace std;

bool visited[101][101];
int map[101][101];
int minHeight;
int maxHeight;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0 , 0};
int N;
int result = 1;

void dfs(int h, int y, int x) {
	int nx;
	int ny;
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 1 || ny > N || nx < 1 || nx > N)
			continue;
		if (map[ny][nx] <= h || visited[ny][nx])
			continue;
		visited[ny][nx] = true;
		dfs(h, ny, nx);
	}
}


int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			minHeight = min(map[i][j], minHeight);
			maxHeight = max(map[i][j], maxHeight);
		}
	}

	for (int h = minHeight; h < maxHeight; h++) {
		memset(visited, 0, sizeof(visited));

		int cnt = 0;
		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {
				if (!visited[y][x] && map[y][x] > h) {
					cnt++;
					dfs(h, y, x);
				}
			}
		}
		result = max(cnt, result);
	}

	cout << result << endl;


	return 0;
}