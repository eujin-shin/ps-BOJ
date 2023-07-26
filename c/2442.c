#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);
  int k = 1;
  while(N) {
    for(int i=0; i<N-1; i++) {
      printf(" ");
    }
    for(int i=0; i<k; i++) {
      printf("*");
    }
    printf("\n");
    k += 2;
    N--;
  }
  return 0;
}