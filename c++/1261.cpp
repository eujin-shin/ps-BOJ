#include <iostream>
#include <string.h>
using namespace std;

int x_move[4] = {0, 1, 0, -1};
int y_move[4] = {1, 0, -1, 0};
int dp[102][102] = {0, };
int visit[102][102] = {0, };

int Getdp(int x, int y, int m, int n) {
  int min=-1, nx, ny, temp;
  visit[x][y] = 1;
  for(int i=0; i<4; i++) {
    nx = x+x_move[i]; ny = y+y_move[i];
    if(nx<1 || nx>m || ny<1 || ny>n) continue;
    if(visit[nx][ny] && dp[nx][ny]>=0) {
      temp = dp[nx][ny];
    } else if(visit[nx][ny]) {
      continue;
    } else temp = Getdp(nx, ny, m, n);
    if(temp<min || min==-1) min = temp;
  }
  cout<<x<<' '<<y<<' '<<dp[x][y]<<' '<<min<<'\n';
  dp[x][y] = dp[x][y]+2+min;
  
  return dp[x][y];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string map;
  int n, m;
  cin>>m>>n;
  for(int y=1; y<=n; y++) {
    cin>>map;
    for(int x=1; x<=m; x++) {
      dp[x][y] = map[x-1]-'2';
    }
  }
  dp[1][1] = 0; visit[1][1] = 1;
  cout<<Getdp(m, n, m, n)<<'\n';
  return 0;
}