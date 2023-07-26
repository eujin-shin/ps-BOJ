#include <stdio.h>

int main() {
  int n, fac;
  scanf("%d", &n);
  fac = 1;
  for(int i=1; i<=n; i++) {
    fac *= i;
  }
  printf("%d\n", fac);
  return 0;
}