#include <stdio.h>

int main() {
  int m, n;
  scanf("%d\n%d", &m, &n);
  int sum, count, min;
  min = 10000;
  sum = 0;
  for(int i=m; i<=n; i++) {
    int exit = 0;
      for(int k=i; k>0; k--) {
      if(k*k==i) {
        exit = 1;
        break;
      }
    }
    if(exit==1) {
      sum += i;
      if(i<min) {
        min=i;
      }
    } else {
      continue;
    }
  }
    if(sum==0) {
        printf("%d\n", -1);
    } else {
        printf("%d\n%d\n", sum, min);
    }
  return 0;
}