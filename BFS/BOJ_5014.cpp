#include <iostream>
#include <queue>
#include <vector>

#define ERROR  "use the stairs"

std::queue<std::pair<int, int>> q;
// std::vector<bool> v;
bool v[1000001];

int main()
{
	int f, s, g, u ,d;
	int cnt = 0;
	int stair = 0;
	int result = -1;
	std::cin >> f >> s >> g >> u >> d;
	// v.assign(f + 1, false);
	q.push(std::make_pair(s, cnt));
	v[s] = true;
	while (!(q.empty()))
	{
		stair = q.front().first;
		cnt = q.front().second;
		if (stair == g)
		{
			result = cnt;
			break;
		}
		v[stair] = true;
		q.pop();
		if (stair + u <= f && !v[stair + u])
		{
			q.push(std::make_pair(stair + u, cnt + 1));
			v[stair + u] = true;
		}
			

		if (stair - d > 0 && !v[stair - d])
		{
			q.push(std::make_pair(stair - d, cnt + 1));
			v[stair - d] = true;
		}
	}

	if (result == -1)
		std::cout << ERROR << std::endl;
	else
		std::cout << result << std::endl;
	return 0;
}