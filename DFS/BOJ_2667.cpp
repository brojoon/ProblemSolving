#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string map[25];
int visited[25][25];

int N;
int cnt;
vector<int> group;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xdx = x + dx[i];
        int ydy = y + dy[i];
        if (xdx < 0 || xdx >= N || ydy < 0 || ydy >= N) continue;

        if (visited[xdx][ydy] == 0 && map[xdx][ydy] == '1') {
            visited[xdx][ydy] = 1;
            cnt++;
            dfs(xdx, ydy);
        }
    }
}


int main() {
    int result = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> map[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == '1' && visited[i][j] == 0) {
                visited[i][j] = 1;
                cnt = 1;
                dfs(i, j);
                group.push_back(cnt);
                result++;
            }
        }
    }

    sort(group.begin(), group.end());
    cout << result << "\n";

    for (int i = 0; i < group.size(); i++) {
        cout << group[i] << "\n";
    }

    return 0;


}