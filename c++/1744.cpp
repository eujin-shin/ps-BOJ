#include <queue>
#include <iostream>
using namespace std;

priority_queue <int, vector<int>, greater<int> > mq;
priority_queue <int> pq;

int main() {
  int n, x, a, b, zero=0, one=0, sum=0;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>x;
    if(x==1) one++;
    else if(x==0) zero++;
    else if(x>0) pq.push(x);
    else mq.push(x);
  }
  while(mq.size()>1) {
    a=mq.top(); mq.pop();
    b=mq.top(); mq.pop();
    sum+=a*b;
  }
  while(!mq.empty()) {
    if(zero>0) {
      zero--; mq.pop();
    } else {
      a=mq.top(); sum+=a; mq.pop();
    }
  }
  while(pq.size()>1) {
    a=pq.top(); pq.pop();
    b=pq.top(); pq.pop();
    sum+=a*b;
  }
  while(!pq.empty()) {
    a=pq.top(); sum+=a; pq.pop();
  }
  sum+=one;
  cout<<sum<<'\n';
  return 0;
}