#include <stdio.h>

int fib_set[41] = {0, };

int fib(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else if(fib_set[n]==0) {
    fib_set[n] = fib(n-1) + fib(n-2);
  }
  return fib_set[n];
}

int main() {
  fib_set[0]=0;
  fib_set[1]=1;
  int T, n;
  scanf("%d", &T);
  for(int i=0; i<T; i++) {
    scanf("%d", &n);
    if(n==0) {
      printf("1 0\n");
    } else if(n==1) {
      printf("0 1\n");
    } else {
      printf("%d %d\n", fib(n-1), fib(n));
    }
  }
  return 0;
}