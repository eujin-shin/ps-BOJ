#include <stdio.h>

long long dp[1002][1002] = {0, };

long long GetNum(int n, int m) {
  if(!dp[n][m]) {
    if(n>1 && m>1) {
      dp[n][m] = GetNum(n-1, m) + GetNum(n, m-1) + GetNum(n-1, m-1);
      dp[n][m] = dp[n][m] % 1000000007;
    } else if(n>1) {
      dp[n][m] = GetNum(n-1, m);
    } else if(m>1) {
      dp[n][m] = GetNum(n, m-1);
    }
  }
  return dp[n][m];
}

int main() {
  int n, m;
  dp[1][1] = 1;
  scanf("%d %d", &n, &m);
  printf("%lld\n", GetNum(n, m));
  return 0;
}