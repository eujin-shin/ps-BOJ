#include <stdio.h>

int main() {
  int n, k, sum;
  scanf("%d", &n);
  sum = 0;
  k = 1;
  while(n) {
    if(k>n) {
      k = 1;
    }
    sum++;
    n -= k;
    k++;
  }
  printf("%d\n", sum);
  return 0;
}