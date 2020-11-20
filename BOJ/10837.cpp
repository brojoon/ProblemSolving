#include <iostream>
#include <cmath>
#include <algorithm>

using  namespace std;

int main () 
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int gap, remain;
  int a, b, k, c;

  cin >> k >> c;

  while(c--) {
    cin >> a >> b;
    if (a == b) {
      cout << '1' << '\n';
      continue;
    }
    gap = abs(a - b);
    remain = k - max(a, b); 
    if (a > b ) {
      if (gap - remain <= 2) {
        cout << '1' << '\n';
        continue;
      }
      else {
        cout << '0' << '\n';
        continue;
      }
    } else {
      if (gap - remain <= 1) {
        cout << '1' << '\n';
        continue;
      }
        cout << '0' << '\n';
    }
  }
return 0;
}