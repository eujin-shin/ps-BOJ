#include <stdio.h>

int sum_set[12] = {0, };

int GetSum(int N) {
  if(sum_set[N]==0) {
    sum_set[N] = GetSum(N-1) + GetSum(N-2) + GetSum(N-3);
  }
  return sum_set[N];
}

int main() {
  sum_set[1] = 1;
  sum_set[2] = 2;
  sum_set[3] = 4;
  int T, N;
  scanf("%d", &T);
  for(int i=0; i<T; i++) {
    scanf("%d", &N);
    printf("%d\n", GetSum(N));
  }
  return 0;
}