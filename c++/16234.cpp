#include <iostream>
#include <queue>
using namespace std;

int n, m, l, r, s;
int map[51][51]={0, }, visit[51][51]={0, };
int xm[4]={0, 0, -1, 1}, ym[4]={1, -1, 0, 0};

void DFS(int x, int y, int k) {
  int nx, ny, tmp;
  visit[x][y]=k;
  s+=map[x][y]; m++;
  for(int i=0; i<4; i++) {
    nx=x+xm[i]; ny=y+ym[i];
    if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
    if(visit[nx][ny]==k) continue;
    tmp=map[nx][ny]-map[x][y];
    if(tmp<0) tmp=-tmp;
    if(tmp>=l && tmp<=r) DFS(nx, ny, k);
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int avg[2501]={0, };
  cin>>n>>l>>r;
  for(int y=0; y<n; y++) {
    for(int x=0; x<n; x++) {
      cin>>map[x][y];
    }
  }
  int day=0, cnt;
  while(1) {
    cnt=0;
    for(int y=0; y<n; y++) {
      for(int x=0; x<n; x++) {
        if(visit[x][y]>0) continue;
        cnt++; m=0; s=0;
        DFS(x, y, cnt);
        avg[cnt]=s/m;
      }
    }
    if(cnt==n*n) break;
    for(int y=0; y<n; y++) {
      for(int x=0; x<n; x++) {
        map[x][y]=avg[visit[x][y]];
        visit[x][y]=0;
      }
    }
    day++;
  }
  cout<<day<<'\n';
  return 0;
}