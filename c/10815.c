#include <stdio.h>

int plus_set[10000000] = {0, };
int minus_set[10000000] = {0, };

int main() {
  int N, M, x;
  int ans_set[500000] = {0, };
  scanf("%d", &N);
  for(int i=0; i<N; i++) {
    scanf("%d", &x);
    if(x<0) {
      minus_set[-x] = 1;
    } else {
      plus_set[x] = 1;
    }
  }
  scanf("%d", &M);
  for(int i=0; i<M; i++) {
    scanf("%d", &x);
    if(x<0) {
      if(minus_set[-x]>0) {
        ans_set[i] = 1;
      }
    } else {
      if(plus_set[x]>0) {
        ans_set[i] = 1;
      }
    }
  }
  for(int i=0; i<M; i++) {
    printf("%d ", ans_set[i]);
  }
  printf("\n");
  return 0;
}