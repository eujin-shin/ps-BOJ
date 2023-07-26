#include <stdio.h>

int main() {
  int N, sum;
  scanf("%d", &N);
  sum = 0;
  for(int i=0; i<N; i++) {
    int x;
    scanf("%d", &x);
    sum+=x;
  }
  printf("%d\n", sum-N+1);
  return 0;
}