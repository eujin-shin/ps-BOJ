#include <iostream>
using namespace std;

int p[1001]={0, }, dp[1001]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin>>n;
  for(int i=1; i<=n; i++) {
    cin>>p[i]; dp[i]=p[i];
    for(int j=1; j<i; j++) {
      if(dp[i-j]+p[j]<dp[i]) dp[i]=dp[i-j]+p[j];
    }
  }
  cout<<dp[n]<<'\n';
  return 0;
}