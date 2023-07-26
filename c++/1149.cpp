#include <iostream>
using namespace std;

int price[4][1001] = {0, };
int dp[4][1001] = {0, };

int Smaller(int a, int b) {
  int ret=a;
  if(b<a) ret=b;
  return ret; 
}

int GetDp(int n) {
  int ret;
  for(int i=2; i<=n; i++) {
    dp[0][i]=price[0][i]+Smaller(dp[1][i-1], dp[2][i-1]);
    dp[1][i]=price[1][i]+Smaller(dp[0][i-1], dp[2][i-1]);
    dp[2][i]=price[2][i]+Smaller(dp[0][i-1], dp[1][i-1]);
  }
  ret=Smaller(dp[0][n], dp[1][n]);
  ret=Smaller(ret, dp[2][n]);
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  for(int i=1; i<=n; i++) {
    for(int j=0; j<3; j++) {
      cin>>price[j][i];
      if(i==1) dp[j][i]=price[j][i];
    }
  }
  cout<<GetDp(n)<<'\n';
  return 0;
}