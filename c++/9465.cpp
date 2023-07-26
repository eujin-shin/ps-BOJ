#include <iostream>
#define M 100000
using namespace std;

#define max(x, y) (((x)>(y)) ? (x) : (y))

int map[2][M]={0, };
int dp[M+1]={0, };

int Getdp(int n) {
  dp[1]=max(map[0][0], map[1][0]);
  for(int i=2; i<=n; i++) {
    map[0][i-1]=map[0][i-1]+max(map[1][i-2], dp[i-2]);
    map[1][i-1]=map[1][i-1]+max(map[0][i-2], dp[i-2]);
    dp[i]=max(map[1][i-1], map[0][i-1]);
  }
  return dp[n];
}

int main() {
  ios_base::sync_with_stdio(false);
  int t, n;
  cin>>t;
  while(t-->0) {
    cin>>n;
    for(int i=0; i<2; i++) {
      for(int j=0; j<n; j++) {
        cin>>map[i][j];
      }
    }
    cout<<Getdp(n)<<'\n';
  }
  return 0;
}