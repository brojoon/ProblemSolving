#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int,int>>> Edge;
int Parent[100001];
int N, M, result;



void Input() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		Edge.push_back(make_pair(c, make_pair(a, b)));
	}

	for (int i = 1; i <= M; i++) {
		Parent[i] = i;
	}	
}

int Find(int x) {
	if (Parent[x] == x) return x;
	else return Parent[x] = Find(Parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x != y) Parent[y] = x;
}

bool SameParent(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y) return true;
	else return false;
}

void Solution() {
	sort(Edge.begin(), Edge.end());
	for (int i = 0; i < M; i++) {
		if (SameParent(Edge[i].second.first, Edge[i].second.second) == false) {
			Union(Edge[i].second.first, Edge[i].second.second);
			result = result + Edge[i].first;
		}
	}
	cout << result << endl;
}

void Solve() {
	Input();
	Solution();
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solve();

	return 0;
}