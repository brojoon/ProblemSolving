#include <iostream>
#include <algorithm>

using namespace std;

int n, result;

int arr[1001], L_dp[1001], R_dp[1001];

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        L_dp[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (arr[i] > arr[j] && L_dp[i] < L_dp[j] + 1)
                L_dp[i] = L_dp[j] + 1;
        }
    }

    for (int i = n; i >= 1; i--)
    {
        R_dp[i] = 1;
        for (int j = n; j > i; j--)
        {
            if (arr[i] > arr[j] && R_dp[i] < R_dp[j] + 1)
                R_dp[i] = R_dp[j] + 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (result < L_dp[i] + R_dp[i] - 1)
            result = L_dp[i] + R_dp[i] - 1;
    }

    cout << result;

    return 0;
}