#include <iostream>
#define MOD 10000
using namespace std;

int arr[101]={0, }, dp[101][4][3]={0, };

int first(int d, int x) {
  int tmp=0;
  for(int i=1; i<4; i++) {
    if(i==x) continue;
    tmp+=dp[d-1][i][1]+dp[d-1][i][2];
  }
  return tmp%MOD;
}

int main() {
  int n, k, a, b;
  cin>>n>>k;
  for(int i=0; i<k; i++) {
    cin>>a>>b;
    arr[a]=b;
  }
  dp[1][1][1]=1; dp[1][2][1]=1; dp[1][3][1]=1;
  for(int i=1; i<4; i++) {
    if(arr[1]!=0 && arr[1]!=i) dp[1][i][1]=0;
  }
  for(int i=2; i<=n; i++) {
    for(int j=1; j<4; j++) {
      if(arr[i]!=0 && arr[i]!=j) continue;
      dp[i][j][1]=first(i, j);
      dp[i][j][2]=dp[i-1][j][1];
    }
  }
  cout<<(dp[n][1][1]+dp[n][1][2]+dp[n][2][1]+dp[n][2][2]+dp[n][3][1]+dp[n][3][2])%MOD<<'\n';
  return 0;
}