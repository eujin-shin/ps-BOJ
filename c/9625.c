#include <stdio.h>

int main() {
  int a[50] = {1, };
  int b[50] = {0, };
  int n;
  scanf("%d", &n);
  for(int i=1; i<=n; i++) {
    a[i] = b[i-1];
    b[i] = a[i-1] + b[i-1];
  }
  printf("%d %d\n", a[n], b[n]);
  return 0;
}