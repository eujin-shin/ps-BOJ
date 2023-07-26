#include <stdio.h>

int fib_set[47] = {0, };

int fib (int n) {
  
  if(n>1 && fib_set[n]==0) {
    fib_set[n] = fib(n-1) + fib(n-2);
  } else if(n==1) {
    fib_set[n] = 1;
  }
  return fib_set[n];
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", fib(n));
  return 0;
}