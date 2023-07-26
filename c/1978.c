#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);
  int sum = 0;
  for(int i=0; i<N; i++) {
    int x;
    scanf("%d", &x);
    int exit = 0;
    if(x==1) {
      exit = 1;
    }
    for(int k=2; k<x; k++) {
      if(x%k==0) {
        exit = 1;
        break;
      }
    }
    if(exit==0) {
      sum += 1;
    }
  }
  printf("%d\n", sum);
  return 0;
}