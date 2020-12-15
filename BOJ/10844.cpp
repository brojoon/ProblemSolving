#include <iostream>

using namespace std;

int n, sum;

int dp[101][11];

int main()
{
	cin >> n;

	for (int i = 1; i < 10; i++)
	{
		dp[0] #include<iostream>

			using namespace std;

		int n, sum;

		int dp[101][11];

		int main()
		{
			cin >> n;

			for (int i = 1; i < 10; i++)
			{
				dp[0][i] = 1;
			}

			for (int i = 1; i < n; i++)
			{
				dp[i][0] = dp[i - 1][1];
				for (int j = 1; j < 10; j++)
				{
					dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
				}
			}
			for (int i = 0; i <= 9; i++)
			{
				sum = (sum + dp[n - 1][i]) % 1000000000;
			}
			cout << sum;
			return 0;
		}

		for (int i = 1; i < n; i++)
		{
			dp[i][0] = dp[i - 1][1];
			for (int j = 1; j < 10; j++)
			{
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
			}
		}
		for (int i = 0; i <= 9; i++)
		{
			sum = (sum + dp[n - 1][i]) % 1000000000;
		}
		cout << sum;
		return 0;
	}