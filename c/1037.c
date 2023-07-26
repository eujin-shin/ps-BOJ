#include <stdio.h>

int main() {
  int N, max, min, x;
  scanf("%d", &N);
  if(N==1) {
    scanf("%d", &max);
    min = max;
  } else {
    min = 1000000;
    max = 2;
    for(int i=0; i<N; i++) {
      scanf("%d", &x);
      if(x<min) {
        min = x;
      } 
      if (x>max) {
        max = x;
      }
    }
  }
  printf("%d\n", min*max);
  return 0;
}