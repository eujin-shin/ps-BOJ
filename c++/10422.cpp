#include <iostream>
#define ll long long
#define M 1000000007
using namespace std;

ll c[5001]={1, };

ll GetC(int n) {
  if(c[n]>0) return c[n];
  ll tmp=0;
  for(int i=0; i<n; i++) {
    tmp=(GetC(n-1-i)*(GetC(i)))%M;
    c[n]=(c[n]+tmp)%M;
  }
  return c[n];
}

int main() {
  int t, l;
  cin>>t;
  while(t--) {
    cin>>l;
    if(l%2!=0) cout<<"0\n";
    else cout<<GetC(l/2)<<'\n';
  }
  return 0;
}