#include <iostream>
#include <queue>
#include <vector>
#define MAX 32001
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  vector <int> outd[MAX];
  int ind[MAX];
  int n, m, x, y;
  cin>>n>>m;
  for(int i=0; i<m; i++) {
    cin>>x>>y;
    outd[x].push_back(y);
    ind[y]=ind[y]+1;
  }
  priority_queue <int, vector<int>, greater<int> > q;
  for(int i=1; i<=n; i++){
   if(ind[i]==0) {
     q.push(i);
   }
  }
  for(int i=0; i<n; i++) {
    x=q.top(); q.pop();
    cout<<x;
    if(i==n-1) cout<<'\n';
    else cout<<' ';
    for(int j=0; j<outd[x].size(); j++) {
      ind[outd[x][j]]=ind[outd[x][j]]-1;
      if(ind[outd[x][j]]==0) {
        q.push(outd[x][j]);
      }
    }
  }
  return 0;
 }