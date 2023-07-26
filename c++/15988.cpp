#include <iostream>
#define MOD 1000000009
#define M 1000001
using namespace std;

int dp[M]={0, };

int Dp(int n) {
  if(dp[n]==0) {
    for(int i=dp[0]+1; i<=n; i++) {
      dp[i]=(dp[i-1]+dp[i-2])%MOD;
      dp[i]=(dp[i-3]+dp[i])%MOD;
    }
    dp[0]=n;
  }
  return dp[n];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  dp[1]=1; dp[2]=2; dp[3]=4; dp[0]=3;
  int t, n;
  cin>>t;
  for(int i=0; i<t; i++) {
    cin>>n;
    cout<<Dp(n)<<'\n';
  }
  return 0;
}