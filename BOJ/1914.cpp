#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int n;

void hanoi(int n, int from, int tmp, int to)
{
  if (n == 1)
    cout << from << ' ' << to << '\n';
  else
  {
    hanoi(n - 1, from, to, tmp);
    cout << from << ' ' << to << '\n';
    hanoi(n - 1, tmp, from, to);
  }
}

int main()
{
  cin >> n;

  string a = to_string(pow(2, n));
  int idx = a.find('.');
  a = a.substr(0, idx);
  a[a.length() - 1] -= 1;

  cout << a << '\n';

  if (n <= 20)
    hanoi(n, 1, 2, 3);

  return 0;
}