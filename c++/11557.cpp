#include <iostream>
#include <string>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s, ans;
  int t, n, tmp, max=0;
  cin>>t;
  while(t--) {
    cin>>n;
    for(int i=0; i<n; i++) {
      cin>>s>>tmp;
      if(tmp<max) continue;
      max=tmp; ans=s;
    }
    cout<<ans<<'\n';
  }
  return 0;
}