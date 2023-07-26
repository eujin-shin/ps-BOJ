#include <iostream>
#include <queue>
#include <vector>
#define pnt pair<int, int>
#define ppnt pair<int, pnt>
using namespace std;

int visit[1001]={0, };
vector <pnt> v[1001];
priority_queue <ppnt, vector<ppnt>, greater<ppnt> > pq;

void push_pq(int x) {
  int dest;
  for(int i=0; i<v[x].size(); i++) {
    dest=v[x][i].second;
    if(visit[dest]==1) continue;
    pq.push(make_pair(v[x][i].first, make_pair(x, dest)));
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, a, b, c, min, x, y;
  min=10001;
  cin>>n>>m;
  for(int i=0; i<m; i++) {
    cin>>a>>b>>c;
    v[a].push_back(make_pair(c, b));
    v[b].push_back(make_pair(c, a));
    if(c>min || a==b) continue;
    min=c; x=a; y=b;
  }
  int left, sum, cur, dest, w;
  left=n-2; sum=min;
  visit[x]=1; visit[y]=1;
  push_pq(x); push_pq(y);
  while(left>0) {
    cur=pq.top().second.first;
    dest=pq.top().second.second;
    w=pq.top().first;
    pq.pop();
    if(visit[dest]==1) continue;
    visit[dest]=1; sum+=w;
    push_pq(dest);
    left--; 
  }
  cout<<sum<<'\n';
  return 0;
}