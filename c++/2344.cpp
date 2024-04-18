#include <iostream>
using namespace std;

int map[1005][1005]={0, }, ans[4001]={0, }, n, m;
int dir[4][2]={{1, 0}, {0, -1}, {-1, 0}, {0, 1}}, pos[4]={1, 0, 3, 2};

int move(int d, int x, int y) {
  if(x<1) return y;
  else if(y>n) return n+x;
  else if(x>m) return n+m+(n+1-y);
  else if(y<1) return 2*n+2*m-x+1;
  if(map[y][x]==1) d=pos[d];
  return move(d, x+dir[d][0], y+dir[d][1]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin>>n>>m;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) cin>>map[i][j];
  }
  int x, y, d, e;
  for(int i=1; i<=2*(n+m); i++) {
    if(ans[i]!=0) continue;
    if(i<=n) e=move(0, 1, i);
    else if(i<=n+m) e=move(1, i-n, n);
    else if(i<=2*n+m) e=move(2, m, n+1-(i-n-m));
    else e=move(3, m+1-(i-2*n-m), 1);
    ans[i]=e; ans[e]=i;
  }
  for(int i=1; i<=2*(n+m); i++) {
    if(i>1) cout<<' ';
    cout<<ans[i];
  }
  cout<<'\n';
  return 0;
}