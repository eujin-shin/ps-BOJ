#include <stdio.h>

long long koong[70] = {1, 1, 2, 4, 8, };

long long GetK(int n) {
  if(koong[n]==0) {
    long long x = GetK(n-1);
    koong[n] = x-GetK(n-5);
    koong[n] = koong[n]+x;
  }
  return koong[n];
}

int main() {
  int t, n;
  scanf("%d", &t);
  for(int i=0; i<t; i++) {
    scanf("%d", &n);
    printf("%lld\n", GetK(n));
  }
  return 0;
}