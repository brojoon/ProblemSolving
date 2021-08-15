#include <iostream>

#define MAX 501

using namespace std;

int N, M, result, nx, ny;
int MAP[MAX][MAX];
int DP[MAX][MAX];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int DFS(int x, int y)
{
	if (x == N && y == M) return  1;
	if (DP[y][x] != -1) return DP[y][x];

	DP[y][x] = 0;
	for (int i = 0; i < 4; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx > 0 && nx <= N && ny > 0 && ny <= M)
		{
			if (MAP[ny][nx] < MAP[y][x])
				DP[y][x] = DP[y][x] + DFS(nx, ny);
		}
	}
	return DP[y][x];
}

int main()
{
	cin >> M >> N;

	for (int j = 1; j <= M; j++)
	{
		for (int i = 1; i <= N; i++)
		{
			cin >> MAP[j][i];
			DP[j][i] = -1;
		}
	}
	result =  DFS(1, 1);
	cout << result << endl;

	return 0;
}