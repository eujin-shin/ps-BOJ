#include <stdio.h>

int dp[16] = {0, };
int set[20][5] = {0, };

int GetDp(int k, int n) {
  int max = dp[k+1];
  int index = k+set[k][0];
  while(index<=n+1) {
    if(max<set[k][1]+dp[index]) {
      max = set[k][1] + dp[index];
    }
    index++;
  }
  dp[k] = max;
  return dp[k];
}

int main() {
  int n, temp;
  scanf("%d", &n);
  for(int i=1; i<=n; i++) {
    scanf("%d %d", &set[i][0], &set[i][1]);
  }
  for(int i=n; i>1; i--) {
    temp = GetDp(i, n);
  }
  printf("%d\n", GetDp(1, n));
  return 0;
}