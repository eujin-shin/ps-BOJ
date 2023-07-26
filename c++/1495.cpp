#include <iostream>
using namespace std;

int dp[51][1001]={0, };
int arr[50]={0, };

int GetDp(int n, int m) {
  int v, max=-1;
  for(int i=0; i<n; i++) {
    for(int j=0; j<=m; j++) {
      if(dp[i][j]==0) continue;
      v=arr[i];
      if(j+v<=m) dp[i+1][j+v]=1;
      if(j-v>=0) dp[i+1][j-v]=1;
    }
  }
  for(int i=m; i>=0; i--) {
    if(dp[n][i]!=1) continue;
    max=i; break;
  }
  return max;
}


int main() {
  ios_base::sync_with_stdio(false);
  int n, m, s;
  cin>>n>>s>>m;
  for(int i=0; i<n; i++) cin>>arr[i];
  dp[0][s]=1;
  cout<<GetDp(n, m)<<'\n';
  return 0;
}