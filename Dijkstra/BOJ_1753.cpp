#include <iostream>
#include <queue>
#include <vector>

#define MAX 999999

using namespace std;

vector<pair<int,int>> vertext[20001];
int dist[20001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E, s, u, v, w;
	cin >> V >> E >> s;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		vertext[u].push_back(make_pair(v, w));
	}

	for (int i = 1; i <= V; i++)
		dist[i] = MAX;
	dist[s] = 0;
	priority_queue<pair<int,int>> pq;
	pq.push(make_pair(0, s));
	int cost, cur, next, next_cost, size;
	while (!pq.empty())
	{
		cost = -pq.top().first;
		cur = pq.top().second;
		pq.pop();
		if (dist[cur] < cost)
			continue;
		size = vertext[cur].size();
		for (int i = 0; i < size; i++)
		{
			next = vertext[cur][i].first;
			next_cost = vertext[cur][i].second + cost;
			if (dist[next] > next_cost)
			{
				dist[next] = next_cost;
				pq.push(make_pair(-next_cost, next));
			}
		}
	}
	
	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == MAX)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}
	return 0;
}