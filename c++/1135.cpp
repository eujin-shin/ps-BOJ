#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> v[51];
queue <int> q;
priority_queue <int> pq;
int p[51]={0, }, c[51]={0, }, m[51]={0, };

void Check(int cur) {
  int x=1, t, max=0;
  for(int i=0; i<v[cur].size(); i++) pq.push(m[v[cur][i]]);
  while(!pq.empty()) {
    t=x+pq.top();
    if(t>max) max=t;
    pq.pop(); x++;
  }
  m[cur]=max;
  if(p[cur]>=0) {
    c[p[cur]]--;
    if(c[p[cur]]==0) q.push(p[cur]);
  }
  return;
}

int main() {
  int n, cur=-1;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>p[i];
    if(i!=0) {
      v[p[i]].push_back(i); c[p[i]]++;
    }
  }
  for(int i=0; i<n; i++) {
    if(c[i]!=0) continue;
    c[p[i]]--;
    if(c[p[i]]==0) q.push(p[i]);
  }
  while(cur!=0) {
    cur=q.front(); q.pop();
    Check(cur);
  }
  cout<<m[0]<<'\n';
  return 0;
}