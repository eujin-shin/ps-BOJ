#include <iostream>
#define ll long long
using namespace std;

int main() {
  ll lcm, gcd, sum=-1, k, j, x, y, tmp;
  cin>>gcd>>lcm;
  k=gcd*lcm;
  for(int i=lcm; i>0; i--) {
    if(k%i==0 && k/i<=lcm) {
      j=k/i;
      if(sum==-1 || j+i<sum) {
        sum=j+i; x=i; y=j;
      }
    }
  }
  if(x>y) {
    tmp=y; y=x; x=tmp;
  }
  cout<<x<<' '<<y<<'\n';
  return 0;
}