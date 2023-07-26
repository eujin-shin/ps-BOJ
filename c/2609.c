#include <stdio.h>

int main() {
  int min, max, a, b, x, y;
  scanf("%d %d", &a, &b);
  if (a>b) {
    max = b;
    min = a;
  } else {
    max = a;
    min = b;
  }
  for(int i=max; i>=1; i--) {
    if(max%i==0 && min%i==0) {
      x = i;
      break;
    }
  }
  for(int i=min; i<=min*max; i++) {
    if(i%max==0 && i%min==0) {
      y = i;
      break;
    }
  }
  printf("%d\n%d\n", x, y);
  return 0;
}