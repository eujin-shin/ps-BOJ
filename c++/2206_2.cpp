#include <iostream>
#include <queue>
using namespace std;

int visit[3][1002][1002] = {0, };

int main() {
  queue <int> xq, yq, zq;
  int map[1002][1002] = {0, };
  int x_move[4] = {0, 1, 0, -1};
  int y_move[4] = {1, 0, -1, 0};
  char temp[1002];
  int n, m;
  cin>>n>>m;
  for(int y=1; y<=n; y++) {
    cin>>temp;
    for(int x=1; x<=m; x++) {
      map[x][y] = temp[x-1]-'0';
    }
  }
  int cx, cy, z, nx, ny, now, next, count;
  bool flag=false;
  xq.push(1); yq.push(1); zq.push(0);
  visit[0][1][1] = 1;
  now=1; next=0; count=1;
  while(!xq.empty()) {
    if(now==0) {
      now=next; next=0; count++;
    }
    cx = xq.front(); xq.pop();
    cy = yq.front(); yq.pop();
    z = zq.front(); zq.pop();
    // cout<<cx<<' '<<cy<<' '<<z<<'\n';
    now--;
    if(cx==m && cy==n) {
      flag = true; break;
    }
    for(int i=0; i<4; i++) {
      nx = cx+x_move[i]; ny = cy+y_move[i];
      if(nx<1 || nx>m || ny<1 || ny>n) continue;
      if(z==1) {
        if(visit[0][nx][ny] || visit[1][nx][ny]) continue;
      }
      if(z==0 && visit[0][nx][ny]) continue;
      if(z==0 && map[nx][ny]==1) {
        xq.push(nx); yq.push(ny); zq.push(1);
        visit[1][nx][ny] = 1; next++;
      } else if(z==1 && map[nx][ny]==1) {
        continue;
      } else {
        xq.push(nx); yq.push(ny); zq.push(z);
        visit[z][nx][ny] = 1; next++;
      }
    }
  }
  if(flag) cout<<count<<'\n';
  else cout<<"-1\n";
  return 0;
}

/*

0100100
0110110
0110110
0000110
*/