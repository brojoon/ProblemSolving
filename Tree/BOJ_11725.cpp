#include <iostream>
#include <vector>
#include <queue>


bool visited[100001];
int parent[100001];
std::vector<int> tree[100001];
std::queue<int> q;

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int n, u ,v, cur;

	std::cin >> n;
	
	for (int i = 1;i < n; i++)
	{
		std::cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	q.push(1);
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		for (int i = 0;i < tree[cur].size(); i++)
		{
			if (!visited[tree[cur][i]])
			{
				visited[tree[cur][i]] = true;
				parent[tree[cur][i]] = cur;
				q.push(tree[cur][i]);
			}
		}
	}

	for (int i = 2;i <= n; i++)
		std::cout << parent[i] << "\n";
	return 0;
}