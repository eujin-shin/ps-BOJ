#include <iostream>
#define M 500
using namespace std;

#define max(x, y) (((x)>(y)) ? (x):(y))

int map[M][M]={0, };
int dp[M][M]={0, };
int xm[4]={0, 0, -1, 1};
int ym[4]={1, -1, 0, 0};

int Update(int x, int y, int n) {
  if(dp[x][y]!=0) return dp[x][y];
  int nx, ny, m=1, temp;
  for(int i=0; i<4; i++) {
    nx=x+xm[i]; ny=y+ym[i];
    if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
    if(map[nx][ny]<=map[x][y]) continue;
    temp = Update(nx, ny, n)+1;
    m=max(m, temp);
  }
  dp[x][y]=m;
  return dp[x][y];
}

int main() {
  int n, m=0;
  cin>>n;
  for(int y=0; y<n; y++) {
    for(int x=0; x<n; x++) {
      cin>>map[x][y];
    }
  }
  for(int y=0; y<n; y++) {
    for(int x=0; x<n; x++) {
      dp[x][y]=Update(x, y, n);
      m=max(m, dp[x][y]);
    }
  }
  cout<<m<<'\n';
  return 0;
}