#include <iostream>
#include <stack>
#define pnt pair<int, int>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  stack <pnt> s;
  int n;
  long long max=0, t, x, l;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>t;
    l=i;
    while(!s.empty() && s.top().first>t) {
      l=s.top().second;
      x=s.top().first*(i-s.top().second);
      s.pop();
      if(x>max) max=x;
    }
    s.push(make_pair(t, l));
  }
  while(!s.empty()) {
    x=s.top().first*(n-s.top().second);
    s.pop();
    if(x>max) max=x;
  }
  cout<<max<<"\n";
  return 0;
}