#include <iostream>
using namespace std;

int map[1002][1002] = {0, };
int visit[1002][1002] = {0, };
int x_move[4] = {0, 1, 0, -1};
int y_move[4] = {1, 0, -1, 0};

void DFS(int x, int y, int n, int m, int r, bool flag) {
  if(visit[0][0]!=-1) return;
  if(x==m && y==n) {
    visit[0][0] = r;
    return;
  } else {
    int next_x, next_y;
    for(int i=0; i<4; i++) {
      next_x = x + x_move[i];
      next_y = y + y_move[i];
      if(next_x>m || next_x<1 || next_y>n || next_y<1 || visit[next_x][next_y]) continue;
      if(map[next_x][next_y]) {
        if(flag) {
          visit[next_x][next_y]=1;
          DFS(next_x, next_y, n, m, r+1, false);
          visit[next_x][next_y]=0;
        }
      } else {
        visit[next_x][next_y]=1;
        DFS(next_x, next_y, n, m, r+1, flag);
        visit[next_x][next_y]=0;
      }
    }
  }
  return;
}

int main() {
  int n, m;
  cin>>n>>m;
  for(int y=1; y<=n; y++) {
    for(int x=1; x<=m; x++) {
      scanf("%1d", &map[x][y]);
    }
  }
  visit[0][0]=-1; visit[1][1] = 1;
  DFS(1, 1, n, m, 1, true);
  cout<<visit[0][0]<<'\n';
  return 0;
}