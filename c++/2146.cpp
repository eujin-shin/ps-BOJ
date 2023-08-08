#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

queue <pair<int, int> > q;
int map[100][100], visit[100][100]={0, };
int n, xm[4]={0, 0, -1, 1}, ym[4]={1, -1, 0, 0};

void Island(int x, int y, int r) {
  int nx, ny;
  q.push(make_pair(x, y));
  map[y][x]=r;
  while(!q.empty()) {
    x=q.front().first; y=q.front().second;
    q.pop();
    for(int i=0; i<4; i++) {
      nx=x+xm[i]; ny=y+ym[i];
      if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
      if(map[ny][nx]==1) {
        map[ny][nx]=r;
        q.push(make_pair(nx, ny));
      }
    }
  }
  return;
}

int Bridge(int x, int y) {
  int s=map[y][x], nx, ny;
  memset(visit, 0, sizeof(visit));
  visit[y][x]=1;
  q=queue<pair<int, int> >();
  q.push(make_pair(x, y));
  while(!q.empty()) {
    x=q.front().first; y=q.front().second;
    q.pop();
    for(int i=0; i<4; i++) {
      nx=x+xm[i]; ny=y+ym[i];
      if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
      if(map[ny][nx]==0 && visit[ny][nx]==0) {
        visit[ny][nx]=visit[y][x]+1;
        q.push(make_pair(nx, ny));
      } else if(map[ny][nx]!=0 && map[ny][nx]!=s) {
        return visit[y][x]-1;
      }
    }
  }
  return -1;
}

int main() {
  int cnt=2, min=200, tmp;
  cin>>n;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin>>map[i][j];
    }
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(map[i][j]==1) {
        Island(j, i, cnt++);
      }
    }
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(map[i][j]==0) {
        continue;
      }
      tmp=Bridge(j, i);
      if(tmp>0 && tmp<min) min=tmp;
    }
  }
  cout<<min<<'\n';
  return 0;
}