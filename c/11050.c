#include <stdio.h>

int c_set[11][11] = {0, };

int c(int N, int K) {
  if(N==K || K==0) {
    c_set[N][K] = 1;
  } else if(c_set[N][K]==0) {
    c_set[N][K] = c(N-1, K) + c(N-1, K-1);
  }
  return c_set[N][K];
}

int main() {
  int N, K;
  scanf("%d %d", &N, &K);
  printf("%d\n", c(N, K));
  return 0;
}