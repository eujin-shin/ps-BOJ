#include <iostream>
#include <queue>
#include <string>
#define pnt pair<int, int>
using namespace std;

priority_queue <pnt, vector<pnt>, greater<pnt> > pq;
vector <pnt> v[51];
int visit[51]={0, };

void add(int k) {
  visit[k]=1;
  for(int i=0; i<v[k].size(); i++) {
    if(visit[v[k][i].second]!=0) continue;
    pq.push(v[k][i]);
  }
  return;
}

int main() {
  string s;
  int n, c, t, sum=0, mst=0, cnt=1, min=53, x=0, y=0;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>s;
    for(int j=0; j<n; j++) {
      if(s[j]=='0') continue;
      c=(s[j]>='a' && s[j]<='z') ? (s[j]-'a'+1) : (s[j]-'A'+27);
      sum+=c;
      if(i==j) continue;
      v[i+1].push_back(make_pair(c, j+1));
      v[j+1].push_back(make_pair(c, i+1));
      if(min>c) {
        min=c; x=i+1; y=j+1;
      }
    }
  }
  if(x!=0) {
    add(y); add(x); 
    cnt++; 
    mst=min;
  }
  while(!pq.empty()) {
    c=pq.top().first; t=pq.top().second;
    pq.pop();
    if(visit[t]!=0) continue;
    add(t); cnt++; mst+=c;
  }
  if(cnt<n) cout<<"-1\n";
  else cout<<sum-mst<<'\n';
  return 0;
}