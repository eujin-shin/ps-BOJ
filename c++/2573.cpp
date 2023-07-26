#include <iostream>
#include <queue>
using namespace std;

int x_move[4]={0, 1, 0, -1};
int y_move[4]={1, 0, -1, 0};

int main() {
  ios_base::sync_with_stdio(false);
  int map[301][301]={0, };
  int n, m, count=0, ans=0;
  cin>>n>>m;
  for(int y=0; y<n; y++) {
    for(int x=0; x<m; x++) {
      cin>>map[x][y];
      if(map[x][y]>0) count++;
    }
  }
  queue <int> xq; queue <int> yq;
  int year=0, minus, cx, cy, nx, ny, ice;
  while(++year && count>0) {
    for(int x=1; x<m-1; x++) {
      for(int y=1; y<n-1; y++) {
        if(map[x][y]==0) continue;
        minus=0;
        for(int i=0; i<4; i++) {
          if(map[x+x_move[i]][y+y_move[i]]==0) minus++;
        }
        map[x][y]=map[x][y]-minus;
        if(map[x][y]<=0) {
          map[x][y]=-1;
          xq.push(x); yq.push(y);
          count--;
        } else {
          cx=x; cy=y;
        }
      }
    }
    if(count<=0) break;
    while(!xq.empty()) {
      nx=xq.front(); ny=yq.front();
      xq.pop(); yq.pop();
      map[nx][ny]=0;
    }
    xq.push(cx); yq.push(cy);
    ice=0;
    int visit[301][301]={0, };
    visit[cx][cy]=1;
    while(!xq.empty()) {
      ice++;
      cx=xq.front(); xq.pop();
      cy=yq.front(); yq.pop();
      for(int i=0; i<4; i++) {
        nx=cx+x_move[i]; ny=cy+y_move[i];
        if(map[nx][ny]>0 && visit[nx][ny]==0) {
          xq.push(nx);
          yq.push(ny);
          visit[nx][ny]=1;
        }
      }
    }
    if(ice<count) {
      ans=year; break;
    }
  }
  cout<<ans<<'\n';
  return 0;
}