#include <stdio.h>

long long pinary[91] = {0, };

long long GetPinary(int N) {
  if(pinary[N]==0) {
    pinary[N] = GetPinary(N-1) + GetPinary(N-2);
  }
  return pinary[N];
}


int main() {
  pinary[1] = 1;
  pinary[2] = 1;
  int N;
  long long ans;
  scanf("%d", &N);
  if(N<3) {
    ans = 1;
  } else {
    ans = GetPinary(N);
  }
  printf("%lld\n", ans);
  return 0;
}