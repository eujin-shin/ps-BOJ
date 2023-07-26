#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  long long FibArr[n+1];
  FibArr[0]=0; FibArr[1]=1;
  for(int i=2; i<=n; i++) {
    FibArr[i]=FibArr[i-1]+FibArr[i-2];
  }
  printf("%lld\n", FibArr[n]);
  return 0;
}