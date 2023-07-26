#include <stdio.h>

int main() {
  int T, a, b, gcd, lcm; 
  scanf("%d", &T);
  for(int i=0; i<T; i++) {
    scanf("%d %d", &a, &b);
    if(a==b) {
      printf("%d\n", a);
      continue;
    } else if (b>a) {
      int temp = a;
      a = b;
      b = temp;
    }
    int large = a;
    int small = b;
    while(large%small!=0) {
      int x = large%small;
      large=small;
      small=x;
    }
      gcd = small;
      printf("%d\n", a*b/gcd);
  }
  return 0;
}