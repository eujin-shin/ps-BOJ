#include <stdio.h>

int main() {
  int sum, min, max, x;
  sum = 0;
  max = 0; min = 100;
  for(int i=0; i<3; i++) {
    scanf("%d", &x);
    sum += x;
    if(x>max) {
      max = x;
    }
    if (x<min) {
      min = x;
    }
  }
  printf("%d\n", sum-min-max);
  return 0;
}