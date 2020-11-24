#include <iostream>
#include <string.h>

using namespace std;

int n, flag;
int map[65][65];
string S;

void input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin  >> S;
    for (int j = 0; j < n; j++) {
        map[i][j] = S[j] - '0';
    }
  }
}

void div_conq(int x, int y, int size) {
  flag = map[y][x];
  for (int i = y; i < y + size && flag != 2; i++) {
    for (int j = x; j < x + size; j++) {
      if (map[i][j] != flag) {
        flag = 2;
        break;
      }
    }
  }
  switch(flag) {
    case 0:
      cout << '0';
      break;
    case 1:
      cout << '1';
      break;
    default:
      cout << '(';
      div_conq(x, y, size / 2);
      div_conq(x + size / 2, y, size / 2 );
      div_conq(x, y + size / 2, size / 2);
      div_conq(x + size / 2, y + size / 2, size / 2);
      cout << ')';
      break;
  }
}

void solve() {
  input();
  div_conq(0, 0, n);
}

int main() {
  
  solve();
  return 0;

}