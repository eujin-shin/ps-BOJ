#include <stdio.h>

int main() {
  int N, x;
  scanf("%d", &N);
  x = 2*N-1;
  for(int i=0; i<N; i++) {
    for(int j=0; j<i; j++) {
      printf(" ");
    }
    for(int j=0; j<x; j++) {
      printf("*");
    }
    x -= 2;
    printf("\n");
  }
  return 0;
}