#include <iostream>
using namespace std;

int main() {
  long long a, b, c, mod, result=1;
  cin>>a>>b>>c;
  while(b>0) {
    mod=a%c;
    if(b%2==1) {
      result*=mod; result%=c;
    }
    a=(a%c)*(a%c);
    b/=2;
  }
  cout<<result<<'\n';
  return 0;
}