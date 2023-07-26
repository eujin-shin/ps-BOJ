#include <stdio.h>

int plus_set[10000001] = {0, };
int minus_set[10000001] = {0, };

int main() {
  int N, M, case_n, case_m;
  scanf("%d", &N);
  for(int i=0; i<N; i++) {
    scanf("%d", &case_n);
    if(case_n<0) {
      case_n *= -1;
      minus_set[case_n] += 1;
    } else {
      plus_set[case_n] += 1;
    }
  }
  scanf("%d", &M);
  for(int i=0; i<M; i++) {
    scanf("%d", &case_m);
    if(case_m<0) {
      case_m *= -1;
      printf("%d", minus_set[case_m]);
    } else {
      printf("%d", plus_set[case_m]);
    }
    if(i==M-1) {
      printf("\n");
    } else {
      printf(" ");
    }
  }
  return 0;
}