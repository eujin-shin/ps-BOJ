#include <stdio.h>

int GetGcd(int a, int b) {
  int gcd;
  if(a%b==0) {
    gcd = b;
  } else {
    gcd = GetGcd(b, a%b);
  }
  return gcd;
}

int main() {
  int n, m, gcd;
  scanf("%d:%d", &n, &m);
  if(n>m) {
    gcd = GetGcd(n, m);
  } else {
    gcd = GetGcd(m, n);
  }
  printf("%d:%d\n", n/gcd, m/gcd);
  return 0;
}