#include <iostream>
using namespace std;

int arr[100] = {0, };
long long dp[102][22]={0, };

long long DFS(int n, int r, int cur) {
  if(r==n-1) {
    if(cur==arr[n-1]) dp[r][cur]=1;
  } else if(dp[r][cur]==0) {
    if(cur+arr[r]<=20) dp[r][cur]=dp[r][cur]+DFS(n, r+1, cur+arr[r]);
    if(r>0 && cur-arr[r]>=0) dp[r][cur]=dp[r][cur]+DFS(n, r+1, cur-arr[r]);
  }
  return dp[r][cur];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>arr[i];
  }
  cout<<DFS(n, 0, 0)<<'\n';
  return 0;
}