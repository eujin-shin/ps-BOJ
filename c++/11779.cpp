#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define M 1001
#define pnt pair<int, int>
using namespace std;

priority_queue <pnt> pq;
vector <pnt> v[M];
int cost[M]={0, }, parent[M]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  memset(cost, -1, sizeof(cost));
  int n, m, a, b, p;
  cin>>n>>m;
  for(int i=0; i<m; i++) {
    cin>>a>>b>>p;
    v[a].push_back(make_pair(p, b));
  }
  int start, end, cur, next, tmp, p=0;
  cin>>start>>end;
  for(int i=0; i<v[start].size(); i++) {
    pq.push(v[start][i]);
  }
  cur=start;
  while(!pq.empty()) {
    while(!pq.empty()) {
      next=pq.top().second;
      tmp=pq.top().first;
      if(cost[next]<0 || cost[next]>tmp+p) break;
      pq.pop();
    }
    parent[next]=cur; cost[next]=tmp+p;
  }
}