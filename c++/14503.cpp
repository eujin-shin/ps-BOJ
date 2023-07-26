#include <iostream>
using namespace std;

int x_move[] = {0, -1, 0, 1, 0};
int y_move[] = {-1, 0, 1, 0};
int map[53][53] = {0, };

void DFS(int x, int y, int d) {
  int dir, next_x, next_y;
  if(map[x][y]==0) map[0][0] = map[0][0] + 1;
  map[x][y] = 2;
  for(int i=0; i<4; i++) {
    dir = (d + i)%4;
    next_x = x + x_move[dir];
    next_y = y + y_move[dir];
    if(map[next_x][next_y]==0) {
      DFS(next_x, next_y, dir+1);
      return;
    }
  }
  next_x = x - x_move[dir];
  next_y = y - y_move[dir];
  if(map[next_x][next_y]!=1) DFS(next_x, next_y, dir+1);
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, r, c, d;
  cin>>n>>m>>r>>c>>d;
  if(d==1) d=3; else if(d==3) d=1;
  for(int y=1; y<=n; y++) {
    for(int x=1; x<=m; x++) {
      cin>>map[x][y];
    }
  }
  int x = c+1, y = r+1;
  DFS(x, y, d+1);
  cout<<map[0][0]<<'\n';
  return 0;
}