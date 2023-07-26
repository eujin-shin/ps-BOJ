#include <iostream>
using namespace std;

int map[502][502] = {0, };
int x_move[4] = {0, 1, 0, -1};
int y_move[4] = {1, 0, -1, 0};

void DFS(int x, int y, int n, int m) {
  if(x==n && y==m) {
    map[0][0] = map[0][0] + 1;
  } else {
    int n_x, n_y, cur=map[x][y];
    for(int i=0; i<4; i++) {
      n_x = x+x_move[i]; n_y = y+y_move[i];
      if(n_x>n || n_y>m || n_x<1 || n_y<1 || cur<=map[n_x][n_y]) continue;
      DFS(n_x, n_y, n, m);
    }
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin>>m>>n;
  for(int y=1; y<=m; y++) {
    for(int x=1; x<=n; x++) {
      cin>>map[x][y];
    }
  }
  DFS(1, 1, n, m);
  cout<<map[0][0]<<'\n';
  return 0;
}