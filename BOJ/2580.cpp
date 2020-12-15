#include <iostream>

using namespace std;

const int MAX = 9;

int map[MAX][MAX];
bool row[MAX][MAX];
bool col[MAX][MAX];
bool square[MAX][MAX];

void input () {
	for(int i = 0; i < MAX; i++) {
		for(int j = 0; j < MAX; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				row[i][map[i][j]] = true;
				col[j][map[i][j]] = true;
				square[j / 3 * 3 + i / 3][map[i][j]] = true;
			}
		}
	}
}

void print() {
	for(int i = 0; i < MAX; i++) {
		for(int j = 0; j < MAX; j++) {
			cout << map[i][j];
			if (j != 8) cout << ' ';
		}
		if (i != 8) cout << '\n';
	}
}

void dfs(int depth) {
	
	int x = depth % MAX;
	int y = depth / MAX;
	
	if (depth == 81) {
		print();
		exit(0);
	}
	
	if (map[y][x] == 0)	 {
		for (int i = 1; i <= 9; i++) {
			if (row[y][i] == false && col[x][i] == false && square[x / 3 * 3 + y / 3][i] == false) {
				map[y][x] = i;
				row[y][i] = true;	
				col[x][i] = true;
				square[x / 3 * 3 + y / 3][i] = true;
				dfs(depth + 1);
				map[y][x] = 0;
				row[y][i] = false;	
				col[x][i] = false;
				square[x / 3 * 3 + y / 3][i] = false;
			} 
		}
	} else dfs(depth + 1);
}

int main() {
	
	input();
	dfs(0);
	return 0;
}