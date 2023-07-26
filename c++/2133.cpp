#include <iostream>
using namespace std;

int dp[31][8]={0, };

int GetDp(int n) {
  for(int i=3; i<=n+1; i++) {
    dp[i][0]=dp[i-1][1]+dp[i-1][4]+dp[i-1][7];
    dp[i][1]=dp[i-1][6]+dp[i-1][0];
    dp[i][2]=dp[i-1][5];
    dp[i][3]=dp[i-1][4];
    dp[i][4]=dp[i-1][3]+dp[i-1][0];
    dp[i][5]=dp[i-1][2];
    dp[i][6]=dp[i-1][1];
    dp[i][7]=dp[i-1][0];
  }
  return dp[n+1][0];
}

int main() {
  int n;
  dp[2][1]=1; dp[2][4]=1; dp[2][7]=1;
  cin>>n;
  cout<<GetDp(n)<<'\n';
  return 0;
}