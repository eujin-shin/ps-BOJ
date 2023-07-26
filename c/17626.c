#include <stdio.h>
#include <math.h>

int dp[50001] = {0, 1, 2, };

int GetDp(int n) {
  int min;
  for(int i=3; i<=n; i++) {
    min = i;
    for(int j=1; j<=sqrt(i); j++) {
      if(min>dp[i-j*j]+1) {
        min = dp[i-j*j]+1;
      }
    }
    dp[i] = min;
  }
  return dp[n];
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", GetDp(n));
  return 0;
}