#include <iostream>
using namespace std;

int map[500][500]={0, };

int xm[4]={0, 0, -1, 1};
int ym[4]={1, -1, 0, 0};

int dfs(int x, int y, int n, int m) {
  int nx, ny, ret=1;
  map[x][y]=0;
  for(int i=0; i<4; i++) {
    nx=x+xm[i]; ny=y+ym[i];
    if(nx<0 || ny<0 || nx>=m || ny>=n) continue;
    if(map[nx][ny]==1) ret+=dfs(nx, ny, n, m);
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, count=0, max=0, temp;
  cin>>n>>m;
  for(int y=0; y<n; y++) {
    for(int x=0; x<m; x++) {
      cin>>map[x][y];
    }
  }
  for(int y=0; y<n; y++) {
    for(int x=0; x<m; x++) {
      if(map[x][y]!=1) continue;
      count++;
      temp=dfs(x, y, n, m);
      if(temp>max) max=temp;
    }
  }
  cout<<count<<'\n'<<max<<'\n';
  return 0;
}