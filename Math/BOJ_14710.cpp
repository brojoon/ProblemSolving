#include <iostream>

int main()
{
	int i, j;
	std::cin >> i >> j;
	if (i != 0)
		i = i % 30;
	if (i * 12 != j)
		std::cout << "X" << std::endl;
	else
			std::cout << "O" << std::endl;
	return 0;
}