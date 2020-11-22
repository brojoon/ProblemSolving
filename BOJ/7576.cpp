#include <iostream>
#include <algorithm>
#include <queue>
int storage[1001][1001];
typedef struct point2d {
    int x, y;
} point2d;
int x, y, xdx, ydy;
int day = 0;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
std::queue<point2d> q;
int m, n;
void bfs(void) {
    while (!q.empty()) {
        x = q.front().x;
        y = q.front().y;
        q.pop();
        for (int i = 0; i < 4; i++) {
            xdx = x + dx[i];
            ydy = y + dy[i];
            if (xdx > 0 && ydy > 0 && xdx <= m && ydy <= n
                && storage[ydy][xdx] == 0) {
                storage[ydy][xdx] = storage[y][x] + 1;
                q.push({ xdx, ydy });
            }
        }
    }
}   

int main(void) {

    std::cin >> m >> n;
    std::fill(&storage[0][0], &storage[m][n + 1], -1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cin >> storage[i][j];
            if (storage[i][j] == 1) {
                q.push({ j, i });
            }
        }
    }
    bfs();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (storage[i][j] == 0) {
                std::cout << "-1";
                return 0;
            }
            if (storage[i][j] > day)
                day = storage[i][j];
        }
    }
    std::cout << --day;
    return 0;
}
