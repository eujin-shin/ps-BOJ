#include <stdio.h>

int main() {
  int X, stick, sum;
  sum = 0;
  stick = 64;
  scanf("%d", &X);
  while(X) {
    sum += X/stick;
    X %= stick;
    stick /= 2;
  }
  printf("%d\n", sum);
  return 0;
}