#include <iostream>
#include <queue>
using namespace std;

priority_queue <long long, vector<long long>, greater<long long> > pq;

int main() {
  ios_base::sync_with_stdio(false);
  int n, cnt=0;
  long long x, sum=0;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>x; pq.push(x);
  }
  while(pq.size()>1) {
    sum+=pq.top()/2; 
    if(pq.top()%2!=0) cnt++;
    pq.pop();
  }
  cout<<sum+pq.top()+cnt*0.5<<'\n';
  return 0;
}