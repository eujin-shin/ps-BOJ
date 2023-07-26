#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue <int> l;
priority_queue <int, vector<int>, greater<int> > r;

void Push(int x) {
  if(r.empty() || r.top()<=x) r.push(x);
  else l.push(x);
  return;
}

int Odd(int x) {
  Push(x);
  if(r.size()<l.size()) {
    r.push(l.top()); l.pop();
  }
  return r.top();
}

void Even(int x) {
  Push(x);
  if(r.size()!=l.size()) {
    l.push(r.top()); r.pop();
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  int t, m, x;
  cin>>t;
  while(t--) {
    cin>>m;
    l=priority_queue <int>();
    r=priority_queue <int, vector<int>, greater<int> >();
    vector <int> v;
    for(int i=1; i<=m; i++) {
      cin>>x;
      if(i%2) v.push_back(Odd(x));
      else Even(x);
    }
    cout<<v.size()<<'\n';
    for(int i=1; i<=v.size(); i++) {
      cout<<v[i-1];
      if(i%10==0 || i==v.size()) cout<<'\n';
      else cout<<' ';
    }
  }
  return 0;
}