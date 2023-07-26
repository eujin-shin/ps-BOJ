#include <stdio.h>

int num_arr[10000001] = {0, 1, 2};

int GetNum(int n) {
  for(int i=3; i<=n; i++) {
    num_arr[i] = (num_arr[i-1] + num_arr[i-2])%10;
  }
  return num_arr[n];
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", GetNum(n));
  return 0;
}