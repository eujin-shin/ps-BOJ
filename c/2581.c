#include <stdio.h>

int main() {
  int m, n;
  scanf("%d\n%d", &m, &n);
  int sum, count, min;
  min = 10000;
  sum = 0;
  for(int i=m; i<=n; i++) {
      if(i==1) {
          continue;
      }
    int exit = 0;
      for(int k=i-1; k>1; k--) {
      if(i%k==0) {
        exit = 1;
        break;
      }
    }
    if(exit==1) {
      continue;
    } else {
      sum += i;
      if(i<min) {
        min=i;
      }
    }
  }
    if(sum==0) {
        printf("%d\n", -1);
    } else {
        printf("%d\n%d\n", sum, min);
    }
  return 0;
}