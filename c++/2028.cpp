#include <iostream>
using namespace std;

int main() {
  int t, n, x;
  cin>>t;
  while(t--) {
    cin>>n; x=1;
    while(x<=n) x*=10;
    if(n*n%x==n) cout<<"YES\n";
    else cout<<"NO\n";
  }
  return 0;
}