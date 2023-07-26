#include <stdio.h>

int sum[100001] = {0, };

int main() {
  int n, m, x, y;
  scanf("%d", &n);
  for(int i=1; i<=n; i++) {
    scanf("%d", &x);
    sum[i] = sum[i-1] + x;
  }
  scanf("%d", &m);
  for(int i=0; i<m; i++) {
    scanf("%d %d", &x, &y);
    printf("%d\n", sum[y]-sum[x-1]);
  }
  return 0;
}