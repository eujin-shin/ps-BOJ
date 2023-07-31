#include <iostream>
#include <queue>
using namespace std;

int map[1000][1000]={0, };
int xm[4]={0, 0, -1, 1}, ym[4]={1, -1, 0, 0};
queue <pair<int, int> > q;

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, x, y, tmp;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin>>tmp;
      if(tmp==2) {
        q.push(make_pair(j, i)); map[i][j]=0;
      } else if(tmp==1) {
        map[i][j]=-1;
      } else {
        map[i][j]=0;
      }
    }
  }
  int nx, ny;
  while(!q.empty()) {
    x=q.front().first; y=q.front().second;
    q.pop();
    for(int i=0; i<4; i++) {
      nx=x+xm[i]; ny=y+ym[i];
      if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
      if(map[ny][nx]==-1) {
        map[ny][nx]=map[y][x]+1;
        q.push(make_pair(nx, ny));
      }
    }
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(j>0) cout<<' ';
      cout<<map[i][j];
    }
    cout<<'\n';
  }
  return 0;
}