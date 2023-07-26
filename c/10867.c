#include <stdio.h>

int main() {
  int minus_set[1000] = {0, };
  int plus_set[1000] = {0, };
  int n, x, min, max;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d", &x);
    if(i==0) {
      min=x;
      max=x;
    } else if(x<min) {
      min=x;
    } else if(x>max) {
      max=x;
    }
    if(x<0) {
      minus_set[-x] = minus_set[-x] + 1;
    } else {
      plus_set[x] = plus_set[x] + 1;
    }
  }
  for(int i=min; i<=max; i++) {
    if(i<0 && minus_set[-i]>0) {
      printf("%d ", i);
    } else if(i>=0 && plus_set[i]>0) {
      printf("%d ", i);
    }
  }
  printf("\n");
  return 0;
}