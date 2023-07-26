#include <iostream>
using namespace std;

int arr[2][501]={0, };
int dp[501][501]={0, };

int solve(int a, int b) {
  if(a==b) return 0;
  if(dp[a][b]!=0) return dp[a][b];
  if(a+1==b) return dp[a][b]=arr[0][a]*arr[1][a]*arr[1][b];
  int tmp; 
  dp[a][b]=-1;
  for(int k=a; k<b; k++) {
    tmp=solve(a, k)+solve(k+1, b)+arr[0][a]*arr[1][k]*arr[1][b];
    if(dp[a][b]>tmp || dp[a][b]<0) dp[a][b]=tmp;
  }
  return dp[a][b];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n;
  cin>>n;
  for(int i=0; i<n; i++) cin>>arr[0][i]>>arr[1][i];
  cout<<solve(0, n-1)<<'\n';
  return 0;
}