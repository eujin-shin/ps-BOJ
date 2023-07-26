#include <iostream>
#define M 1500000
using namespace std;

int prime[M]={0, };

int Check(int n, int k) {
  bool flag=false;
  if(n==1134311) flag=true;
  int x=n, l=10, r=k, a, b;
  while(x>0) {
    a=x%l; b=x/r;
    if(a!=b) return 0;
    x=(x%r)/l; r/=100;
  }
  return 1;
}

int main() {
  int n, x, k=1;
  prime[1]=1;
  for(int i=2; i<M; i++) {
    if(prime[i]==1) continue;
    for(int j=2*i; j<M; j+=i) prime[j]=1;
  }
  cin>>n;
  while(k*10<n) k*=10;
  for(int i=n; i<M; i++) {
    if(i==k*10) k=i;
    if(prime[i]==1) continue;
    if(Check(i, k)==1) {
      cout<<i<<'\n'; break;
    }
  }
  return 0;
}