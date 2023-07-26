#include <stdio.h>

int main() {
  int n, ans;
  scanf("%d", &n);
  if(n%5==0) {
    ans = n/5;
  } else if((n%5)%2==0) {
    ans = n/5+(n%5)/2;
  } else if(n>5) {
    ans = n/5-1;
    ans += (n-(ans*5))/2;
  } else {
    ans = -1;
  }
  printf("%d\n", ans);
  return 0;
}