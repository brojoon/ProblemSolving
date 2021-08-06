#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
	int n;
	int budget;
	int sum = 0;
	int max = 0;

	std::cin >> n;
	std::vector<int> v(n);

	for (int i = 0;i < n; i++)
	{
		std::cin >> v[i];
		sum += v[i];
		if (v[i] > max)
			max = v[i];
	}
	
	std::cin >> budget;

	if (budget >= sum)
	{
		std::cout << max << std::endl;
		return 0;
	}

	int result = 0;
	while (max > result)
	{
		int mid = (max + result) / 2;
		int tmp = 0;
		for (int i = 0; i < n; i++)
		{
			if (mid >= v[i])
				tmp += v[i];
			else
				tmp += mid;
		}

		if (tmp > budget)
			max = mid;
		else
			result = mid + 1;
	}

	std::cout << result - 1 << std::endl;
	 
	return 0;

}