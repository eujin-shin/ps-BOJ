#include <stdio.h>

int main() {
  int fibonacci[1000] = {1, 1, };
  int n;
  scanf("%d", &n);
  for(int i=2; i<=n; i++) {
    fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    fibonacci[i] %= 10007;
  }
  printf("%d\n", fibonacci[n]);
}