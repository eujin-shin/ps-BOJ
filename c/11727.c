#include <stdio.h>

int main() {
  int f[1000] = {1, 1, };
  int n;
  scanf("%d", &n);
  for(int i=2; i<=n; i++) {
    f[i] = f[i-1] + 2*f[i-2];
    f[i] %= 10007;
  }
  printf("%d\n", f[n]);
  return 0;
}