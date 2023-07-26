#include <iostream>
#include <string>
using namespace std;

int main() {
  string x, y;
  int n, t, w, b;
  cin>>t;
  while(t--) {
    w=0; b=0;
    cin>>n>>x>>y;
    for(int i=0; i<n; i++) {
      if(x[i]==y[i]) continue;
      if(x[i]=='W') w++;
      else b++;
    }
    if(w>b) cout<<w<<'\n';
    else cout<<b<<'\n';
  }
  return 0;
}