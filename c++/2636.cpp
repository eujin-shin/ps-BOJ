#include <iostream>
#include <queue>
#include <vector>
#define pnt pair<int, int>
using namespace std;

int moves[2][4]={{0, 1, 0, -1}, {1, 0, -1, 0}};
int arr[100][100]={0, }, n, m;

int Melt() {
  int visit[100][100]={0, }, x, y, nx, ny;
  queue <pnt> q;
  vector <pnt> v;
  visit[0][0]=1;
  q.push(make_pair(0, 0));
  while(!q.empty()) {
    x=q.front().first; y=q.front().second;
    q.pop();
    for(int i=0; i<4; i++) {
      nx=x+moves[0][i]; ny=y+moves[1][i];
      if(nx>=m || nx<0 || ny>=n || ny<0 || visit[ny][nx]!=0) continue;
      visit[ny][nx]=1;
      if(arr[ny][nx]==1) v.push_back(make_pair(nx, ny));
      else q.push(make_pair(nx, ny));
    }
  }
  for(int i=0; i<v.size(); i++) arr[v[i].second][v[i].first]=0;
  return v.size();
}

int main() {
  int t=0, cnt=0, del;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin>>arr[i][j];
      if(arr[i][j]==1) cnt++;
    }
  }
  while(cnt>0) {
    t++;
    del=Melt();
    cnt-=del;
  }
  cout<<t<<'\n'<<del<<'\n';
}