#include <stdio.h>

int main() {
  int N, P, k, cycle, ans;
  scanf("%d %d", &N, &P);
  int cycle_set[97] = {0, };
  if(N<97) {
    cycle_set[N]=1;
  }
  cycle = 1;
  k = N;
  while(1) {
    k = k*N%P;
    cycle ++;
    if(cycle_set[k]==0) {
      cycle_set[k]=cycle;
    } else {
      ans = cycle - cycle_set[k];
      break;
    }
  }
  printf("%d\n", ans);
  return 0;
}