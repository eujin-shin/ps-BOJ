#include <iostream>
#include <queue>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, tmp;
  ll sum=0, x, y;
  priority_queue <ll, vector<ll>, greater<ll> > pq;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    cin>>tmp; pq.push(tmp);
  }
  for(int i=0; i<m; i++) {
    x=pq.top(); pq.pop(); y=pq.top(); pq.pop();
    pq.push(x+y); pq.push(x+y);
  }
  while(!pq.empty()) {
    sum+=pq.top(); pq.pop();
  }
  cout<<sum<<'\n';
  return 0;
}