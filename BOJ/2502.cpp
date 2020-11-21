#include <iostream>

int main () {
  int fibo[32];
  int d, k, a, b;
  std::cin >> d >> k;
  fibo[1] = fibo[2] = 1;
  for (int i = 3; i <= d; i++) {
    fibo[i] = fibo[i - 1] + fibo[i - 2];
  }
  a = fibo[d - 2];
  b = fibo[d - 1];
  for(int i = 1; i <= 100000; i++) {
    if (!((k - a * i) % b)) {
      std::cout << i << std::endl;
      std::cout << (k - a * i) / b;
      break;
    }
  }
  return 0;
}