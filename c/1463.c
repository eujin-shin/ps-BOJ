#include <stdio.h>

int dp[1000001] = {0, 0, 1, 1, };

int GetDp(int n) {
  int min;
  if(n>1 && dp[n]==0) {
    min = GetDp(n-1)+1;
    if(n%2==0 && GetDp(n/2)+1<min) {
      min = GetDp(n/2)+1;
    }
    if(n%3==0 && GetDp(n/3)+1<min) {
      min = GetDp(n/3)+1;
    }
    dp[n] = min;
  }
  return dp[n];
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", GetDp(n));
  return 0;
}