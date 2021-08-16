#include <iostream>

#define MAX 91

using namespace std;

int N;
long long DP[MAX];

int main()
{
	cin >> N;

	DP[0] = 1;
	DP[1] = 1;
	
	for (int i = 2; i < N; i++)
		DP[i] = DP[i - 1] + DP[i - 2];

	cout << DP[N - 1] << endl;

	return 0;
}