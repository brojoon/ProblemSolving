#include <iostream>
#include <string>
#include <algorithm>

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int cx, cy, dir, maxX, maxY, minX, minY;
int T;
std::string str;

void solution()
{
	std::cin >> T;
	for(int i = 0; i < T; i++)
	{
		std::cin >> str;
		cx = 0, cy = 0, dir = 0, maxX = 0, maxY = 0, minX = 0, minY = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == 'R' || str[i] == 'L')
			{
				if (str[i] == 'R')
					dir = (dir + 1) % 4;
				else
					dir = (dir + 3) % 4;
			}
			else {
				if (str[i] == 'F')
				{
					cx += dx[dir];
					cy += dy[dir];
				}
				else
				{
					cx -= dx[dir];
					cy -= dy[dir];
				}
				maxX = std::max(cx, maxX);
				maxY = std::max(cy, maxY);
				minX = std::min(cx, minX);
				minY = std::min(cy, minY);
			}
		}
  std::cout << (maxX - minX) * (maxY - minY) << '\n';
	}
}


int main()
{
	std::cin.tie(nullptr)->sync_with_stdio(false);
	solution();

	return 0;
}