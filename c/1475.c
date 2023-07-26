#include <stdio.h>

int main() {
  int N, x, max;
  max = 1;
  int num_set[9] = {0, };
  scanf("%d", &N);
  while(N) {
    x = N%10;
    if(x==9) {
      x = 6;
    }
    num_set[x] += 1;
    N /= 10;
  }
  num_set[6] = (num_set[6]+1)/2;
  for(int i=0; i<9; i++) {
    if(max<num_set[i]) {
      max = num_set[i];
    }
  }
  printf("%d\n", max);
  return 0;
}