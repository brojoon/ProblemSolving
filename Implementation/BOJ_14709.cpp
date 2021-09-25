#include <iostream>
#include <string>

bool pair[4];

int n, i, j;

void input()
{
	std::cin >> n;
	for (int k = 0; k < n; k++)
	{
			std::cin >> i >> j;
			if ((i != 1 && i != 3 && i != 4) || (j != 1 && j != 3 && j != 4))
				pair[3] = true;
			else if ((i == 1 && j == 3) || (i == 3 && j == 1))
				pair[0] = true;
			else if ((i == 4 && j == 1) || (i == 1 && j == 4))
				pair[1] = true;
			else if ((i == 3 && j == 4) || (i == 4 && j == 3))
				pair[2] = true;
	}
}

void solution()
{
	if (pair[3] != true && pair[0] && pair[1] && pair[2])
		std::cout << "Wa-pa-pa-pa-pa-pa-pow!" << std::endl;
	else
		std::cout << "Woof-meow-tweet-squeek" << std::endl;
}

int main()
{
	input();
	solution();
	return 0;
}