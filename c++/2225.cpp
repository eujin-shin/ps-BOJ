#include <iostream>
using namespace std;

int DP[202][202] = {0, };

int Dp(int n, int k) {
  int sum, num = 1000000000;
  for(int i=0; i<=n; i++) {
    DP[2][i] = i+1;
  }
  for(int i=3; i<=k; i++) {
    sum = 0;
    for(int j=0; j<=n; j++) {
      sum += DP[i-1][j];
      sum %= num;
      DP[i][j] = sum;
    }
  }
  return DP[k][n];
}

int main() {
  int n, k, ans = 1;
  cin>>n>>k;
  if(k==2) ans=n+1; else if(k>2) ans=Dp(n, k);
  cout<<ans<<'\n';
  return 0;
}