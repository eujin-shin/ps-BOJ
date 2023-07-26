#include <iostream>
#include <stack>
using namespace std;

stack <int> s[6];

int main() {
  ios_base::sync_with_stdio(false);
  int n, p, k, x, cnt=0;
  cin>>n>>p;
  for(int i=0; i<n; i++) {
    cin>>k>>x;
    k--;
    while(!s[k].empty() && s[k].top()>x) {
      cnt++; s[k].pop();
    }
    if(s[k].empty() || s[k].top()!=x) {
      s[k].push(x); cnt++;
    }
  }
  cout<<cnt<<'\n';
  return 0;
}