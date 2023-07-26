#include <iostream>
#include <cmath>
using namespace std;

int main() {
  long long g, a, b=1, i=2;
  double t;
  int flag=-1;
  cin>>g;
  while(1) {
    a=i*i;
    if(a-b>g) break;
    t=sqrt(a-g);
    if(t==(long long)t && t>0) {
      cout<<i<<'\n'; flag=1;
    }
    b=i*i; i++;
  }
  if(flag<0) cout<<flag<<'\n';
  return 0;
}