#include <iostream>
#include <queue>
using namespace std;

priority_queue <int> pq;

int main() {
  int n, h, t, x, cnt=1;
  cin>>n>>h>>t;
  for(int i=0; i<n; i++) {
    cin>>x; pq.push(x);
  }
  while(cnt<=t && pq.top()>=h) {
    x=pq.top(); pq.pop();
    if(x>1) pq.push(x/2);
    else pq.push(1);
    cnt++;
  }
  if(pq.top()>=h) cout<<"NO\n"<<pq.top()<<'\n';
  else cout<<"YES\n"<<cnt-1<<'\n';
  return 0;
}