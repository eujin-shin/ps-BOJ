#include <stdio.h>

int dp[11] = {0, 0, 1, 3, };

int GetDp(int n) {
  if(n>3 && dp[n]==0) {
    dp[n] = (n/2)*(n-n/2)+GetDp(n/2)+GetDp(n-n/2);
  }
  return dp[n];
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", GetDp(n));
  return 0;
}