#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define M 100001
using namespace std;

vector <int> g[M];
int visit[M]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, r, u, v;
  cin>>n>>m>>r;
  for(int i=0; i<m; i++) {
    cin>>u>>v;
    g[u].push_back(v); g[v].push_back(u);
  }
  int cur, next, num=1;
  queue <int> q;
  q.push(r);
  while(!q.empty()) {
    cur=q.front(); q.pop();
    visit[cur]=num++;
    sort(g[cur].begin(), g[cur].end());
    for(int i=0; i<g[cur].size(); i++) {
      next=g[cur][i];
      if(visit[next]>0) continue;
      q.push(next); visit[next]=1;
    }
  }
  for(int i=1; i<=n; i++) {
    cout<<visit[i]<<'\n';
  }
  return 0;
}