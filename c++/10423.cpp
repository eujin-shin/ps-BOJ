#include <iostream>
#include <vector>
#include <queue>
#define pnt pair<int, int>
#define ppnt pair<int, pnt>
using namespace std;

vector <pnt> ve[1001];
priority_queue <ppnt, vector<ppnt>, greater<ppnt> > pq;
int parent[1001]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, k, cnt=0, u, v, w, sum=0;
  cin>>n>>m>>k;
  for(int i=0; i<k; i++) {
    cin>>u; parent[u]=u; cnt++;
  }
  for(int i=0; i<m; i++) {
    cin>>u>>v>>w;
    if(parent[u]==u && parent[v]!=v) {
      pq.push(make_pair(w, make_pair(u, v)));
    } else if(parent[v]==v && parent[u]!=u) {
      pq.push(make_pair(w, make_pair(v, u)));
    } else {
      ve[u].push_back(make_pair(w, v));
      ve[v].push_back(make_pair(w, u));
    }
  }
  while(cnt<n) {
    w=pq.top().first;
    u=pq.top().second.first;
    v=pq.top().second.second;
    pq.pop();
    if(parent[v]!=0) continue;
    sum+=w; cnt++;
    parent[v]=u;
    for(int i=0; i<ve[v].size(); i++) {
      if(parent[ve[v][i].second]!=0) continue;
      pq.push(make_pair(ve[v][i].first, make_pair(v, ve[v][i].second))); 
    }
  }
  cout<<sum<<'\n';
  return 0;
}