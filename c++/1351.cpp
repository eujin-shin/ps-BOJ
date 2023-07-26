#include <iostream>
#include <queue>
using namespace std;

void Swap(long long *a, long long *b) {
  int temp=*a;
  *a=*b;
  *b=temp;
  return;
}

int main() {
  long long n, p, q, sum, cur, a, b;
  cin>>n>>p>>q;
  queue <long long> qu;
  if(p>q) Swap(&p, &q);
  qu.push(n);
  sum=0;
  while(!qu.empty()) {
    cur=qu.front(); qu.pop();
    if(cur==0) {
      sum++;
    } else if(cur<p) {
      sum+=2;
    } else if(cur<q) {
      qu.push(cur/p); sum++;
    } else {
      qu.push(cur/p); qu.push(cur/q);
    }
  }
  cout<<sum<<'\n';
  return 0;
}