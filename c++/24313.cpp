#include <iostream>
using namespace std;

int main() {
  int a, b, c, n, flag=0;
  cin>>a>>b>>c>>n;
  if(a<=c) {
    if(n*(c-a)-b>=0) flag=1;
  }
  cout<<flag<<'\n';
  return 0;
}