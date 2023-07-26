#include <iostream>
#define M 100000000
using namespace std;

int n;
int dp[16][1<<16] = {0, };
int map[16][16] = {0, };

int Solve(int cur, int cb) {
  int cost=M, temp;
  if(dp[cur][cb]!=0) return dp[cur][cb];
  if(cb==(1<<n)-1) {
    if(map[cur][0]==0) cost=M;
    else cost=map[cur][0];
  }
  else {
    for(int i=0; i<n; i++) {
      if(cb & (1<<i)) continue;
      if(map[cur][i]==0) continue;
      temp=Solve(i, cb|(1<<i));
      if(temp+map[cur][i]<cost) cost=temp+map[cur][i];
    }
  }
  dp[cur][cb]=cost;
  return dp[cur][cb];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>n;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin>>map[i][j];
    }
  }
  cout<<Solve(0, 1)<<'\n';
  return 0;
}