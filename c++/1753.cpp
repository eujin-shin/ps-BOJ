#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define M 20001
using namespace std;

vector <pair<int, int> > graph[M];
bool visit[M];
int ans[M];

void Solve(int x) {
  int cur, dis, next, nd;
  ans[x]=0;
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  pq.push(make_pair(0, x));
  while(!pq.empty()) {
    cur=pq.top().second; dis=pq.top().first; pq.pop();
    if(ans[cur]!=-1 && ans[cur]<dis) continue;
    if(visit[cur]) continue;
    visit[cur]=true;
    for(int i=0; i<graph[cur].size(); i++) {
      next=graph[cur][i].second; nd=graph[cur][i].first;
      if(ans[next]==-1 || ans[next]>dis+nd) {
        ans[next]=dis+nd;
        pq.push(make_pair(ans[next], next));
      }
    }
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, k, x, y, w;
  cin>>n>>m>>k;
  for(int i=1; i<=n; i++) {
    ans[i]=-1; visit[i]=false;
  }
  for(int i=0; i<m; i++) {
    cin>>x>>y>>w;
    graph[x].push_back(make_pair(w, y));
  }
  Solve(k);
  for(int i=1; i<=n; i++) {
    if(ans[i]==-1) cout<<"INF\n";
    else cout<<ans[i]<<'\n';
  }
  return 0;
}