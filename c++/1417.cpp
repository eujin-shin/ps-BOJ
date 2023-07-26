#include <iostream>
#include <queue>
using namespace std;

int main() {
  priority_queue <int> pq;
  int n, x, tmp, c=0;
  cin>>n>>x;
  for(int i=1; i<n; i++) {
    cin>>tmp; pq.push(tmp);
  }
  while(!pq.empty() && pq.top()>=x) {
    tmp=pq.top()-1; pq.pop(); x++; c++;
    if(tmp>0) pq.push(tmp);
  }
  cout<<c<<'\n';
  return 0;
}