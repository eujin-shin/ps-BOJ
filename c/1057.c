#include <stdio.h>

int main() {
  int n, k, i, count;
  scanf("%d %d %d", &n, &k, &i);
  count = 0;
  while(k!=i) {
    k = (k+1)/2;
    i = (i+1)/2;
    count++;
  }
  printf("%d\n", count);
  return 0;
}