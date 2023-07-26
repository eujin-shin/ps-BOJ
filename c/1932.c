#include <stdio.h>

int triangle[501][501] = {0, };
int DP[501][501] = {0, };

void GetMax(int n, int k, int x) {
  if(n+k==0) {
    DP[n][k] = x;
  } else if(!k) {
    DP[n][k] = DP[n-1][0] + x;
  } else if(k==n) {
    DP[n][k] = DP[n-1][n-1] + x;
  } else if(DP[n-1][k-1]>DP[n-1][k]) {
    DP[n][k] = DP[n-1][k-1] + x;
  } else {
    DP[n][k] = DP[n-1][k] + x;
  }
}

int main() {
  int n, x, max;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    for(int j=0; j<i+1; j++) {
      scanf("%d", &x);
      GetMax(i, j, x);
    }
  }
  max = 0;
  for(int i=0; i<n; i++) {
    if(max<DP[n-1][i]) {
      max = DP[n-1][i];
    }
  }
  printf("%d\n", max);
}