#include <iostream>
using namespace std;

int main() {
  int a, b, c, n, x, f=0;
  cin>>a>>b>>c>>n;
  for(int i=0; i<=n; i+=c) {
    x=n-i; if(x==0) f=1;
    for(int j=0; j<=x; j+=b) {
      if(x-j==0) f=1;
      for(int h=0; h<=x-j; h+=a) {
        if(x-j-h==0) f=1;
      }
    }
  }
  cout<<f<<'\n';
  return 0;
}