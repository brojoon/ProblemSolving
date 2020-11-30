#include <iostream>

using namespace std;

int a, b, c;

int main() {
  cin >> a >> b >> c;
  c -= b;
  if (c <= 0) {
    cout << -1;
  } else if (a % c == 0) {
    cout << a / c + 1;
  } else {
    cout << a / c;
  }
  return 0;
}