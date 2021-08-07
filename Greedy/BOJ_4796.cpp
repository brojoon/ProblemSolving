#include <iostream>
#include <vector>

std::vector<int> v;

int main()
{
	int l, p, v, idx;

	std::cin >> l >> p >> v;

	int ftime;
	int ptime;

	idx = 1;

	while (!(l == 0 && p == 0 && v == 0))
	{
		ftime = v / p * l;
		ptime = (v % p) > l ? l : v % p;
		
		std::cout << "Case " << idx << ": " << ptime + ftime << std::endl;
		idx++;
		std::cin >> l >> p >> v;
	}
	return 0;
}