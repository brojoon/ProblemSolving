#include <iostream>
#include <algorithm>

using namespace std;

int n, result;

int arr[200], dp[200];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
        result = result < dp[i] ? dp[i] : result;
    }

    cout << n - result;

    return 0;
}