#include <stdio.h>

int fib[21] = {0, 1, };

int FindFiv(int n) {
  if(n>1 && !fib[n]) {
    fib[n] = FindFiv(n-1) + FindFiv(n-2);
  }
  return fib[n];
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", FindFiv(n));
  return 0;
}