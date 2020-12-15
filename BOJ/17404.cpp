#include <iostream>
#include <algorithm>
#define MAX 123456789;

using namespace std;

int n, result = MAX;
int map[1001][3];
int dp[1001][3];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int k = 0; k <= 2; k++)
    {

        for (int i = 0; i <= 2; i++)
        {
            if (i == k)
                dp[1][i] = map[1][i];
            else
                dp[1][i] = MAX;
        }
        for (int i = 2; i <= n; i++)
        {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + map[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + map[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + map[i][2];
        }

        for (int i = 0; i <= 2; i++)
        {
            if (i == k)
                continue;
            result = min(result, dp[n][i]);
        }
    }

    cout << result;
    return 0;
}