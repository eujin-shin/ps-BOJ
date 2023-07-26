#include <iostream>
using namespace std;

int xmove[8]={0, 1, 0, -1, -1, 1, -1, 1};
int ymove[8]={1, 0, -1, 0, 1, 1, -1, -1};

int map[252][252]={0, };

void DFS(int x, int y) {
  map[x][y]=0;
  int nx, ny;
  for(int i=0; i<8; i++) {
    nx=x+xmove[i]; ny=y+ymove[i];
    if(nx<1 || ny<1) continue;
    if(map[nx][ny]==1) DFS(nx, ny);
  }
  return;
}

int main() {
  int count=0, m, n;
  cin>>m>>n;
  for(int y=1; y<=m; y++) {
    for(int x=1; x<=n; x++) {
      cin>>map[x][y];
    }
  }
  for(int y=1; y<=m; y++) {
    for(int x=1; x<=n; x++) {
      if(map[x][y]>0) {
        count++; DFS(x, y);
      }
    }
  }
  cout<<count<<'\n';
  return 0;
}