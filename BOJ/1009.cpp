#include <stdio.h>

int main() {
  int t, a, b;
  int result, temp;
  scanf("%d", &t);
  while(t--) {
    scanf("%d %d", &a, &b);
    temp = a;
    b = b % 4 + 4;
    for(int i = 2; i <= b; i++) {
      a = (a * temp) % 10;
      if (a == 0)
        a = 10;
    }
    result = a % 10;
    if (!result) {
      printf("10\n");
    } else {
      printf("%d\n", result);
    }
  }
  return 0;
}