#include <iostream>
#include <queue>
#define pnt pair<pair<int, int>, int>
using namespace std;

int map[500][500]={0, };
int xm[4]={0, 1, 0, -1}, ym[4]={1, 0, -1, 0};
int ans=0;

void BFS(int n, int m, int x, int y) {
  int visit[500][500]={0, };
  queue <pnt> q;
  int nx, ny, count=0, now=1, r=1, p;
  q.push(make_pair(make_pair(x, y), map[y][x]));
  visit[y][x]=1;
  while(!q.empty()) {
    x=q.front().first.first;
    y=q.front().first.second;
    p=q.front().second;
    q.pop();
    if(r==4) {
      if(ans<p) ans=p; 
      continue;
    }
    for(int i=0; i<4; i++) {
      nx=x+xm[i]; ny=y+ym[i];
      if(nx>=m || nx<0 || ny>=n || ny<0) continue;
      if(visit[ny][nx]!=0) continue;
      visit[ny][nx]=1;
      q.push(make_pair(make_pair(nx, ny), p+map[ny][nx]));
      count++;
    }
    now--;
    if(now==0) {
      now=count; count=0; r++;
    }
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin>>map[i][j];
    }
  }
  for(int y=0; y<n; y++) {
    for(int x=0; x<m; x++) {
      BFS(n, m, x, y);
    }
  }
  cout<<ans<<'\n';
  return 0;
}