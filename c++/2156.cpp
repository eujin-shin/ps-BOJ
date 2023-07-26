#include <iostream>
#include <algorithm>
using namespace std;

int dp[5][10010] = {0, };

int GetMax(int n) {
  int sec, fir;
  if(dp[0][n]>dp[1][n]) {
    sec = dp[0][n];
  } else {
    sec = dp[1][n];
  }
  if(dp[2][n]>sec) {
    fir = dp[2][n];
  } else {
    fir = sec;
  }
  return fir;
}

int GetDp(int num[], int n) {
  for(int i=2; i<=n; i++) {
    dp[2][i] = dp[1][i-1] + num[i-1];
    dp[1][i] = dp[0][i-1] + num[i-1];
    dp[0][i] = GetMax(i-1);
  }
  return GetMax(n);
}

int main() {
  int n;
  int amount[10000] = {0, };
  cin>>n;
  for(int i=0; i<n; i++) {
    scanf("%d", &amount[i]);
  }
  dp[1][1] = amount[0];  
  cout<<GetDp(amount, n)<<endl;
}