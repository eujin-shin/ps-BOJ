#include <stdio.h>

long long num_arr[117] = {1, 1, 1, 1, };

long long GetNum(int n) {
  for(int i=4; i<=n; i++) {
    num_arr[i] = num_arr[i-1]+num_arr[i-3];
  }
  return num_arr[n];
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%lld\n", GetNum(n));
  return 0;
}