#include <iostream>
#include <vector>
using namespace std;

vector <int> v[2];
int dp[10001][101]={0, };
int ans=-1;

int main() {
  int n, m, t, c=0;
  cin>>n>>m;
  for(int i=0; i<2; i++) {
    for(int j=0; j<n; j++) {
      cin>>t; v[i].push_back(t);
      if(i==1) c+=t;
    }
  }
  for(int i=0; i<=c; i++) {
    for(int j=1; j<=n; j++) {
      if(v[1][j-1]>i) {
        dp[i][j]=dp[i][j-1];
      } else {
        dp[i][j]=dp[i-v[1][j-1]][j-1]+v[0][j-1];
        if(dp[i][j]<dp[i][j-1]) dp[i][j]=dp[i][j-1];
      }
    }
    if(dp[i][n]>=m) {
      ans=i; break;
    }
  }
  cout<<ans<<'\n';
  return 0;
}