#include <iostream>
#include <algorithm>
using namespace std;

int map[129][129];
int blueC = 0;
int whiteC = 0;
int n;

void div_conq(int x, int y, int xdx, int ydy) {
  int flag = map[x][y];
  for (int i = x; i < xdx; i++) {
    for (int j = y; j < ydy; j++) {
      if (flag != map[i][j]) {
        flag = 2;
        break;
      }
    }
  }
  if (flag == 0) {
    whiteC++;
  } else if (flag == 1) {
    blueC++;
  } else if (flag == 2) {
    div_conq(x, y, (x + xdx) / 2, (y + ydy) / 2);
    div_conq((x + xdx) / 2, y, xdx, (y + ydy) / 2);
    div_conq(x, (y + ydy) / 2, (x + xdx) / 2, ydy);
    div_conq((x  + xdx) / 2, (y + ydy) / 2, xdx, ydy);   
  }
}

int main () {
  cin >>  n;
  fill(&map[1][1], &map[n - 1][n - 1], 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
    }
  }
  div_conq(0, 0, n, n);
  cout << whiteC << '\n' << blueC;
}