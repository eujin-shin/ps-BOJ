#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, s, n, p, q;
  cin>>t;
  while(t--) {
    cin>>s>>n;
    for(int i=0; i<n; i++) {
      cin>>p>>q;
      s+=p*q;
    }
    cout<<s<<'\n';
  }
  return 0;
}