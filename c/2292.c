#include <stdio.h>

int main() {
  int n, x, ans;
  scanf("%d", &n);
  x=1;
  ans=1;
  while(n>x) {
    x+=6*ans;
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}