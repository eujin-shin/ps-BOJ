#include <stdio.h>

int main() {
  long long ans, N;
  scanf("%lld", &N);
  ans = N*(N-1)*(N+1)/2;
  printf("%lld\n", ans); 
  return 0;
}