#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> a, b;
vector<long long> seg_tree;

void update(int start, int end, int node, int idx, int diff)
{
	if (idx < start || idx > end)
		return;
	seg_tree[node] += diff;
	if (start == end)
		return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, diff);
	update(mid + 1, end, node * 2 + 1, idx, diff);
}

long long sum(int start, int end, int node, int left, int right)
{
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return seg_tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1 , end, node * 2 + 1, left, right);
}

int main()
{
	cin >> N;

	a.reserve(1000001);
	b.reserve(N + 1);
	seg_tree.reserve((N + 1) * 4);

	int tmp;
	for (int i = 1; i <= N; i++)
	{
		cin >> tmp;
		a[tmp] = i;
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> tmp;
		b[i] = a[tmp];
	}

	long long count = 0;

	for (int i = 1; i <= N; i++)
	{
		count += sum(1, N, 1, b[i] + 1, N);
		update(1, N, 1, b[i], 1);
	}
	cout << count << endl;
}