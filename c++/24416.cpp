#include <iostream>
using namespace std;

int main() {
  int n, x, a=1, b=1;
  cin>>n;
  for(int i=3; i<=n; i++) {
    x=a+b; a=b; b=x;
  }
  cout<<x<<' '<<n-2<<'\n';
}