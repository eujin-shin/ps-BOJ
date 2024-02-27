#include <iostream>
#include <vector>
using namespace std;

vector <int> v[1001];
int dist[1001][1001]={0, }, arr[1001], cnt;

void dfs(int s, int x) {
  int t;
  arr[x]=1;
  for(int i=0; i<v[x].size(); i++) {
    t=v[x][i];
    if(t!=s && dist[s][t]==0) {
      cnt--; 
      dist[s][t]=dist[s][x]+dist[x][t];
      dist[t][s]=dist[s][t];
    }
    if(cnt==0) return;
    if(arr[t]==0) dfs(s, t);
  }
  return;
}

int main() {
  int n, m, x, y, d;
  cin>>n>>m;
  for(int i=1; i<n; i++) {
    cin>>x>>y>>d;
    dist[x][y]=dist[y][x]=d;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for(int i=1; i<=n; i++) {
    cnt=n-1; 
    for(int j=1; j<=n; j++) {
      arr[j]=0;
      if(dist[i][j]!=0) cnt--;
    }
    dfs(i, i);
  }
  for(int i=0; i<m; i++) {
    cin>>x>>y;
    cout<<dist[x][y]<<'\n';
  }
  return 0;
}