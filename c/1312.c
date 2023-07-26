#include <stdio.h>

int main() {
  int a, b, n, x;
  scanf("%d %d %d", &a, &b, &n);
  a = a%b*10;
  for(int i=0; i<n; i++) {
    if(a==0) {
      x = 0;
      break;
    }
    x = a/b;
    a = a%b*10;
  }
  printf("%d\n", x);
  return 0;
}