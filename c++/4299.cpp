#include <iostream>
using namespace std;

int main() {
  int s, d;
  cin>>s>>d;
  if((s-d)<0 || (s-d)%2!=0) cout<<"-1\n";
  else cout<<(s-d)/2+d<<' '<<(s-d)/2<<'\n';
  return 0;
}