#include <stdio.h>

int dp[1000010] = {0, 1, 2, };

int GetDp(int n) {
  for(int i=3; i<=n; i++) {
    dp[i] = (dp[i-1]+dp[i-2])%15746;
  }
  return dp[n];
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", GetDp(n));
  return 0;
}