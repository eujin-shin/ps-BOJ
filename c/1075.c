#include <stdio.h>

int main() {
  int N, F;
  scanf("%d\n%d", &N, &F);
  int N_1 = N - (N%100);
  while(1) {
    if(N_1%F==0) {
      break;
    } else {
      N_1 += 1;
    }
  }
  printf("%02d\n", N_1%100);
  return 0;
}