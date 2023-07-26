#include <iostream>
using namespace std;

int main() {
  long long ans=1, s, k, n, m;
  cin>>s>>k;
  if(s==0) {
    cout<<"0\n"; return 0;
  }
  n=s/k; m=s%k;
  for(int i=0; i<k; i++) {
    if(i<m) ans*=(n+1);
    else ans*=n;
  }
  cout<<ans<<'\n';
  return 0;
}