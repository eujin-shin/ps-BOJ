#include <iostream>
using namespace std;

int dp[41]={0, };

int GetDp(int n) {
  if(n==0) return 1;
  if(dp[n]==0) {
    dp[n]=GetDp(n-1)+GetDp(n-2);
  }
  return dp[n];
}

int main() {
  int m, n, b, c, ans=1;
  cin>>n>>m;
  dp[1]=1; dp[2]=2;
  if(m==0) cout<<GetDp(n)<<'\n';
  else {
    b=0;
    for(int i=0; i<m; i++) {
      cin>>c;
      ans*=GetDp(c-b-1);
      b=c;
    }
    ans*=GetDp(n-b);
    cout<<ans<<'\n';
  }
  return 0;
}