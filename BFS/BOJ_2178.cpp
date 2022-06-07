#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N, M;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

string map[101];
int visited[101][101];
int check[101][101];

void bfs(int x, int y) {
    visited[x][y] = 1;

    queue<pair<int, int>> q;

    q.push(make_pair(x, y));

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int xdx = x + dx[i];
            int ydy = y + dy[i];

            if (0 <= xdx && xdx < N && 0 <= ydy && ydy < M) {
                if (map[xdx][ydy] == '1' && visited[xdx][ydy] == 0) {
                    check[xdx][ydy] = check[x][y] + 1;
                    visited[xdx][ydy] = 1;
                    q.push(make_pair(xdx, ydy));
                }
            }
        }
    }
}

int main() {

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> map[i]; 
    }

    bfs(0, 0);
    cout << check[N - 1][M - 1] + 1 << "\n";


    return 0;
}