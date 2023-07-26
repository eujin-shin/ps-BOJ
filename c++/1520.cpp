#include <iostream>
#include <queue>
using namespace std;

int map[502][502]={0, };
int dp[502][502]={0, };
int visit[502][502]={0, };
int x_move[4]={0, 1, 0, -1};
int y_move[4]={1, 0, -1, 0};

int GetDp(int n, int m, int x, int y) {
  if(dp[x][y]==0) {
    int nx, ny, next, sum=0, cur=map[x][y];
    for(int i=0; i<4; i++) {
      nx=x+x_move[i]; ny=y+y_move[i];
      if(nx>n || nx<1 || ny>m || ny<1) continue;
      if(visit[nx][ny]==0 && cur<map[nx][ny]) { 
        visit[x][y]=1;  
        next=GetDp(n, m, nx, ny);
        if(next>0) sum+=next;
        visit[x][y]=0;
      }
    }
    if(sum==0) dp[x][y]=-1;
    else dp[x][y]=sum;
  }
  return dp[x][y];
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int m, n, ans;
  cin>>m>>n;
  for(int y=1; y<=m; y++) {
    for(int x=1; x<=n; x++) {
      cin>>map[x][y];
    }
  }
  dp[1][1]=1;
  ans=GetDp(n, m, n, m);
  if(ans==-1) ans=0;
  cout<<ans<<'\n';
  return 0;
}