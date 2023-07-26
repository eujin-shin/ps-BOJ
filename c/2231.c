#include <stdio.h>

int main() {
  int n; 
  scanf("%d", &n);
  int ans = 0;
  for(int i=1; i<n; i++) {
    int a = i;
    int ix = i;
    while(a>0) {
      ix += a%10;
      a /= 10;
    }
    if(ix==n) {
      ans = i;
      break;
    }
  }
  printf("%d\n", ans);
  return 0;
}