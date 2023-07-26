#include <stdio.h>

int main() {
  int plus_set[1000001] = {0, };
  int minus_set[1000001] = {0, };
  int n, x, min, max;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d", &x);
    if(i==0) {
      min = x;
      max = x;
    } else {
      if(min>x) {
        min = x;
      } else if(max<x) {
        max = x;
      }
    }
    if(x<0) {
      minus_set[-x] = 1;

    } else {
      plus_set[x] = 1;
    }
  }
  int count = min;
  while(1) {
    if(count<0) {
      if(minus_set[-count]==1) {
        printf("%d\n", count);
      }
    } else {
      if(plus_set[count]==1) {
        printf("%d\n", count);
      }
    }
    count++;
    if(count>max) {
      break;
    }
  }
  return 0;
}