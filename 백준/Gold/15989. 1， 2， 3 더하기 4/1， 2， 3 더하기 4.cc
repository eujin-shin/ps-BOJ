#include <iostream>
using namespace std;

int dp[10001][4] = {0, }, bound = 0;

int getDp(int n);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n;
  cin>>t;
  dp[0][1] = 1;

  while(t--) {
    cin>>n;
    cout<<getDp(n)<<'\n';
  }
  return 0;
}

int getDp(int n) {
  for(int x = bound + 1; x <= n; x++) {
    dp[x][3] = x >= 3 ? dp[x - 3][1] + dp[x - 3][2] + dp[x - 3][3] : 0;
    dp[x][2] = x >= 2 ? dp[x - 2][1] + dp[x - 2][2] : 0;
    dp[x][1] = dp[x - 1][1];
  }
  bound = n;
  return dp[n][1] + dp[n][2] + dp[n][3];
}