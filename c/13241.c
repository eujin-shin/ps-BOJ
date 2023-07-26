#include <stdio.h>

long long GetGcd(long long x, long long y) {
  long long large, small, gcd;
  if(x>y) {
    large = x;
    small = y;
  } else {
    large = y;
    small = x;
  }
  gcd = small;
  if(large%small!=0) {
    gcd = GetGcd(small, large-small);
  }
  return gcd;
}

int main() {
  long long x, y, gcd;
  scanf("%lld %lld", &x, &y);
  gcd = GetGcd(x, y);
  printf("%lld\n", x/gcd*y);
  return 0;
}