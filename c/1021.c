#include <stdio.h>

int main() {
  int q[151] = {0, };
  int n, m, k, count, a, x, y;
  scanf("%d %d", &n, &m);
  for(int i=1; i<=n; i++) {
    q[49+i] = i;
  }
  x = 50; y = 49+n;
  count = 0;
  for(int i=0; i<m; i++) {
    scanf("%d", &k);
    a = 0;
    while(q[x]!=k) {
      y++;
      q[y] = q[x];
      x++;
      a++;
    }
    if(a>(y-x+1)/2) {
      a = y-x+1-a;
    }
    x++;
    count += a;
  }
  printf("%d\n", count);
  return 0;
}