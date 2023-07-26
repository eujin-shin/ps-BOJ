#include <iostream>
#define M 100001
using namespace std;

int prime[M]={0, };

int main() {
  int t, n, c;
  for(int i=2; i<M; i++) {
    if(prime[i]==1) continue;
    for(int j=i*2; j<M; j+=i) prime[j]=1;
  }
  cin>>t;
  while(t--) {
    cin>>n;
    for(int i=2; i<=n; i++) {
      if(n==1) break;
      if(prime[i]==1) continue;
      c=0;
      while(n%i==0) {
        c++; n/=i;
      }
      if(c>0) cout<<i<<' '<<c<<'\n';
    }
  }
  return 0;
}