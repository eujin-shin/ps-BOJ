#include <iostream>
#define M 9901
using namespace std;

int dp[3][100001]={0, };

int GetDp(int n) {
  int sum;
  for(int i=2; i<=n; i++) {
    dp[1][i]=(dp[2][i-1]+dp[0][i-1])%M;
    dp[2][i]=(dp[1][i-1]+dp[0][i-1])%M;
    dp[0][i]=(dp[0][i-1]+dp[1][i-1]+dp[2][i-1])%M;
  }
  return (dp[0][n]+dp[1][n]+dp[2][n])%M;
}

int main() {
  int n;
  cin>>n;
  for(int i=0; i<3; i++) {
    dp[i][1]=1;
  }
  cout<<GetDp(n)<<'\n';
  return 0;
}