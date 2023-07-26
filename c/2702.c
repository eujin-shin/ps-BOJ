#include <stdio.h>

int GCD(int a, int b) {
  if(a<b) {
      int temp = a;
      a = b;
      b = temp;
    }
  if(a%b==0) {
    return b;
  } else if(b<3) {
    return 1;
  } else {
    return GCD(b, a-b);
  }
}

int main() {
  int T, a, b, gcd, l;
  scanf("%d", &T);
  for(int i=0; i<T; i++) {
    scanf("%d %d", &a, &b);
    gcd = GCD(a, b);
    printf("%d %d\n", a*b/gcd, gcd);
  }
  return 0;
}