#include <iostream>
#include <queue>
using namespace std;

char map[100][100];
int visit[100][100]={0, };

int xm[4]={0, 0, 1, -1};
int ym[4]={1, -1, 0, 0};

int GetPower(int x, int y, int m, int n) {
  int p=0, nx, ny;
  queue <pair <int, int> > q;
  q.push(make_pair(x, y)); visit[x][y]=1;
  while(!q.empty()) {
    x=q.front().first; y=q.front().second;
    q.pop(); p++;
    for(int i=0; i<4; i++) {
      nx=x+xm[i]; ny=y+ym[i];
      if(nx>=m || ny>=n || nx<0 || ny<0 || visit[nx][ny]==1) continue;
      if(map[ny][nx]==map[y][x]) {
        visit[nx][ny]=1;
        q.push(make_pair(nx, ny));
      }
    }
  }
  return p*p;
}

int main() {
  int n, m, w=0, b=0, temp;
  cin>>m>>n;
  for(int i=0; i<n; i++) {
    cin>>map[i];
  }
  for(int y=0; y<n; y++) {
    for(int x=0; x<m; x++) {
      if(visit[x][y]==1) continue;
      if(map[y][x]=='W') w+=GetPower(x, y, m, n);
      else if(map[y][x]=='B') b+=GetPower(x, y, m, n);
    }
  }
  cout<<w<<' '<<b<<'\n';
  return 0;
}