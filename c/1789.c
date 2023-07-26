#include <stdio.h>

int main() {
  long long int n, x;
  x = 0;
  scanf("%lld", &n);
  while(1) {
    if((x+1)*(x+2)/2>n) {
      break;
    }
    x++;
  }
  printf("%lld\n", x);
  return 0;
}