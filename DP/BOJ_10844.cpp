#include <iostream>

using namespace std;

int N;

int DP[101][11];
long long sum;

int main()
{
	cin >> N;
	
	for (int i = 1; i < 10; i++)
		DP[1][i] = 1;
	for (int i = 2; i <= N; i++)
	{
		DP[i][0] = DP[i - 1][1];
		for (int j = 1; j < 10; j++)
		{
			DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % 1000000000; 
		}
	} 
	for (int i = 0; i <= 9; i++)
		sum += DP[N][i];
	cout << sum % 1000000000 << endl;
}