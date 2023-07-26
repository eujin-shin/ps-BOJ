#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#define pnt pair<int, int>
#define ppnt pair<int, pnt>
using namespace std;

priority_queue <ppnt, vector<ppnt>, greater<ppnt> > pq;
vector <pnt> v[1001];
stack <int> way;
int price[1001]={0, }, parent[1001]={0, };

void push_pq(int x) {
  int next, w;
  for(int i=0; i<v[x].size(); i++) {
    next=v[x][i].second;
    if(parent[next]!=0) continue;
    pq.push(make_pair(v[x][i].first+price[x], make_pair(x, next)));
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, start, end, w;
  cin>>n>>m;
  for(int i=0; i<m; i++) {
    cin>>start>>end>>w;
    v[start].push_back(make_pair(w, end));
  }
  cin>>start>>end;
  parent[start]=-1; push_pq(start);
  int cur=start, next;
  while(parent[end]==0) {
    w=pq.top().first;
    cur=pq.top().second.first;
    next=pq.top().second.second;
    pq.pop();
    if(price[next]!=0 && price[next]<w) continue;
    price[next]=w; parent[next]=cur;
    push_pq(next);
  }
  cur=end;
  while(cur>0) {
    way.push(cur); cur=parent[cur];
  }
  cout<<price[end]<<'\n'<<way.size()<<'\n';
  while(!way.empty()) {
    cout<<way.top(); way.pop();
    if(!way.empty()) cout<<' ';
  }
  cout<<'\n';
  return 0;
}