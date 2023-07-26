#include <stdio.h>

int main() {
  int seat[101] = {0, };
  int ans, n, x;
  ans = 0;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d", &x);
    if(seat[x]==0) {
      seat[x]=1;
    } else {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}