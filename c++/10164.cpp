#include <iostream>
using namespace std;

int dp[16][16]={0, };

int route(int x, int y) {
  if(x==1 || y==1) return 1;
  if(dp[y][x]==0) dp[y][x]=route(x-1, y)+route(x, y-1);
  return dp[y][x];
}

int main() {
  int n, m, k, x, y, ans;
  cin>>n>>m>>k;
  y=(k-1)/m+1; x=k%m;
  if(x==0) x=m;
  ans=(k==0 ? route(m, n) : route(x, y) * route(m-x+1, n-y+1));
  cout<<ans<<'\n';
  return 0;
}