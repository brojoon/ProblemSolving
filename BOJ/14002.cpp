#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

int arr[1000], dp[1000];

vector<int> LIS[1000];
vector<int> result;

int main()
{
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    dp[i] = 1;
    LIS[i].push_back(arr[i]);
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
      {
        dp[i] = dp[j] + 1;
        LIS[i] = LIS[j];
        LIS[i].push_back(arr[i]);
      }
    }
    if (result.size() < LIS[i].size())
      result = LIS[i];
  }
  cout << result.size() << '\n';

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << ' ';
  }

  return 0;
}