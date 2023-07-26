#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int t, n, x, tmp;
  cin>>t;
  while(t--) {
    cin>>n;
    x=10;
    while(n>x) {
      tmp=n%x;
      n-=tmp;
      tmp/=x/10;
      if(tmp>4) n+=x;
      x*=10;
    }
    cout<<n<<'\n';
  }
  return 0;
}