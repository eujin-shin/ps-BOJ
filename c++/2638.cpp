#include <iostream>
#include <vector>
#include <queue>
#define pnt pair<int, int>
using namespace std;

int moves[2][4]={{0, 1, 0, -1}, {1, 0, -1, 0}};
int map[101][101]={0, }, n, m;

int Melt() {
  int tmp[101][101]={0, };
  queue <pnt> q;
  vector <pnt> v;
  int x, y, nx, ny;
  q.push(make_pair(0, 0));
  while(!q.empty()) {
    x=q.front().first; y=q.front().second;
    q.pop();
    for(int i=0; i<4; i++) {
      nx=x+moves[0][i]; ny=y+moves[1][i];
      if(nx<0 || ny<0 || nx>=m || ny>=n || tmp[ny][nx]>0) continue;
      if(map[ny][nx]==1) {
        tmp[ny][nx]--;
        if(tmp[ny][nx]==-2) v.push_back(make_pair(nx, ny));
      } else {
        tmp[ny][nx]=1;
        q.push(make_pair(nx, ny));
      } 
    }
  }
  for(int i=0; i<v.size(); i++) map[v[i].second][v[i].first]=0;
  return v.size();
}

int main() {
  int cnt=0, s=0;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin>>map[i][j];
      if(map[i][j]==1) cnt++;
    }
  }
  while(cnt>0) {
    s++; 
    cnt-=Melt(); 
  }
  cout<<s<<'\n';
  return 0;
}