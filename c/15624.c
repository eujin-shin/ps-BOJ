#include <stdio.h>

int fib[1000001] = {0, 1, 1, };

int GetFib(int n) {
  for(int i=3; i<=n; i++) {
    fib[i] = fib[i-1] + fib[i-2];
    fib[i] = fib[i]%1000000007;
  }
  return fib[n];
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", GetFib(n));
  return 0;
}