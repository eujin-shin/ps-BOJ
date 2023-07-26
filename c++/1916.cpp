#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define M 1001
using namespace std;

vector <pair <int, int> > graph[M];
priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
int d[M];
int visit[M]={0, };

void AddBus(int x, int w) {
  int next, plus;
  for(int i=0; i<graph[x].size(); i++) {
    plus=graph[x][i].first;
    next=graph[x][i].second;
    if(w+plus<d[next] || d[next]<0) {
      d[next]=w+plus;
      q.push(make_pair(d[next], next));
    }
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, dep, arr, w;
  cin>>n>>m;
  for(int i=0; i<m; i++) {
    cin>>dep>>arr>>w;
    graph[dep].push_back(make_pair(w, arr));
  }
  cin>>dep>>arr;
  int cur=dep;
  memset(d, -1, sizeof(d)); d[cur]=0;
  q.push(make_pair(0, cur));
  while(!q.empty()) {
    cur=q.top().second; 
    w=q.top().first;
    q.pop();
    if(visit[cur]==1 || d[cur]<w) continue;
    visit[cur]=1;
    AddBus(cur, w);
  }
  cout<<d[arr]<<'\n';
  return 0;
}