#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int t, f;
  string a, b, x, y;
  cin>>t;
  while(t--) {
    cin>>a>>b;
    if(a.size()!=b.size()) {
      cout<<a<<" & "<<b<<" are NOT anagrams.\n";
      continue;
    }
    x=a; y=b; f=1;
    sort(x.begin(), x.end()); sort(y.begin(), y.end());
    for(int i=0; i<x.size(); i++) {
      if(x[i]==y[i]) continue;
      f=0; break;
    }
    if(f>0) cout<<a<<" & "<<b<<" are anagrams.\n";
    else cout<<a<<" & "<<b<<" are NOT anagrams.\n";
  }
  return 0;
}