#include <iostream>
#define Max 1000000
using namespace std;

int main() {
  int prime[Max]={0, }, t, n, cnt;
  for(int i=2; i<Max; i++) {
    for(int j=i*2; j<Max; j+=i) prime[j]=1;
  }
  cin>>t;
  for(int i=0; i<t; i++) {
    cin>>n; cnt=0;
    for(int j=2; j<=n/2; j++) {
      if(prime[j]==0 && prime[n-j]==0) cnt++;
    }
    cout<<cnt<<'\n';
  }
  return 0;
}