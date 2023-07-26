#include <iostream>
#include <stack>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n;
  long long cur, bef, sum, tmp;
  stack <long long> s;
  cin>>t;
  while(t--) {
    cin>>n>>bef;
    sum=0;
    for(int i=1; i<n; i++) {
      cin>>cur;
      if(bef>cur) {
        while(!s.empty()) {
          sum+=bef-s.top();
          s.pop();
        }
      } else s.push(cur);
      bef=cur;
    }
    while(!s.empty()) {
      sum+=bef-s.top();
      s.pop();
    }
    cout<<sum<<'\n';
  }
  return 0;
}