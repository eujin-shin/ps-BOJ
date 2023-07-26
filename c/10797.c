#include <stdio.h>

int main() {
  int n, sum;
  scanf("%d", &n);
  sum = 0;
  for(int i=0; i<5; i++) {
    int x;
    scanf("%d", &x);
    if(n==x) {
      sum++;
    }
  }
  printf("%d\n", sum);
  return 0;
}