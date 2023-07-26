#include <iostream>
using namespace std;

int main() {
  int s[3]={300, 60, 10}, c[3]={0, };
  int t;
  cin>>t;
  for(int i=0; i<3; i++) {
    if(t<s[i]) continue;
    c[i]=t/s[i]; t%=s[i];
  }
  if(t!=0) cout<<"-1\n";
  else {
    for(int i=0; i<3; i++) {
      cout<<c[i];
      if(i<2) cout<<' ';
    }
    cout<<'\n';
  }
  return 0;
}