#include <iostream>
#include <queue>
#define pnt pair<int, int>
using namespace std;

int moves[2][4]={{0, 1, 0, -1}, {-1, 0, 1, 0}};
int map[20][20]={0, }, visit[20][20], n;

void init() {
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) visit[i][j]=0;
  }
  return;
}

pnt count(int x, int y, int d) {
  int cur[20][20]={0, };
  int b=1, r=0, cx, cy, nx, ny, k=map[y][x];
  queue <pnt> q;
  q.push(make_pair(x, y)); cur[y][x]=1; visit[y][x]=1;
  while(!q.empty()) {
    cx=q.front().first; cy=q.front().second;
    if(d==1) map[cy][cx]=-2;
    q.pop();
    for(int i=0; i<4; i++) {
      nx=cx+moves[0][i]; ny=cy+moves[1][i];
      if(nx<0 || ny<0 || nx>=n || ny>=n || cur[ny][nx]!=0) continue;
      if(map[ny][nx]==k || map[ny][nx]==0) {
        if(map[ny][nx]==k) visit[ny][nx]=1;
        else r++;
        b++;
        q.push(make_pair(nx, ny)); cur[ny][nx]=1;
      }
    }
  }
  return make_pair(b, r);
}

void Down() {
  int idx;
  for(int j=0; j<n; j++) {
    idx=n-1;
    for(int i=n-1; i>=0; i--) {
      if(map[i][j]==-1) idx=i-1;
      else if(map[i][j]>=0) {
        if(idx!=i) {
          map[idx][j]=map[i][j];
          map[i][j]=-2;
        }
        idx--;
      }
    }
  }
  return;
}

void Rotate() {
  int tmp[20][20]={0, };
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) tmp[i][j]=map[j][n-1-i];
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) map[i][j]=tmp[i][j];
  }
  return;
}

int main() {
  int m, b, s=0, x, y;
  pnt max, t;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) cin>>map[i][j];
  }
  while(1) {
    init(); max=make_pair(0, 0);
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
        if(map[i][j]<1 || visit[i][j]!=0) continue;
        t=count(j, i, 0);
        if(t.first>max.first || (t.first==max.first && t.second>=max.second)) {
          max=t; x=j; y=i;
        }
      }
    }
    if(max.first<2) break;
    init();
    t=count(x, y, 1);
    s+=max.first*max.first;
    Down(); Rotate(); Down();
  }
  cout<<s<<'\n';
  return 0;
}