#include <iostream>
#include <string>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

using namespace std;

int map[1001][1001];

int main()
{
	int n, m, Max = 0;
	string s;

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		for (int j = 1; j <= m; j++)
		{
			map[i][j] = s[j - 1] - '0';
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] != 0)
			{	
				map[i][j] = MIN(map[i - 1][j - 1], MIN(map[i - 1][j], map[i][j - 1])) + 1;
				if (Max < map[i][j])
					Max = map[i][j];
			}
		}
	}

	cout << Max * Max << endl;

	return 0;

}