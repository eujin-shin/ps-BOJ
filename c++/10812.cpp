#include <iostream>
#include <queue>
using namespace std;

queue <int> q, tmp;

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, x, a, b, k;
  cin>>n>>m;
  for(int i=1; i<=n; i++) q.push(i);
  for(int i=0; i<m; i++) {
    cin>>a>>b>>k;
    for(int j=1; j<=n; j++) {
      x=q.front(); q.pop();
      if(j>=a && j<k) tmp.push(x);
      else q.push(x);
      if(j==b) {
        while(!tmp.empty()) {
          q.push(tmp.front()); tmp.pop();
        }
      }
    }
  }
  for(int i=0; i<n; i++) {
    cout<<q.front();
    q.pop();
    if(!q.empty()) cout<<' ';
  }
  cout<<'\n';
  return 0;
}