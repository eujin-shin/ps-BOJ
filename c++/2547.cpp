#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, n, cur, x;
  cin>>t;
  while(t--) {
    cin>>n; cur=0;
    for(int i=0; i<n; i++) {
      cin>>x; cur+=x; cur%=n;
    }
    if(cur==0) cout<<"YES\n";
    else cout<<"NO\n";
  }
  return 0;
}