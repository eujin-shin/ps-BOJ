#include <iostream>
using namespace std;

int main() {
  int a, b, c;
  cin>>a>>b>>c;
  if(a+b>c*2) cout<<a+b-c*2<<"\n";
  else cout<<a+b<<"\n";
  return 0;
}