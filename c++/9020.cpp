#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  int prime[10001]={0, };
  int n, t;
  for(int i=2; i<=10000; i++) {
    if(prime[i]!=0) continue;
    for(int j=2; j*i<=10000; j++) {
      prime[j*i]=1;
    }
  }
  cin>>t;
  while(t--) {
    cin>>n;
    for(int i=n/2; i>1; i--) {
      if(prime[i]==0 && prime[n-i]==0) {
        cout<<i<<' '<<n-i<<'\n';
        break;
      }
    }
  }
  return 0;
}