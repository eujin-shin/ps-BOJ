#include <iostream>
#include <vector>
#define M 100000
using namespace std;

vector <int> h;

void Push(int x) {
  h.push_back(x);
  int cur=h.size()-1, next, tmp;
  while(cur>0) {
    next=(cur-1)/2;
    if(h[next]<=h[cur]) break;
    tmp=h[cur]; h[cur]=h[next]; h[next]=tmp;
    cur=next;
  }
  return;
}

void Pop() {
  h[0]=h[h.size()-1];
  h.erase(h.begin()+h.size()-1);
  int cur=0, l, r, next, tmp;
  while(cur<h.size()) {
    l=cur*2+1; r=l+1;
    if(l>=h.size()) break;
    next=l;
    if(r<h.size() && h[r]<h[l]) next=r;
    if(h[cur]<=h[next]) break;
    tmp=h[cur]; h[cur]=h[next]; h[next]=tmp;
    cur=next;
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, x, a, b;
  long long sum=0;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>x; Push(x);
  }
  while(h.size()>1) {
    a=h[0]; Pop();
    b=h[0]; Pop();
    sum+=a+b; Push(a+b);
  }
  cout<<sum<<'\n';
  return 0;
}