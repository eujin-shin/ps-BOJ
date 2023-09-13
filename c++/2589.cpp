#include <iostream>
#include <string>
#include <queue>
using namespace std;

string map[50];
int xm[4]={1, -1, 0, 0}, ym[4]={0, 0, -1, 1};

int Maxlen(int n, int m, int x, int y) {
  int visit[50][50]={0, }, nx, ny;
  queue <pair<int, int> > q;
  q.push(make_pair(x, y));
  visit[y][x]=1;
  int len=0, cur=1, next=0;
  while(!q.empty()) {
    if(cur==0) {
      cur=next; next=0; len++;
    }
    x=q.front().first; y=q.front().second;
    q.pop();
    for(int i=0; i<4; i++) {
      nx=x+xm[i]; ny=y+ym[i];
      if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
      if(map[ny][nx]!='L' || visit[ny][nx]!=0) continue;
      visit[ny][nx]=1; next++;
      q.push(make_pair(nx, ny));
    }
    cur--;
  }
  return len;
}

int main() {
  int n, m, ans=0, tmp;
  cin>>n>>m;
  for(int i=0; i<n; i++) cin>>map[i];
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(map[i][j]!='L') continue;
      tmp=Maxlen(n, m, j, i);
      if(tmp>ans) ans=tmp;
    }
  }
  cout<<ans<<'\n';
  return 0;
}