#include <iostream>
#include <algorithm>

using namespace std;

int n, result;
int numbers[1000];
int dp[1000];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (numbers[i] > numbers[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        result = max(result, dp[i]);
    }
    cout << result;

    return 0;
}