#include <stdio.h>

int Gcd(int x, int temp) {
  int gcd, a, b;
  if(x>temp) {
    a = x;
    b = temp;
  } else {
    a = temp;
    b = x;
  }
  if(a%b==0) {
    gcd = b;
  } else {
    gcd = Gcd(b, a-b);
  }
  return gcd;
}

int main() {
  int n, x, temp, gcd;
  scanf("%d", &n);
  scanf("%d", &x);
  for(int i=1; i<n; i++) {
    scanf("%d", &temp);
    gcd = Gcd(x, temp);
    printf("%d/%d\n", x/gcd, temp/gcd);
  }
  return 0;
}