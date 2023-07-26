#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  vector <int> outd[1001];
  int ind[1001]={0, };
  int n, m, x, f, b;
  bool ans=true;
  cin>>n>>m;
  for(int i=0; i<m; i++) {
    cin>>x>>f; x--;
    while(x--) {
      cin>>b;
      ind[b]+=1; outd[f].push_back(b);
      f=b;
    }
  }
  queue <int> q, a;
  for(int i=1; i<=n; i++) {
    if(ind[i]==0) q.push(i);
  }
  int cur, next;
  for(int i=1; i<=n; i++) {
    if(q.empty()) {
      ans=false; break;
    }
    cur=q.front(); q.pop(); a.push(cur);
    for(int j=0; j<outd[cur].size(); j++) {
      next=outd[cur][j];
      ind[next]--;
      if(ind[next]==0) q.push(next);
    }
  }
  if(ans) {
    while(!a.empty()) {
      cout<<a.front()<<'\n';
      a.pop();
    }
  } else {
    cout<<"0\n";
  }
  return 0;
}