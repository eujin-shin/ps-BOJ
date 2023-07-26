#include <iostream>
#include <vector>
#include <queue>
#define pnt pair<int, int>
#define ppnt pair<int, pnt>
using namespace std;

vector <pnt> v[1001], rv[1001];
priority_queue <ppnt, vector<ppnt>, greater<ppnt> > pq, rpq;
int arr[2][1001]={0, }, visit[1001]={0, }, rvisit[1001]={0, };

void push_pq(int x) {
  int next, t, base=arr[0][x];
  for(int i=0; i<v[x].size(); i++) {
    next=v[x][i].second; t=v[x][i].first;
    pq.push(make_pair(t+base, make_pair(x, next)));
  }
  return;
}

void push_rpq(int x) {
  int next, t, base=arr[1][x];
  for(int i=0; i<rv[x].size(); i++) {
    next=rv[x][i].second; t=rv[x][i].first;
    rpq.push(make_pair(t+base, make_pair(x, next)));
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, x, a, b, t;
  cin>>n>>m>>x;
  for(int i=0; i<m; i++) {
    cin>>a>>b>>t;
    v[a].push_back(make_pair(t, b));
    rv[b].push_back(make_pair(t, a));
  }
  int left=n-1, start, end;
  push_pq(x); visit[x]=1;
  while(left>0) {
    t=pq.top().first;
    start=pq.top().second.first;
    end=pq.top().second.second;
    pq.pop();
    if(visit[end]!=0) continue;
    visit[end]=1;
    arr[0][end]=t;
    push_pq(end); left--;
  }
  left=n-1;
  push_rpq(x); rvisit[x]=1;
  while(left>0) {
    t=rpq.top().first;
    start=rpq.top().second.first;
    end=rpq.top().second.second;
    rpq.pop();
    if(rvisit[end]!=0) continue;
    rvisit[end]=1;
    arr[1][end]=t;
    push_rpq(end); left--;
  }
  int max=0;
  for(int i=1; i<=n; i++) {
    if(arr[0][i]+arr[1][i]>max) max=arr[0][i]+arr[1][i];
  }
  cout<<max<<'\n';
  return 0;
}