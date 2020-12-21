#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, gcd;

int ft_gcd(int a, int b)
{
  return a % b ? ft_gcd(b, a % b) : b;
}

int main()
{
  cin >> n;

  vector<int> v(n);

  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  gcd = v[1] - v[0];

  for (int i = 2; i < n; i++)
  {
    gcd = ft_gcd(gcd, v[i] - v[i - 1]);
  }

  v.clear();

  for (int i = 2; i * i <= gcd; i++)
  {
    if (gcd % i == 0)
    {
      v.push_back(i);
      if (gcd / i > i)
      {
        v.push_back(gcd / i);
      }
    }
  }

  v.push_back(gcd);

  sort(v.begin(), v.end());

  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  return 0;
}