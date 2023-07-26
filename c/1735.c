#include <stdio.h>
#include <math.h>

int main() {
  int x1, x2, x3, y1, y2, y3;
  scanf("%d %d", &x1, &y1);
  scanf("%d %d", &x2, &y2);
  y3 = y2 * y1;
  x3 = x1 * y2 + x2 * y1;
  for(int i=2; i<=sqrt(x3); i++) {
    while(!(x3%i+y3%i)) {
      x3 /= i;
      y3 /= i;
    }
  }
  printf("%d %d\n", x3, y3);
}