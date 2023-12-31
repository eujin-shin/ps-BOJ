#include <iostream>
#include <queue>
#define pnt pair<int, int>
#define INF 100000
using namespace std;

int moves[2][4]={{0, 0, -1, 1}, {1, -1, 0, 0}};
int map[11][50][50]={0, }, arr[10]={0, }, n, m, ans=-1;

int Check() {
  int k, max=0, min;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(map[0][i][j]!=0) continue;
      min=-1;
      for(int h=0; h<m; h++) {
        k=arr[h];
        if(map[k][i][j]>=0 && (min<0 || min>map[k][i][j])) min=map[k][i][j];
      }
      if(min<0) return -1;
      else if(max<min) max=min;
    }
  }
  return max;
}

void DFS(int r, int x, int k) {
  if(r==m) {
    int c=Check();
    if(c>=0 && (ans<0 || ans>c)) ans=c;
    return;
  }
  for(int i=x; i<=k; i++) {
    arr[r]=i;
    DFS(r+1, i+1, k);
  }
  return;
}

void SetVirus(int x, int y, int r) {
  int nx, ny;
  queue <pnt> q;
  for(int i=0; i<n; i++) for(int j=0; j<n; j++) map[r][i][j]=-1;
  map[r][y][x]=0;
  map[0][y][x]=0;
  q.push(make_pair(x, y));
  while(!q.empty()) {
    x=q.front().first; y=q.front().second;
    q.pop();
    for(int i=0; i<4; i++) {
      nx=moves[0][i]+x; ny=moves[1][i]+y;
      if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
      if(map[0][ny][nx]!=-1 && map[r][ny][nx]==-1) {
        q.push(make_pair(nx, ny));
        map[r][ny][nx]=map[r][y][x]+1;
      }
    }
  }
  return;
}

int main() {
  int x, r=1;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin>>map[0][i][j];
      if(map[0][i][j]==1) map[0][i][j]=-1;
    }
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(map[0][i][j]==2) SetVirus(j, i, r++);
    }
  }
  DFS(0, 1, r-1);
  cout<<ans<<'\n';
  return 0;
}